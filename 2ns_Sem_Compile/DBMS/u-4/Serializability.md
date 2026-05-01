# Serializability

## Definition

Serializability is the correctness criterion for concurrent schedules. A schedule is serializable if its effect is equivalent to some serial execution of the same transactions.

## Types

### Conflict Serializability

Two schedules are conflict equivalent if non-conflicting operations can be swapped to obtain the same order.

### View Serializability

Two schedules are view equivalent if they read and write the same values in a logically equivalent way.

## Precedence Graph Method

### Steps

1. Create one node for each transaction.
2. Draw an edge from `Ti` to `Tj` if `Ti` performs a conflicting operation before `Tj`.
3. If the graph has no cycle, the schedule is conflict serializable.

## Example

```text
T1: R(X) W(X)
T2: R(X) W(X)

If T1 writes X before T2 reads or writes X, draw T1 -> T2
```

## Exam Notes

- Definition plus graph method is enough for most 5-mark answers.
- No cycle means serializable.
- A cyclic precedence graph implies not conflict serializable.
