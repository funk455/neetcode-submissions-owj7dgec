-- Write your query below
select distinct title 
from tv_program t
join content c on t.content_id = c.content_id
where t.program_date >= '2020-06-01' and t.program_date < '2020-07-01'
and kids_content = 'Y'
and content_type = 'Movies';
