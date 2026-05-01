# 📘 UNIT–II: INTRODUCTION TO THE RELATIONAL MODEL (DETAILED THEORY)

## 1. 📊 RELATIONAL MODEL – CONCEPTUAL UNDERSTANDING

### 🔹 Definition

The Relational Model is a logical data model that represents data as relations (tables) consisting of rows and columns. It is based on set theory and predicate logic, making it mathematically strong and formally defined.

### 🔹 Why Relational Model is Important

Before this model, databases were:

- Complex (hierarchical/network models)
- Hard to maintain
- Dependent on programs

The relational model introduced:

- Simplicity (table format)
- Data independence
- Formal query systems
- Standardization (SQL)

### 🔹 Structure of a Relation

```
Relation (Table)
   ↓
Attributes (Columns)
   ↓
Tuples (Rows)
```

**Key Insight**

A relation is not just a table, it has strict properties:

- No duplicate rows
- Order of rows does not matter
- Order of columns does not matter
- Values are atomic (no multi-values)

### 🔹 Core Terminology

1. **Relation**
   - A relation is a table representing an entity or relationship.

2. **Tuple**
   - A tuple is a single row representing one record.

3. **Attribute**
   - An attribute is a column describing a property.

4. **Domain**
   - A domain defines valid values for an attribute.

   👉 **Example:** Age → only integers between 18–60

5. **Degree**
   - Number of attributes (columns).

6. **Cardinality**
   - Number of tuples (rows).

### 🔹 Conceptual Understanding

- Relation = Set of tuples
- Tuple = Set of attribute values
- Attribute = Named column with domain

---

## 2. 🔐 INTEGRITY CONSTRAINTS (VERY IMPORTANT THEORY)

Integrity constraints ensure that database remains correct and consistent.

### 🔹 Why Constraints are Needed

Without constraints:

- Duplicate records occur
- Invalid data is inserted
- Relationships break

👉 Constraints enforce rules at database level

### 🔹 Types of Constraints

1. **Domain Constraint**
   - Ensures attribute values come from a valid domain.

   ✔ Prevents invalid data
   ✔ Based on datatype and conditions

   👉 **Example:** Age cannot be negative

2. **Entity Integrity Constraint**

   **Rule:**
   - Primary key must be:
     - Unique
     - Not NULL

   👉 **Why important?**
   - Because every entity must be uniquely identifiable.

3. **Referential Integrity Constraint**

   **Rule:**
   - Foreign key must:
     - Match primary key of another table
     - Or be NULL

   👉 Ensures valid relationships

   **Conceptual Diagram**

   ```
   DEPARTMENT (DeptID)
           ↑
           │ (Foreign Key)
   STUDENT (DeptID)
   ```

   👉 Prevents:
   - Orphan records
   - Invalid references

4. **Key Constraint**
   - Ensures uniqueness of data using keys.

5. **NOT NULL Constraint**
   - Ensures attribute must have a value.

6. **UNIQUE Constraint**
   - Ensures no duplicate values.

7. **CHECK Constraint**
   - Enforces custom conditions.

### 🔹 Conceptual Summary

Integrity Constraints = Rules that protect database correctness

✔ Maintain accuracy
✔ Maintain consistency
✔ Enforce business rules

---

## 3. 🔑 KEYS IN RELATIONAL MODEL (CORE THEORY)

### 🔹 Why Keys Are Needed

- Identify tuples uniquely
- Establish relationships
- Prevent redundancy

### 🔹 Types of Keys

1. **Super Key**
   - Any attribute set that uniquely identifies a tuple.

   👉 May contain extra attributes

2. **Candidate Key**
   - Minimal super key.

   👉 No unnecessary attributes

3. **Primary Key**
   - Chosen candidate key.

   ✔ Unique
   ✔ Not NULL

4. **Alternate Key**
   - Candidate keys not selected as primary.

5. **Composite Key**
   - Key formed using multiple attributes.

   👉 Used when single attribute is insufficient

6. **Foreign Key**
   - Attribute referencing another table’s primary key.

### 🔹 Key Hierarchy

```
Super Key
   ↓
Candidate Key
   ↓
Primary Key
   ↓
Foreign Key (links relations)
```

### 🔹 Conceptual Insight

Keys ensure:

- Uniqueness
- Connectivity between tables
- Efficient querying

---

## 4. 📐 RELATIONAL ALGEBRA (PROCEDURAL QUERY LANGUAGE)

### 🔹 Definition

Relational algebra is a procedural query language that tells **HOW** to retrieve data.

### 🔹 Important Concept

It works through operations on relations.

### 🔹 Fundamental Operations

1. **Selection (σ)**
   - Filters rows.

   👉 **Concept:** Apply condition

2. **Projection (π)**
   - Selects columns.

   👉 **Concept:** Reduce attributes

3. **Union (∪)**
   - Combines tuples of same structure.

4. **Intersection (∩)**
   - Returns common tuples.

5. **Difference (−)**
   - Returns tuples in one relation but not another.

6. **Cartesian Product (×)**
   - Combines all possible tuples.

   👉 **Concept:** All combinations

7. **Join (⨝)**
   - Combines related data from tables.

   👉 Most important operation

### 🔹 Conceptual Flow

```
Input Relations → Apply Operations → Output Relation
```

### 🔹 Key Insight

Relational algebra:

- Forms foundation of SQL
- Used internally by DBMS
- Enables query optimization

---

## 5. 🧠 RELATIONAL CALCULUS (NON-PROCEDURAL)

### 🔹 Definition

Relational calculus is a declarative language that specifies **WHAT** data is required, not how.

### 🔹 Types

1. **Tuple Relational Calculus (TRC)**
   - Focuses on tuples.

2. **Domain Relational Calculus (DRC)**
   - Focuses on attribute values.

### 🔹 Key Difference from Algebra

| **Feature** | **Algebra** | **Calculus** |
|-------------|-------------|--------------|
| **Type**    | Procedural  | Declarative  |
| **Focus**   | HOW         | WHAT         |

### 🔹 Important Concept

Calculus is based on:

- Predicate logic
- Quantifiers (∃, ∀)

### 🔹 Safe vs Unsafe Expressions

- **Safe Expression**
  - Produces finite results.

- **Unsafe Expression**
  - Produces infinite or undefined results.

### 🔹 Real Insight

Relational calculus is:

- Theoretical foundation of SQL
- More expressive logically
- Less practical for direct use

---

## 6. 🗄️ SQL – PRACTICAL IMPLEMENTATION

### 🔹 Definition

SQL is a standard query language used to interact with relational databases.

### 🔹 Nature of SQL

- Declarative
- Based on algebra + calculus
- User-friendly

### 🔹 Categories

1. **DDL**
   - Defines structure.

2. **DML**
   - Manipulates data.

3. **DQL**
   - Retrieves data (SELECT).

4. **DCL**
   - Controls access.

5. **TCL**
   - Manages transactions.

### 🔹 Conceptual Execution Flow

```
FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY
```

### 🔹 Important Concepts

- **WHERE Clause**
  - Filters rows

- **GROUP BY**
  - Groups data

- **HAVING**
  - Filters groups

- **ORDER BY**
  - Sorts results

**Aggregate Functions**
- COUNT
- SUM
- AVG

### 🔹 Key Insight

SQL:

- Is industry standard
- Hides complexity of relational algebra
- Allows complex queries in simple form

---

## 7. 🔍 TYPES OF SQL QUERIES

### 🔹 1. Simple Queries

- Basic retrieval.

### 🔹 2. Conditional Queries

- Use conditions.

### 🔹 3. Join Queries

- Combine tables.

### 🔹 4. Aggregate Queries

- Perform calculations.

### 🔹 5. Nested Queries

- Query inside query.

### 🔹 6. View Queries

- Use virtual tables.

### 🔹 7. Union Queries

- Combine results.

### 🔹 Key Understanding

Real-world queries often combine:

- JOIN + GROUP BY + HAVING + SUBQUERY

---

## 8. 🧩 LOGICAL DATABASE DESIGN

### 🔹 Definition

Logical design converts ER model into relational schema.

### 🔹 Steps

- Entities → Tables  
- Attributes → Columns  
- Relationships → Foreign Keys  
- Constraints → Rules

### 🔹 Goal

- Remove redundancy
- Ensure consistency
- Improve efficiency

### 🔹 Example Concept

```
Student — Enrolls — Course
↓
3 tables with keys
```

---

## 9. 👁️ VIEWS (IMPORTANT THEORY)

### 🔹 Definition

A view is a virtual table derived from one or more tables.

### 🔹 Characteristics

- Does not store data physically
- Stores query definition
- Always shows updated data

### 🔹 Advantages

✔ Security  
✔ Simplifies complex queries  
✔ Data abstraction

### 🔹 Types

- Simple view  
- Complex view

---

## 10. 🗑️ ALTERING & DESTROYING TABLES

### 🔹 Operations

- Create  
- Modify  
- Delete

### 🔹 Concepts

- **ALTER**
  - Modify structure

- **DROP**
  - Remove table completely

### 🔹 Important Insight

DDL operations:

- Affect schema
- Are usually irreversible

---

## 🎯 FINAL THEORY SUMMARY

### 🔹 Core Understanding

Relational Model = Tables + Constraints + Keys + Queries

### 🔹 Concept Flow

```
Data → Relations → Constraints → Queries → Results
```

---

## 📘 UNIT–II: IMPORTANT QUESTIONS & ANSWERS (8 MARKS EACH)

❓ Q1. Explain the Relational Model with its basic concepts.
✅ Answer:

The Relational Model is a database model that represents data in the form of relations (tables) consisting of rows and columns. It was proposed by E.F. Codd and is based on set theory and predicate logic.

🔹 Basic Concepts
1. Relation

A relation is a table containing data.

2. Tuple

A tuple is a row representing a single record.

3. Attribute

An attribute is a column representing a property.

4. Domain

A domain is the set of valid values for an attribute.

5. Degree

Number of attributes in a relation.

6. Cardinality

Number of tuples in a relation.

🔹 Properties of Relational Model
No duplicate tuples
Atomic values (no multi-valued attributes)
Order of rows and columns does not matter
🔹 Advantages
Simple structure
Data independence
Easy querying using SQL
🔹 Conclusion

The relational model provides a simple, flexible, and mathematically strong way to manage data.

❓ Q2. Explain different types of integrity constraints.
✅ Answer:

Integrity constraints are rules that ensure accuracy and consistency of data in a database.

🔹 Types of Constraints
1. Domain Constraint

Ensures values belong to a valid domain.

👉 Example: Age must be ≥ 18

2. Entity Integrity Constraint

Primary key must:

Be unique
Not be NULL

👉 Ensures each record is identifiable

3. Referential Integrity Constraint

Foreign key must match a primary key in another table or be NULL.

👉 Prevents invalid references

4. Key Constraint

Ensures uniqueness of keys.

5. NOT NULL Constraint

Attribute cannot have NULL value.

6. UNIQUE Constraint

Ensures no duplicate values.

7. CHECK Constraint

Ensures condition is satisfied.

🔹 Importance
Maintains correctness
Prevents invalid data
Enforces business rules
🔹 Conclusion

Integrity constraints are essential for maintaining data reliability and consistency.

❓ Q3. Explain different types of keys in relational model.
✅ Answer:

Keys are attributes used to uniquely identify tuples and establish relationships.

🔹 Types of Keys
1. Super Key

Set of attributes that uniquely identifies a tuple.

2. Candidate Key

Minimal super key.

3. Primary Key

Selected candidate key.

✔ Unique
✔ Not NULL

4. Alternate Key

Candidate keys not chosen as primary.

5. Composite Key

Combination of multiple attributes.

6. Foreign Key

Attribute referencing primary key of another table.

🔹 Key Hierarchy
Super Key → Candidate Key → Primary Key
🔹 Importance
Ensures uniqueness
Maintains relationships
Supports integrity
🔹 Conclusion

Keys play a crucial role in data identification and relational mapping.

❓ Q4. Explain relational algebra and its operations.
✅ Answer:

Relational algebra is a procedural query language used to retrieve data from relations. It specifies how to perform operations step-by-step.

🔹 Fundamental Operations
1. Selection (σ)

Selects rows based on condition.

2. Projection (π)

Selects specific columns.

3. Union (∪)

Combines tuples of two relations.

4. Intersection (∩)

Returns common tuples.

5. Difference (−)

Returns tuples in one relation but not another.

6. Cartesian Product (×)

Combines all possible tuples.

7. Join (⨝)

Combines related tuples.

🔹 Characteristics
Procedural
Based on set theory
Forms foundation of SQL
🔹 Conclusion

Relational algebra provides a formal and structured way to query data.

❓ Q5. Explain relational calculus and its types.
✅ Answer:

Relational calculus is a non-procedural query language that specifies what data to retrieve rather than how.

🔹 Types
1. Tuple Relational Calculus (TRC)

Works on tuples.

2. Domain Relational Calculus (DRC)

Works on attribute values.

🔹 Key Features
Based on predicate logic
Uses quantifiers (∃, ∀)
Declarative
🔹 Safe vs Unsafe Expressions
Safe → finite results
Unsafe → infinite results
🔹 Conclusion

Relational calculus provides a logical and theoretical foundation for SQL.

❓ Q6. Differentiate between relational algebra and relational calculus.
✅ Answer:
Feature	Relational Algebra	Relational Calculus
Type	Procedural	Non-procedural
Focus	HOW	WHAT
Approach	Step-by-step	Logical expression
Basis	Set theory	Predicate logic
Usage	Internal DBMS	Theoretical foundation
🔹 Explanation

Relational algebra describes how to perform operations, while relational calculus describes what result is needed.

🔹 Conclusion

Both are equivalent in power but differ in approach and expression.

❓ Q7. Explain SQL and its different categories.
✅ Answer:

SQL (Structured Query Language) is used to create, manipulate, and retrieve data in relational databases.

🔹 Categories
1. DDL (Data Definition Language)

Defines structure (CREATE, ALTER, DROP)

2. DML (Data Manipulation Language)

Handles data (INSERT, UPDATE, DELETE)

3. DQL (Data Query Language)

Retrieves data (SELECT)

4. DCL (Data Control Language)

Controls access (GRANT, REVOKE)

5. TCL (Transaction Control Language)

Manages transactions (COMMIT, ROLLBACK)

🔹 Features
Declarative
Standardized
Easy to use
🔹 Conclusion

SQL is the standard language for relational databases.

❓ Q8. Explain different types of SQL queries.
✅ Answer:

SQL queries are used to retrieve and manipulate data.

🔹 Types
1. Simple Query

Retrieves data from one table.

2. Conditional Query

Uses conditions (WHERE).

3. Join Query

Combines multiple tables.

4. Aggregate Query

Uses functions like COUNT, AVG.

5. Nested Query

Query inside another query.

6. View Query

Uses virtual tables.

7. Union Query

Combines results of multiple queries.

🔹 Importance
Handles complex data retrieval
Supports real-world applications
🔹 Conclusion

SQL queries provide powerful mechanisms to extract meaningful data.

❓ Q9. Explain views and their advantages.
✅ Answer:

A view is a virtual table derived from one or more tables.

🔹 Characteristics
Does not store data
Stores query definition
Always reflects updated data
🔹 Advantages
Data security
Simplifies complex queries
Provides abstraction
🔹 Types
Simple view
Complex view
🔹 Conclusion

Views improve security, simplicity, and flexibility.

❓ Q10. Explain logical database design.
✅ Answer:

Logical database design is the process of converting ER model into relational schema.

🔹 Steps
Convert entities into tables
Convert attributes into columns
Define primary keys
Establish foreign keys
Apply constraints
🔹 Goals
Reduce redundancy
Ensure consistency
Improve efficiency
🔹 Example Concept
Student — Enrolls — Course
↓
3 tables with relationships
🔹 Conclusion

Logical design ensures a well-structured and efficient database system.