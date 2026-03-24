DROP TABLE IF EXISTS employees;
DROP TABLE IF EXISTS departments;
DROP TABLE IF EXISTS salary_grades;

CREATE TABLE departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(50) NOT NULL,
    location VARCHAR(50) NOT NULL
);

CREATE TABLE salary_grades (
    grade_code VARCHAR(5) PRIMARY KEY,
    min_salary INT NOT NULL,
    max_salary INT NOT NULL
);

CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(50) NOT NULL,
    department_id INT,
    manager_id INT,
    salary INT NOT NULL,
    FOREIGN KEY (department_id) REFERENCES departments(department_id),
    FOREIGN KEY (manager_id) REFERENCES employees(employee_id)
);

INSERT INTO departments (department_id, department_name, location) VALUES
(10, 'Sales', 'Mumbai'),
(20, 'HR', 'Pune'),
(30, 'IT', 'Bengaluru'),
(40, 'Finance', 'Delhi'),
(50, 'Research', 'Hyderabad');

INSERT INTO salary_grades (grade_code, min_salary, max_salary) VALUES
('G1', 0, 50000),
('G2', 50001, 70000),
('G3', 70001, 90000),
('G4', 90001, 120000);

INSERT INTO employees (employee_id, employee_name, department_id, manager_id, salary) VALUES
(1, 'Aarav', 10, NULL, 95000),
(2, 'Diya', 20, 1, 62000),
(3, 'Kabir', 30, 1, 78000),
(4, 'Meera', 10, 2, 50000),
(5, 'Rohan', NULL, 3, 45000),
(6, 'Isha', 30, 3, 88000),
(7, 'Vikram', 20, 2, 67000);
