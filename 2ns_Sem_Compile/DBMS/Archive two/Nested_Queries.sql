drop database if exists Nested_Queries;
create database Nested_Queries;
use Nested_Queries;

drop table if exists Employee;
create table Employee
(
	Emp_ID int primary key,
    Emp_Name varchar(255),
    Emp_salary int,
    Dept_ID int
);
insert into Employee(Emp_ID,Emp_Name,Emp_salary,Dept_ID)
values
(1,'Aryan Suryavanshi',1000000,101),
(2,'Dhawal Chaudhari',10000,102),
(3,'Sashreeek Gokhale',100000,103),
(4,'Shrivarad Bhagwatikar',10000,104),
(5,'Harkeerat Singh',10000,105);

drop table if exists Department;
create table Department
(
	Dept_ID int Primary Key,
    Dept_Name varchar(255),
    Emp_ID int
);
insert into Department(Dept_ID,Dept_Name,Emp_ID)
values
(101,'Developer',1),
(102,'HR',2),
(103,'Management',3),
(104,'Physical',4),
(105,'CS',5);

-- Scalar Sub-query
select Emp_name,
(select avg(emp_salary) from employee) AS Average_Salary
from employee;

-- Row Sub-query
select Emp_name,Emp_ID
from employee
where Emp_name = (select emp_name from employee
					where emp_name = 'Dhawal Chaudhari');
                    
-- Table Sub-query
SELECT * FROM (
    SELECT Emp_Name, Emp_salary 
    FROM Employee 
    WHERE Emp_salary > 10000
) AS High_Earners;


-- When comparing with aggregate values
select emp_name,emp_salary
from employee
where emp_salary > (select avg(emp_salary)from employee);

-- When Checking Membership (IN or NOT IN)
select Emp_name 
from employee
where dept_id in (select dept_id from employee
					where emp_id = 2);

-- To check if a record exists.   
select Dept_Name 
from Department d
where d.dept_name = 'HR'
and exists(select 2 from Employee e
				where e.Dept_ID = d.Dept_ID);                 
                    

-- Sub-query returns only one value
select emp_name
from employee
where dept_id = (select dept_id from department 
					where  dept_name = 'Developer');
