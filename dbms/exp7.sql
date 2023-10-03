use clg;

SELECT salesman_id FROM salesman WHERE commision <= 1;
-- Select customers who deal with salesmen with affordable commisions (commision less than/equal to 1 %)
SELECT * FROM customer WHERE SALESMAN_ID IN(
	SELECT salesman_id FROM salesman WHERE commision <= 1
);

SELECT * FROM orders WHERE ord_no = 4;
-- Select orders made on dates after order no 4
SELECT * FROM orders WHERE ord_date > (
	SELECT ord_date FROM orders WHERE ord_no = 4
);

SELECT AVG(purchase_amt) FROM orders;
-- Select orders with above average purchase amount
SELECT * FROM orders WHERE purchase_amt > (
	SELECT AVG(purchase_amt) FROM orders
);

SELECT customer_id FROM customer WHERE city = 'pune';
-- Select orders where customer belongs to Pune city
SELECT * FROM orders WHERE customer_id IN (
	SELECT customer_id FROM customer WHERE city = 'pune'
);

SELECT MAX(purchase_amt) FROM orders;
-- Select order with max purchase amount
SELECT * FROM orders WHERE purchase_amt = (
	SELECT MAX(purchase_amt) FROM orders
);

-- Select customer with max order value
SELECT * FROM customer WHERE customer_id = (
	SELECT customer_id FROM orders WHERE purchase_amt = (SELECT MAX(purchase_amt) FROM orders)
)
