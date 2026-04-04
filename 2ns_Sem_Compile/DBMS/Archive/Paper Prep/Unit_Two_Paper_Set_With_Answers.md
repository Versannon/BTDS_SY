# DBMS Unit Two Question Paper

## Total Marks: 50  
Each question carries 5 marks.

### Question 1: Integrity Constraints
**Q:** Define integrity constraints in relational databases. Explain different types of integrity constraints with examples.  
**A:** Integrity constraints are rules that ensure the accuracy and consistency of data in a relational database. Types include:
- **Domain Integrity:** Ensures that all values in a column fall within a defined domain (e.g., age should be a positive integer).
- **Entity Integrity:** Ensures that each table has a primary key that uniquely identifies each row. No primary key value can be null.
- **Referential Integrity:** Ensures that a foreign key value must either be null or must match a value in the primary key of another table.

### Question 2: Relational Model Terminology
**Q:** Explain the basic terminology of the relational model with examples.
**A:** Key terms include:
- **Relation:** A table with rows and columns.
- **Tuple:** A single row in a table.
- **Attribute:** A column in a table.
- **Domain:** The set of allowable values for an attribute.

### Question 3: Logical Database Design
**Q:** What is logical database design? Discuss its importance.
**A:** Logical database design refers to the process of creating a model of the database that defines the relationships between data without regard to how the data will be stored physically. It is crucial for ensuring that the database structure meets its intended purpose and performance requirements.

### Question 4: Views
**Q:** What are database views? Provide an example scenario.
**A:** A database view is a virtual table created by querying data from one or more tables. For example, a view might be created to show only customer names and their purchase totals, hiding sensitive data like credit card numbers.

### Question 5: Altering Tables
**Q:** Explain how to alter a table in SQL. Provide examples of different alterations.
**A:** The `ALTER TABLE` command is used to modify an existing table structure. Examples include:
- Adding a new column: `ALTER TABLE students ADD COLUMN age INT;`
- Dropping a column: `ALTER TABLE students DROP COLUMN age;`
- Modifying a column type: `ALTER TABLE students ALTER COLUMN age TYPE VARCHAR(3);`

### Question 6: Relational Algebra
**Q:** Define relational algebra and its significance in database operations.  
**A:** Relational algebra is a procedural query language that provides a set of operations (such as SELECT, PROJECT, and JOIN) for manipulating relations (tables). It is significant because it forms the theoretical foundation for SQL and other database query languages.

### Question 7: Tuple Relational Calculus
**Q:** What is tuple relational calculus? Describe its main components.
**A:** Tuple relational calculus is a non-procedural query language that specifies the properties of the desired result without detailing the procedure to obtain it. Its main components include:
- **Tuple Variables:** Represents individual rows in a relation.
- **Predicate Logic:** Used to express queries in the form of logical formulas.

### Question 8: Domain Relational Calculus
**Q:** Explain domain relational calculus and how it differs from tuple relational calculus.
**A:** Domain relational calculus is similar to tuple relational calculus but focuses on specifying values from domains rather than tuples. It utilizes domain variables that take on values from an attribute's domain.

### Question 9: Comparison of Calculus Types
**Q:** Compare tuple relational calculus and domain relational calculus.
**A:** While both are non-procedural query languages, tuple relational calculus deals with tuples in relations, whereas domain relational calculus deals with values from attributes. Tuple calculus variables range over tuples, while domain calculus variables range over attribute values.

### Question 10: Real-world Application
**Q:** Provide a real-world example of when integrity constraints are critical in a database application.
**A:** In a banking application, integrity constraints are critical to ensure that funds are only debited from an account if the account exists (entity integrity), and that a transfer between two accounts reflects accurate balances (referential integrity).

---  
**End of Question Paper**