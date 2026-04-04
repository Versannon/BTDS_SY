**Nested Queries (Subqueries)**

- Definition: A nested query is a query inside a another SQL query.
- The inner query is executed first, and its result is used by the outer query.
- Types of Nested Queries:
    1. Scalar Subquery: Returns a single value.
    2. Row Subquery: Returns a single row with one or more columns.
    3. Table Subquery: Returns multiple rows and columns.

- Example of a Scalar Subquery:

SELECT employee_name
FROM employees
WHERE employee_id = (SELECT manager_id FROM departments WHERE department_name = 'Sales');

- Example of a Row Subquery:

SELECT employee_name, department_id
FROM employees
WHERE (department_id, salary) IN (SELECT department_id, MAX(salary) FROM employees GROUP BY department_id);

- Example of a Table Subquery:

SELECT employee_name
FROM employees
WHERE department_id IN (SELECT department_id FROM departments WHERE location = 'New York');

- Use Cases:

    - When Comparing with Aggregate Values:
        - When you need to compare a value with average, max, min, etc.
        - E.g.,
            - Find students scoring above average:
SELECT student_name
FROM students
WHERE score > (SELECT AVG(score) FROM students);
    - **NOTE**: Inner query calculates average
    - **Note**: Outer query compares each student's marks.

    - When Checking Membership (IN or NOT IN):
        - When you want to check if a value exists in another query result.
        - E.g.,
            - Find employees working in departments located in Mumbai:
            SELECT name
            FROM Employee
            WHERE dept_id IN
            (
                SELECT dept_id FROM Department WHERE location = "Mumbai"
            );
    
    - When Using EXISTS:
        - When you want to check if a record exists.
        - E.g.,
            - Find departments that have employees:

             SELECT department_name
             FROM departments d
             WHERE EXISTS
             (
                 SELECT * FROM Employee e
                 WHERE e.dept_id = d.dept_id
             );
    
    - When Using Single value Subquery:
        - When subquery returns only one value.
        - E.g.,
            - Find employee with Highest salary
            SELECT employee_name
            FROM employees
            WHERE salary = 
            (
                SELECT MAX(salary)
                FROM Employee
            );