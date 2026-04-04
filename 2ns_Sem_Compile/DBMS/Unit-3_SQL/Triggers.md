# Triggers

## Definition

A **trigger** is a stored database action that runs automatically when a specified event occurs on a table.

## Trigger Events

- `BEFORE INSERT`
- `AFTER INSERT`
- `BEFORE UPDATE`
- `AFTER UPDATE`
- `BEFORE DELETE`
- `AFTER DELETE`

## Why Triggers Are Used

- Audit logging
- Automatic value updates
- Validation support
- Enforcing business rules

## Example 1: Audit Trigger

```sql
CREATE TABLE Salary_Audit (
    AuditID INT PRIMARY KEY AUTO_INCREMENT,
    EmployeeID INT,
    OldSalary DECIMAL(10,2),
    NewSalary DECIMAL(10,2),
    ChangedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

```sql
DELIMITER //

CREATE TRIGGER trg_after_salary_update
AFTER UPDATE ON Employees
FOR EACH ROW
BEGIN
    IF OLD.Salary <> NEW.Salary THEN
        INSERT INTO Salary_Audit (EmployeeID, OldSalary, NewSalary)
        VALUES (OLD.EmployeeID, OLD.Salary, NEW.Salary);
    END IF;
END //

DELIMITER ;
```

## Example 2: Auto Timestamp Style Trigger

This pattern also appears in the archived Sakila reference files.

```sql
DELIMITER //

CREATE TRIGGER trg_before_insert_department
BEFORE INSERT ON Departments
FOR EACH ROW
BEGIN
    IF NEW.CreatedAt IS NULL THEN
        SET NEW.CreatedAt = CURRENT_TIMESTAMP;
    END IF;
END //

DELIMITER ;
```

## Exam Notes

- Define trigger first, then list event types.
- Mention `FOR EACH ROW` in syntax.
- Write one practical use such as audit trail or automatic logging.
