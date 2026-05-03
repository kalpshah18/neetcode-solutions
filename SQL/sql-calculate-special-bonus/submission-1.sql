ALTER TABLE employees ADD bonus INT DEFAULT 0;

UPDATE employees
SET bonus = salary
WHERE employee_id % 2 = 1
  AND name NOT LIKE 'M%';

SELECT employee_id, bonus FROM employees ORDER BY employee_id;