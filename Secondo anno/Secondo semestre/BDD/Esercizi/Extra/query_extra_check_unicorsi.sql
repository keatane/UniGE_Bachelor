set search_path to "unicorsi"

-- VINCOLI
-- 1) Specificare attraverso un vincolo CHECK che un esame non può essere sostenuto in data precedente la data di nascita dello studente che lo sostiene. Si riesce ad aggiungere tale vincolo? Perchè?

ALTER TABLE Esami
ADD CONSTRAINT checkDataNMinDataEs CHECK (Esami.data >= (
SELECT dataNascita
FROM Studenti
WHERE matricola = Esami.studente
));
-- Non viene inserito perchè non si può usare una sottoquery nel vincolo di controllo

-- 2) Specificare sulla relazione Corsi un vincolo che imponga l'unicità della colonna Professori. L'aggiunta del vincolo è possibile? Perché? 
ALTER TABLE Corsi
ADD CONSTRAINT prof_unique UNIQUE (Professore);
-- Non viene applicato perchè professore presenta un valore duplicato in Corsi

-- 3)
UPDATE Esami SET Voto = 18 WHERE Voto < 18;
UPDATE Esami SET Voto = 30 WHERE Voto > 30 AND Voto != 33;
ALTER TABLE Esami
ADD CONSTRAINT noEsamiMin18Max30Ex33 CHECK ((Esami.voto >= 18 AND Esami.voto <= 30) OR Esami.voto = 33);
-- Dopo l'aggiornamento di alcune tuple, è possibile applicare il vincolo
-- ALTER TABLE Esami DROP CONSTRAINT noEsamiMin18Max30Ex33

-- MODIFICHE
-- 1) Diminuire del 5% lo stipendio dei Professori che non sono relatori di alcuno studente.
UPDATE Professori SET Stipendio = stipendio*0.95 WHERE (id NOT IN 
(
SELECT Relatore
FROM Studenti
));

-- 2(*) Assegnare ad ogni professore titolare di un corso di informatica e relatore di almeno uno studente lo stipendio medio di tali professori aumentato del 5%. Verificare che dopo l’esecuzione del comando tutti tali professori abbiano lo stesso valore di stipendio.
UPDATE Professori SET Stipendio = (SELECT AVG(Stipendio)*1.05 FROM Professori WHERE id IN
(
SELECT Relatore
FROM Studenti
)
AND id IN
(
SELECT Professore
FROM Corsi JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica'
)
) WHERE (id IN 
(
SELECT Relatore
FROM Studenti
)
AND id IN
(
SELECT Professore
FROM Corsi JOIN CorsiDiLaurea ON CorsoDiLaurea = CorsiDiLaurea.id
WHERE CorsiDiLaurea.Denominazione = 'Informatica'
)
);


-- 3(*) Assegnare ai corsi che non hanno docente il docente che ha meno corsi attivi assegnati e che (a parità di numero di corsi assegnati) precede gli altri in ordine alfabetico.
UPDATE Corsi
SET professore = (
SELECT professore
FROM Corsi
GROUP BY professore
ORDER BY COUNT(*)
LIMIT(1)
)
WHERE professore IS NULL;


-- DATI DERIVATI, VISTE
-- 1(*) Definire una vista StudentiInfo che per gli studenti di informatica associ ad ogni studente le informazioni sul numero di esami che ha sostenuto con successo, la data del primo e quella dell'ultimo di tali esami e la votazione media conseguita, insieme al numero di esami sostenuti senza successo (cioè con votazione inferiore a 18) [per definire tale vista è necessario utilizzare delle altre viste o delle sottointerrogazioni nella clausola FROM].
CREATE VIEW StudentiSuff AS
SELECT matricola, COUNT(*) AS esamiSucc, MIN(Data), MAX(Data), AVG(Voto)
FROM Studenti JOIN Esami ON studente = matricola
WHERE Voto >= 18
GROUP BY matricola

--INSERT INTO Esami VALUES ('pd123745','elimm2','2022-05-18',14)
CREATE VIEW StudentiInsuff AS
SELECT matricola, COUNT(*) AS esamiInsucc
FROM Studenti JOIN Esami ON studente = matricola
WHERE Voto < 18
GROUP BY matricola

-- DROP VIEW StudentiInfo
CREATE VIEW StudentiInfo AS
SELECT StudentiSuff.matricola, esamiSucc, MIN(Data) as mini, MAX(Data) as maxi, AVG(Voto), esamiInsucc
FROM StudentiSuff JOIN Esami ON Studente = StudentiSuff.matricola
LEFT OUTER JOIN StudentiInsuff ON StudentiInsuff.matricola = StudentiSuff.matricola
GROUP BY StudentiSuff.matricola, esamiSucc, esamiInsucc

-- 2) Interrogare la vista StudentiInfo per trovare gli studenti che, a parità di esami sostenuti, hanno la votazione media più alta, limitandosi agli studenti che hanno sempre sostenuto con successo gli esami.
SELECT matricola
FROM StudentiInfo AS S JOIN Esami ON matricola = studente
WHERE esamiInsucc IS NULL
GROUP BY matricola, esamiSucc
HAVING AVG(Voto) >= ALL (SELECT AVG(Voto) FROM StudentiInfo JOIN Esami ON matricola = studente WHERE esamiSucc = S.esamiSucc GROUP BY matricola)

-- 3) Interrogare al vista StudenteInfo per trovare le coppie di Studenti che hanno sostenuto con successo almeno due esami e i cui periodi tra il primo e l'ultimo esame sostenuti con successo si sovrappongono, ordinati in base alla data del primo esame sostenuto con successo [può essere utile il predicato OVERLAPS].
SELECT S1.matricola AS m1, S2.matricola AS m2
FROM StudentiInfo S1, StudentiInfo S2
WHERE S1.esamiSucc >= 2 AND S2.esamiSucc >= 2 AND (S1.mini, S2.maxi + 1) OVERLAPS (S1.mini, S2.maxi) AND S1.matricola <> S2.matricola
ORDER BY(S1.mini)

-- 4) Creare una tabella derivata (usando CREATE TABLE AS) CorsiSenzaProf che contenga i corsi a cui non è associato un professore.
-- DROP TABLE CorsiSenzaProf
CREATE TABLE CorsiSenzaProf AS 
SELECT id, corsodilaurea, denominazione, professore, attivato
FROM Corsi
WHERE Professore IS NULL

-- MODIFICHE SU VISTE
-- (a) Inserire una tupla a vostra scelta, con professore non nullo, nella tabella CorsiSenzaProf.
INSERT INTO CorsiSenzaProf VALUES ('testcorso', 1, 'testcorso', 5, TRUE)
-- L'inserimento va a buon fine, l'idea è che viene creata una tabella completamente indipendente da Corsi, quindi i vincoli di corsi non riguardano la nuova tabella

-- (b) Definire ora CorsiSenzaProf2 come vista, con la stessa query di definizione, e senza check option. Inserire ora la stessa tupla di prima in CorsiSenzaProf2.
CREATE VIEW CorsiSenzaProf2 AS 
SELECT id, corsodilaurea, denominazione, professore, attivato
FROM Corsi
WHERE Professore IS NULL

INSERT INTO CorsiSenzaProf2 VALUES ('testcorso', 1, 'testcorso', 5, TRUE)
-- L'inserimento va a buon fine, nessun vincolo violato

-- (c) Definire ora CorsiSenzaProf3 come vista, con la stessa query di definizione, e con check option. Inserire ora la stessa tupla di prima in CorsiSenzaProf3.
CREATE VIEW CorsiSenzaProf3 AS 
SELECT id, corsodilaurea, denominazione, professore, attivato
FROM Corsi
WHERE Professore IS NULL
WITH CHECK OPTION

INSERT INTO CorsiSenzaProf3 VALUES ('testcorso', 1, 'testcorso', 5, TRUE)
-- Poichè ho già una vista che opera su Corsi, e ho precedentemente aggiunto una pkey uguale all'attuale, l'inserimento della stessa pkey nella nuova vista
-- fallisce, perchè viene controllato che il vincolo di pkey venga rispettato nella relazione di base.


