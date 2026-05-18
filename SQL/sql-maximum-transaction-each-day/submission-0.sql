-- Write your query below
select transaction_id
from transactions 
where (DATE(day),amount) in (
    select DATE(day),max(amount) from transactions group by date(day)
)
order by transaction_id;