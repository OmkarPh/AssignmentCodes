create database clg;
use clg;
drop table salesman;
drop table customer;
drop table orders;


-- SALESMAN (Salesman_id, Name, City, Commission)
CREATE TABLE salesman(
	salesman_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(20),
    city VARCHAR(20),
    commision float
);
INSERT INTO salesman VALUES(1, 'ram', 'mumbai', 2);
INSERT INTO salesman(name, city, commision) VALUES
('sam', 'mumbai', 1.5),
('mark', 'thane', 0.9),
('mahesh', 'pune', 1.0),
('pinky', 'pune', 0.75),
('meena', 'mumbai', 1.45),
('suresh', 'pune', 1.23),
('raju', 'pune', 1.9),
('dinesh', 'mumbai', 1.7),
('john', 'mumbai', 1.3)
;
SELECT * FROM salesman;


-- CUSTOMER (Customer_id, Cust_Name, City, Grade, Salesman_id)
CREATE TABLE customer(
	customer_id INT PRIMARY KEY AUTO_INCREMENT,
    cust_name VARCHAR(20),
    city VARCHAR(20),
    grade CHAR,
    salesman_id INT,
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);
INSERT INTO customer VALUES(1, 'parth', 'mumbai', 'A', 2);
INSERT INTO customer(cust_name, city, grade, salesman_id) VALUES
('soham', 'mumbai', 'B', 10),
('bartosz', 'mumbai', 'A', 2),
('samuel', 'mumbai', 'A', 10),
('gilbert', 'mumbai', 'B', 1),
('shyam', 'mumbai', 'C', 1),
('ramesh', 'pune', 'B', 5),
('maya', 'pune', 'A', 5),
('sita', 'pune', 'A', 4),
('jenny', 'pune', 'D', 8),
('gayatri', 'thane', 'A', 3),
('rajan', 'pune', 'B', 5);
SELECT * FROM customer;



-- ORDERS (Ord_No, Purchase_Amt, Ord_Date, Customer_id, Salesman_id)
CREATE TABLE orders(
	ord_no INT PRIMARY KEY AUTO_INCREMENT,
    purchase_amt INT,
    ord_date DATE,
    customer_id INT,
    salesman_id INT,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);
INSERT INTO orders(purchase_amt, ord_date, customer_id, salesman_id) VALUES
(62000, '2022-11-25', 2, 10);
INSERT INTO orders(purchase_amt, ord_date, customer_id, salesman_id) VALUES
(25000, '2022-11-25', 1, 10),
(60000, '2021-10-15', 2, 2),
(22000, '2020-8-19', 7, 5),
(500, '2022-7-4', 5, 3),
(15000, '2021-10-8', 9, 4),
(9000, '2023-1-15', 3, 6)
;
SELECT * FROM orders;

TRUNCATE TABLE orders;

-- Get customers who've dealt with salesmen with ID 3,4,5
SELECT * FROM customer WHERE salesman_id IN(3,4,5);

-- Get customers who've *not dealt* with salesmen with ID 1,4,5,10
SELECT * FROM customer WHERE salesman_id NOT IN(1,4,5,10);


SELECT city, COUNT(*) AS no_of_salesmen FROM salesman WHERE city = 'mumbai';
 SELECT city, COUNT(*) AS no_of_salesmen
	FROM salesman
    GROUP BY city
    ORDER BY no_of_salesmen DESC
;
 SELECT grade, COUNT(*) AS no_of_customers
	FROM customer
    GROUP BY grade
    ORDER BY no_of_customers DESC;
;
SELECT SUM(purchase_amt) AS total_purchase_amount FROM orders;
SELECT SUM(purchase_amt) AS total_purchase_amount
	FROM orders WHERE ord_date >= '2022-10-01';
;
SELECT
	SUM(purchase_amt) AS avg_purchase_amount_fromOct22,
    COUNT(ord_no) AS no_of_orders,
    AVG(purchase_amt) AS avg_purchase_amount_fromOct22
	FROM orders WHERE ord_date >= '2022-10-01';

SELECT MIN(purchase_amt) AS min_purchase_22
	FROM orders WHERE ord_date >= '2022-1-01';
    
SELECT MAX(purchase_amt) AS min_purchase_22
	FROM orders WHERE ord_date >= '2022-1-01';

SELECT STDDEV(commision) FROM salesman;
    
-- First & last order of 22
SELECT * FROM orders WHERE ord_date >= '2022-1-01' ORDER BY ord_date LIMIT 1;
SELECT * FROM orders WHERE ord_date >= '2022-1-01' ORDER BY ord_date DESC LIMIT 1;
    
-- Group by - City wise average commision
SELECT city, COUNT(*), AVG(commision) FROM salesman GROUP BY city;

-- Group by - Group customers with same grade, also we show no. of customers of each grade
SELECT grade, COUNT(*) AS no_of_customers
	FROM customer GROUP BY grade;
    
-- Group by - Group customers with same grade, but, we only allow a/b/c grades, also we show no. of customers of each grade
SELECT grade, COUNT(*) AS no_of_customers
	FROM customer GROUP BY grade HAVING grade IN ('A','B','C');


DROP TABLE salesman;
DROP TABLE customer;
DROP TABLE orders;
