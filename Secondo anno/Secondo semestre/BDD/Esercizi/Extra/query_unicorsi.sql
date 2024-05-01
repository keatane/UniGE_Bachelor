set search_path to "unicorsi";


-- INTERROGAZIONI SU SINGOLA RELAZIONE
-- La matricola dello studente ‘Mario Rossi’, iscritto nell’anno accademico 2009/2010;
SELECT Matricola
FROM Studenti
WHERE Cognome = 'Rossi' AND Nome = 'Mario' AND Iscrizione = 2009;

-- L’elenco alfabetico dei comuni, diversi da Genova, in cui risiedono studenti (senza duplicati);
SELECT DISTINCT Residenza
FROM Studenti
WHERE Residenza <> 'Genova'
ORDER BY Residenza;

-- La matricola degli studenti che hanno registrato dei voti dal 2 febbraio del 2009;
SELECT DISTINCT Matricola
FROM Studenti JOIN Esami ON Studente = Matricola
WHERE Data >= '2009-02-02' AND Voto IS NOT NULL
ORDER BY Matricola;

-- Gli identificativi dei professori il cui nome contenga la stringa ‘te’ che abbiano uno stipendio compreso tra i 12500 e i 16000 euro l’anno.
SELECT DISTINCT Id
FROM Professori
WHERE Nome LIKE '%te%' AND Stipendio BETWEEN 12500 AND 16000;


-- INTERROGAZIONI CHE COINVOLGONO PIU' RELAZIONI
-- L’elenco dei nominativi dei professori, con, per ognuno, i corsi di cui sono titolari, in ordine decrescente di identificativo di corso;
SELECT Corsi.id, Denominazione, Cognome, Nome
FROM Professori, Corsi
WHERE Professore = Professori.id
ORDER BY Corsi.id DESC;

-- L’elenco alfabetico dei corsi, con i nominativi dei professori titolari, ordinati per corso di laurea, attivati;
SELECT Corsi.id, CorsoDiLaurea, Cognome, Nome
FROM Professori, Corsi, CorsiDiLaurea
WHERE Professore = Professori.id AND CorsoDiLaurea = CorsiDiLaurea.id AND Attivato = TRUE
ORDER BY CorsoDiLaurea ASC;

-- L’elenco dei corsi attivi nell’anno accademico corrente presso il corso di laurea di informatica, il cui nome abbia, come terza lettera, la lettera ‘s’ ;
SELECT Corsi.id, Corsi.Denominazione
FROM Corsi, CorsiDiLaurea
WHERE CorsoDiLaurea = CorsiDiLaurea.id AND Attivato = TRUE
	AND CorsiDiLaurea.Denominazione = 'Informatica' AND Corsi.Denominazione LIKE '__s%'
ORDER BY CorsoDiLaurea ASC;

-- La matricola degli studenti di matematica che hanno registrato voti sufficienti per l’esame di ‘Informatica Generale’ svoltosi il 15 febbraio 2012;
SELECT Matricola
FROM Studenti 
JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id
JOIN Esami ON Studente = Matricola
JOIN Corsi ON Corso = Corsi.id
WHERE CorsiDiLaurea.Denominazione = 'Matematica' AND Voto >= 18 AND Corsi.Denominazione = 'Informatica Generale' AND Data = '2012-02-15'
ORDER BY Matricola;

-- OPERAZIONI INSIEMISTICHE

-- Cognome e nome di studenti e professori.
SELECT Cognome, Nome
FROM Professori
UNION
SELECT Cognome, Nome
FROM Studenti

-- I professori  che hanno omonimi tra gli studenti (cioè studenti con lo stesso nome e cognome dei professori).
SELECT Cognome, Nome
FROM Professori
INTERSECT
SELECT Cognome, Nome
FROM Studenti
ORDER BY Cognome

-- Gli studenti che NON hanno omonimi tra i professori.
SELECT Cognome, Nome
FROM Studenti
EXCEPT
SELECT Cognome, Nome
FROM Professori
ORDER BY Cognome
