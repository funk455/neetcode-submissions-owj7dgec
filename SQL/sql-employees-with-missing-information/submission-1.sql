-- Write your query below
select coalesce(e.employee_id, s.employee_id) as employee_id
from employees e
full join salaries s on e.employee_id = s.employee_id
where e.name IS NULL or s.salary IS NULL
order by employee_id;