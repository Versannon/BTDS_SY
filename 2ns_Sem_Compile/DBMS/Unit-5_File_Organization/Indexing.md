# Indexing

## Definition

An **index** is an auxiliary access structure that improves the speed of data retrieval.

## Why Indexing Is Needed

- Reduces search time
- Avoids full table scans in many cases
- Improves performance of `WHERE`, `JOIN`, and `ORDER BY`

## Types of Indexes

- Primary index
- Secondary index
- Clustered index
- Non-clustered index
- Dense index
- Sparse index
- Composite index
- Unique index

## Advantages

- Faster search
- Faster sorting and joining
- Better query performance

## Limitations

- Extra storage required
- Insert, update, and delete may become slower

## SQL Example

```sql
CREATE INDEX idx_employee_department
ON Employees (DepartmentID);
```

## Exam Notes

- Definition, types, advantages, and limitations form a complete 5-mark answer.
- State that indexes improve retrieval but add maintenance cost.
