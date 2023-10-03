USE clg;

SELECT *
FROM customer, salesman
WHERE customer.salesman_id = salesman.salesman_id;

-- Natural join
SELECT customer.*, salesman.name AS Salesman, salesman.city AS 'Salesman city', commision
FROM customer NATURAL JOIN salesman;

-- Equi join
SELECT * FROM orders JOIN customer ON orders.customer_id = customer.customer_id;

SELECT * FROM orders JOIN customer ON orders.customer_id = customer.customer_id WHERE purchase_amt > 20000;


SELECT * FROM orders LEFT JOIN customer ON orders.customer_id = customer.customer_id;



-- Non equi join
SELECT * FROM orders JOIN salesman ON orders.purchase_amt > salesman.commision * 0.01 * orders.purchase_amt * 110;


-- Self join
SELECT A.cust_name AS CustomerA, B.cust_name AS CustomerB, A.city
FROM customer A, customer B
WHERE A.customer_id <> B.customer_id
AND A.city = B.city
AND A.grade IN('A') AND B.grade IN('A')
ORDER BY A.city;


-- left Outer join
SELECT * FROM orders LEFT OUTER JOIN customer ON orders.customer_id = customer.customer_id;

-- right Outer join
SELECT * FROM orders RIGHT OUTER JOIN customer ON orders.customer_id = customer.customer_id;

-- full Outer join
SELECT * FROM orders LEFT OUTER JOIN customer ON orders.customer_id = customer.customer_id
UNION 
SELECT * FROM orders RIGHT OUTER JOIN customer ON orders.customer_id = customer.customer_id;


-- Inner join
SELECT * FROM customer INNER JOIN salesman ON customer.salesman_id != salesman.salesman_id
WHERE salesman.city = customer.city;

