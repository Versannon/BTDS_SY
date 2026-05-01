# SQL Query Types with Examples

## Query Category Overview

```
SQL Queries
    ├─ Simple Queries (Single table, basic selection)
    ├─ Conditional Queries (With WHERE clause)
    ├─ Join Queries (Multiple related tables)
    ├─ Aggregate Queries (COUNT, SUM, AVG, etc.)
    ├─ Nested Queries (Subqueries)
    ├─ View Queries (Virtual tables)
    ├─ Union Queries (Combining results)
    └─ Complex Queries (Multiple clauses combined)
```

## 1. Simple Query

**Definition**: Basic query retrieving all or specific columns from a single table with no conditions.

### Example 1: Retrieve All Data

**Scenario**: Get all student information

```sql
SELECT * FROM STUDENT;
```

**Result**: All columns and all rows from STUDENT table
```
StudentID | StudentName    | Email                | GPA
----------|----------------|--------------------|-------
101       | Raj Kumar      | raj@college.edu     | 3.7
102       | Priya Singh    | priya@college.edu   | 3.5
103       | Amit Patel     | amit@college.edu    | 3.2
```

### Example 2: Retrieve Specific Columns

**Scenario**: Get student names and email addresses only

```sql
SELECT StudentID, StudentName, Email 
FROM STUDENT;
```

**Result**: Only requested columns
```
StudentID | StudentName    | Email
----------|----------------|--------------------|
101       | Raj Kumar      | raj@college.edu
102       | Priya Singh    | priya@college.edu
103       | Amit Patel     | amit@college.edu
```

### Example 3: With DISTINCT

**Scenario**: Find all unique departments

```sql
SELECT DISTINCT Department 
FROM STUDENT;
```

**Result**: Only unique department values
```
Department
IT
HR
Finance
CS
```

## 2. Conditional Query (WHERE Clause)

**Definition**: Query with conditions to filter specific rows based on criteria.

### Example 1: Simple Condition

**Scenario**: Get all students with GPA >= 3.5

```sql
SELECT StudentName, GPA 
FROM STUDENT 
WHERE GPA >= 3.5;
```

**Result**: Only students meeting criteria
```
StudentName    | GPA
---------------|------
Raj Kumar      | 3.7
Priya Singh    | 3.5
```

### Example 2: Multiple Conditions (AND)

**Scenario**: Get IT students with GPA > 3.0

```sql
SELECT StudentName, Department, GPA
FROM STUDENT 
WHERE Department = 'IT' AND GPA > 3.0;
```

**Result**:
```
StudentName    | Department | GPA
---------------|------------|------
Raj Kumar      | IT         | 3.7
Amit Patel     | IT         | 3.2
```

### Example 3: Multiple Conditions (OR)

**Scenario**: Get students from IT or HR department

```sql
SELECT StudentName, Department
FROM STUDENT 
WHERE Department = 'IT' OR Department = 'HR';
```

**Result**:
```
StudentName    | Department
---------------|------------
Raj Kumar      | IT
Priya Singh    | HR
Amit Patel     | IT
```

### Example 4: IN Operator

**Scenario**: Get students from IT, HR, or Finance departments

```sql
SELECT StudentName, Department
FROM STUDENT 
WHERE Department IN ('IT', 'HR', 'Finance');
```

### Example 5: BETWEEN Operator

**Scenario**: Get students with GPA between 3.0 and 3.8

```sql
SELECT StudentName, GPA
FROM STUDENT 
WHERE GPA BETWEEN 3.0 AND 3.8;
```

### Example 6: LIKE Operator (Pattern Matching)

**Scenario**: Get students whose names start with 'R'

```sql
SELECT StudentName
FROM STUDENT 
WHERE StudentName LIKE 'R%';
```

**Wildcard Patterns**:
- `%` - Zero or more characters
- `_` - Exactly one character

**More Examples**:
```sql
WHERE StudentName LIKE '%Singh%'  -- Contains Singh
WHERE Email LIKE '%@college.edu'  -- Ends with domain
WHERE PhoneNumber LIKE '98_______'  -- Starts with 98, 10 total digits
```

## 3. Join Query

**Definition**: Query combining data from multiple related tables using relationships.

### Database Schema for Examples

```
STUDENT Table:
├─ StudentID (PK)
├─ StudentName
└─ DepartmentID (FK)

COURSE Table:
├─ CourseID (PK)
├─ CourseName
└─ DepartmentID (FK)

ENROLLMENT Table:
├─ StudentID (FK)
├─ CourseID (FK)
├─ Semester
└─ Grade

DEPARTMENT Table:
├─ DepartmentID (PK)
└─ DepartmentName
```

### Example 1: INNER JOIN

**Scenario**: Get student names with their enrolled course names

```sql
SELECT s.StudentName, c.CourseName, e.Grade
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID;
```

**What it does**:
1. Matches students with their enrollments
2. Matches enrollments with course details
3. Returns only rows with matches in all tables

**Result**:
```
StudentName    | CourseName      | Grade
----------------|-----------------|-------
Raj Kumar      | Database        | A
Raj Kumar      | Networks        | B
Priya Singh    | Database        | A+
```

### Example 2: LEFT JOIN (LEFT OUTER JOIN)

**Scenario**: Get all students and their courses (include students with no enrollment)

```sql
SELECT s.StudentName, c.CourseName
FROM STUDENT s
LEFT JOIN ENROLLMENT e ON s.StudentID = e.StudentID
LEFT JOIN COURSE c ON e.CourseID = c.CourseID;
```

**Result** (includes students even if not enrolled):
```
StudentName    | CourseName
---------------|------------------
Raj Kumar      | Database
Raj Kumar      | Networks
Priya Singh    | Database
Amit Patel     | NULL  (Not enrolled in any course)
```

### Example 3: Multiple Joins

**Scenario**: Get student names, department names, and course names

```sql
SELECT s.StudentName, d.DepartmentName, c.CourseName
FROM STUDENT s
INNER JOIN DEPARTMENT d ON s.DepartmentID = d.DepartmentID
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID;
```

### Example 4: Self Join

**Scenario**: Get manager-employee relationships (if employees managed by other employees)

```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    ManagerID INT  -- References EmployeeID
);

-- Query: Get each employee with their manager
SELECT e1.EmployeeName as Employee, e2.EmployeeName as Manager
FROM EMPLOYEE e1
LEFT JOIN EMPLOYEE e2 ON e1.ManagerID = e2.EmployeeID;
```

**Result**:
```
Employee   | Manager
------------|----------
Raj        | NULL (CEO)
Priya      | Raj
Amit       | Raj
Neha       | Priya
```

## 4. Aggregate Query

**Definition**: Query using aggregate functions to compute summary values.

### Common Aggregate Functions

```
COUNT()  - Count rows
SUM()    - Sum values
AVG()    - Average value
MIN()    - Minimum value
MAX()    - Maximum value
```

### Example 1: Simple Aggregation

**Scenario**: Count total students

```sql
SELECT COUNT(*) as TotalStudents
FROM STUDENT;
```

**Result**:
```
TotalStudents
100
```

### Example 2: Aggregation with GROUP BY

**Scenario**: Count students per department

```sql
SELECT Department, COUNT(*) as StudentCount
FROM STUDENT
GROUP BY Department;
```

**Result**:
```
Department | StudentCount
------------|---------------
IT         | 25
HR         | 15
Finance    | 20
CS         | 40
```

### Example 3: Multiple Aggregates

**Scenario**: Get GPA statistics per department

```sql
SELECT Department, 
       COUNT(*) as StudentCount,
       AVG(GPA) as AverageGPA,
       MIN(GPA) as LowestGPA,
       MAX(GPA) as HighestGPA
FROM STUDENT
GROUP BY Department;
```

**Result**:
```
Department | Count | AvgGPA | MinGPA | MaxGPA
------------|-------|--------|--------|--------
IT         | 25    | 3.55   | 2.8    | 4.0
HR         | 15    | 3.42   | 3.0    | 3.9
Finance    | 20    | 3.38   | 2.5    | 3.8
```

### Example 4: Aggregation with HAVING

**Scenario**: Find departments with average GPA > 3.5

```sql
SELECT Department, AVG(GPA) as AvgGPA
FROM STUDENT
GROUP BY Department
HAVING AVG(GPA) > 3.5;
```

**Result** (only departments with high average):
```
Department | AvgGPA
------------|--------
IT         | 3.55
HR         | 3.52
```

### Example 5: Complex Aggregation with Multiple Joins

**Scenario**: Get course-wise enrollment count and average grade

```sql
SELECT c.CourseName, 
       COUNT(e.StudentID) as EnrollmentCount,
       AVG(CAST(e.Grade AS DECIMAL)) as AverageGrade
FROM COURSE c
LEFT JOIN ENROLLMENT e ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName
HAVING COUNT(e.StudentID) >= 2
ORDER BY EnrollmentCount DESC;
```

## 5. Nested Query (Subquery)

**Definition**: Query containing another query. Inner query executes first, result used by outer query.

### Example 1: Subquery in WHERE Clause

**Scenario**: Get students with GPA above average

```sql
SELECT StudentName, GPA
FROM STUDENT
WHERE GPA > (
    SELECT AVG(GPA)
    FROM STUDENT
);
```

**Execution**:
1. Inner query: Calculate average GPA
2. Outer query: Find students above that average

**Result**:
```
StudentName    | GPA
---------------|------
Raj Kumar      | 3.7
Priya Singh    | 3.5
```

### Example 2: Subquery with IN

**Scenario**: Get students who have enrolled in courses

```sql
SELECT StudentName
FROM STUDENT
WHERE StudentID IN (
    SELECT StudentID
    FROM ENROLLMENT
);
```

### Example 3: Subquery with EXISTS

**Scenario**: Get courses that have at least one student enrolled

```sql
SELECT CourseName
FROM COURSE c
WHERE EXISTS (
    SELECT 1
    FROM ENROLLMENT e
    WHERE e.CourseID = c.CourseID
);
```

### Example 4: Correlated Subquery

**Scenario**: Get students who have taken more courses than their department average

```sql
SELECT s1.StudentName
FROM STUDENT s1
WHERE (
    SELECT COUNT(*)
    FROM ENROLLMENT
    WHERE StudentID = s1.StudentID
) > (
    SELECT AVG(CourseCount)
    FROM (
        SELECT COUNT(*) as CourseCount
        FROM ENROLLMENT
        JOIN STUDENT ON ENROLLMENT.StudentID = STUDENT.StudentID
        WHERE STUDENT.DepartmentID = s1.DepartmentID
        GROUP BY StudentID
    ) as DeptStats
);
```

### Example 5: Multiple Levels of Nesting

**Scenario**: Get students from departments having average GPA > college average

```sql
SELECT StudentName, Department
FROM STUDENT
WHERE DepartmentID IN (
    SELECT DepartmentID
    FROM (
        SELECT DepartmentID, AVG(GPA) as AvgDeptGPA
        FROM STUDENT
        GROUP BY DepartmentID
        HAVING AvG(GPA) > (
            SELECT AVG(GPA)
            FROM STUDENT
        )
    ) as HighAvgDepts
);
```

## 6. View Query

**Definition**: Creating and using virtual tables (stored queries).

### Create a View

**Scenario**: Create a view for IT department students with high GPA

```sql
CREATE VIEW IT_TopStudents AS
SELECT StudentID, StudentName, GPA
FROM STUDENT
WHERE Department = 'IT' AND GPA >= 3.5;
```

### Query Using a View

**Scenario**: Get names of IT top students

```sql
SELECT StudentName, GPA
FROM IT_TopStudents
ORDER BY GPA DESC;
```

### Complex View with Join

**Scenario**: Create view with student, course, and grade information

```sql
CREATE VIEW StudentCourseGrades AS
SELECT s.StudentID, s.StudentName, c.CourseID, c.CourseName, e.Grade
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID;
```

**Usage**:
```sql
SELECT * FROM StudentCourseGrades
WHERE Grade >= 'B';
```

## 7. Union Query

**Definition**: Combining results from multiple SELECT statements.

### Example: Union

**Scenario**: Get list of all academic staff (faculty and department heads)

```sql
SELECT EmployeeName, Department, 'Faculty' as Role
FROM FACULTY
UNION
SELECT EmployeeName, Department, 'Head' as Role
FROM DEPARTMENT_HEAD;
```

**Result** (combined without duplicates):
```
EmployeeName    | Department | Role
-----------------|------------|----------
Prof. Raj       | IT         | Faculty
Prof. Priya     | IT         | Faculty
Dr. Amit        | IT         | Head
Dr. Neha        | HR         | Head
```

### UNION vs UNION ALL

```sql
-- UNION (removes duplicates)
SELECT Department FROM STUDENT
UNION
SELECT Department FROM FACULTY;

-- UNION ALL (keeps duplicates)
SELECT Department FROM STUDENT
UNION ALL
SELECT Department FROM FACULTY;
```

## 8. Complex Queries (Multiple Clauses)

**Definition**: Real-world queries combining multiple features.

### Example 1: Complex Analytical Query

**Scenario**: Get top 3 departments by student count with average GPA, excluding those with less than 5 students

```sql
SELECT Department, 
       COUNT(*) as StudentCount,
       AVG(GPA) as AvgGPA,
       MIN(GPA) as MinGPA,
       MAX(GPA) as MaxGPA
FROM STUDENT
GROUP BY Department
HAVING COUNT(*) >= 5
ORDER BY StudentCount DESC
LIMIT 3;
```

### Example 2: Combining JOIN, GROUP BY, HAVING, ORDER BY

**Scenario**: Get courses with enrollment > 10 students, showing total enrollment, average grade, sorted by enrollment

```sql
SELECT c.CourseName, 
       COUNT(e.StudentID) as TotalEnrollment,
       AVG(CAST(e.Grade AS DECIMAL)) as AvgGrade
FROM COURSE c
INNER JOIN ENROLLMENT e ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName
HAVING COUNT(e.StudentID) > 10
ORDER BY TotalEnrollment DESC;
```

### Example 3: Using Subquery with Aggregation

**Scenario**: Get students who have taken more courses than the average number of courses per student

```sql
SELECT s.StudentName, COUNT(e.StudentID) as CourseTaken
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
GROUP BY s.StudentID, s.StudentName
HAVING COUNT(e.StudentID) > (
    SELECT AVG(CourseCount)
    FROM (
        SELECT COUNT(*) as CourseCount
        FROM ENROLLMENT
        GROUP BY StudentID
    ) CourseStats
)
ORDER BY CourseTaken DESC;
```

## Query Optimization Tips

1. **SELECT specific columns** instead of *
2. **Use indexed columns** in WHERE clause
3. **Minimize subqueries** - use JOINs when possible
4. **Filter early** - apply WHERE before GROUP BY
5. **Use HAVING** to filter groups, not WHERE
6. **Avoid SELECT DISTINCT** unless necessary (expensive)
7. **Index foreign keys** used in JOINs

## Exam Notes

1. **Simple Query**: Know SELECT with all columns or specific columns, with DISTINCT
2. **Conditional**: Master WHERE, AND, OR, IN, BETWEEN, LIKE operators
3. **Joins**: Understand INNER, LEFT, RIGHT, FULL OUTER, SELF JOINs
4. **Aggregation**: Know COUNT, SUM, AVG, MIN, MAX with GROUP BY and HAVING
5. **Subqueries**: Show examples with IN, EXISTS, correlated subqueries
6. **Views**: Define and show how to create and use views
7. **Complex Queries**: Combine multiple features in practical scenario
8. **Execution Order**: Understand query execution sequence (FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY → LIMIT)
