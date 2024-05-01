-- CREATE SCHEMA "Pizze";
-- set search_path to "Pizze";

-- DROP TABLE Pizza, Cliente, Ordine

CREATE TABLE Pizza(
	CodP NUMERIC(2) PRIMARY KEY,
	Nome VARCHAR(50) UNIQUE NOT NULL,
	Costo NUMERIC(3,1) NOT NULL
);

INSERT INTO Pizza VALUES (1, 'marinara', 5);
INSERT INTO Pizza VALUES (2, 'margherita', 6);
INSERT INTO Pizza VALUES (3, 'napoli', 7);
INSERT INTO Pizza VALUES (4, 'prosciutto', 7.5);
INSERT INTO Pizza VALUES (5, 'prosciutto e funghi', 8);
INSERT INTO Pizza VALUES (6, 'capricciosa', 8);
INSERT INTO Pizza VALUES (7, 'vegetariana', 5);
INSERT INTO Pizza VALUES (8, 'quattro formaggi', 7.5);
INSERT INTO Pizza VALUES (9, 'mortadella e pistacchio', 7.5);
INSERT INTO Pizza VALUES (10, 'diavola', 7.5);
INSERT INTO Pizza VALUES (11, 'tartufo', 12);
INSERT INTO Pizza VALUES (12, 'pesto, bufala e pomodorini', 10);
INSERT INTO Pizza VALUES (13, 'wurstel', 7);
INSERT INTO Pizza VALUES (14, 'quattro stagioni', 6);

CREATE TABLE Cliente(
	TelC NUMERIC(4) PRIMARY KEY,
	NomeC VARCHAR(10) NOT NULL,
	Via VARCHAR(10) NOT NULL,
	NCiv VARCHAR(3) NOT NULL,
	NInt VARCHAR(5) NOT NULL
);

INSERT INTO Cliente VALUES (6610, 'rossi', 'scribanti', '16', 4);
INSERT INTO Cliente VALUES (6635, 'bianchi', 'dodecaneso', 16, 'uni');
INSERT INTO Cliente VALUES (6642, 'verdi', 'lagustena', 16, 7);
INSERT INTO Cliente VALUES (6628, 'verdi', 'rodi', '9A', 3);


CREATE TABLE Ordine(
	TelC NUMERIC(4) REFERENCES Cliente,
	Data CHAR(20),
	CodP NUMERIC(2) REFERENCES Pizza,
	Qta NUMERIC(2) NOT NULL,
	Importo NUMERIC(3,1) NOT NULL,
	PRIMARY KEY (TelC,Data,CodP)
);

INSERT INTO Ordine VALUES (6635, '04/03/20 20:35', 2, 2, 8);
INSERT INTO Ordine VALUES (6635, '04/03/20 20:35', 8, 1, 6);
INSERT INTO Ordine VALUES (6610, '05/03/20 20:15', 2, 3, 12);
INSERT INTO Ordine VALUES (6635, '05/03/20 20:23', 6, 1, 6);
INSERT INTO Ordine VALUES (6628, '05/03/20 20:35', 8, 1, 6);
INSERT INTO Ordine VALUES (6642, '06/03/20 20:12', 2, 3, 12);
INSERT INTO Ordine VALUES (6642, '06/03/20 20:12', 7, 1, 6);
INSERT INTO Ordine VALUES (6635, '06/03/20 20:27', 7, 2, 12);
INSERT INTO Ordine VALUES (6628, '07/03/20 19:50', 2, 10, 40);
INSERT INTO Ordine VALUES (6628, '07/03/20 19:50', 14, 1, 6);
INSERT INTO Ordine VALUES (6628, '07/03/20 19:50', 1, 11, 6);