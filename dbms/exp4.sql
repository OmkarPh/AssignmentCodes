create database clg;
use clg;

CREATE TABLE customer_vip(
	customer_id INT PRIMARY KEY AUTO_INCREMENT,
    cust_name VARCHAR(20),
    city VARCHAR(20),
    grade CHAR,
    salesman_id INT,
    FOREIGN KEY (salesman_id) REFERENCES salesman(salesman_id)
);
INSERT INTO customer_vip(cust_name, city, grade, salesman_id) VALUES
('ronit', 'mumbai', 'B', 10),
('manan', 'mumbai', 'A', 2),
('komal', 'pune', 'A', 5),
('mangesh', 'mumbai', 'A', 10);


-- get orders done after july 
SELECT * FROM orders WHERE ord_date >= '2022-7-01';

-- get orders done after july with readable formatted date
SELECT *, DATE_FORMAT(ord_date,'%D %M %Y') AS formatted_order_date
	FROM orders WHERE ord_date >= '2022-7-01';

-- get orders done between july & oct
SELECT * FROM orders WHERE ord_date BETWEEN '2022-7-01' AND '2022-10-31';

    
SELECT SYSDATE();

SELECT TIME(SYSDATE());

SELECT TIMESTAMP(SYSDATE());

SELECT *,
	DATE_FORMAT(ord_date,'%D %M %Y') AS formatted_order_date,
	DATE_FORMAT(adddate(ord_date, 15), '%D %M %Y') AS max_order_fulfilment_date
	FROM orders WHERE ord_date >= '2022-7-01';
    
SELECT *,
	DATE_FORMAT(ord_date,'%D %M %Y') AS formatted_order_date,
    monthname(ord_date) AS MONTH,
    year(ord_date) AS YEAR
	FROM orders WHERE ord_date >= '2022-7-01';

    
SELECT *, commision * 10 AS commision_on_1000rs_order FROM salesman;

SELECT *,
	commision * 10 AS commision_on_1000rs_order,
    1000 + commision*10 + 0.18 * commision*10 AS 'Total order amount payable for 1000rs order'
    FROM salesman;
    
SELECT * FROM salesman WHERE salesman_id IN(10,2,3,4)   
UNION
SELECT * FROM salesman WHERE city != 'pune';  

SELECT cust_name, grade, city FROM customer WHERE city = 'pune'
SELECT cust_name, grade, city FROM customer WHERE grade = 'A';  

SELECT * FROM customer
UNION
SELECT * FROM customer_vip;
