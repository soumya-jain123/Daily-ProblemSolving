# Write your MySQL query statement below
select max(Salary) as SecondHighestSalary from employee where salary < (select max(Salary) from employee);