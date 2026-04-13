create table student
(
    SID INT primary key,
    Name VARCHAR(50),
    Marks INT
)

create table student_log
(
    log varchar(100)
)


-- Trigger Create

DELIMITER //
create triggertrg_after_insert
after insert on student
for each row
begin
insert into Student_log
values(concat('Student Added: ', New.Name));
end //

DELIMITER ;

-- Test Trigger

insert into student
VALUES(
    1,'John Doe', 85
;)

DELIMITER //
create trigger trg_after_update
after update on student
for each row
begin
insert into Student_log
values(concat('Student Updated: ', New.Name));
end //

DELIMITER ;