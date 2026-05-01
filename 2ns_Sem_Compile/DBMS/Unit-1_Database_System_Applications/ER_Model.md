# Entity-Relationship (ER) Model

## Definition and Purpose

The **Entity-Relationship (ER) Model** is a high-level conceptual data model used to describe the structure of a database at the conceptual level. It bridges the gap between real-world requirements and the relational database model.

### Purpose of ER Model

1. **Understand Requirements**: Visualize what data needs to be stored
2. **Communication**: Facilitate discussion between database designer and stakeholders
3. **Design Blueprint**: Create a logical design before implementation
4. **Documentation**: Provide clear database architecture documentation
5. **Prevent Errors**: Identify issues early before coding

### ER Model Development Process

```
Real World Problem
        ↓
Identify Entities & Relationships
        ↓
Create ER Diagram
        ↓
Validate with Stakeholders
        ↓
Convert to Relational Schema
        ↓
Implement in DBMS
```

## Main Components of ER Model

### Component 1: Entity

An **entity** is a thing or object in the real world that has an independent existence and about which we want to store information.

#### Characteristics of an Entity

- Has a distinct, independent existence
- Can be identified uniquely
- Describes a class of objects, not individual instances
- Examples: Student, Employee, Department, Course

#### Types of Entities

**Strong Entity**: 
- Has its own primary key
- Exists independently
- Example: STUDENT with StudentID as PK
- Represented by single rectangle

**Weak Entity**:
- Does not have its own primary key
- Depends on a strong entity for its existence
- Identified by combination of own attributes and related entity's key
- Example: DEPENDENT depends on EMPLOYEE
- Represented by double rectangle

#### Entity Notation

```
Regular Entity          Weak Entity
┌──────────────┐       ╔══════════════╗
│   STUDENT    │       ║  DEPENDENT   ║
└──────────────┘       ╚══════════════╝
```

#### Real-World Entity Examples

| Entity | Real-World Object | Key Identifier |
|--------|-------------------|-----------------|
| EMPLOYEE | A person working in organization | EmployeeID |
| STUDENT | A person enrolled in college | StudentID |
| COURSE | A subject offered by college | CourseID |
| DEPARTMENT | An organizational unit | DepartmentID |
| PROJECT | A work assignment | ProjectID |

### Component 2: Attribute

An **attribute** is a property or characteristic of an entity. It describes what information we store about the entity.

#### Types of Attributes

##### Simple (Atomic) Attribute
- Cannot be divided further
- Stores a single value
- Examples: Age, StudentID, Salary, Email

```
EMPLOYEE entity has simple attributes:
  ├─ EmployeeID
  ├─ Age
  └─ Salary
```

##### Composite Attribute
- Can be divided into smaller sub-attributes
- Stores multiple related values
- Example: Address (Street, City, State, ZipCode), Name (FirstName, LastName)

```
EMPLOYEE entity with composite attributes:
  └─ Address
      ├─ Street
      ├─ City
      ├─ State
      └─ ZipCode

  └─ Name
      ├─ FirstName
      └─ LastName
```

**Advantages of Composite Attributes**:
- Can query individual parts (e.g., find employees in Mumbai)
- Natural grouping of related attributes
- Better data organization

##### Multivalued Attribute
- Can have multiple values for a single entity
- Example: PhoneNumbers (a person can have multiple phone numbers), Email addresses, Qualifications

```
EMPLOYEE entity:
  └─ PhoneNumbers {9876543210, 9987654321, 9876543211}
  └─ Qualifications {B.Tech, M.Tech, MBA}
```

**Storage Note**: Multivalued attributes are typically stored in separate tables during normalization

##### Derived Attribute
- Not stored in database but calculated from other attributes
- Recalculated as needed
- Example: Age (derived from DateOfBirth), Experience (derived from JoiningDate)

```
EMPLOYEE entity:
  Simple Attributes:      DateOfBirth, Salary
  Derived Attribute:      Age = CurrentYear - YearOfBirth
                         (calculated when needed)
```

**Notation**: Derived attributes often shown in dashed oval

##### Key Attribute
- Uniquely identifies an entity instance
- No two entities can have same key value
- Also called **Identifier** or **Candidate Key**
- Examples: StudentID, EmployeeID, Email (if unique)

```
STUDENT entity:
  └─ StudentID (underlined - indicates key attribute)
```

**Notation**: Key attributes are typically underlined

#### Attribute Notation Diagram

```
Simple Attribute
    ├─ StudentID
    ├─ Age
    ├─ Email
    │
Composite Attribute
    └─ Address
        ├─ Street
        ├─ City
        ├─ State
        └─ ZipCode

Multivalued Attribute
    ├─ PhoneNumber {9876543210, 9987654321}
    ├─ Email {raj@college.edu, raj.kumar@gmail.com}
    │
Derived Attribute
    └─ Age (calculated from DOB)
```

### Component 3: Relationship

A **relationship** is an association or connection between two or more entities.

#### Relationship Definition

- Describes how entities are related
- Shows business rules and constraints
- Examples:
  - Student ENROLLS IN Course
  - Employee WORKS FOR Department
  - Professor TEACHES Course

#### Relationship Notation

```
Entity1 ---- Relationship ---- Entity2
```

**Full Example**:
```
┌─────────┐           ┌─────────┐
│ STUDENT ├──enrolls─┤ COURSE  │
└─────────┘           └─────────┘
```

#### Types of Relationships (by number of entities)

##### Unary Relationship
- Relationship between entity and itself
- Also called **recursive relationship**
- Example: EMPLOYEE (Supervisor, Subordinate)

```
       ┌──────────────┐
       │   EMPLOYEE   │
       │              │
       │  EmployeeID  │
       │  Name        │
       │  Salary      │
       └──────────────┘
             │
        manages│manages
             │
       (Same entity related to itself)
```

**Real Example**: Organizational hierarchy where employees manage other employees

##### Binary Relationship
- Relationship between two entities
- Most common type
- Example: STUDENT enrolls in COURSE, EMPLOYEE works in DEPARTMENT

```
┌─────────────┐          ┌─────────────┐
│   STUDENT   │─enrolls─┤   COURSE    │
└─────────────┘          └─────────────┘
```

##### Ternary Relationship
- Relationship involving three entities
- More complex than binary
- Example: DOCTOR prescribes MEDICINE to PATIENT

```
           ┌──────────┐
           │ MEDICINE │
           └──────────┘
                 │
                 │
      ┌──────────┼──────────┐
      │          │          │
    ┌────────┐ prescribes ┌─────────┐
    │ DOCTOR │────────────│ PATIENT │
    └────────┘            └─────────┘
```

## Cardinality Ratios

Cardinality specifies how many instances of one entity can be associated with instances of another entity.

### 1:1 (One-to-One)

Each instance of Entity1 is associated with at most one instance of Entity2, and vice versa.

```
┌─────────┐ 1    1 ┌───────────┐
│ PERSON  ├────────┤ PASSPORT  │
└─────────┘        └───────────┘

One PERSON has one PASSPORT
One PASSPORT belongs to one PERSON
```

**Real-world examples**:
- One EMPLOYEE has one LOCKER
- One STUDENT has one REGISTRATION
- One PERSON has one BIRTH_CERTIFICATE

**Implementation**: Foreign key can go on either side

### 1:N (One-to-Many)

Each instance of Entity1 can be associated with multiple instances of Entity2, but each instance of Entity2 is associated with at most one instance of Entity1.

```
┌───────────┐ 1    * ┌──────────┐
│DEPARTMENT ├────────┤ EMPLOYEE │
└───────────┘        └──────────┘

One DEPARTMENT has many EMPLOYEES
One EMPLOYEE works in one DEPARTMENT
```

**Real-world examples**:
- One DEPARTMENT has many COURSES
- One STUDENT has many ENROLLMENTS
- One TEACHER teaches many COURSES

**Implementation**: Foreign key on "many" side

### N:1 (Many-to-One)

Same as 1:N but from other perspective. Many instances of Entity1 are associated with one instance of Entity2.

```
┌──────────┐ *    1 ┌───────────┐
│ EMPLOYEE ├────────┤DEPARTMENT │
└──────────┘        └───────────┘

Many EMPLOYEES work in one DEPARTMENT
```

### M:N (Many-to-Many)

Each instance of Entity1 can be associated with many instances of Entity2, and vice versa.

```
┌─────────┐ *     * ┌────────┐
│ STUDENT ├─────────┤ COURSE │
└─────────┘         └────────┘

One STUDENT can enroll in many COURSES
One COURSE can have many STUDENTS
```

**Real-world examples**:
- STUDENT and COURSE (many-to-many enrollment)
- AUTHOR and BOOK (many authors, multiple books; one book by multiple authors)
- STUDENT and PROJECT (students collaborate on projects)

**Implementation**: Requires creating a junction/bridge table

### Cardinality Diagram Summary

```
Cardinality Notation:

1 ────── (One)
│ ────── (Zero or more)
≤1 ────── (Zero or one)

Examples:

One-to-One:       One-to-Many:      Many-to-Many:
┌────┐ 1  1 ┌──┐ ┌────┐ 1  * ┌──┐ ┌────┐ *  * ┌──┐
│ A  ├─────┤B│ │ A  ├─────┤B│ │ A  ├─────┤B│
└────┘      └──┘ └────┘      └──┘ └────┘      └──┘
```

## Entity Relationship Diagram (ERD) Symbols

### Chen's Notation (Classical)

```
┌──────────┐
│  Entity  │  (Rectangle) - Regular entity
└──────────┘

╔══════════╗
║  Entity  ║  (Double Rectangle) - Weak entity
╚══════════╝

┌─ Attribute ─┐  (Oval) - Simple attribute
└─────────────┘

┌─ Attribute ─┐  (Double Oval) - Multivalued attribute
└─────────────┘

┌─ - - - - ┐  (Dashed Oval) - Derived attribute
│ Attribute│
└─ - - - - ┘

    ╱─ ─ ─╲
  ╱         ╲   (Diamond) - Relationship
 ╱           ╲
Relationship

Cardinality:
1 : 1      (One-to-One)
1 : N      (One-to-Many)
M : N      (Many-to-Many)
```

## Strong and Weak Entities

### Strong Entity

**Definition**: An entity that has a primary key and can exist independently without relying on any other entity.

**Characteristics**:
- Has its own primary key to uniquely identify instances
- Existence does not depend on other entities
- Participates in relationships independently

**Example**: STUDENT Entity
```
STUDENT (
    StudentID PRIMARY KEY,  ← Own primary key
    StudentName,
    Email,
    DepartmentID
)
```

### Weak Entity

**Definition**: An entity that does not have a primary key and must depend on a strong entity (called **owner** or **parent**) for its existence and identification.

**Characteristics**:
- Lacks a complete primary key
- Depends on strong entity for existence
- Identified by combination of:
  - Its own partial key (discriminator)
  - Primary key of owner entity
- Has **total participation** in owner relationship

**Example**: DEPENDENT Entity
```
EMPLOYEE (Strong entity)
    ↓ (has)
DEPENDENT (Weak entity)
    - No primary key of own
    - Identified by: EmployeeID + DependentName

DEPENDENT (
    EmployeeID,           ← Part of primary key (from EMPLOYEE)
    DependentName,        ← Part of primary key (partial key)
    DateOfBirth,
    Relationship
)

Composite Primary Key: (EmployeeID, DependentName)
```

**Real-world Weak Entity Examples**:

1. **ROOM depends on BUILDING**:
   - Room identified by: Building + RoomNumber
   - Primary Key: (BuildingID, RoomNumber)

2. **ORDER_LINE depends on ORDER**:
   - Order line identified by: OrderID + LineNumber
   - Primary Key: (OrderID, LineNumber)

3. **QUESTION depends on EXAM**:
   - Question identified by: ExamID + QuestionNumber
   - Primary Key: (ExamID, QuestionNumber)

### Notation Difference

```
Strong Entity        Weak Entity        Weak Relationship
┌──────────────┐    ╔══════════════╗   ┌──────────────┐
│   EMPLOYEE   │    ║  DEPENDENT   ║   │  EMPLOYEE    │
└──────────────┘    ╚══════════════╝   └──────────────┘
                                            ║ (double line)
                                            ║ has
                                            ╚
                                       ╔══════════════╗
                                       ║  DEPENDENT   ║
                                       ╚══════════════╝
```

## ER Model to Relational Schema Conversion

### Conversion Rules

#### Rule 1: Entity to Relation

**Each strong entity** becomes a relation (table).

**Example**:
```
ER Model: [STUDENT]
Relational Schema: STUDENT (StudentID, StudentName, Email, DepartmentID)
```

#### Rule 2: Attributes to Columns

**Each attribute** becomes a column.

**Simple attributes** → Direct column
**Composite attributes** → Split into multiple columns

**Example**:
```
Address (composite) becomes:
  - Street
  - City
  - State
  - ZipCode
```

#### Rule 3: Key Attribute to Primary Key

**Candidate key** becomes **Primary Key**

#### Rule 4: 1:1 Relationship Conversion

**Option A**: Foreign key on either side
```
PERSON (PersonID, Name)
PASSPORT (PassportNumber, PersonID FK, IssuedDate)
```

**Option B**: Merge both into single table (if no optional participation)
```
PERSON_WITH_PASSPORT (PersonID PK, Name, PassportNumber, IssuedDate)
```

#### Rule 5: 1:N Relationship Conversion

**Foreign key on "many" side**:
```
DEPARTMENT (DepartmentID, DepartmentName)
EMPLOYEE (EmployeeID, Name, Salary, DepartmentID FK)
```

#### Rule 6: M:N Relationship Conversion

**Create junction/bridge table**:
```
STUDENT (StudentID, Name, Email)
COURSE (CourseID, CourseName, Credits)

ENROLLMENT (StudentID FK, CourseID FK, Semester, Grade)
             ↑ Composite primary key
```

#### Rule 7: Multivalued Attribute Conversion

**Create separate table**:
```
EMPLOYEE (EmployeeID, Name)
PHONE_NUMBER (EmployeeID FK, PhoneNumber)
```

#### Rule 8: Weak Entity Conversion

**Weak entity** becomes relation with:
- All attributes of weak entity
- Primary key of owner entity as foreign key
- Composite primary key = (owner's PK + partial key)

**Example**:
```
DEPENDENT (EmployeeID FK, DependentName, DOB)
           ↑ Primary Key: (EmployeeID, DependentName)
```

### Complete Conversion Example

**ER Model**:
```
┌──────────────┐        ┌──────────────┐
│   STUDENT    │──*─────│   COURSE     │
│              │enrolls │              │
│ StudentID PK │        │ CourseID PK  │
│ Name         │        │ CourseName   │
│ Email        │        │ Credits      │
└──────────────┘        └──────────────┘

M:N Relationship: ENROLLMENT
```

**Relational Schema**:
```sql
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE
);

CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL,
    Credits INT CHECK (Credits BETWEEN 1 AND 6)
);

CREATE TABLE ENROLLMENT (
    StudentID INT NOT NULL,
    CourseID INT NOT NULL,
    Semester VARCHAR(10),
    Grade CHAR(2),
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES STUDENT(StudentID),
    FOREIGN KEY (CourseID) REFERENCES COURSE(CourseID)
);
```

## ER Modeling Best Practices

### 1. Entity Identification

- Think about entities first before attributes
- Identify which things/concepts need to be stored
- Ask: "What are we storing information about?"

### 2. Relationship Identification

- Identify how entities are related
- Determine cardinality carefully
- Use naming that describes the relationship

### 3. Avoiding Common Mistakes

**Mistake 1**: Making attribute an entity
```
WRONG: CourseID, CourseName, Credits as separate entities
RIGHT: Combine into single COURSE entity
```

**Mistake 2**: Incorrect cardinality
```
WRONG: Student 1-1 Advisor (one student can have one advisor)
RIGHT: Student N-1 Advisor (many students can have one advisor)
```

**Mistake 3**: Missing relationships
```
Make sure all logical relationships are captured
```

## Example: College Database ER Model

```
                    ┌──────────────┐
                    │ DEPARTMENT   │
                    └──────────────┘
                           ▲
                           │ 1
                           │
    ┌──────────────────────┼──────────────────────┐
    │ 1                    │                      │
    │                      │                      │
┌───────────┐         ┌─────────────┐      ┌──────────────┐
│ FACULTY   │ *─────* │ COURSE      │──*──┤ STUDENT      │
└───────────┘ teaches └─────────────┘   enrolls└──────────────┘
    │                       │
    │ 1                     │ 1
    │                       │
    │              ┌────────────────┐
    │              │ PREREQUISITE   │
    │              │ (self-join)    │
    │              └────────────────┘
    │
    └─────────────────┐
                      │
                  ┌───────────┐
                  │ OFFICE    │ (Weak entity)
                  │ (depends  │
                  │ on FACULTY│
                  └───────────┘
```

## Exam Notes and Tips

1. **Definition**: Define ER model as conceptual tool for database design
2. **Components**: Always mention Entity, Attribute, Relationship with clear definitions
3. **Attribute Types**: Give at least one concrete example for each type (simple, composite, multivalued, derived, key)
4. **Cardinality**: Explain 1:1, 1:N, M:N with real-world examples
5. **Strong vs Weak**: Define both, mention primary key, give examples
6. **Conversion Rules**: Write rules for entity, 1:N, and M:N conversions with examples
7. **SQL Examples**: Always include CREATE TABLE statements for all conversions
8. **Diagram**: Draw complete ER diagram for given scenario with all notations
9. **Real-World Relevance**: Connect concepts to practical business scenarios
