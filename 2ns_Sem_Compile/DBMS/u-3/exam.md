# 🔷 UNIT–III: SQL (Complete Deep Explanation)

## 1. SQL OVERVIEW (Core Foundation)

### What is SQL?

SQL (Structured Query Language) is a declarative language used to:

- Define database structure
- Manipulate data
- Query data
- Control access

👉 **Key idea:**

You tell **WHAT** you want, not **HOW** to get it.

### SQL Categories (Very Important for Exams)

| **Category** | **Purpose**       | **Commands**            |
|--------------|-------------------|-------------------------|
| **DDL**      | Structure         | CREATE, ALTER, DROP     |
| **DML**      | Data change       | INSERT, UPDATE, DELETE  |
| **DQL**      | Data retrieval    | SELECT                  |
| **DCL**      | Permissions       | GRANT, REVOKE           |
| **TCL**      | Transactions      | COMMIT, ROLLBACK        |

---

## 2. BASIC SQL QUERIES (Core of Unit)

### 🔹 SELECT Statement (Most Important)

```sql
SELECT column1, column2
FROM table_name
WHERE condition;
```

### 🔹 Execution Order (VERY IMPORTANT)

**FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY → LIMIT**

This is commonly asked in exams.

### 🔹 Examples

1. **Simple Query**
   ```sql
   SELECT * FROM STUDENT;
   ```
2. **Conditional Query**
   ```sql
   SELECT StudentName
   FROM STUDENT
   WHERE GPA > 3.5;
   ```
3. **Pattern Matching**
   ```sql
   SELECT * FROM STUDENT
   WHERE Name LIKE 'R%';
   ```
4. **Range Query**
   ```sql
   SELECT * FROM STUDENT
   WHERE GPA BETWEEN 3.0 AND 4.0;
   ```

---

## 3. SET OPERATIONS (UNION, INTERSECT, EXCEPT)

### 🔹 UNION

```sql
SELECT Name FROM STUDENTS
UNION
SELECT Name FROM FACULTY;
```

✔ Removes duplicates

### 🔹 INTERSECT

```sql
SELECT ID FROM STUDENTS
INTERSECT
SELECT ID FROM EMPLOYEES;
```

✔ Common rows only

### 🔹 EXCEPT (or MINUS)

```sql
SELECT ID FROM STUDENTS
EXCEPT
SELECT ID FROM EMPLOYEES;
```

✔ Difference

📌 These come from relational algebra concepts.

---

## 4. NESTED QUERIES (Subqueries)

### 🔹 Types

1. **Single-value subquery**
   ```sql
   SELECT Name
   FROM STUDENT
   WHERE GPA > (
       SELECT AVG(GPA) FROM STUDENT
   );
   ```
2. **IN Subquery**
   ```sql
   SELECT Name
   FROM STUDENT
   WHERE StudentID IN (
       SELECT StudentID FROM ENROLLMENT
   );
   ```
3. **EXISTS**
   ```sql
   SELECT Name
   FROM STUDENT s
   WHERE EXISTS (
       SELECT * FROM ENROLLMENT e
       WHERE e.StudentID = s.StudentID
   );
   ```

### 🔹 Important Concept

- Inner query runs first
- Output used by outer query

---

## 5. AGGREGATION FUNCTIONS

### 🔹 Functions

| **Function** | **Purpose** |
|--------------|-------------|
| **COUNT()**  | Count rows  |
| **SUM()**    | Total       |
| **AVG()**    | Average     |
| **MIN()**    | Minimum     |
| **MAX()**    | Maximum     |

### 🔹 Example

```sql
SELECT Department, AVG(GPA)
FROM STUDENT
GROUP BY Department;
```

### 🔹 HAVING vs WHERE

| **WHERE**          | **HAVING**         |
|--------------------|--------------------|
| Filters rows       | Filters groups     |
| Before grouping    | After grouping     |

```sql
SELECT Department, COUNT(*)
FROM STUDENT
GROUP BY Department
HAVING COUNT(*) > 5;
```

---

## 6. NULL VALUES (Important Theory + Questions)

### 🔹 What is NULL?

- Unknown value
- Not zero
- Not empty

### 🔹 Handling NULL

```sql
SELECT * FROM STUDENT
WHERE Phone IS NULL;
```

### 🔹 Important Rule

- ❌ `= NULL` is wrong
- ✔ Use `IS NULL`

---

## 7. SQL CONSTRAINTS (VERY IMPORTANT)

### 🔹 Definition

Constraints ensure:

✔ Valid data
✔ Consistency
✔ Integrity

### 🔹 Types

1. **PRIMARY KEY**
   ```sql
   StudentID INT PRIMARY KEY
   ```
   ✔ Unique
   ✔ Not NULL

2. **FOREIGN KEY**
   ```sql
   FOREIGN KEY (DeptID)
   REFERENCES DEPARTMENT(DeptID)
   ```
   ✔ Maintains relationships

3. **UNIQUE**
   ```sql
   Email VARCHAR(100) UNIQUE
   ```
4. **NOT NULL**
   ```sql
   Name VARCHAR(50) NOT NULL
   ```
5. **CHECK**
   ```sql
   CHECK (GPA >= 0 AND GPA <= 4)
   ```
6. **DEFAULT**
   ```sql
   Status VARCHAR(20) DEFAULT 'Active'
   ```

### 🔹 Key Insight

Constraints enforce data correctness at DB level, not application level.

---

## 8. COMPLEX INTEGRITY CONSTRAINTS

These go beyond basic constraints.

**Examples:**

- `CHECK (Salary > Bonus)`
- `CHECK (EndDate > StartDate)`

✔ Used to enforce business rules

---

## 9. TRIGGERS (VERY IMPORTANT)

### 🔹 Definition

A trigger is an automatic action executed when:

- INSERT
- UPDATE
- DELETE

happens.

### 🔹 Syntax

```sql
CREATE TRIGGER trigger_name
BEFORE INSERT ON table_name
FOR EACH ROW
BEGIN
    -- logic
END;
```

### 🔹 Types

| **Type**   | **Description** |
|------------|-----------------|
| **BEFORE** | Before operation|
| **AFTER**  | After operation |

### 🔹 OLD and NEW

| **Keyword** | **Meaning**     |
|-------------|-----------------|
| **OLD**     | Before value    |
| **NEW**     | After value     |

### 🔹 Example (Audit Trigger)

```sql
CREATE TRIGGER trg_salary_update
AFTER UPDATE ON Employee
FOR EACH ROW
BEGIN
    INSERT INTO Audit
    VALUES (OLD.Salary, NEW.Salary);
END;
```

### 🔹 Use Cases

- Audit logs
- Validation
- Automation

---

# 🟦 UNIT–III: IMPORTANT QUESTIONS (8 MARKS EACH)

## 🔷 Q1. Explain different categories of SQL commands with examples.

### ✅ Answer:

1. **DDL (Data Definition Language)**

Used to define structure of database.

```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50)
);
```

✔ **Commands:**
- CREATE
- ALTER
- DROP
- TRUNCATE

2. **DML (Data Manipulation Language)**

Used to modify data.

```sql
INSERT INTO STUDENT VALUES (101, 'Rahul');
UPDATE STUDENT SET Name = 'Amit' WHERE StudentID = 101;
DELETE FROM STUDENT WHERE StudentID = 101;
```

3. **DQL (Data Query Language)**

Used to retrieve data.

```sql
SELECT * FROM STUDENT;
```

4. **DCL (Data Control Language)**

Controls permissions.

```sql
GRANT SELECT ON STUDENT TO user1;
REVOKE SELECT ON STUDENT FROM user1;
```

5. **TCL (Transaction Control Language)**

Manages transactions.

```sql
START TRANSACTION;
COMMIT;
ROLLBACK;
```

✔ **Conclusion:**
SQL is divided into categories based on functionality: structure, data, security, and transactions.

---

## 🔷 Q2. Explain SELECT query with all clauses and execution order.

### ✅ Answer:

🔹 **Syntax**

```sql
SELECT column_list
FROM table
WHERE condition
GROUP BY column
HAVING condition
ORDER BY column;
```

🔹 **Execution Order**

1. FROM
2. WHERE
3. GROUP BY
4. HAVING
5. SELECT
6. ORDER BY

🔹 **Example**

```sql
SELECT DeptID, AVG(GPA)
FROM STUDENT
WHERE GPA > 2.5
GROUP BY DeptID
HAVING AVG(GPA) > 3.0
ORDER BY DeptID;
```

🔹 **Diagram**

Raw Data → Filter → Group → Aggregate → Sort → Output

✔ **Important:**
- WHERE filters rows
- HAVING filters groups

---

## 🔷 Q3. Explain different types of SQL queries with examples.

### ✅ Answer:

1. **Simple Query**
   ```sql
   SELECT * FROM STUDENT;
   ```
2. **Conditional Query**
   ```sql
   SELECT Name FROM STUDENT WHERE GPA > 3.5;
   ```
3. **Join Query**
   ```sql
   SELECT s.Name, c.CourseName
   FROM STUDENT s
   JOIN ENROLLMENT e ON s.StudentID = e.StudentID
   JOIN COURSE c ON e.CourseID = c.CourseID;
   ```
4. **Aggregate Query**
   ```sql
   SELECT DeptID, COUNT(*) FROM STUDENT GROUP BY DeptID;
   ```
5. **Nested Query**
   ```sql
   SELECT Name FROM STUDENT
   WHERE GPA > (SELECT AVG(GPA) FROM STUDENT);
   ```

✔ **Conclusion:**
SQL queries range from simple retrieval to complex multi-table operations.

---

## 🔷 Q4. Explain UNION, INTERSECT, and EXCEPT with examples.

### ✅ Answer:

1. **UNION**

Combines results, removes duplicates.

```sql
SELECT DeptID FROM STUDENT
UNION
SELECT DeptID FROM COURSE;
```

2. **INTERSECT**

Common values.

```sql
SELECT DeptID FROM STUDENT
INTERSECT
SELECT DeptID FROM COURSE;
```

3. **EXCEPT**

Difference.

```sql
SELECT DeptID FROM STUDENT
EXCEPT
SELECT DeptID FROM COURSE;
```

🔹 **Conditions:**
- Same number of columns
- Same data types

✔ These operations are derived from relational algebra.

---

## 🔷 Q5. Explain nested queries (subqueries) with types.

### ✅ Answer:

🔹 **Definition:**

A query inside another query.

🔹 **Types**

1. **Single-row subquery**
   ```sql
   SELECT Name FROM STUDENT
   WHERE GPA > (SELECT AVG(GPA) FROM STUDENT);
   ```
2. **IN subquery**
   ```sql
   SELECT Name FROM STUDENT
   WHERE StudentID IN (
       SELECT StudentID FROM ENROLLMENT
   );
   ```
3. **EXISTS subquery**
   ```sql
   SELECT Name FROM STUDENT s
   WHERE EXISTS (
       SELECT * FROM ENROLLMENT e
       WHERE e.StudentID = s.StudentID
   );
   ```

✔ **Execution:**
- Inner query runs first
- Outer query uses result

---

## 🔷 Q6. Explain aggregate functions with GROUP BY and HAVING.

### ✅ Answer:

🔹 **Aggregate Functions**

| **Function** | **Purpose** |
|--------------|-------------|
| **COUNT()**  | Number of rows |
| **SUM()**    | Total         |
| **AVG()**    | Average       |
| **MIN()**    | Minimum       |
| **MAX()**    | Maximum       |

🔹 **Example**

```sql
SELECT DeptID, AVG(GPA)
FROM STUDENT
GROUP BY DeptID;
```

🔹 **HAVING Clause**

```sql
SELECT DeptID, COUNT(*)
FROM STUDENT
GROUP BY DeptID
HAVING COUNT(*) > 1;
```

🔹 **Difference**

| **WHERE**          | **HAVING**         |
|--------------------|--------------------|
| Row filter         | Group filter       |

✔ GROUP BY groups data, HAVING filters grouped data.

---

## 🔷 Q7. Explain NULL values and their handling in SQL.

### ✅ Answer:

🔹 **Definition:**

NULL represents unknown or missing value.

🔹 **Properties:**
- Not equal to 0
- Not equal to empty string
- Cannot use = operator

🔹 **Example**

```sql
SELECT * FROM STUDENT
WHERE GPA IS NULL;
```

🔹 **Operators**

| **Operator** | **Meaning** |
|--------------|-------------|
| **IS NULL**  | Check NULL  |
| **IS NOT NULL** | Not NULL |

✔ **Important:**
- GPA = NULL ❌
- GPA IS NULL ✔

---

## 🔷 Q8. Explain SQL constraints with examples.

### ✅ Answer:

🔹 **Definition:**

Constraints enforce rules for valid data.

🔹 **Types**

1. **PRIMARY KEY**
   ```sql
   StudentID INT PRIMARY KEY
   ```
2. **FOREIGN KEY**
   ```sql
   FOREIGN KEY (DeptID)
   REFERENCES DEPARTMENT(DeptID)
   ```
3. **UNIQUE**
   ```sql
   Email VARCHAR(100) UNIQUE
   ```
4. **NOT NULL**
   ```sql
   Name VARCHAR(50) NOT NULL
   ```
5. **CHECK**
   ```sql
   CHECK (GPA >= 0 AND GPA <= 4)
   ```
6. **DEFAULT**
   ```sql
   Status VARCHAR(20) DEFAULT 'Active'
   ```

✔ Ensures data integrity and consistency.

---

## 🔷 Q9. Explain complex integrity constraints with examples.

### ✅ Answer:

🔹 **Definition:**

Constraints involving multiple attributes.

🔹 **Examples**

- `CHECK (EndDate > StartDate)`
- `CHECK (Salary > Bonus)`

🔹 **Multi-column constraint**

```sql
CHECK (GPA >= 3.5 AND Status = 'Active')
```

✔ Used for enforcing business rules.

---

## 🔷 Q10. Explain triggers with syntax, types, and examples.

### ✅ Answer:

🔹 **Definition:**

Trigger = automatic execution on event.

🔹 **Syntax**

```sql
CREATE TRIGGER trigger_name
BEFORE INSERT ON table
FOR EACH ROW
BEGIN
    -- logic
END;
```

🔹 **Types**

| **Type**   | **Meaning**       |
|------------|-------------------|
| **BEFORE** | Before operation  |
| **AFTER**  | After operation   |

🔹 **Example**

```sql
CREATE TRIGGER trg_check_gpa
BEFORE INSERT ON STUDENT
FOR EACH ROW
BEGIN
    IF NEW.GPA < 0 THEN
        SET NEW.GPA = 0;
    END IF;
END;
```

🔹 **OLD vs NEW**

| **Operation** | **OLD** | **NEW** |
|---------------|---------|---------|
| **INSERT**    | ❌      | ✔       |
| **DELETE**    | ✔       | ❌      |
| **UPDATE**    | ✔       | ✔       |

✔ Used for automation, auditing, validation.

---

## 🔷 Q11. Explain schema refinement and redundancy problem.

### ✅ Answer:

🔹 **Problem: Redundancy**

```sql
STUDENT_COURSE(StudentID, Name, Course)
```

✔ Name repeated many times.

🔹 **Issues:**
- Data inconsistency
- Update anomaly
- Storage waste

🔹 **Solution: Decomposition**

```sql
STUDENT(StudentID, Name)
COURSE(CourseID, CourseName)
ENROLLMENT(StudentID, CourseID)
```

✔ Removes redundancy and improves structure.

---

## 🔷 Q12. Explain Functional Dependency (FD) with types.

### ✅ Answer:

🔹 **Definition**

```sql
A → B
```

A determines B.

🔹 **Example**

```sql
StudentID → Name
```

🔹 **Types**
- Full dependency
- Partial dependency
- Transitive dependency

✔ Used in normalization.

---

## 🔷 Q13. Explain normalization (1NF, 2NF, 3NF, BCNF).

### ✅ Answer:

🔹 **1NF**
- Atomic values only.

🔹 **2NF**
- Remove partial dependency.

🔹 **3NF**
- Remove transitive dependency.

🔹 **BCNF**
- Stronger than 3NF.
- Every determinant must be candidate key.

✔ Goal: eliminate redundancy and anomalies.

---

## 🔷 Q14. Explain lossless join decomposition.

### ✅ Answer:

🔹 **Definition:**

Decomposition where original table can be reconstructed.

🔹 **Condition**

- Common attribute must be key.

🔹 **Example**

```sql
R(A, B, C)
→ R1(A, B), R2(B, C)
```

If B is key → lossless.

✔ Prevents data loss after decomposition.

---

## 🔷 Q15. Explain multivalued dependency and 4NF, 5NF.

### ✅ Answer:

🔹 **Multivalued Dependency**

```sql
A →→ B
```

B independent of other attributes.

🔹 **Example**

```sql
Student →→ Hobby
Student →→ Skill
```

🔹 **4NF**

- Removes multivalued dependency.

🔹 **5NF**

- Removes join dependency.

✔ Used for advanced normalization.