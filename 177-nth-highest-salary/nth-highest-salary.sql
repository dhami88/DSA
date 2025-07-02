CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 set N=N;
  RETURN (
      # Write your MySQL query statement below.
  select (select distinct salary from employee e1 where N=(select count(distinct salary) from employee e2 where e2.salary>=e1.salary))as temp
  
  );
END