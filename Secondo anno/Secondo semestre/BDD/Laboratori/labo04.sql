set search_path to 'unicorsi';

-- 1)la matricola degli studenti di informatica che nel mese di giugno 2010 hanno registrato voti 
-- sia per il corso di basi di dati 1 che per quello di interfacce grafiche - formulare senza usare operatori 
-- insiemistici [Formulare l'interrogazione senza usare operatori insiemistici, IN DUE DIVERSI MODI: usando 
-- EXISTS e sotto-interrogazione correlata E senza usare sotto-interrogazioni ma usando due alias sulle relazioni];
SELECT Matricola
FROM Studenti AS S
JOIN Esami ON Studente = Matricola 
JOIN Corsi ON Corso = Corsi.id
JOIN CorsiDiLaurea AS CL1 ON Corsi.CorsoDiLaurea = CL1.id
WHERE CL1.Denominazione = 'Informatica' 
AND Data BETWEEN '2010-06-01' AND '2010-06-30'
AND Corsi.Denominazione = 'Basi Di Dati 1'
AND EXISTS
(	SELECT Matricola 
	FROM Studenti 
	JOIN Esami ON Studente = Matricola 
 	JOIN Corsi ON Corso = Corsi.id
 	JOIN CorsiDiLaurea AS CL2 ON Corsi.CorsoDiLaurea = CL2.id
	WHERE CL2.Denominazione = 'Informatica' 
	AND Data BETWEEN '2010-06-01' AND '2010-06-30'
	AND Corsi.Denominazione = 'Interfacce Grafiche'
	AND S.Matricola = Matricola)
	
-- 1-alternativa)
SELECT DISTINCT S1.Matricola
FROM Studenti AS S1
JOIN Studenti AS S2 ON S1.Matricola = S2.Matricola
JOIN Esami AS E1 ON E1.Studente = S1.Matricola 
JOIN Esami AS E2 ON E2.Studente = S2.Matricola 
JOIN Corsi AS C1 ON E1.Corso = C1.id
JOIN Corsi AS C2 ON E2.Corso = C2.id
JOIN CorsiDiLaurea AS CL1 ON C1.CorsoDiLaurea = CL1.id
WHERE CL1.Denominazione = 'Informatica'
AND E1.Data BETWEEN '2010-06-01' AND '2010-06-30'
AND C1.Denominazione = 'Basi Di Dati 1'
AND C2.Denominazione = 'Interfacce Grafiche';


-- 2) la matricola degli studenti di informatica che hanno sostenuto basi di dati 1 
-- con votazione superiore alla votazione media (per tale esame);
SELECT DISTINCT Matricola studente
FROM Studenti AS S
JOIN Esami ON Studente = Matricola 
JOIN Corsi AS C ON Corso = C.id
JOIN CorsiDiLaurea ON C.CorsoDiLaurea = CorsiDiLaurea.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica'
AND C.Denominazione = 'Basi Di Dati 1'
AND Voto > 
( SELECT AVG(Voto)
 FROM Esami
 JOIN Corsi ON Corso = Corsi.id
 WHERE Corsi.Denominazione = C.Denominazione
)

-- 3) i nominativi dei professori che insegnano nel maggior numero di corsi;
SELECT Cognome, Nome, COUNT(Corsi.id)
FROM Professori AS P
JOIN Corsi ON Professore = P.id
GROUP BY Cognome, Nome
HAVING COUNT(Corsi.id) >= ALL 
(	SELECT COUNT(Corsi.id)
	FROM Corsi 
 	GROUP BY Professore)

-- 4) i professori che sono titolari dei corsi i cui voti medi sono i più  alti;
-- Nota: la media dei singoli corsi del prof è > della media di OGNI corso (non una unica)
SELECT DISTINCT Cognome, Nome, P.id
FROM Professori AS P
JOIN Corsi ON Professore = P.id
JOIN Esami ON Corso = Corsi.id
GROUP BY Cognome, Nome, P.id, Corsi.id
HAVING AVG(Voto) >= ALL
(	SELECT AVG(Voto)
	FROM Esami JOIN Corsi ON Corso = Corsi.id
	GROUP BY Corsi.id
)

-- 5) per ogni corso, la matricola degli studenti che hanno ottenuto un voto 
-- sotto la votazione media del corso, indicando anche corso e voto;
SELECT DISTINCT E.Corso, Matricola, Voto
FROM Studenti
JOIN Esami AS E ON Studente = Matricola
GROUP BY Matricola, E.Corso, Voto
HAVING Voto < ANY
(	SELECT AVG(Voto) 
 	FROM Esami
	WHERE E.Corso = Corso)
ORDER BY E.Corso

-- 6) per ogni docente, il suo tesista con la votazione media più alta;
-- Nota: media del tesista > media di ogni studente (group on studente)
SELECT P.Nome, P.Cognome, S.Nome, S.Cognome
FROM Professori AS P
JOIN Studenti AS S ON Relatore = P.id
JOIN Esami ON Studente = S.Matricola
GROUP BY P.Nome, P.Cognome, P.id, S.Nome, S.Cognome
HAVING AVG(Voto)
>= ALL
(SELECT AVG(Voto)
FROM Esami
JOIN Studenti ON Studente = Studenti.Matricola
WHERE Relatore = P.id
GROUP BY Studente)


-- 7) per ogni docente, i corsi correntemente attivati in cui ha attribuito una votazione media superiore 
-- alla votazione media assegnata da tale docente (indipendentemente dal corso);
-- Nota: media singolo corso del prof > media 'del prof' (per tutti i suoi corsi)
SELECT DISTINCT Nome, Cognome, Corsi.id corso
FROM Professori AS P
JOIN Corsi ON Professore = P.id
JOIN Esami ON Corso = Corsi.id
WHERE Corsi.Attivato = TRUE
GROUP BY Nome, Cognome, P.id, Corsi.id
HAVING AVG(Voto)
 >
(SELECT AVG(Voto)
 FROM Esami
 JOIN Corsi ON Corso = Corsi.id
 WHERE P.id = Professore
 )


-- 8) (*) gli studenti non ancora in tesi che hanno passato tutti gli esami del proprio corso di laurea.
SELECT Matricola
FROM Studenti S
WHERE relatore ISNULL
AND NOT EXISTS (
		SELECT *
		FROM Corsi C1
		WHERE S.corsoDiLaurea = C1.corsoDiLaurea
			AND NOT EXISTS (
				SELECT *
				FROM Esami
				WHERE S.matricola = studente
					AND C1.id = corso
			)
)

-- 8) Alternativa con count
SELECT matricola
FROM Studenti S
JOIN Esami ON Studente = Matricola
WHERE Relatore IS NULL
GROUP BY Matricola
HAVING COUNT(DISTINCT Corso) = (
	SELECT COUNT(*)
	FROM Corsi
	WHERE CorsoDiLaurea = S.CorsoDiLaurea
)