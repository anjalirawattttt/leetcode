# Write your MySQL query statement below
(SELECT x,y,z,'Yes' AS triangle
FROM Triangle
WHERE x+y>z AND y+z>x AND x+z>y)
UNION
(SELECT x,y,z,'No' AS triangle
FROM Triangle
WHERE x+y<=z OR y+z<=x OR x+z<=y)
;