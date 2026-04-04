# Constraints

## Definition

Constraints are rules applied on table columns to maintain valid and consistent data.

## Main Constraints

### PRIMARY KEY

- Uniquely identifies each row
- Cannot be `NULL`

### FOREIGN KEY

- Maintains relationship between two tables

### UNIQUE

- Prevents duplicate values

### NOT NULL

- Prevents missing values

### CHECK

- Restricts values using a condition

### DEFAULT

- Assigns a default value when no explicit value is given

## Example

```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    Age INT CHECK (Age >= 17),
    City VARCHAR(30) DEFAULT 'Pune'
);
```

## Exam Notes

- Differentiate key constraints from domain constraints.
- Use one compact `CREATE TABLE` example in theory answers.
