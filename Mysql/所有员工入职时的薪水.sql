/* 查找所有员工入职时候的薪水情况，给出emp_no以及salary， 并按照emp_no进行逆序(请注意，一个员工可能有多次涨薪的情况)
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

1. 内联 hire_date=from_date

SELECT s.emp_no, s.salary 
FROM employees AS e  INNER JOIN salaries AS s
    on e.emp_no = s.emp_no AND e.hire_date=s.from_date
ORDER BY e.emp_no DESC;


2. 直接从salaries中找每个人的最早的薪水
SELECT emp_no, salary FROM salaries GROUP BY emp_no HAVING min(from_date) ORDER BY  emp_no DESC;
