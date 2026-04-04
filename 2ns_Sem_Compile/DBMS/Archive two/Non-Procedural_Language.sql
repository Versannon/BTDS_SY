drop database if exists NPL;

create database NPL;
use NPL;

drop table if exists Student;
create table Student
(
	ID int Primary Key,
    Full_Name varchar(255) NOT NULL,
    Roll_No int,
    Dept varchar(255),
    Age int,
    Phone int
);

insert into Student(ID,Full_Name,Roll_No,Dept,Age,Phone)
Values
(1,'Aryan Suryavanshi',8,'Developer',21,1234567890),
(2,'Sashreek Gokhale',37,'Technology',20,123423456),
(3,'Shrivarad Bhagwatikar',16,'Technology',20,1234123451),
(4,'Dhawal Chaudhari',28,'Management',20,123454321),
(5,'Harkeerat Singh',15,'Technology',20,1245562111),
(6,'Soham Kane',47,'TCS',20,1234512345);


-- Domain Relational Calculus 
Select Full_Name from Student
where Dept = 'Management';

-- Tuple Relational Calculus
Select Age,Full_Name from Student
where ID = 1;