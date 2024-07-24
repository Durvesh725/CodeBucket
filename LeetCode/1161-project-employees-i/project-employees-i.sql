# Write your MySQL query statement below
select p.project_id, ROUND(AVG(e.experience_years), 2) as average_years from project as p
left join Employee as e
ON p.employee_id = e.employee_id
GROUP BY project_id;