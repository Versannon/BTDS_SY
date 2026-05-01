# Exam Preparation: Unit 1

## 1️⃣ Historical Perspective (Why DBMS came)

### 📌 Before DBMS → File System

Data stored in separate files:

- **Student.txt**
- **Marks.txt**
- **Fees.txt**

#### ❌ Problems:
- Data duplication (same student repeated)
- No relationships
- Hard to update
- No security

### 💡 After DBMS
- Data stored in tables (relations)
- Connected using keys
- Easy querying using SQL

👉 This shift came after **Relational Model (1970)**

---

## 2️⃣ File System vs DBMS (VERY IMPORTANT)

| **Feature**      | **File System ❌** | **DBMS ✅**       |
|------------------|-------------------|------------------|
| **Redundancy**   | High              | Controlled       |
| **Consistency**  | Poor              | Maintained       |
| **Security**     | Weak              | Strong           |
| **Access**       | Hard              | SQL-based        |
| **Relationships**| None              | Supported        |

🔥 **Exam Line:**

👉 “DBMS eliminates redundancy and improves data integrity compared to file systems.”

---

## 3️⃣ What is Data Model?

### 📌 Definition:

A data model defines:
- Structure of data
- Relationships
- Constraints

### Types:
- **Relational** (most important)
- **Hierarchical**
- **Network**

👉 **Relational model** = tables (rows + columns)

---

## 4️⃣ Levels of Abstraction (TOP EXAM QUESTION)

DBMS hides complexity using 3 levels:

### 🧱 1. Physical Level
- How data is stored (disk, blocks)

### 🧠 2. Logical Level
- Tables, attributes, relationships

### 👁️ 3. View Level
- What user sees

🔥 **Example:**
- **Admin** → full database
- **Student** → only marks

---

## 5️⃣ Data Independence (IMPORTANT THEORY)

### 📌 Meaning:

Ability to change one level without affecting others

### 🔹 Types:
1. **Physical Data Independence**
   - Change storage without changing schema
2. **Logical Data Independence**
   - Change schema without affecting apps

🔥 **Exam Line:**

👉 “Data independence reduces application maintenance.”

---

## 6️⃣ Structure of DBMS

DBMS has 3 main components:

### 🧠 1. Query Processor
- Converts SQL → execution plan

### 💾 2. Storage Manager
- Handles disk + memory

### 🗄️ 3. Database
- Actual stored data

👉 Query languages like SQL are built on relational concepts

---

## 7️⃣ Introduction to Database Design

Now we move to design phase (**ER Model**)

### 🧩 ER Model (MOST IMPORTANT PART OF UNIT 1)

#### 🔹 Entity
- Real-world object
- 👉 **Example:** Student

#### 🔹 Attribute
- Properties
- 👉 **Example:** Name, Age

#### 🔹 Relationship
- Connection between entities
- 👉 **Example:** Student → Enrolls → Course

#### 🔹 ER Diagram Symbols

| **Symbol**   | **Meaning**         |
|--------------|---------------------|
| Rectangle    | Entity              |
| Oval         | Attribute           |
| Diamond      | Relationship        |

---

## 8️⃣ Types of Attributes

- **Simple** → Name
- **Composite** → Address
- **Multivalued** → Phone
- **Derived** → Age (from DOB)

---

## 9️⃣ Entity Sets & Relationship Sets

- **Entity Set** → Collection of entities
- **Relationship Set** → Collection of relationships

---

## 🔟 Additional ER Features

- **Specialization** (Student → UG/PG)
- **Generalization**
- **Weak Entity** (depends on another entity)

---

## 1️⃣1️⃣ Conceptual Design Using ER Model

### Steps:
1. Identify entities
2. Identify attributes
3. Define relationships
4. Draw ER diagram
5. Convert to tables

⚡ **How This Connects to Unit 2**

Everything here leads to:
- 👉 Tables (Relations)
- 👉 Tuples, Attributes, Keys

---

## 1️⃣ Define DBMS and its advantages (5 marks)

### Answer:

A DBMS (Database Management System) is software that allows users to create, store, manage, and retrieve data efficiently.

**Advantages:**
- Reduces data redundancy
- Ensures data consistency
- Provides data security
- Supports multiple users
- Enables easy data access using queries

👉 DBMS improves data management compared to traditional file systems.

---

## 2️⃣ What is Data Model? Explain types (5 marks)

### Answer:

A data model defines how data is structured, stored, and related.

**Types:**
- **Relational Model** – Data stored in tables (most used)
- **Hierarchical Model** – Tree structure
- **Network Model** – Graph structure with multiple links

👉 The relational model is widely used due to simplicity and efficiency.

---

## 3️⃣ Explain Schema and Instance (5 marks)

### Answer:

- **Schema:** Structure/design of database (fixed)
- **Instance:** Actual data stored at a particular time

**Example:**
- Schema → Table structure
- Instance → Data inside table

👉 Schema is stable, instance changes frequently.

---

## 4️⃣ Explain types of attributes (5 marks)

### Answer:

Attributes describe properties of an entity.

**Types:**
- **Simple:** Cannot be divided (Name)
- **Composite:** Can be divided (Address)
- **Multivalued:** Multiple values (Phone numbers)
- **Derived:** Calculated (Age from DOB)

---

## 5️⃣ Explain Entity and Relationship (5 marks)

### Answer:

- **Entity:** Real-world object (Student)
- **Entity Set:** Collection of entities
- **Relationship:** Association between entities

**Example:**
- Student → Enrolls → Course

---

## 🔴 8 MARK QUESTIONS (DETAILED + DIAGRAM)

## 6️⃣ DBMS vs File System (8 marks)

### Answer:

**Definition:**
- **File System** → Stores data in files
- **DBMS** → Manages structured data efficiently

**Comparison:**
```
| **Feature**   | **File System** | **DBMS**       |
|---------------|-----------------|----------------|
| **Redundancy**| High            | Low            |
| **Consistency**| Poor           | High           |
| **Security**  | Weak            | Strong         |
| **Access**    | Difficult       | Easy (SQL)     |
| **Integrity** | Not enforced    | Enforced       |
```

**Conclusion:**

DBMS provides better data management, security, and consistency.

---

## 7️⃣ Levels of Abstraction in DBMS (8 marks)

### Answer:

DBMS uses 3 levels to hide complexity:

1. **Physical Level**
   - How data is stored on disk
2. **Logical Level**
   - Structure of database (tables, relationships)
3. **View Level**
   - What user sees

**Diagram (Draw this in exam):**
```
View Level (User)
       ↓
Logical Level (Tables)
       ↓
Physical Level (Storage)
```

👉 This improves usability and security.

---

## 8️⃣ Data Independence (8 marks)

### Answer:

Data independence means ability to modify schema without affecting applications.

**Types:**
1. **Physical Data Independence**
   - Change storage without affecting logical schema
2. **Logical Data Independence**
   - Change schema without affecting applications

**Advantages:**
- Flexibility
- Reduced maintenance

---

## 9️⃣ Explain ER Model with diagram (8 marks)

### Answer:

ER model is used for database design.

**Components:**
- **Entity:** Object (Student)
- **Attribute:** Property (Name, Age)
- **Relationship:** Connection (Enrolls)

**Diagram:**
```
[Student] ---- Enrolls ---- [Course]
   |                         |
 (ID)                     (CourseID)
```

👉 ER model helps in conceptual design of database.

---

## 🔟 Weak Entity vs Strong Entity (8 marks)

### Answer:

- **Strong Entity:**
  - Has its own primary key
  - Exists independently
- **Weak Entity:**
  - No primary key
  - Depends on strong entity

**Example:**
- Student → Strong
- Dependent → Weak

---

## 1️⃣1️⃣ Specialization & Generalization (8 marks)

### Answer:

- **Specialization:**
  - Top-down approach
  - Entity divided into subtypes

**Example:** Student → UG, PG

- **Generalization:**
  - Bottom-up approach
  - Combine entities into one

---

## 1️⃣2️⃣ ER Diagram Design (8 marks)

### Example: Student–Course

**Steps:**
1. Identify entities → Student, Course
2. Attributes → Name, ID
3. Relationship → Enrolls

**Diagram:**
```
[Student] ---- Enrolls ---- [Course]
   |                         |
 (ID)                     (CourseID)
```