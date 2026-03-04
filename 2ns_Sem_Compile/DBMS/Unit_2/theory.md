Types of integrity constraints:

    - Integrity constraints are rules that ensure the accuracy and consistency of data in a database. They are used to enforce data integrity and maintain the quality of data stored in the database.

    - Types of integrity constraints:
        1: Entity Constrains
        2: Domain Constraints
        3: User-Defined Integrity Constraints
        4: Check Integrity Constraints
        5: Referential Integrity Constraints
        6: Unique Constraints
        7: Null Constraints
        8: Not Null Constraints
    

    1: Entity Constraints:
        - Entity constraints ensure that each entity in a database is uniquely identifiable. This is typically achieved through the use of primary keys, which are unique identifiers for each record in a table.
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
    
    2: Domain Constraints:
        - Domain constraints specify the permissible values for a given attribute. They ensure that the data entered into a column falls within a specific range or set of values.
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
    
    3: User-Defined Integrity Constraints:
        - User-defined integrity constraints are custom rules defined by the user to enforce specific business logic or requirements that are not covered by standard constraints.
        - Example:

        CREATE TABLE Employees
        (
            EmployeeID INT PRIMARY KEY,
            FirstName VARCHAR(50) NOT NULL,
            LastName VARCHAR(50) NOT NULL,
            Age INT CHECK (Age>=18 AND Age <=65),
            Email VARCHAR(100) UNIQUE,
            DepartmentID INT,
            FOREIGN KEY (DepartmentID) REFERENCES Departments(DepartmentID),
            CHECK (Email LIKE '%@%') -- User-defined constraint to ensure email format
        )

        CREATE TABLE Departments
        (
            DepartmentID INT PRIMARY KEY,
            DepartmentName VARCHAR(100) NOT NULL
        )

        (Display table):
        Employees Table:
        SELECT * FROM Employees;
    
    4: Check Integrity Constraints:
        - Check integrity constraints are used to limit the values that can be placed in a column. They ensure that the data entered into a column meets specific conditions.
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
    
    5: Referential Integrity Constraints:
        - Referential integrity constraints ensure that relationships between tables are maintained. They prevent the creation of orphan records and ensure that foreign keys correctly reference primary keys in related tables.
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
    
    6: Unique Constraints:
        - Unique constraints ensure that all values in a column are unique. They prevent duplicate entries in a column, ensuring that each value is distinct.
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

        SELECT * FROM Employees;
    
    7: Null Constraints:
        - Null constraints specify whether a column can accept NULL values or not. They enforce whether a column can have missing or undefined values.
        - Enforcement: If a column is defined with NOT NULL constraint, it cannot accept NULL values. If a column is defined with NULL constraint, it can accept NULL values.