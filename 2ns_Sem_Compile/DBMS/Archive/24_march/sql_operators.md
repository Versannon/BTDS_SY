**Operators in SQL**

1: Aggregation Operators:
    - Definition: Functions used to perform calculations on a set of values
    - Common Functions:
        - COUNT(): Counts the number of rows
        - SUM(): Calculates the total sum of a numeric column
        - AVG(): Computes the average value of a numeric column
        - MAX(): Finds the maximum value in a column
        - MIN(): Finds the minimum value in a column
    - Syntax:
        SELECT AGG_Function(column_name)
        FROM table_name
        WHERE condition;
    - Example:
        SELECT AVG (salary) AS avg_salary
        FROM Employees;