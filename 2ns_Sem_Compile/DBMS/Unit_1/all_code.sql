create database aryandb;
use aryandb;
create table student(
	RollNo int,
    FirstName varchar(255),
    LastName varchar(255),
    Primary Key(RollNo)
	);
insert into student(RollNo,FirstName,LastName) values(8,"Aryan","Suryavanshi");

select * from student;
use aryandb;
create table student(
	RollNo int,
    FirstName varchar(255),
    LastName varchar(255),
    Primary Key(RollNo)
	);
insert into student(RollNo,FirstName,LastName) values(8,"Aryan","Suryavanshi");

select * from student;

drop table student;
use aryandb;
create table employee(
	EmpID int,
    DeptID int,
    EmpName varchar(255)
    );
insert into employee(EmpID,DeptID,EmpName) values(100,2,"Aryan Suryavanshi"),(101,4,"Sashreek Gokhale"),(102,3,"Kartik Mangliya"); 

select * from employee;

create table department(
	DeptID int,
    DeptName varchar(255),
    DeptZone varchar(255)
    );
insert into department(DeptID,DeptName,DeptZone) values(1,"Operations","North"),(2,"Finance","South"),(3,"Marketing","East");

/*Unique Constraints*/

CREATE TABLE Employees
    (
        EmployeeID INT PRIMARY KEY,
        FirstName VARCHAR(50) NOT NULL,
        LastName VARCHAR(50) NOT NULL,
        Age INT CHECK (Age>=18 AND Age <=65),
        Email VARCHAR(100) UNIQUE,
        DepartmentID INT,
        FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
    )

    CREATE TABLE Departments
    (
        DepartmentID INT PRIMARY KEY,
        DepartmentName VARCHAR(100) NOT NULL
    )

    /*(Display table):
    Employees Table:*/
    SELECT * FROM Employees;


/*select * from department;

select Employee.EmpID,Department.DeptName
from Department
right Join Employee on Employee.DeptID=Department.DeptID;

drop database aryandb;

create database aryandb;
use aryandb;
create table employee(
	emp_id int,
	first_name varchar(255),
    last_name varchar(255),
    roll_no int
    );
insert into employee(emp_id,first_name,last_name,roll_no)  values(1,"Aryan","Suryavanshi",8);*/