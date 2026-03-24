DROP TABLE IF EXISTS employees;
DROP TABLE IF EXISTS departments;

CREATE TABLE departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50) NOT NULL,
    location VARCHAR(50) NOT NULL
);

CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(50) NOT NULL,
    department_id INT,
    salary INT NOT NULL,
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

INSERT INTO departments (department_id, department_name, location) VALUES
(10, 'Sales', 'Mumbai'),
(20, 'HR', 'Pune'),
(30, 'IT', 'Bengaluru'),
(40, 'Finance', 'Delhi');

INSERT INTO employees (employee_id, employee_name, department_id, salary) VALUES
(1, 'Aarav', 10, 95000),
(2, 'Diya', 20, 62000),
(3, 'Kabir', 30, 78000),
(4, 'Meera', 10, 50000),
(5, 'Rohan', 30, 88000),
(6, 'Isha', 20, 67000);
