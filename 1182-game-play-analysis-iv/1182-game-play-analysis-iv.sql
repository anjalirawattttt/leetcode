# Write your MySQL query statement below
SELECT 
    ROUND(
        COUNT(DISTINCT a1.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity)
    ,2) AS fraction 
FROM
(SELECT player_id,MIN(event_date) AS min_event_date
FROM Activity
GROUP BY player_id) a1
INNER JOIN
Activity a2
ON a1.player_id=a2.player_id AND a1.min_event_date=DATE_SUB(a2.event_date,INTERVAL 1 DAY);