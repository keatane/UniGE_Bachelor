--creazione schema corsi 

CREATE schema "corsi";
set search_path to "corsi";
set datestyle to 'DMY';

CREATE TABLE Professori
       (Id   NUMERIC(5,0) PRIMARY KEY,
        Cognome  VARCHAR(20) NOT NULL, 
        Nome     VARCHAR(20) NOT NULL,
        Stipendio NUMERIC(8,2) DEFAULT 15000,
		InCongedo BOOLEAN DEFAULT FALSE,
	    UNIQUE (Cognome,Nome));
		
 INSERT INTO Professori VALUES (54661, 'guerrini','giovanna', 123456.78, FALSE);
 INSERT INTO Professori VALUES (49444, 'cattaneo','kevin', 14000.55, FALSE);
 INSERT INTO Professori VALUES (494, 'TestCognome', 'TestNome', 4000.00, TRUE);
 
 -- Inserimento fallito: violazione vincolo chiave primaria
 -- INSERT INTO Professori VALUES (494, 'marchini', 'marco', 5000, FALSE);
 -- Inserimento fallito: violazione vincolo unicità
 -- INSERT INTO Professori VALUES (4945, 'cattaneo', 'kevin', 5000, FALSE);
 -- Inserimento fallito: violazione vincolo NOT NULL
 -- INSERT INTO Professori VALUES (4945, 'rossi', NULL, 5000, FALSE);
 
 -- EXTRA
 ALTER TABLE Professori
 ALTER COLUMN Stipendio TYPE NUMERIC (9,2);
 
 -- Errore: Un campo con precisione 7 e 2 cifre decimali deve arrotondarsi ad un valore assoluto inferiore a 10^5.
 ALTER TABLE Professori
 ALTER COLUMN Stipendio TYPE NUMERIC (7,2);
 
 ALTER TABLE Professori
 DROP COLUMN InCongedo;
 
 ALTER TABLE Professori
 ADD CONSTRAINT check_stipendio CHECK(Stipendio >= 800)
 
 -- Inserimento fallito: violazione check stipendio
 INSERT INTO Professori VALUES (500, 'marchini', 'francesco', 600);
 -- Soluzione
 INSERT INTO Professori VALUES (500, 'marchini', 'francesco', 800);
 
 
-- DROP TABLE Corsi
 CREATE TABLE Corsi
       (Id   CHAR(10) PRIMARY KEY,
        CorsoDiLaurea  VARCHAR(20) NOT NULL, 
        Nome     VARCHAR(20) NOT NULL,
        Professore NUMERIC(5,0) REFERENCES Professori ON UPDATE CASCADE,
		Attivato BOOLEAN DEFAULT FALSE,
		MutuaDa CHAR(10) REFERENCES Corsi ON UPDATE CASCADE ON DELETE CASCADE
	    );
		
 INSERT INTO Corsi VALUES (1, 'Informatica', 'Programmazione', 49444, TRUE);
 INSERT INTO Corsi VALUES (2, 'Informatica', 'Calculus', 49444, TRUE);
 INSERT INTO Corsi VALUES (3, 'Informatica', 'Algebra', 54661, FALSE);
 -- Extra
  INSERT INTO Corsi VALUES (4, 'Informatica', 'Basi di dati', 54661, FALSE);
 INSERT INTO Corsi VALUES (5, 'Smid', 'Basi di dati', 54661, FALSE, 4);
 
 INSERT INTO Corsi VALUES (68, 'Informatica', 'tcs', NULL, NULL);
 INSERT INTO Corsi VALUES (69, 'Informatica', 'tcs', NULL, NULL);
 
 -- Errore: La chiave (corsodilaurea, nome)=(Informatica, tcs) è duplicata.
 ALTER TABLE Corsi
 ADD CONSTRAINT corsoDiLaurea_nome_unique UNIQUE(CorsoDiLaurea,Nome)
 
 UPDATE Corsi
 SET Nome = 'tds'
 WHERE Id = '69'
 
 -- Quanto sopra ora funziona
 ALTER TABLE Corsi
 ADD CONSTRAINT corsoDiLaurea_nome_unique UNIQUE(CorsoDiLaurea,Nome)
 
  -- Inserimento fallito: violazione vincolo integrità referenziale
  -- INSERT INTO Corsi VALUES (4, 'Informatica', 'APA', 4961, FALSE);
  -- Inserimento fallito: violazione vincolo NOT NULL
  -- INSERT INTO Corsi VALUES (3, 'Informatica', 'Algebra', NULL, FALSE);
  
UPDATE Professori
SET Nome = 'gianfranco'
WHERE Id = 494;

-- Cancellazione fallita: violazione vincolo chiave esterna:
	-- non posso cancellare un valore riferito esternamente
-- DELETE FROM Professori
-- WHERE Id = 49444; 

-- EXTRA
-- DROP TABLE Studenti
CREATE TABLE Studenti(
	Matricola SERIAL PRIMARY KEY,
	Cognome VARCHAR(20) NOT NULL,
	Nome VARCHAR(20) NOT NULL,
	CorsoDiLaurea VARCHAR(20),
	Iscrizione CHAR(9),
	Relatore NUMERIC(5,0) REFERENCES Professori ON UPDATE CASCADE);
	
INSERT INTO Studenti VALUES (DEFAULT, 'Cattaneo', 'Kevin', 'Informatica', '2020/2021', NULL);
INSERT INTO Studenti VALUES (DEFAULT, 'Rossi', 'Claudio', 'Chimica', '2021/2022', NULL);
INSERT INTO Studenti VALUES (DEFAULT, 'Legati', 'Anna', 'Fisica', '2020/2021', 54661);
