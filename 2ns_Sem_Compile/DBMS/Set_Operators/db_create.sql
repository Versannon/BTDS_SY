DROP TABLE IF EXISTS cs_students;
DROP TABLE IF EXISTS it_students;

CREATE TABLE cs_students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50) NOT NULL,
    city VARCHAR(50) NOT NULL
);

CREATE TABLE it_students (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50) NOT NULL,
    city VARCHAR(50) NOT NULL
);

INSERT INTO cs_students (student_id, student_name, city) VALUES
(1, 'Aarav', 'Mumbai'),
(2, 'Diya', 'Pune'),
(3, 'Kabir', 'Nashik'),
(4, 'Meera', 'Nagpur');

INSERT INTO it_students (student_id, student_name, city) VALUES
(3, 'Kabir', 'Nashik'),
(4, 'Meera', 'Nagpur'),
(5, 'Rohan', 'Delhi'),
(6, 'Isha', 'Bengaluru');
