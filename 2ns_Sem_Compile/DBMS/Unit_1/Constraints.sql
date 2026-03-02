create database ver1;

create table Employees
    (
        EmployeeID INT PRIMARY KEY,
        FirstName VARCHAR(50) NOT NULL,
        LastName VARCHAR(50) NOT NULL,
        Age INT CHECK (Age>=18 AND Age <=65),
        Email VARCHAR(100) UNIQUE,
        DepartmentID INT,
        FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
    );

CREATE TABLE Departments
    (
        DepartmentID INT PRIMARY KEY,
        DepartmentName VARCHAR(100) NOT NULL
    );


select * from Employees;
use ver1;
INSERT INTO Departments (DepartmentID, DepartmentName) VALUES
(1, 'Human Resources'),
(2, 'Finance'),
(3, 'IT'),
(4, 'Marketing'),
(5, 'Operations');

INSERT INTO Employees 
(EmployeeID, FirstName, LastName, Age, Email, DepartmentID) VALUES
(101, 'Rahul', 'Sharma', 28, 'rahul.sharma@example.com', 3),
(102, 'Priya', 'Patel', 32, 'priya.patel@example.com', 2),
(103, 'Amit', 'Verma', 40, 'amit.verma@example.com', 1),
(104, 'Sneha', 'Kulkarni', 25, 'sneha.k@example.com', 4),
(105, 'Arjun', 'Mehta', 35, 'arjun.mehta@example.com', 5),
(106, 'Neha', 'Joshi', 29, 'neha.joshi@example.com', 3),
(107, 'Vikas', 'Reddy', 45, 'vikas.reddy@example.com', 2),
(108, 'Anjali', 'Desai', 30, 'anjali.desai@example.com', 4);

/*Display table*/

Select * from Employees;

/*Linking foreign key*/

