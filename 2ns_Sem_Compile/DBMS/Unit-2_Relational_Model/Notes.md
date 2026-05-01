# Unit 2: Relational Model

## Definition and Historical Context

The **Relational Model** is a data model that represents data as relations (tables), where data is organized into rows and columns. It was proposed by **Dr. Edgar F. Codd** in 1970 as a revolutionary approach to database management.

### Why Relational Model?

**Before Relational Model**:
- Hierarchical and network models were complex
- No formal mathematical foundation
- Difficult to optimize queries
- Program-data dependencies

**After Relational Model**:
- Simple and intuitive (tables are familiar)
- Mathematical basis (set theory and predicate logic)
- Query optimization possible
- Data independence achieved
- Standard SQL language

## Basic Terminology

The relational model uses specific terminology to describe its components:

### 1. Relation

**Definition**: A relation is a two-dimensional table consisting of rows and columns.

**Characteristics**:
- Each relation has a name
- Represents an entity type or relationship
- Also called "table"

**Example**:
```
Relation Name: STUDENT

┌───────────┬──────────────┬──────────────┬──────┐
│ StudentID │ StudentName  │ Email        │ Age  │
├───────────┼──────────────┼──────────────┼──────┤
│ 101       │ Raj Kumar    │ raj@col.edu  │ 20   │
│ 102       │ Priya Singh  │ priya@col.edu│ 19   │
│ 103       │ Amit Patel   │ amit@col.edu │ 21   │
└───────────┴──────────────┴──────────────┴──────┘
```

### 2. Tuple

**Definition**: A tuple is a single row in a relation, representing one instance of an entity.

**Characteristics**:
- Also called "record" or "row"
- Contains values for all attributes
- Each tuple is unique (in practice, often enforced)

**Example**:
```
One tuple from STUDENT relation:
(101, 'Raj Kumar', 'raj@col.edu', 20)
```

**Number of tuples** = Cardinality of the relation

### 3. Attribute

**Definition**: An attribute is a column in a relation, representing a property of the entity.

**Characteristics**:
- Also called "field" or "column"
- Has a name and data type
- Values are atomic (single values, not composite)

**Example**:
```
STUDENT relation has attributes:
  1. StudentID (INT)
  2. StudentName (VARCHAR(50))
  3. Email (VARCHAR(100))
  4. Age (INT)
```

**Number of attributes** = Degree of the relation

### 4. Domain

**Definition**: A domain is the set of allowed values that an attribute can take.

**Characteristics**:
- Defines valid data type and range
- Each attribute is associated with a domain
- Enforces data validity

**Examples**:
```
StudentID domain:    {1, 2, 3, ...} (positive integers)
StudentName domain:  {Any string of length 1-50}
Age domain:          {17, 18, 19, ..., 65} (18 to 65 years)
Email domain:        {Valid email addresses}
```

**Domain in SQL**:
```sql
CREATE DOMAIN PosInt AS INT CHECK (VALUE > 0);
CREATE DOMAIN StudentAge AS INT CHECK (VALUE BETWEEN 17 AND 65);
```

### 5. Degree

**Definition**: Degree is the number of attributes (columns) in a relation.

**Formula**: Degree = Number of Attributes

**Example**:
```
STUDENT (StudentID, StudentName, Email, Age)
Degree = 4

EMPLOYEE (EmpID, Name, Salary, DeptID, JoinDate)
Degree = 5
```

### 6. Cardinality

**Definition**: Cardinality is the number of tuples (rows) in a relation.

**Characteristics**:
- Changes over time as data is added/removed
- Can be 0 (empty relation) to very large numbers
- Dynamic property

**Example**:
```
STUDENT relation currently has:
┌───────────┬──────────────┬──────────────┬──────┐
│ StudentID │ StudentName  │ Email        │ Age  │
├───────────┼──────────────┼──────────────┼──────┤
│ 101       │ Raj Kumar    │ raj@col.edu  │ 20   │
│ 102       │ Priya Singh  │ priya@col.edu│ 19   │
│ 103       │ Amit Patel   │ amit@col.edu │ 21   │
└───────────┴──────────────┴──────────────┴──────┘
Cardinality = 3

After adding more students:
Cardinality = 1000 (might increase)
```

### Terminology Summary Table

| Term | Alternative Name | Definition | Example |
|------|-------------------|-----------|---------|
| **Relation** | Table | 2D structure with rows and columns | STUDENT |
| **Tuple** | Record, Row | Single horizontal entry | (101, 'Raj', 'raj@col.edu', 20) |
| **Attribute** | Field, Column | Single vertical property | StudentName, Age |
| **Domain** | Data type set | Allowed values for attribute | INT, VARCHAR(50) |
| **Degree** | Arity | Number of attributes (columns) | 4 attributes = degree 4 |
| **Cardinality** | Record count | Number of tuples (rows) | 1000 records = cardinality 1000 |

## Integrity Constraints

**Integrity constraints** are rules applied to ensure that only valid, consistent data is stored in the database. They maintain database quality and enforce business rules.

### Types of Integrity Constraints

#### 1. Domain Constraint (Attribute-Level)

**Definition**: Specifies valid values for an attribute.

**Purpose**: Prevents invalid data entry

**Implementation**:
- Data type specification
- CHECK constraint
- Default values

**SQL Example**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT,
    EmployeeName VARCHAR(50),
    Age INT CHECK (Age >= 18 AND Age <= 65),
    Salary DECIMAL(10, 2) CHECK (Salary > 0),
    Status VARCHAR(10) CHECK (Status IN ('Active', 'Inactive'))
);
```

**Violation Example**:
```sql
INSERT INTO EMPLOYEE VALUES (101, 'Raj', 15, 50000); -- FAILS: Age < 18
INSERT INTO EMPLOYEE VALUES (101, 'Raj', 25, -5000); -- FAILS: Salary < 0
```

#### 2. Key Constraint

**Definition**: Ensures that primary key values are unique and not NULL.

**Purpose**: Uniquely identify each tuple

**Types**:
- **Primary Key**: Main identifier
- **Unique Key**: Alternate identifier
- **Candidate Key**: Potential primary key

**SQL Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,  -- Must be unique and not NULL
    Email VARCHAR(100) UNIQUE,   -- Must be unique (can be NULL)
    Phone VARCHAR(10)
);

INSERT INTO STUDENT VALUES (101, 'raj@col.edu', '9876543210');
INSERT INTO STUDENT VALUES (101, 'priya@col.edu', '9876543211'); -- FAILS: Duplicate StudentID

INSERT INTO STUDENT VALUES (102, NULL, '9876543212'); -- OK for Email (NULL allowed in UNIQUE)
INSERT INTO STUDENT VALUES (103, NULL, '9876543213'); -- FAILS: Duplicate NULL in UNIQUE? (DB dependent)
```

**Note**: Some databases allow multiple NULLs in UNIQUE columns, others don't.

#### 3. Entity Integrity Constraint

**Definition**: The primary key of any relation must contain non-NULL values and must be unique.

**Formal Rule**: For each tuple t in relation R:
- **t[PK] ≠ NULL** (No NULL in primary key)
- **No two tuples have same primary key value** (Uniqueness)

**Purpose**: Ensures each entity instance is uniquely identifiable

**SQL Example**:
```sql
CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,      -- Must be NOT NULL and UNIQUE
    CourseName VARCHAR(100) NOT NULL,
    Credits INT
);

INSERT INTO COURSE VALUES (NULL, 'Database', 4);     -- FAILS: NULL primary key
INSERT INTO COURSE VALUES (CS101, 'Database', 4);    -- OK
INSERT INTO COURSE VALUES (CS101, 'Networks', 3);    -- FAILS: Duplicate CourseID
```

#### 4. Referential Integrity Constraint

**Definition**: Ensures that foreign key values in one relation match existing primary key values in another relation.

**Formal Rule**: For each foreign key value in R1:
- Either the value exists as primary key in R2
- Or the value is NULL

**Purpose**: Maintains relationships between related tables

**SQL Example**:
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

INSERT INTO DEPARTMENT VALUES (1, 'IT');
INSERT INTO DEPARTMENT VALUES (2, 'HR');

INSERT INTO EMPLOYEE VALUES (101, 'Raj', 1);     -- OK: DepartmentID=1 exists
INSERT INTO EMPLOYEE VALUES (102, 'Priya', 3);   -- FAILS: DepartmentID=3 doesn't exist
INSERT INTO EMPLOYEE VALUES (103, 'Amit', NULL); -- OK: NULL is allowed in FK
```

**Foreign Key Actions**:
```sql
-- Option 1: Restrict (default)
FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
ON DELETE RESTRICT  -- Cannot delete referenced row
ON UPDATE RESTRICT  -- Cannot update referenced row

-- Option 2: Cascade
ON DELETE CASCADE   -- Delete all dependent rows
ON UPDATE CASCADE   -- Update all dependent rows

-- Option 3: Set NULL
ON DELETE SET NULL  -- Set dependent FK to NULL
ON UPDATE SET NULL

-- Option 4: Set Default
ON DELETE SET DEFAULT  -- Set to default value
ON UPDATE SET DEFAULT
```

**Example with Cascade**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
    ON DELETE CASCADE
);

DELETE FROM DEPARTMENT WHERE DepartmentID = 1;
-- All employees in department 1 are automatically deleted
```

#### 5. Check Constraint

**Definition**: Allows specifying a condition that each row must satisfy.

**Purpose**: Enforce complex business rules

**SQL Example**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    Salary DECIMAL(10, 2),
    HRA DECIMAL(10, 2),
    DA DECIMAL(10, 2),
    CHECK (Salary > 0 AND HRA >= 0 AND DA >= 0),
    CHECK (Salary >= HRA + DA)  -- Salary should be greater than allowances
);
```

#### 6. Unique Constraint

**Definition**: Ensures that attribute values are unique (but allows NULLs).

**Difference from Primary Key**:
- UNIQUE allows multiple NULLs
- PRIMARY KEY allows no NULLs
- Table can have one PRIMARY KEY, multiple UNIQUE constraints

**SQL Example**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    Email VARCHAR(100) UNIQUE NOT NULL,   -- Unique and not null
    Phone VARCHAR(10) UNIQUE,              -- Unique but can be null
    Aadhar VARCHAR(12) UNIQUE NOT NULL
);
```

#### 7. Not Null Constraint

**Definition**: Ensures that an attribute always has a value (never NULL).

**Purpose**: Enforce required fields

**SQL Example**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50) NOT NULL,  -- Must have value
    Email VARCHAR(100),                 -- Can be null
    Salary DECIMAL(10, 2) NOT NULL
);

INSERT INTO EMPLOYEE VALUES (101, NULL, 'raj@company.com', 50000);  -- FAILS
INSERT INTO EMPLOYEE VALUES (101, 'Raj', NULL, 50000);              -- OK
```

## Keys in Relational Model

**Keys** are attributes or combinations of attributes that identify tuples uniquely and establish relationships.

### Super Key

**Definition**: An attribute or set of attributes that uniquely identifies a tuple.

**Characteristics**:
- Uniquely identifies each tuple
- May contain unnecessary attributes
- May contain redundant information

**Example**:
```
STUDENT (StudentID, Email, Phone, Name)

Super Keys:
  1. {StudentID}
  2. {Email}
  3. {Phone}
  4. {StudentID, Name}
  5. {Email, Phone}
  6. {StudentID, Email, Phone, Name}
  
All these can uniquely identify a student
```

### Candidate Key

**Definition**: A super key such that no proper subset of it is a super key (minimal super key).

**Characteristics**:
- Uniquely identifies tuple with minimal attributes
- No proper subset is a super key
- Multiple candidate keys possible for one relation

**Example**:
```
STUDENT (StudentID, Email, Phone, Name)

Candidate Keys:
  1. {StudentID}
  2. {Email}
  3. {Phone}
  
NOT candidate keys:
  - {StudentID, Name}  (StudentID alone is sufficient)
  - {StudentID, Email, Phone, Name}  (has redundant attributes)
```

### Primary Key

**Definition**: A candidate key chosen by database designer to uniquely identify tuples. It's the main identifier for a relation.

**Characteristics**:
- Exactly one primary key per relation
- Chosen from candidate keys
- Cannot be NULL
- Must be unique
- Usually smallest or most frequently used candidate key

**Example**:
```
STUDENT (StudentID, Email, Phone, Name)

Candidate Keys:  {StudentID}, {Email}, {Phone}
Primary Key:     {StudentID}  ← Designer's choice

Alternative would be valid but StudentID is most efficient
```

### Alternate Key (Secondary Key)

**Definition**: A candidate key that is not chosen as the primary key.

**Characteristics**:
- One or more alternate keys per relation
- Uniquely identifies tuples
- Can be NULL (depending on implementation)
- Used in UNIQUE constraints

**Example**:
```
STUDENT (StudentID, Email, Phone, Name)

Primary Key:      StudentID
Alternate Keys:   Email, Phone

SQL implementation:
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    Email VARCHAR(100) UNIQUE,   -- Alternate key 1
    Phone VARCHAR(10) UNIQUE,    -- Alternate key 2
    Name VARCHAR(50)
);
```

### Composite Key (Compound Key)

**Definition**: A primary key made up of two or more attributes.

**Characteristics**:
- Used when no single attribute uniquely identifies tuple
- All attributes together form uniqueness
- Common in junction/bridge tables

**Example**:
```
ENROLLMENT (StudentID, CourseID, Semester, Grade)

Single attributes not sufficient:
  - StudentID alone: Student in multiple courses
  - CourseID alone: Course has multiple students

Composite Primary Key: (StudentID, CourseID, Semester)
  - Uniquely identifies one student's enrollment in one course in one semester
```

**SQL Example**:
```sql
CREATE TABLE ENROLLMENT (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(10),
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID, Semester),
    FOREIGN KEY (StudentID) REFERENCES STUDENT(StudentID),
    FOREIGN KEY (CourseID) REFERENCES COURSE(CourseID)
);
```

### Foreign Key

**Definition**: An attribute/set of attributes in one relation that refers to primary key in same or different relation.

**Characteristics**:
- Links two relations
- Creates relationships
- Enforces referential integrity
- Can be NULL

**Example**:
```
DEPARTMENT (DepartmentID, DepartmentName)
             ↑ Primary Key

EMPLOYEE (EmployeeID, Name, DepartmentID)
                             ↑ Foreign Key (references DEPARTMENT.DepartmentID)
```

**SQL Example**:
```sql
CREATE TABLE EMPLOYEE (
    EmployeeID INT PRIMARY KEY,
    EmployeeName VARCHAR(50),
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES DEPARTMENT(DepartmentID)
);
```

### Key Relationship Diagram

```
SUPER KEY
   │
   ├─── Contains all attributes that uniquely identify
   │
   ▼
CANDIDATE KEY (Minimal Super Keys)
   │
   ├─── One chosen as PRIMARY KEY
   │
   ├─── Others become ALTERNATE KEYS
   │
COMPOSITE KEY (if multi-attribute)
   │
FOREIGN KEY (references other relation's PK)
```

## Relational Query Languages

Query languages are used to retrieve and manipulate data in the database.

### Categorization of Query Languages

```
Query Languages
    │
    ├─────────────────────────────┬──────────────────────────
    │                             │
Procedural                    Non-Procedural
(Tell HOW)                   (Tell WHAT)
    │                             │
    ├─ Relational Algebra        ├─ Relational Calculus
    │                             │  ├─ Tuple Relational Calculus
    │                             │  └─ Domain Relational Calculus
    │                             │
    │                             ├─ SQL (de facto standard)
    │                             │
    │                             └─ Query by Example (QBE)
```

### Relational Algebra (Procedural)

**Definition**: A procedural language that specifies sequence of operations to retrieve data.

**Characteristics**:
- Specifies HOW to get data
- Step-by-step operations
- Operations on entire relations
- Mathematical foundation

**Key Operations**:
1. Selection (Filter rows)
2. Projection (Select columns)
3. Union (Combine sets)
4. Intersection (Common elements)
5. Difference (Set difference)
6. Cartesian Product (All combinations)
7. Join (Combine related rows)

**Example**:
```
Find names of employees earning more than 50,000 in IT department

Algebra (Step-by-step):
σ (Salary > 50000) (π (EmployeeName, Salary) (EMPLOYEE))

English (What it means):
1. Filter EMPLOYEE for salary > 50,000
2. Select only EmployeeName and Salary columns
```

### Relational Calculus (Non-Procedural)

**Definition**: A declarative language where user specifies WHAT data to retrieve without specifying HOW.

**Characteristics**:
- Specifies WHAT, not HOW
- Based on predicate logic
- More intuitive for users
- Two types: TRC and DRC

**Example**:
```
Find names of employees earning more than 50,000

Calculus (What we want):
{ t.EmployeeName | t ∈ EMPLOYEE ∧ t.Salary > 50000 }

User doesn't specify steps, just the criteria
```

### SQL (Structured Query Language)

**Definition**: Industry-standard language combining procedural and non-procedural features.

**Characteristics**:
- Based on both relational algebra and calculus
- Declarative (WHAT, not HOW)
- Supported by all major DBMS
- English-like syntax

**Relationship to Algebra and Calculus**:
```
Relational Algebra + Relational Calculus → SQL

SQL SELECT FROM WHERE
  represents the logical query intent
  but DBMS decides HOW to execute it
```

## Example Relational Schema

```
Database: COLLEGE

┌─ STUDENT ─────────────────────────┐
│ StudentID (PK)                    │
│ StudentName                       │
│ Email                             │
│ DepartmentID (FK → DEPARTMENT)    │
└───────────────────────────────────┘

┌─ COURSE ──────────────────────────┐
│ CourseID (PK)                     │
│ CourseName                        │
│ Credits                           │
│ DepartmentID (FK → DEPARTMENT)    │
└───────────────────────────────────┘

┌─ ENROLLMENT ──────────────────────┐
│ StudentID (FK → STUDENT)          │
│ CourseID (FK → COURSE)            │
│ Semester                          │
│ Grade (PK: StudentID+CourseID+Sem)│
└───────────────────────────────────┘

┌─ DEPARTMENT ──────────────────────┐
│ DepartmentID (PK)                 │
│ DepartmentName                    │
│ Building                          │
└───────────────────────────────────┘
```

## Advantages of Relational Model

1. **Simple and Intuitive**: Tables are familiar data structures
2. **Strong Mathematical Foundation**: Based on set theory and predicate logic
3. **Data Independence**: Logical independence from physical storage
4. **Query Optimization**: DBMS can optimize query execution
5. **Strong Integrity**: Built-in constraint mechanisms
6. **Flexibility**: Can model most business scenarios
7. **Standardization**: SQL is industry standard
8. **Scalability**: Handles large datasets efficiently

## Exam Notes

- **Define Relation**: Start with "Relation is a two-dimensional table..."
- **Terminology Table**: Use table format for degree, cardinality, domain, etc.
- **Integrity Constraints**: Write at least 4-5 with SQL examples
- **Keys**: Explain super key, candidate key, primary key with examples
- **Comparative**: Show differences between keys clearly
- **SQL Examples**: Include CREATE TABLE statements for key concepts
- **Relational Algebra vs Calculus**: Explain procedural vs non-procedural difference
- **Schema Example**: Draw complete schema diagram with relationships
