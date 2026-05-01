# Transactions - Comprehensive Guide

## Definition

A **transaction** is a sequence of one or more SQL statements grouped together as a logical unit of work. All statements in a transaction must complete successfully, or the entire transaction is rolled back.

### Key Concept

```
Transaction = Atomic Unit of Work
             Either all operations succeed
             Or all are rolled back (nothing happens)
```

### Transaction Properties (ACID)

The four fundamental properties that guarantee reliable transactions:

## 1. ATOMICITY (A)

**Definition**: Transaction is atomic – either all operations execute or none execute. No partial execution.

**Characteristic**: "All or Nothing"

**How it works**:
```
Start Transaction
    ├─ Operation 1: Debit Account A by $1000 ✓
    ├─ Operation 2: Credit Account B by $1000 ✓
    └─ Commit
    
Result: Both succeed - Transfer complete

OR (if error occurs):

Start Transaction
    ├─ Operation 1: Debit Account A by $1000 ✓
    ├─ Operation 2: Credit Account B - ERROR! ✗
    └─ Rollback (undo operation 1)
    
Result: Neither operation happens - Accounts unchanged
```

**Benefits**:
- Prevents database corruption
- Ensures consistency
- No partial data updates

**Real-World Example**:
```
Bank Transfer: $1000 from Account A to Account B

Without Atomicity (Dangerous):
- $1000 removed from A ✓
- System crashes
- $1000 never added to B ✗
- Money lost!

With Atomicity (Safe):
- Both operations succeed together
- Or both fail together
- No money lost
```

### SQL Example of Atomicity

```sql
START TRANSACTION;

UPDATE Accounts 
SET Balance = Balance - 1000 
WHERE AccountID = 1;  -- Debit

UPDATE Accounts 
SET Balance = Balance + 1000 
WHERE AccountID = 2;  -- Credit

-- If any error occurs before COMMIT:
IF (error) THEN
    ROLLBACK;  -- Both updates undone
ELSE
    COMMIT;    -- Both updates saved
END IF;
```

## 2. CONSISTENCY (C)

**Definition**: Transaction transforms database from one valid state to another valid state. All integrity constraints are maintained.

**Guarantee**: Database is never in inconsistent state

**How it works**:
```
Before Transaction: Consistent state
          ↓
Transaction executes
          ↓
After Transaction: Consistent state
(All constraints satisfied)
```

**Types of Consistency**:

### Data Consistency
All integrity constraints maintained:
- PRIMARY KEY uniqueness
- FOREIGN KEY references valid
- CHECK constraints satisfied
- NOT NULL constraints satisfied

### Logical Consistency
Business rules maintained:
- Total money in all accounts remains same
- All accounts have valid balances
- No negative balances (if not allowed)

**Example - Bank Transfer**:
```
Initial State (Consistent):
Account A Balance: $5000
Account B Balance: $3000
Total: $8000

Transfer $1000 from A to B:
Account A Balance: $4000
Account B Balance: $4000
Total: $8000 (Same total - Consistent!)

Invalid transaction (violates rule):
Transfer $1000, but A only has $500 balance
Rejected - maintains consistency
```

### SQL Example

```sql
-- Consistency: All constraints must be satisfied

CREATE TABLE ACCOUNT (
    AccountID INT PRIMARY KEY,
    Balance DECIMAL(10, 2) CHECK (Balance >= 0),  -- Balance constraint
    CurrencyID INT,
    FOREIGN KEY (CurrencyID) REFERENCES CURRENCY(CurrencyID)
);

START TRANSACTION;
    UPDATE ACCOUNT SET Balance = -100 WHERE AccountID = 1;  -- Violates CHECK
    -- Transaction fails - constraint violation prevents update
ROLLBACK;
```

## 3. ISOLATION (I)

**Definition**: Each transaction executes in isolation from concurrent transactions. Operations of one transaction don't interfere with other concurrent transactions until committed.

**Concept**: "As if transactions execute serially (one after another)"

### Why Isolation is Needed

Without isolation, concurrent transactions cause problems:

#### Problem 1: Dirty Read

One transaction reads uncommitted data from another transaction.

```
Transaction 1              Transaction 2
─────────────             ─────────────
START;
UPDATE Salary = 60000
  WHERE EmpID = 1;
(Not committed yet)
                          SELECT Salary
                            WHERE EmpID = 1;  ← Reads $60000 (dirty!)
                          
ROLLBACK;                 (Transaction 1 rolls back)
(Salary reverts to $50000)
                          ← Transaction 2 has wrong data ($60000)!
```

#### Problem 2: Non-Repeatable Read

Same query gives different results within same transaction.

```
Transaction 1              Transaction 2
─────────────             ─────────────
SELECT Salary
WHERE EmpID = 1;  ← $50000
                          UPDATE Salary = 60000
                            WHERE EmpID = 1;
                          COMMIT;
                          
SELECT Salary
WHERE EmpID = 1;  ← $60000 (Different from first read!)
(Read twice, got different values)
```

#### Problem 3: Phantom Read

Re-executing a query returns different set of rows.

```
Transaction 1              Transaction 2
─────────────             ─────────────
SELECT * FROM Employee
WHERE Salary > 50000;
(Result: 10 employees)
                          INSERT INTO Employee VALUES (..., 60000);
                          COMMIT;
                          
SELECT * FROM Employee
WHERE Salary > 50000;
(Result: 11 employees) ← New row appeared!
```

#### Problem 4: Lost Update

One transaction's update is overwritten by another.

```
Transaction 1              Transaction 2
─────────────             ─────────────
READ Salary = 50000
(In memory)
                          READ Salary = 50000
                          (In memory)
Calculate new: 55000
(Add 5000)
WRITE: 55000
COMMIT;
                          Calculate new: 52000
                          (Add 2000)
                          WRITE: 52000
                          COMMIT;
                          
Result: Only $52000 update saved
        $3000 increase from T1 is lost!
```

### Isolation Levels

Different levels provide different isolation vs performance trade-offs:

| Isolation Level | Dirty Read | Non-Rep Read | Phantom Read |
|-----------------|-----------|------------|------------|
| READ UNCOMMITTED | ✓ Possible | ✓ Possible | ✓ Possible |
| READ COMMITTED | ✗ Prevented | ✓ Possible | ✓ Possible |
| REPEATABLE READ | ✗ Prevented | ✗ Prevented | ✓ Possible |
| SERIALIZABLE | ✗ Prevented | ✗ Prevented | ✗ Prevented |

**Performance vs Safety Trade-off**:
```
Higher Isolation
      ↓
  More Safe
  Slower Performance
      ↓
SERIALIZABLE
REPEATABLE READ
READ COMMITTED
READ UNCOMMITTED
      ↑
  Less Safe
  Faster Performance
```

### SQL Example - Setting Isolation Level

```sql
-- MySQL
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
START TRANSACTION;
    SELECT * FROM Account WHERE Balance < 100;
COMMIT;

-- SQL Server
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE;
BEGIN TRANSACTION
    SELECT * FROM Account WHERE Balance < 100;
COMMIT;
```

## 4. DURABILITY (D)

**Definition**: Once a transaction is committed, changes are permanent and survive any subsequent failures (system crashes, hardware failure, etc.).

**Guarantee**: Committed data persists permanently

### Durability Mechanism

**Approach**: Transaction Log

```
Transaction executes
        ↓
Changes written to LOG (on disk) before commit
        ↓
Transaction commits
        ↓
Log entry marked as committed
        ↓
System crash occurs (any time after commit)
        ↓
On recovery: Log shows transaction committed
        ↓
Changes re-applied from log
        ↓
Data restored
```

### Why Log is Essential

```
Without Log:
INSERT → RAM → Commit → Crash → Data Lost!

With Log:
INSERT → Log → Commit → Crash → Recover from Log → Data Safe!
```

### Real-World Example - Bank

```
Initial: Account A = $5000, Account B = $3000

Transaction: Transfer $1000 from A to B
    ├─ Log: "Update A: 5000→4000"
    ├─ Log: "Update B: 3000→4000"
    ├─ Apply changes to database
    ├─ Log: "COMMIT"
    └─ Crash happens immediately after!

Recovery:
    ├─ Read log from disk
    ├─ Find "COMMIT" flag for transfer
    ├─ Re-apply updates from log
    ├─ Database restored:
    │   Account A = $4000
    │   Account B = $4000
    └─ Transfer successfully persisted!

Durability achieved!
```

### SQL Example

```sql
-- Application level
START TRANSACTION;
    UPDATE Accounts SET Balance = Balance - 1000 WHERE AccountID = 1;
    UPDATE Accounts SET Balance = Balance + 1000 WHERE AccountID = 2;
COMMIT;  -- Permanent! Even if system crashes next instant

-- After power failure and recovery:
-- Database will have the updates (no data loss)
```

## ACID Summary

```
ATOMICITY: "All or Nothing"
           All operations in transaction succeed
           OR all fail and rollback

CONSISTENCY: "Valid State Transition"
            Database remains valid
            All constraints satisfied

ISOLATION: "Independent Execution"
          Transactions don't interfere with each other
          Concurrent but independent

DURABILITY: "Permanent Save"
           Committed changes survive failures
           Persist even after crashes
```

## Transaction Control Commands

### 1. START TRANSACTION (BEGIN)

**Purpose**: Begin a new transaction

**Syntax**:
```sql
START TRANSACTION;
-- or
BEGIN;
```

**Example**:
```sql
START TRANSACTION;
INSERT INTO Employee VALUES (101, 'Raj', 50000);
UPDATE Department SET Count = Count + 1 WHERE DeptID = 1;
```

### 2. COMMIT

**Purpose**: Save all changes permanently

**Syntax**:
```sql
COMMIT;
```

**Effect**:
```
Before COMMIT:
├─ Changes exist only in transaction
├─ Other sessions can't see changes
└─ Changes can still be rolled back

After COMMIT:
├─ Changes permanently saved in database
├─ Other sessions can see changes
├─ Changes cannot be undone (except with new transaction)
└─ Transaction ends
```

**Example**:
```sql
START TRANSACTION;
UPDATE Account SET Balance = Balance - 100 WHERE AccountID = 1;
UPDATE Account SET Balance = Balance + 100 WHERE AccountID = 2;
COMMIT;  -- Both updates now permanent

-- Later, if tried to undo:
ROLLBACK;  -- Too late! Cannot undo committed transaction
```

### 3. ROLLBACK

**Purpose**: Undo all changes in transaction

**Syntax**:
```sql
ROLLBACK;
```

**Effect**:
```
Before ROLLBACK:
├─ Changes made but not committed
├─ Database state unchanged (changes in buffer)
└─ Changes can be undone

After ROLLBACK:
├─ All changes discarded
├─ Database reverts to before transaction
├─ As if transaction never happened
└─ Transaction ends
```

**Example - Successful Transaction**:
```sql
START TRANSACTION;
INSERT INTO Student VALUES (101, 'Raj');  -- Not yet in database
DELETE FROM Enrollment WHERE StudentID = 102;  -- Not yet applied
-- Decide: Complete transaction
COMMIT;  -- Both operations applied
```

**Example - Failed Transaction**:
```sql
START TRANSACTION;
INSERT INTO Student VALUES (101, 'Raj');
UPDATE Course SET Seats = Seats - 1 WHERE CourseID = 'CS101';
-- Discover error in data
ROLLBACK;  -- Both operations undone, database unchanged
```

### 4. SAVEPOINT

**Purpose**: Create a restore point within transaction to rollback partially

**Syntax**:
```sql
SAVEPOINT savepoint_name;
```

**Rollback to Savepoint**:
```sql
ROLLBACK TO SAVEPOINT savepoint_name;
```

**Release Savepoint**:
```sql
RELEASE SAVEPOINT savepoint_name;
```

**Example**:
```sql
START TRANSACTION;

INSERT INTO Employee VALUES (101, 'Raj', 50000);
UPDATE Department SET Count = Count + 1 WHERE DeptID = 1;

SAVEPOINT sp1;  -- ← Restore point created

INSERT INTO Salary VALUES (101, 50000);
-- Error occurs

ROLLBACK TO SAVEPOINT sp1;  -- Undo only the last INSERT
                             -- Restore point sp1 recovers

COMMIT;  -- Commits employee and department updates
         -- Salary insert is undone
```

## Transaction Flow Diagram

```
┌─────────────────────────────────────────────────┐
│ Application starts a transaction                │
└──────────────────┬──────────────────────────────┘
                   ↓
        ┌──────────────────────────┐
        │ Execute SQL Statements   │
        ├──────────────────────────┤
        │ INSERT/UPDATE/DELETE     │
        │ (Changes in buffer only) │
        └──────┬─────────────────┬──┘
               │                 │
        ┌──────▼──┐      ┌─────────▼──┐
        │ COMMIT  │      │ ROLLBACK   │
        │ (Save)  │      │ (Discard)  │
        └──────┬──┘      └─────┬──────┘
               │                │
        ┌──────▼────────────────▼──────┐
        │ Transaction Ends             │
        │ ├─ COMMIT: Changes saved     │
        │ └─ ROLLBACK: Changes undone  │
        └─────────────────────────────┘
```

## Practical Examples

### Example 1: Successful Bank Transfer

```sql
START TRANSACTION;

-- Step 1: Debit source account
UPDATE Accounts SET Balance = Balance - 1000 WHERE AccountID = 1;

-- Step 2: Credit destination account
UPDATE Accounts SET Balance = Balance + 1000 WHERE AccountID = 2;

-- Step 3: Commit if no errors
COMMIT;

-- Result: Both updates applied, money transferred successfully
```

### Example 2: Failed Transfer with Rollback

```sql
START TRANSACTION;

-- Step 1: Debit source account
UPDATE Accounts SET Balance = Balance - 1000 WHERE AccountID = 1;

-- Step 2: Validate and then credit
IF (SELECT Balance FROM Accounts WHERE AccountID = 2) >= 0 THEN
    UPDATE Accounts SET Balance = Balance + 1000 WHERE AccountID = 2;
ELSE
    ROLLBACK;  -- Destination account invalid
END IF;

-- Step 3: Commit
COMMIT;
```

### Example 3: Multi-Step with Savepoints

```sql
START TRANSACTION;

-- Create new student record
INSERT INTO Student VALUES (101, 'Raj', 'raj@college.edu');

SAVEPOINT student_created;

-- Enroll in 3 courses
INSERT INTO Enrollment VALUES (101, 'CS101');
INSERT INTO Enrollment VALUES (101, 'CS102');

SAVEPOINT courses_enrolled;

-- Try to enroll in 4th course (system limit: 3 courses)
IF (SELECT COUNT(*) FROM Enrollment WHERE StudentID = 101) <= 3 THEN
    INSERT INTO Enrollment VALUES (101, 'CS103');
ELSE
    ROLLBACK TO SAVEPOINT courses_enrolled;
    -- Undo 4th enrollment attempt but keep first 3
END IF;

COMMIT;
-- Result: Student created with 3 courses enrolled
```

## Exam Notes

1. **ACID Properties**: Define each with clear one-liner, then detailed explanation
2. **Atomicity Example**: Always use bank transfer scenario
3. **Consistency**: Explain constraint maintenance
4. **Isolation**: Show problems (dirty read, non-repeatable read, phantom read) with examples
5. **Durability**: Mention transaction log and crash recovery
6. **Commands**: Know START, COMMIT, ROLLBACK, SAVEPOINT syntax and purpose
7. **Practical Scenarios**: Write multi-step transaction examples
8. **Problems**: Understand what problems ACID solves in concurrent environment
