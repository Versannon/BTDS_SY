DELIMITER //
create trigger trg_after_update
after update on student
for each row
begin
insert into Student_log
values(concat('Student Updated: ', New.Name));
end //

DELIMITER ;


update student
set Marks = 90
where SID = 2;