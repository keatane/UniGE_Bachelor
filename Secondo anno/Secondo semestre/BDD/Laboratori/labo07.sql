-- 1) 
set search_path to "information_schema";
SELECT *
FROM table_privileges
WHERE table_schema = 'unicorsi'

-- 2)
CREATE USER yoda PASSWORD 'yoda';
CREATE USER luke PASSWORD 'luke';

-- 3)
set search_path to "unicorsi";
SELECT *
FROM Studenti
-- Vengo disconesso dalla sessione, con un tentativo di riconnessione che ha successo
-- Ottengo un errore, che segnala l'assenza della relazione 'studenti', 
-- probabilmente perchè non ho 'visibilità' (permesso di lettura) su tale tabella

-- 4)
set search_path to "information_schema";
SELECT *
FROM table_privileges
WHERE grantor = 'yoda' OR grantee = 'yoda'
-- La relazione è vuota con yoda, perchè non si hanno privilegi

-- 5)
GRANT USAGE ON SCHEMA unicorsi TO yoda WITH GRANT OPTION;
set search_path to "unicorsi";
GRANT SELECT
ON Professori, Studenti, Esami
TO yoda

GRANT SELECT
ON CorsiDiLaurea, Corsi
TO yoda
WITH GRANT OPTION

-- 6)
SET ROLE yoda

-- 7)
SELECT *
FROM Studenti
-- ora yoda ha il permesso di lettura e infatti può leggere Studenti
-- SET ROLE luke fallirebbe, non ho il permesso

-- 8)+
set search_path to "information_schema";
SELECT *
FROM table_privileges
WHERE grantee = 'yoda'
-- ho la tupla corrispondente all'autorizzazione SELECT su studenti data da postgres a yoda

-- 9)
SET ROLE yoda;
-- RESET ROLE
GRANT USAGE ON SCHEMA unicorsi TO luke WITH GRANT OPTION;
set search_path to "unicorsi";
GRANT SELECT
ON Studenti
TO luke
-- poichè yoda ha il permesso SELECT su studenti senza GRANT OPTION, non posso delegare il permesso SELECT

-- 10)
SET ROLE yoda;
GRANT SELECT
ON Corsi
TO luke
-- poichè yoda ha il permesso SELECT su corsi con GRANT OPTION, posso delegare il permesso SELECT

-- 11)
SET ROLE postgres;

-- 12)
set search_path to "unicorsi";
REVOKE SELECT
ON corsi
FROM yoda
RESTRICT
-- Non posso farlo perchè esistono privilegi dipendenti

-- 13)+
set search_path to "information_schema";
SELECT *
FROM table_privileges
WHERE grantor = 'yoda'
-- Viene mostrata correttamente una tupla ove yoda delega il permesso SELECT a luke, non permettendo il REVOKE RESTRICT

-- 14)
set search_path to "unicorsi";
REVOKE SELECT
ON corsi
FROM yoda
CASCADE

-- 15)+
set search_path to "information_schema";
SELECT *
FROM table_privileges
WHERE grantor = 'yoda' OR grantee = 'yoda'
-- a differenza del punto 13) ora non ho tuple corrispondenti a yoda - grantee per corsi e (yoda - grantor, luke - grantee) per corsi


-- 16)*
set search_path to "unicorsi";
GRANT CREATE ON SCHEMA unicorsi TO yoda;
SET ROLE yoda;
CREATE VIEW studenti_23 AS
SELECT matricola
FROM studenti
WHERE matricola LIKE '%23%'

SET ROLE yoda;
GRANT ALL
ON studenti_23
TO luke

-- La vista viene creata su una tabella su cui yoda ha i permessi, ad esempio STUDENTI
-- L'insieme dei privilegi delegabili è l'intersezione fra i permessi di yoda su STUDENTI (SELECT) e le operazioni eseguibili come owner della vista (ALL)
-- dunque yoda delega con ALL solo SELECT su studenti_23 a luke. 
-- Si nota in realtà che l'insieme dei permessi concessi a luke con ALL sono tutti i permessi di owner sulla vista.



-- TRANSAZIONI: OPERAZIONI E INFORMAZIONI PRELIMINARI

-- 1) 
set search_path to banca;

INSERT INTO ContoCorrente VALUES (0,100);
INSERT INTO ContoCorrente VALUES (5,0);

INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
INSERT INTO ContoCorrente VALUES (5,10);
INSERT INTO ContoCorrente VALUES (6,0);
-- Vengono inserite 5 sulle 6 elencate, perchè ho violazione di pkey
-- Vengono eseguite una transazione per comando
DELETE FROM ContoCorrente

-- 2)
INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
INSERT INTO ContoCorrente VALUES (5,10);
INSERT INTO ContoCorrente VALUES (6,0);
SELECT * FROM ContoCorrente
-- Selezionando tutto, lo comprendo all'interno di una stessa transazione
-- quindi l'autocommit, non agisce perchè ho 'esplicitato' con la selezione totale,
-- la modalità è immediata e quindi fallisce dopo la violazione del vincolo su pkey
-- nessuna tupla viene inserita

-- 3)
DELETE FROM ContoCorrente

BEGIN;
INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
INSERT INTO ContoCorrente VALUES (5,10);
INSERT INTO ContoCorrente VALUES (6,0);
COMMIT;
-- Stesso risultato del punto 2)

-- 4)
DELETE FROM ContoCorrente

BEGIN;
INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
COMMIT;
-- Non avendo violazione di pkey la transazione ha successo,
-- quindi l'inserimento ha successo

-- 5)
BEGIN;
INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
INSERT INTO ContoCorrente VALUES (5,10);
INSERT INTO ContoCorrente VALUES (6,0);
ROLLBACK;
SELECT * FROM ContoCorrente;
-- Non viene inserita alcuna tupla, viene ripristinato lo stato antecedente
-- alla transazione visto la violazione su pkey da parte di 5

-- 6)
DELETE FROM ContoCorrente
BEGIN;
SET CONSTRAINTS ALL DEFERRED; 
INSERT INTO ContoCorrente VALUES (1,0);
INSERT INTO ContoCorrente VALUES (2,0);
INSERT INTO ContoCorrente VALUES (3,0);
INSERT INTO ContoCorrente VALUES (4,0);
INSERT INTO ContoCorrente VALUES (5,10);
INSERT INTO ContoCorrente VALUES (6,0);
DELETE FROM ContoCorrente WHERE saldo >= 10;
COMMIT;
SELECT * FROM ContoCorrente;
-- Le tuple vengono inserite tutte, in quanto la valutazione dei vincoli viene eseguita alla fine
-- della transazione, viene infine tolta la tupla con chiave 5

-- 7)
BEGIN;
SET CONSTRAINTS ALL DEFERRED; 
INSERT INTO ContoCorrente VALUES (7,NULL);
DELETE FROM ContoCorrente WHERE numero = 7;
COMMIT;
SELECT * FROM ContoCorrente;
-- In questo caso la valutazione del NOT NULL è immediata, quindi fallisce immediatamente la transazione

-- 8)
INSERT INTO ContoCorrente VALUES (1,10);
INSERT INTO ContoCorrente VALUES (2,20);
INSERT INTO ContoCorrente VALUES (3,30);
INSERT INTO ContoCorrente VALUES (4,40);
INSERT INTO ContoCorrente VALUES (5,50);

-- SCHEDULE 1)
-- Eseguo T1, prima di effettuare COMMIT
-- T2 attende (T1 ha il lock), al COMMIT di T1 (rilascio del lock)
-- T2 non riesce a serializzare (meccanismo interno allo snapshot isolation di PostGre, non garantisce serializzabilità con REPEATABLE READS)
-- a causa di modifiche concorrenti e quindi T2 viene interrotta con ROLLBACK allo stato iniziale

-- SCHEDULE 2)
-- T1 esegue, T2 attende, T1 ROLLBACK (lock rilasciato) e T2 COMMIT, terminando correttamente (serializzabilità applicata)

-- SCHEDULE 3)
-- T1 esegue, T2 attende, T1 COMMIT (lock rilasciato) e T2 COMMIT, terminando correttamente (serializzabilità applicata)

-- SCHEDULE 4)
-- T1 esegue, T2 attende, T1 ROLLBACK (lock rilasciato) e T2 COMMIT, terminando correttamente (serializzabilità applicata)

-- SCHEDULE 5)
-- T1 esegue, T2 attende, T1 COMMIT (lock rilasciato) e T2 COMMIT, T1 termina correttamente inserendo la tupla con pkey pari a 6
-- ma al momento del rilascio del lock, quando T2 può modificare la tabella, l'inserimento non va a buon fine perchè è già
-- esistente una tupla con pkey 6

-- SCHEDULE 6)
-- T1 esegue, T2 attende, T1 ROLLBACK (lock rilasciato) e T2 COMMIT, l'inserimento della tupla con pkey pari a 7 va a buon fine
-- con la differenza che l'inserimento è stato effettuato da T2, in quanto T1 dopo l'inserimento fa ROLLBACK, tornando allo stato
-- precedente alla transazione (inserimento), quindi non esiste una tupla con pkey a 7 quando T2 la inserisce

-- SCHEDULE 7)
-- T1 esegue ma il lock è di tipo condiviso, quindi T2 lo prende esclusivo e modifica la tabella per poi rilasciarlo. Nel frattempo PostGre avverte che vi è una transazione
-- già in corso, ma tutto procede correttamente. La somma data da T1 è ora aggiornata con il nuovo valore inserito. T1 e T2 terminano correttamente.
-- Questo è possibile perchè READ COMMITTED (default) riferisce su uno snapshot isolation creato a livello di singolo comando 

-- SCHEDULE 8)
-- similmente al caso precedente, la tupla mostrata da T1 presenta correttamente il valore aggiornato da T2

-- SCHEDULE 9)
-- similmente al caso precedente, la tupla mostrata da T1 presenta correttamente il valore aggiornato da T2

-- 8(*)
-- S6 non cambia
-- S7 cambia:
	-- in T1 non viene visualizzata la modifica anche se T2 l'ha effettuata, modifica che è comunque visibile all'esterno di T1.
	-- In accordo a quanto scritto circa i livelli di isolamento REPEATABLE READS si focalizza su uno snapshot creato dalle transazioni committed fino a quel
	-- momento e quindi la transazione fa riferimento a una versione del db precedente a quella attuale (ove il dato non è ancora stato aggiornato), quindi
	-- lo snapshot isolation non è creato a livello di singolo comando
-- S8 cambia: similmente al caso di S7
-- S9 non cambia
