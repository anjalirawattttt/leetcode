# Write your MySQL query statement below
-- SELECT reports_to AS employee_id ,
--     (SELECT name FROM Employees WHERE employee_id=reports_to) AS name , 
--     COUNT(employee_id) AS reports_count , ROUND(AVG(age),0) AS average_age
-- FROM Employees
-- GROUP BY reports_to
-- HAVING reports_to IS NOT NULL
-- ORDER BY reports_to;

SELECT employee_id,name,COUNT(reports_to) AS reports_count,ROUND(AVG(age),0) AS average_age
FROM
    (SELECT e1.employee_id,e1.name,e2.reports_to,e2.age
    FROM Employees e1
    INNER JOIN Employees e2
    ON e1.employee_id=e2.reports_to) temp
GROUP BY employee_id
ORDER BY employee_id;
