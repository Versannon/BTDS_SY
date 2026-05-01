# Views and Constraints in Relational Model

## VIEWS - Virtual Tables

### Definition

A **view** is a virtual table created from the result of a SELECT query stored in the database. It doesn't store data; instead, it displays data from underlying tables based on defined query.

### View Concept

```
Physical Tables (Store actual data):
├─ STUDENT (StudentID, Name, Email, GPA, DepartmentID)
├─ COURSE (CourseID, CourseName, Credits)
└─ ENROLLMENT (StudentID, CourseID, Grade)

Views (Virtual - no data storage):
├─ IT_Students_View (filtered students)
├─ HighGPA_View (filtered by GPA)
├─ StudentCourses_View (joined data)
└─ CourseStats_View (aggregated data)
```

### Advantages of Views

#### 1. Security and Data Privacy

**Scenario**: Restrict student access to only their own data

```sql
-- Physical table (sensitive)
STUDENT (StudentID, Name, Email, Phone, GPA, Address, Parent_Contact)

-- View for students (restricted)
CREATE VIEW StudentOwnData AS
SELECT StudentID, Name, Email, GPA
FROM STUDENT
WHERE StudentID = CURRENT_USER();

-- Student can see only their own limited data
```

#### 2. Simplification and Convenience

**Scenario**: Complex query used frequently

```sql
-- Complex query (hard to remember and reuse)
SELECT s.StudentName, c.CourseName, e.Grade,
       CONCAT(d.DepartmentName, ' - ', c.CourseName) as CourseInfo
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID
INNER JOIN DEPARTMENT d ON c.DepartmentID = d.DepartmentID
WHERE e.Grade >= 'A';

-- Create view once (easy to use)
CREATE VIEW StudentCoursesWithGrade AS
SELECT s.StudentName, c.CourseName, e.Grade,
       CONCAT(d.DepartmentName, ' - ', c.CourseName) as CourseInfo
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID
INNER JOIN DEPARTMENT d ON c.DepartmentID = d.DepartmentID
WHERE e.Grade >= 'A';

-- Simple to use
SELECT * FROM StudentCoursesWithGrade;
```

#### 3. Data Abstraction

**Scenario**: Hide complex underlying structure from users

```sql
-- Physical complex schema
STUDENT, DEPARTMENT, ENROLLMENT, COURSE (4 tables)

-- Simplified view for reports
CREATE VIEW StudentCourseInfo AS
SELECT StudentName, CourseName, Grade
FROM (joined tables...);

-- Users see simple flat structure
```

#### 4. Logical Independence

**Scenario**: Change physical structure without affecting applications

```sql
-- Original: Single EMPLOYEE table with composite address
CREATE VIEW EmployeeSimple AS
SELECT EmployeeID, Name, Salary, City
FROM EMPLOYEE;

-- Later: Split address into separate table
CREATE TABLE ADDRESS (...);
ALTER TABLE EMPLOYEE DROP COLUMN City;

-- Update view to still provide same interface
CREATE OR REPLACE VIEW EmployeeSimple AS
SELECT e.EmployeeID, e.Name, e.Salary, a.City
FROM EMPLOYEE e
LEFT JOIN ADDRESS a ON e.EmployeeID = a.EmployeeID;

-- Applications using view work unchanged!
```

### Types of Views

#### 1. Simple View

**Definition**: Based on single table, no aggregation or joins

**Characteristics**:
- Single source table
- All rows or filtered rows
- Specific columns
- Can perform DML operations (INSERT, UPDATE, DELETE)

**Example**:
```sql
CREATE VIEW ActiveStudents AS
SELECT StudentID, StudentName, Email
FROM STUDENT
WHERE Status = 'Active';

-- Can perform INSERT, UPDATE, DELETE
INSERT INTO ActiveStudents VALUES (105, 'Neha', 'neha@college.edu');
-- Updates STUDENT table automatically
```

#### 2. Complex View

**Definition**: Based on multiple tables, includes aggregation, grouping, or joins

**Characteristics**:
- Multiple source tables
- Joins between tables
- Aggregate functions
- GROUP BY or HAVING
- Cannot perform DML in most databases

**Example**:
```sql
CREATE VIEW CourseEnrollmentStats AS
SELECT c.CourseName, 
       COUNT(e.StudentID) as EnrollmentCount,
       AVG(CAST(e.Grade AS DECIMAL)) as AvgGrade
FROM COURSE c
LEFT JOIN ENROLLMENT e ON c.CourseID = e.CourseID
GROUP BY c.CourseID, c.CourseName
HAVING COUNT(e.StudentID) > 5;

-- Cannot perform INSERT because it's based on aggregation
INSERT INTO CourseEnrollmentStats VALUES ('Database', 20, 3.8);
-- ERROR: Cannot insert into complex view
```

### Creating Views

**Basic Syntax**:
```sql
CREATE VIEW view_name AS
SELECT columns...
FROM table(s)
WHERE condition(s);
```

**Examples**:

**1. Simple View**:
```sql
CREATE VIEW IT_Students AS
SELECT StudentID, StudentName, GPA
FROM STUDENT
WHERE Department = 'IT';
```

**2. View with Multiple Tables (Join)**:
```sql
CREATE VIEW StudentCourseAssignments AS
SELECT s.StudentName, c.CourseName, e.Semester
FROM STUDENT s
INNER JOIN ENROLLMENT e ON s.StudentID = e.StudentID
INNER JOIN COURSE c ON e.CourseID = c.CourseID;
```

**3. View with Aggregation**:
```sql
CREATE VIEW DepartmentStats AS
SELECT Department, 
       COUNT(*) as StudentCount,
       AVG(GPA) as AvgGPA,
       MIN(GPA) as LowestGPA,
       MAX(GPA) as HighestGPA
FROM STUDENT
GROUP BY Department;
```

**4. View with Calculated Columns**:
```sql
CREATE VIEW StudentDetails AS
SELECT StudentID, 
       StudentName,
       GPA,
       (CASE 
           WHEN GPA >= 3.7 THEN 'Excellent'
           WHEN GPA >= 3.3 THEN 'Very Good'
           WHEN GPA >= 3.0 THEN 'Good'
           ELSE 'Average'
       END) as Performance
FROM STUDENT;
```

### Using Views

**Query View Like Table**:
```sql
-- Select from view
SELECT * FROM IT_Students;

-- Filter view results
SELECT StudentName, GPA
FROM IT_Students
WHERE GPA > 3.5;

-- Join view with table
SELECT st.StudentName, d.DepartmentName
FROM IT_Students st
INNER JOIN DEPARTMENT d ON st.Department = d.DepartmentName;
```

### Modifying Views

**Alter View** (SQL Server):
```sql
ALTER VIEW IT_Students AS
SELECT StudentID, StudentName, GPA, Email  -- Added Email
FROM STUDENT
WHERE Department = 'IT' AND Status = 'Active';  -- Added Status filter
```

**Create or Replace View** (MySQL, PostgreSQL):
```sql
CREATE OR REPLACE VIEW IT_Students AS
SELECT StudentID, StudentName, GPA, Email
FROM STUDENT
WHERE Department = 'IT' AND Status = 'Active';
```

**Drop View**:
```sql
DROP VIEW IT_Students;

-- Drop multiple views
DROP VIEW StudentCourseAssignments, DepartmentStats;

-- Drop with error handling
DROP VIEW IF EXISTS IT_Students;
```

### View Materialization

**Virtual View** (Default):
- View query executed each time accessed
- Data always current
- No storage overhead
- Performance depends on underlying query complexity

```sql
-- Virtual view
CREATE VIEW StudentCount AS
SELECT COUNT(*) as Total FROM STUDENT;

-- Each query execution runs the COUNT
SELECT * FROM StudentCount;  -- Executes COUNT
SELECT * FROM StudentCount;  -- Executes COUNT again
```

**Materialized View** (Some databases):
- View results stored like table
- Fast query performance
- Must refresh periodically
- Additional storage needed

```sql
-- Oracle example
CREATE MATERIALIZED VIEW StudentCount AS
SELECT COUNT(*) as Total FROM STUDENT;

-- Refresh to update
REFRESH MATERIALIZED VIEW StudentCount;
```

---

## CONSTRAINTS Revisited

### Domain Constraint

**Definition**: Restricts valid values for an attribute to specified domain (data type, range).

**Purpose**: Ensure only valid data types and ranges stored

**Implementation**:
- Data type definition
- CHECK constraint
- ENUM/SET data types

**Example**:
```sql
CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100),
    Credits INT CHECK (Credits BETWEEN 1 AND 6),
    Difficulty ENUM('Beginner', 'Intermediate', 'Advanced')
);

-- Valid:
INSERT INTO COURSE VALUES (1, 'Database', 4, 'Intermediate');

-- Invalid:
INSERT INTO COURSE VALUES (2, 'Networks', 8, 'Intermediate');
-- FAILS: Credits must be 1-6

INSERT INTO COURSE VALUES (3, 'SQL', 3, 'Expert');
-- FAILS: Expert not in ENUM
```

### Entity Integrity Constraint

**Definition**: Primary key cannot be NULL, and must be unique.

**Formal Rule**: 
- PK ≠ NULL
- No two tuples have same PK value

**Purpose**: Ensure each entity instance is uniquely identifiable

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT NOT NULL,
    StudentName VARCHAR(50),
    CONSTRAINT pk_student PRIMARY KEY (StudentID)
);

-- Valid:
INSERT INTO STUDENT VALUES (101, 'Raj');

-- Invalid:
INSERT INTO STUDENT VALUES (NULL, 'Priya');
-- FAILS: PK cannot be NULL

INSERT INTO STUDENT VALUES (101, 'Amit');
-- FAILS: Duplicate StudentID violates uniqueness
```

### Referential Integrity Constraint

**Definition**: Foreign key values must reference valid primary key values in referenced table.

**Formal Rule**:
- For each FK value in R1
- Either value exists as PK in R2
- Or value is NULL

**Purpose**: Maintain valid relationships between tables

**Example**:
```sql
CREATE TABLE DEPARTMENT (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(50)
);

CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    DepartmentID INT,
    CONSTRAINT fk_dept FOREIGN KEY (DepartmentID) 
    REFERENCES DEPARTMENT(DepartmentID)
);

-- Valid:
INSERT INTO DEPARTMENT VALUES (1, 'IT');
INSERT INTO EMPLOYEE VALUES (101, 'Raj', 1);  -- DepartmentID 1 exists

-- Invalid:
INSERT INTO EMPLOYEE VALUES (102, 'Priya', 5);
-- FAILS: DepartmentID 5 doesn't exist in DEPARTMENT
```

**Referential Integrity Actions**:
```sql
-- Prevent deletion of referenced rows
ON DELETE RESTRICT

-- Delete dependent rows automatically
ON DELETE CASCADE

-- Set dependent FK to NULL
ON DELETE SET NULL

-- Set dependent FK to default
ON DELETE SET DEFAULT

-- Similar options for UPDATE
ON UPDATE RESTRICT | CASCADE | SET NULL | SET DEFAULT
```

### Key Constraint

**Definition**: Ensures PRIMARY KEY and UNIQUE constraints maintain uniqueness.

**Types**:
- PRIMARY KEY: Uniqueness for main identifier
- UNIQUE: Uniqueness for alternate identifier
- CANDIDATE KEY: Any potential key

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,      -- Key constraint (PK)
    Email VARCHAR(100) UNIQUE,      -- Key constraint (UNIQUE)
    Phone VARCHAR(10) UNIQUE,       -- Key constraint (UNIQUE)
    StudentName VARCHAR(50)
);

-- All three attributes enforce uniqueness
```

## Constraints Summary Table

| Constraint | Purpose | NULL Allowed | Multiple | Example |
|-----------|---------|-----------|----------|---------|
| PRIMARY KEY | Unique identifier | No | 1 per table | StudentID |
| FOREIGN KEY | Reference other table | Yes | Multiple | DepartmentID → DEPT |
| UNIQUE | Unique values | Yes | Multiple | Email, Phone |
| NOT NULL | Required value | No | Multiple | Name, Salary |
| CHECK | Range/condition | N/A | Multiple | Age > 18 |
| DEFAULT | Default value | N/A | Multiple | Status = 'Active' |

## View vs Table

| Aspect | View | Table |
|--------|------|-------|
| **Storage** | Virtual (no storage) | Physical (stores data) |
| **Query Performance** | Slower (recreated each time) | Faster (data ready) |
| **Data Updates** | Always current | Must refresh |
| **Space Used** | No overhead | Occupies disk space |
| **DML Operations** | Simple views only | All tables |
| **Creation** | From SELECT query | Direct table creation |

## Practical Scenario: Using Views and Constraints

**Database Schema**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE NOT NULL,
    GPA DECIMAL(3, 2) CHECK (GPA >= 0 AND GPA <= 4.0),
    DepartmentID INT NOT NULL,
    Status VARCHAR(20) DEFAULT 'Active',
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
);

-- Create views for different purposes
CREATE VIEW TopStudents AS
SELECT StudentID, StudentName, GPA
FROM STUDENT
WHERE GPA >= 3.7;

CREATE VIEW ActiveITStudents AS
SELECT StudentID, StudentName, Email
FROM STUDENT
WHERE DepartmentID = 1 AND Status = 'Active';

CREATE VIEW StudentStats AS
SELECT DepartmentID, 
       COUNT(*) as StudentCount,
       AVG(GPA) as AvgGPA
FROM STUDENT
GROUP BY DepartmentID;
```

## Exam Notes

1. **View Definition**: Explain as virtual table storing query result
2. **Advantages**: Mention security, simplification, abstraction, logical independence
3. **Types**: Differentiate simple vs complex views
4. **Syntax**: Write CREATE VIEW examples
5. **Constraints**: Define each type clearly
6. **Differences**: Compare PRIMARY KEY vs UNIQUE vs FOREIGN KEY
7. **Referential Integrity**: Explain with diagrams
8. **Practical Example**: Show realistic schema with views and constraints
9. **View vs Table**: Explain storage and performance differences
10. **DML on Views**: Mention limitations on complex views
