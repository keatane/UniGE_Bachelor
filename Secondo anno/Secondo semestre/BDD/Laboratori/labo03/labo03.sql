set search_path to unicorsi;  

-- OUTER JOIN
SELECT Corsi.id, Denominazione, Cognome, Nome
FROM Corsi LEFT OUTER JOIN Professori ON Corsi.Professore = Professori.id
ORDER BY Denominazione

SELECT S.Cognome, S.Nome, P.Cognome, P.Nome 
FROM Studenti AS S LEFT OUTER JOIN Professori AS P ON S.Relatore = P.id
JOIN CorsiDiLaurea ON S.CorsoDiLaurea = CorsiDiLaurea.id
WHERE Denominazione = 'Matematica'
ORDER BY S.Cognome, S.Nome


-- FUNZIONI DI GRUPPO
SELECT MIN(Voto), AVG(Voto), MAX(Voto)
FROM Esami 
JOIN Corsi ON Corsi.id = Esami.Corso
JOIN CorsiDiLaurea ON Corsi.CorsoDiLaurea = CorsiDiLaurea.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica'


SELECT Cognome, Nome, COUNT(*)
FROM Professori JOIN Corsi ON Corsi.Professore = Professori.id
WHERE Corsi.attivato = 'true'
GROUP BY Cognome, Nome
HAVING COUNT(*) > 2
ORDER BY Cognome, Nome


SELECT P.Cognome, P.Nome, COUNT(Relatore)
FROM Professori AS P LEFT OUTER JOIN Studenti ON Studenti.Relatore = P.id
GROUP BY P.Cognome, P.Nome
ORDER BY P.Cognome, P.Nome


SELECT Matricola, EXTRACT(MONTH FROM Esami.Data) AS Mese, EXTRACT(YEAR FROM Esami.Data) AS Anno, AVG(Esami.Voto) AS Media
FROM Studenti JOIN CorsiDiLaurea ON CorsiDiLaurea.id = Studenti.CorsoDiLaurea
JOIN Esami ON Esami.Studente = Studenti.Matricola
WHERE CorsiDiLaurea.Denominazione = 'Informatica'
GROUP BY Matricola, EXTRACT(MONTH FROM Esami.Data), EXTRACT(YEAR FROM Esami.Data)
HAVING COUNT(DISTINCT Corso) > 1

-- SOTTOINTERROGAZIONI SEMPLICI

SELECT DISTINCT Denominazione
FROM CorsiDiLaurea AS C JOIN Studenti ON Studenti.CorsoDiLaurea = C.id
WHERE Iscrizione = 2010 AND 
(SELECT COUNT(*) FROM Studenti 
 	JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
	WHERE CorsiDiLaurea.Denominazione = C.Denominazione)
<
(SELECT COUNT(*) FROM Studenti 
 	JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
	WHERE Denominazione = 'Informatica')
	
-- Alternativa
/*
SELECT DISTINCT Denominazione
FROM CorsiDiLaurea AS C JOIN Studenti ON Studenti.CorsoDiLaurea = C.id
WHERE Iscrizione = 2010
GROUP BY C.id
HAVING COUNT(Matricola) <
(	SELECT COUNT(*)
	FROM CorsiDiLaurea AS C JOIN Studenti ON Studenti.CorsoDiLaurea = C.id
	WHERE Iscrizione = 2010 AND Denominazione = 'Informatica')
*/

SELECT Matricola
FROM Studenti JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studenti.Matricola = Esami.Studente
WHERE Denominazione = 'Informatica' AND Voto = 
(SELECT MAX(Voto) FROM Esami)

SELECT DISTINCT Matricola
FROM Studenti AS S
JOIN Esami ON Esami.Studente = S.Matricola
JOIN Corsi ON Esami.Corso = Corsi.id
JOIN CorsiDiLaurea ON Corsi.CorsoDiLaurea = CorsiDiLaurea.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Corsi.Denominazione = 'Basi Di Dati 1' AND EXTRACT(MONTH FROM Esami.Data) = 6 AND EXTRACT(YEAR FROM Esami.Data) = 2010 
AND S.Matricola IN 
(	SELECT Matricola FROM Studenti 
 	JOIN Esami ON Esami.Studente = S.Matricola
	JOIN Corsi ON Esami.Corso = Corsi.id WHERE Corsi.Denominazione = 'Interfacce Grafiche')

