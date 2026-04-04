-- Keys In MySQL
drop database if exists keyss;
create database keyss;
use keyss;

drop table if exists employee;

create table department
(
	Dept_ID int PRIMARY KEY,    -- Primary Key
    Dept_Name varchar(255) NOT NULL
);
insert into Department(Dept_ID,Dept_Name)
Values
(101,'Technlogy');

create table Employee
(
	Emp_ID int,
    Emp_Name varchar(255) NOT NULL,
    Emp_Dept varchar(255) NOT NULL,
    Emp_Age int NOT NULL,
    Emp_Salary int NOT NULL,
    Primary Key(Emp_ID),
    Dept_ID int,
    Foreign Key(Dept_ID) references department(Dept_ID)   -- Foreign Key
);

insert into Employee(Emp_ID,Emp_Name,Emp_Dept,Emp_Age,Emp_Salary,Dept_ID)
Values
(1,'Aryan Suryavanshi','Technology',21,1000000,101);

/*
CREATE TABLE Employee (
    Emp_ID int PRIMARY KEY,   
    Emp_Name varchar(255) NOT NULL,
    Emp_Passport varchar(255) UNIQUE NOT NULL,   -- Candidate Key
    Emp_Age int,
    Emp_Salary int
);

insert into Employee(Emp_ID,Emp_Name,Emp_Passport,Emp_Email,Emp_Age,Emp_Salary)
Values
(1,'Aryan Suryavanshi',12345,'aryan@gmail.com',10000000);

select * from employee;


CREATE TABLE Employee (
    Emp_ID int PRIMARY KEY,   
    Emp_Name varchar(255) NOT NULL,
    Emp_Phone varchar(255) UNIQUE,   -- Unique Key
    Emp_Age int,
    Emp_Salary int
);

insert into Employee(Emp_ID,Emp_Name,Emp_Phone,Emp_Age,Emp_Salary)
Values
(1,'Aryan Suryavanshi',1234567890,21,10000000);

select * from employee;

*/