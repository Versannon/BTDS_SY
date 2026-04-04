SELECT student_id, student_name, city
FROM cs_students
EXCEPT
SELECT student_id, student_name, city
FROM it_students;
