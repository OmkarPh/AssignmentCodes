use clg;

SELECT * FROM orders;
SELECT * FROM salesman;
SELECT * FROM customer;

CREATE TABLE dept(
	dept_id INT PRIMARY KEY,
    dept_name VARCHAR(20)
);

CREATE TABLE stud(
	sid INT PRIMARY KEY,
    name VARCHAR(20),
    dept_id INT,
    FOREIGN KEY(dept_id) REFERENCES dept(dept_id)
);

INSERT INTO dept VALUES
	(25, 'CSE'),
    (22, 'CSE-DS'),
	(52, 'CSE-AIML');
INSERT INTO dept VALUES(50, 'EXTC');
SELECT * FROM dept;
INSERT INTO stud VALUES
	(2, 'OP', 22),
	(1, 'OP', 22),
	(3, 'GP', 22),
	(4, 'PV', 52),
	(5, 'SD', 52),
	(7, 'MN', 25);
SELECT * FROM stud;

DELETE FROM stud WHERE sid = 2;
UPDATE stud SET name='John doe' WHERE sid=1;

TRUNCATE TABLE stud;
DROP TABLE stud;

ALTER TABLE stud
	ADD (
		grade VARCHAR(1) DEFAULT 'A',
        tmp INT
    );
INSERT INTO stud VALUES
	(9, 'IF', 52, 'B', 43),
	(8, 'GJ', 25, 'C', 50);
INSERT INTO stud VALUES
	(11, 'ZF', 25, 'B', 43),
	(12, 'OL', 52, 'C', 60);
INSERT INTO stud(sid, name, grade, tmp) VALUES
	(6, 'misc guy', 'B', 43),
	(10, 'misc guy2', 'C', 60);
DESC stud;


SELECT grade, COUNT(*) FROM stud GROUP BY grade HAVING grade IN('A', 'B');
SELECT count(*), SUM(tmp), MIN(tmp), MAX(tmp), AVG(tmp) FROM stud WHERE tmp >= 50;

SELECT * FROM stud;
SELECT * FROM stud NATURAL JOIN dept;
SELECT * FROM stud LEFT JOIN dept ON stud.dept_id = dept.dept_id;
SELECT * FROM stud RIGHT JOIN dept ON stud.dept_id = dept.dept_id;

SELECT DATE_FORMAT(SYSDATE(), '%d !!! %m GG --- %y');
SELECT DATE_FORMAT(SYSDATE(), '%d %D %m %M %y %Y --- %i'), SYSDATE();
SELECT time_format(SYSDATE(), "%h-%i %p --- %i --- %s. |.  %r.  |.  %T"), SYSDATE();


-- inserted.grade := select rollno from inserted
	
DELIMITER $$
CREATE TRIGGER update_grade
BEFORE INSERT ON stud
FOR EACH ROW
BEGIN
	DECLARE total INT;
    set total = NEW.tmp + 6;
	SET NEW.tmp = total;
    SET NEW.grade = CASE WHEN NEW.tmp >= 90 THEN 'A' WHEN NEW.tmp >= 70 THEN 'B' ELSE 'C' END;
    -- UPDATE dept SET dept_name = 'CSDS' WHERE dept_id=22; 
END $$
DELIMITER ;

DROP TRIGGER update_grade;

INSERT INTO stud values(23, 'oewf', 22, 'E', 65);
INSERT INTO stud(sid,name,dept_id,tmp) VALUES(25, 'opw', 52, 93);
INSERT INTO stud(sid,name,dept_id,tmp) values(52, 'jl', 25, 57);
SELECT * FROM stud;
SELECT * FROM dept;
DELETE FROM stud where sid in(23,25,52);
DESC stud;





