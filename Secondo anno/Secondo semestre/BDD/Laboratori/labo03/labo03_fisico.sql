set search_path to unicorsi;  

-- BASE DI DATI A LIVELLO FISICO
SHOW data_directory
-- Risultato: D:/Programs/PostGreSQL/data

SELECT datname,oid
FROM pg_database;
-- Risultato: D:/Programs/PostGreSQL/data/base/13754

SELECT N.oid, N.nspname, C.relname, C.relfilenode, C.relpages, C.reltuples
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
WHERE  N.nspname = 'unicorsi' AND relname IN ('corsi','corsidilaurea', 'professori','studenti','esami','pianidistudio');
-- Risultato: Unicorsi(24586): PianiDiStudio(24652), CorsiDiLaurea(24594), Corsi(24601), Professori(24587), Studenti(24619), Esami(24636) 

-- Risultato: Il file denominato 24587 in D:\Programs\PostGreSQL\data\base\13754 non viene aperto correttamente da un editor di testo,
	-- probabilmente perchè presenta qualche codifica (probabilmente binaria) associata ai nomi di alcuni Professori che invece rimangono visibili.
	-- dunque ci si aspetta che tale file contenga, associato ad ogni stringa, dettagli e riferimento in memoria per allocare lo spazio di ogni tabella


-- CREAZIONE INDICI
SELECT C.oid, relname, relfilenode, relam, relpages, relhasindex, relkind
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
WHERE N.nspname = 'unicorsi';
-- Risultato: sì sono già presenti indici creati da PostGre relativi a:
/* 
	primary key di PianiDiStudio
	primary key di Professori
	primary key di CorsiDiLaurea
	primary key di Corsi
	primary key di Studenti
	primary key di Esami
	chiave alternativa - Facoltà, Denominazione di CorsiDiLaurea
	chiave alternativa - CorsoDiLaurea, Denominazione di Corsi
	chiave alternativa - Cognome, Nome, DataNascita, LuogoNascita, CorsoDiLaure di Studenti
*/

SELECT C.oid, relname, relam, relpages, relkind, indexrelid, indrelid, indnatts, indisunique, indisprimary, indisclustered, indkey
FROM (pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace) JOIN pg_index ON C.oid = indexrelid
WHERE N.nspname = 'unicorsi'  ;

-- Risultato: Tutti gli indici presenti sono di tipo 403, in base a quanto descritto sopra fanno riferimento a
/* 1, 2, 3 o 5 attributi diversi con le relative posizioni indicate nel vector. Gli indici primari sono quelli riferiti alle primary key di cui sopra.
Sono tutti unique e nessuno è clusterizzato.
*/

-- un indice ordinato secondario sull’attributo voto della tabella esami
CREATE INDEX idx_ord_voto_esami
ON esami(voto);

-- un indice hash secondario sull’attributo iscrizione della tabella studenti
CREATE INDEX idx_hash_iscrizione_studenti
ON studenti USING HASH (iscrizione);

 -- un indice ordinato clusterizzato sull’attributo corsodilaurea della tabella  studenti
CREATE INDEX idx_ord_corsodilaurea_studenti
ON studenti(corsodilaurea);

CLUSTER studenti
USING idx_ord_corsodilaurea_studenti;

-- Ri-esecuzione del comando
SELECT C.oid, relname, relam, relpages, relkind, indexrelid, indrelid, indnatts, indisunique, indisprimary, indisclustered, indkey
FROM (pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace) JOIN pg_index ON C.oid = indexrelid
WHERE N.nspname = 'unicorsi'  ;

-- Risultato complessivo: Tutti gli indici presenti sono di tipo 403, a meno di quello hash a cui corrisponde 405 in base a quanto descritto sopra fanno riferimento a
/* 1, 2, 3 o 5 attributi diversi con le relative posizioni indicate nel vector. Gli indici primari sono quelli riferiti alle primary key di cui sopra.
I tre indici appena creati non sono unique, non sono primari e nessuno è clusterizzato a meno di quello ordinato su CorsiDiLaurea-Studenti.
*/