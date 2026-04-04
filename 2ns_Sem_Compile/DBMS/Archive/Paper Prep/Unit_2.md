# DBMS NOTES - UNIT II
## Introduction to Relational Model

**Topics:** Integrity constraints, relational queries, logical design, views, altering tables, relational algebra, relational calculus

---

## 1. Relational Model

The **Relational Model** was proposed by **E. F. Codd** in 1970.

### Key Characteristics

- Data is stored in **relations (tables)**
- Simple and understandable structure
- Strong theoretical foundation
- Widely used (SQL databases)

### Basic Terminology

| Term | Meaning | Example |
|------|---------|---------|
| **Relation** | Table containing data | Employee table |
| **Tuple** | Row in a table | One employee record |
| **Attribute** | Column in a table | EmployeeID, Name, Salary |
| **Domain** | Set of possible values for an attribute | Ages between 18-65 |
| **Degree** | Number of attributes (columns) in a relation | Employee table has 5 attributes |
| **Cardinality** | Number of tuples (rows) in a relation | 100 employees = cardinality 100 |

### Example Relation: Employee

```
EmployeeID | Name        | Position      | Salary  | DepartmentID
-----------|-------------|---------------|---------|---------------
101        | John Smith  | Manager       | 75000   | D01
102        | Sarah Jones | Developer     | 65000   | D02
103        | Mike Brown  | Analyst       | 60000   | D02
```

- **Relation:** Employee
- **Degree:** 5 (5 columns)
- **Cardinality:** 3 (3 rows/tuples)

---

## 2. Integrity Constraints

**Integrity constraints** ensure accuracy and consistency of data in the database.

### Types of Integrity Constraints

#### 1. Domain Constraint

- **Definition:** Attribute values must belong to a valid domain
- **Purpose:** Ensures meaningful data
- **Example:**
  - Age between 18 and 65
  - Email must contain '@' symbol
  - Salary > 0

```sql
CREATE TABLE Employee (
    EmployeeID INT NOT NULL,
    Name VARCHAR(50),
    Age INT CHECK (Age >= 18 AND Age <= 65),
    Salary DECIMAL CHECK (Salary > 0)
);
```

#### 2. Key Constraint

- **Definition:** Keys uniquely identify records
- **Purpose:** Prevents duplicate rows

**Types of Keys:**

| Key Type | Description | Uniqueness | Null Allowed |
|----------|-------------|-----------|--------------|
| **Super Key** | Any set of attributes that uniquely identifies a tuple | Yes | May vary |
| **Candidate Key** | Minimal super key | Yes | No |
| **Primary Key** | Selected candidate key | Yes | No |
| **Composite Key** | Primary key with multiple attributes | Yes | No |
| **Alternate Key** | Candidate key not chosen as primary key | Yes | No |
| **Foreign Key** | References primary key of another table | No | Yes |

**Example:**

```sql
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,        -- Primary Key
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,           -- Candidate Key
    DepartmentID INT
);
```

#### 3. Entity Integrity Constraint

- **Definition:** Primary key cannot contain NULL values
- **Purpose:** Ensures every row is uniquely identifiable
- **Violation Example:**
  - Trying to insert employee without EmployeeID

```sql
-- VALID
INSERT INTO Employee VALUES (101, 'John', 'john@mail.com', 'D01');

-- INVALID (violates entity integrity)
INSERT INTO Employee VALUES (NULL, 'Jane', 'jane@mail.com', 'D02');
```

#### 4. Referential Integrity Constraint

- **Definition:** Foreign key must reference an existing primary key value
- **Purpose:** Maintains relationships between tables
- **Example:**
  - Employee.DepartmentID must reference Department.DepartmentID

```sql
CREATE TABLE Department (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(50)
);

CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Department(DepartmentID)
);

-- VALID (Department D01 exists)
INSERT INTO Employee VALUES (101, 'John', 'D01');

-- INVALID (Department D99 doesn't exist)
INSERT INTO Employee VALUES (102, 'Jane', 'D99');
```

---

## 3. Querying Relational Data

Data is retrieved from relational databases using **SQL (Structured Query Language)** queries.

### Common SQL Query Examples

#### Select Records

```sql
-- Get all employees
SELECT * FROM Employees;

-- Get specific columns
SELECT EmployeeID, Name, Salary FROM Employees;
```

#### Conditional Query (WHERE clause)

```sql
-- Find employees with age > 30
SELECT * FROM Employees WHERE Age > 30;

-- Find employees in department D02 with salary > 50000
SELECT * FROM Employees 
WHERE DepartmentID = 'D02' AND Salary > 50000;
```

#### Sorting (ORDER BY)

```sql
-- Sort by age ascending (default)
SELECT * FROM Employees ORDER BY Age;

-- Sort by salary descending
SELECT * FROM Employees ORDER BY Salary DESC;

-- Sort by multiple columns
SELECT * FROM Employees ORDER BY Department, Age DESC;
```

#### Aggregation

```sql
-- Count total employees
SELECT COUNT(*) FROM Employees;

-- Average salary
SELECT AVG(Salary) FROM Employees;

-- Sum of all salaries
SELECT SUM(Salary) FROM Employees;

-- Group by department
SELECT DepartmentID, COUNT(*) AS EmployeeCount
FROM Employees
GROUP BY DepartmentID;
```

#### Joins

```sql
-- Inner join (show matching records)
SELECT e.Name, d.DepartmentName
FROM Employees e
INNER JOIN Department d ON e.DepartmentID = d.DepartmentID;

-- Left outer join
SELECT e.Name, d.DepartmentName
FROM Employees e
LEFT JOIN Department d ON e.DepartmentID = d.DepartmentID;
```

---

## 4. Logical Database Design

**Logical design** converts conceptual ER models into relational tables.

### Design Steps

#### 1. Convert Entity Sets → Tables

- Each entity type becomes a table
- Each entity instance becomes a row

```
Entity: Student
↓ Converts to
Table: Student (StudentID, Name, Email, DOB)
```

#### 2. Convert Attributes → Columns

- Simple attributes become columns directly
- Composite attributes split into separate columns
- Multivalued attributes get separate tables

#### 3. Convert Relationships → Foreign Keys

- One-to-Many: Foreign key in "Many" side table
- Many-to-Many: Create junction/bridge table
- One-to-One: Foreign key in either table

#### 4. Define Constraints

- Primary keys
- Foreign keys
- Check constraints
- Not-null constraints

### Example Logical Design

```
ER Model:
- Entity: Student (StudentID, Name, Email)
- Entity: Course (CourseID, CourseName, Credits)
- Relationship: Enrolls (M:N)

Converts to:

CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE
);

CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50),
    Credits INT
);

CREATE TABLE Enrollment (  -- Junction table
    StudentID INT,
    CourseID INT,
    EnrollmentDate DATE,
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);
```

---

## 5. Views in DBMS

A **view** is a **virtual table** created from the result of a SQL query.

### Characteristics

- Not stored physically in database
- Dynamically created when accessed
- Based on one or more tables
- Provides logical independence

### Creating a View

```sql
CREATE VIEW emp_view AS
SELECT EmployeeID, Name, DepartmentID
FROM Employees
WHERE Salary > 50000;

-- Access view like a table
SELECT * FROM emp_view;
```

### Advantages of Views

| Advantage | Description |
|-----------|-------------|
| **Security** | Hide sensitive columns (salaries, personal info) |
| **Simplifies queries** | Pre-write complex queries |
| **Data abstraction** | Hide underlying table structure |
| **Logical data independence** | Change physical schema without affecting views |
| **Reduced redundancy** | Avoid rewriting common queries |

### Example: Security with Views

```sql
-- Original table with sensitive data
CREATE TABLE Employee (
    EmployeeID INT,
    Name VARCHAR(50),
    Salary INT,          -- Sensitive
    SSN VARCHAR(11),     -- Sensitive
    DepartmentID INT
);

-- View for regular employees (without sensitive data)
CREATE VIEW emp_public_view AS
SELECT EmployeeID, Name, DepartmentID
FROM Employee;

-- Employees can only see limited information
SELECT * FROM emp_public_view;  -- No salary or SSN visible
```

### Types of Views

| Type | Description | Example |
|------|-------------|---------|
| **Simple View** | Based on single table | View from one Employee table |
| **Complex View** | Based on multiple tables | View joining Employee and Department |

### Deleting a View

```sql
DROP VIEW emp_view;
```

---

## 6. Altering and Destroying Tables

### ALTER TABLE

**Modifies existing table structure without deleting data.**

```sql
-- Add new column
ALTER TABLE Employees ADD Salary INT;

-- Drop a column
ALTER TABLE Employees DROP COLUMN Salary;

-- Modify column datatype
ALTER TABLE Employees MODIFY COLUMN Name VARCHAR(100);

-- Add constraint
ALTER TABLE Employees ADD CONSTRAINT pk_emp PRIMARY KEY (EmployeeID);

-- Rename column
ALTER TABLE Employees RENAME COLUMN Age TO YearsOld;
```

### DROP TABLE

**Deletes the entire table and all its data completely.**

```sql
-- Drop entire table
DROP TABLE Employees;

-- Drop with condition (some databases)
DROP TABLE IF EXISTS Employees;
```

### Key Differences

| Operation | Effect | Data |
|-----------|--------|------|
| **ALTER TABLE** | Modifies structure | Data retained |
| **DROP TABLE** | Removes entire table | Data deleted |
| **DELETE** | Removes rows | Table structure remains |
| **TRUNCATE** | Removes all rows quickly | Table structure remains |

---

## 7. Relational Algebra

**Relational Algebra** is a procedural query language for relational databases.

- Defines operations on relations
- Theoretical foundation of SQL
- Provides algebraic notation

### Fundamental Operations

#### 1. Selection (σ - sigma)

- **Definition:** Selects rows satisfying a condition
- **Notation:** σ condition (Relation)
- **Example:** σ Age>30 (Employees)
- **Equivalent SQL:** SELECT * FROM Employees WHERE Age > 30;

#### 2. Projection (π - pi)

- **Definition:** Selects specific columns
- **Notation:** π column1,column2 (Relation)
- **Example:** π Name,Salary (Employees)
- **Equivalent SQL:** SELECT Name, Salary FROM Employees;

#### 3. Union (∪)

- **Definition:** Combines rows from two relations
- **Notation:** R1 ∪ R2
- **Requirement:** Relations must have same schema
- **Example:** σ Department='Sales' (Employees) ∪ σ Department='Marketing' (Employees)

#### 4. Intersection (∩)

- **Definition:** Returns common rows from two relations
- **Notation:** R1 ∩ R2
- **Example:** Employees in both Sales and Marketing (unlikely but possible)

#### 5. Difference (−)

- **Definition:** Returns rows in first relation but not in second
- **Notation:** R1 − R2
- **Example:** Employees with age > 30 minus employees with salary > 100000

#### 6. Cartesian Product (×)

- **Definition:** All combinations of rows from two relations
- **Notation:** R1 × R2
- **Result:** (m × n) rows if R1 has m rows and R2 has n rows
- **Example:** Employee × Department (all possible employee-department pairs)

#### 7. Join (⋈) and Variants

- **Natural Join:** Combines relations on common attributes
- **Equijoin:** Join based on equality condition
- **Theta Join:** Join with any comparison operator

**Example:**
```
Employee ⋈ Department
Joins on: Employee.DepartmentID = Department.DepartmentID
```

### Combined Example

Find names and salaries of all Sales employees with age > 25:

```
π Name, Salary (σ (Department='Sales' ∧ Age>25) (Employees))
```

---

## 8. Tuple Relational Calculus (TRC)

**Tuple Relational Calculus** is a non-procedural query language.

### Characteristics

- **Non-procedural:** Specifies WHAT, not HOW
- **Logic-based:** Uses mathematical logic
- **Foundation:** Basis for SQL SELECT statements

### Basic Form

```
{ t | P(t) }
```

- **t:** Tuple variable
- **P(t):** Predicate (condition) on tuple t

### Examples

#### Example 1: Find all employees with age > 30

```
{ e | Employee(e) ∧ e.Age > 30 }
```

**Meaning:** Find all tuples e in Employee relation where age > 30

#### Example 2: Find names of employees in Sales department

```
{ e.Name | Employee(e) ∧ e.Department = 'Sales' }
```

**Meaning:** Project Name of all employees where Department = Sales

#### Example 3: Find employees and their departments

```
{ e.Name, d.DepartmentName | Employee(e) ∧ Department(d) ∧ e.DepartmentID = d.DepartmentID }
```

**Meaning:** Find Name and DepartmentName where employee's DepartmentID matches department's ID

### Existential and Universal Quantifiers

- **Existential (∃):** "There exists"
- **Universal (∀):** "For all"

```
{ e | Employee(e) ∧ ∃ s in Salary(s.EmployeeID = e.EmployeeID ∧ s.Amount > 50000) }
```

---

## 9. Domain Relational Calculus (DRC)

**Domain Relational Calculus** differs from TRC in that variables represent attribute values instead of tuples.

### Characteristics

- Variables represent **individual attribute values**
- Less intuitive than TRC
- Still non-procedural

### Basic Form

```
{ x1, x2, ... | P(x1, x2, ...) }
```

- **x1, x2, ...:** Domain variables
- **P(...):** Predicate condition

### Examples

#### Example 1: Find employee names where age > 30

```
{ Name | ∃ ID, Age (Employee(ID, Name, Age) ∧ Age > 30) }
```

**Meaning:** Find Name value where Employee relation contains (ID, Name, Age) and Age > 30

#### Example 2: Find employee names and departments

```
{ Name, DeptName | ∃ ID, Dept (Employee(ID, Name, Dept) ∧ Department(Dept, DeptName)) }
```

### Difference from TRC

| Feature | TRC | DRC |
|---------|-----|-----|
| Variables | Tuple variables | Domain variables |
| Granularity | Whole tuples | Individual attributes |
| Complexity | More intuitive | Less intuitive |
| Base for SQL | More direct | More translation needed |

---

## Summary

- **Relational Model** organizes data in tables with relationships through keys
- **Integrity Constraints** ensure data accuracy and consistency
- **SQL Queries** retrieve and manipulate relational data
- **Logical Design** converts ER models into relational tables
- **Views** provide security and simplify complex queries
- **Relational Algebra** provides algebraic operations on relations
- **TRC and DRC** are formal query languages expressing queries logically
- **Proper schema design** is critical for database efficiency and maintenance
