# Relational Calculus

## Definition

**Relational Calculus** is a non-procedural query language based on predicate logic and first-order logic. It specifies WHAT data to retrieve without specifying HOW to retrieve it.

### Key Characteristics

1. **Non-Procedural (Declarative)**: Specifies WHAT, not HOW
2. **Based on Predicate Logic**: Uses logical formulas and predicates
3. **Formal Notation**: Mathematical foundation
4. **User-Friendly**: More intuitive than relational algebra
5. **Equivalent to Relational Algebra**: Can express same queries

### Relationship with SQL

```
Relational Calculus (Logical Specification)
         ↓
    (User specifies desired result)
         ↓
SQL Query (WHAT approach)
         ↓
DBMS converts to Algebra operations
         ↓
DBMS optimizes and executes
```

### Procedural vs Non-Procedural

```
Procedural (Algebra):
1. Filter table by condition
2. Select columns
3. Remove duplicates
(User specifies steps)

Non-Procedural (Calculus):
"Give me names and salaries of IT employees earning > 50,000"
(User specifies result, not steps)
```

## Two Types of Relational Calculus

### Type 1: Tuple Relational Calculus (TRC)

**Definition**: Variables in TRC represent tuples (complete rows).

#### General Form of TRC

```
{ t | P(t) }

Where:
  t  = tuple variable
  P(t) = predicate/condition on t
  |  = "such that"
  
Read as: "Get all tuples t such that predicate P(t) is true"
```

#### Components

##### Tuple Variable

- Represents a tuple (entire row)
- Ranges over a relation
- Denoted by lowercase letters (t, t1, t2, etc.)

##### Predicate (P(t))

- Logical formula that must be satisfied
- Combines conditions with ∧ (AND), ∨ (OR), ¬ (NOT)
- Includes:
  - Comparisons: t.Attribute = value
  - Range tests: t ∈ Relation
  - Logical operators

##### Quantifiers

- **∃t** (Existential): "there exists a tuple t"
- **∀t** (Universal): "for all tuples t"

#### TRC Syntax Rules

```
Simple form:       { t | t ∈ Relation ∧ Condition }
With projection:   { t.Attr1, t.Attr2 | Condition }
With quantifiers:  { t | ∃s (Condition) }
                   { t | ∀s (Condition) }
```

#### TRC Examples

**Example 1: Simple Selection**

**Problem**: Find all employees earning more than 50,000

**TRC Query**:
```
{ t | t ∈ EMPLOYEE ∧ t.Salary > 50000 }

Read as: "Get all tuples t from EMPLOYEE where salary > 50,000"
```

**Explanation**:
- `t ∈ EMPLOYEE`: t is tuple from EMPLOYEE relation
- `t.Salary > 50000`: Salary attribute of t > 50,000
- `∧`: AND (both conditions must be true)

**SQL Equivalent**:
```sql
SELECT * FROM Employees WHERE Salary > 50000;
```

**Example 2: Projection (Specific Columns)**

**Problem**: Find names and salaries of employees in IT department

**TRC Query**:
```
{ t.EmployeeName, t.Salary | t ∈ EMPLOYEE ∧ t.Department = 'IT' }

Read as: "Get EmployeeName and Salary from EMPLOYEE where Department is IT"
```

**SQL Equivalent**:
```sql
SELECT EmployeeName, Salary 
FROM Employees 
WHERE Department = 'IT';
```

**Example 3: With Existential Quantifier**

**Problem**: Find names of students who have enrolled in some course

**Relations**:
```
STUDENT (StudentID, StudentName)
ENROLLMENT (StudentID, CourseID)
```

**TRC Query**:
```
{ t.StudentName | t ∈ STUDENT ∧ ∃e (e ∈ ENROLLMENT ∧ e.StudentID = t.StudentID) }

Read as: "Get StudentName from STUDENT where there exists an ENROLLMENT 
          record with same StudentID"
```

**Explanation**:
- Main tuple variable: t (from STUDENT)
- Secondary tuple variable: e (from ENROLLMENT)
- `∃e`: "there exists enrollment e"
- `e.StudentID = t.StudentID`: Link through StudentID
- Returns students who have at least one enrollment

**SQL Equivalent**:
```sql
SELECT DISTINCT s.StudentName
FROM Students s
WHERE EXISTS (
    SELECT 1 FROM Enrollment e
    WHERE e.StudentID = s.StudentID
);
```

**Example 4: With Universal Quantifier**

**Problem**: Find names of students who have enrolled in ALL courses

**TRC Query**:
```
{ t.StudentName | t ∈ STUDENT ∧ ∀c (c ∈ COURSE → ∃e (e ∈ ENROLLMENT ∧ 
  e.StudentID = t.StudentID ∧ e.CourseID = c.CourseID)) }

Read as: "Get StudentName where for all courses c, there exists enrollment 
         for that course and student"
```

**Explanation**:
- `∀c`: "for all courses"
- `→`: logical implication
- Student must have enrollment for every course

**SQL Equivalent**:
```sql
SELECT s.StudentName
FROM Students s
WHERE NOT EXISTS (
    SELECT 1 FROM Courses c
    WHERE NOT EXISTS (
        SELECT 1 FROM Enrollment e
        WHERE e.StudentID = s.StudentID
        AND e.CourseID = c.CourseID
    )
);
```

**Example 5: Complex Condition with AND/OR**

**Problem**: Find employees in IT department earning > 50,000 or in HR department earning > 40,000

**TRC Query**:
```
{ t | t ∈ EMPLOYEE ∧ 
      ((t.Department = 'IT' ∧ t.Salary > 50000) ∨ 
       (t.Department = 'HR' ∧ t.Salary > 40000)) }
```

**SQL Equivalent**:
```sql
SELECT * FROM Employees
WHERE (Department = 'IT' AND Salary > 50000)
   OR (Department = 'HR' AND Salary > 40000);
```

### Type 2: Domain Relational Calculus (DRC)

**Definition**: Variables in DRC represent attribute values (domain values) rather than entire tuples.

#### General Form of DRC

```
{ <x, y, z, ...> | P(x, y, z, ...) }

Where:
  x, y, z = domain variables (individual attribute values)
  P(...)  = predicate on domain variables
  < ... > = ordered list of domain variables to retrieve
  
Read as: "Get values x, y, z such that predicate P is true"
```

#### DRC Syntax Rules

```
Simple form:       { <x, y> | Relation(x, y, ...) ∧ Condition }
With specific DB:  { <name, salary> | EMPLOYEE(id, name, salary) ∧ 
                     salary > 50000 }
With quantifiers:  { <x> | ∃y (Relation(x, y)) }
```

#### DRC Examples

**Example 1: Simple Query**

**Problem**: Find names and salaries of all employees

**Relation**: EMPLOYEE(EmployeeID, EmployeeName, Salary)

**DRC Query**:
```
{ <n, s> | EMPLOYEE(id, n, s) }

Read as: "Get values n and s (name and salary) from EMPLOYEE records"
```

**Explanation**:
- `<n, s>`: Result will contain name and salary
- `EMPLOYEE(id, n, s)`: Refers to EMPLOYEE relation with attributes
- All records returned (no condition)

**SQL Equivalent**:
```sql
SELECT EmployeeName, Salary FROM Employees;
```

**Example 2: With Condition**

**Problem**: Find names of employees earning more than 50,000

**DRC Query**:
```
{ <n> | EMPLOYEE(id, n, s) ∧ s > 50000 }

Read as: "Get name n from EMPLOYEE records where salary s > 50,000"
```

**Explanation**:
- `<n>`: Only name in result
- `EMPLOYEE(id, n, s)`: Three domain variables for three attributes
- `s > 50000`: Filter condition on salary domain

**SQL Equivalent**:
```sql
SELECT EmployeeName FROM Employees WHERE Salary > 50000;
```

**Example 3: With Existential Quantifier (Join)**

**Problem**: Find names of students enrolled in courses

**Relations**:
```
STUDENT(StudentID, StudentName)
ENROLLMENT(StudentID, CourseID)
```

**DRC Query**:
```
{ <n> | STUDENT(id, n) ∧ ∃cid (ENROLLMENT(id, cid)) }

Read as: "Get name n from STUDENT where there exists a CourseID in 
         ENROLLMENT for that StudentID"
```

**Explanation**:
- `<n>`: Student name in result
- `STUDENT(id, n)`: Domain variables for ID and name
- `∃cid`: Existential quantifier for CourseID (not in result)
- `ENROLLMENT(id, cid)`: Records from ENROLLMENT with same StudentID

**SQL Equivalent**:
```sql
SELECT DISTINCT StudentName
FROM Students s
WHERE EXISTS (
    SELECT 1 FROM Enrollment e
    WHERE e.StudentID = s.StudentID
);
```

**Example 4: Comparison Between TRC and DRC**

**Same Query: "Find employee names earning > 50,000"**

**TRC Version**:
```
{ t.EmployeeName | t ∈ EMPLOYEE ∧ t.Salary > 50000 }

(Focus: Tuple t and its attributes)
```

**DRC Version**:
```
{ <n> | EMPLOYEE(id, n, s) ∧ s > 50000 }

(Focus: Domain values n and s)
```

**SQL**:
```sql
SELECT EmployeeName FROM Employees WHERE Salary > 50000;
```

All three express same query - different approaches!

## Safe and Unsafe Expressions

Not all calculus expressions are meaningful or feasible to implement.

### Safe Expression

**Definition**: An expression is safe if it guarantees producing finite, meaningful results.

**Characteristics**:
- Produces only domain values that appear in database
- Finite result set
- Can be practically implemented

**Example of Safe Expression**:
```
{ <n> | EMPLOYEE(id, n, s) ∧ s > 50000 }

Safe because:
- Only retrieves actual name values from EMPLOYEE
- Condition limits to existing employees with s > 50000
- Result is finite
```

### Unsafe Expression

**Definition**: An expression that may produce infinite results or values not in database.

**Characteristics**:
- May produce values not in database
- Can't be feasibly implemented
- Results might be infinite

**Example of Unsafe Expression**:
```
{ <n> | ¬(EMPLOYEE(id, n, s)) }

Unsafe because:
- Asks for all names NOT in EMPLOYEE
- Infinite possibilities (any name not in database)
- Infinite result set

Alternative:
{ <n> | EMPLOYEE(id, n, s) ∧ s > 50000 }
(This is safe - bounded to employees)
```

**Another Unsafe Example**:
```
{ <x> | x > 100 }

Unsafe because:
- No relation specified
- Could return infinite values {101, 102, 103, ...}
- Not bounded to database

Safe version:
{ <s> | EMPLOYEE(id, n, s) ∧ s > 100 }
(Bounded to actual employee salaries)
```

## Difference Between TRC and DRC

| Aspect | TRC | DRC |
|--------|-----|-----|
| **Variable Type** | Tuple variable (entire row) | Domain variable (single value) |
| **Notation** | { t \| condition } | { <x, y> \| condition } |
| **Focus** | Whole tuple properties | Individual attribute values |
| **Example** | t ∈ EMPLOYEE | EMPLOYEE(id, name, sal) |
| **Intuition** | "Get rows where..." | "Get values where..." |
| **Quantifiers** | ∃t, ∀t | ∃x, ∀x |
| **Complexity** | Easier for beginners | More precise for complex queries |

## Relationship to SQL

SQL is based on relational calculus (non-procedural):

```
Relational Calculus        SQL
─────────────────          ───
{ t \| condition }         SELECT ... FROM ... WHERE condition
{ t.A, t.B \| ... }       SELECT A, B FROM ... WHERE ...
∃ quantifier               EXISTS subquery
∀ quantifier               NOT EXISTS (negative existential)
Relation membership        FROM clause
```

## Limitations of Relational Calculus

1. **No Aggregation**: Can't compute SUM, COUNT, AVG
2. **No Grouping**: Can't use GROUP BY concepts
3. **Complex Notation**: Not user-friendly for non-mathematicians
4. **Unsafe Expressions**: Need to ensure safety

## Practical Comparison: Algebra vs Calculus

**Problem**: Find salaries of employees in IT department earning > 50,000

**Relational Algebra** (HOW - procedural):
```
Step 1: σ Department='IT' (EMPLOYEE)           -- Filter by department
Step 2: σ Salary > 50000 (Result1)             -- Filter by salary
Step 3: π Salary (Result2)                     -- Select column
```

**Relational Calculus** (WHAT - non-procedural):
```
{ t.Salary | t ∈ EMPLOYEE ∧ t.Department = 'IT' ∧ t.Salary > 50000 }
```

**SQL** (Industry standard):
```sql
SELECT Salary
FROM Employees
WHERE Department = 'IT' AND Salary > 50000;
```

## Exam Notes

1. **Distinguish TRC and DRC**: Explain tuple vs domain variables clearly
2. **General Form**: Write syntax before examples
3. **Examples**: Provide 3-4 examples with SQL equivalents
4. **Quantifiers**: Explain ∃ (exists) and ∀ (for all) with context
5. **Safety**: Mention safe/unsafe expressions and why they matter
6. **Comparison**: Show TRC vs DRC side-by-side for same query
7. **Relationship to SQL**: Connect calculus concepts to SQL constructs
8. **Real Examples**: Use practical database scenarios
9. **Complexity**: Note that calculus is not user-friendly but theoretically important
