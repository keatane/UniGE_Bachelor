set search_path to "unicorsi";

-- VINCOLI
-- 1) Specificare attraverso un vincolo CHECK che un esame non può essere sostenuto in data successiva alla data odierna. Si riesce ad aggiungere tale vincolo? Perchè?
ALTER TABLE Esami DROP CONSTRAINT esami_nodata_successiva  
ALTER TABLE Esami ADD CONSTRAINT esami_nodata_successiva 
CHECK(Data <= CURRENT_DATE);
-- Si riesce ad aggiungere tale vincolo perchè tutte le tuple presentano una data di esame sostenuto precedente a quella attuale

-- 2) Specificare attraverso un vincolo CHECK che un esame non può essere sostenuto in data precedente il 1 gennaio 2014. Si riesce ad aggiungere tale vincolo? Perchè?
ALTER TABLE Esami ADD CONSTRAINT esami_nodata_prec1gennaio2014
CHECK (Data > '2014-01-01');
-- Non si riesce ad aggiungere tale vincolo perchè almeno una tupla viola il vincolo di controllo

-- 3) Specificare attraverso un vincolo CHECK che non è mai possibile che il relatore non sia specificato (relatore nullo) per uno studente che ha già iniziato la tesi ( laurea non nulla)
ALTER TABLE Studenti ADD CONSTRAINT relatore_notnull_studenteintesi
CHECK (Relatore IS NOT NULL AND Laurea IS NOT NULL);
-- Non si riesce ad aggiungere tale vincolo perchè almeno una tupla viola il vincolo di controllo

-- MODIFICHE
-- 1) Inserire nella relazione Professori:

-- (a)  i dati relativi al Professore Prini Gian Franco con identificativo 38 e stipendio 50000 euro;
INSERT INTO Professori VALUES (38, 'Prini', 'GianFranco', 50000);
-- (b)  i dati relativi alla Professoressa Stefania Bandini, con identificativo 39, senza specificare un valore per stipendio;
INSERT INTO Professori(id,Cognome,Nome) VALUES (39, 'Stefania', 'Bandini');
-- (c)  i dati relativi alla Professorressa Rosti, con identificativo 40, senza specificare nome proprio né stipendio.
INSERT INTO Professori(id,Cognome) VALUES (38, 'Rosti');

-- I comandi vanno a buon fine? Perchè?
-- I primi due inserimenti vanno a buon fine perchè non violano vincoli.
-- Il terzo inserimento viola il vincolo NOT NULL sull'attributo 'Nome'

-- 2) Aumentare di 5000 euro lo stipendio dei Professori che hanno uno stipendio inferiore a 15000 euro.
UPDATE Professori
SET stipendio = stipendio + 5000
WHERE stipendio < 15000

-- 3) Rimuovere il vincolo not null su Esami.voto mediante il comando alter table esami alter column voto drop not null;
alter table esami alter column voto drop not null;

INSERT INTO Corsi(id, corsodilaurea, denominazione) VALUES ('labinfo', 9, 'Laboratorio di Informatica');
INSERT INTO Esami(studente,corso,data) 
SELECT DISTINCT studente,corso,CURRENT_DATE
FROM Esami
JOIN Studenti ON Matricola = studente
JOIN Corsi ON Corsi.id = Corso
JOIN CorsiDiLaurea ON Studenti.CorsoDiLaurea = CorsiDiLaurea.id
WHERE Relatore IS NULL AND CorsiDiLaurea.Denominazione = 'Informatica' AND Corsi.Denominazione = 'Laboratorio di Informatica'

UPDATE Esami 
SET voto = (SELECT AVG(voto) FROM Esami) 
WHERE voto IS NULL AND Corso = 'labinfo'

alter table esami add constraint vnn check (voto is not null); 

-- DATI DERIVATI, VISTE
-- 1) Creare una vista StudentiNonInTesi che permetta di visualizzare i dati (matricola, cognome, nome, residenza, data di nascita, luogo di nascita, corso di laurea, anno accademico di iscrizione) degli studenti non ancora in tesi (che non hanno assegnato alcun relatore).
CREATE VIEW StudentiNonInTesi(matricola, cognome, nome, residenza, dataNascita, luogoNascita, corsoDiLaurea, iscrizione)
AS SELECT * FROM Studenti WHERE Relatore IS NULL

-- 2) Interrogare la vista StudentiNonInTesi per determinare gli studenti non in tesi nati e residenti a Genova.
SELECT * FROM StudentiNonInTesi WHERE residenza = 'Genova' AND luogoNascita = 'Genova'

-- 3) Creare la vista StudentiMate degli studenti di matematica non ancora laureati in cui ad ogni studente sono associate le informazioni sul numero di esami che ha sostenuto e la votazione media conseguita. Nella vista devono comparire anche gli studenti che non hanno sostenuto alcun esame.
DROP VIEW StudentiMate;
CREATE VIEW StudentiMate(matricola, cognome, nome, nesami, media)
AS SELECT matricola, cognome, nome, COUNT(Voto), AVG(Voto)
FROM Studenti
LEFT OUTER JOIN Esami ON Studente = Matricola
JOIN CorsiDiLaurea ON CorsiDiLaurea.id = Studenti.CorsoDiLaurea
WHERE Laurea IS NULL AND CorsiDiLaurea.Denominazione = 'Matematica'
GROUP BY Matricola


-- 4) Utilizzando la vista StudentiMate determinare quanti esami hanno sostenuto complessivamente glli studenti di matematica non ancora laureati.
SELECT SUM(nesami)
FROM StudentiMate



-- 5) Inserire una tupla a vostra scelta nella vista StudentiNonInTesi. L'inserimento va a buon fine? Perché? Esaminare l'effetto dell'inserimento, se andato a buon fine, sulla tabella Studenti
INSERT INTO StudentiNonInTesi VALUES (191919,'Cosulich','Marco','Genova','2001-11-02','Genova', 9, 2020);

-- 6) Inserire una tupla a piacere nella vista StudentiMate. L'inserimento va a buon fine? Perché? Esaminare l'effetto dell'inserimento, se andato a buon fine, sulla tabella Studenti.
INSERT INTO StudentiMate VALUES (191918,'Cattaneo','Kevin');
-- ERROR: ERRORE:  non è possibile inserire nella vista "studentimate"
-- DETAIL:  Le viste contenenti GROUP BY non sono aggiornabili automaticamente.
-- HINT:  Per consentire inserimenti nella vista occorre fornire un trigger INSTEAD OF INSERT oppure una regola ON INSERT DO INSTEAD senza condizioni.

