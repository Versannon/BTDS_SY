# ER Model

## Definition

The **Entity Relationship (ER) Model** is a conceptual design model used to represent data, attributes, and relationships before creating database tables.

## Main Components

### Entity

An entity is a real-world object or concept.

Examples:

- Student
- Department
- Course
- Employee

### Attribute

An attribute describes a property of an entity.

Example:

- `Student(StudentID, Name, Email, Age)`

### Relationship

A relationship shows association between entities.

Example:

- Student `ENROLLS IN` Course
- Employee `WORKS IN` Department

## Types of Attributes

- **Simple**: Cannot be divided further, for example `Age`
- **Composite**: Can be divided, for example `Name -> FirstName, LastName`
- **Derived**: Calculated from another attribute, for example `Age` from `DOB`
- **Multivalued**: Can have many values, for example `PhoneNumbers`
- **Key attribute**: Uniquely identifies an entity

## Cardinality Ratios

- **1:1** One-to-one
- **1:N** One-to-many
- **M:N** Many-to-many

## Strong and Weak Entity

### Strong Entity

- Has its own primary key
- Exists independently

Example:

- `Department(DepartmentID, DepartmentName)`

### Weak Entity

- Does not have a complete key of its own
- Depends on a strong entity

Example:

- `Dependent` depends on `Employee`

## Example ER Design

```text
[STUDENT] ----< ENROLLMENT >---- [COURSE]
   |                                  |
 StudentID (PK)                    CourseID (PK)
 Name                              CourseName
 Email                             Credits
```

## Conversion to Tables

### Entity to Relation

Each entity becomes a table.

### Relationship to Foreign Key or Separate Table

- `1:N` relationship: foreign key on the many side
- `M:N` relationship: create a separate relation

### Example

```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50) NOT NULL
);

CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL
);

CREATE TABLE Enrollments (
    StudentID INT,
    CourseID INT,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);
```

## Exam Notes

- Define entity, attribute, and relationship separately.
- Mention attribute types with one example each.
- Draw at least one ER diagram in answers.
- Write the rule for converting `M:N` relationships into a separate relation.
