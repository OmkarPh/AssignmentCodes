-- If then else loop : 

DECLARE  
   a number(3) := 500;  
BEGIN  
   -- check the boolean condition using if statement   
   IF( a < 20 ) THEN  
      -- if condition is true then print the following    
      dbms_output.put_line('a is less than 20 ');  
   ELSE  
      dbms_output.put_line('a is not less than 20');  
   END IF;  
   dbms_output.put_line('value of a is : ' || a);  
END;  


-- For Loop : 

BEGIN  
FOR i IN 1..5 LOOP  
-- note that k was not declared  
DBMS_OUTPUT.PUT_LINE(i);  
END LOOP;   
END;

-- While Loop : 

DECLARE  
i INTEGER := 1;  
BEGIN  
WHILE i <= 6 LOOP  
DBMS_OUTPUT.PUT_LINE(i);  
i := i+1;  
END LOOP;  
END;  

-- Nested Loop 

-- Program uses a nested basic loop to find the prime numbers from 2 to 100
DECLARE 
   i number(3); 
   j number(3); 
BEGIN 
   i := 2; 
   LOOP 
      j:= 2; 
      LOOP 
         exit WHEN ((mod(i, j) = 0) or (j = i)); 
         j := j +1; 
      END LOOP; 
   IF (j = i ) THEN 
      dbms_output.put_line(i || ' is prime'); 
   END IF; 
   i := i + 1; 
   exit WHEN i = 50; 
   END LOOP; 
END;


--Now creation of table 

CREATE TABLE CUSTOMERS( 
   ID   INT NOT NULL, 
   NAME VARCHAR (20) NOT NULL, 
   AGE INT NOT NULL, 
   ADDRESS CHAR (25), 
   SALARY   DECIMAL (18, 2),        
   PRIMARY KEY (ID) 
);  

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (1, 'Aniruddha', 32, 'Ahmedabad', 2000.00 );  

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (2, 'Rupesh', 25, 'Delhi', 1500.00 );  

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (3, 'Omkar', 23, 'Kota', 2000.00 );

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (4, 'Devang', 25, 'Mumbai', 6500.00 ); 

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (5, 'Arpan', 27, 'Bhopal', 8500.00 );  

INSERT INTO CUSTOMERS (ID,NAME,AGE,ADDRESS,SALARY) 
VALUES (6, 'Rishabh', 22, 'MP', 4500.00 ); 

SELECT * FROM CUSTOMERS ORDER BY ID ASC;

--Cursor

DECLARE  
   total_rows number(2); 
BEGIN 
   UPDATE customers 
   SET salary = salary + 500; 
   IF sql%notfound THEN 
      dbms_output.put_line('no customers selected'); 
   ELSIF sql%found THEN 
      total_rows := sql%rowcount;
      dbms_output.put_line( total_rows || ' customers selected '); 
   END IF;  
END; 

--Predefined Exception : 

create table student(s_id int , s_name varchar(20), marks int); 
insert into student values(1, 'Suraj',100);
insert into student values(2, 'Praveen',97);
insert into student values(3, 'Jessie', 99);

select * from student order by s_id;

DECLARE
temp varchar(20); 

BEGIN
SELECT s_id into temp from student where s_name='Rahul'; 

exception 
WHEN no_data_found THEN
	dbms_output.put_line('ERROR'); 
	dbms_output.put_line('there is no name as'); 
	dbms_output.put_line('Rahul in student table'); 
end; 


DECLARE
a int:=10; 
b int:=0; 
answer int; 

BEGIN
answer:=a/b; 
dbms_output.put_line('the result after division is'||answer); 

exception 
WHEN zero_divide THEN
	dbms_output.put_line('dividing by zero please check the values again'); 
	dbms_output.put_line('the value of a is '||a); 
	dbms_output.put_line('the value of b is '||b); 
END; 

--User Defined Exception : 

DECLARE 
   c_id customers.id%type := -8; 
   c_name customers.Name%type; 
   c_addr customers.address%type;  
   -- user defined exception 
   ex_invalid_id  EXCEPTION; 
BEGIN 
   IF c_id <= 0 THEN 
      RAISE ex_invalid_id; 
   ELSE 
      SELECT  name, address INTO  c_name, c_addr 
      FROM customers 
      WHERE id = c_id;
      DBMS_OUTPUT.PUT_LINE ('Name: '||  c_name);  
      DBMS_OUTPUT.PUT_LINE ('Address: ' || c_addr); 
   END IF; 

EXCEPTION 
   WHEN ex_invalid_id THEN 
      dbms_output.put_line('ID must be greater than zero!'); 
   WHEN no_data_found THEN 
      dbms_output.put_line('No such customer!'); 
   WHEN others THEN 
      dbms_output.put_line('Error!');  
END; 
/

--@Rupesh-2003 will add some codes of trigger and function & procedure...
