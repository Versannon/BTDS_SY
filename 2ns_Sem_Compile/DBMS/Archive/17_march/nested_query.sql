select name,marks from marks
where marks > (
    select AVG(marks)
    from marks
)