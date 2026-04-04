-- Sample data for BTDS211_DBMS
-- Run this file after create_tables.sql.

USE BTDS211_DBMS;

-- Insert department records
INSERT INTO Departments (DepartmentID, DepartmentName, Location) VALUES
(10, 'Computer', 'Pune'),
(20, 'Information Technology', 'Mumbai'),
(30, 'Electronics', 'Nashik'),
(40, 'Mechanical', 'Nagpur');

-- Insert employee records
INSERT INTO Employees (
    EmployeeID,
    FirstName,
    LastName,
    Email,
    Age,
    Salary,
    DepartmentID,
    ManagerID,
    HireDate
) VALUES
(101, 'Rahul', 'Sharma', 'rahul.sharma@example.com', 34, 75000.00, 10, NULL, '2021-06-15'),
(102, 'Priya', 'Patil', 'priya.patil@example.com', 29, 54000.00, 20, 101, '2022-01-10'),
(103, 'Amit', 'Kulkarni', 'amit.kulkarni@example.com', 41, 88000.00, 10, 101, '2020-08-05'),
(104, 'Sneha', 'Jadhav', 'sneha.jadhav@example.com', 27, 48000.00, 30, 103, '2023-02-11'),
(105, 'Arjun', 'Deshmukh', 'arjun.deshmukh@example.com', 31, 62000.00, 20, 101, '2021-11-01'),
(106, 'Neha', 'Joshi', 'neha.joshi@example.com', 38, 69000.00, 40, 101, '2019-09-12');

-- Insert student records
INSERT INTO Students (StudentID, StudentName, Email, Age, DepartmentID) VALUES
(1, 'Aarav Patil', 'aarav.patil@example.com', 20, 10),
(2, 'Diya Kulkarni', 'diya.kulkarni@example.com', 21, 20),
(3, 'Kabir Shinde', 'kabir.shinde@example.com', 19, 10),
(4, 'Meera Pawar', 'meera.pawar@example.com', 22, 30),
(5, 'Rohan More', 'rohan.more@example.com', 20, 20);

-- Insert course records
INSERT INTO Courses (CourseID, CourseCode, CourseName, Credits, DepartmentID) VALUES
(201, 'DBMS101', 'Database Management Systems', 4, 10),
(202, 'OS102', 'Operating Systems', 4, 10),
(203, 'CN103', 'Computer Networks', 3, 20),
(204, 'DS104', 'Data Structures', 4, 10),
(205, 'SE105', 'Software Engineering', 3, 20);

-- Insert enrollment records
INSERT INTO Enrollments (StudentID, CourseID, Semester, Grade) VALUES
(1, 201, 'SEM-IV', 'A'),
(1, 202, 'SEM-IV', 'B+'),
(2, 201, 'SEM-IV', 'A+'),
(2, 203, 'SEM-IV', 'A'),
(3, 204, 'SEM-IV', 'B'),
(4, 201, 'SEM-IV', 'B+'),
(5, 205, 'SEM-IV', 'A');
