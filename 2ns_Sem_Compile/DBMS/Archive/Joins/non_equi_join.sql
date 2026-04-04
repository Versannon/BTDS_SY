SELECT
    e.employee_id,
    e.employee_name,
    e.salary,
    s.grade_code
FROM employees e
JOIN salary_grades s
    ON e.salary BETWEEN s.min_salary AND s.max_salary;
