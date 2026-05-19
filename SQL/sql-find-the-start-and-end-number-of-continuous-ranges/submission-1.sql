-- Write your query below
with idgroup as (
    select log_id,
    log_id - row_number() over (order by log_id) as g
    from logs
)
select min(log_id) as start_id,
max(log_id) as end_id
from idgroup
group by g
order by start_id;