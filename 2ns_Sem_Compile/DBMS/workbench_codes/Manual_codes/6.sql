create table marks
(SID INT, marks INT);
SELECT Name FROM Student 
WHERE SID IN (SELECT SID FROM Marks WHERE Marks > 80);