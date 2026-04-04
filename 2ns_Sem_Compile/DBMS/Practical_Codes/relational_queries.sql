-- Relational and SQL query examples
-- Run after create_tables.sql and insert_sample_data.sql.

USE BTDS211_DBMS;

-- Display all employees
SELECT *
FROM Employees;

-- Display selected employee columns
SELECT EmployeeID, FirstName, LastName, Salary
FROM Employees;

-- Employees with salary greater than average salary
SELECT EmployeeID, FirstName, LastName, Salary
FROM Employees
WHERE Salary > (
    SELECT AVG(Salary)
    FROM Employees
);

-- Employees working in Pune or Mumbai locations using nested subquery
SELECT EmployeeID, FirstName, LastName, DepartmentID
FROM Employees
WHERE DepartmentID IN (
    SELECT DepartmentID
    FROM Departments
    WHERE Location IN ('Pune', 'Mumbai')
);

-- Count employees department-wise
SELECT DepartmentID, COUNT(*) AS EmployeeCount
FROM Employees
GROUP BY DepartmentID;

-- Average salary department-wise with HAVING
SELECT DepartmentID, AVG(Salary) AS AverageSalary
FROM Employees
GROUP BY DepartmentID
HAVING AVG(Salary) >= 60000;

-- Student and course details using EXISTS
SELECT StudentID, StudentName
FROM Students s
WHERE EXISTS (
    SELECT 1
    FROM Enrollments e
    WHERE e.StudentID = s.StudentID
);

-- Create a simple view
CREATE OR REPLACE VIEW HighSalaryEmployees AS
SELECT EmployeeID, FirstName, LastName, Salary, DepartmentID
FROM Employees
WHERE Salary >= 70000;

-- Query the view
SELECT *
FROM HighSalaryEmployees;

-- Students enrolled in DBMS course
SELECT s.StudentName
FROM Students s
WHERE s.StudentID IN (
    SELECT e.StudentID
    FROM Enrollments e
    WHERE e.CourseID = 201
);

-- Aggregate query on courses
SELECT c.CourseName, COUNT(e.StudentID) AS TotalStudents
FROM Courses c
LEFT JOIN Enrollments e
    ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName
ORDER BY TotalStudents DESC;
