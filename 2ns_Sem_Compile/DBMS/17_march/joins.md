**Joins in SQL**

- Used to connect two or more tables based on a related column between them.

- Types of Joins:
1. **Self join**: 
- A self join is a regular join, but the table is joined with itself. It is used to compare rows within the same table.
- Self joins can be particularly useful in scenarios like:
    - Hierarchical data (e.g., employee-manager relationships)
    - Recursive data structures (e.g., bill of materials)
    - Comparing data within The Same table (e.g., finding duplicate records)
- Example:
```sql
SELECT A.employee_id, A.name, B.manager_id
FROM employees A
JOIN employees B ON A.manager_id = B.employee_id;
```

2. **Left-Join**:
- A left join returns all records from the left table and the matched records from the right table. If there is no match, the result is NULL on the right side.
- Example:
```sql
SELECT A.employee_id, A.name, B.department_name
FROM employees A
LEFT JOIN departments B ON A.department_id = B.department_id;
```

3. **Right-Join**:
- A right join returns all records from the right table and the matched records from the left table. If there is no match, the result is NULL on the left side.
- Example:
```sql
SELECT A.employee_id, A.name, B.department_name
FROM employees A
RIGHT JOIN departments B ON A.department_id = B.department_id;
```

4. **Outer Join**

- Everything that is not common is shown in the result. It is a combination of left and right join.
- Example:
```sql
SELECT A.employee_id, A.name, B.department_name
FROM employees A
FULL OUTER JOIN departments B ON A.department_id = B.department_id;
```