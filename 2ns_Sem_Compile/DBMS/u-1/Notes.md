# Unit 1: Database System Applications

## Definition

A **Database Management System (DBMS)** is an integrated set of software programs that facilitates the creation, maintenance, and utilization of databases by allowing users to define, create, query, update, and manage data efficiently and securely.

## Evolution and Purpose

### Traditional File System Limitations

Before DBMS, organizations relied on file systems to manage data. This approach had critical limitations:

1. **Data Redundancy**: Same data stored in multiple files
   - Example: Customer address stored in both Invoice file and Customer file
   - Leads to wasted storage and maintenance issues

2. **Data Inconsistency**: Redundant data may be inconsistent
   - Example: Address updated in Invoice file but not in Customer file
   - Creates conflicting information

3. **Difficult Data Access**: Accessing data requires writing custom programs
   - Requires programmer involvement for each new query
   - Time-consuming and error-prone

4. **Poor Security**: Hard to implement access control
   - No fine-grained permission management
   - All users may have access to sensitive data

5. **Lack of Concurrency Control**: Multiple users cannot access data safely
   - Lost updates when two users modify same record
   - Data corruption possible

6. **Weak Backup and Recovery**: Manual, unreliable recovery mechanisms
   - Data loss during system failures
   - No automated backup procedures

### Why DBMS Solved These Problems

- **Centralized Data Management**: Single source of truth
- **Data Abstraction**: Users don't need to know physical storage details
- **Automated Query Processing**: Declarative SQL instead of procedural code
- **Built-in Security**: User authentication and authorization
- **Concurrency Control**: Multiple users can work simultaneously
- **Automated Backup and Recovery**: Systematic fault tolerance

## File System vs DBMS

| Point | File System | DBMS |
|---|---|---|
| **Data Redundancy** | High - same data in multiple files | Minimized - normalized structure |
| **Data Consistency** | Difficult to maintain | Enforced by constraints |
| **Data Access** | Programming language dependent | SQL queries, easy ad-hoc queries |
| **Security** | File-level only | Row and column level access control |
| **Concurrency** | Limited - file-level locking | Sophisticated locking and isolation |
| **Backup and Recovery** | Manual, error-prone | Automatic with logs |
| **Query Performance** | Slow - requires full file scans | Optimized - indexes and query plans |
| **Data Independence** | Low - program tied to file structure | High - schema changes don't break programs |
| **Integrity** | Enforced by application | Enforced by database constraints |
| **Scalability** | Limited to single machine | Scales to large datasets |

## Data Models

Data models define the logical structure of how data is organized and relationships between data elements.

### 1. Relational Model (Most Popular)

- Data organized in tables (relations)
- Tables have rows (tuples) and columns (attributes)
- Based on relational algebra and calculus
- Used by: MySQL, PostgreSQL, Oracle, SQL Server

**Example**:
```
Employee Table:
| EmployeeID | Name     | Department | Salary |
|------------|----------|------------|--------|
| 101        | Raj      | IT         | 50000  |
| 102        | Priya    | HR         | 45000  |
```

### 2. Entity-Relationship (ER) Model

- Used for database design and conceptual modeling
- Represents entities, attributes, and relationships
- Bridge between real world and relational model
- Foundation for creating relational schemas

**Example**:
```
[Student] --enrolls-in--> [Course]
```

### 3. Object-Oriented Model

- Treats data as objects with properties and methods
- Supports inheritance and object relationships
- Used when complex objects need to be stored
- Used by: ObjectDB, db4o

**Example**:
```java
class Student {
    int studentID;
    String name;
    Vector<Course> enrolledCourses;
    public void registerCourse(Course c) {...}
}
```

### 4. Object-Relational Model

- Hybrid combining relational and object features
- Tables can contain object types
- Used by: PostgreSQL, Oracle

### 5. Semi-Structured Model

- Data with variable structure
- No fixed schema required
- Used for XML and NoSQL databases
- Used by: MongoDB, CouchDB

**Example**:
```json
{
  "studentID": 101,
  "name": "Raj",
  "enrolledCourses": ["CS101", "CS102"],
  "contactInfo": {
    "email": "raj@college.edu",
    "phone": "9876543210"
  }
}
```

### 6. Hierarchical Model (Legacy)

- Data organized in tree structure
- Parent-child relationships
- One parent can have many children
- One child has only one parent
- Rarely used today

### 7. Network Model (Legacy)

- Extension of hierarchical model
- Allows multiple parent-child relationships
- More flexible than hierarchical
- Complex to use, largely replaced by relational model

## Levels of Abstraction (Three-Schema Architecture)

Database systems hide complexity by organizing data at three levels:

### Level 1: Physical Level (Internal Level)

**Purpose**: Describes HOW data is actually stored on disk

**Includes**:
- Physical file organization (heap, sequential, hashed)
- Storage structures and compression techniques
- Indexes (B-trees, Hash tables)
- Block sizes and buffering mechanisms
- Partitioning and distribution strategies

**Details managed by**:
- Storage managers
- Physical database designers

**Example**: "Customer records are stored in B+ tree index on customer_id in file `/data/customer.db`, with 4KB block size"

### Level 2: Logical/Conceptual Level

**Purpose**: Describes WHAT data is stored and logical relationships

**Includes**:
- Database schema (table definitions)
- Attributes (columns) and their data types
- Constraints and keys
- Relationships between entities

**Details managed by**:
- Database administrators
- Database designers

**Example**:
```
CUSTOMER Table:
  CustomerID (INT, PRIMARY KEY)
  CustomerName (VARCHAR(50), NOT NULL)
  Email (VARCHAR(100), UNIQUE)
  PhoneNumber (VARCHAR(10))
  CityID (INT, FOREIGN KEY)
```

### Level 3: View Level (External Level)

**Purpose**: Describes HOW users see data (user-specific views)

**Includes**:
- User-defined views
- Application-level schemas
- Customized data presentations
- Restricted subsets of data based on permissions

**Details managed by**:
- Application developers
- End users

**Example**:
```sql
CREATE VIEW Customer_Summary AS
SELECT CustomerID, CustomerName, CityID
FROM CUSTOMER
WHERE Status = 'Active';
```

### Advantages of Three-Level Abstraction

1. **Data Independence**: Changes at one level don't affect other levels
2. **Security**: Physical details hidden from users
3. **Flexibility**: Multiple views on same data
4. **Simplified User Interfaces**: Users see only relevant data
5. **Easier Maintenance**: Physical changes don't require application changes

## Data Independence

Data independence is the capacity to change the schema at one level without affecting the schema at the next level.

### Physical Data Independence

**Definition**: The ability to change the physical schema without changing the logical schema or applications.

**Changes allowed**:
- Moving data from one storage device to another
- Changing file organization (e.g., from sequential to hashed)
- Adding or modifying indexes
- Changing compression techniques
- Reorganizing physical storage layout

**Why it matters**: Database administrators can optimize storage and performance without affecting applications or users.

**Real-world example**:
```
Old setup: Sequential file scan for customer lookup - 2 seconds
New setup: Add B+ tree index - 0.1 seconds lookup
Applications: No code changes needed, queries still work!
```

### Logical Data Independence

**Definition**: The ability to change the logical schema without changing user views or external schema.

**Changes allowed**:
- Adding new tables
- Adding new columns (with DEFAULT values)
- Merging tables
- Splitting tables
- Changing relationships

**Why it matters**: Database designers can reorganize data structure for better design without rewriting applications.

**Real-world example**:
```
Before: Single EMPLOYEE table with both home and work addresses
After:  Split into EMPLOYEE and ADDRESS tables with 1:M relationship
View remains same for existing applications, improved data organization!
```

## DBMS Architecture

### Query Processor Components

The Query Processor translates SQL queries into executable instructions.

#### 1. DDL Interpreter
- Processes Data Definition Language statements
- Statements: CREATE, ALTER, DROP, TRUNCATE
- Functions:
  - Validates schema specifications
  - Stores schema in data dictionary
  - Checks for duplicate names
  - Enforces domain and integrity constraints
- Output: Schema definitions stored in system catalog

#### 2. DML Compiler and Query Optimizer
- DML Compiler: Translates INSERT, UPDATE, DELETE, SELECT statements
- Query Optimizer: Determines most efficient way to execute queries
- Evaluates different execution plans
- Selects plan with minimum estimated cost
- Considers available indexes, table sizes, join methods

#### 3. Query Engine
- Executes compiled query plan
- Performs actual data retrieval and modification
- Coordinates with storage manager

### Storage Manager Components

The Storage Manager manages database files and is responsible for storing and retrieving data efficiently.

#### 1. Authorization and Integrity Manager
- **Authorization**: Enforces user privileges and access control
  - GRANT and REVOKE privileges
  - Ensures users can only access authorized data
  - Maintains user authentication credentials
  
- **Integrity**: Enforces data constraints
  - PRIMARY KEY uniqueness
  - FOREIGN KEY references
  - CHECK constraints
  - NOT NULL constraints
  - UNIQUE constraints
  - Domain constraints

#### 2. Transaction Manager
- Ensures ACID properties
- Controls concurrent access by multiple transactions
- Manages transaction logging
- Coordinates with recovery manager
- Implements locking and timestamp ordering

#### 3. File Manager
- Manages logical files and their allocation on disk
- Handles file creation, deletion, modification
- Manages space allocation and deallocation
- Converts logical file references to physical locations

#### 4. Buffer Manager
- Manages main memory buffer pool
- Decides which pages to keep in memory
- Minimizes disk I/O operations
- Implements page replacement policies (LRU, LFU)
- Coordinates with file manager for page fetches

#### 5. Recovery Manager
- Maintains transaction logs
- Performs undo/redo operations
- Creates checkpoints
- Recovers database after failures
- Manages backup and restore operations

## DBMS Architecture Diagram

```
┌─────────────────────────────────────────┐
│          USER INTERFACE                 │
│      (Applications, SQL Tools)          │
└─────────────────────────────────────────┘
                    ▲
                    │ SQL Queries
                    ▼
┌─────────────────────────────────────────┐
│       QUERY PROCESSOR                   │
├─────────────────────────────────────────┤
│  • DDL Interpreter                      │
│  • DML Compiler                         │
│  • Query Optimizer                      │
│  • Query Engine                         │
└─────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────┐
│       STORAGE MANAGER                   │
├─────────────────────────────────────────┤
│  • Authorization & Integrity Manager    │
│  • Transaction Manager                  │
│  • File Manager                         │
│  • Buffer Manager                       │
│  • Recovery Manager                     │
└─────────────────────────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────┐
│    SECONDARY STORAGE                    │
│  (Database Files, Indexes, Logs)        │
└─────────────────────────────────────────┘
```

## Processing of SQL Query

### Step 1: Lexical and Syntax Analysis
```
SQL Input: "SELECT Name FROM EMPLOYEE WHERE Age > 25"
           ▼
Tokenization: SELECT | Name | FROM | EMPLOYEE | WHERE | Age | > | 25
           ▼
Syntax Check: Verify valid SQL syntax
           ▼
Output: Parse tree created
```

### Step 2: Semantic Analysis and Query Compilation
```
Query: "SELECT Name FROM EMPLOYEE WHERE Age > 25"
           ▼
Semantic Check:
  • Does EMPLOYEE table exist?
  • Do Name and Age attributes exist?
  • Are data types compatible?
  • Are user privileges sufficient?
           ▼
Query Compilation: Convert to intermediate code
```

### Step 3: Query Optimization
```
Optimization Task:
  Input: Multiple possible execution plans
  
  Plan 1: Sequential scan + Filter (slow, 5 seconds)
  Plan 2: Use Age index + Retrieve Names (fast, 0.5 seconds)
  
  Optimizer estimates cost:
    • I/O operations
    • CPU time
    • Memory usage
  
  Output: Best plan selected (Plan 2)
```

### Step 4: Query Execution and Results
```
Execution Plan:
  1. Locate index for Age column
  2. Find all records where Age > 25
  3. Retrieve Name from matching records
  4. Return result set to user
           ▼
Result: Names of employees older than 25
```

## Real-World DBMS Examples

### MySQL/MariaDB
- Open source relational DBMS
- Popular in web applications
- User-friendly, easy to set up
- Good for small to medium databases

### PostgreSQL
- Advanced open source relational DBMS
- ACID compliance
- Complex data type support
- Excellent for enterprise applications

### Oracle Database
- Enterprise-grade DBMS
- High reliability and scalability
- Advanced security features
- Used in large organizations

### SQL Server
- Microsoft's enterprise DBMS
- Integrated with Windows environment
- Business intelligence capabilities
- Used in enterprise data warehouses

### MongoDB (NoSQL)
- Document-oriented database
- Flexible schema
- Horizontal scalability
- Good for unstructured data

## Exam Notes

- **1-Line Definition**: Start with "DBMS is software for managing databases."
- **File System Problems**: Write 4-6 distinct points with short examples
- **Three-Level Architecture**: Always draw diagram with clear labels for Physical, Logical, and View levels
- **Data Independence**: Explain with real-world storage/design examples
- **DBMS Components**: Classify into Query Processor and Storage Manager with sub-components
- **Key Differences**: Use table format comparing file systems vs DBMS when asked
- **Processing Steps**: If asked about query processing, cover all 4 steps with diagram
