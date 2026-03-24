SELECT
    employee_id,
    employee_name,
    department_id,
    department_name,
    location,
    manager_id,
    salary
FROM employees
NATURAL JOIN departments;
