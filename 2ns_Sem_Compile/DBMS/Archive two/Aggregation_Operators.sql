DROP DATABASE IF EXISTS aggregation;
CREATE DATABASE aggregation;
USE aggregation;

DROP TABLE IF EXISTS Employee;
CREATE TABLE Employee
(
    Emp_ID INT PRIMARY KEY,
    Emp_Salary INT,
    Emp_Name VARCHAR(255),
    Hire_Date DATE 
);

INSERT INTO Employee (Emp_ID, Emp_Salary, Emp_Name, Hire_Date)
VALUES
    (1, '60000', 'Aisha Khan', '2020-01-15'),
    (2, '75000', 'Rahul Sharma', '2021-03-10'),
    (3, '55000', 'Priya Patel', '2019-11-01'),
    (4, '90000', 'Vikram Singh', '2022-06-20'),
    (5, '48000', 'Neha Gupta', '2018-08-12');

SELECT 
    COUNT(Emp_ID) AS Total_Employees,
    
    SUM(Emp_Salary) AS Total_Salaries,
    
    MIN(Hire_Date) AS Longest_Tenured_Hire_Date,
    
    MAX(Emp_Salary) AS Top_Salary,
    
    AVG(Emp_Salary) AS Average_Salaries
    
FROM 
    Employee;