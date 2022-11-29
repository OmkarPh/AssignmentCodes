create database omkar;
use omkar;

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
(60000, '', ,),
(22000, '', ,),
(500, '', ,),
(15000, '', ,),
(9000, '', ,)
;
SELECT * FROM orders;




DROP TABLE salesman;
DROP TABLE customer;
DROP TABLE orders;
