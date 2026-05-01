# Recovery - Comprehensive Guide

## Definition

**Recovery** is the process of restoring database to consistent state after failure using backup and transaction logs.

## Types of Failures

### 1. Transaction Failure

**Definition**: Transaction fails before completion due to logical error, constraint violation, or explicit abort.

**Causes**:
- Constraint violation (duplicate key)
- Arithmetic error (division by zero)
- Logical error in transaction code
- Explicit abort/ROLLBACK command

**Example**:
```
Transaction T1:
├─ UPDATE Account SET Balance = Balance - 1000 WHERE ID = 1;
├─ UPDATE Account SET Balance = Balance + 1000 WHERE ID = 2;
├─ CHECK: Both accounts must have Balance >= 0
├─ Account 2 validation FAILS! (would be negative)
└─ Automatic ROLLBACK

Recovery needed: Undo all changes
```

**Recovery Strategy**: UNDO all operations

---

### 2. System Crash

**Definition**: System crashes (power failure, OS crash) causing loss of main memory but disk data preserved.

**Characteristics**:
- Database in memory lost
- Committed data on disk preserved
- Uncommitted transactions lost
- Buffer cache cleared

**Recovery Strategy**: 
- REDO committed transactions
- UNDO incomplete transactions

---

### 3. Media Failure

**Definition**: Permanent damage to disk causing data loss.

**Characteristics**:
- Disk data lost
- Requires backup restoration
- Time-consuming recovery
- Potential data loss

**Recovery Strategy**: 
- Restore from backup
- Reapply logs
- Accept data loss since last backup

## Transaction Log

### Definition

A **transaction log** is persistent storage recording all database modifications before they're applied.

### Log Structure

```
Log File:
┌───────────────────────────────────────┐
│ <Start T1>                            │
│ <T1, Account_1, Before: 5000>         │
│ <T1, Account_1, After: 4000>          │
│ <T1, Account_2, Before: 3000>         │
│ <T1, Account_2, After: 4000>          │
│ <Commit T1>                           │ ← Durability point
│ <Start T2>                            │
│ <T2, Course_1, Before: 30>            │
│ <T2, Course_1, After: 29>             │
│ <Abort T2>                            │
└───────────────────────────────────────┘
```

### Log Entry Format

```
<TransactionID, Object, OldValue, NewValue>

Examples:
<T1, Account_1, 5000, 4000>     ← Debit $1000
<T1, Account_2, 3000, 4000>     ← Credit $1000
<T2, Salary, 50000, 55000>      ← Raise salary
```

## Recovery Techniques

### 1. Immediate Update

```
Immediate Update Strategy:

├─ Update main database immediately
├─ BEFORE changing: Write UNDO log entry
├─ AFTER change: Write REDO log entry

Example: T1 Deposit $100
├─ Write UNDO entry: <T1, Account_2, 3000>
├─ Update Account_2 to 4000
├─ Write REDO entry: <T1, Account_2, 4000>

Advantage: No REDO needed for committed transactions
Disadvantage: High disk I/O
```

### 2. Deferred Update

```
Deferred Update Strategy:

├─ DON'T update main database immediately
├─ Write log entries
├─ At COMMIT: Apply all changes together
├─ UNDO: No need (never changed DB)
└─ REDO: Apply logged changes

Example: T1 Deposit $100
├─ Write log entries (no DB changes)
├─ Write COMMIT marker
├─ Apply all changes from log to database

Advantage: Never need UNDO
Disadvantage: Need REDO for all committed
```

### 3. Checkpoint-Based Recovery

#### Checkpoint Concept

```
Without Checkpoints:
Crash → Scan entire log from beginning → Slow

With Checkpoints:
Last Checkpoint at 1:00 PM
Crash at 2:00 PM
  ↓
Scan log from 1:00 PM only → Fast!
```

#### Checkpoint Process

```
Checkpoint Operation:

1. Stop accepting new transactions
2. Complete all active transactions
3. Write Checkpoint marker to log
4. Flush all modified buffers to disk
5. Resume transactions

Log with Checkpoints:
<Start T1>
<T1, Account_1, 5000, 4000>
<Commit T1>
<Start T2>
<CHECKPOINT: Active = {T2}>  ← Marker
<T2, Account_2, 3000, 4000>
<Commit T2>
```

## Crash Recovery Algorithm

### Step 1: Analysis Phase

```
Scan log from last checkpoint forward
Build transaction status:

Active Transactions (to UNDO):
├─ T2 (started after checkpoint)
├─ T3 (started after checkpoint)

Committed Transactions (to REDO):
├─ T1 (COMMIT before crash)
├─ T2 (COMMIT before crash)
```

### Step 2: Redo Phase

```
Scan log forward from checkpoint
For each committed transaction entry:

<T2, Account, 3000, 4000>
  ├─ If T2 committed:
  ├─ Apply: Account = 4000
  └─ (Restore committed changes)

Purpose: Restore changes from memory
```

### Step 3: Undo Phase

```
Scan log backward from END
For each uncommitted transaction entry:

<T3, Salary, 50000, 55000> (backward)
  ├─ If T3 NOT committed:
  ├─ Reverse: Salary = 50000
  └─ (Continue backward to START T3)

Purpose: Remove incomplete transactions
```

---

## Real-World Example: Bank

### Scenario

```
Account A: $5000, B: $3000, C: $2000

T1: Transfer $1000 from A to B (COMPLETED)
T2: Transfer $500 from B to C (IN PROGRESS)

System crashes during T2
```

### Recovery

```
Log Entries Before Crash:
<Start T1>
<T1, A, 5000, 4000>
<T1, B, 3000, 4000>
<Commit T1>          ← T1 committed
<Start T2>
<T2, B, 4000, 3500>
<T2, C, 2000, 2500>
(CRASH - no Commit T2)

Recovery Steps:

1. Analysis: REDO T1, UNDO T2

2. Redo Phase (forward):
   Apply T1 entries:
   A = 4000, B = 4000

3. Undo Phase (backward):
   Reverse T2 entries:
   C = 2000, B = 4000

Final: A=$4000, B=$4000, C=$2000
T1 saved, T2 rolled back
Consistency maintained!
```

## Strategy Comparison

| Strategy | Undo | Redo | Disk I/O | Speed |
|----------|------|------|---------|-------|
| Immediate | Yes | No | High | Slow |
| Deferred | No | Yes | Medium | Fast |
| Checkpoint | Yes | Yes | Low | Very Fast |

## Practical SQL

```sql
-- Transaction with logging
START TRANSACTION;

-- Each operation logged before execution
UPDATE Account SET Balance = Balance - 1000 
WHERE AccountID = 1;
-- Log entry written to disk first

UPDATE Account SET Balance = Balance + 1000 
WHERE AccountID = 2;
-- Log entry written to disk first

COMMIT;
-- Commit marker written to log
-- Transaction durable even if crash next instant
```

---

## Exam Notes

1. **Definition**: Restoring DB to consistent state after failure
2. **Failures**: Know 3 types (transaction, system, media)
3. **Transaction Log**: Persistent storage of modifications
4. **UNDO/REDO**: When to use each
5. **Checkpoints**: Purpose and benefit for recovery
6. **Recovery Steps**: Analysis → Redo → Undo phases
7. **Immediate vs Deferred**: Understand trade-offs
8. **Practical Examples**: Show bank transfer scenario
9. **Durability**: Log ensures persistence
10. **Performance**: Checkpoint strategy improves speed

### Deferred Update

Updates are applied to the database after commit.

### Immediate Update

Updates may reach the database before commit, so both `UNDO` and `REDO` may be needed.

## Diagram

```text
Failure -> Check log -> Undo/Redo -> Consistent state
```

## Exam Notes

- Define recovery first.
- Write `UNDO`, `REDO`, and checkpoint in bold points in written exams.
- Differentiate deferred and immediate update in one small table if time permits.
