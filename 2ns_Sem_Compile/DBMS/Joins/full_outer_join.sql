SELECT
    e.employee_id,
    e.employee_name,
    d.department_name,
    d.location
FROM employees e
LEFT JOIN departments d
    ON e.department_id = d.department_id
UNION
SELECT
    e.employee_id,
    e.employee_name,
    d.department_name,
    d.location
FROM employees e
RIGHT JOIN departments d
    ON e.department_id = d.department_id;
