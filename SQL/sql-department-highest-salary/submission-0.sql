-- Write your query below
select d.name as department,e.name as employee,e.salary
from employee e 
join department d  on e.department_id = d.id
where e.salary in (select max(salary) from employee group by department_id);