# Views and Constraints

## Views

### Definition

A **view** is a virtual table created from the result of a query.

### Why Views Are Used

- Security
- Simpler query reuse
- Data abstraction
- Logical independence

### Example

```sql
CREATE VIEW Employee_Public_View AS
SELECT EmployeeID, EmployeeName, DepartmentID
FROM Employees;
```

### Simple and Complex Views

- **Simple view**: Based on one table
- **Complex view**: Based on multiple tables or aggregate queries

## Constraints

### Domain Constraint

Restricts the valid values of an attribute.

```sql
Age INT CHECK (Age BETWEEN 18 AND 65)
```

### Entity Integrity

Primary key cannot be `NULL`.

### Referential Integrity

Foreign key must match a valid primary key in another table.

### Unique Constraint

Ensures no duplicate values.

### Not Null Constraint

Ensures a column cannot store `NULL`.

## Example

```sql
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    Age INT CHECK (Age BETWEEN 18 AND 65),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
);
```

## Exam Notes

- Define view as a virtual table.
- Mention security and simplification as two main advantages.
- For constraints, write both definition and one SQL example.
