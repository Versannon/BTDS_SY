use join_db;
    create table dep
        (
        Dep_ID int;
        Dep_name varchar(255)
        );
    create table emp
    (
        Emp_ID int;
        Emp_name varchar(255);
        Dep_ID int;
    )
    insert into dep
    values
    (1, 'HR'),
    (2, 'IT'),
    (3, 'Finance');

    insert into emp
    values
    (1, 'Alice', 1),
    (2, 'Bob', 2),
    (3, 'Charlie', 3);