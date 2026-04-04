# Relational Algebra

## Definition

Relational algebra is a **procedural query language** used to perform operations on relations.

## Fundamental Operations

### Selection

- Symbol: `sigma`
- Purpose: Select rows satisfying a condition

Example:

```text
sigma Salary > 50000 (Employee)
```

SQL equivalent:

```sql
SELECT *
FROM Employees
WHERE Salary > 50000;
```

### Projection

- Symbol: `pi`
- Purpose: Select specific columns

Example:

```text
pi EmployeeName, Salary (Employee)
```

### Union

- Combines tuples from compatible relations
- Removes duplicates

### Intersection

- Gives tuples common to both relations

### Difference

- Gives tuples present in first relation but not in second

### Cartesian Product

- Combines every row of one relation with every row of another relation

### Join

- Combines related tuples from two relations

## Common Join Forms

- Theta join
- Equi join
- Natural join

## Example

```text
pi EmployeeName, DepartmentName (
    Employee join Department
)
```

SQL equivalent:

```sql
SELECT e.EmployeeName, d.DepartmentName
FROM Employees e
INNER JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;
```

## Diagram

```text
Selection  -> filters rows
Projection -> filters columns
Join       -> combines related tables
```

## Exam Notes

- Write symbol, meaning, and one example for each operation.
- Mention that union, intersection, and difference require union compatibility.
- Join is often asked with an SQL equivalent.
