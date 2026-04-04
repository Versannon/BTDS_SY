-- Trigger examples
-- Run after create_tables.sql and insert_sample_data.sql.

USE BTDS211_DBMS;

-- Audit table for salary changes
CREATE TABLE IF NOT EXISTS Salary_Audit (
    AuditID INT PRIMARY KEY AUTO_INCREMENT,
    EmployeeID INT NOT NULL,
    OldSalary DECIMAL(10,2) NOT NULL,
    NewSalary DECIMAL(10,2) NOT NULL,
    ChangedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

DROP TRIGGER IF EXISTS trg_before_insert_department;
DROP TRIGGER IF EXISTS trg_after_update_employee_salary;

DELIMITER //

-- Automatically fill CreatedAt if not provided
CREATE TRIGGER trg_before_insert_department
BEFORE INSERT ON Departments
FOR EACH ROW
BEGIN
    IF NEW.CreatedAt IS NULL THEN
        SET NEW.CreatedAt = CURRENT_TIMESTAMP;
    END IF;
END //

-- Maintain audit log after salary updates
CREATE TRIGGER trg_after_update_employee_salary
AFTER UPDATE ON Employees
FOR EACH ROW
BEGIN
    IF OLD.Salary <> NEW.Salary THEN
        INSERT INTO Salary_Audit (EmployeeID, OldSalary, NewSalary)
        VALUES (OLD.EmployeeID, OLD.Salary, NEW.Salary);
    END IF;
END //

DELIMITER ;

-- Trigger demonstration
INSERT INTO Departments (DepartmentID, DepartmentName, Location)
VALUES (50, 'Civil', 'Satara');

UPDATE Employees
SET Salary = Salary + 5000
WHERE EmployeeID = 102;

-- Check results
SELECT *
FROM Departments
WHERE DepartmentID = 50;

SELECT *
FROM Salary_Audit;
