use school;

DELIMITER //

create procedure GetSTDDetails(IN std_id INT)
begin
	select * from student where std_id = SID;
end //

DELIMITER ;

call GetSTDDetails(1);