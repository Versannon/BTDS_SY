# SQL (Structured Query Language) - Comprehensive Guide

## Definition

**SQL (Structured Query Language)** is the standard language for querying, creating, and managing relational databases. It is declarative, meaning users specify WHAT they want, not HOW to get it.

### Characteristics of SQL

1. **Declarative**: Specify desired result, DBMS determines how
2. **Standardized**: ISO/ANSI standard (most databases follow)
3. **User-Friendly**: English-like syntax
4. **Comprehensive**: Covers data definition, manipulation, control
5. **Powerful**: Can perform complex operations with simple statements
6. **Portable**: Works across different DBMS (with minor variations)

## Categories of SQL Commands

SQL commands are categorized into five groups based on their function:

### 1. DDL (Data Definition Language)

**Purpose**: Define and modify database structure/schema

#### DDL Commands

| Command | Purpose | Syntax |
|---------|---------|--------|
| **CREATE** | Create new objects | `CREATE TABLE/DATABASE/VIEW/INDEX` |
| **ALTER** | Modify existing objects | `ALTER TABLE ... ADD/MODIFY/DROP COLUMN` |
| **DROP** | Delete objects | `DROP TABLE/DATABASE/VIEW/INDEX` |
| **TRUNCATE** | Delete all data quickly | `TRUNCATE TABLE table_name` |
| **RENAME** | Rename objects | `RENAME TABLE old TO new` |

#### DDL Examples

**CREATE TABLE**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    DateOfBirth DATE,
    Department VARCHAR(30),
    GPA DECIMAL(3, 2) CHECK (GPA >= 0 AND GPA <= 4.0),
    CreatedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

**ALTER TABLE - Add Column**:
```sql
ALTER TABLE STUDENT
ADD COLUMN Phone VARCHAR(10);
```

**ALTER TABLE - Modify Column**:
```sql
ALTER TABLE STUDENT
MODIFY COLUMN StudentName VARCHAR(100);
```

**ALTER TABLE - Drop Column**:
```sql
ALTER TABLE STUDENT
DROP COLUMN Phone;
```

**TRUNCATE vs DELETE**:
```sql
-- DELETE: Removes rows but keeps structure, slower, can rollback
DELETE FROM STUDENT;

-- TRUNCATE: Removes all data quickly, faster, cannot rollback (usually)
TRUNCATE TABLE STUDENT;
```

### 2. DML (Data Manipulation Language)

**Purpose**: Insert, update, and delete data in database

#### DML Commands

| Command | Purpose |
|---------|---------|
| **INSERT** | Add new records |
| **UPDATE** | Modify existing records |
| **DELETE** | Remove records |

#### DML Examples

**INSERT - Single Record**:
```sql
INSERT INTO STUDENT (StudentID, StudentName, Email, DateOfBirth, Department)
VALUES (101, 'Raj Kumar', 'raj@college.edu', '2003-05-12', 'IT');
```

**INSERT - Multiple Records**:
```sql
INSERT INTO STUDENT (StudentID, StudentName, Email, DateOfBirth, Department)
VALUES 
    (102, 'Priya Singh', 'priya@college.edu', '2003-03-25', 'HR'),
    (103, 'Amit Patel', 'amit@college.edu', '2002-07-18', 'Finance'),
    (104, 'Neha Sharma', 'neha@college.edu', '2003-11-30', 'IT');
```

**INSERT - From Another Table**:
```sql
INSERT INTO STUDENT_BACKUP (StudentID, StudentName, Email)
SELECT StudentID, StudentName, Email
FROM STUDENT
WHERE Department = 'IT';
```

**UPDATE - Specific Records**:
```sql
UPDATE STUDENT
SET Email = 'newemail@college.edu', Department = 'CS'
WHERE StudentID = 101;
```

**UPDATE - Conditional**:
```sql
UPDATE STUDENT
SET GPA = GPA + 0.1
WHERE Department = 'IT' AND GPA < 3.5;
```

**DELETE - Specific Records**:
```sql
DELETE FROM STUDENT
WHERE StudentID = 101;
```

**DELETE - Multiple Conditions**:
```sql
DELETE FROM STUDENT
WHERE Department = 'HR' AND GPA < 2.5;
```

### 3. DQL (Data Query Language)

**Purpose**: Retrieve data from database

#### DQL Commands

Only one command: **SELECT** (used for retrieval)

#### SELECT - Complete Syntax

```sql
SELECT [DISTINCT] column_list
FROM table_name
[WHERE condition]
[GROUP BY column(s)]
[HAVING group_condition]
[ORDER BY column(s)]
[LIMIT number];
```

#### SELECT Examples

**Basic SELECT**:
```sql
SELECT * FROM STUDENT;
```

**SELECT Specific Columns**:
```sql
SELECT StudentName, Email, GPA
FROM STUDENT;
```

**SELECT with WHERE**:
```sql
SELECT StudentName, GPA
FROM STUDENT
WHERE GPA >= 3.5;
```

**SELECT with Aggregation**:
```sql
SELECT COUNT(*) as TotalStudents
FROM STUDENT;

SELECT Department, AVG(GPA) as AverageGPA
FROM STUDENT
GROUP BY Department;
```

**SELECT with JOIN**:
```sql
SELECT s.StudentName, c.CourseName, e.Grade
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID;
```

### 4. DCL (Data Control Language)

**Purpose**: Control access to database (Security and Authorization)

#### DCL Commands

| Command | Purpose |
|---------|---------|
| **GRANT** | Give privileges to users |
| **REVOKE** | Remove privileges from users |

#### DCL Examples

**GRANT - All Privileges**:
```sql
GRANT ALL PRIVILEGES ON DATABASE College TO 'admin'@'localhost';
```

**GRANT - Specific Privileges**:
```sql
GRANT SELECT, INSERT, UPDATE ON College.STUDENT TO 'faculty'@'localhost';
```

**GRANT - Table Level**:
```sql
GRANT SELECT ON STUDENT TO 'student_user'@'localhost';
GRANT SELECT, UPDATE ON STUDENT(GPA) TO 'advisor'@'localhost';
```

**REVOKE - Remove All Privileges**:
```sql
REVOKE ALL PRIVILEGES ON DATABASE College FROM 'intern'@'localhost';
```

**REVOKE - Specific Privilege**:
```sql
REVOKE DELETE ON STUDENT FROM 'intern'@'localhost';
```

### 5. TCL (Transaction Control Language)

**Purpose**: Manage transaction execution and ensure ACID properties

#### TCL Commands

| Command | Purpose |
|---------|---------|
| **BEGIN/START TRANSACTION** | Begin a new transaction |
| **COMMIT** | Save all changes permanently |
| **ROLLBACK** | Undo all changes in transaction |
| **SAVEPOINT** | Create restore point within transaction |

#### TCL Examples

**Basic Transaction**:
```sql
START TRANSACTION;

INSERT INTO STUDENT VALUES (105, 'Vijay', 'vijay@college.edu', '2003-01-15', 'IT', 3.7);
UPDATE STUDENT SET GPA = 3.8 WHERE StudentID = 101;
DELETE FROM STUDENT WHERE StudentID = 102;

COMMIT;  -- All changes saved
```

**Rollback Example**:
```sql
START TRANSACTION;

UPDATE ACCOUNT SET Balance = Balance - 1000 WHERE AccountID = 1;
UPDATE ACCOUNT SET Balance = Balance + 1000 WHERE AccountID = 2;

-- If error occurs:
IF (error) THEN
    ROLLBACK;  -- All changes undone
ELSE
    COMMIT;    -- All changes saved
END IF;
```

**SAVEPOINT Example**:
```sql
START TRANSACTION;

INSERT INTO STUDENT VALUES (105, 'Vijay', 'vijay@college.edu', '2003-01-15', 'IT', 3.7);

SAVEPOINT sp1;  -- Create restore point

UPDATE STUDENT SET GPA = 3.8 WHERE StudentID = 101;

-- If error in update:
ROLLBACK TO SAVEPOINT sp1;  -- Undo only the update, keep insert

COMMIT;  -- Save everything remaining
```

## Important Clauses in SELECT

### WHERE Clause

**Purpose**: Filter rows based on conditions

**Syntax**:
```sql
WHERE condition
```

**Conditions**:
- Comparison: =, <>, <, >, <=, >=
- Logical: AND, OR, NOT
- Pattern: LIKE, IN, BETWEEN
- Null: IS NULL, IS NOT NULL

**Examples**:
```sql
WHERE Salary > 50000
WHERE Department = 'IT' AND Salary > 50000
WHERE GPA BETWEEN 3.0 AND 3.9
WHERE StudentName LIKE 'R%'
WHERE Department IN ('IT', 'HR', 'Finance')
WHERE Phone IS NULL
```

### GROUP BY Clause

**Purpose**: Group rows by specified column(s)

**Used With**: Aggregate functions (COUNT, SUM, AVG, MIN, MAX)

**Syntax**:
```sql
GROUP BY column1, column2, ...
```

**Example**:
```sql
SELECT Department, COUNT(*) as StudentCount, AVG(GPA) as AvgGPA
FROM STUDENT
GROUP BY Department;
```

### HAVING Clause

**Purpose**: Filter groups (WHERE filters rows, HAVING filters groups)

**Syntax**:
```sql
GROUP BY column
HAVING group_condition
```

**Example**:
```sql
SELECT Department, COUNT(*) as StudentCount
FROM STUDENT
GROUP BY Department
HAVING COUNT(*) >= 3;
```

**WHERE vs HAVING**:
```sql
-- WHERE - filters individual rows before grouping
SELECT Department, AVG(GPA)
FROM STUDENT
WHERE GPA > 3.0  -- Exclude low GPA students first
GROUP BY Department;

-- HAVING - filters entire groups after grouping
SELECT Department, AVG(GPA)
FROM STUDENT
GROUP BY Department
HAVING AVG(GPA) > 3.5;  -- Exclude departments with low average
```

### ORDER BY Clause

**Purpose**: Sort result set

**Syntax**:
```sql
ORDER BY column [ASC | DESC]
```

**Examples**:
```sql
SELECT StudentName, GPA
FROM STUDENT
ORDER BY GPA DESC;  -- Descending: highest GPA first

SELECT StudentName, GPA
FROM STUDENT
ORDER BY Department ASC, GPA DESC;  -- Multiple columns
```

### DISTINCT Clause

**Purpose**: Remove duplicate rows

**Syntax**:
```sql
SELECT DISTINCT column(s)
FROM table
```

**Example**:
```sql
SELECT DISTINCT Department
FROM STUDENT;
```

**Result - All unique departments**:
```
Department
IT
HR
Finance
CS
```

### LIMIT Clause

**Purpose**: Restrict number of rows returned

**Syntax**:
```sql
LIMIT number [OFFSET start_position]
```

**Examples**:
```sql
SELECT * FROM STUDENT LIMIT 10;  -- First 10 rows

SELECT * FROM STUDENT LIMIT 10 OFFSET 20;  -- 10 rows starting from 21st

SELECT * FROM STUDENT LIMIT 5, 10;  -- MySQL syntax: start at 5, get 10 rows
```

## Aggregate Functions

Functions that operate on groups of rows:

| Function | Purpose | Example |
|----------|---------|---------|
| COUNT() | Count rows | `COUNT(*), COUNT(DISTINCT Department)` |
| SUM() | Sum numeric values | `SUM(Salary)` |
| AVG() | Average value | `AVG(GPA)` |
| MIN() | Minimum value | `MIN(Salary)` |
| MAX() | Maximum value | `MAX(GPA)` |

**Examples**:
```sql
SELECT COUNT(*) as TotalStudents FROM STUDENT;

SELECT SUM(Salary) as TotalPayroll FROM EMPLOYEE;

SELECT AVG(GPA) as AverageGPA FROM STUDENT;

SELECT MIN(GPA), MAX(GPA) FROM STUDENT;

SELECT Department, COUNT(*) as DeptSize, AVG(Salary) as AvgSalary
FROM EMPLOYEE
GROUP BY Department;
```

## Query Execution Order

Understanding execution order is crucial for writing correct queries:

```
1. FROM       - Identify table(s)
2. WHERE      - Filter rows
3. GROUP BY   - Create groups
4. HAVING     - Filter groups
5. SELECT     - Choose columns
6. DISTINCT   - Remove duplicates
7. ORDER BY   - Sort result
8. LIMIT      - Restrict result count
```

**Example**:
```sql
SELECT Department, COUNT(*) as StudentCount
FROM STUDENT
WHERE GPA > 2.5
GROUP BY Department
HAVING COUNT(*) >= 3
ORDER BY StudentCount DESC
LIMIT 5;

Execution:
1. FROM STUDENT
2. WHERE GPA > 2.5 (filter low GPA students)
3. GROUP BY Department (group remaining students)
4. HAVING COUNT(*) >= 3 (keep groups with 3+ students)
5. SELECT Department, COUNT(*) (choose columns)
6. (No DISTINCT)
7. ORDER BY StudentCount DESC (sort by count descending)
8. LIMIT 5 (return only first 5)
```

## Common SQL Patterns

### Finding Duplicates
```sql
SELECT Column1, COUNT(*)
FROM TableName
GROUP BY Column1
HAVING COUNT(*) > 1;
```

### Finding Null Values
```sql
SELECT * FROM TableName WHERE Column IS NULL;
```

### Pattern Matching
```sql
SELECT * FROM STUDENT WHERE StudentName LIKE 'R%';  -- Starts with R
SELECT * FROM STUDENT WHERE Email LIKE '%@college.edu';  -- Ends with domain
SELECT * FROM STUDENT WHERE StudentName LIKE '%Singh%';  -- Contains Singh
```

### Top N Records
```sql
-- MySQL
SELECT * FROM STUDENT ORDER BY GPA DESC LIMIT 5;

-- SQL Server
SELECT TOP 5 * FROM STUDENT ORDER BY GPA DESC;

-- Oracle
SELECT * FROM STUDENT ORDER BY GPA DESC FETCH FIRST 5 ROWS ONLY;
```

## Exam Notes

1. **Command Classification**: Memorize DDL, DML, DQL, DCL, TCL with examples
2. **SELECT Syntax**: Know the complete syntax and execution order
3. **Clauses**: Explain WHERE, GROUP BY, HAVING, ORDER BY with examples
4. **Aggregate Functions**: Know COUNT, SUM, AVG, MIN, MAX usage
5. **WHERE vs HAVING**: Key distinction between filtering rows vs groups
6. **Practical Queries**: Be able to write queries for common scenarios
7. **Transaction Safety**: Understand COMMIT, ROLLBACK in practical context
8. **DCL Examples**: Show privilege granting with realistic scenarios
