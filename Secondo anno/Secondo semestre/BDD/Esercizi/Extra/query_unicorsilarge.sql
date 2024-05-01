set search_path to "unicorsilarge";

SELECT Nome 
FROM Professori;

EXPLAIN SELECT Nome 
FROM Professori
WHERE Nome = '%t%';

EXPLAIN ANALYZE SELECT Nome 
FROM Professori, Esami
WHERE Nome = '%t%' AND Voto = 18;

-- DROP INDEX idx_ord_voto_esami
CREATE INDEX idx_ord_voto_esami
ON esami(voto);

-- DROP INDEX idx_ord_nome_prof
CREATE INDEX idx_ord_nome_prof
ON professori(nome);

-- Query verbosa per ottenere tutte le info sugli oggetti nel DB
SELECT C.oid, relname, relfilenode, relam, relpages, reltuples, relhasindex, relkind
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
WHERE N.nspname = 'unicorsilarge' 

-- Query per ottenere relpages (numero blocchi per memorizzare la tabella) e reltuples (numero tuple per tabella)
SELECT relname, relpages, reltuples
FROM pg_namespace N JOIN pg_class C ON N.oid = C.relnamespace
WHERE N.nspname = 'unicorsilarge' 