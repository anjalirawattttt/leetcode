# Write your MySQL query statement below
SELECT name FROM Customer c1
WHERE NOT EXISTS (
    SELECT * FROM Customer c2
    WHERE (c1.referee_id=c2.id) AND (c2.id=2)
);