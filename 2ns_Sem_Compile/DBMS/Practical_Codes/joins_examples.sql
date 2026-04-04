-- Join examples for BTDS211_DBMS
-- Run after create_tables.sql and insert_sample_data.sql.

USE BTDS211_DBMS;

-- INNER JOIN: employees with their departments
SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName, d.Location
FROM Employees e
INNER JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;

-- LEFT JOIN: keep all employees
SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName
FROM Employees e
LEFT JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;

-- RIGHT JOIN: keep all departments
SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName
FROM Employees e
RIGHT JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;

-- FULL OUTER JOIN simulation for MySQL
SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName
FROM Employees e
LEFT JOIN Departments d
    ON e.DepartmentID = d.DepartmentID
UNION
SELECT e.EmployeeID, e.FirstName, e.LastName, d.DepartmentName
FROM Employees e
RIGHT JOIN Departments d
    ON e.DepartmentID = d.DepartmentID;

-- SELF JOIN: employees and their managers
SELECT
    e.EmployeeID,
    CONCAT(e.FirstName, ' ', e.LastName) AS EmployeeName,
    CONCAT(m.FirstName, ' ', m.LastName) AS ManagerName
FROM Employees e
LEFT JOIN Employees m
    ON e.ManagerID = m.EmployeeID;

-- JOIN with student, enrollment, and course tables
SELECT s.StudentName, c.CourseName, e.Semester, e.Grade
FROM Students s
INNER JOIN Enrollments e
    ON s.StudentID = e.StudentID
INNER JOIN Courses c
    ON e.CourseID = c.CourseID;

-- CROSS JOIN: every student with every course
SELECT s.StudentName, c.CourseName
FROM Students s
CROSS JOIN Courses c;
