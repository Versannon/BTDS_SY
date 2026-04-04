SELECT
    employee_id,
    employee_name,
    salary
FROM employees
WHERE department_id IN (
    SELECT department_id
    FROM departments
    WHERE department_name IN ('Sales', 'IT')
);
