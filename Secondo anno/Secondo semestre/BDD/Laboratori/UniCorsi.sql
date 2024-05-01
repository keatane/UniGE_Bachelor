create schema "unicorsi";
set search_path to "unicorsi";
set datestyle to "MDY";

CREATE TABLE Professori(
Id decimal(5,0) PRIMARY KEY,
Cognome varchar(30) NOT NULL,
Nome varchar(30) NOT NULL,
Stipendio decimal(8,2) NOT NULL DEFAULT 15000 CHECK (Stipendio >=0)
);

INSERT INTO Professori  VALUES (1, 'Aguzzoli', 'Davide', 120000);
INSERT INTO Professori  VALUES (00002, 'Alberti', 'Maria', 16500);
INSERT INTO Professori  VALUES (00003, 'Bettini', 'Claudio', 18000);
INSERT INTO Professori  VALUES (00004, 'Borghese', 'Alberto', 12387);
INSERT INTO Professori  VALUES (00005, 'Cerri', 'Stefano Alberto', 30000);
INSERT INTO Professori  VALUES (00006, 'Campadelli', 'Laura', 13000);
INSERT INTO Professori  VALUES (00007, 'Ferrari', 'Mauro', 25000);
INSERT INTO Professori  VALUES (00008, 'De Falco', 'Stefano', 22000);
INSERT INTO Professori  VALUES (00009, 'Haus', 'Goffredo', 15000);
INSERT INTO Professori  VALUES (00010, 'Valle', 'Giorgio', 19760);
INSERT INTO Professori  VALUES (00011, 'Morpurgo', 'Anna', 18734);
INSERT INTO Professori  VALUES (00012, 'Aguzzoli', 'Stefano', 13700);
INSERT INTO Professori  VALUES (00013, 'Angeleri', 'Emanuele', 14000);
INSERT INTO Professori  VALUES (00014, 'Apolloni', 'Bruno', 17834);
INSERT INTO Professori  VALUES (00015, 'Bellettini', 'Carlo', 12000);
INSERT INTO Professori  VALUES (00016, 'Bertero', 'Gianni', 18000);
INSERT INTO Professori  VALUES (00017, 'Ribaudo', 'Carlo', 19500);
INSERT INTO Professori  VALUES (00018, 'Lamberti', 'Stefano', default);
INSERT INTO Professori  VALUES (00019, 'Galvagna', 'Gabriele', 17600);
INSERT INTO Professori  VALUES (00020, 'Levrero', 'Michele', 12000);
INSERT INTO Professori  VALUES (00021, 'Martini', 'Guido', 19800);
INSERT INTO Professori  VALUES (00022, 'Rondinelli', 'Maria', 13500);
INSERT INTO Professori  VALUES (00023, 'Rondinelli', 'Gianluigi', 13500);
INSERT INTO Professori  VALUES (00024, 'Rondinelli', 'Patrizio', 13500);
INSERT INTO Professori  VALUES (00025, 'Rosa', 'Aldo', 19200);
INSERT INTO Professori  VALUES (00026, 'Rondanino', 'Carmela', 19000);
INSERT INTO Professori  VALUES (00027, 'Cangini', 'Palmiro', 11200);
INSERT INTO Professori  VALUES (00028, 'Rondanino', 'Gianna', 19000);
INSERT INTO Professori  VALUES (00029, 'Vincenzini', 'Palmiro', 11200);
INSERT INTO Professori  VALUES (00030, 'Devoto', 'Gianni', 13500);
INSERT INTO Professori  VALUES (00031, 'Farazza', 'Valentina', 18000);
INSERT INTO Professori  VALUES (00032, 'Serra', 'Pietro', 22387);
INSERT INTO Professori  VALUES (00033, 'Fabrizi', 'Maura', 30000);
INSERT INTO Professori  VALUES (00034, 'Gavizzi', 'Stefania', 13000);
INSERT INTO Professori  VALUES (00035, 'Nizzi', 'Marco', 25000);
INSERT INTO Professori  VALUES (00036, 'Farano', 'Anna', 23000);
INSERT INTO Professori  VALUES (00037, 'Merlo', 'Anita', 20000);


-----------------------------------------------------------------------------------------
CREATE TABLE CorsiDiLaurea(
id decimal(3,0) PRIMARY KEY,
Facolta varchar(50) NOT NULL,
Denominazione varchar(50) NOT NULL,
Attivazione char(9) NOT NULL,
UNIQUE(Facolta, Denominazione)
);

INSERT INTO CorsiDiLaurea  VALUES (1, 'SS.MM.FF.NN', 'Matematica', '1980/1981');
INSERT INTO CorsiDiLaurea  VALUES (2, 'SS.MM.FF.NN', 'Chimica', '1990/1991');
INSERT INTO CorsiDiLaurea  VALUES (3, 'SS.MM.FF.NN', 'Scienze Biologiche', '2009/2010');
INSERT INTO CorsiDiLaurea  VALUES (4, 'SS.MM.FF.NN', 'Scienze Geologiche', '2008/2009');
INSERT INTO CorsiDiLaurea  VALUES (5, 'SS.MM.FF.NN', 'Chimica Industriale', '1992/1993');
INSERT INTO CorsiDiLaurea  VALUES (6, 'SS.MM.FF.NN', 'Fisica', '1995/1996');
INSERT INTO CorsiDiLaurea  VALUES (7, 'SS.MM.FF.NN', 'Scienza dei Materiali', '2005/2006');
INSERT INTO CorsiDiLaurea  VALUES (8, 'SS.MM.FF.NN', 'Scienze Ambientali', '2008/2009');
INSERT INTO CorsiDiLaurea  VALUES (9, 'SS.MM.FF.NN', 'Informatica', '2004/2005');
INSERT INTO CorsiDiLaurea  VALUES (10, 'SS.MM.FF.NN', 'Scienze dell''Informazione', '1996/1997');
INSERT INTO CorsiDiLaurea  VALUES (15, 'Agraria', 'Scienze e Tecnologie Alimentari','2004/2005');
INSERT INTO CorsiDiLaurea  VALUES (16, 'Economia', 'Economia e Commercio', '1992/1993');
INSERT INTO CorsiDiLaurea  VALUES (17, 'Ingegneria', 'Ingegneria Elettronica', '1982/1983');
INSERT INTO CorsiDiLaurea  VALUES (18, 'Medicina e chirurgia', 'Biotecnologie', '2008/2009');
INSERT INTO CorsiDiLaurea  VALUES (19, 'Giurisprudenza', 'Giurisprudenza', '2007/2008');
INSERT INTO CorsiDiLaurea  VALUES (20, 'Farmacia', 'Biotecnologie', '2004/2005');
INSERT INTO CorsiDiLaurea  VALUES (21, 'Agraria', 'Scienze Ambientali', '2009/2010');
INSERT INTO CorsiDiLaurea  VALUES (22, 'Agraria', 'Biotecnologie', '2002/2003');
INSERT INTO CorsiDiLaurea  VALUES (23, 'Agraria', 'Scienze e Tecnologie Agrarie', '2007/2008');
INSERT INTO CorsiDiLaurea  VALUES (24, 'Medicina e Chirurgia', 'Odontoiatria', '2007/2008');
INSERT INTO CorsiDiLaurea  VALUES (25, 'Lettere e Filosofia', 'Filosofia', '1985/1986');
INSERT INTO CorsiDiLaurea  VALUES (26, 'Lettere e Filosofia', 'Lettere', '1985/1986');
INSERT INTO CorsiDiLaurea  VALUES (27, 'Ingegneria', 'Ingegneria Informatica', '1995/1996');
------------------------------------------------------------------------------------------------

CREATE TABLE Corsi(
Id char(10) PRIMARY KEY,
CorsoDiLaurea decimal(3) NOT NULL REFERENCES CorsiDiLaurea (id) ON UPDATE CASCADE,
Denominazione varchar(50) NOT NULL,
Professore decimal(5,0)  REFERENCES Professori (id) ON DELETE NO ACTION ON UPDATE CASCADE,
Attivato boolean NOT NULL DEFAULT FALSE,
UNIQUE (CorsoDiLaurea, Denominazione)
);

INSERT INTO Corsi VALUES ('bdd1n', 9, 'Basi Di Dati 1', 15, TRUE);
INSERT INTO Corsi VALUES ('bdd2', 9, 'Basi Di Dati 2', 1, TRUE);
INSERT INTO Corsi VALUES ('ldp', 9, 'Linguaggi di Programmazione', 2, TRUE);
INSERT INTO Corsi VALUES ('r1', 9, 'Reti di calcolatori 1', 3, TRUE);
INSERT INTO Corsi VALUES ('r2', 9, 'Reti di Calcolatori 2', 3, TRUE);
INSERT INTO Corsi VALUES ('elimm1', 9, 'Elaborazione delle immagini 1', 5, TRUE);
INSERT INTO Corsi VALUES ('elimm2', 9, 'Elaborazione delle immagini 2', NULL, FALSE);
INSERT INTO Corsi VALUES ('mecraz', 27, 'Meccanica Razionale', NULL, FALSE);
INSERT INTO Corsi VALUES ('an1info', 9, 'Analisi 1', 1, TRUE);
INSERT INTO Corsi VALUES ('an2info', 9, 'Analisi 2', NULL, FALSE);
INSERT INTO Corsi VALUES ('an1mate', 1, 'Analisi 1', 1, TRUE);
INSERT INTO Corsi VALUES ('an2mate', 1, 'Analisi 2', NULL, FALSE);
INSERT INTO Corsi VALUES ('mate', 2, 'Istituzioni Matematiche', 2, TRUE);
INSERT INTO Corsi VALUES ('mat', 20, 'Istituzioni Matematiche', 1, TRUE);
INSERT INTO Corsi VALUES ('org1', 2, 'Chimica Organica 1', 10, TRUE);
INSERT INTO Corsi VALUES ('graf', 9, 'Grafica', 22, TRUE);
INSERT INTO Corsi VALUES ('ig', 9, 'Interfacce Grafiche', 22, TRUE);
INSERT INTO Corsi VALUES ('fis1', 6, 'Fisica 1', 1, TRUE);
INSERT INTO Corsi VALUES ('fis2', 6, 'Fisica 2 ', 2, TRUE);
INSERT INTO Corsi VALUES ('infogen', 6, 'Informatica Generale', 8, TRUE);
INSERT INTO Corsi VALUES ('infogenM', 1, 'Informatica Generale', 8, TRUE);
INSERT INTO Corsi VALUES ('matGen', 27, 'Istituzioni Matematiche', 14, TRUE);
INSERT INTO Corsi VALUES ('fis1si', 10, 'Fisica 1', 18, TRUE);
INSERT INTO Corsi VALUES ('fis2si', 10, 'Fisica 2', null, FALSE);
INSERT INTO Corsi VALUES ('ep', 25, 'Epistemologia', 7, TRUE);
INSERT INTO Corsi VALUES ('ai1', 10, 'Intelligenza Artificiale 1', 25, TRUE);
INSERT INTO Corsi VALUES ('ai2', 10, 'Intelligenza Artificiale 2', 27, TRUE);
INSERT INTO Corsi VALUES ('ai1in', 9, 'Intelligenza Artificiale 1', 23, TRUE);
INSERT INTO Corsi VALUES ('se', 9, 'Sistemi Esperti', 22, TRUE);
INSERT INTO Corsi VALUES ('it', 9, 'Informatica Teorica ', 20, TRUE);
INSERT INTO Corsi VALUES ('met', 10, 'Metodi', 19, TRUE);
INSERT INTO Corsi VALUES ('algo1', 9, 'Algoritmi e strutture dati 1', 15, TRUE);
INSERT INTO Corsi VALUES ('algo2', 10, 'Algoritmi e strutture dati 2', 15, TRUE);
INSERT INTO Corsi VALUES ('mraz', 6, 'Meccanica Razionale', 3, TRUE);
INSERT INTO Corsi VALUES ('mring', 17, 'Meccanica Razionale', 10, TRUE);
INSERT INTO Corsi VALUES ('info', 27, 'Informatica', 6, TRUE);
INSERT INTO Corsi VALUES ('ele1', 2, 'elettrochimica 1', 20, TRUE);
INSERT INTO Corsi VALUES ('ele2', 2, 'elettrochimica 2', 22, TRUE);
-----------------------------------------------------------------------------------------------------

/**** Studenti ****/
CREATE TABLE Studenti(
Matricola varchar(10) PRIMARY KEY,
Cognome varchar(30) NOT NULL,
Nome varchar(30) NOT NULL,
Residenza varchar(30) NOT NULL,
DataNascita date NOT NULL,
LuogoNascita varchar(30) NOT NULL,
CorsoDiLaurea decimal(3,0)  REFERENCES CorsiDiLaurea (id) ON UPDATE CASCADE NOT NULL,
Iscrizione integer NOT NULL,
Relatore decimal(5,0)  REFERENCES Professori (id) ON UPDATE CASCADE,
Laurea date,
UNIQUE(Cognome,Nome,DataNascita, LuogoNascita, CORSODILAUREA)
);

INSERT INTO Studenti VALUES
('pd123745', 'Rossi', 'Mario', 'Genova', '12/23/1987', 'Savona', 9, '2006', 1, NULL);
INSERT INTO Studenti VALUES
('se2084', 'Gelli', 'Mirko', 'Genova', '07/01/1990', 'Savona', 1, '2009', NULL, NULL);
INSERT INTO Studenti VALUES
('cdo42361', 'Parodi', 'Franca', 'Savona', '08/15/1989', 'Rimini', 4, '2008', 1, NULL);
INSERT INTO Studenti VALUES
('23re123', 'Verdi', 'Luisa', 'Roma', '08/04/1990', 'Bari', 4, '2009', 1, NULL);
INSERT INTO Studenti VALUES
('sc4023', 'Mercurio', 'Giuliano', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 21, NULL);
INSERT INTO Studenti VALUES
('pl5672', 'Merello', 'Fabrizio', 'Noli', '07/03/1990', 'Firenze', 6, '1999', 21, NULL);
INSERT INTO Studenti VALUES
('hg76394', 'Merella', 'Maurizio', 'Loano', '12/15/1986', 'Darfo B. T.', 9, '2005', 12, NULL);
INSERT INTO Studenti VALUES
('iu765', 'Gavilli', 'Dino', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 21, NULL);
INSERT INTO Studenti VALUES
('mf192', 'Fara', 'Vincenzo', 'Spotorno', '07/03/1985', 'Firenze', 9, '1999', 3, NULL);
INSERT INTO Studenti VALUES
('9uhg563', 'FAnizzi', 'Maurizio', 'Boissano', '12/15/1991', 'Milano', 1, '2003', 5, NULL);
INSERT INTO Studenti VALUES
('ed362', 'Gavizzi', 'Pietro', 'Bogliasco', '01/15/1989', 'Genova', 19, '2002', 7, '02/23/2010');
INSERT INTO Studenti VALUES
('kfi345', 'Fantino', 'Giuliano', 'Genova', '07/08/1990', 'Genova', 9, '2006', 4, '03/12/2011');
INSERT INTO Studenti VALUES
('pl489d', 'Bodrato', 'Fabrizio', 'Genova', '11/03/1990', 'Arquata Scrivia', 1, '2005', 1, NULL);
INSERT INTO Studenti VALUES
('hg763d', 'De Vecchi', 'Maurizio', 'Genova', '12/12/1989', 'Genova', 9, '2009', 4, NULL);
INSERT INTO Studenti VALUES
('12gt5', 'Devoto', 'Stefania', 'Genova', '06/25/1988', 'La Spezia', 9, '2006', 2, null);
INSERT INTO Studenti VALUES
('bd765', 'Gavilli', 'Mauro', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 21, NULL);
INSERT INTO Studenti VALUES
('ijff192', 'Fara', 'Vincenza', 'Spotorno', '07/03/1985', 'Firenze', 9, '1999', 3, NULL);
INSERT INTO Studenti VALUES
('45hg563', 'FAnizzi', 'Angela', 'Genova', '12/15/1991', 'Milano', 1, '2003', 5, '04/03/2011');
INSERT INTO Studenti VALUES
('e3462', 'Gavizzi', 'Simona', 'Bogliasco', '01/15/1989', 'Genova', 19, '2009', 7, null);
INSERT INTO Studenti VALUES
('kf7645', 'Fantino', 'Giulia', 'Genova', '07/08/1990', 'Genova', 9, '2006', 4, null);
INSERT INTO Studenti VALUES
('hy489d', 'Bodrato', 'Fabiana', 'Genova', '11/03/1990', 'Arquata Scrivia', 1, '2005', 1, NULL);
INSERT INTO Studenti VALUES
('h8u763d', 'De Vecchi', 'Massimiliano', 'Genova', '12/12/1989', 'Genova', 9, '2009', 4, NULL);
INSERT INTO Studenti VALUES
('23gt5', 'Devoto', 'Gianni', 'Genova', '06/25/1988', 'La Spezia', 9, '2006', 2, '10/24/2011');
INSERT INTO Studenti VALUES
('ki1235', 'Rossini', 'Mario', 'Genova', '12/23/1979', 'Genova', 9, '2004', 1, null);
INSERT INTO Studenti VALUES
('se26084', 'Gellini', 'Marco', 'Genova', '07/01/1990', 'Savona', 1, '2009', NULL, NULL);
INSERT INTO Studenti VALUES
('cdo361', 'Parodi', 'Francesco', 'Savona', '08/15/1989', 'Rimini', 4, '2008', 1, NULL);
INSERT INTO Studenti VALUES
('23re12yr3', 'De Vecchi', 'Luisa', 'Roma', '08/04/1990', 'Bari', 4, '2009', 1, NULL);
INSERT INTO Studenti VALUES
('sc47e023', 'Marcia', 'Giuliano', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 8, null);
INSERT INTO Studenti VALUES
('ed12yr3', 'Rossi', 'Mario', 'Roma', '08/04/1990', 'Bari', 4, '2009', 1, NULL);
INSERT INTO Studenti VALUES
('pl567re2', 'Marello', 'Fabrizio', 'Noli', '07/03/1990', 'Firenze', 6, '1999', 21, NULL);
INSERT INTO Studenti VALUES
('hg794', 'Marte', 'Maurizio', 'Loano', '12/15/1986', 'Brescia', 9, '2005', 12, NULL);
INSERT INTO Studenti VALUES
('12765tr', 'Gavizzi', 'Stefania', 'Roma', '06/13/1983', 'Roma', 19, '2002', 7, '02/21/2010');
INSERT INTO Studenti VALUES
('lu765', 'Gavilli', 'Daniela', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 21, NULL);
INSERT INTO Studenti VALUES
('mfiu192', 'Farassa', 'Vincenzina', 'Spotorno', '07/03/1985', 'Firenze', 9, '1999', 8, NULL);
INSERT INTO Studenti VALUES
('9ug563', 'Ferizzi', 'Maurizio', 'Boissano', '12/15/1991', 'Milano', 1, '2003', 5, NULL);
INSERT INTO Studenti VALUES
('xsed362', 'Gavilli', 'Giulio', 'Bogliasco', '01/15/1989', 'Genova', 19, '2002', 7, '02/21/2010');
INSERT INTO Studenti VALUES
('lofi345', 'Fantino', 'Alberto', 'Genova', '07/08/1990', 'Genova', 9, '2006', 4, '03/21/2011');
INSERT INTO Studenti VALUES
('pl9d', 'Bodrato', 'Emanuele', 'Genova', '11/03/1990', 'Arquata Scrivia', 1, '2005', 1, NULL);
INSERT INTO Studenti VALUES
('hg7d', 'Devoto', 'Marilena', 'Genova', '12/12/1989', 'Genova', 9, '1999', 4, NULL);
INSERT INTO Studenti VALUES
('12olgt5', 'Casaccio', 'Stefania', 'Genova', '06/25/1988', 'La Spezia', 9, '2006', 2, null);
INSERT INTO Studenti VALUES
('bd70f65', 'Novarese', 'Mauro', 'La Spezia', '01/06/1990', 'Novi Ligure', 9, '2006', 21, NULL);
INSERT INTO Studenti VALUES
('ijfer92', 'Novella', 'Vincenza', 'Spotorno', '07/03/1985', 'Firenze', 9, '1999', 3, NULL);
INSERT INTO Studenti VALUES
('43olg563', 'Filli', 'Angela', 'Genova', '12/15/1991', 'Milano', 1, '2003', 5, NULL);
INSERT INTO Studenti VALUES
('cde3462', 'Licci', 'Simona', 'Bogliasco', '01/15/1989', 'Genova', 19, '2005', 7, null);
INSERT INTO Studenti VALUES
('kf76hy', 'Damassino', 'Giulia', 'Genova', '07/08/1990', 'Genova', 9, '2006', 4, null);
INSERT INTO Studenti VALUES
('hy4mj89d', 'Baroncelli', 'Fabiana', 'Genova', '11/03/1990', 'Arquata Scrivia', 1, '2005', 1, NULL);
INSERT INTO Studenti VALUES
('h3d', 'De Sanctis', 'Massimiliano', 'Genova', '12/12/1989', 'Genova', 9, '2009', 4, NULL);
INSERT INTO Studenti VALUES
('23glot5', 'Danza', 'Gianni', 'Genova', '06/25/1988', 'La Spezia', 9, '2006', 2, null);
INSERT INTO Studenti VALUES
('dy192', 'Farazza', 'Valentina', 'Genova', '07/03/1982', 'Firenze', 6, '1999', 3, '07/03/2006');
INSERT INTO Studenti VALUES
('rehg563', 'Fabrizi', 'Maura', 'Boissano', '12/15/1983', 'Milano', 6, '2002', 5, '04/03/2007');
INSERT INTO Studenti VALUES
('ewd362', 'Serra', 'Pietro', 'Genova', '01/15/1986', 'Genova', 6, '2002', 7, '02/21/2009');
INSERT INTO Studenti VALUES
('kefi345', 'Melogno', 'Giuliano', 'Genova', '07/08/1984', 'Genova', 6, '2003', 4, '03/12/2010');
INSERT INTO Studenti VALUES
('dy3192', 'Farazza', 'Michele', 'Genova', '07/03/1982', 'Firenze', 9, '2010', null, null);
INSERT INTO Studenti VALUES
('r5g563', 'Fabrizi', 'Morena', 'Boissano', '12/15/1983', 'Milano', 9, '2010', null, null);
INSERT INTO Studenti VALUES
('e8fdy62', 'Serra', 'Paride', 'Genova', '01/15/1986', 'Genova', 9, '2010', null, null);
INSERT INTO Studenti VALUES
('kedue45', 'Melogno', 'Gennaro', 'Genova', '07/08/1984', 'Genova', 9, '2010', null, null);

 INSERT INTO Studenti VALUES ('dy3192fr', 'Farazza', 'Michele','Genova', '07/03/1990', 'Firenze', 1, '2010', null,null);
 INSERT INTO Studenti VALUES ('r5g56de3', 'Fabrizi', 'Morena', 'Boissano', '12/15/1988', 'Milano', 1, '2010', null, null);
 INSERT INTO Studenti VALUES ('e8fdy62fs', 'Serra', 'Paride', 'Genova', '01/15/1990', 'Genova', 6, '2010', null, null);
 INSERT INTO Studenti VALUES ('kedue45srt', 'Melogno', 'Gennaro', 'Genova', '07/08/1989', 'Genova', 6, '2010', null,null);
 INSERT INTO Studenti VALUES ('kee45srt', 'Melogno', 'Gennaro', 'Genova', '07/08/1983', 'Genova', 6, '2010', null, null);



INSERT INTO Studenti VALUES
('af198aa', 'Farano', 'Anna', 'Spotorno', '07/03/1985', 'Firenze', 9, '2007', 3, '02/23/2013' );
INSERT INTO Studenti VALUES
('nm4hg56', 'Nizzi', 'Marco', 'Genova', '12/15/1989', 'Genova', 1, '2008', 5,'02/03/2013');
INSERT INTO Studenti VALUES
('am166mm', 'Merlo', 'Anita', 'Rapallo', '07/03/1989', 'Genova', 9, '2008', 3, '06/23/2013' );


---------------------------------------------------------------------------------------------

/**** ESAMI ****/
CREATE TABLE Esami(
Studente varchar(10) REFERENCES Studenti 
(matricola) ON UPDATE CASCADE, /* aggiunto update*/
Corso char(10)  REFERENCES Corsi (id) ON UPDATE NO ACTION, /* aggiunto update*/
Data date,
Voto decimal(2,0) NOT NULL check (Voto  between 1 and 33),
PRIMARY KEY(Studente,Corso,Data)
);


INSERT INTO Esami VALUES ('23glot5', 'algo1', '02/20/2008', 21);
INSERT INTO Esami VALUES ('23glot5', 'graf', '7/20/2008', 25);
INSERT INTO Esami VALUES ('23glot5', 'bdd2', '02/27/2009', 29);
INSERT INTO Esami VALUES ('23glot5', 'bdd1n', '9/8/2010', 27);
INSERT INTO Esami VALUES ('23glot5', 'it', '06/2/2009', 30);
INSERT INTO Esami VALUES ('23glot5', 'ldp', '9/9/2011', 27);
INSERT INTO Esami VALUES ('23glot5', 'r1', '11/27/2009', 29);
INSERT INTO Esami VALUES ('23glot5', 'r2', '9/21/2011', 30);
INSERT INTO Esami VALUES ('bd70f65', 'algo1', '02/20/2008', 21);
INSERT INTO Esami VALUES ('bd70f65', 'graf', '7/20/2008', 25);
INSERT INTO Esami VALUES ('bd70f65', 'bdd2', '02/27/2009', 29);
INSERT INTO Esami VALUES ('bd70f65', 'bdd1n', '9/8/2010', 27);
INSERT INTO Esami VALUES ('bd70f65', 'it', '06/2/2009', 30);
INSERT INTO Esami VALUES ('bd70f65', 'ldp', '9/9/2011', 27);
INSERT INTO Esami VALUES ('bd70f65', 'r1', '11/27/2009', 29);
INSERT INTO Esami VALUES ('bd70f65', 'r2', '9/21/2011', 30);
INSERT INTO Esami VALUES ('h3d', 'algo1', '02/20/2010', 21);
INSERT INTO Esami VALUES ('h3d', 'graf', '7/20/2010', 25);
INSERT INTO Esami VALUES ('h3d', 'bdd2', '02/27/2011', 29);
INSERT INTO Esami VALUES ('h3d', 'bdd1n', '9/8/2011', 27);
INSERT INTO Esami VALUES ('ijff192', 'algo1', '02/20/2008', 21);
INSERT INTO Esami VALUES ('ijff192', 'graf', '7/20/2008', 20);
INSERT INTO Esami VALUES ('ijff192', 'bdd2', '02/27/2004', 19);
INSERT INTO Esami VALUES ('ijff192', 'an1mate', '02/27/2010', 19);
INSERT INTO Esami VALUES ('ijff192', 'bdd1n', '9/8/2010', 27);
INSERT INTO Esami VALUES ('ijff192', 'it', '04/2/2008', 30);
INSERT INTO Esami VALUES ('ijff192', 'ldp', '9/9/2011', 27);
INSERT INTO Esami VALUES ('ijff192', 'r1', '11/27/2009', 29);
INSERT INTO Esami VALUES ('ijff192', 'r2', '9/21/2011', 30);
INSERT INTO Esami VALUES ('sc47e023', 'bdd1n', '9/8/2010', 27);
INSERT INTO Esami VALUES ('sc47e023', 'it', '04/2/2008', 30);
INSERT INTO Esami VALUES ('sc47e023', 'ldp', '9/9/2011', 27);
INSERT INTO Esami VALUES ('sc47e023', 'r1', '11/27/2009', 29);
INSERT INTO Esami VALUES ('sc47e023', 'r2', '2/15/2012', 29);
INSERT INTO Esami VALUES ('hy489d', 'infogenM', '2/15/2010', 18);
INSERT INTO Esami VALUES ('43olg563', 'an2mate', '2/15/2010', 25);
INSERT INTO Esami VALUES ('43olg563', 'infogenM', '2/15/2012', 25);
INSERT INTO Esami VALUES ('45hg563', 'infogenM', '2/15/2012', 20);
INSERT INTO Esami VALUES ('hy4mj89d', 'infogenM', '2/15/2012', 19);
INSERT INTO Esami VALUES ('pl9d', 'infogenM', '2/15/2012', 19);
INSERT INTO Esami VALUES ('se2084', 'infogenM', '2/15/2012', 29);

----------------------------------------------------------------------------------------------------

/**** PianiDiStudio ****/
CREATE TABLE PianiDiStudio(
Studente varchar(10) REFERENCES Studenti (matricola) ON UPDATE CASCADE, /* aggiunto update*/
AnnoAccademico integer not null,
Anno decimal(1,0) check (Anno  between 1 and 6),
PRIMARY KEY(Studente,AnnoAccademico,Anno)
);


INSERT INTO PianiDiStudio VALUES ('kf7645', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('kf76hy', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('kfi345', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('mfiu192','2011', 5);
INSERT INTO PianiDiStudio VALUES ('ki1235', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('pd123745','2011', 5);
INSERT INTO PianiDiStudio VALUES ('sc4023', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('sc47e023','2011', 5);


------
INSERT INTO PianiDiStudio VALUES ('23re123', '2010', 2);
INSERT INTO PianiDiStudio VALUES ('45hg563', '2003', 1);
INSERT INTO PianiDiStudio VALUES ('45hg563', '2004', 2);
INSERT INTO PianiDiStudio VALUES ('45hg563', '2005', 3);
INSERT INTO PianiDiStudio VALUES ('45hg563', '2010', 4);
INSERT INTO PianiDiStudio VALUES ('bd765', '2006', 1);
INSERT INTO PianiDiStudio VALUES ('bd765', '2007', 2);
INSERT INTO PianiDiStudio VALUES ('bd765', '2008', 3);
INSERT INTO PianiDiStudio VALUES ('bd765', '2010', 4);
INSERT INTO PianiDiStudio VALUES ('bd765', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('23gt5', '2006', 1);
INSERT INTO PianiDiStudio VALUES ('23gt5', '2007', 2);
INSERT INTO PianiDiStudio VALUES ('23gt5', '2008', 3);
INSERT INTO PianiDiStudio VALUES ('23gt5', '2010', 4);
INSERT INTO PianiDiStudio VALUES ('23gt5', '2011', 5);
INSERT INTO PianiDiStudio VALUES ('h8u763d', '2009', 1);
INSERT INTO PianiDiStudio VALUES ('h8u763d', '2010', 2);
INSERT INTO PianiDiStudio VALUES ('h8u763d', '2011', 3);
--------------

INSERT INTO ESAMI VALUES('h3d', 'bdd1n', '10/08/2009', 20);
INSERT INTO ESAMI VALUES('bd70f65', 'bdd1n', '10/08/2009', 29);
INSERT INTO ESAMI VALUES('bd70f65', 'ig', '10/22/2009', 24);
INSERT INTO ESAMI VALUES('23glot5', 'bdd1n', '10/08/2009', 23);
INSERT INTO ESAMI VALUES('ijff192', 'bdd1n', '06/15/2010', 22);
INSERT INTO ESAMI VALUES('sc47e023', 'bdd1n', '06/15/2010', 20);
INSERT INTO ESAMI VALUES('ijff192', 'ig', '06/30/2010', 24);
INSERT INTO ESAMI VALUES('sc47e023', 'ig', '06/29/2010', 27);
INSERT INTO ESAMI VALUES('23glot5', 'algo1', '06/01/2010', 32);
INSERT INTO ESAMI VALUES('23glot5', 'ldp', '06/09/2010', 22);
INSERT INTO ESAMI VALUES('bd70f65', 'bdd1n', '10/08/2008', 12);
INSERT INTO ESAMI VALUES('bd70f65', 'ig', '09/01/2009', 15);
INSERT INTO ESAMI VALUES('23glot5', 'bdd1n', '02/12/2009', 10);
INSERT INTO ESAMI VALUES('ijff192', 'bdd1n', '01/15/2010', 8);
INSERT INTO ESAMI VALUES('sc47e023', 'ig', '04/12/2010', 16);
INSERT INTO ESAMI VALUES('23glot5', 'algo1', '04/01/2010', 12);
INSERT INTO ESAMI VALUES('23glot5', 'ldp', '01/07/2010', 13);
INSERT INTO Esami VALUES('23glot5', 'it', '04/01/2009', 10);
INSERT INTO Esami VALUES('23glot5', 'ldp', '7/9/2011', 7);
INSERT INTO Esami VALUES('23glot5', 'r1', '01/27/2009', 9);
INSERT INTO Esami VALUES('23glot5', 'r2', '02/21/2011', 10);
INSERT INTO Esami VALUES('bd70f65', 'algo1', '02/20/2007', 11);
INSERT INTO Esami VALUES('bd70f65', 'graf', '06/20/2008', 5);
INSERT INTO Esami VALUES('h8u763d', 'an1info', '02/21/2010', 10);
INSERT INTO Esami VALUES('hg76394', 'an1info', '02/21/2010', 8);
INSERT INTO Esami VALUES('hg763d', 'an1info', '02/21/2010', 15);
INSERT INTO Esami VALUES('h8u763d', 'an2info', '02/21/2011', 10);
INSERT INTO Esami VALUES('hg76394', 'an2info', '02/21/2011', 8);
INSERT INTO Esami VALUES('hg763d', 'an2info', '02/21/2011', 15);
INSERT INTO Esami VALUES('h8u763d', 'elimm1', '02/21/2009', 10);
INSERT INTO Esami VALUES('hg76394', 'elimm1', '02/21/2009', 8);
INSERT INTO Esami VALUES('hg763d', 'elimm2', '02/21/2009', 15);
INSERT INTO Esami VALUES('e8fdy62fs', 'fis1', '02/21/2009', 20);
INSERT INTO Esami VALUES('e8fdy62fs', 'fis2', '06/21/2009', 24);
INSERT INTO Esami VALUES('e8fdy62fs', 'infogen', '04/21/2010', 27);
INSERT INTO Esami VALUES('e8fdy62fs', 'mraz', '06/21/2011', 28);
INSERT INTO Esami VALUES('kee45srt', 'fis1', '02/21/2009', 20);
INSERT INTO Esami VALUES('kee45srt', 'fis2', '06/21/2009', 24);
INSERT INTO Esami VALUES('kee45srt', 'infogen', '04/21/2010', 27);
INSERT INTO Esami VALUES('kee45srt', 'mraz', '06/21/2011', 28);
INSERT INTO Esami VALUES('dy3192fr', 'an1mate', '06/21/2009', 24);
INSERT INTO Esami VALUES('dy3192fr', 'an2mate', '04/21/2010', 27);
INSERT INTO Esami VALUES('dy3192fr', 'infogenM', '06/21/2011', 28);
insert into esami values ('9ug563', 'an2mate', '06/07/2010', 14);   
insert into esami values ('dy3192fr', 'an2mate', '06/07/2010', 24);   
insert into esami values ('9uhg563', 'an2mate', '06/07/2010', 21);   
insert into esami values ('pl489d', 'infogenM', '06/15/2010', 22);   
insert into esami values ('kedue45srt', 'infogen', '06/12/2010', 14);   
insert into esami values ('kee45srt', 'fis2', '06/14/2010', 24);   
insert into esami values ('kefi345', 'fis2', '06/14/2010', 21);   
insert into esami values ('dy192', 'fis1', '06/30/2010', 22);
insert into esami values ('hg794', 'r2', '06/14/2010', 21);   
insert into esami values ('hg7d', 'r2', '06/30/2010', 22);
insert into esami values ('kfi345', 'algo1', '06/20/2010', 21);   
insert into esami values ('ki1235', 'elimm2', '06/20/2010', 22);   
insert into esami values ('kedue45', 'bdd1n', '06/20/2010', 21);   
insert into esami values ('lofi345', 'bdd1n', '06/20/2010', 22); 
insert into esami values ('sc4023', 'ig', '06/20/2010', 22);   
insert into esami values ('mf192', 'ig', '06/20/2010', 21);
insert into esami values ('r5g563', 'ig', '06/20/2010', 22); 
insert into esami values ('kf7645', 'bdd1n', '06/13/2010', 22); 
insert into esami values ('kf76hy', 'ig', '06/1/2010', 22);   
insert into esami values ('mfiu192', 'ig', '06/1/2010', 21);
insert into esami values ('pd123745', 'ig', '06/1/2010', 22); 


