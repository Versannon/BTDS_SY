# Triggers

## Definition

A **trigger** is a stored database program or action that runs automatically when a specified event occurs on a table.

Triggers are commonly used to:

- respond automatically to data changes
- keep related information synchronized
- maintain audit history
- enforce business rules at the database level

In MySQL, triggers are usually created on tables and are fired by `INSERT`, `UPDATE`, or `DELETE` operations.

## General Syntax

```sql
DELIMITER //

CREATE TRIGGER trigger_name
BEFORE | AFTER
INSERT | UPDATE | DELETE
ON table_name
FOR EACH ROW
BEGIN
    -- SQL statements
END //

DELIMITER ;
```

## Main Parts of a Trigger

- `trigger_name`: name of the trigger
- `BEFORE` or `AFTER`: tells when the trigger should run
- `INSERT`, `UPDATE`, or `DELETE`: the event that activates the trigger
- `ON table_name`: the table on which the trigger is defined
- `FOR EACH ROW`: the trigger runs once for every affected row
- `BEGIN ... END`: block that contains the trigger logic

## Trigger Events

- `BEFORE INSERT`
- `AFTER INSERT`
- `BEFORE UPDATE`
- `AFTER UPDATE`
- `BEFORE DELETE`
- `AFTER DELETE`

## Timing of Triggers

### BEFORE Trigger

A `BEFORE` trigger runs before the actual change is stored in the table.

It is useful for:

- validating input values
- assigning default values
- correcting or formatting data before storage

### AFTER Trigger

An `AFTER` trigger runs after the row has already been inserted, updated, or deleted successfully.

It is useful for:

- audit logging
- recording history
- updating summary or supporting tables
- tracking changes made to important data

## OLD and NEW Keywords

Inside row-level triggers, special keywords are used to access row values:

- `OLD.column_name`: value before the change
- `NEW.column_name`: value after the change

These are used differently depending on the event:

- In `INSERT`, only `NEW` is meaningful because the row is new.
- In `DELETE`, only `OLD` is meaningful because the row is being removed.
- In `UPDATE`, both `OLD` and `NEW` are available.

## Trigger Working Flow

1. A user or application performs an `INSERT`, `UPDATE`, or `DELETE`.
2. The DBMS checks whether a trigger is defined for that event.
3. If a matching trigger exists, the trigger body executes automatically.
4. The original SQL statement then completes with the trigger action included as part of the operation.

## Why Triggers Are Used

- Audit logging
- Automatic value updates
- Validation support
- Enforcing business rules
- Preventing invalid data changes
- Maintaining derived or summary information

## Advantages

- Logic is executed automatically without user intervention.
- Important rules stay close to the data.
- Auditing and history tracking become easier.
- Repeated database tasks can be centralized.

## Limitations

- Too many triggers can reduce performance.
- Debugging becomes harder because actions happen automatically.
- Hidden side effects may confuse developers if triggers are not documented well.
- Complex business logic is often better handled in procedures or application code.

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

### Explanation

- This trigger runs `AFTER UPDATE` on the `Employees` table.
- `OLD.Salary` stores the previous salary and `NEW.Salary` stores the updated salary.
- The `IF` condition ensures that the audit table is updated only when salary actually changes.
- A new row is inserted into `Salary_Audit` to maintain a history of salary modifications.

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

### Explanation

- This is a `BEFORE INSERT` trigger on the `Departments` table.
- If the `CreatedAt` value is not supplied, the trigger assigns `CURRENT_TIMESTAMP`.
- This helps maintain consistent timestamps automatically.

## Common Practical Uses

- Creating audit trails for salary, marks, or account changes
- Automatically filling timestamps like `CreatedAt`
- Preventing invalid values such as negative salary
- Copying deleted records into backup or history tables
- Maintaining log tables for security-sensitive actions

## Trigger Management

### View Existing Triggers

```sql
SHOW TRIGGERS;
```

### Drop a Trigger

```sql
DROP TRIGGER trigger_name;
```

## Exam Notes

- Define a trigger as an automatic database action fired by a table event.
- Write the syntax with timing, event type, table name, and `FOR EACH ROW`.
- Explain the difference between `BEFORE` and `AFTER` triggers.
- Mention how `OLD` and `NEW` are used, especially in `UPDATE`.
- Write one practical example such as audit logging or automatic timestamp insertion.
- If needed, mention one limitation such as debugging difficulty or performance cost.
