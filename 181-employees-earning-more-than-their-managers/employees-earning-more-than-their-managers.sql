# Write your MySQL query statement below
select e1.name as Employee from Employee as e1  join  Employee as m on m.id=e1.managerId where m.salary<e1.salary;