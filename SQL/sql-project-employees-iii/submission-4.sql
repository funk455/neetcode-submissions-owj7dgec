-- Write your query below
SELECT p.project_id, p.employee_id
FROM project p 
JOIN employee e ON p.employee_id = e.employee_id
WHERE e.experience_years = (
    SELECT MAX(e2.experience_years) 
    FROM project p2
    JOIN employee e2 ON p2.employee_id = e2.employee_id
    WHERE p2.project_id = p.project_id  -- 关键：关联到外层的 p.project_id
);