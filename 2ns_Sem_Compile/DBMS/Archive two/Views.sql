drop database if exists db;
create database db;
use db;

drop table if exists Student;
create table Student
(
	ID int Primary Key,
    Full_Name varchar(255),
    Roll_No int,
    Dept varchar(255)
);

insert into Student(ID,Full_Name,Roll_No,Dept)
Values
(1,'Aryan Suryavanshi',8,'Developer'),
(2,'Dhawal Chaudhari',28,'Management'),
(3,'Sashreek Gokhale',37,'Cultural'),
(4,'Shrivarad Bhagwatikar',16,'HR');

create view Student_View AS  --      AS --> Alias
Select Full_Name,Dept 
from Student;

Select * from Student_View;

-- Destory View

drop view Student_View;
