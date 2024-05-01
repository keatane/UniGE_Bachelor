set search_path to unicorsi;
set datestyle to "MDY";

-- INTERROGAZIONI SU SINGOLA RELAZIONE
SELECT Matricola, Cognome, Nome
FROM Studenti
WHERE Iscrizione <= 2007 AND Relatore IS NULL

SELECT Facolta, Denominazione
FROM CorsiDiLaurea
WHERE Attivazione < '2006/2007' OR Attivazione > '2009/2010'
ORDER BY Facolta, Denominazione

SELECT Matricola, Cognome, Nome
FROM Studenti
WHERE Residenza = 'Genova' OR Residenza = 'La Spezia' OR Residenza = 'Savona' OR Cognome <> 'Serra' OR Cognome <> 'Melogno' OR Cognome <> 'Giunchi'
ORDER BY Matricola DESC

-- INTERROGAZIONI SU PIU' RELAZIONI
SELECT Matricola
FROM Studenti JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
WHERE Laurea < '01/11/2009' AND Denominazione = 'Informatica'

SELECT Studenti.Cognome, Studenti.Nome, Professori.Cognome
FROM Studenti JOIN Professori ON Studenti.Relatore = Professori.id
ORDER BY Studenti.Cognome, Studenti.Nome ASC

SELECT DISTINCT Cognome, Nome
FROM Studenti 
JOIN PianiDiStudio ON PianiDiStudio.Studente = Studenti.Matricola
JOIN CorsiDiLaurea ON CorsiDiLaurea.id = Studenti.CorsoDiLaurea
WHERE Relatore IS NOT NULL AND Denominazione = 'Informatica' AND AnnoAccademico = 2011 AND Anno = '5'
ORDER BY Cognome DESC

-- OPERAZIONI INSIEMISTICHE
SELECT Cognome, Nome, 'Studente'
FROM Studenti
UNION
SELECT Cognome, Nome, 'Professore'
FROM Professori

SELECT Matricola
FROM Studenti
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Voto >= 18 AND Corsi.Denominazione = 'Basi Di Dati 1' 
AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'
EXCEPT
SELECT Matricola
FROM Studenti 
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Voto >= 18 AND Corsi.Denominazione = 'Interfacce Grafiche' 
AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'

SELECT Matricola
FROM Studenti
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Voto >= 18 AND Corsi.Denominazione = 'Basi Di Dati 1' 
AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'
INTERSECT
SELECT Matricola
FROM Studenti 
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
JOIN Corsi ON Esami.Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Voto >= 18 AND Corsi.Denominazione = 'Interfacce Grafiche' 
AND Esami.Data BETWEEN '06/01/2010' AND '06/30/2010'
