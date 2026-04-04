# Transaction Notes

## Definition

A **transaction** is a sequence of database operations treated as one logical unit of work.

## ACID Properties

### Atomicity

Either all operations execute or none execute.

### Consistency

The database moves from one valid state to another valid state.

### Isolation

Concurrent transactions should not interfere incorrectly.

### Durability

Committed changes remain saved even after failure.

## Example

Bank transfer:

```text
Step 1: Debit Account A
Step 2: Credit Account B
Both steps must succeed together.
```

## Transaction Control Commands

- `START TRANSACTION`
- `COMMIT`
- `ROLLBACK`
- `SAVEPOINT`

## SQL Example

```sql
START TRANSACTION;

UPDATE Accounts
SET Balance = Balance - 1000
WHERE AccountID = 1;

UPDATE Accounts
SET Balance = Balance + 1000
WHERE AccountID = 2;

COMMIT;
```

## Exam Notes

- ACID is almost always asked directly.
- Use banking transfer as the standard example.
- Mention that rollback is used when an error occurs.
