-- Write your query below
select p.player_id, p.player_name , count(*) as grand_slams_count
from players p
join (
    select wimbledon as player_id from championships 
    union all
    select fr_open from championships
    union all
    select us_open from championships
    union all
    select au_open from championships
) as champions  on p.player_id = champions.player_id
group by p.player_id;