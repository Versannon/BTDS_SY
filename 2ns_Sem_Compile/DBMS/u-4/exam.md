# UNIT–IV: Transaction Property (Detailed Theory)

This unit covers **transactions**, their **ACID properties**, **concurrency anomalies**, **serializability**, **recoverability**, **isolation protocols**, and **recovery/log-based techniques**.

---

## Quick Index

1. [Transaction Concept](#1-transaction-concept)
2. [Transaction States](#2-transaction-states)
3. [ACID Properties](#3-acid-properties-core-of-transactions)
4. [Concurrent Execution of Transactions](#4-concurrent-execution-of-transactions)
5. [Serializability](#5-serializability)
6. [Recoverability](#6-recoverability)
7. [Implementation of Isolation](#7-implementation-of-isolation)
8. [Testing for Serializability](#8-testing-for-serializability)
9. [Recovery and Atomicity](#9-recovery-and-atomicity)
10. [Log-Based Recovery](#10-log-based-recovery)
11. [Recovery with Concurrent Transactions](#11-recovery-with-concurrent-transactions)

---

## 1. Transaction Concept

A **transaction** is a sequence of database operations (read/write) executed as **one logical unit of work**. The DBMS guarantees that a transaction is treated as an **atomic unit**:

- either **all** its operations complete successfully (**commit**), or
- **none** of them take effect (**abort/rollback**).

### Example: Bank Transfer (Account A → Account B)

1. Debit ₹1000 from Account A  
2. Credit ₹1000 to Account B

If the system fails **after the debit but before the credit**, the database becomes inconsistent (money appears “lost”). Transactions prevent this by ensuring the whole transfer is applied **completely** or **not at all**.

### Basic Transaction Commands (Conceptual)

- `BEGIN/START TRANSACTION` : marks the start
- `COMMIT` : permanently makes changes
- `ROLLBACK/ABORT` : undoes changes

---

## 2. Transaction States

During execution, a transaction moves through well-defined states:

```
Active  →  Partially Committed  →  Committed
   ↘
   Failed  →  Aborted
```

### State Meaning

1. **Active**
   - Transaction is executing its read/write operations.
2. **Partially Committed**
   - Last statement executed; system is performing final checks and preparing to make updates permanent.
3. **Committed**
   - Effects are permanently recorded in the database (durable).
4. **Failed**
   - Error occurs (crash, deadlock, constraint violation, etc.).
5. **Aborted**
   - Transaction is rolled back completely.

**Important:** After abort, a transaction may **restart** (retry) or **terminate** depending on the failure type and policy.

---

## 3. ACID Properties (Core of Transactions)

ACID properties guarantee correctness and reliability.

### A — Atomicity (“All or Nothing”)

- Entire transaction must happen completely or not at all.
- No partial updates are allowed.

**Example:**  
If A is debited (5000 → 4000) and crash occurs before crediting B, atomicity ensures rollback restores A to 5000.

**How DBMS supports it:**
- **UNDO** (rollback) using logs / before-images.

### C — Consistency

- Database must move from **one valid state to another valid state**.
- All integrity constraints must remain true:
  - Primary key, foreign key
  - `CHECK` constraints, domain constraints
  - Application rules (e.g., balance can’t go negative)

**Example:** In bank transfer, the **total money** across accounts remains constant.

> Note: The DBMS provides mechanisms (constraints, triggers, transactions), but **the transaction logic must be written correctly** to preserve consistency.

### I — Isolation

- Concurrent transactions must not interfere with each other.
- Each transaction should behave *as if* it is executing alone.

**Without isolation, common anomalies occur:**
- Dirty Read
- Lost Update
- Non-repeatable Read
- Phantom Read

### D — Durability

- Once a transaction commits, its effects are permanent.
- Even if the system crashes after commit, results must persist.

**Achieved using:**
- Log files (Write-Ahead Logging)
- Recovery mechanisms (REDO during restart)

---

## 4. Concurrent Execution of Transactions

**Concurrent execution** means multiple transactions run simultaneously (interleaving operations) to improve performance.

### Why concurrency is needed

- Better CPU and disk utilization
- Higher throughput (more transactions per second)
- Faster response time
- Supports multi-user/multi-application environments

### Problems without proper control (Anomalies)

#### 1) Lost Update
Two transactions update the same item; one update overwrites the other.

#### 2) Dirty Read
One transaction reads data written by another transaction that has **not committed**.

#### 3) Non-repeatable Read
The same `SELECT` by a transaction returns different values because another transaction modified and committed the row.

#### 4) Phantom Read
Re-running a query returns a different **set of rows** because another transaction inserted/deleted rows that match the query condition.

> These anomalies reduce correctness and can violate consistency. Hence, concurrency control is required.

---

## 5. Serializability

### Definition

A schedule (interleaving of operations) is **serializable** if it produces the same final database state as **some serial (one-by-one) execution** of the same transactions.

Serializability is the standard correctness criterion for concurrent schedules.

### Types

1. **Conflict Serializability**
   - Based on the ordering of **conflicting operations**.
   - Two operations conflict if:
     - they are in different transactions,
     - access the same data item, and
     - at least one is a write (`W`).
   - Tested using a **precedence (serialization) graph**.

2. **View Serializability**
   - Two schedules are view-equivalent if they:
     - read the same initial values,
     - read values written by the same transactions, and
     - produce the same final write for each data item.
   - More general than conflict serializability (but harder to test).

### Precedence Graph Method (for Conflict Serializability)

Steps:

1. Create a node for each transaction `Ti`.
2. Add a directed edge `Ti → Tj` if an operation of `Ti` conflicts with and precedes an operation of `Tj` on the same item.
3. If the graph has **no cycle**, schedule is **conflict serializable**.
4. If the graph has a **cycle**, schedule is **not serializable**.

---

## 6. Recoverability

### Definition

A schedule is **recoverable** if transactions commit only after all transactions whose changes they have read are committed.

Meaning: if `T2` reads a value written by `T1`, then **`T2` must not commit before `T1` commits**.

### Types of Schedules

1. **Recoverable Schedule**
   - If `T2` reads from `T1`, then commit order must satisfy: `C1` before `C2`.

2. **Cascading Rollback**
   - If a transaction aborts, all transactions that read its uncommitted data must also abort.
   - Causes a “domino effect”.

3. **Cascadeless Schedule**
   - Transactions read only **committed** data.
   - Prevents cascading rollbacks (stronger safety).

> In practice, many DBMS aim for cascadeless behavior by preventing dirty reads.

---

## 7. Implementation of Isolation

Isolation is enforced using **concurrency control protocols**.

### 7.1 Lock-Based Protocol

Locks control access to data items.

| Lock Type | Symbol | Purpose | Compatibility |
|---|---:|---|---|
| Shared | `S` | Read | Multiple `S` allowed |
| Exclusive | `X` | Write | Blocks all other locks |

- If a transaction holds an `S` lock on a data item, other transactions can also take `S` on it (read-read is fine).
- If any transaction holds an `X` lock, no other `S`/`X` lock is allowed (write requires isolation).

### 7.2 Two-Phase Locking (2PL)

2PL guarantees conflict serializability by dividing locking into two phases:

1. **Growing phase**: acquire locks, cannot release any.
2. **Shrinking phase**: release locks, cannot acquire new ones.

Pros:
- Ensures conflict serializability.

Cons:
- Can cause **deadlocks** (T1 waits for T2 and T2 waits for T1).

> **Strict 2PL** (commonly used): hold all write (`X`) locks until commit/abort, which also helps recovery (prevents dirty reads/writes).

### 7.3 Timestamp Protocol

- Each transaction gets a unique **timestamp**.
- The protocol enforces an ordering based on timestamps (older transactions get priority).

Pros:
- Avoids deadlocks (no waiting; conflicts cause abort).

Cons:
- Can lead to more rollbacks under high conflict.

### 7.4 Validation-Based Protocol (Optimistic CC)

Phases:

1. **Read phase**: execute without locks, collect read/write sets.
2. **Validation phase**: check whether conflicts occurred.
3. **Write phase**: apply updates if validation succeeds; otherwise rollback.

Best suited when:
- Conflicts are rare (e.g., mostly reads).

### 7.5 Multiple Granularity Locking

Locks can be applied at different levels:

- Database level
- Table level
- Page/block level
- Row level

Benefit:
- Improves efficiency by choosing appropriate granularity (coarse locks reduce overhead; fine locks increase concurrency).

---

## 8. Testing for Serializability

The standard exam method:

1. Construct the **precedence graph**.
2. Check for **cycles**:
   - No cycle → **Serializable**
   - Cycle → **Not serializable**

Tip: While drawing edges, focus only on **conflicting pairs** (RW, WR, WW) on the same data item.

---

## 9. Recovery and Atomicity

Recovery ensures:

- **Atomicity**: uncommitted changes are undone (UNDO).
- **Durability**: committed changes survive crashes (REDO).

### Types of Failures

1. **Transaction failure**
   - Logical error, constraint violation, deadlock victim, etc.
2. **System crash**
   - Power failure, OS crash; main memory contents lost.
3. **Media failure**
   - Disk crash/corruption; stable storage affected.

### Recovery Techniques

#### 1) Immediate Update

- Database may be updated **before commit**.
- Requires both:
  - **UNDO** (for uncommitted transactions)
  - **REDO** (for committed transactions, if changes not fully on disk)

#### 2) Deferred Update

- Updates are applied to the database **only after commit**.
- Needs only:
  - **REDO** (because uncommitted updates are never written to DB)

### Checkpointing

A **checkpoint** records a consistent point in the log and often forces dirty pages to disk (implementation dependent).

Why checkpointing helps:
- Reduces recovery time by limiting how far back the system must scan logs.

General idea:
- Only log records **after the last checkpoint** are considered during recovery (again, depending on the algorithm).

### Typical Recovery Phases (Conceptual)

1. **Analysis**: determine which transactions were active/committed at crash time.
2. **Redo**: re-apply actions of committed transactions if needed.
3. **Undo**: roll back actions of incomplete transactions.

---

## 10. Log-Based Recovery

The DBMS maintains a **log** on stable storage to support UNDO/REDO.

### Log Record Structure

Common format:

`<Ti, Data Item, Old Value, New Value>`

Used for:

- **UNDO**: restore `Old Value`
- **REDO**: reapply `New Value`

### Example

```
<T1, A, 5000, 4000>
<T1, B, 3000, 4000>
<COMMIT T1>
```

Durability principle:
- If the system crashes after commit, the log helps **redo** the committed changes.

> (Extra theory) **Write-Ahead Logging (WAL)** rule: the log record describing an update must be written to stable storage **before** the actual database page is written. This guarantees recovery can always redo/undo safely.

---

## 11. Recovery with Concurrent Transactions

In real systems, multiple transactions run concurrently, so logs must preserve enough ordering information.

At recovery time:

- **Committed transactions** → **REDO** (ensure their updates are reflected)
- **Uncommitted/active transactions** → **UNDO** (remove partial effects)

This ensures the database returns to a **consistent state**, even under failures in a multi-user environment.

---

### Exam Pointers (1–2 Lines Each)

- **ACID**: Atomicity(UNDO), Consistency(constraints), Isolation(concurrency control), Durability(REDO + logs).
- **Serializability**: precedence graph, cycle test.
- **Recoverability**: avoid commit-before-writer-commit; cascadeless prevents dirty reads.
- **2PL**: serializable but deadlocks possible; strict 2PL improves recovery safety.

---

# UNIT–IV: Important Theory Questions (With Answers)

## Q1. Define a transaction. Explain its characteristics.

**Answer:**

A **transaction** is a sequence of operations performed as a **single logical unit of work**.

It must either:

- complete fully → **COMMIT**
- fail completely → **ROLLBACK**

**Example**

```sql
START TRANSACTION;
UPDATE Accounts SET Balance = Balance - 1000 WHERE ID = 1;
UPDATE Accounts SET Balance = Balance + 1000 WHERE ID = 2;
COMMIT;
```

**Characteristics (ACID):**

- Atomic
- Consistent
- Isolated
- Durable

Transaction ensures **reliability** and **integrity** of the database.

---

## Q2. Explain ACID properties in detail.

**Answer:**

1. **Atomicity**: All operations succeed or none.
2. **Consistency**: Database remains valid (constraints hold).
3. **Isolation**: Transactions don’t interfere with each other.
4. **Durability**: Changes persist after commit.

**Diagram**

```
Transaction
   ↓
ACID Properties
├─ Atomicity
├─ Consistency
├─ Isolation
└─ Durability
```

---

## Q3. Explain different transaction states with diagram.

**Answer:**

**States:**

- Active
- Partially Committed
- Committed
- Failed
- Aborted

**Diagram**

```
Active → Partially Committed → Committed
   ↓
 Failed → Aborted
```

---

## Q4. What is concurrency? Explain its advantages.

**Answer:**

**Concurrency** = Multiple transactions executing simultaneously.

**Advantages:**

- Faster execution
- Better resource utilization
- Multi-user support

**Problem:** Data inconsistency without control → requires **concurrency control**.

---

## Q5. Explain lost update problem with example.

**Answer:**

Occurs when one transaction’s update overwrites another’s update.

**Example**

- T1: Read A = 1000  
- T2: Read A = 1000  
- T1: Write A = 1100  
- T2: Write A = 950  ← lost update

Final value becomes incorrect.

---

## Q6. Explain dirty read, non-repeatable read, and phantom read.

**Answer:**

- **Dirty Read**: Reading **uncommitted** data.
- **Non-repeatable Read**: Same query returns **different values** due to another committed update.
- **Phantom Read**: Same query returns **different set of rows** due to inserts/deletes by others.

**Diagram**

```
Problem Types:
├─ Dirty Read
├─ Non-repeatable Read
└─ Phantom Read
```

---

## Q7. Define serializability. Explain its types.

**Answer:**

**Serializability** ensures correctness of concurrent execution by making the result equivalent to some **serial execution**.

**Types:**

- Conflict Serializability
- View Serializability

---

## Q8. Explain precedence graph method.

**Answer:**

**Steps:**

1. Create nodes for transactions.
2. Add directed edges for conflicts.
3. Check cycles.

**Diagram**

```
T1 → T2 → T3
↑        ↓
└────────┘  (Cycle → Not Serializable)
```

No cycle → **Serializable**.

---

## Q9. What is recoverability? Explain types.

**Answer:**

Recoverability ensures transactions commit in a **safe order** (a transaction that reads from another should not commit before it).

**Types:**

- Recoverable schedule
- Cascading rollback
- Cascadeless schedule

---

## Q10. Explain lock-based protocols.

**Answer:**

Locks control access to data items to ensure isolation.

**Types:**

- Shared (Read)
- Exclusive (Write)

| Lock | Use |
|---:|---|
| S | Read |
| X | Write |

---

## Q11. Explain Two-Phase Locking (2PL).

**Answer:**

**Phases:**

- Growing: acquire locks
- Shrinking: release locks

**Diagram**

```
Growing Phase → Lock Point → Shrinking Phase
```

- Guarantees serializability  
- May cause deadlock

---

## Q12. Explain timestamp-based protocol.

**Answer:**

- Each transaction gets a timestamp.
- Older transaction gets priority.

**Rule (idea):**

If `TS(T1) < TS(T2)` then `T1` is treated as earlier in ordering.

- No deadlocks
- Rollbacks possible

---

## Q13. Explain validation-based protocol.

**Answer:**

**Phases:**

- Read phase
- Validation phase
- Write phase

- No locks used during execution
- Good for low-conflict environments

---

## Q14. Explain multiple granularity locking.

**Answer:**

Locks are applied at different levels:

- Database
- Table
- Row

Improves efficiency and concurrency when chosen appropriately.

---

## Q15. Explain deadlock and prevention methods.

**Answer:**

**Deadlock** = circular waiting among transactions.

**Diagram**

```
T1 → waits for T2
T2 → waits for T1
```

**Prevention methods:**

- Lock ordering
- Timeout

---

## Q16. Explain recovery techniques.

**Answer:**

**Techniques:**

- Immediate Update
- Deferred Update

Recovery uses logs to ensure atomicity and durability.

---

## Q17. Explain checkpoint mechanism.

**Answer:**

Checkpoint saves system state to reduce recovery time.

**Process (concept):**

- Stop/slow new transactions briefly
- Flush buffers / write necessary info
- Write checkpoint record

**Benefit:** Faster recovery.

---

## Q18. Explain log-based recovery.

**Answer:**

**Log format:**

`<Ti, Data Item, Old Value, New Value>`

**Types:**

- Undo log
- Redo log

Ensures durability and supports rollback/redo.

---

## Q19. Explain recovery process after crash.

**Answer:**

**Phases:**

- Analysis
- Redo
- Undo

**Flow**

```
Crash → Analysis → Redo → Undo → Consistent DB
```

---

## Q20. Explain recovery with concurrent transactions.

**Answer:**

Multiple transactions execute and are logged; recovery ensures:

- Committed → **REDO**
- Uncommitted → **UNDO**

Maintains consistency using the log system.
