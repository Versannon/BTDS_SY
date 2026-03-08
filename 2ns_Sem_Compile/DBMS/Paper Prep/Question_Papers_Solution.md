# DBMS QUESTION PAPER SETS - WITH ANSWERS

---

# Question Paper Set 1

## Q1 (5 Marks) - Explain the three levels of abstraction in DBMS with diagram.

### Answer:

The **three levels of abstraction in DBMS** hide the complexity of database systems by organizing data representation at different levels:

#### Diagram:

```
┌──────────────────────────────────────────────┐
│        VIEW LEVEL (External Level)           │
│  - User-specific views                       │
│  - Admin View, Employee View, Manager View   │
│  - Different users see different data        │
│  - Most abstract                             │
└──────────────────────────────────────────────┘
           ↕ LOGICAL DATA INDEPENDENCE
┌──────────────────────────────────────────────┐
│     LOGICAL LEVEL (Conceptual Level)         │
│  - Describes WHAT data is stored             │
│  - Table structures and relationships        │
│  - Integrity constraints                     │
│  - Middle level                              │
└──────────────────────────────────────────────┘
           ↕ PHYSICAL DATA INDEPENDENCE
┌──────────────────────────────────────────────┐
│      PHYSICAL LEVEL (Internal Level)         │
│  - Describes HOW data is stored              │
│  - File organization, indexing               │
│  - Storage structures                        │
│  - Most concrete                             │
└──────────────────────────────────────────────┘
```

#### Detailed Explanation:

**1. View Level (External Layer)**
- Presented to end users
- Multiple views for different users
- Example: Admin sees salaries; Employee doesn't
- Provides data privacy and security
- User doesn't know about physical storage

**2. Logical Level (Conceptual Layer)**
- Describes overall database structure
- Defines tables, columns, relationships, constraints
- Example: Employee table with columns (ID, Name, Salary, DeptID)
- Independent of physical storage details
- Multiple views map to one logical schema

**3. Physical Level (Internal Layer)**
- How data actually stored in memory/disk
- File block management
- Index structures (B-tree, hash tables)
- Buffer management
- Users and programmers don't interact directly

#### Advantages:
- **Hiding complexity:** Users work with simplified views
- **Data independence:** Changes at physical level don't affect applications
- **Security:** Sensitive information hidden at view level
- **Flexibility:** Multiple representations of same data

---

## Q2 (5 Marks) - Explain File System vs DBMS.

### Answer:

#### Comparative Table:

| **Aspect** | **File System** | **DBMS** |
|-----------|------------------|----------|
| **Data Organization** | Data in separate files | Data in structured tables/relations |
| **Data Redundancy** | High (same data in multiple files) | Controlled & Minimized |
| **Data Consistency** | Difficult to maintain | Automatically maintained |
| **Security** | Weak (file permissions only) | Strong (encryption, user roles) |
| **Data Sharing** | Difficult & limited sharing | Easy & standardized sharing |
| **Backup & Recovery** | Manual & time-consuming | Automatic & efficient |
| **Concurrency** | Not supported or limited | Fully supported |
| **Query Capability** | Limited to file operations | Powerful SQL queries |
| **Transaction Support** | Not available | ACID properties guaranteed |
| **Data Integrity** | No enforcement | Constraints enforced |
| **Memory Usage** | Less memory overhead | More memory needed |

#### Detailed Explanation:

**File System Problems:**

1. **Data Redundancy**
   - Employee data stored in both HR and Payroll files
   - Wastes storage space
   - Example: Employee address in 3 places

2. **Data Inconsistency**
   - If address changes in one file but not others
   - Inconsistent information available
   - Difficult to maintain accuracy

3. **Poor Security**
   - Only file-level access control
   - No field-level security
   - Anyone with file access sees all data

4. **Difficult Data Sharing**
   - Different file formats incompatible
   - Complex to share information between programs
   - Manual data extraction required

5. **Lack of Concurrency Control**
   - File locks prevent simultaneous access
   - One user locks file, others must wait
   - Reduces efficiency

**Why DBMS is Better:**

- **Single source of truth:** One database for all data
- **Centralized management:** DBA maintains integrity
- **Efficient queries:** SQL allows complex data retrieval
- **Transaction management:** ACID guarantees consistency
- **Built-in security:** User authentication and authorization
- **Multiple simultaneous users:** Concurrency control mechanism

---

## Q3 (5 Marks) - Explain integrity constraints in relational model.

### Answer:

**Integrity constraints** are rules that ensure data accuracy, consistency, and reliability in a relational database.

#### Types of Integrity Constraints:

### 1. Domain Constraint

- **Definition:** Values in each column must belong to specified domain
- **Purpose:** Prevent invalid data entry
- **Examples:**
  ```sql
  Age INT CHECK (Age >= 18 AND Age <= 65);
  Email VARCHAR(50) -- must be email format
  Salary DECIMAL(10,2) CHECK (Salary >= 0);
  ```
- **Violation:** Entering age = 200 or negative salary

### 2. Key Constraint

- **Definition:** Keys uniquely identify records
- **Types:**
  - **Primary Key:** Unique + Not Null
  - **Candidate Key:** Unique, can be null
  - **Super Key:** Any uniquely identifying set
  - **Composite Key:** Multiple attributes as key
  ```sql
  PRIMARY KEY (EmployeeID)
  UNIQUE (Email)
  PRIMARY KEY (StudentID, CourseID)  -- Composite
  ```
- **Violation:** Duplicate primary key values

### 3. Entity Integrity Constraint

- **Definition:** Primary key cannot be NULL
- **Purpose:** Ensure every record is uniquely identifiable
- **Example:**
  ```sql
  CREATE TABLE Employee (
      EmployeeID INT PRIMARY KEY NOT NULL,
      Name VARCHAR(50)
  );
  
  -- INVALID
  INSERT INTO Employee VALUES (NULL, 'John');  -- Violates
  ```
- **Violation:** NULL in primary key column

### 4. Referential Integrity Constraint

- **Definition:** Foreign key must reference existing primary key
- **Purpose:** Maintain relationships between tables
- **Example:**
  ```sql
  CREATE TABLE Department (
      DeptID INT PRIMARY KEY
  );
  
  CREATE TABLE Employee (
      EmployeeID INT PRIMARY KEY,
      DeptID INT,
      FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
  );
  
  -- VALID: DeptID D01 exists in Department
  INSERT INTO Employee VALUES (101, 'John', D01);
  
  -- INVALID: DeptID D99 doesn't exist
  INSERT INTO Employee VALUES (102, 'Jane', D99);
  ```
- **Violation:** Foreign key references non-existent primary key

#### Importance:
- **Data Accuracy:** Prevents invalid data
- **Consistency:** Ensures relationships valid
- **Reliability:** Maintains database integrity
- **ACID Compliance:** Supports transaction consistency

---

## Q4 (5 Marks) - Explain relational algebra operations.

### Answer:

**Relational Algebra** is a procedural query language with mathematical operations on relations.

#### Fundamental Operations:

### 1. Selection (σ - Sigma)

- **Definition:** Select rows (tuples) satisfying a condition
- **Notation:** σ condition (Relation)
- **Example:** σ Salary > 50000 (Employee)
- **SQL Equivalent:** SELECT * FROM Employee WHERE Salary > 50000;
- **Result:** Horizontal subset of relation

### 2. Projection (π - Pi)

- **Definition:** Select specific columns (attributes)
- **Notation:** π column1,column2 (Relation)
- **Example:** π Name,Salary (Employee)
- **SQL Equivalent:** SELECT Name, Salary FROM Employee;
- **Result:** Vertical subset of relation

### 3. Union (∪)

- **Definition:** Combine rows from two relations
- **Notation:** R1 ∪ R2
- **Condition:** Both relations must have same schema
- **Example:** 
  ```
  σ Department='Sales' (Employee) ∪ σ Department='Marketing' (Employee)
  ```
- **Result:** All unique rows from both relations

### 4. Intersection (∩)

- **Definition:** Find common rows in two relations
- **Notation:** R1 ∩ R2
- **Condition:** Same schema required
- **Example:** Find employees who speak both English and Spanish
- **Result:** Only rows present in both relations

### 5. Difference (−)

- **Definition:** Rows in first relation but not in second
- **Notation:** R1 − R2
- **Example:** All employees minus employees in Sales department
- **Result:** Tuples in R1 that are not in R2

### 6. Cartesian Product (×)

- **Definition:** All possible combinations of rows from two relations
- **Notation:** R1 × R2
- **If R1 has m rows and R2 has n rows:** Result has m×n rows
- **Example:** 
  ```
  Employee × Department creates all possible employee-department pairs
  ```
- **Important:** Usually combined with selection

### 7. Join (⋈)

**Natural Join:**
- Combine relations on common attributes
- Notation: R1 ⋈ R2
- Common attributes appear only once
- Example:
  ```
  Employee ⋈ Department
  (Joins on DepartmentID)
  ```

**Theta Join (θ):**
- Join with any condition
- Notation: R1 ⋈θ R2
- Example: σ condition (R1 × R2)

#### Example Query:

Find names and salaries of Sales employees with age > 25:

```
π Name, Salary (σ (Department='Sales' ∧ Age>25) (Employee))
```

#### Operations Classification:

| Type | Operations |
|------|-----------|
| **Unary** | Selection, Projection |
| **Binary** | Union, Intersection, Difference, Cartesian Product, Join |

---

## Q5 (5 Marks) - Explain ER model with entities, attributes and relationships.

### Answer:

**Entity Relationship (ER) Model** is a conceptual database design model representing real-world data.

### 1. Entities

- **Definition:** Objects or things represented in database
- **Real-world examples:** Student, Employee, Course, Department
- **Database representation:** Tables
- **Instance:** One entity = one row in table

**Example - Student Entity:**
```
StudentID | Name     | Email          | Department
----------|----------|----------------|----------
101       | John     | john@mail.com  | CSE
102       | Sarah    | sarah@mail.com | ECE
```

### 2. Attributes

**Definition:** Properties or characteristics of entities

#### Types of Attributes:

| Type | Example | Description |
|------|---------|-------------|
| **Simple** | Name, Age | Cannot be divided |
| **Composite** | Address (street, city, zip) | Can be divided |
| **Derived** | Age (from DOB) | Calculated value |
| **Multivalued** | Phone (multiple numbers) | Multiple values |
| **Key** | StudentID | Uniquely identifies |

**Example - Student Attributes:**
```
Student Entity:
- Simple: Name, Email
- Composite: Address (Street, City, ZipCode)
- Derived: Age (from DateOfBirth)
- Multivalued: PhoneNumbers
- Key: StudentID
```

### 3. Relationships

**Definition:** Association between entities

#### Types by Cardinality:

**1. One-to-One (1:1)**
- One entity related to exactly one entity
- Example: Person ↔ PassportNumber
```
      Person (1 : 1) Passport
A person has one passport, one passport for one person
```

**2. One-to-Many (1:N)**
- One entity related to many entities
- Example: Department → Employees
```
        Department (1 : N) Employee
One department has many employees
```

**3. Many-to-One (M:1)**
- Many entities related to one entity
- Example: Employees ← Department
```
        Employee (M : 1) Department
Many employees work in one department
```

**4. Many-to-Many (M:N)**
- Many entities related to many entities
- Example: Student ↔ Course
```
        Student (M : N) Course
Many students enroll in many courses
```

### ER Model Example: College Database

```
Entities: Student, Course, Instructor, Department

Attributes:
- Student: StudentID*, Name, Email, DateOfBirth
- Course: CourseID*, CourseName, Credits
- Instructor: InstructorID*, Name, Qualification
- Department: DeptID*, DeptName

Relationships:
- Student -- Enrolls -- Course (M:N)
- Course -- TaughtBy -- Instructor (M:1)
- Instructor -- WorksIn -- Department (M:1)
- Student -- BelongsTo -- Department (M:1)
```

### ER Diagram Symbols:

```
┌─────────────┐         ┌──────────────┐
│   Student   │  ----   │    Course    │
├─────────────┤  Enroll  ├──────────────┤
│ StudentID*  │   (M:N)  │ CourseID*    │
│ Name        │---------│ CourseName   │
│ Email       │         │ Credits      │
└─────────────┘         └──────────────┘

Symbols:
- Rectangle = Entity
- Oval = Attribute
- Diamond = Relationship
- * = Key attribute
- Line = Relationship connection
```

### Converting ER Model to Relational Schema:

```
ER Entities → Tables:

Student Table:
StudentID | Name     | Email
----------|----------|--------
101       | John     | john@mail.com

Course Table:
CourseID | CourseName        | Credits
---------|-------------------|--------
C01      | Database Systems  | 3
C02      | Web Development   | 4

Enrollment Table (for M:N relationship):
StudentID | CourseID | Grade
-----------|----------|-------
101        | C01      | A
101        | C02      | B
```

---

# Question Paper Set 2

## Q1 (5 Marks) - Explain structure of DBMS.

### Answer:

DBMS has three main components that work together:

```
┌────────────────────────────────────────────┐
│         QUERY PROCESSOR                     │
├────────────────────────────────────────────┤
│  - DDL Interpreter                    │
│  - DML Compiler                      │
│  - Query Optimizer                   │
└────────────────────────────────────────────┘
                    ↕
┌────────────────────────────────────────────┐
│      STORAGE MANAGER                        │
├────────────────────────────────────────────┤
│  - Authorization Manager              │
│  - Integrity Manager                  │
│  - Transaction Manager                │
│  - File Manager                       │
│  - Buffer Manager                     │
└────────────────────────────────────────────┘
                    ↕
┌────────────────────────────────────────────┐
│         DATABASE                            │
│    (Stored data on disk)                   │
└────────────────────────────────────────────┘
```

### Component 1: Query Processor

**Function:** Parse and execute user queries

**Sub-components:**

1. **DDL Interpreter**
   - Processes Data Definition Language commands
   - Examples: CREATE, ALTER, DROP
   - Updates data dictionary
   - Creates table structures

2. **DML Compiler**
   - Processes Data Manipulation Language commands
   - Examples: SELECT, INSERT, UPDATE, DELETE
   - Translates queries to lower-level instructions
   - Generates intermediate code

3. **Query Optimizer**
   - Determines most efficient execution plan
   - Analyzes multiple strategies
   - Chooses path with lowest cost
   - Improves query performance

### Component 2: Storage Manager

**Function:** Manage physical data storage and retrieval

**Sub-components:**

1. **Authorization Manager**
   - Manages user access control
   - Enforces security permissions
   - Validates user credentials
   - Restricts data access

2. **Integrity Manager**
   - Enforces integrity constraints
   - Validates data before storage
   - Ensures consistency
   - Prevents invalid operations

3. **Transaction Manager**
   - Manages transactions
   - Ensures ACID properties
   - Handles commit/rollback
   - Maintains consistency

4. **File Manager**
   - Manages database files
   - Allocates storage space
   - Handles file organization
   - Manages free space

5. **Buffer Manager**
   - Manages main memory buffer pool
   - Reduces disk I/O operations
   - Caches frequently used data
   - Improves performance

### Component 3: Database

- Physical storage of all data
- Stored on disk/persistent storage
- Managed by storage manager
- Organized in files and blocks

---

## Q2 (5 Marks) - Explain data independence and its types.

### Answer:

**Data Independence** is the ability to modify database schema without affecting application programs and user views.

### Types of Data Independence:

### 1. Physical Data Independence

- **Definition:** Changes at physical level do NOT affect logical level
- **Most important and flexible type**
- **Physical level changes:**
  - File organization (sequential, indexed, hashed)
  - Index structures (B-tree, hash table)
  - Storage location (new disk, different partition)
  - Compression techniques
  - Caching strategies

**Example:**

```
Before: Employees stored in sequential file with no index
After: Same data stored in indexed B-tree structure

Impact:
- Query performance improves
- Logical schema unchanged
- Applications unaffected
- Users see same data
```

**Benefits:**
- DBA can modify storage without changing applications
- Improves performance without code changes
- Allows data migration between storage devices

### 2. Logical Data Independence

- **Definition:** Changes in logical schema do NOT affect user views
- **Less flexible than physical independence**
- **Logical level changes:**
  - Adding new column to table
  - Removing unused column
  - Modifying attribute domain
  - Creating new relationships

**Example:**

```
Before: Employee table (EmpID, Name, Department)
After: Employee table (EmpID, Name, Department, Salary, Skills)

Added Columns: Salary, Skills

Impact:
- New data stored
- Existing views still work
- Old programs continue running
- Backward compatibility maintained
```

**Benefits:**
- Schema evolution without breaking applications
- Supports database growth
- Maintains view stability

### Comparison:

| Feature | Physical Independence | Logical Independence |
|---------|----------------------|----------------------|
| **Level** | Internal → Logical | Logical → External |
| **Flexibility** | More flexible | Less flexible |
| **Change type** | Storage/indexing | Structure/schema |
| **User impact** | None | Minimal |
| **Application impact** | None | Potentially affected |

### Why Data Independence Matters:

1. **Reduced Development Cost**
   - No need to recompile applications
   - Faster schema modifications

2. **Improved Maintenance**
   - DBA can tune storage independently
   - Schema evolution easier

3. **Better Performance**
   - Can optimize storage without affecting users
   - Flexible indexing strategies

4. **Stability**
   - Applications more stable
   - Views protected from changes

---

## Q3 (5 Marks) - Explain relational model terminology.

### Answer:

**Relational Model Terminology** provides standard vocabulary for relational databases.

### Key Terms:

#### 1. Relation

- **Definition:** A table organized in rows and columns
- **Example:** Employee table with employee records
- **Characteristics:** 
  - Flat structure (no nested tables)
  - Unordered rows and columns
  - Unique column names

```
Employee Table (Relation):
EmpID | Name   | Salary  | Dept
------|--------|---------|-----
101   | John   | 50000   | IT
102   | Sarah  | 60000   | HR
```

#### 2. Tuple

- **Definition:** A row in a relation (single record)
- **Example:** One employee record
- **Characteristics:**
  - Represents one instance
  - Contains full record information
  - Distinguished by primary key

```
Tuple 1: (101, John, 50000, IT)
Tuple 2: (102, Sarah, 60000, HR)
```

#### 3. Attribute

- **Definition:** A column in a relation (field/property)
- **Example:** Name, Salary, Department
- **Characteristics:**
  - Represents a property
  - Has specific domain
  - Atomic value (single value)

```
Attributes: EmpID, Name, Salary, Dept
```

#### 4. Domain

- **Definition:** Set of all possible values for an attribute
- **Examples:**
  - Age domain: 18-65
  - Salary domain: Positive numbers
  - Department domain: {IT, HR, Finance, Sales}
- **Importance:** Ensures data validity

#### 5. Degree

- **Definition:** Number of attributes (columns) in a relation
- **Example:** Employee table has degree 4 (EmpID, Name, Salary, Dept)
- **Calculation:** Count all columns

```
Employee Table:
Degree = 4 (EmpID, Name, Salary, Dept)
```

#### 6. Cardinality

- **Definition:** Number of tuples (rows) in a relation
- **Example:** Employee table has 100 employees = cardinality 100
- **Changes:** Increases/decreases with insertions/deletions

```
Employee Table:
Cardinality = Number of employee records
If 100 employees → Cardinality = 100
```

### Relationship Cardinality:

Describes relationship between entities:
- **1:1** (One-to-One)
- **1:N** (One-to-Many)
- **M:N** (Many-to-Many)

### Summary Table:

| Term | Analogy | Definition |
|------|---------|-----------|
| **Relation** | Table | Set of tuples |
| **Tuple** | Row/Record | Single instance |
| **Attribute** | Column/Field | Single property |
| **Domain** | Data type | Valid values |
| **Degree** | Width | Number of columns |
| **Cardinality** | Height | Number of rows |

---

## Q4 (5 Marks) - Explain views in DBMS with advantages.

### Answer:

A **View** is a virtual table created from a query result that presents a logical view of data.

### Characteristics:

- Not physically stored (virtual)
- Dynamically created when accessed
- Based on one or more tables
- Appears like regular table to users
- Result of stored query

### Creating a View:

```sql
CREATE VIEW emp_sales AS
SELECT EmployeeID, Name, Salary, Department
FROM Employees
WHERE Department = 'Sales';

-- Access view
SELECT * FROM emp_sales;
```

### Advantages of Views:

#### 1. **Security**

- Hide sensitive information
- Restrict column access
- Control row access
- Enforce data protection

**Example:**
```sql
-- Original table with sensitive data
CREATE TABLE Employee (
    EmpID INT,
    Name VARCHAR(50),
    Salary INT,           -- Sensitive
    SSN VARCHAR(11),      -- Sensitive
    Department VARCHAR(30)
);

-- Secure view (hides salary and SSN)
CREATE VIEW emp_public AS
SELECT EmpID, Name, Department
FROM Employee;

-- Employee can see only public information
SELECT * FROM emp_public;  -- Salary and SSN hidden
```

#### 2. **Simplifies Queries**

- Pre-write complex queries
- Avoid repetitive code
- Reuse common queries

**Example:**
```sql
-- Complex query
SELECT e.Name, e.Salary, d.DepartmentName, e.YearsExperience
FROM Employee e
INNER JOIN Department d ON e.DeptID = d.DeptID
WHERE e.DeptID IN (SELECT DeptID FROM Department WHERE Budget > 100000)
ORDER BY e.Salary DESC;

-- View simplifies this
CREATE VIEW high_budget_employees AS
SELECT e.Name, e.Salary, d.DepartmentName, e.YearsExperience
FROM Employee e
INNER JOIN Department d ON e.DeptID = d.DeptID
WHERE e.DeptID IN (SELECT DeptID FROM Department WHERE Budget > 100000);

-- Easy access
SELECT * FROM high_budget_employees WHERE Salary > 50000;
```

#### 3. **Data Abstraction**

- Hide database complexity
- Show only relevant data
- Keep implementation details hidden
- Independence from actual structure

**Example:**
```sql
-- User only knows this simple interface
SELECT * FROM sales_summary;

-- Without knowing complex underlying joins
```

#### 4. **Logical Data Independence**

- Changes in physical schema less impactful
- Modify underlying tables without affecting views
- Applications remain unaffected

**Example:**
```sql
-- Original table
CREATE TABLE Employee (EmpID INT, Name VARCHAR(50), Dept VARCHAR(30));

-- Create view
CREATE VIEW emp_names AS SELECT Name FROM Employee;

-- Later, add columns to Employee (Address, Salary)
ALTER TABLE Employee ADD Address VARCHAR(100), Salary INT;

-- View still works perfectly
SELECT * FROM emp_names;  -- Still returns names only
```

#### 5. **Reduces Redundancy**

- Write complex query once
- Use in multiple applications
- Maintain single version
- Easier updates

### Types of Views:

#### Simple View
- Based on single table
- No calculations
- Can update underlying data through view

```sql
CREATE VIEW it_employees AS
SELECT * FROM Employee WHERE Department = 'IT';
```

#### Complex View
- Based on multiple tables (joins)
- May contain aggregations
- Not always updatable

```sql
CREATE VIEW dept_salaries AS
SELECT Department, AVG(Salary) AS AvgSalary, COUNT(*) AS EmpCount
FROM Employee
GROUP BY Department;
```

### Deleting Views:

```sql
DROP VIEW emp_sales;
DROP VIEW IF EXISTS emp_sales;  -- Safe drop
```

---

## Q5 (5 Marks) - Explain relational calculus (TRC and DRC).

### Answer:

**Relational Calculus** is a non-procedural query language based on mathematical logic.

### Characteristics (Both TRC and DRC):

- **Non-procedural:** Specifies WHAT to retrieve, not HOW
- **Logic-based:** Uses predicates and quantifiers
- **Formal foundation:** Mathematical basis for SQL
- **Declarative:** States conditions, not procedures

---

### 1. Tuple Relational Calculus (TRC)

**Definition:** Query language where variables represent tuples (rows)

#### Basic Form:

```
{ t | P(t) }
```

- **t:** Tuple variable
- **P(t):** Predicate (condition) on tuple t

#### Examples:

**Example 1: Find all employees with age > 30**

```
{ e | Employee(e) ∧ e.Age > 30 }
```

- **Meaning:** Find all tuples `e` in Employee relation where age > 30
- **SQL Equivalent:** SELECT * FROM Employee WHERE Age > 30;

**Example 2: Find names of Sales employees**

```
{ e.Name | Employee(e) ∧ e.Department = 'Sales' }
```

- **Meaning:** Project Name of employees where Dept = Sales
- **SQL Equivalent:** SELECT Name FROM Employee WHERE Department = 'Sales';

**Example 3: Find employees with salary > 60000**

```
{ e | Employee(e) ∧ e.Salary > 60000 }
```

#### Using Quantifiers:

**Existential Quantifier (∃) - "There exists"**

```
{ e | Employee(e) ∧ ∃ s (Salary(s) ∧ s.EmpID = e.EmpID ∧ s.Amount > 50000) }
```

- **Meaning:** Find employees who have a salary record > 50000

**Universal Quantifier (∀) - "For all"**

```
{ e | Employee(e) ∧ ∀ p (Project(p) → WorksOn(e, p)) }
```

- **Meaning:** Find employees who work on all projects

---

### 2. Domain Relational Calculus (DRC)

**Definition:** Query language where variables represent attribute values (domains)

#### Basic Form:

```
{ x1, x2, ... | P(x1, x2, ...) }
```

- **x1, x2, ...:** Domain variables (individual values)
- **P(...):** Predicate on domain variables

#### Examples:

**Example 1: Find employee names where age > 30**

```
{ Name | ∃ ID, Age (Employee(ID, Name, Age) ∧ Age > 30) }
```

- **Meaning:** Find Name values from Employee where Age > 30
- **SQL Equivalent:** SELECT Name FROM Employee WHERE Age > 30;

**Example 2: Find employee names and departments**

```
{ Name, DeptName | ∃ ID, Dept (Employee(ID, Name, Dept) ∧ Department(Dept, DeptName)) }
```

- **Meaning:** Find Name and DeptName from joined relations

**Example 3: Find all employees in IT department**

```
{ ID, Name | Employee(ID, Name, 'IT') }
```

- **Meaning:** Find ID and Name where Dept = 'IT'

#### Using Quantifiers:

**Existential Quantifier:**

```
{ Name, Salary | ∃ ID, Dept (Employee(ID, Name, Dept, Salary) ∧ Dept = 'IT') }
```

---

### Comparison: TRC vs DRC

| Feature | TRC | DRC |
|---------|-----|-----|
| **Variables** | Tuple variables (whole rows) | Domain variables (individual values) |
| **Granularity** | Entire tuples | Single attributes |
| **Intuition** | More intuitive | Less intuitive |
| **Expression** | Variable.Attribute | Separate variable |
| **Complexity** | Simpler syntax | More variables needed |
| **SQL Basis** | Closer to SELECT query | More translation needed |
| **Example** | e.Name | Name (separate variable) |

### Detailed Comparison Example:

**Query: Find names of employees with salary > 50000**

**TRC:**
```
{ e.Name | Employee(e) ∧ e.Salary > 50000 }
```

**DRC:**
```
{ Name | ∃ ID, Dept (Employee(ID, Name, Dept, Salary) ∧ Salary > 50000) }
```

### Safe Queries:

Both TRC and DRC must be "safe":
- Should not produce infinite result sets
- Should only reference existing domains
- Should have finite answer

### Importance:

- **Theoretical foundation** for SQL
- **Formal specification** of queries
- **Basis for query optimization**
- **Academic understanding** of database queries

---

# Question Paper Set 3

## Q1 (5 Marks) - Explain database design process using ER model.

### Answer:

**Database design process** converts real-world requirements into structured database.

### Steps in Database Design using ER Model:

#### Step 1: Identify Entities

**Definition:** Determine major objects/concepts to store

**Questions to ask:**
- What real-world objects are important?
- What things do we need to track?
- What entities appear in requirements?

**Example - Library System:**
- Student
- Book
- Librarian
- Loan

#### Step 2: Identify Attributes

**Definition:** Determine properties of each entity

**For each entity, list:**
- What information do we need?
- What properties describe this entity?
- What characteristics are important?

**Example - Student Entity:**
- StudentID (unique identifier)
- Name
- Email
- DateOfBirth
- Phone
- Address

#### Step 3: Identify Relationships

**Definition:** Determine how entities connect

**For each pair of entities, determine:**
- Do they relate?
- What is the relationship?
- What is the cardinality (1:1, 1:N, M:N)?

**Example - Library System Relationships:**
- Student -- Borrows -- Book (M:N)
- Librarian -- Processes -- Loan (1:N)
- Student -- BelongsTo -- Department (M:1)

#### Step 4: Draw ER Diagram

**Create visual representation showing:**
- All entities as rectangles
- All attributes as ovals
- All relationships as diamonds
- Cardinality labels

**Example ER Diagram:**

```
┌──────────────┐         ┌──────────────┐
│   Student    │         │    Book      │
├──────────────┤  ──●    ├──────────────┤
│ StudentID*   │ Borrows │ BookID*      │
│ Name         │  (M:N)  │ Title        │
│ Email        │────●    │ Author       │
│ Phone        │         │ ISBN         │
└──────────────┘         └──────────────┘
      │                          │
      │ BelongsTo (M:1)          │
      │                          │
      └──────────────┬───────────┘
                     │
              ┌──────────────┐
              │  Department  │
              ├──────────────┤
              │ DeptID*      │
              │ DeptName     │
              │ Location     │
              └──────────────┘
```

#### Step 5: Convert ER Diagram to Tables

**For each entity:**
- Create table
- Attributes become columns
- Primary key specified
- Foreign keys for relationships

**SQL Implementation:**

```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,
    Phone VARCHAR(15),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

CREATE TABLE Book (
    BookID INT PRIMARY KEY,
    Title VARCHAR(100),
    Author VARCHAR(50),
    ISBN VARCHAR(20) UNIQUE,
    PublicationYear INT
);

CREATE TABLE Loan (
    LoanID INT PRIMARY KEY,
    StudentID INT,
    BookID INT,
    LoanDate DATE,
    ReturnDate DATE,
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (BookID) REFERENCES Book(BookID)
);

CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50),
    Location VARCHAR(50)
);
```

### Key Points:

- **Identify entities first:** Understand core objects
- **Define attributes carefully:** Include all necessary properties
- **Determine relationships:** Understand how entities connect
- **Validate design:** Check for completeness and redundancy
- **Normalize if needed:** Remove anomalies

### Benefits:

- **Clear structure:** Easy to understand database
- **Reduced redundancy:** No data duplication
- **Data integrity:** Relationships maintained
- **Scalability:** Easy to add new entities

---

## Q2 (5 Marks) - Explain types of keys in relational model.

### Answer:

**Keys** are attributes or combinations that uniquely identify tuples in a relation.

### Types of Keys:

#### 1. Super Key

**Definition:** Any set of attributes that uniquely identifies a tuple

**Characteristics:**
- Can have redundant attributes
- One or more attributes
- Uniquely identifies records

**Example - Student Table:**
```
Attributes: StudentID, Name, Email, Phone, RollNo

Super Keys:
1. {StudentID}
2. {Email}
3. {RollNo}
4. {StudentID, Name}
5. {Email, Phone}
6. {StudentID, Name, Email, Phone, RollNo}
```

#### 2. Candidate Key

**Definition:** Minimal super key (no redundant attributes)

**Characteristics:**
- Smallest set that uniquely identifies
- No attribute can be removed
- Can have multiple candidate keys
- Each can become primary key

**Example:**
```
Candidate Keys:
1. {StudentID} - minimal, unique
2. {Email} - minimal, unique
3. {RollNo} - minimal, unique

NOT a candidate key:
{StudentID, Name} - NOT minimal (StudentID alone is enough)
```

#### 3. Primary Key

**Definition:** Candidate key chosen by designer as main identifier

**Characteristics:**
- Exactly one per relation
- Cannot be NULL
- Uniquely identifies each tuple
- Used for references

**Example:**
```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,  -- Primary Key
    Email VARCHAR(50) UNIQUE,
    Name VARCHAR(50),
    RollNo INT UNIQUE
);

-- StudentID is primary key
-- Email and RollNo are candidate keys but not selected
```

#### 4. Composite Key

**Definition:** Primary key consisting of multiple attributes

**Characteristics:**
- Two or more attributes combined
- Each attribute alone may not be unique
- Combination is unique
- Common in junction/bridge tables

**Example:**
```sql
CREATE TABLE Enrollment (
    StudentID INT,
    CourseID INT,
    Semester INT,
    EnrollmentDate DATE,
    PRIMARY KEY (StudentID, CourseID, Semester)
);

-- No single attribute uniquely identifies
-- Combination of three identifies enrollment uniquely
```

#### 5. Alternate Key (Secondary Key)

**Definition:** Candidate key NOT chosen as primary key

**Characteristics:**
- Still unique
- Could have been primary key
- Used for indexing
- Alternative identifier

**Example:**
```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,           -- Primary Key
    Email VARCHAR(50) UNIQUE,            -- Alternate Key 1
    RollNo INT UNIQUE                    -- Alternate Key 2
);

-- Email and RollNo are alternate keys
-- StudentID is primary key
```

#### 6. Foreign Key

**Definition:** Key that references primary key of another table

**Characteristics:**
- Links tables together
- References another table's primary key
- Can be NULL
- Enforces referential integrity

**Example:**
```sql
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

-- DeptID in Employee is foreign key
-- References DeptID (primary key) in Department
```

### Comparison Table:

| Key Type | Uniqueness | NULL Allowed | Count per Relation | Purpose |
|----------|-----------|-------------|-------------------|---------|
| **Super Key** | Yes | May vary | Many | Identification |
| **Candidate Key** | Yes | No | Multiple | Selection for PK |
| **Primary Key** | Yes | No | 1 | Main identifier |
| **Composite Key** | Yes | No | 1 | Multi-attribute PK |
| **Alternate Key** | Yes | No | Multiple | Backup identifier |
| **Foreign Key** | No | Yes | Many | Relationship link |

### Example Database:

```sql
CREATE TABLE Course (
    CourseID INT PRIMARY KEY,           -- Primary Key
    CourseCode VARCHAR(10) UNIQUE,      -- Alternate Key
    CourseName VARCHAR(50),
    Credits INT
);

CREATE TABLE Student (
    StudentID INT PRIMARY KEY,          -- Primary Key
    Email VARCHAR(50) UNIQUE,           -- Alternate Key
    Name VARCHAR(50),
    DepartmentID INT
);

CREATE TABLE Enrollment (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(10),
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID, Semester),  -- Composite Key
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);
```

---

## Q3 (5 Marks) - Explain logical database design.

### Answer:

**Logical Database Design** converts conceptual ER model into relational database tables.

### Purpose:

- Transform abstract ER diagram into concrete relational schema
- Define tables, columns, keys, and constraints
- Ready for physical implementation

### Steps in Logical Design:

#### Step 1: Convert Entity Sets to Tables

**Rule:** Each entity type → One table

**Process:**
- Entity class becomes table
- Entity instances become rows
- Each element has unique identifier

**Example:**

```
ER Model:
Entity: Student with attributes StudentID, Name, Email, DOB

Logical Design:
Table: Student (StudentID, Name, Email, DOB)

SQL:
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50),
    Email VARCHAR(50),
    DOB DATE
);
```

#### Step 2: Convert Attributes to Columns

**Rule:** Each attribute → One column

**Handling different attribute types:**

```
Simple Attribute → Single Column
Example: Name VARCHAR(50)

Composite Attribute → Multiple Columns
Example: Address (Street, City, ZipCode)
Becomes: Street VARCHAR(50), City VARCHAR(30), ZipCode VARCHAR(10)

Multivalued Attribute → Separate Table
Example: PhoneNumbers {mobile, home, work}
Becomes: PhoneNumber table with foreign key to Student

Derived Attribute → Usually Stored (for efficiency)
Example: Age calculated from DateOfBirth
Stored as column for quick access
```

**Alternative: Composite Attribute Handling**

```
Option 1: Store separately (recommended for queries)
CREATE TABLE Student (
    StudentID INT,
    AddressStreet VARCHAR(50),
    AddressCity VARCHAR(30),
    AddressZip VARCHAR(10)
);

Option 2: Store as single field
CREATE TABLE Student (
    StudentID INT,
    Address VARCHAR(100)  -- Full address in one field
);
```

#### Step 3: Convert Relationships to Foreign Keys

**Rule:** Relationships between entities become foreign keys

**For different cardinalities:**

**One-to-Many (1:N):** 
- Foreign key goes in "Many" side table
```sql
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,                        -- Foreign Key
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);
```

**Many-to-Many (M:N):**
- Create junction/bridge table
```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50)
);

CREATE TABLE Enrollment (         -- Junction Table
    StudentID INT,
    CourseID INT,
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);
```

**One-to-One (1:1):**
- Foreign key in either table
```sql
CREATE TABLE Person (
    PersonID INT PRIMARY KEY,
    Name VARCHAR(50)
);

CREATE TABLE Passport (
    PassportID INT PRIMARY KEY,
    PassportNumber VARCHAR(20),
    PersonID INT UNIQUE,               -- Foreign Key (UNIQUE for 1:1)
    FOREIGN KEY (PersonID) REFERENCES Person(PersonID)
);
```

#### Step 4: Define Constraints

**After converting structure, add constraints:**

```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE NOT NULL,
    GPA DECIMAL(3,2) CHECK (GPA >= 0 AND GPA <= 4.0),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);
```

### Complete Example: University Database

**ER Model:**
```
Student -- Enrolls -- Course
  |
  BelongsTo
  |
Department -- Offers -- Course
```

**Converted Logical Schema:**

```sql
-- Step 1: Entity Tables
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50) NOT NULL,
    Budget INT
);

CREATE TABLE Course (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(50) NOT NULL,
    Credits INT CHECK (Credits > 0),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Email VARCHAR(50) UNIQUE,
    Phone VARCHAR(15),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

-- Step 2: Relationship Table (M:N)
CREATE TABLE Enrollment (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(10),
    Grade CHAR(1),
    PRIMARY KEY (StudentID, CourseID, Semester),
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)
);
```

### Key Design Decisions:

1. **Normalization:** Avoid data redundancy
2. **Constraint definition:** Ensure data integrity
3. **Attribute selection:** Include all necessary information
4. **Key selection:** Choose appropriate primary and foreign keys

---

## Q4 (5 Marks) - Explain relational algebra with examples.

### Answer:

**Relational Algebra** is a procedural language for querying relational databases using mathematical operations.

### Fundamental Operations:

#### 1. Selection (σ - Sigma)

**Definition:** Select rows satisfying a condition

**Notation:** σ condition (Relation)

**Example: Find employees with salary > 50000**
```
σ Salary > 50000 (Employee)

Result:
Name    | Salary | Dept
--------|--------|------
John    | 60000  | IT
Sarah   | 70000  | HR
```

**SQL Equivalent:**
```sql
SELECT * FROM Employee WHERE Salary > 50000;
```

**Multiple conditions:**
```
σ (Dept='IT' ∧ Salary > 50000) (Employee)
```

#### 2. Projection (π - Pi)

**Definition:** Select specific columns

**Notation:** π column1,column2 (Relation)

**Example: Get names and salaries**
```
π Name, Salary (Employee)

Result:
Name    | Salary
--------|-------
John    | 60000
Sarah   | 70000
Mike    | 55000
```

**SQL Equivalent:**
```sql
SELECT Name, Salary FROM Employee;
```

#### 3. Union (∪)

**Definition:** Combine rows from two relations

**Notation:** R1 ∪ R2

**Requirements:** Same schema (columns and types)

**Example: Employees in Sales OR Marketing**
```
σ Dept='Sales' (Employee) ∪ σ Dept='Marketing' (Employee)

Result: All Sales and Marketing employees (no duplicates)
```

**SQL Equivalent:**
```sql
SELECT * FROM Employee WHERE Dept='Sales'
UNION
SELECT * FROM Employee WHERE Dept='Marketing';
```

#### 4. Intersection (∩)

**Definition:** Common rows from two relations

**Notation:** R1 ∩ R2

**Example: Employees in both queries**
```
σ Salary > 50000 (Employee) ∩ σ Dept='IT' (Employee)

Result: IT employees with salary > 50000
```

**SQL Equivalent:**
```sql
SELECT * FROM Employee 
WHERE Salary > 50000 AND Dept='IT';
```

#### 5. Difference (−)

**Definition:** Rows in first relation but not in second

**Notation:** R1 − R2

**Example: Employees with salary > 50000 except IT employees**
```
σ Salary > 50000 (Employee) − σ Dept='IT' (Employee)

Result: High-paid non-IT employees
```

**SQL Equivalent:**
```sql
SELECT * FROM Employee WHERE Salary > 50000
MINUS
SELECT * FROM Employee WHERE Dept='IT';
```

#### 6. Cartesian Product (×)

**Definition:** All combinations of rows from two relations

**Notation:** R1 × R2

**If R1 has m rows, R2 has n rows:** Result has m × n rows

**Example: All employee-department pairs**
```
Employee × Department

If Employee has 100 rows, Department has 5 rows
Result: 100 × 5 = 500 combinations
```

**Note:** Rarely used alone, usually combined with selection

#### 7. Join (⋈)

**Definition:** Combine related rows from two relations

**Types:**

**Natural Join:**
```
Employee ⋈ Department
(Joins on common attribute: DepartmentID)

Result: Shows all matching employee-department pairs
```

**Theta Join (with condition):**
```
R1 ⋈θ R2 = σθ (R1 × R2)
```

**Example: Employees and their managers**
```
Employee ⋈ (Employee.ManagerID = Employee.EmpID) Employee
```

### Complex Query Examples:

#### Example 1: Find IT employees earning > 50000

```
Relational Algebra:
π Name, Salary (σ (Dept='IT' ∧ Salary > 50000) (Employee))

Step-by-step:
1. σ (Dept='IT' ∧ Salary > 50000) (Employee) -- Selection
2. π Name, Salary (result) -- Projection

SQL:
SELECT Name, Salary FROM Employee 
WHERE Dept='IT' AND Salary > 50000;
```

#### Example 2: Names and departments of high earners

```
Relational Algebra:
π Employee.Name, Department.DeptName (
    σ Salary > 60000 (Employee ⋈ Department)
)

Step-by-step:
1. Employee ⋈ Department (Join on DeptID)
2. σ Salary > 60000 (filtered join result)
3. π Name, DeptName (project columns)

SQL:
SELECT e.Name, d.DeptName
FROM Employee e
INNER JOIN Department d ON e.DeptID = d.DeptID
WHERE e.Salary > 60000;
```

#### Example 3: Employees not in IT or HR

```
Relational Algebra:
Employee − (σ Dept='IT' (Employee) ∪ σ Dept='HR' (Employee))

Step-by-step:
1. σ Dept='IT' (Employee) -- IT employees
2. σ Dept='HR' (Employee) -- HR employees
3. ∪ (combine them)
4. Employee − (result) -- subtract from all

SQL:
SELECT * FROM Employee 
WHERE Dept != 'IT' AND Dept != 'HR';
```

### Operations Classification:

| Type | Operations | Operands |
|------|-----------|----------|
| **Unary** | Selection, Projection | Single relation |
| **Binary** | Union, Intersection, Difference, Cartesian Product, Join | Two relations |

### Summary:

- **Selection filters rows**
- **Projection filters columns**
- **Set operations combine/compare relations**
- **Join brings related data together**
- Provides formal foundation for SQL queries

---

## Q5 (5 Marks) - Explain integrity constraints with examples.

### Answer:

**Integrity Constraints** are rules ensuring data accuracy, consistency, and validity in database.

### Types and Explanation:

#### 1. Domain Constraint

**Definition:** Every attribute value must belong to valid domain

**Purpose:** 
- Prevent invalid data insertion
- Enforce data type correctness
- Specify allowed value ranges

**Examples:**

```sql
CREATE TABLE Employee (
    EmpID INT,                              -- Domain: Integer
    Name VARCHAR(50),                       -- Domain: String, max 50 chars
    Age INT CHECK (Age >= 18 AND Age <= 65),-- Domain: 18-65
    Salary DECIMAL(10,2) CHECK (Salary >= 0),-- Domain: Positive numbers
    Email VARCHAR(50),                      -- Domain: Email format
    JoinDate DATE,                          -- Domain: Valid date
    Gender CHAR(1) CHECK (Gender IN ('M', 'F')) -- Domain: M or F
);
```

**Violations:**
```sql
-- INVALID
INSERT INTO Employee VALUES (1, 'John', 200, 50000, ..);  -- Age out of range
INSERT INTO Employee VALUES (1, 'John', 30, -5000, ..);   -- Negative salary
INSERT INTO Employee VALUES (1, 'John', 25, 50000, 'Invalid', ..); -- Invalid email
```

#### 2. Key Constraint (Uniqueness)

**Definition:** Key values must uniquely identify records

**Types:**

**Primary Key:**
```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,  -- Must be unique, not null
    Name VARCHAR(50),
    Email VARCHAR(50)
);

-- INVALID
INSERT INTO Student VALUES (101, 'John', 'john@mail.com');
INSERT INTO Student VALUES (101, 'Jane', 'jane@mail.com');  -- Duplicate StudentID
```

**Candidate Key (Unique):**
```sql
CREATE TABLE Student (
    StudentID INT PRIMARY KEY,
    Email VARCHAR(50) UNIQUE NOT NULL,  -- Also unique, not null
    Phone VARCHAR(15) UNIQUE             -- Can be null but unique
);

-- INVALID
INSERT INTO Student VALUES (101, 'john@mail.com', '9876543210');
INSERT INTO Student VALUES (102, 'john@mail.com', '9123456789');  -- Duplicate email

-- VALID
INSERT INTO Student VALUES (102, 'jane@mail.com', NULL);  -- Phone can be null
INSERT INTO Student VALUES (103, 'bob@mail.com', '9876543210');
INSERT INTO Student VALUES (104, 'alice@mail.com', NULL);  -- Multiple nulls allowed
```

#### 3. Entity Integrity Constraint

**Definition:** Primary key cannot contain NULL values

**Purpose:** 
- Ensure uniquely identifiable records
- Prevent missing primary keys

**Example:**

```sql
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,     -- Cannot be NULL
    DeptName VARCHAR(50) NOT NULL,
    Location VARCHAR(50)        -- Can be NULL
);

-- VALID
INSERT INTO Department VALUES (1, 'IT', 'Building A');
INSERT INTO Department VALUES (2, 'HR', NULL);

-- INVALID
INSERT INTO Department VALUES (NULL, 'Finance', 'Building C');  -- Primary key null
```

#### 4. Referential Integrity Constraint

**Definition:** Foreign key must reference existing primary key value

**Purpose:** 
- Maintain valid relationships
- Prevent orphaned records

**Example:**

```sql
CREATE TABLE Department (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);

-- Setup
INSERT INTO Department VALUES (1, 'IT');
INSERT INTO Department VALUES (2, 'HR');

-- VALID
INSERT INTO Employee VALUES (101, 'John', 1);    -- DeptID 1 exists
INSERT INTO Employee VALUES (102, 'Jane', 2);    -- DeptID 2 exists

-- INVALID
INSERT INTO Employee VALUES (103, 'Bob', 5);     -- DeptID 5 doesn't exist
```

**Delete/Update Rules:**

```sql
-- Restrict deletion
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
        ON DELETE RESTRICT
);

-- CASCADE deletion
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
        ON DELETE CASCADE      -- Delete employees if dept deleted
        ON UPDATE CASCADE
);

-- SET NULL on deletion
CREATE TABLE Employee (
    EmpID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
        ON DELETE SET NULL     -- Set DeptID to NULL if dept deleted
);
```

### Additional Constraints:

**Check Constraint:**
```sql
CREATE TABLE Product (
    ProductID INT PRIMARY KEY,
    Price DECIMAL(10,2) CHECK (Price > 0),
    Quantity INT CHECK (Quantity >= 0),
    DiscountPercent INT CHECK (DiscountPercent >= 0 AND DiscountPercent <= 100)
);
```

**Not Null Constraint:**
```sql
CREATE TABLE Person (
    PersonID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    Email VARCHAR(50) NOT NULL,
    Phone VARCHAR(15)  -- Can be null
);
```

### Complete Example: Bank Database

```sql
CREATE TABLE Customer (
    CustomerID INT PRIMARY KEY,             -- Entity integrity
    Name VARCHAR(50) NOT NULL,              -- Not null
    Email VARCHAR(50) UNIQUE NOT NULL,      -- Unique
    Age INT CHECK (Age >= 18),              -- Domain constraint
    CityID INT,
    FOREIGN KEY (CityID) REFERENCES City(CityID)  -- Referential integrity
);

CREATE TABLE Account (
    AccountID INT PRIMARY KEY,
    CustomerID INT NOT NULL,
    Balance DECIMAL(12,2) CHECK (Balance >= 0),  -- Domain constraint
    AccountType VARCHAR(20) DEFAULT 'Savings',
    OpenDate DATE,
    FOREIGN KEY (CustomerID) REFERENCES Customer(CustomerID)
        ON DELETE RESTRICT
);

-- Violations and Valid Inserts

-- VALID
INSERT INTO Customer VALUES (1, 'John', 'john@mail.com', 30, 1);
INSERT INTO Account VALUES (1001, 1, 5000, 'Savings', '2023-01-01');

-- INVALID
INSERT INTO Customer VALUES (NULL, 'Jane', 'jane@mail.com', 28, 1);  -- PK null
INSERT INTO Customer VALUES (2, 'Bob', 'bob@mail.com', 15, 1);       -- Age < 18
INSERT INTO Account VALUES (1002, 99, 3000, 'Checking', '2023-02-01'); -- FK invalid
INSERT INTO Account VALUES (1003, 1, -1000, 'Savings', '2023-02-01');  -- Negative balance
```

### Summary Table:

| Constraint | Type | Example | Impact |
|-----------|------|---------|--------|
| **Domain** | Validation | Age 18-65 | Type & range check |
| **Key** | Uniqueness | PRIMARY KEY | Prevents duplicates |
| **Entity** | Not Null | PK NOT NULL | Ensures identifiability |
| **Referential** | Foreign Key | FOREIGN KEY | Maintains relationships |

### Benefits:

1. **Data Quality:** Only valid data entry
2. **Consistency:** Relationships maintained
3. **Reliability:** No orphaned records
4. **Enforcement:** Automatic by DBMS
5. **Trust:** Data integrity guaranteed

