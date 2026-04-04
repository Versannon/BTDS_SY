create database group_by;
use group_by;


-- Create tables

create table employee
(
    id INT(255) PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    department VARCHAR(255) NOT NULL,
    salary INT(255) NOT NULL
)

create table department
(
    id INT(255) PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    location VARCHAR(255) NOT NULL,
)

-- Adding values to tables

insert into employee(id, name, departmnt, salary)
Values
(1, 'John Doe', 'IT', 50000),
(2, 'Jane Doe', 'HR', 60000),
(3, 'Jim Brown', 'IT', 55000),
(4, 'Jack Smith', 'HR', 65000),
(5, 'Jill White', 'Finance', 70000),
(6, 'Joe Black', 'Finance', 75000);

insert into department(id, name, location)
Values
(1, 'IT', 'New York'),
(2, 'HR', 'Los Angeles'),
(3, 'Finance', 'Chicago');