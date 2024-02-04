WITH RankedSalaries AS (
    SELECT
        e.id AS employee_id,
        e.name AS employee,
        e.salary,
        e.departmentId,
        DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rank_in_department
    FROM
        Employee e
)
SELECT
    d.name AS Department,
    r.employee,
    r.salary
FROM
    Department d
JOIN
    RankedSalaries r ON d.id = r.departmentId
WHERE
    r.rank_in_department <= 3;
