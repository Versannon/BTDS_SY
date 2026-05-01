create database manual_codes;
use manual_codes;

CREATE TABLE Student (SID INT PRIMARY KEY, Name VARCHAR(50), Age INT);
ALTER TABLE Student ADD Address VARCHAR(100);
DROP TABLE Student;