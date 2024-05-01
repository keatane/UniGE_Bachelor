set search_path to "unicorsi";

-- ROUTINE
CREATE OR REPLACE FUNCTION AggiornaVal2(IN soglia NUMERIC(5), IN perc NUMERIC(5))
	RETURNS void AS
	$$
	DECLARE 
	medio NUMERIC(5);
	scarto NUMERIC(5);
	
	id VARCHAR(5);
	nome VARCHAR(30);
 	cognome VARCHAR(30);
	stip NUMERIC(5);
	
	viaggiatore CURSOR FOR 
			SELECT Cognome, Nome, stipendio
			FROM Professori;
	
	BEGIN -- utilizzo per più di un'istruzione, identifica un blocco
		IF (soglia > 100 AND perc BETWEEN 0 AND 100)
			THEN 	
			BEGIN 
					RAISE NOTICE 'Parametri corretti';
					
					SELECT AVG(stipendio) INTO medio
					FROM Professori LEFT OUTER JOIN Corsi ON Professore = Professori.id
					GROUP BY Corsi.id
					HAVING COUNT(Professore) = 1;
			END;
			ELSE 	RAISE NOTICE 'Parametri non corretti';
		END IF;
		IF medio < soglia
			THEN
			BEGIN
				OPEN viaggiatore;
				FETCH viaggiatore INTO id, nome, cognome, stip;
				WHILE FOUND LOOP
					BEGIN
						scarto := stip-soglia;
						IF(scarto < 0)
							THEN 
							BEGIN
								RAISE NOTICE 'Professore: id - %, nome - %, cognome - %, scarto - negativo', id, nome, cognome;
							END;
							ELSE
								RAISE NOTICE 'Professore: id - %, nome - %, cognome - %, scarto - %', id, nome, cognome, scarto;
						END IF;
					END;
				FETCH viaggiatore INTO id, nome, cognome, stip;
				END LOOP;
				
				UPDATE Professori
				SET stipendio = stipendio + (perc/100)*stipendio
				WHERE stipendio < soglia;
				
				CLOSE viaggiatore;
				END;
			END IF;
	END;
	$$ LANGUAGE plpgsql;
	
SELECT AggiornaVal2(150, 50);


-- TRIGGER

CREATE OR REPLACE FUNCTION controllaProfFun() RETURNS trigger AS
$$
BEGIN
	IF (
		SELECT COUNT(*) FROM Corsi
		WHERE attivato = 'true'
		AND professore = NEW.professore
		) >= 5
		THEN 
			RAISE EXCEPTION 'eccesso corsi attivi per prof';
	END IF;
END;
$$ LANGUAGE plpgsql;

-- DROP TRIGGER ControllaProf ON Corsi;
CREATE TRIGGER ControllaProf
BEFORE INSERT ON Corsi
FOR EACH ROW
EXECUTE PROCEDURE controllaProfFun();

-- 2)
DELETE FROM Corsi WHERE id = 'algo03'
INSERT INTO Corsi VALUES('algo01', 9, 'Algoritmi 1', 1, TRUE);
INSERT INTO Corsi VALUES('algo02', 9, 'Algoritmi 2', 1, TRUE);
INSERT INTO Corsi VALUES('algo03', 9, 'Algoritmi 3', 1, TRUE);
INSERT INTO Corsi VALUES('algo04', 9, 'Algoritmi 4', 1, TRUE);
-- non posso assegnare più di 5 corsi per uno stesso professore, come da trigger

-- 3)
UPDATE Corsi SET professore = 15 WHERE CorsoDiLaurea = 9 AND Attivato = FALSE;
UPDATE Corsi SET professore = 1 WHERE CorsoDiLaurea = 1 AND Attivato = FALSE;
UPDATE Corsi SET attivato = TRUE WHERE attivato = FALSE;
-- Non succede nulla, probabilmente perchè il prof di id 1 precedentemente aveva già i corsi
-- di matematica attivati, dunque il trigger non lancia eccezione (non aumenta il n di corsi)

-- 4)
DROP TRIGGER ControllaProf ON Corsi;

-- 5)
CREATE OR REPLACE FUNCTION controllaProfFunnoExp() RETURNS trigger AS
$$
BEGIN
	IF (
		SELECT COUNT(*) FROM Corsi
		WHERE attivato = 'true'
		AND professore = NEW.professore
		) >= 5
		THEN 
			RAISE NOTICE 'eccesso corsi attivi per prof';
	END IF;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER ControllaProf
BEFORE INSERT ON Corsi
FOR EACH ROW
EXECUTE PROCEDURE controllaProfFunNoExp();

-- UPDATE Corsi SET Attivato = FALSE  WHERE CorsoDiLaurea = 1 AND Attivato = TRUE;

UPDATE Corsi SET attivato = TRUE WHERE attivato = FALSE
-- Anche questa volta non accade nulla, e l'update va a buon fine.
-- Probabilmente i motivi sono similari alla scorsa update su corsi