# Relational Algebra

## Definition

**Relational algebra** is a procedural query language that defines a set of operations on relations. It specifies operations to be performed and the order in which they are performed to retrieve data.

### Key Characteristics

1. **Procedural**: Specifies HOW to get data (step-by-step)
2. **Formal**: Mathematical foundation (set theory)
3. **Operations on Relations**: Works on entire tables
4. **Compositional**: Operations can be combined
5. **Foundation for SQL**: SQL is based on relational algebra concepts

### Relationship to SQL

```
Relational Algebra (Procedural - HOW)
    ↓
    Specifies operations and order
    
SQL Query (Declarative - WHAT)
    ↓
    DBMS translates to algebra operations
    ↓
    DBMS optimizes execution plan
```

## Fundamental Operations

### 1. Selection (σ - Sigma)

**Definition**: Selects tuples (rows) that satisfy a specified condition.

**Syntax**:
```
σ condition (Relation)
```

**Characteristics**:
- Filters horizontal subset
- Operates on rows
- Produces relation with same attributes
- Cardinality can be ≤ original
- Degree remains same

**Symbols**:
- `=` Equal
- `<>` Not equal
- `<` Less than
- `>` Greater than
- `≤` Less than or equal
- `≥` Greater than or equal
- `∧` AND
- `∨` OR
- `¬` NOT

**Example 1 - Simple Selection**:
```
Find employees with salary > 50000

Algebra: σ Salary > 50000 (EMPLOYEE)

Result (Selected rows):
┌────────────┬──────────────┬─────────┐
│ EmployeeID │ EmployeeName │ Salary  │
├────────────┼──────────────┼─────────┤
│ 101        │ Raj          │ 55000   │
│ 103        │ Amit         │ 60000   │
└────────────┴──────────────┴─────────┘

Discarded rows (Salary ≤ 50000 not shown)
```

**Example 2 - Complex Selection**:
```
Find employees in IT department earning more than 50000

Algebra: σ (Department = 'IT' ∧ Salary > 50000) (EMPLOYEE)

Multiple conditions combined with AND
```

**SQL Equivalent**:
```sql
SELECT * FROM Employees 
WHERE Salary > 50000;

SELECT * FROM Employees
WHERE Department = 'IT' AND Salary > 50000;
```

### 2. Projection (π - Pi)

**Definition**: Selects specified attributes (columns) from a relation.

**Syntax**:
```
π Attribute1, Attribute2, ... (Relation)
```

**Characteristics**:
- Filters vertical subset
- Operates on columns
- Produces relation with selected attributes only
- Degree changes (to number of selected attributes)
- Cardinality can be ≤ original (duplicates removed)
- Can eliminate duplicate tuples

**Example 1 - Simple Projection**:
```
Find all employee names and salaries

Algebra: π EmployeeName, Salary (EMPLOYEE)

Result (Selected columns):
┌──────────────┬─────────┐
│ EmployeeName │ Salary  │
├──────────────┼─────────┤
│ Raj          │ 55000   │
│ Priya        │ 45000   │
│ Amit         │ 60000   │
└──────────────┴─────────┘

Other columns (ID, Department, etc.) not shown
```

**Example 2 - Projection with Duplicate Elimination**:
```
Find all departments employees belong to

Algebra: π Department (EMPLOYEE)

Original data (with duplicates):
┌──────────────┐
│ Department   │
├──────────────┤
│ IT           │
│ IT           │
│ HR           │
│ IT           │
│ Finance      │
└──────────────┘

Result (duplicates removed):
┌──────────────┐
│ Department   │
├──────────────┤
│ IT           │
│ HR           │
│ Finance      │
└──────────────┘
```

**SQL Equivalent**:
```sql
SELECT EmployeeName, Salary FROM Employees;

SELECT DISTINCT Department FROM Employees;
```

### 3. Union (∪)

**Definition**: Combines tuples from two compatible relations, removing duplicates.

**Syntax**:
```
Relation1 ∪ Relation2
```

**Requirements (Union Compatibility)**:
1. Both relations must have same degree (number of attributes)
2. Corresponding attributes must have same domain
3. Attributes should be in same order

**Characteristics**:
- Produces relation with same attributes
- Duplicates automatically removed
- Cardinality = sum of both (minus common tuples)
- Commutative: R ∪ S = S ∪ R

**Example**:
```
Find IDs of all students and faculty members

Relation 1 (STUDENTS):
┌────────────┬──────────────┐
│ ID         │ Name         │
├────────────┼──────────────┤
│ 101        │ Raj          │
│ 102        │ Priya        │
└────────────┴──────────────┘

Relation 2 (FACULTY):
┌────────────┬──────────────┐
│ ID         │ Name         │
├────────────┼──────────────┤
│ 201        │ Prof. A      │
│ 202        │ Prof. B      │
└────────────┴──────────────┘

STUDENTS ∪ FACULTY:
┌────────────┬──────────────┐
│ ID         │ Name         │
├────────────┼──────────────┤
│ 101        │ Raj          │
│ 102        │ Priya        │
│ 201        │ Prof. A      │
│ 202        │ Prof. B      │
└────────────┴──────────────┘
```

**SQL Equivalent**:
```sql
SELECT StudentID AS ID, StudentName AS Name FROM Students
UNION
SELECT FacultyID, FacultyName FROM Faculty;
```

### 4. Intersection (∩)

**Definition**: Returns tuples that appear in both relations.

**Syntax**:
```
Relation1 ∩ Relation2
```

**Requirements**: Same as Union (union compatible)

**Characteristics**:
- Returns only common tuples
- Cardinality = min(cardinality1, cardinality2)
- Commutative: R ∩ S = S ∩ R

**Example**:
```
Find IDs of people who are both students and employees

STUDENTS_ID: {101, 102, 103, 104}
EMPLOYEES_ID: {102, 104, 105, 106}

STUDENTS_ID ∩ EMPLOYEES_ID: {102, 104}

(Only Raj and Amit are both students and employees)
```

**SQL Equivalent**:
```sql
SELECT StudentID FROM Students
INTERSECT
SELECT EmployeeID FROM Employees;
```

### 5. Difference (–)

**Definition**: Returns tuples in first relation but not in second relation.

**Syntax**:
```
Relation1 – Relation2
```

**Requirements**: Same as Union (union compatible)

**Characteristics**:
- Not commutative: R – S ≠ S – R
- Cardinality = variable (≤ cardinality1)
- A – A = ∅ (empty set)

**Example**:
```
Find students who are NOT employees

STUDENTS_ID: {101, 102, 103, 104}
EMPLOYEES_ID: {102, 104, 105, 106}

STUDENTS – EMPLOYEES:
Result: {101, 103}

(Raj and Priya are students but not employees)

EMPLOYEES – STUDENTS:
Result: {105, 106}

(Different result, not commutative)
```

**SQL Equivalent**:
```sql
SELECT StudentID FROM Students
MINUS (or EXCEPT in SQL Server)
SELECT EmployeeID FROM Employees;
```

### 6. Cartesian Product (×)

**Definition**: Combines every tuple from first relation with every tuple from second relation.

**Syntax**:
```
Relation1 × Relation2
```

**Characteristics**:
- Creates all possible combinations
- Cardinality = (cardinality1) × (cardinality2)
- Degree = (degree1) + (degree2)
- Usually followed by selection to get meaningful results

**Example**:
```
Create all possible (Student, Course) combinations

STUDENTS:                    COURSES:
┌──────┬──────┐            ┌──────┬────────┐
│ SID  │ Name │            │ CID  │ Name   │
├──────┼──────┤            ├──────┼────────┤
│ 101  │ Raj  │            │ C1   │ Math   │
│ 102  │ Priya│            │ C2   │ Physics│
└──────┴──────┘            └──────┴────────┘

STUDENTS × COURSES:
┌──────┬──────┬──────┬────────┐
│ SID  │ Name │ CID  │ Name   │
├──────┼──────┼──────┼────────┤
│ 101  │ Raj  │ C1   │ Math   │
│ 101  │ Raj  │ C2   │ Physics│
│ 102  │Priya │ C1   │ Math   │
│ 102  │Priya │ C2   │ Physics│
└──────┴──────┴──────┴────────┘

Cardinality = 2 × 2 = 4
Degree = 2 + 2 = 4
```

**Why it's useful**: Often used with Selection to find meaningful relationships

**SQL Equivalent**:
```sql
SELECT * FROM Students, Courses;
-- or
SELECT * FROM Students CROSS JOIN Courses;
```

### 7. Join (⨝)

**Definition**: Combines tuples from two relations based on a condition (usually equality on common attributes).

**Syntax**:
```
Relation1 ⨝condition Relation2
```

**Purpose**: More efficient way to combine related data (instead of Cartesian product + Selection)

#### Theta Join (θ-join)

**Definition**: Join with any comparison operator (=, <, >, ≤, ≥, <>)

**Syntax**:
```
R1 ⨝θ R2  where θ is any condition
```

**Example**:
```
Find combinations where employee salary > department budget

Algebra: EMPLOYEE ⨝ Salary > Budget DEPARTMENT
```

#### Equi-join

**Definition**: Special case of theta join where condition is equality.

**Syntax**:
```
R1 ⨝ R1.Key = R2.ForeignKey R2
```

**Example**:
```
EMPLOYEE ⨝ DeptID = DepartmentID DEPARTMENT

Result combines rows where DeptID matches DepartmentID
```

#### Natural Join

**Definition**: Equi-join where we join on common attributes automatically and remove duplicate columns.

**Notation**:
```
R1 * R2
```

**Characteristics**:
- Automatically finds common attributes
- Removes duplicate columns
- Most commonly used join

**Example**:
```
EMPLOYEE * DEPARTMENT

Common attribute: DepartmentID

Result:
┌────────────┬──────────────┬─────────┬──────────────┬────────────┐
│EmployeeID │EmployeeName  │ Salary  │DepartmentID  │DeptName    │
├────────────┼──────────────┼─────────┼──────────────┼────────────┤
│ 101        │ Raj          │ 55000   │ 1            │ IT         │
│ 102        │ Priya        │ 45000   │ 2            │ HR         │
│ 103        │ Amit         │ 60000   │ 1            │ IT         │
└────────────┴──────────────┴─────────┴──────────────┴────────────┘

(DepartmentID column appears once)
```

**SQL Equivalent**:
```sql
SELECT * FROM Employees
INNER JOIN Departments ON Employees.DepartmentID = Departments.DepartmentID;

SELECT * FROM Employees
NATURAL JOIN Departments;  -- Automatic on DepartmentID
```

## Combining Operations (Compositional Approach)

Operations can be combined to form complex queries.

### Example: Multi-step Query

**Problem**: Find names and salaries of all employees in IT department earning more than 50,000

**Solution 1 - Step by step**:
```
Step 1: σ Department='IT' (EMPLOYEE)
        Filter to IT department only

Step 2: σ Salary > 50000 (result of step 1)
        Filter to salary > 50,000

Step 3: π EmployeeName, Salary (result of step 2)
        Select only name and salary
```

**Solution 2 - Single expression (combined)**:
```
π EmployeeName, Salary (
    σ Department='IT' ∧ Salary > 50000 (EMPLOYEE)
)
```

**SQL Equivalent**:
```sql
SELECT EmployeeName, Salary
FROM Employees
WHERE Department = 'IT' AND Salary > 50000;
```

### Example: Join with Projection and Selection

**Problem**: Find course names taken by student "Raj"

**Solution**:
```
π CourseName (
    σ StudentName='Raj' (
        STUDENT * ENROLLMENT * COURSE
    )
)
```

**SQL Equivalent**:
```sql
SELECT DISTINCT CourseName
FROM Courses
WHERE CourseID IN (
    SELECT CourseID FROM Enrollment
    WHERE StudentID IN (
        SELECT StudentID FROM Students WHERE StudentName = 'Raj'
    )
)
-- or with JOIN
SELECT DISTINCT c.CourseName
FROM Courses c
INNER JOIN Enrollment e ON c.CourseID = e.CourseID
INNER JOIN Students s ON e.StudentID = s.StudentID
WHERE s.StudentName = 'Raj';
```

## Advantages of Relational Algebra

1. **Formal Foundation**: Mathematical basis for optimization
2. **Query Equivalence**: Can prove two queries are equivalent
3. **Optimization Opportunities**: Can reorder operations for efficiency
4. **Completeness**: Can express most practical queries

## Limitations of Relational Algebra

1. **Doesn't Support Aggregation**: Can't compute SUM, AVG, COUNT
2. **Complex Syntax**: Not user-friendly compared to SQL
3. **Verbose**: Requires multiple steps for simple queries

## Visual Summary

```
Basic Operations:

Selection:        Projection:       Union:
┌────┐           ┌────┐            R1        R2
│ ██ │ (filters  │ ██ │ (filters   ├──────────┤
│ ██ │  rows)    │ ██ │  columns)  │    ▓     │
│    │           │    │            └──────────┘
└────┘           └────┘

Intersection:     Difference:       Cartesian Product:
R1        R2      R1        R2      R1    ×    R2
├──────────┤      ├──────────┤      ┌──────────┐
│    ▓     │      │    ▓     │      │ ▓▓▓▓▓▓▓  │
└──────────┘      └──────────┘      │ ▓▓▓▓▓▓▓  │
(Common)          (Exclusive)        └──────────┘
                                     (All combinations)
```

## Exam Notes

- **Define Clearly**: Specify whether procedural/declarative and what it does
- **Operations**: Write symbol, meaning, syntax, and one concrete example for each
- **Cardinality Effects**: Always mention how degree/cardinality changes
- **SQL Equivalents**: Include SQL for each major operation
- **Complex Queries**: Show how operations are composed/combined
- **Limitations**: Mention aggregation not supported
- **Join Types**: Explain theta, equi, and natural joins with examples
- **Practical Use**: Connect to real database scenarios
