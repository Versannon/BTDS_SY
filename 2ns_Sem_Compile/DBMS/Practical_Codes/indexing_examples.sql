-- Indexing examples
-- Run after create_tables.sql and insert_sample_data.sql.

USE BTDS211_DBMS;

-- Index on employee last name for faster search
CREATE INDEX idx_employees_lastname
ON Employees (LastName);

-- Composite index on department and salary
CREATE INDEX idx_employees_department_salary
ON Employees (DepartmentID, Salary);

-- Unique index on course code
CREATE UNIQUE INDEX idx_courses_coursecode
ON Courses (CourseCode);

-- Index on enrollment course id
CREATE INDEX idx_enrollments_course
ON Enrollments (CourseID);

-- Example queries that can benefit from indexes
SELECT *
FROM Employees
WHERE LastName = 'Patil';

SELECT *
FROM Employees
WHERE DepartmentID = 20
  AND Salary >= 50000;

SELECT *
FROM Courses
WHERE CourseCode = 'DBMS101';
