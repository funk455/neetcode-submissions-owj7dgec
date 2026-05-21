-- Write your query below
with scores as (
    select 
    exam_id,
    max(score) as max_score,
    min(score) as min_score
    from exam
    group by exam_id
),
not_student as (
    select distinct e.student_id
    from exam e
    join scores s on e.exam_id = s.exam_id
    where e.score = s.max_score or e.score = s.min_score
)
select student_id,student_name
from student s
where s.student_id in (select student_id from exam)
    and s.student_id not in (select student_id from not_student)
order by s.student_id;