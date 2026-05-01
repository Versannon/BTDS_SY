use group_by;

SELECT department, SUM(salary)
FROM employee
GROUP BY department;

-- Having Clause

SELECT department, SUM(salary)
FROM employee
GROUP BY department
HAVING SUM(salary) >= 125000;