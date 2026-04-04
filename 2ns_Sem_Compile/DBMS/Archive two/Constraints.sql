-- INTEGRITY CONSTRAINTS (ENTITY , REFERNTIAL , DOMAIN , USER-DEFINED , CHECK)
drop database if exists Constraints;
create database Constraints;
use Constraints;

drop table if exists department;
create table department
(
	Dept_ID int Primary Key,
    Dept_Name varchar(255) NOT NULL
);

insert into department(Dept_ID,Dept_Name)
values
(101,'Technology'),
(102,'Developer');

drop table if exists employee;
create table employee
(
	Emp_ID int Primary Key,     -- ENTITY CONSTRAINT
    Emp_Name varchar(255) NOT NULL,    -- DOMAIN CONSTRAINT AND NOT NULL CONSTRAINT
    Emp_Age int NOT NULL,   -- DOMAIN AND NOT NULL CONSTRAINT
    Check (Emp_Age >= 20 AND Emp_Age <= 30),  -- User-defined Constraint (Peak Working Hours)
    Check(Emp_Age >= 30 AND Emp_Age <= 60),   -- CHECK CONSTRAINT
    Dept_ID int,
    Foreign Key(Dept_ID) references department(Dept_ID) -- Referential Constraint
);
insert into employee(Emp_ID,Emp_Name,Emp_Age,Dept_ID)
values
(1,'Aryan Suryavanshi',30,102),
(2,'Dhawal Chaudhari',30,101);