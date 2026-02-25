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

        Procedural RQL:

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
