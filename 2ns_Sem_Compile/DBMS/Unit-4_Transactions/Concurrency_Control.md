# Concurrency Control

## Definition

Concurrency control ensures correct execution when multiple transactions access the same data at the same time.

## Problems Without Concurrency Control

### Lost Update

One transaction overwrites another transaction's update.

### Dirty Read

A transaction reads uncommitted data.

### Non-Repeatable Read

The same row gives different values on repeated reads.

### Phantom Read

Re-executing a query returns a different set of rows.

## Techniques

### Lock-Based Protocols

- Shared lock
- Exclusive lock
- Two-phase locking

### Timestamp-Based Protocols

- Orders transactions by timestamps
- Prevents conflicting operations

### Optimistic Concurrency Control

- Assumes conflicts are rare
- Validates before commit

## Exam Notes

- Write anomaly names with one-line definitions.
- Two-phase locking is an important keyword.
- Compare optimistic and pessimistic control if asked.
