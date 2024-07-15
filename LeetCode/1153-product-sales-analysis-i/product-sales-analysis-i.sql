# Write your MySQL query statement below

select P.product_name, S.year, S.price FROM SALES AS S
INNER JOIN PRODUCT AS P
ON S.PRODUCT_ID = P.PRODUCT_ID;
