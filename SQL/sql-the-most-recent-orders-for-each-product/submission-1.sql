-- Write your query below
select product_name,p.product_id,order_id,order_date
from orders o 
join products p  on p.product_id = o.product_id
where o.order_date in (
    select max(order_date) from orders group by product_id
)
order by product_name, p.product_id , order_id; 