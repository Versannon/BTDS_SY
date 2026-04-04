-- Relational Language

drop database if exists relational_algebra_db;
create database relational_algebra_db;
use relational_algebra_db;

create table R
(
	Roll_No int
);

insert into R
values
(1),(2),(3),(4),(5),(6);

create table S
(
	Roll_No int
);

insert into S
values
(1),(2),(3),(4);

drop table if exists Department;
CREATE TABLE Department (
    Dept_ID INT PRIMARY KEY,
    Dept_Name VARCHAR(50)
);

insert into Department
values
(101,'Developer'),
(102,'Technology'),
(103,'Mechanical'),
(104,'HR');


drop table if exists Student;
Create table Student
(
	ID INT PRIMARY KEY,
    Full_Name varchar(255),
    Age INT,
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
);

insert into Student
values
(1,'Aryan Suryavanshi',21,101),
(2,'Dhawal Chaudhari',20,102),
(3,'Shashreek Gokhale',20,103),
(4,'Shrivarad Bhagwatikar',20,104);

drop table if exists Course;
Create table Course
(
	Course_ID INT PRIMARY KEY,
    Course_Name VARCHAR(50)
);

insert into Course
values
(12,'DataBase'),
(13,'Operating System'),
(14,'Object Oriented Programming Language');

-- Select (Sigma)

Select * from student
where Age < 21;

-- Projection (π)

Select Full_Name,Age
from student
where Age > 20;

-- Cross Join

Select * from Student
Cross Join
Course;

-- Union

Select * from R
Union
Select * from S;

-- Inner Join

Select Student.ID,Student.Full_Name,Department.Dept_ID
from Student 
Inner Join
Department on Student.Dept_ID = Department.Dept_ID;

-- Set Difference

SELECT Roll_No FROM R
EXCEPT
SELECT Roll_No FROM S;

-- Intersection
SELECT Roll_No FROM R
INTERSECT
SELECT Roll_No FROM S;
