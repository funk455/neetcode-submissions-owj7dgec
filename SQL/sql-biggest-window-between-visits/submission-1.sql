-- Write your query below
select user_id,max(gap) as biggest_window
from (
    select user_id,
    coalesce(
        lead(visit_date) over(partition by user_id order by visit_date),
        '2021-01-01'::DATE 
    ) - visit_date as gap 
    from user_visits
) as gaps
group by user_id
order by user_id;