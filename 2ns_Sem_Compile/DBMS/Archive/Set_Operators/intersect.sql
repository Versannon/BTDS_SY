SELECT student_id, student_name, city
FROM cs_students
INTERSECT
SELECT student_id, student_name, city
FROM it_students;
