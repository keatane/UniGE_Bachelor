set search_path to 'unicorsi';

-- OUTER JOIN
-- 1) l’elenco dei cognomi, in ordine di codice identificativo, dei professori con l’indicazione del cognome, del nome e della matricola degli studenti di cui sono relatori, laddove seguano degli studenti per la tesi
SELECT P.id, P.Cognome, Matricola, S.Cognome, S.Nome
FROM Professori AS P 
LEFT OUTER JOIN Studenti AS S ON Relatore = id
ORDER BY P.id


-- FUNZIONI DI GRUPPO
-- 1) lo stipendio massimo, minimo e medio dei professori;

SELECT MAX(Stipendio), MIN(Stipendio), AVG(Stipendio)
FROM Professori


-- 2) il voto massimo registrato in ogni corso di laurea;
SELECT CorsiDiLaurea.Facolta, CorsiDiLaurea.Denominazione, MAX(Voto)
FROM Esami
JOIN Corsi ON Corso = Corsi.id
JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id 
GROUP BY CorsiDiLaurea.Facolta, CorsiDiLaurea.Denominazione

-- 3) i nomi dei corsi del corso di studio in informatica per i quali sono stati registrati meno di 5 esami a partire dal 1 aprile 2012 [(*) includendo anche i corsi per cui non sono stati registrati esami a partire dal 1 aprile 2012];
SELECT DISTINCT Corsi.Denominazione
FROM Corsi 
LEFT OUTER JOIN Esami ON Corso = Corsi.id
LEFT OUTER JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id 
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND (Data > '2012-04-01' OR Data IS NULL)
GROUP BY Corsi.id
HAVING COUNT(*) <= 5 
UNION
SELECT DISTINCT Corsi.Denominazione
FROM Corsi 
JOIN Esami ON Corso = Corsi.id
JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id 
WHERE CorsiDiLaurea.Denominazione = 'Informatica' AND Data < '2012-04-01'


-- SOTTOINTERROGAZIONI SEMPLICI
-- 1) il professore titolare del corso in cui ́è stata assegnata la votazione più alta;
SELECT P.Cognome, P.Nome
FROM Professori AS P 
JOIN Corsi ON Professore = P.id
JOIN Esami ON Corso = Corsi.id
WHERE Voto = (SELECT MAX(Voto) FROM Esami)


-- 2) la matricola degli studenti che si sono laureati in informatica prima del novembre 2009 - formulare usando una sotto-interrogazione e non join nè prodotto Cartesiano.
SELECT S.Matricola
FROM Studenti AS S 
WHERE EXISTS
(	SELECT *
	FROM Studenti
 	WHERE CorsoDiLaurea = 9 -- per 'Informatica' senza JOIN nè Cartesiano
 	AND Matricola = S.Matricola
)
AND EXISTS
(	SELECT *
	FROM Studenti
 	WHERE Laurea < '2009-11-01' AND Matricola = S.Matricola
)


-- 3) la matricola degli studenti di informatica che nel mese di giugno 2010 hanno registrato voti per il corso di basi di dati 1 ma non per quello di interfacce grafiche - formulare senza usare operatori insiemistici.
SELECT S.Matricola
FROM Studenti AS S 
JOIN CorsiDiLaurea AS CL ON CorsoDiLaurea = CL.id
JOIN Esami ON Studente = Matricola
JOIN Corsi ON Corso = Corsi.id
WHERE CL.Denominazione = 'Informatica' AND Data BETWEEN '2010-06-01' AND '2010-06-30'
AND Corsi.Denominazione = 'Basi Di Dati 1'
AND NOT EXISTS (SELECT * FROM Studenti JOIN Esami ON Studente = Matricola
				JOIN Corsi ON Corso = Corsi.id
			   	WHERE Corsi.Denominazione = 'Interfacce Grafiche' AND Matricola = S.Matricola)
