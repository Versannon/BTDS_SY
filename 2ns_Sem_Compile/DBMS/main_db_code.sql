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
