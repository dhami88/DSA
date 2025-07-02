# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary from (select max(salary) as Salary, departmentid from Employee group by departmentid) temp
inner join employee e on temp.departmentid=e.departmentid and temp.Salary=e.salary
inner join department d on temp.departmentid = d.id;

-- select w.department, w.first_name, w.salary from
--  (select max(salary) as maxsal, department from worker group by department) temp
-- inner join worker w on temp.department = w.department and temp.maxsal = w.salary;
