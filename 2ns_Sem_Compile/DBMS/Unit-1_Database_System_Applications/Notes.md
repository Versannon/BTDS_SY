# Unit 1: Database System Applications

## Definition

A **Database Management System (DBMS)** is software that stores, organizes, retrieves, and manages data in a controlled manner.

## Why DBMS Was Needed

Traditional file systems had major problems:

- Data redundancy
- Data inconsistency
- Difficult data access
- Poor security
- No proper concurrency control
- Weak backup and recovery support

## File System vs DBMS

| Point | File System | DBMS |
|---|---|---|
| Redundancy | High | Controlled |
| Consistency | Difficult | Better maintained |
| Security | Weak | Stronger access control |
| Query support | Program dependent | SQL based |
| Concurrency | Limited | Supported |
| Backup and recovery | Manual | Systematic |

## Data Models

- **Relational model**: Data stored in tables
- **ER model**: Used for conceptual design
- **Object-based model**: Uses object concepts
- **Semi-structured model**: Flexible structure, common in XML/NoSQL

## Levels of Abstraction

### 1. Physical Level

- Describes how data is stored internally
- Includes files, blocks, indexes, and storage structures

### 2. Logical Level

- Describes what data is stored
- Includes relations, attributes, and relationships

### 3. View Level

- Describes how end users see data
- Different users may see different views

## Data Independence

### Physical Data Independence

Changes in storage structure do not affect the logical schema.

Example:

- Changing sequential storage to indexed storage
- Moving data to another disk

### Logical Data Independence

Changes in logical schema do not affect user views or application programs significantly.

Example:

- Adding a new attribute to a table
- Splitting a table into two related tables

## Structure of DBMS

### Query Processor

- DDL interpreter
- DML compiler
- Query optimizer

### Storage Manager

- Authorization manager
- Integrity manager
- Transaction manager
- File manager
- Buffer manager

## Example

```text
User SQL Query
      |
      v
Query Processor
      |
      v
Storage Manager
      |
      v
Database Files
```

## Exam Notes

- Define DBMS in 1 line first.
- Write 4 to 6 points for file system disadvantages.
- Always draw the three-level abstraction diagram in theory answers.
- Data independence is frequently asked as a short note or 5-mark question.
