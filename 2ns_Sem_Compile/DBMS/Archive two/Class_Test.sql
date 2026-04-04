drop database if exists test;
create database test;
use test;

drop table if exists Employee;
create table Employee
(
	Emp_ID int Primary Key,
    Emp_Name varchar(255),
    Dept_Name varchar(255),
    Emp_Salary int
);

insert into Employee(Emp_ID,Emp_Name,Dept_Name,Emp_Salary)
values
(1,'Aryan Suryavanshi','Developer',100000000),
(2,'Dhawal Chaudhari','Physical',10000000),
(3,'Sashreek Gokhale','CS',1000000),
(4,'Soham Kane','Web Developer',1000000),
(5,'Chaitanya Deshmukh','HR',100000);

drop table if exists Department;
create table Department
(
	Dept_ID int Primary Key,
    Dept_Name varchar(255),
    Dept_location varchar(255),
    Emp_ID int
);

insert into Department(Dept_ID,Dept_Name,Dept_location,Emp_ID)
values
(101,'Developer','Mumbai',1),
(102,'Physical','Chennai',2),
(103,'CS','Pune',3),
(104,'Web Developer','Delhi',4),
(105,'HR','Chattisgarh',5);

-- Find Maximum salary with employee name
select emp_name,emp_salary
from employee
where emp_salary=(select max(emp_salary)from employee);

-- Find Maximum Salary
select emp_salary
from employee
where emp_salary=(select max(emp_salary) from employee);

-- Find Minimum Salary
select emp_salary
from employee
where emp_salary=(select min(emp_salary) from employee);

-- Display employee name along with department name
select employee.emp_name , department.dept_name
from employee
inner join department on
employee.emp_id=department.emp_id;

-- Find employee who earn more than average salary
select emp_name , emp_salary
from employee
where emp_salary > (select avg(emp_salary) from employee);

-- Show all employee with their department location
select employee.emp_name,department.dept_location
from employee
inner join department
on employee.emp_id=department.emp_id;

-- Find employee salary greater than 50000
select emp_name,emp_salary
from 
(select emp_name,emp_salary from employee 
where emp_salary > 50000) 
AS High_Earners;

-- Find average salary department wise
select dept_name,
(select avg(emp_salary)
from employee e2 
where e1.dept_name = e2.dept_name)AS Average_salary
from Employee e1;

-- List all departments located in Mumbai
select dept_name
from department
where dept_id in (select dept_id from department
 where dept_location = 'Mumbai');