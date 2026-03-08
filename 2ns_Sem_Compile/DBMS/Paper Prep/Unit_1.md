# DBMS NOTES - UNIT I
## Database System Applications

**Topics:** Historical perspective, file systems vs DBMS, data model, abstraction levels, data independence, structure of DBMS, ER design

---

## 1. Historical Perspective of Database Systems

Before DBMS existed, data was stored in file processing systems.

### Early Systems

- **Manual record keeping**
  - Data stored in paper files
  - Difficult to maintain and retrieve

### File Processing Systems

- Data stored in separate application files
- Programs directly accessed files

### Problems of File Systems

| Problem | Description |
|---------|-------------|
| Data redundancy | Same data stored in multiple places |
| Data inconsistency | Multiple copies may have contradictory values |
| Difficult data access | Hard to retrieve required information |
| Poor security | No protection against unauthorized access |
| Lack of concurrency control | Multiple users cannot access simultaneously |

**Result:** These problems led to the development of Database Management Systems (DBMS).

---

## 2. File System vs DBMS

| Feature | File System | DBMS |
|---------|------------|------|
| Data redundancy | High | Controlled |
| Data consistency | Difficult to maintain | Automatically maintained |
| Security | Weak | Strong |
| Data sharing | Difficult | Easy |
| Backup & recovery | Manual | Automatic |
| Concurrency | Limited | Fully supported |
| Query capability | Limited | Comprehensive (SQL) |

---

## 3. Data Model

A **data model** is a collection of concepts used to describe the structure of a database.

### What it defines:

- **Data** - The information to be stored
- **Relationships** - How data elements are related
- **Constraints** - Rules that data must follow

### Types of Data Models

1. **Relational Model**
   - Data stored in tables (relations)
   - Most widely used
   - Examples: MySQL, PostgreSQL, Oracle

2. **Entity Relationship Model (ER Model)**
   - Used for conceptual database design
   - Represents entities and their relationships
   - Used to create database schemas

3. **Object Based Model**
   - Uses objects and classes
   - Combines OOP with databases
   - Example: Object-Oriented Databases

4. **Semi Structured Model**
   - Used in XML and NoSQL databases
   - Flexible schema
   - Examples: MongoDB, Cassandra

---

## 4. Levels of Abstraction in DBMS

DBMS hides complexity using **three abstraction levels**:

```
┌─────────────────────────────────┐
│      View Level (External)      │
│  (User specific views)          │
├─────────────────────────────────┤
│     Logical Level (Conceptual)  │
│  (Data structure & relations)   │
├─────────────────────────────────┤
│      Physical Level (Internal)  │
│  (Storage & file organization)  │
└─────────────────────────────────┘
```

### 1. Physical Level (Internal Level)

- **Lowest level** describing how data is stored physically
- Deals with file organization and indexing
- Examples:
  - File blocks and records
  - Index structures (B-tree, hash tables)
  - Memory management

### 2. Logical Level (Conceptual Level)

- **Middle level** describing what data is stored and relationships
- Defines overall structure of the database
- Examples:
  - Employee table with columns: EmployeeID, Name, Salary, DepartmentID
  - Relationships between tables

### 3. View Level (External Level)

- **Highest level** describing how users see data
- Different users see different views of the database
- Examples:
  - **Admin view:** EmployeeID, Salary, Department, Performance Rating
  - **Employee view:** EmployeeID, Name, Department
  - **HR view:** EmployeeID, Name, Salary, Benefits

---

## 5. Data Independence

**Data independence** is the ability to modify database schema without affecting application programs or other views.

### Types of Data Independence

#### Physical Data Independence

- Changes at physical level do **not affect** logical level
- Most flexible type
- Examples:
  - Changing file structure
  - Changing indexing strategy
  - Moving data to different storage devices
  - Application programs remain unaffected

#### Logical Data Independence

- Changes in logical schema do **not affect** user views
- Less flexible than physical independence
- Examples:
  - Adding a new column to a table
  - Removing a column no longer needed
  - User views continue to work normally

### Importance

- Allows database administrators to modify schema without recompiling programs
- Provides flexibility in database design
- Reduces development and maintenance costs

---

## 6. Structure of a DBMS

DBMS architecture contains three main components:

### Part 1: Query Processor

Handles SQL queries and translates them to database operations.

**Components:**

- **DDL Interpreter**
  - Processes Data Definition Language statements
  - Examples: CREATE, ALTER, DROP
  - Updates data dictionary

- **DML Compiler**
  - Processes Data Manipulation Language statements
  - Examples: SELECT, INSERT, UPDATE, DELETE
  - Performs optimization

- **Query Optimizer**
  - Determines efficient execution plan
  - Considers multiple execution strategies
  - Selects optimal path with lowest cost

### Part 2: Storage Manager

Responsible for storing data and managing physical storage.

**Components:**

- **Authorization Manager**
  - Manages user access and permissions
  - Ensures data security

- **Integrity Manager**
  - Enforces integrity constraints
  - Validates data before storage

- **Transaction Manager**
  - Manages transactions
  - Ensures ACID properties

- **File Manager**
  - Manages database files
  - Allocates storage space

- **Buffer Manager**
  - Manages main memory buffer pool
  - Reduces disk I/O operations

### Part 3: Database

- **Collection of stored data**
- Physical storage of all data
- Managed by storage manager

---

## 7. Introduction to Database Design

Database design converts real-world data into structured database tables.

### Design Steps

1. **Identify entities**
   - Real-world objects or concepts
   - Example: Student, Course, Instructor

2. **Identify attributes**
   - Properties/characteristics of entities
   - Example: Student has StudentID, Name, Email

3. **Identify relationships**
   - Associations between entities
   - Example: Student enrolls in Course

4. **Define keys**
   - Primary keys (unique identifiers)
   - Foreign keys (relationships)

5. **Create schema**
   - Define tables and constraints
   - Write CREATE TABLE statements

### Importance

- Ensures efficient data storage
- Prevents data redundancy
- Maintains data integrity
- Ensures easy data retrieval

---

## 8. ER Model (Entity Relationship Model)

The **Entity Relationship Model** is used for **conceptual database design**. It provides a visual representation of database structure.

### Key Concepts

#### Entities

An **entity** represents real-world objects or concepts.

**Examples:**
- Student
- Employee
- Course
- Department

#### Attributes

**Attributes** describe properties or characteristics of entities.

**Example - Student Entity:**
- StudentID
- Name
- Age
- Email
- Address

**Types of Attributes:**

| Type | Description | Example |
|------|-------------|---------|
| Simple | Cannot be divided further | Name, Age |
| Composite | Can be divided into parts | Address (street, city, zip) |
| Derived | Calculated from other attributes | Age (calculated from DOB) |
| Multivalued | Can have multiple values | PhoneNumbers (multiple phones) |
| Key | Uniquely identifies entity | StudentID |

#### Entity Set

Collection of similar entities of the same type.

**Example:**
- Entity: Student (single instance)
- Entity Set: All students in database (collection)

#### Relationships

**Relationship** represents association or connection between entities.

**Example:**
- Student **Enrolls** in Course

**Types of Relationships (Cardinality):**

| Type | Notation | Example |
|------|----------|---------|
| One-to-One (1:1) | A→B | Person - PassportNumber |
| One-to-Many (1:N) | A→B* | Department - Employees |
| Many-to-One (M:1) | A* ← B | Employees - Department |
| Many-to-Many (M:N) | A* ↔ B* | Student - Course |

### Additional ER Model Features

#### 1. Weak Entities

- Entities that cannot be uniquely identified by their attributes alone
- Depend on a strong entity
- Example: Dependent (of Employee)

#### 2. Aggregation

- Allowing relationships to become entities
- Useful for modeling complex relationships

#### 3. Specialization

- Creating specialized versions of an entity
- Example: Employee → Manager, Developer, Designer

#### 4. Generalization

- Grouping similar entities into a generalized entity
- Reverse of specialization

### Conceptual Design using ER Model

#### Steps:

1. **Identify entities**
   - What real-world objects need to be stored?

2. **Identify attributes**
   - What properties do entities have?

3. **Identify relationships**
   - How are entities related?
   - What is the cardinality?

4. **Draw ER diagram**
   - Visual representation
   - Use standard symbols

5. **Convert ER diagram to tables**
   - Create relational schema
   - Define primary and foreign keys

#### ER Diagram Symbols

- **Rectangle:** Entity
- **Oval:** Attribute
- **Diamond:** Relationship
- **Double rectangle:** Weak entity
- **Double oval:** Multivalued attribute
- **Dashed oval:** Derived attribute

---

## Summary

- DBMS evolved to solve problems of file systems
- Three abstraction levels hide complexity: Physical, Logical, View
- Data independence allows schema changes without affecting applications
- DBMS structure includes Query Processor, Storage Manager, and Database
- ER Model is essential for database design
- Proper database design ensures efficiency and data integrity
