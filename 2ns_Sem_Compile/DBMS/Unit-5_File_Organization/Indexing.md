# Indexing - Comprehensive Guide

## Definition

An **index** is an auxiliary access structure that improves the speed of data retrieval operations on a table. It's like a table of contents in a book – instead of reading every page, you look up the page number and jump directly to the relevant pages.

### Analogy with Book

```
Without Index (Table Scan):
Reader wants information about "Transactions"
└─ Must read all 500 pages sequentially
└─ Slow! Takes time to find information

With Index (Using Index):
Reader looks up "Transactions" in index
└─ Finds: "Transactions: pages 234-245"
└─ Jumps directly to pages 234-245
└─ Fast! Much quicker retrieval
```

## Why Indexing is Critical

### Without Index - Table Scan

```
Query: SELECT * FROM STUDENT WHERE StudentID = 101

Without Index:
┌─────────────────────────────────────┐
│ Full Table Scan                     │
├─────────────────────────────────────┤
│ Check Row 1: StudentID = 50? NO     │
│ Check Row 2: StudentID = 75? NO     │
│ Check Row 3: StudentID = 101? YES!  │ ← Found at row 3
│ ...continue to end (unnecessary)... │
│ Check Row 1000000: StudentID = 200? NO │
└─────────────────────────────────────┘

Time Complexity: O(n) - Linear search through all rows
Performance: Very Slow for large tables
```

### With Index - Direct Access

```
Query: SELECT * FROM STUDENT WHERE StudentID = 101

With B+ Tree Index on StudentID:
┌──────────────┐
│ Index Root   │
└──────┬───────┘
       │
    (Binary search on index)
       │
    StudentID = 101 found
       │ (Points to actual row)
       ▼
┌─────────────┐
│ Row 3 Data  │
│ StudentID:101 │
│ Name: Raj    │
└─────────────┘

Time Complexity: O(log n) - Binary search through index
Performance: Much faster!
```

### Performance Impact

```
Table Size: 1,000,000 records

Without Index:
  Average search: 500,000 record reads
  Time: ~5 seconds

With B+ Tree Index:
  Average search: log₂(1,000,000) ≈ 20 index checks
  Time: ~0.02 seconds

Speed Improvement: 250x faster!
```

## Types of Indexes

### 1. Primary Index

**Definition**: Index on primary key attribute, automatically created by DBMS.

**Characteristics**:
- Unique index on primary key
- Automatically enforces uniqueness
- One per table
- Guarantees unique values

**Example**:
```
STUDENT table has StudentID as PK
DBMS automatically creates primary index
```

**SQL**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,  -- Automatic primary index
    StudentName VARCHAR(50),
    Email VARCHAR(100)
);
```

### 2. Secondary Index

**Definition**: Index on non-primary key attributes to speed up queries.

**Characteristics**:
- Created on non-key attributes
- Multiple secondary indexes possible
- Don't enforce uniqueness (unless specified)
- Improve query performance on specific columns

**Example**:
```
STUDENT table
  ├─ Primary Index on StudentID (automatic)
  └─ Secondary Indexes (optional):
     ├─ Index on Email
     ├─ Index on Department
     └─ Index on GPA
```

**SQL**:
```sql
-- Create secondary index on Email
CREATE INDEX idx_student_email ON STUDENT(Email);

-- Create secondary index on Department
CREATE INDEX idx_student_department ON STUDENT(Department);
```

### 3. Clustered Index

**Definition**: Index that determines physical order of rows in table.

**Characteristics**:
- One clustered index per table
- Usually on primary key
- Rows stored in index order
- Leaf nodes contain actual data
- Most efficient for range queries

**How it Works**:
```
Clustered Index on StudentID

Index Structure (Physical Order in Disk):
┌─ StudentID: 101 → Name: Raj → GPA: 3.7
├─ StudentID: 102 → Name: Priya → GPA: 3.5
├─ StudentID: 103 → Name: Amit → GPA: 3.2
└─ ...

Rows physically sorted by StudentID on disk
Scanning range is very efficient
```

**SQL**:
```sql
-- MySQL (Automatic for PRIMARY KEY)
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,  -- Clustered index
    StudentName VARCHAR(50)
);

-- SQL Server (Explicit)
CREATE CLUSTERED INDEX idx_student_id
ON STUDENT (StudentID);
```

### 4. Non-Clustered Index

**Definition**: Index that doesn't affect physical order of rows.

**Characteristics**:
- Multiple non-clustered indexes per table
- Index entries point to actual rows
- Leaf nodes contain index key + row pointer
- More flexible than clustered

**How it Works**:
```
Non-Clustered Index on Email

Index Structure:
┌─ Email: amit@college.edu → Pointer to Row#3
├─ Email: priya@college.edu → Pointer to Row#2
└─ Email: raj@college.edu → Pointer to Row#1

Actual Table (Physical Order):
Row#1: StudentID=101, Name=Raj, Email=raj@college.edu
Row#2: StudentID=102, Name=Priya, Email=priya@college.edu
Row#3: StudentID=103, Name=Amit, Email=amit@college.edu

Index order ≠ Physical order
```

**SQL**:
```sql
CREATE NONCLUSTERED INDEX idx_student_email
ON STUDENT(Email);
```

### 5. Dense Index

**Definition**: Index with entry for every record in table.

**Characteristics**:
- Entry for each record
- Memory intensive
- Faster search
- Used when space available

**Example**:
```
Table Records: 10,000
Dense Index Entries: 10,000 (one per record)

Memory: Significant space required
Speed: Very fast (but many entries to scan)
```

**Visual**:
```
Dense Index (StudentID):
┌─ 101
├─ 102
├─ 103
├─ 104
├─ 105
└─ ... (entry for every record)
```

### 6. Sparse Index

**Definition**: Index with entry for only some records.

**Characteristics**:
- Entries at intervals (e.g., every 10th record)
- Less memory required
- Slower than dense (need binary search)
- Used when space constrained

**Example**:
```
Table Records: 10,000 (physically sorted)
Sparse Index Entries: 1,000 (every 10th record)

Memory: 10x less than dense
Speed: Need binary search in main data
```

**Visual**:
```
Sorted Table with Sparse Index (StudentID):

Index:
┌─ StudentID: 101 (points to position 1)
├─ StudentID: 111 (points to position 11)
├─ StudentID: 121 (points to position 21)
└─ ... (every 10th entry)

To find 105:
  1. Find nearest index entry ≤ 105 (101)
  2. Scan linearly from position 1 until 105
```

### 7. Composite Index

**Definition**: Index on combination of multiple columns.

**Characteristics**:
- Index on 2+ columns
- Useful for queries filtering on multiple columns
- Column order matters

**Example**:
```
STUDENT table:
├─ StudentID
├─ Department
├─ GPA

Composite Index: (Department, GPA)
```

**Advantage**:
```
Query: SELECT * FROM STUDENT 
       WHERE Department = 'IT' AND GPA > 3.5

Without Composite Index:
  Index on Department: Narrows to IT students
  Then scan GPA manually (slow)

With Composite Index (Department, GPA):
  Both conditions use index (very fast)
```

**SQL**:
```sql
CREATE INDEX idx_dept_gpa ON STUDENT(Department, GPA);
```

**Important**: Column order in composite index matters
```sql
-- Index 1: Good for WHERE Department = 'IT' AND GPA > 3.5
CREATE INDEX idx1 ON STUDENT(Department, GPA);

-- Index 2: Different; Good for WHERE GPA > 3.5 (but not Department filter first)
CREATE INDEX idx2 ON STUDENT(GPA, Department);

-- These are different indexes with different efficiency!
```

### 8. Unique Index

**Definition**: Index that enforces uniqueness of values.

**Characteristics**:
- No duplicate values allowed
- Can be on primary or secondary key
- Enforces data integrity

**Example**:
```
Email should be unique in STUDENT table
```

**SQL**:
```sql
CREATE UNIQUE INDEX idx_student_email 
ON STUDENT(Email);

-- Now this will fail:
INSERT INTO STUDENT VALUES (104, 'Neha', 'raj@college.edu');
-- Error: Duplicate email (raj@college.edu already exists)
```

### 9. Full-Text Index

**Definition**: Index for fast text search and pattern matching.

**Characteristics**:
- Used for searching document content
- Supports complex text queries
- Optimized for text data

**Example**:
```sql
CREATE FULLTEXT INDEX idx_description
ON COURSE(CourseDescription);

-- Query with FULLTEXT search
SELECT * FROM COURSE
WHERE MATCH(CourseDescription) AGAINST('database' IN BOOLEAN MODE);
```

## Comparison of Index Types

| Index Type | Use Case | Memory | Speed | Unique |
|-----------|----------|--------|-------|--------|
| Primary | Primary Key | Low | Very Fast | Yes |
| Secondary | Non-key columns | Medium | Fast | No |
| Clustered | Frequent range queries | Low | Very Fast | Often |
| Non-Clustered | Multiple access paths | Medium | Fast | No |
| Dense | Small tables | High | Very Fast | N/A |
| Sparse | Large sorted tables | Low | Medium | N/A |
| Composite | Multi-column queries | Medium | Fast | No |
| Unique | Unique columns | Medium | Fast | Yes |
| Full-Text | Text search | High | Medium | N/A |

## Index Implementation Techniques

### B-Tree Index

**Structure**: Balanced multi-way search tree

**Advantages**:
- Good for equality and range queries
- Balanced (no worst-case O(n))
- Efficient disk usage

**SQL Support**: Most databases use B-Tree for general indexes

### Hash Index

**Structure**: Hash table

**Advantages**:
- Very fast equality search
- Simple implementation

**Disadvantages**:
- No range query support
- Collision handling overhead

**Usage**: MySQL MEMORY table engine

### B+ Tree Index

**Structure**: Extended B-Tree with linked leaf nodes

**Advantages**:
- Excellent for both equality and range queries
- Leaf nodes linked for sequential access
- Most efficient for DBMS

**Usage**: Most DBMS default (MySQL InnoDB, PostgreSQL)

## Creating and Managing Indexes

### Create Index

**Syntax**:
```sql
CREATE [UNIQUE | FULLTEXT] INDEX index_name
ON table_name (column1 [ASC | DESC], column2, ...);
```

**Examples**:
```sql
-- Simple index
CREATE INDEX idx_salary ON EMPLOYEE(Salary);

-- Unique index
CREATE UNIQUE INDEX idx_email ON STUDENT(Email);

-- Composite index
CREATE INDEX idx_dept_salary ON EMPLOYEE(Department, Salary DESC);

-- Full-text index
CREATE FULLTEXT INDEX idx_desc ON COURSE(Description);
```

### View Indexes

```sql
-- MySQL
SHOW INDEX FROM table_name;
SHOW INDEXES FROM STUDENT;

-- SQL Server
SELECT * FROM sys.indexes WHERE object_id = OBJECT_ID('STUDENT');

-- PostgreSQL
\d table_name
SELECT * FROM pg_indexes WHERE tablename = 'student';
```

### Drop Index

```sql
-- MySQL
DROP INDEX index_name ON table_name;
DROP INDEX idx_student_email ON STUDENT;

-- SQL Server
DROP INDEX table_name.index_name;
DROP INDEX STUDENT.idx_student_email;

-- PostgreSQL
DROP INDEX index_name;
DROP INDEX idx_student_email;
```

### Rebuild/Analyze Indexes

```sql
-- MySQL - Analyze table
ANALYZE TABLE STUDENT;

-- MySQL - Optimize table
OPTIMIZE TABLE STUDENT;

-- SQL Server - Rebuild index
ALTER INDEX index_name ON table_name REBUILD;

-- SQL Server - Reorganize index
ALTER INDEX index_name ON table_name REORGANIZE;
```

## Index Design Guidelines

### When to Create Index

1. **Primary Keys** - Automatically indexed
2. **Foreign Keys** - Frequently used in JOINs
3. **Columns in WHERE Clause** - Filter operations
4. **Columns in JOIN Conditions** - Link tables
5. **Columns in ORDER BY** - Sort operations
6. **Columns in GROUP BY** - Grouping operations

### When NOT to Create Index

1. **Small tables** - Full scan may be faster
2. **Columns with many NULLs** - Index less effective
3. **Columns with low cardinality** - Many duplicates, index less effective
4. **Columns frequently updated** - Maintenance overhead

### Index Overhead

```
Benefits of Index:
├─ Faster SELECT queries
├─ Faster WHERE filtering
└─ Faster JOIN operations

Costs of Index:
├─ Disk space for index storage
├─ Slower INSERT (must update index)
├─ Slower UPDATE (must update index)
├─ Slower DELETE (must update index)
└─ Memory for index caching
```

## Index Example - Complete Scenario

**Scenario**: Student enrollment system with slow queries

**Before Optimization**:
```sql
-- Slow query (full table scan)
SELECT StudentName, CourseName, Grade
FROM Enrollment
WHERE StudentID = 101
AND Grade >= 'B';

-- Performance: 5 seconds (scans all 1M records)
```

**Add Indexes**:
```sql
-- Index 1: On StudentID (most selective)
CREATE INDEX idx_enrollment_student ON ENROLLMENT(StudentID);

-- Index 2: Composite index for both conditions
CREATE INDEX idx_enrollment_student_grade 
ON ENROLLMENT(StudentID, Grade);
```

**After Optimization**:
```sql
-- Same query
SELECT StudentName, CourseName, Grade
FROM Enrollment
WHERE StudentID = 101
AND Grade >= 'B';

-- Performance: 0.05 seconds (uses composite index)
-- 100x faster!
```

## Exam Notes

1. **Definition**: Simple definition first, then explain as access structure
2. **Why Needed**: Performance improvement with examples
3. **Index Types**: Know at least 6-8 types with characteristics
4. **Clustered vs Non-Clustered**: Key distinction
5. **Dense vs Sparse**: Understand trade-off
6. **Composite Indexes**: Explain column order importance
7. **Trade-offs**: Know advantages and limitations
8. **SQL Syntax**: Know CREATE, DROP, SHOW INDEX commands
9. **Design Guidelines**: When to create, when not to create
10. **B-Tree/B+ Tree**: Basic structure and why used
