# Logical Design

## Definition

Logical database design converts an ER model into a relational schema.

## Steps

### 1. Convert Entities Into Relations

Each strong entity becomes a relation.

### 2. Convert Attributes Into Columns

- Simple attribute -> direct column
- Composite attribute -> split into parts
- Multivalued attribute -> separate relation

### 3. Convert Relationships

- `1:1` -> foreign key on one side
- `1:N` -> foreign key on many side
- `M:N` -> separate relation

### 4. Define Keys and Constraints

- Primary key
- Foreign key
- Unique
- Check
- Not null

## Example

```text
ER Model:
Student -- Enrolls -- Course

Logical Schema:
Students(StudentID, StudentName, Email)
Courses(CourseID, CourseName, Credits)
Enrollments(StudentID, CourseID, Semester)
```

## SQL Example

```sql
CREATE TABLE Students (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE
);

CREATE TABLE Courses (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits INT CHECK (Credits BETWEEN 1 AND 6)
);

CREATE TABLE Enrollments (
    StudentID INT,
    CourseID INT,
    Semester VARCHAR(20),
    PRIMARY KEY (StudentID, CourseID, Semester),
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID)
);
```

## Diagram

```text
ER Design -> Relation Mapping -> Constraints -> SQL Schema
```

## Exam Notes

- Always mention mapping rules.
- A many-to-many relationship must become a new table.
- Normalization is usually the next step after logical design.
