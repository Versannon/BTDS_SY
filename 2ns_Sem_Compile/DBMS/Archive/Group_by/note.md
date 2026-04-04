Group by: used to group rows that have the same values in one or more columns, so that aggregate functions can be applied to each group.

E.g.,

Calculate department wise total salary:

SELECT department, SUM(salary)
FROM employee
GROUP BY department;

Having clause:
Used to filter groups (like WHERE but for grouped data)

SELECT department, SUM(salary)
FROM employee
GROUP BY department
HAVING SUM(salary) >= 70000;