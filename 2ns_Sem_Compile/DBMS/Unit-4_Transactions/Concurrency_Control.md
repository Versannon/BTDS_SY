# Concurrency Control - Comprehensive Guide

## Definition

**Concurrency control** is a mechanism to manage simultaneous execution of multiple transactions to ensure data consistency, isolation, and integrity in DBMS.

## Why Concurrency Control is Needed

### Problem: Lost Updates

Without concurrency control, transactions interfere with each other:

```
Transaction T1 (Deposit $100)    Transaction T2 (Withdraw $50)
─────────────────────────────    ──────────────────────────────
READ: Balance = $1000
                                 READ: Balance = $1000
Calculate: 1000 + 100 = 1100
                                 Calculate: 1000 - 50 = 950
WRITE: Balance = 1100
                                 WRITE: Balance = 950  ← Wrong!

Result: Balance = $950
But it should be: $1050 (1000 + 100 - 50)
Lost Update: $100 update is lost!
```

## Concurrency Problems

### 1. Dirty Read

**Definition**: Reading uncommitted (dirty) data from another transaction.

```
Transaction T1              Transaction T2
─────────────              ─────────────
UPDATE Salary = 60000
WHERE EmpID = 1;
(Not committed)
                           READ Salary = 60000
                           (Wrong data!)
ROLLBACK;
(Salary reverts)
                           Salary = 60000 in memory
                           But actual DB has 50000
                           ← T2 has stale data!
```

**Impact**: T2 works with invalid data

---

### 2. Non-Repeatable Read

**Definition**: Same query gives different results within same transaction.

```
Transaction T1              Transaction T2
─────────────              ─────────────
SELECT Salary = 50000
WHERE EmpID = 1;
(First read: $50000)
                           UPDATE Salary = 60000
                           WHERE EmpID = 1;
                           COMMIT;
                           
SELECT Salary = 60000
WHERE EmpID = 1;
(Second read: $60000)
(Different value!)
                           
Issue: Same query, different results
```

**Impact**: Inconsistent data within transaction

---

### 3. Phantom Read

**Definition**: Re-executing query returns different set of rows.

```
Transaction T1              Transaction T2
─────────────              ─────────────
SELECT * FROM Employee
WHERE Salary > 50000;
(Result: 10 employees)
                           INSERT INTO Employee
                           VALUES (..., Salary=55000);
                           COMMIT;
                           
SELECT * FROM Employee
WHERE Salary > 50000;
(Result: 11 employees)
                           
Issue: New row appeared (phantom)
```

**Impact**: Result set changes unexpectedly

---

### 4. Lost Update

**Definition**: One transaction's update overwritten by another.

```
Both transactions read same value: $1000
T1 calculates: $1100 (deposit)
T2 calculates: $950 (withdraw)
T1 writes: $1100
T2 writes: $950 ← Overwrites T1's update
Final: $950 (should be $1050)
T1's $100 deposit lost!
```

**Impact**: Data loss

## Concurrency Control Techniques

### 1. Lock-Based Protocols

#### Shared Lock (Read Lock)

```
Shared Lock (S-Lock):
├─ Multiple transactions can hold simultaneously
├─ For READ operations
├─ Prevents modifications
└─ Released after read

Example:
    Transaction 1        Transaction 2
    ─────────────        ─────────────
    S-Lock on A          
    (Read A)             S-Lock on A
    (Read A)             (Both can read)
    
    Release S-Lock
                         Release S-Lock
```

#### Exclusive Lock (Write Lock)

```
Exclusive Lock (X-Lock):
├─ Only one transaction can hold
├─ For WRITE/UPDATE/DELETE operations
├─ Prevents all other transactions
└─ Released after write

Example:
    Transaction 1        Transaction 2
    ─────────────        ─────────────
    X-Lock on A
    (Write A)            Waits for X-Lock
    (Exclusive)          (Blocked!)
    
    Release X-Lock
                         X-Lock on A
                         (Now acquired)
```

#### Lock Compatibility Matrix

```
        S-Lock  X-Lock
S-Lock  ✓       ✗
X-Lock  ✗       ✗

✓ = Compatible (can hold together)
✗ = Incompatible (must wait)
```

### 2. Two-Phase Locking (2PL)

**Definition**: All locks acquired before any released (Growing Phase → Shrinking Phase)

**Phases**:

#### Growing Phase
```
Transaction acquires locks but releases none

SELECT Salary FROM Employee;
(Acquire S-Lock on Employee)

SELECT * FROM Department;
(Acquire S-Lock on Department)

UPDATE Employee SET Salary = 60000;
(Upgrade to X-Lock on Employee)
(All locks acquired)
```

#### Shrinking Phase
```
Transaction releases locks but acquires none

COMMIT;
(Release X-Lock on Employee)
(Release S-Lock on Department)
(Release S-Lock on Employee)
(No new locks acquired)
```

**Protocol**:
```
Growing Phase → Shrinking Phase
└─ Lock Point: Moment when last lock acquired
└─ Prevents dirty reads, non-repeatable reads, phantom reads
└─ Guarantees serializability (but may deadlock)
```

---

### 3. Timestamp-Based Protocol

**Definition**: Each transaction assigned timestamp. Conflicts resolved using timestamps.

```
Transaction T1 gets TS(1) = 100
Transaction T2 gets TS(2) = 200

Older timestamp = higher priority

Rule: If T2(newer) tries to write data
      that T1(older) is reading,
      T2 must wait (or rollback)
```

**Advantages**:
- No deadlock (timestamps serialized)
- Simple comparison

**Disadvantages**:
- Wasted transactions (rollbacks)
- Cascading aborts possible

---

### 4. Optimistic Concurrency Control

**Definition**: Assume conflicts rare. Check at commit time; if conflict, rollback and retry.

**Phases**:

#### Read Phase
```
Transaction reads from database
└─ No locks acquired
└─ Each data item stamped with write timestamp
└─ Transaction reads freely
```

#### Write Phase
```
1. Transaction accumulates updates in local buffer
2. At COMMIT time:
   - Check if any read item modified by other transaction
   - If YES: Conflict! Rollback and retry
   - If NO: Commit all changes
```

**Advantage**: Better for high-concurrency, low-conflict environments

**Disadvantage**: Wasted work if conflict detected at commit

---

## Deadlock

**Definition**: Circular wait where transactions block each other indefinitely.

**Deadlock Scenario**:
```
Transaction T1          Transaction T2
─────────────          ─────────────
LOCK A (S)
                       LOCK B (S)
LOCK B (S)             (Waits)
(Waits - B locked)
                       LOCK A (S)
                       (Waits - A locked)

Deadlock:
T1 waits for B (held by T2)
T2 waits for A (held by T1)
```

**Visual**:
```
T1 → B ← T2
↑         ↓
└─── A ───┘

(Circular wait - DEADLOCK)
```

---

## Deadlock Prevention

### Lock Ordering

```
Rule: Always acquire locks in same order

Bad (causes deadlock):
T1: LOCK A, LOCK B
T2: LOCK B, LOCK A

Good (prevents deadlock):
T1: LOCK A, LOCK B
T2: LOCK A, LOCK B
(Same order = no cycle possible)
```

### Timeout

```
If transaction waits > timeout period:
├─ Automatically abort and rollback
├─ Release all locks
└─ Other transaction can proceed
```

---

## Practical Example: Bank Transfer

### Without Concurrency Control (Problem)

```
Account A: $1000, Account B: $500

T1: Transfer $100: A → B
T2: Transfer $50: B → A

Result Without CC: A = $950, B = $450 (WRONG!)
Should be: A = $950, B = $550 (both transfers successful)
```

### With 2-Phase Locking (Safe)

```
Transaction T1              Transaction T2
─────────────              ─────────────
BEGIN;
LOCK A (S)
LOCK B (X)
(Growing phase)
                           BEGIN;
                           LOCK B (S)
                           (Waits - B locked)

READ A = 1000
WRITE B = 600

UPDATE A = 900
UPDATE B = 600
COMMIT;
(Shrinking phase)
                           LOCK B (S) acquired
                           READ B = 600 ✓ (correct)
                           
Result: A = $950, B = $550 ✓
```

---

## Exam Notes

1. **Definition**: Mechanism to manage multiple concurrent transactions
2. **Problems**: Know 4 concurrency problems with examples
3. **Lost Update, Dirty Read, Non-Rep Read, Phantom Read**: Understand each
4. **Techniques**: Lock-based, timestamp, optimistic
5. **2PL**: Most important - two phases (growing/shrinking)
6. **Lock Types**: Shared (S) vs Exclusive (X) with compatibility
7. **Deadlock**: Circular wait concept
8. **Prevention**: Lock ordering, timeout
9. **Examples**: Show realistic scenarios
10. **Trade-offs**: Consistency vs Performance considerations
