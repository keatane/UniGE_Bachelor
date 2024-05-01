set search_path to "unicorsi";

-- 1. la matricola degli studenti di informatica che nel mese di giugno 2010 hanno registrato voti per il corso di basi di dati 1 ma non per quello di interfacce grafiche - formulare senza usare operatori insiemistici [Formulare l'interrogazione senza usare operatori insiemistici, usando NOT EXISTS e sottointerrogazione correlata];
SELECT Matricola
FROM Studenti AS S
JOIN CorsiDiLaurea CL ON CorsoDiLaurea = CL.id
JOIN Esami ON Studente = Matricola
JOIN Corsi ON Corso = Corsi.id
WHERE CL.Denominazione = 'Informatica' AND Data BETWEEN '2010-06-01' AND '2010-06-30' AND Corsi.Denominazione = 'Basi Di Dati 1' 
AND NOT EXISTS (SELECT Matricola
	FROM Studenti 
	JOIN CorsiDiLaurea CL ON CorsoDiLaurea = CL.id
	JOIN Esami ON Studente = Matricola
	JOIN Corsi ON Corso = Corsi.id
 	WHERE Corsi.Denominazione = 'Interfacce Grafiche' AND Matricola = S.Matricola)


-- 2. la matricola dello studente di informatica che ha la votazione media più alta;
SELECT Matricola studente
FROM Studenti AS S
JOIN Esami ON Studente = S.Matricola
JOIN CorsiDiLaurea CL ON CorsoDiLaurea = CL.id
WHERE CL.Denominazione = 'Informatica'
GROUP BY Matricola
HAVING AVG(Voto)
>= ALL (SELECT AVG(Voto) FROM Studenti 
		JOIN Esami ON Studente = Matricola
		JOIN CorsiDiLaurea CL ON CorsoDiLaurea = CL.id
		WHERE CL.Denominazione = 'Informatica'
		GROUP BY Matricola)
		

-- 3. per ogni corso di informatica, di cui siano stati registrati almeno 2 esami con votazione superiore a 27, la votazione minima, media e massima conseguita in tale corso, insieme al nome del corso e al numero di esami registrati;
SELECT F.Denominazione, MIN(Voto), AVG(Voto), MAX(Voto), COUNT(Voto)
FROM Corsi F
JOIN Esami ON Corso = F.id
JOIN CorsiDiLaurea C ON CorsoDiLaurea = C.id
WHERE C.Denominazione = 'Informatica'
GROUP BY F.id
HAVING  F.Denominazione IN
(SELECT Corsi.Denominazione
FROM Corsi 
JOIN Esami ON Corso = Corsi.id
WHERE Voto > 27
GROUP BY Corsi.Denominazione
HAVING COUNT(Voto) >= 2
)


-- 4. i corsi in cui si ha il maggior numero di studenti con voti insufficienti;
SELECT C.Denominazione, CorsoDiLaurea, COUNT(Studente)
FROM Corsi AS C
JOIN Esami ON Corso = C.id
WHERE Voto < 18
GROUP BY C.Denominazione, CorsoDiLaurea
HAVING COUNT(Studente) >= ALL
			 (SELECT COUNT(Matricola) FROM Esami
			 	JOIN Studenti ON Matricola = Studente
			  	JOIN Corsi ON Corso = id
			 	WHERE Voto < 18
			 	GROUP BY Corsi.id)

-- 5. i corsi il cui professore titolare ́e relatore di qualche studente di un corso di laurea diverso da quello del corso; [è possibile formularla senza sottointerrogazioni, provate però a usare una sottointerrogazione per esercitarvi]
SELECT DISTINCT C.id, C.Denominazione 
FROM CorsiDiLaurea CL
JOIN Corsi C ON C.CorsoDiLaurea = CL.id
JOIN Professori P ON Professore = P.id -- per essere titolare del corso
JOIN Studenti S ON Relatore = P.id -- perchè relatore dello studente (join prof-studente e non corsidilaurea-studente, perchè coinvolgo solo gli studenti di cui il prof è titolare)
WHERE  Relatore IN
(	SELECT Relatore 
	FROM CorsiDiLaurea
 	JOIN Corsi ON Corsi.CorsoDiLaurea = CorsiDiLaurea.id
	JOIN Professori ON Corsi.Professore = Professori.id 
	JOIN Studenti ON Relatore = Professori.id
	WHERE Studenti.CorsoDiLaurea <> C.CorsoDiLaurea)
ORDER BY C.Denominazione


-- 6. (*) la frequenza delle bocciature, suddivisa per sessione, ovvero per mesi (hint: si può raggruppare rispetto ad un’espressione; se serve potete usare tabelle temporanee - Fare riferimento al comando CREATE [TEMPORARY] TABLE AS, di cui trovate i dettagli sul manuale - Fare attenzione al fatto che la divisione tra interi restituisce un intero (cioè 3/4 fa 0). Un modo di ottenere 0.75 dovete fare CAST a float dei due numeri prima di effettuare la divisione);
DROP TABLE ContaVoti
CREATE TEMPORARY TABLE ContaVoti AS SELECT EXTRACT(MONTH FROM Data) AS M, COUNT(Voto) AS C FROM Esami GROUP BY EXTRACT(MONTH FROM Data);
CREATE TEMPORARY TABLE SessioneSinglePerc AS
(SELECT EXTRACT(MONTH FROM Data) AS Sessione, (CAST(COUNT(Voto) AS float)/CAST(C AS float) * 100) AS perc
FROM Esami
JOIN ContaVoti ON M = EXTRACT(MONTH FROM Data)
WHERE Voto < 18
GROUP BY EXTRACT(MONTH FROM Data), Voto, C
)
SELECT Sessione, SUM(perc)
FROM SessioneSinglePerc
GROUP BY Sessione
ORDER BY Sessione

-- 7. per ogni corso, il cognome e il nome degli studenti che hanno ottenuto un voto sotto la votazione media del corso, indicando anche denominazione del corso e voto.
SELECT C.Denominazione, Cognome, Nome, Voto
FROM Studenti S 
JOIN Esami ON Studente = Matricola
JOIN Corsi C ON Corso = C.id
GROUP BY C.id, Cognome, Nome, Voto
HAVING Voto < ANY (SELECT AVG(Voto) FROM Esami WHERE Corso = C.id)
ORDER BY C.id

