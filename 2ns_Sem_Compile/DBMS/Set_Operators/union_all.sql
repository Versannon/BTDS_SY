SELECT student_id, student_name, city
FROM cs_students
UNION ALL
SELECT student_id, student_name, city
FROM it_students;
