-- Write your query below
select c.customer_id,customer_name 
from customers c
where c.customer_id in (
    select customer_id from orders where product_name = 'A'
)
and c.customer_id in (
    select customer_id from orders where product_name = 'B'
)
AND c.customer_id NOT IN (
    SELECT customer_id FROM orders WHERE product_name = 'C'
)
order by c.customer_name;