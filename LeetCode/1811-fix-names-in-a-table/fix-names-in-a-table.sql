# Write your MySQL query statement below
select user_id, CONCAT(UCASE(SUBSTR(name,1,1)), LCASE(SUBSTR(name, 2))) as name from Users
ORDER BY user_id;