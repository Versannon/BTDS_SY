SELECT
    e.employee_name,
    d.department_name
FROM employees e
CROSS JOIN departments d;
