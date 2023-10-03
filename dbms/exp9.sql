CREATE TABLE student (
	stud_id INT PRIMARY KEY,
    name VARCHAR(20),
    dept_id INT,
    sub1_marks INT, sub2_marks INT,
    total_marks INT, percentage FLOAT(5)
);
CREATE TABLE department (
	dept_id INT PRIMARY KEY,
    dept_name VARCHAR(20),
    sub1_total INT, sub2_total INT,
    avg_total FLOAT(5)
);
DESC student;
DESC department;


SELECT * FROM student;
SELECT * FROM department;


CREATE OR REPLACE TRIGGER total_n_percent_calculator
BEFORE INSERT ON student
FOR EACH ROW  
BEGIN
:NEW.total_marks := :NEW.sub1_marks + :NEW.sub2_marks;
:NEW.percentage := :NEW.total_marks / 2.0;
END;

CREATE OR REPLACE TRIGGER dept_marks_sum
AFTER INSERT ON student
FOR EACH ROW
BEGIN
UPDATE department SET sub1_total = sub1_total + :new.sub1_marks,
sub2_total = sub2_total + :new.sub2_marks
WHERE dept_id = :new.dept_id;
UPDATE department SET avg_total = (sub1_total + sub2_total)/2.0
WHERE dept_id = :new.dept_id;      
END;


INSERT INTO department VALUES (2, 'CSE-DS', 0, 0, 0);
INSERT INTO student (stud_id, name, dept_id, sub1_marks, sub2_marks) VALUES (86, 'Suresh', 2, 87, 88);
INSERT INTO student (stud_id, name, dept_id, sub1_marks, sub2_marks) VALUES (95, 'Ramesh', 2, 97, 83);

SELECT * FROM student;
SELECT * FROM department;


CREATE OR REPLACE TRIGGER delete_dept
AFTER DELETE on department
FOR EACH ROW
BEGIN
DELETE FROM student WHERE student.dept_id = :old.dept_id;
END;

SELECT * FROM student;
SELECT * FROM department;
DELETE FROM department WHERE dept_id = 2;
SELECT * FROM student;
SELECT * FROM department;



CREATE TABLE store(
    store_id INT,
    store_name VARCHAR(20),
    sales INT
);
CREATE TABLE orders(
    ord_no INT,
    amount INT
);

CREATE OR REPLACE TRIGGER calculate_sales
AFTER INSERT on orders
FOR EACH ROW
BEGIN
    UPDATE store SET sales = sales + :NEW.amount;
END;

CREATE OR REPLACE TRIGGER reduce_sales
AFTER DELETE on orders
FOR EACH ROW
BEGIN
    UPDATE store SET sales = sales - :old.amount;
END;

INSERT INTO store VALUES(55, 'MB mart', 0);
INSERT INTO orders VALUES(24, 4200);
INSERT INTO orders VALUES(27, 3500);
INSERT INTO orders VALUES(55, 900);
INSERT INTO orders VALUES(29, 20000);

SELECT * FROM store;
SELECT * FROM orders;

DELETE FROM orders WHERE ord_no IN(27, 29);
SELECT * FROM store;
SELECT * FROM orders;



DROP TRIGGER total_n_percent_calculator;
DROP TRIGGER dept_marks_sum;
DROP TRIGGER delete_dept;



DROP TABLE student;
DROP TABLE department;
DROP TABLE store;
DROP TABLE orders;
