-- Basic
drop database if exists Basic;
create database Basic;
use Basic;

drop table if exists Employee;

Create table Employee
(
	Emp_ID int,
    Emp_Name varchar(255),
    Emp_Dept varchar(255),
    Emp_No varchar(255),
    Emp_Age int,
    Emp_Salary int
);

-- DDL COMMANDS (CREATE , DROP , ALTER , TRUNCATE)

Alter table employee
Modify Emp_NO int;

Truncate table Employee;

Drop Table Employee;

-- DML COMMANDS (SELECT , INSERT , DELETE , UPDATE )

Insert into Employee(Emp_ID,Emp_Name,Emp_Dept_Emp_No,Emp_Age,Emp_Salary) 
Values
(1,'Aryan Suryavanshi','Technology',1234567890,21,10000000),
(2,'Dhawal Chaudhari','Technology',1256723441,21,10000);

Update Employee
Set Emp_Age = 20
Where Emp_ID = 2;

Delete from Employee
Where Emp_ID = 2;

Select * from Employee;

-- DCL COMMANDS ( GRANT , REVOKE)

Create USER 'Priyanka_Mam' IDENTIFIED BY '1234'; -- Before creating a grant the user must exist.

Grant Insert,Select   /*All privileges (All commands)*/
On Employee
To Priyanka_Mam
With Grant option;

Revoke Insert,Select On Employee FROM 'Priyanka_Mam';


-- TCL COMMANDS (SAVEPOINT , ROLLBACK , COMMIT)

UPDATE Employee 
SET Emp_Salary = Emp_Salary + 5000;

SAVEPOINT BonusDone;

UPDATE Employee 
SET Emp_Dept = 'HR'
WHERE Emp_ID = 105;

ROLLBACK TO BonusDone;

COMMIT;
