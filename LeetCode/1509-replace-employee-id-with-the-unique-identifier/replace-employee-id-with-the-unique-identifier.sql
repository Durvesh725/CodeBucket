# Write your MySQL query statement below

select EU.unique_id, E.name from Employees AS E
LEFT JOIN EmployeeUNI AS EU
ON E.ID = EU.ID;