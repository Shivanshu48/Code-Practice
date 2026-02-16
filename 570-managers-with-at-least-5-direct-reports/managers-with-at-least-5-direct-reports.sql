SELECT e1.name FROM Employee e1
JOIN Employee e2
ON e2.managerID = e1.id
GROUP BY e1.id
HAVING COUNT(*) >= 5;
