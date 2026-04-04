-- Normalization examples
-- This file demonstrates UNF to 3NF style decomposition.

USE BTDS211_DBMS;

-- UNNORMALIZED FORM
-- Repeating course information inside one student record
CREATE TABLE IF NOT EXISTS StudentCourse_UNF (
    StudentID INT,
    StudentName VARCHAR(100),
    DepartmentName VARCHAR(100),
    Course1 VARCHAR(100),
    Course2 VARCHAR(100),
    Course3 VARCHAR(100)
);

-- 1NF
-- Make values atomic and move repeating groups into separate rows
CREATE TABLE IF NOT EXISTS StudentCourse_1NF (
    StudentID INT,
    StudentName VARCHAR(100),
    DepartmentName VARCHAR(100),
    CourseName VARCHAR(100)
);

-- 2NF
-- Remove partial dependency from composite key based design
CREATE TABLE IF NOT EXISTS Students_2NF (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(100),
    DepartmentID INT
);

CREATE TABLE IF NOT EXISTS Courses_2NF (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100)
);

CREATE TABLE IF NOT EXISTS Enrollment_2NF (
    StudentID INT,
    CourseID INT,
    PRIMARY KEY (StudentID, CourseID)
);

-- 3NF
-- Remove transitive dependency by separating department details
CREATE TABLE IF NOT EXISTS Departments_3NF (
    DepartmentID INT PRIMARY KEY,
    DepartmentName VARCHAR(100) UNIQUE
);

CREATE TABLE IF NOT EXISTS Students_3NF (
    StudentID INT PRIMARY KEY,
    StudentName VARCHAR(100) NOT NULL,
    DepartmentID INT,
    FOREIGN KEY (DepartmentID) REFERENCES Departments_3NF(DepartmentID)
);

CREATE TABLE IF NOT EXISTS Courses_3NF (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100) NOT NULL
);

CREATE TABLE IF NOT EXISTS Enrollment_3NF (
    StudentID INT,
    CourseID INT,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES Students_3NF(StudentID),
    FOREIGN KEY (CourseID) REFERENCES Courses_3NF(CourseID)
);

-- Suggested theory summary:
-- 1NF: Atomic values
-- 2NF: No partial dependency
-- 3NF: No transitive dependency
