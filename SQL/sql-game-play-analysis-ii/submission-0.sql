-- Write your query below
select a.player_id,a.device_id
from activity a
join (
    select player_id,min(event_date) as first_login from activity
    group by player_id
) as j on a.player_id = j.player_id and a.event_date = j.first_login;