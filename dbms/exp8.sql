-- To Create a different view of database
use clg;












-- Create view of salesman in mumbai with affordable commission
CREATE VIEW affordable_salesman_mumbai AS SELECT * FROM salesman WHERE city = 'mumbai' AND commision <= 1.5;
SELECT * FROM affordable_salesman_mumbai;

-- Create view of equi join, with salesman & customer name for all orders
CREATE VIEW order_info as
SELECT orders.*, customer.cust_name, salesman.name AS salesman_name FROM orders
JOIN customer ON orders.customer_id = customer.customer_id
JOIN salesman ON salesman.salesman_id = salesman.salesman_id;
SELECT * FROM order_info;


-- Create view of orders in 2022
CREATE VIEW orders_2022 AS SELECT * FROM orders WHERE ord_date >= '2022-01-01' AND ord_date <= '2022-12-31';
SELECT * FROM orders_2022;

-- Insert into orders_2022 view
INSERT INTO orders_2022(purchase_amt, ord_date, customer_id, salesman_id) VALUES
(57500, '2022-12-8', 2, 10);
INSERT INTO orders_2022(purchase_amt, ord_date, customer_id, salesman_id) VALUES
(38000, '2022-12-13', 2, 10);
SELECT * FROM orders_2022;
SELECT * FROM orders;

-- Update row in orders_2022 view
UPDATE orders_2022 SET purchase_amt = 20000 WHERE ord_no = 10;
SELECT * FROM orders_2022;

-- Delete from orders_2022 view
DELETE FROM orders_2022 WHERE ord_no = 11;
SELECT * FROM orders_2022;

SELECT * FROM orders;

-- Drop views
DROP VIEW order_info;
DROP VIEW affordable_salesman_mumbai;
DROP VIEW orders_2022;