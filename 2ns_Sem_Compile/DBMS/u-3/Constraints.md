# SQL Constraints - Comprehensive Guide

## Definition

**Constraints** are rules or conditions applied to database columns and tables to ensure data validity, consistency, and integrity. They prevent invalid data from being entered into the database.

## Constraints Hierarchy

```
Database Constraints
    │
    ├─ Column-Level Constraints (Apply to single column)
    │  ├─ NOT NULL
    │  ├─ UNIQUE
    │  ├─ PRIMARY KEY
    │  ├─ FOREIGN KEY
    │  ├─ CHECK
    │  └─ DEFAULT
    │
    └─ Table-Level Constraints (Apply to one or more columns)
       ├─ PRIMARY KEY (composite)
       ├─ FOREIGN KEY (composite)
       ├─ UNIQUE (composite)
       ├─ CHECK (multiple columns)
       └─ Index constraints
```

## 1. PRIMARY KEY

**Definition**: Uniquely identifies each row in table. Primary key cannot be NULL.

**Characteristics**:
- Unique values only (no duplicates)
- Cannot be NULL
- One primary key per table
- Automatically creates index
- Enforces entity integrity

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,  -- Column-level
    StudentName VARCHAR(50)
);

-- OR Table-level:
CREATE TABLE STUDENT (
    StudentID INT,
    StudentName VARCHAR(50),
    PRIMARY KEY (StudentID)
);

-- Composite PRIMARY KEY
CREATE TABLE ENROLLMENT (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(10),
    PRIMARY KEY (StudentID, CourseID, Semester)
);
```

**Violation Example**:
```sql
INSERT INTO STUDENT VALUES (101, 'Raj');
INSERT INTO STUDENT VALUES (101, 'Priya');  -- FAILS: Duplicate StudentID
INSERT INTO STUDENT VALUES (NULL, 'Amit');  -- FAILS: NULL not allowed
```

## 2. FOREIGN KEY

**Definition**: Ensures referential integrity by enforcing that values reference valid primary keys in another table.

**Characteristics**:
- References primary key in other table
- Can be NULL (unless NOT NULL specified)
- Maintains relationship between tables
- Prevents orphaned records
- Can accept CASCADE/SET NULL actions

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
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
);
```

**Referential Integrity**:
```
DEPARTMENT Table:
DepartmentID | DepartmentName
1            | IT
2            | HR
3            | Finance

EMPLOYEE Table (valid):
EmployeeID | Name   | DepartmentID
101        | Raj    | 1         ✓ (DepartmentID 1 exists)
102        | Priya  | 2         ✓ (DepartmentID 2 exists)
103        | Amit   | NULL      ✓ (NULL allowed)

EMPLOYEE Table (invalid):
EmployeeID | Name   | DepartmentID
104        | Neha   | 5         ✗ (DepartmentID 5 doesn't exist)
```

**Violation Example**:
```sql
INSERT INTO EMPLOYEE VALUES (104, 'Neha', 5);  
-- FAILS: DepartmentID 5 not in DEPARTMENT table
```

**Foreign Key Actions**:
```sql
-- ON DELETE RESTRICT (default - prevent deletion)
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
    ON DELETE RESTRICT
);

-- Try to delete department 1:
DELETE FROM DEPARTMENT WHERE DepartmentID = 1;
-- FAILS: Employees exist in this department

-- ON DELETE CASCADE (delete dependent records)
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
    ON DELETE CASCADE
);

DELETE FROM DEPARTMENT WHERE DepartmentID = 1;
-- All employees in department 1 are automatically deleted

-- ON DELETE SET NULL (set to NULL)
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
    ON DELETE SET NULL
);

DELETE FROM DEPARTMENT WHERE DepartmentID = 1;
-- All employees' DepartmentID = 1 become NULL
```

## 3. UNIQUE

**Definition**: Ensures all values in column are unique (no duplicates). Unlike PRIMARY KEY, UNIQUE allows NULLs.

**Characteristics**:
- No duplicate values
- Can be NULL (multiple NULLs allowed - depends on DB)
- Multiple UNIQUE constraints per table
- Does not auto-create primary index

**Difference from PRIMARY KEY**:
```
PRIMARY KEY:
├─ Uniqueness: Yes
├─ NULLs allowed: No
├─ Number per table: Exactly 1
└─ Purpose: Identifies records

UNIQUE:
├─ Uniqueness: Yes
├─ NULLs allowed: Yes
├─ Number per table: Multiple
└─ Purpose: Prevent duplicates
```

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,      -- Primary key
    Email VARCHAR(100) UNIQUE,      -- Unique, no NULLs allowed
    Phone VARCHAR(10) UNIQUE,       -- Unique, NULLs allowed
    StudentName VARCHAR(50)
);

-- Table-level:
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    Email VARCHAR(100),
    Phone VARCHAR(10),
    UNIQUE (Email),
    UNIQUE (Phone)
);

-- Composite UNIQUE (combination must be unique)
CREATE TABLE ENROLLMENT (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(10),
    UNIQUE (StudentID, CourseID, Semester)
);
```

**Examples**:
```sql
-- Valid:
INSERT INTO STUDENT VALUES (101, 'raj@college.edu', '9876543210', 'Raj');
INSERT INTO STUDENT VALUES (102, 'priya@college.edu', NULL, 'Priya');
INSERT INTO STUDENT VALUES (103, NULL, '9876543211', 'Amit');

-- Invalid:
INSERT INTO STUDENT VALUES (104, 'raj@college.edu', '9876543212', 'Neha');
-- FAILS: Email already exists

INSERT INTO STUDENT VALUES (105, NULL, '9876543210', 'Vijay');
-- FAILS: Phone already exists
```

## 4. NOT NULL

**Definition**: Ensures column always has a value (never NULL).

**Characteristics**:
- Must have value when inserting
- Cannot omit value
- Column-level only

**Example**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50) NOT NULL,  -- Must have value
    Email VARCHAR(100),                 -- Can be NULL
    Salary DECIMAL(10, 2) NOT NULL
);
```

**Violations**:
```sql
INSERT INTO EMPLOYEE VALUES (101, 'Raj', 'raj@company.com', 50000);  -- OK

INSERT INTO EMPLOYEE VALUES (102, NULL, 'priya@company.com', 45000);
-- FAILS: EmployeeName cannot be NULL

INSERT INTO EMPLOYEE VALUES (103, 'Amit', NULL, 60000);
-- OK: Email can be NULL

INSERT INTO EMPLOYEE VALUES (104, 'Neha', 'neha@company.com', NULL);
-- FAILS: Salary cannot be NULL
```

## 5. CHECK

**Definition**: Allows specifying a condition that must be true for each row.

**Characteristics**:
- Custom validation rules
- Can reference single or multiple columns
- Condition evaluated for each row

**Example - Single Column**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    Age INT CHECK (Age >= 18 AND Age <= 65),
    Salary DECIMAL(10, 2) CHECK (Salary > 0)
);

-- Valid:
INSERT INTO EMPLOYEE VALUES (101, 'Raj', 30, 50000);

-- Invalid:
INSERT INTO EMPLOYEE VALUES (102, 'Priya', 15, 45000);
-- FAILS: Age < 18

INSERT INTO EMPLOYEE VALUES (103, 'Amit', 35, -5000);
-- FAILS: Salary < 0
```

**Example - Multiple Columns**:
```sql
CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    StartDate DATE,
    EndDate DATE,
    CHECK (EndDate > StartDate)  -- End must be after start
);

-- Valid:
INSERT INTO COURSE VALUES (1, 'Database', '2024-01-15', '2024-05-31');

-- Invalid:
INSERT INTO COURSE VALUES (2, 'SQL', '2024-06-01', '2024-01-15');
-- FAILS: EndDate not > StartDate
```

**Complex CHECK Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50),
    GPA DECIMAL(3, 2),
    EnrollmentStatus VARCHAR(20),
    CHECK (
        (GPA >= 3.5 AND EnrollmentStatus = 'Active')
        OR
        (GPA < 3.5 AND EnrollmentStatus IN ('Active', 'Probation'))
    )
);
```

## 6. DEFAULT

**Definition**: Assigns a default value when no value is provided for column.

**Characteristics**:
- Applied if value not specified in INSERT
- Can be constant, function, or expression
- Column-level only

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentName VARCHAR(50) NOT NULL,
    Department VARCHAR(30) DEFAULT 'General',
    JoinDate DATE DEFAULT CURRENT_DATE,
    Status VARCHAR(20) DEFAULT 'Active',
    GPA DECIMAL(3, 2) DEFAULT 0.0
);

-- Insert with defaults:
INSERT INTO STUDENT (StudentID, StudentName)
VALUES (1, 'Raj');

-- Result:
StudentID | StudentName | Department | JoinDate   | Status | GPA
1         | Raj         | General    | 2024-01-15 | Active | 0.0

-- Insert with explicit values:
INSERT INTO STUDENT (StudentID, StudentName, Department, JoinDate)
VALUES (2, 'Priya', 'IT', '2024-02-01');

-- Result:
StudentID | StudentName | Department | JoinDate   | Status | GPA
2         | Priya       | IT         | 2024-02-01 | Active | 0.0
```

**Function-Based Defaults**:
```sql
CREATE TABLE AUDIT_LOG (
    LogID INT PRIMARY KEY AUTO_INCREMENT,
    Action VARCHAR(50) NOT NULL,
    CreatedAt TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CreatedBy VARCHAR(50) DEFAULT USER()
);

INSERT INTO AUDIT_LOG (LogID, Action)
VALUES (1, 'Database backup started');

-- Result:
LogID | Action                  | CreatedAt           | CreatedBy
1     | Database backup started | 2024-01-15 10:30:00 | admin@localhost
```

## 7. AUTO_INCREMENT (MySQL)

**Definition**: Automatically generates sequential numeric values.

**Characteristics**:
- MySQL-specific feature
- Typically used with PRIMARY KEY
- Generates unique sequential numbers
- Starts at 1 (or specified value)

**Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    StudentName VARCHAR(50),
    Email VARCHAR(100)
);

INSERT INTO STUDENT (StudentName, Email)
VALUES ('Raj', 'raj@college.edu');
-- StudentID auto-generated: 1

INSERT INTO STUDENT (StudentName, Email)
VALUES ('Priya', 'priya@college.edu');
-- StudentID auto-generated: 2

INSERT INTO STUDENT (StudentName, Email)
VALUES ('Amit', 'amit@college.edu');
-- StudentID auto-generated: 3
```

## Constraint Combinations

**Example: Strong Table Design**:
```sql
CREATE TABLE STUDENT (
    -- PRIMARY KEY: Unique identifier
    StudentID INT PRIMARY KEY AUTO_INCREMENT,
    
    -- NOT NULL: Required fields
    StudentName VARCHAR(50) NOT NULL,
    
    -- UNIQUE: Email must be unique
    Email VARCHAR(100) UNIQUE NOT NULL,
    
    -- CHECK: Validate data
    Age INT CHECK (Age >= 17 AND Age <= 65),
    
    -- FOREIGN KEY: Reference department
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID),
    
    -- DEFAULT: Default status
    Status VARCHAR(20) DEFAULT 'Active',
    
    -- UNIQUE composite: No duplicate enrollments
    UNIQUE (StudentID, Email)
);
```

## Viewing Constraints

```sql
-- MySQL
SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE
FROM INFORMATION_SCHEMA.TABLE_CONSTRAINTS
WHERE TABLE_NAME = 'STUDENT';

-- SQL Server
SELECT name, type_desc
FROM sys.objects
WHERE parent_object_id = OBJECT_ID('STUDENT');

-- PostgreSQL
SELECT constraint_name, constraint_type
FROM information_schema.table_constraints
WHERE table_name = 'STUDENT';
```

## Dropping Constraints

```sql
-- MySQL - Drop UNIQUE constraint
ALTER TABLE STUDENT DROP INDEX email;

-- MySQL - Drop CHECK constraint
ALTER TABLE STUDENT DROP CHECK age_check;

-- SQL Server
ALTER TABLE STUDENT DROP CONSTRAINT email;

-- PostgreSQL
ALTER TABLE STUDENT DROP CONSTRAINT email;
```

## Best Practices

1. **Always use PRIMARY KEY** - Every table should have one
2. **Use Foreign Keys** - Maintain referential integrity
3. **Apply NOT NULL** - For required columns
4. **Use CHECK** - For data validation rules
5. **Use UNIQUE** - For natural identifiers (Email, Phone, etc.)
6. **Use DEFAULT** - For predictable default values
7. **Name Constraints** - Make names meaningful for management
8. **Document Constraints** - Explain business rules in comments

## Exam Notes

1. **Definition**: Clear definition for each constraint type
2. **Syntax**: Write CREATE TABLE with constraints
3. **Difference**: Explain differences (PK vs UNIQUE, NOT NULL vs DEFAULT)
4. **Violations**: Show what causes constraint violations
5. **Combinations**: Show realistic table with multiple constraints
6. **Foreign Key Actions**: Explain ON DELETE options
7. **Examples**: Include practical real-world examples
8. **Best Practices**: Mention when to use each constraint
