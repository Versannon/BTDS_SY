# Queries

## Simple Query

```sql
SELECT EmployeeID, EmployeeName
FROM Employees;
```

## Conditional Query

```sql
SELECT EmployeeName, Salary
FROM Employees
WHERE Salary > 50000;
```

## Join Query

```sql
SELECT e.EmployeeName, d.DepartmentName
FROM Employees e
INNER JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;
```

## Aggregate Query

```sql
SELECT DepartmentID, AVG(Salary) AS AverageSalary
FROM Employees
GROUP BY DepartmentID;
```

## Nested Query

```sql
SELECT EmployeeName
FROM Employees
WHERE Salary > (
    SELECT AVG(Salary)
    FROM Employees
);
```

## View Query

```sql
CREATE VIEW IT_Employees AS
SELECT EmployeeID, EmployeeName, Salary
FROM Employees
WHERE DepartmentID = 2;
```

## Exam Notes

- Learn at least one example each of simple, join, aggregate, and nested query.
- Nested query answers become stronger if you state that the inner query runs first.
