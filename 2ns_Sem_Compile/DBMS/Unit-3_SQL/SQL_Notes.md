# SQL Notes

## Definition

**SQL (Structured Query Language)** is the standard language used to create, modify, and query relational databases.

## Categories of SQL Commands

### DDL

- `CREATE`
- `ALTER`
- `DROP`
- `TRUNCATE`

### DML

- `INSERT`
- `UPDATE`
- `DELETE`

### DQL

- `SELECT`

### DCL

- `GRANT`
- `REVOKE`

### TCL

- `COMMIT`
- `ROLLBACK`
- `SAVEPOINT`

## Basic Query Form

```sql
SELECT column_list
FROM table_name
WHERE condition
GROUP BY column_name
HAVING group_condition
ORDER BY column_name;
```

## Important Clauses

- `WHERE` filters rows
- `GROUP BY` forms groups
- `HAVING` filters groups
- `ORDER BY` sorts result
- `DISTINCT` removes duplicates

## Example

```sql
SELECT DepartmentID, COUNT(*) AS EmployeeCount
FROM Employees
GROUP BY DepartmentID
HAVING COUNT(*) >= 2;
```

## Exam Notes

- SQL command classification is commonly asked.
- Differentiate `WHERE` and `HAVING`.
- Mention that SQL is declarative, not procedural like relational algebra.
