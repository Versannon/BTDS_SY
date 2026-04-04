Types of constraints:

NULL Constraints:

    - Specifies whether a column can accpet NULL values or not
    - Enforcement: If a column is defined with NOT NULL constraint, it cannot accept NULL values. If a column is defined with NULL constraint, it can accept NULL values.
    - Example:
    CREATE TABLE Employees
    (
        EmployeeID INT PRIMARY KEY,
        FirstName VARCHAR(50) NOT NULL,
        LastName VARCHAR(50) NOT NULL,
        Age INT CHECK (Age>=18 AND Age <=65),
        Email VARCHAR(100) UNIQUE,
        DepartmentID INT,
        FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
    )

    CREATE TABLE Departments
    (
        DepartmentID INT PRIMARY KEY,
        DepartmentName VARCHAR(100) NOT NULL
    )

    (Display table):
    Employees Table:
    SELECT * FROM Employees;

UNIQUE Constraints:
    - Ensures that all values in a column are unique
    - Enforcement: If a column is defined with UNIQUE constraint, it cannot have duplicate values. Each value must be distinct.
    - Example:
    CREATE TABLE Employees
    (
        EmployeeID INT PRIMARY KEY,
        FirstName VARCHAR(50) NOT NULL,
        LastName VARCHAR(50) NOT NULL,
        Age INT CHECK (Age>=18 AND Age <=65),
        Email VARCHAR(100) UNIQUE,
        DepartmentID INT,
        FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID)
    )



Querying relational Data:

    - Relational Query Language (RQL) is used by the user to communicate with the database user requests for the information from the database.

    - Relational algebra breaks the user requests and instructs the DBMS to execute the requests.

    - They are generally on a higher level than any other programming language. These relational query languages can be 'Procedural' or 'Non-Procedural'.

    - Types of RQL:

        1: Procedural RQL:

            - In Procedural Language, the user instructs the system to perform a series of operations on the database to produce the desired results.
            - Users tell what data to be retrieved and how to retrieve it.
            - Procedural Query Languages performs a set of queries instructing the DBMS to perform various transactions in sequence to meet user request.

            -Types:
                - Relational Algebra:
                    - Relational algebra is a PQL (Procedural Query Language).
                    - There are a few operators that are used in relational algebra:
                        1: Select (σ): Selects rows from a relation that satisfy a given predicate.
                            e.g., SELECT * FROM Employees WHERE Age > 30;
                        2: Project (π): Selects specific columns from a relation.
                            e.g., SELECT FirstName, LastName FROM Employees;
                        3: Set Difference (-): 
                            - It Returns the difference between two relations.
                            - If we have two relations R and S, the set difference R - S will return all tuples that are in R but not in S.
                            - It is a Binary operator.
                            - e.g., 
                            SELECT RollNo FROM R
                            EXCEPT
                            SELECT RollNo FROM S;
                        4: Union (∪): Combines the results of two relations and eliminates duplicates.
                            e.g.,
                            SELECT RollNo FROM R
                            UNION
                            SELECT RollNo FROM S;
                        5: Cartesian Product (×): Combines every tuple of one relation with every tuple of another relation.
                            e.g.,
                            SELECT * FROM R
                            CROSS JOIN S;
        
        2: Non-Procedural Language:

            -In Non Procedural Language, user outlines the desired info without giving a specific procedure or without telling  the steps to retrieve the data. The user specifies what data is needed, and the DBMS determines how to retrieve it.
            - Example:
            SELECT FirstName, LastName FROM Employees WHERE Age > 30;

            -Relational Calculus:
                - Relational calculus is a Non-Procedural Query Language.
                - It is a declarative language that allows users to specify what data they want to retrieve without specifying how to retrieve it.
                - Types:
                    1: Tuple Relational Calculus (TRC):
                        - In TRC, users specify the desired result using tuple variables and predicates.
                        - Example:
                        {t | t ∈ Employees AND t.Age > 30}
                    2: Domain Relational Calculus (DRC):
                        - In DRC, users specify the desired result using domain variables and predicates.
                        - Example:
                        {<FirstName, LastName> | ∃Age (Employees(FirstName, LastName, Age) AND Age > 30)}


Logical Database Design:

- Data view of logical database:- 
    Logical DB provides a particular view of Logical DB tables.
    A logical database is appropriately used when the structure of the database is Large.
    It is convenient to use flow, i.e.,
        1: SELECT.
        2: READ.
        3: PROCESS.
        4: DISPLAY.
- In order to work with databases efficiently, the data of the Logical DB is hierarchical in nature.
- The tables are linked to each other in a Foreign Key relationship.

Keys in Logical Design:
    1: Primary key:
        - Unique identifier for each record in a table.
        - It cannot be NULL and must contain unique values.
        - Canditate key.

Steps in Logical Database Design:

    - Step 1 - Convert ER diagram to Relations
       Mapping Rules:
        
        1: Strong Entity Set:
            - Each strong entity set is mapped to a relation.
            - The attributes of the entity set become the attributes of the relation.
            - The primary key of the entity set becomes the primary key of the relation.
        
        2: Weak Entity Set:
            - Each weak entity set is mapped to a relation.
            - The attributes of the weak entity set become the attributes of the relation.
            - The primary key of the relation is a combination of the primary key of the related strong entity set and the partial key of the weak entity set.
        
        3: Relationship Set:
            - Each relationship set is mapped to a relation.
            - The attributes of the relationship set become the attributes of the relation.
            - The primary key of the relation is a combination of the primary keys of the related entity sets.
        
    - Step 2 - Normalization:

        - Normalization is the process of organizing the attributes and relations of a database to minimize redundancy and dependency.
        - It involves decomposing a relation into smaller relations without losing information.
        - Normal forms:
            1: First Normal Form (1NF):
                - A relation is in 1NF if it contains only atomic values and each attribute contains only a single value.
            2: Second Normal Form (2NF):
                - A relation is in 2NF if it is in 1NF and all non-key attributes are fully functionally dependent on the primary key.
            3: Third Normal Form (3NF):
                - A relation is in 3NF if it is in 2NF and there are no transitive dependencies between non-key attributes.
            4: Boyce-Codd Normal Form (BCNF):
                - A relation is in BCNF if it is in 3NF and for every functional dependency X → Y, X is a superkey.