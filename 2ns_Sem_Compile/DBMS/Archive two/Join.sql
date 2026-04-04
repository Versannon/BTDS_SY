-- JOINS IN MYSQL

DROP DATABASE IF EXISTS Joins;
CREATE DATABASE Joins;
USE Joins;

DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Department;

CREATE TABLE Department
(
    Dept_ID int Primary Key,
    Dept_Name varchar(255)
);

INSERT INTO Department(Dept_ID, Dept_Name)
VALUES
(101, 'Technology'),
(102, 'Cultural'),
(103, 'Management');

CREATE TABLE Student
(
    Student_ID int Primary Key,
    Full_Name varchar(255),
    Age int,
    Roll_No int,
    Gender varchar(255),
    Dept_ID int,
    Foreign key(Dept_ID) references Department(Dept_ID)
);

INSERT INTO Student(Student_ID, Full_Name, Age, Roll_No, Gender, Dept_ID)
VALUES
(1, 'Aryan Suryavanshi', 21, 8, 'Male', 101),
(2, 'Sashreek Gokhale', 20, 37, 'Male', 102),
(3, 'Dhawal Chaudhari', 20, 28, 'Male',103);

-- Inner Join
SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
INNER JOIN Department ON Student.Dept_ID = Department.Dept_ID;

-- Left Join
SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
LEFT JOIN Department ON Student.Dept_ID = Department.Dept_ID;

-- Right Join
SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
RIGHT JOIN Department ON Student.Dept_ID = Department.Dept_ID;

-- Full Outer Join
SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
LEFT JOIN Department ON Student.Dept_ID = Department.Dept_ID

UNION

SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
RIGHT JOIN Department ON Student.Dept_ID = Department.Dept_ID;

-- Natural Join
SELECT Student.Full_Name, Department.Dept_Name     
FROM Student 
NATURAL JOIN Department;

-- Self Join
Select s1.full_name as Student_1,s2.full_name as Student_2
from Student s1
inner join student s2
on s1.age=s2.age
and s1.student_id < s2.student_id;




