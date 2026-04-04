# Recovery

## Definition

Recovery is the process of restoring the database to a consistent state after a failure.

## Types of Failures

- Transaction failure
- System crash
- Media failure

## Recovery Concepts

### Log-Based Recovery

A log stores information about updates so the system can:

- `UNDO` incomplete transactions
- `REDO` committed transactions

### Checkpoint

A checkpoint saves a known good state and reduces recovery time.

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
