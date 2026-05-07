-- Write your query below
select name, sum(t.amount) as balance
from users u
join transactions t on u.account = t.account
group by name
having sum(t.amount) > 10000;
