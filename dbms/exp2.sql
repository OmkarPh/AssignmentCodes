CREATE DATABASE clg;
USE clg;


CREATE TABLE bus (
	bus_no varchar(10) PRIMARY KEY,
    source_station varchar(20) NOT NULL,
    destination varchar(20) NOT NULL,
    couch_type varchar(20) DEFAULT 'Seater'
);

INSERT INTO bus VALUES('C-71', 'Oberoi Mall', 'Azad nagar', 'Sleeper');
INSERT INTO bus (bus_no, source_station, destination) VALUES('A-254', 'Andheri station', 'Versova');
INSERT INTO bus VALUES
('25', 'Ram nagar', 'SVSU garden', 'Seater'),
('A-167', 'Vile parle West', 'Tanaji nagar', 'Seater'),
('645', 'Hub mall', 'SKVM', 'Seater'),
('461', 'Borivali station', 'MB mart', 'Seater'),
('A-56', 'SRP camp', 'Kurar village', 'Sleeper');

SELECT * FROM bus;



CREATE TABLE reservation (
	pnr_no BIGINT PRIMARY KEY,
    journey_date DATE NOT NULL,
    no_of_seats INTEGER(9) NOT NULL,
    address VARCHAR(50),
    contact_no BIGINT CHECK(contact_no >= 1000000000 AND contact_no <= 9999999999),
    bus_no VARCHAR(10) NOT NULL,
    seat_no INT NOT NULL,
    FOREIGN KEY (bus_no) REFERENCES bus(bus_no)
);

INSERT INTO reservation VALUES (6783, '2022-11-25', 2, 'SRP CAMP rajendra nagar, Borivali West', 8887772355, 'A-56', 23);
INSERT INTO reservation VALUES (189, '2022-11-28', 3, 'azad nagar, Borivali West', 8328895926, 'A-56', 23);
INSERT INTO reservation VALUES
(8932, '2022-11-21', 1, 'Thakur complex, Kandivali', 9923454388, 'A-254', 42),
(8873, '2022-12-5', 4, 'Thakur complex, Malad', 8985345882, 'A-254', 32),
(8238, '2022-11-21', 3, 'Ram nagar, Andheri', 7238572384, 'A-254', 9),
(2321, '2022-12-29', 5, 'SG campus', 9923454388, 'A-167', 26),
(1234, '2022-12-5', 4, 'Shivaji nagar', 8985345882, '25', 9),
(43532, '2022-11-30', 1, 'Tanaji nagar, malad', 8482852972, '461', 2);

SELECT * FROM reservation;



CREATE TABLE ticket (
	ticket_no BIGINT PRIMARY KEY,
    journey_date DATE NOT NULL,
    age INT(4) NOT NULL,
    sex CHAR(10) DEFAULT 'male' CHECK(sex = 'male' OR sex = 'female'),
    source_station VARCHAR(20) NOT NULL,
    destination VARCHAR(20) NOT NULL,
    dep_time VARCHAR(10) NOT NULL,
    bus_no VARCHAR(10) NOT NULL,
    FOREIGN KEY(bus_no) REFERENCES bus(bus_no)
);

INSERT INTO ticket VALUES(9828592949, '2022-12-22', 25, 'male', 'Hub mall', 'Kurar village', '10:25 am', '645');
INSERT INTO ticket VALUES(8293877390, '2022-12-15', 26, 'female', 'azad nagar', 'SRP camp', '9:18 am', 'A-56');
INSERT INTO ticket VALUES
(9348734798, '2022-12-22', 16, 'male', 'GT nagar', 'Azad nagar', '12:25 pm', 'C-71'),
(88345884898, '2022-12-18', 17, 'female', 'SKVM', 'Pravin SD', '8:45 am', '461'),
(9934598549, '2022-12-22', 28, 'female', 'Shiv mandir', 'Tilak nagar', '9:20 pm', '645'),
(9889483847, '2022-12-22', 19, 'male', 'Rajendra nagar', 'Kurar village', '11:10 am', 'A-167'),
(9889239405, '2022-12-22', 19, 'female', 'GTS', 'SKVM', '7:56 pm', '25'),
(8293877327, '2022-12-22', 57, 'female', 'SGT', 'SRP camp', '8:20 am', 'A-56'),
(9889138984, '2022-12-22', 45, 'female', 'JB nagar', 'Andheri', '9:11 am', 'A-254');

SELECT * FROM ticket;



CREATE TABLE passenger(
	pnr_no BIGINT PRIMARY KEY,
	ticket_no BIGINT,
    name VARCHAR(15),
    age INT(4) NOT NULL,
    sex CHAR(10) DEFAULT 'male' CHECK(sex = 'male' OR sex = 'female'),
    contact_no BIGINT CHECK(contact_no >= 1000000000 AND contact_no <= 9999999999),
    FOREIGN KEY(ticket_no) REFERENCES ticket(ticket_no),
    FOREIGN KEY(pnr_no) REFERENCES reservation(pnr_no)
);

INSERT INTO passenger VALUES(189, 8293877390, 'Ryan', 32, 'male', 9238923949);
INSERT INTO passenger VALUES
(6783, 9828592949, 'John', 25, 'male', 8887772355),
(8932, 88345884898, 'Jane', 17, 'female', 9923454388),
(43532, 9934598549, 'Mina', 28, 'female', 8482852972),
(1234, 9889239405, 'Mark', 20, 'male', 8985345882),
(8873, 9934598549, 'Martha', 35, 'female', 8985345882),
(8238, 8293877327, 'Jemima', 57, 'female', 7238572384),
(2321, 9889483847, 'Samuel', 19, 'male', 9923454388);

SELECT * FROM passenger;


CREATE TABLE cancellation(
	pnr_no BIGINT PRIMARY KEY,
    journey_date DATE NOT NULL,
    seat_no INT NOT NULL,
    contact_no BIGINT CHECK(contact_no >= 1000000000 AND contact_no <= 9999999999),
    FOREIGN KEY(pnr_no) REFERENCES reservation(pnr_no)
);



INSERT INTO cancellation VALUES
(6783, '2022-11-25', 23, 8887772355),
(8932, '2022-11-21', 42, 9923454388),
(43532, '2022-11-30', 2, 8482852972),
(1234, '2022-12-5', 9, 8985345882),
(8873, '2022-12-5', 32, 8985345882),
(8238, '2022-11-21', 32, 7238572384),
(2321, '2022-12-29', 26, 9923454388);

SELECT * FROM cancellation;




ALTER TABLE passenger ADD city varchar(20) DEFAULT 'Mumbai';
UPDATE passenger SET city = 'Palghar' WHERE pnr_no IN(1234, 2321, 8873);
SELECT * FROM passenger;



DELETE FROM passenger WHERE pnr_no = 189;
SELECT * FROM passenger;


SELECT * FROM passenger WHERE sex = 'female' AND age > 20;



TRUNCATE TABLE passenger;
SET FOREIGN_KEY_CHECKS = 0; 
TRUNCATE TABLE ticket;
SET FOREIGN_KEY_CHECKS = 1;
SELECT * FROM ticket;



UPDATE passenger SET name = 'Rohan' WHERE pnr_no = 6783; 
SELECT * FROM passenger;