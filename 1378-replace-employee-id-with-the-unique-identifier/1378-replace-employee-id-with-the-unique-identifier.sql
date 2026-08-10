# Write your MySQL query statement below
SELECT e.name,ei.unique_id FROM Employees e
LEFT JOIN EmployeeUNI ei
ON e.id=ei.id;