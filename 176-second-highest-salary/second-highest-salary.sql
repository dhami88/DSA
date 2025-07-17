# Write your MySQL query statement below
-- select (select distinct salary from employee e1 where 2=(select count(distinct salary)from employee e2 where e2.salary>=e1.salary))as SecondHighestSalary;

select (select distinct salary from employee order by salary desc limit 1,1)as SecondHighestSalary;