set search_path to "unicorsilarge";

-- INTERROGAZIONI E PIANI DI ESECUZIONE FISICI
-- 1) Scansione sequenziale, start-up cost = 0, stima del costo totale dato dall'operazione = 2683, stima del numero di tuple restituite = 52672 tuple, 
	-- stima dimensione media ciascuna tupla: 28, tempo di esecuzione totale: 18.216 ms
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 18

-- 2) Scansione sequenziale, start-up cost = 0, stima del costo totale dato dall'operazione = 2383, stima del numero di tuple restituite = 52672 tuple, 
	-- stima dimensione media ciascuna tupla: 28, tempo di esecuzione totale: 17.302 ms. 
	-- NON viene utilizzato l'indice (probabilmente la scansione sequenziale fa risparmiare accessi a blocchi, la selezione probabilmente restituisce molte tuple)
CREATE INDEX idx_ord_voto_esami -- default btree
ON esami(voto);
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 18

-- 3) BitmapIndexScan + BitMapHeapScan, start-up cost = 216.09, stima del costo totale dato dall'operazione = 213.26 e 1240.49, stima del numero di tuple restituite = 11312 e 11312 tuple, 
	-- stima dimensione media ciascuna tupla: 0 e 28, tempo di esecuzione totale: 5.444 ms
	-- Viene utilizzato l'indice (probabilmente accedo a meno blocchi, ovvero la selezione filtra molte tulple, restituendone poche)
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 29

-- 4) BitmapIndexScan + BitMapHeapScan, start-up cost = 216.09, stima del costo totale dato dall'operazione = 213.26 e 1240.49, stima del numero di tuple restituite = 11312 e 11312 tuple, 
	-- stima dimensione media ciascuna tupla: 0 e 28, tempo di esecuzione totale: 1.666 ms
	-- Viene utilizzato l'indice clusterizzato e i tempi si riducono rispetto a prima
CLUSTER esami USING idx_ord_voto_esami
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 29

-- 5) BitmapIndexScan + BitMapHeapScan, start-up cost = 214.77, stima del costo totale dato dall'operazione = 213.26 e 1267.45, stima del numero di tuple restituite = 6035 e 6035 tuple, 
	-- stima dimensione media ciascuna tupla: 0 e 28, tempo di esecuzione totale: 1.912 ms
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 29 AND Data > '2018-05-01'

-- 6) BitmapIndexScan + BitMapHeapScan, start-up cost = 4.86, stima del costo totale dato dall'operazione = 4.86 e 235.04, stima del numero di tuple restituite = 76 e 7 tuple, 
	-- stima dimensione media ciascuna tupla: 0 e 28, tempo di esecuzione totale: 0.272  ms
	-- Come nel caso precedente, utilizzando l'indice clusterizzato, i tempi si riducono rispetto al caso sopra, inoltre la selezione ha un indice di selettività più basso (meno tuple restituite)
CREATE INDEX idx_ord_data_esami 
ON esami(data);
EXPLAIN ANALYZE SELECT *
FROM Esami
WHERE Voto > 29 AND Data > '2020-04-28'

-- 7) Scansione Sequenziale, start-up cost = 0, stima del costo totale dato dall'operazione = 2083, stima del numero di tuple restituite = 120000 tuple, 
	-- stima dimensione media ciascuna tupla: 13, tempo di esecuzione totale: 12.53  ms
EXPLAIN ANALYZE SELECT Studente, Voto
FROM Esami
	-- Scansione Sequenziale + Aggregate(Hash), start-up cost = 0 e 2683, stima del costo totale dato dall'operazione = 2083 e 3114.7, stima del numero di tuple restituite = 120000 e 43170 tuple, 
	-- stima dimensione media ciascuna tupla: 13 e 13, tempo di esecuzione totale: 110.643 ms
	-- Come ci si aspettava, l'operazione di rimozione di duplicati è più onerosa. Il sistema sfrutta inoltre una strategia hash per implementare tale query
EXPLAIN ANALYZE SELECT DISTINCT Studente, Voto
FROM Esami


-- 8) Scansione Sequenziale di entrambe le tabelle + Indice Hash su STUDENTI + Hash Inner Join fra l'indice Hash precedente e la scansione seq di ESAMI, 
	-- start-up cost = 1315(hash) e 2769(hash inner join), stima del costo totale dato dall'operazione = 1315(studenti) - 2083(esami) - 1315(hash) e 7513.02(hash inner join), 
	-- stima del numero di tuple restituite = 60000(studenti) - 120000(esami) - 60000(hash) - 120000(hash inner join) tuple, 
	-- stima dimensione media ciascuna tupla: 68(studenti) - 28(esami) - 68(hash) e 96(hash inner join), tempo di esecuzione totale: 164.219  ms
	-- Secondo le stime date dal sistema si identifica come outer la relazione esami (più grande rispetto a studenti)
CREATE INDEX idx_ord_mat_studente 
ON studenti(Matricola);
CREATE INDEX idx_ord_studente_esami 
ON esami(Studente);
EXPLAIN ANALYZE SELECT *
FROM Esami JOIN Studenti ON Matricola = Studente

-- 9) Scansione Sequenziale di STUDENTI + Bitmap Index Scan sull'indice ordinato di ESAMI + BitMapHeapScan sul secondo + Indice Hash sul terzo + Hash Inner Join fra l'indice Hash precedente e la scansione seq di STUDENTI, 
	-- start-up cost = 216.09(BitMapHeapScan) - 1240.49(Hash) e 1381.89(HashInnerJoin), stima del costo totale dato dall'operazione = 1315(studenti) - 2083(esami) - 1315(hash) e 7513.02(hash inner join), 
	-- stima del numero di tuple restituite = 60000(indice su esami) - 11312(BitMapHeapScan) - 11312(hash) - 60000(studenti) e 120000(hash inner join) tuple, 
	-- stima dimensione media ciascuna tupla: 68(studenti) - 28(BitMapHeapScan) - 28(hash) e 96(hash inner join), tempo di esecuzione totale: 20.24  ms
	-- Secondo le stime date dal sistema si identifica come outer la relazione studenti (più grande rispetto a esami (di cui si considera un indice))
EXPLAIN ANALYZE SELECT *
FROM Esami JOIN Studenti ON Matricola = Studente
WHERE Voto > 29

-- 10)Scansione Sequenziale di STUDENTI + Bitmap Index Scan sull'indice ordinato di ESAMI + BitMapHeapScan sul secondo + Indice Hash sul terzo + Hash Inner Join fra l'indice Hash precedente e la scansione seq di STUDENTI, 
	-- start-up cost = 216.09(BitMapHeapScan) - 1240.49(Hash) e 1381.89(HashInnerJoin), stima del costo totale dato dall'operazione = 1315(studenti) - 2083(esami) - 1315(hash) e 7513.02(hash inner join), 
	-- stima del numero di tuple restituite = 60000(studenti) - 60000(hash) - 120000(esami) e 120000(hash inner join) tuple, 
	-- stima dimensione media ciascuna tupla: 68(studenti) - 28(esami) - 68(hash) e 96(hash inner join), tempo di esecuzione totale: 135.08  ms
	-- Secondo le stime date dal sistema si identifica come outer la relazione esami (più grande rispetto a studenti)
CLUSTER esami USING idx_ord_studente_esami;
CLUSTER studenti USING idx_ord_mat_studente;
EXPLAIN ANALYZE SELECT *
FROM Esami JOIN Studenti ON Matricola = Studente
	
	-- Scansione Sequenziale di STUDENTI + Bitmap Index Scan sull'indice ordinato di ESAMI + BitMapHeapScan sul secondo + Indice Hash sul terzo + Hash Inner Join fra l'indice Hash precedente e la scansione seq di STUDENTI, 
	-- start-up cost = 216.09(BitMapHeapScan) - 1240.49(Hash) e 1381.89(HashInnerJoin), stima del costo totale dato dall'operazione = 1315(studenti) - 1240.49(index_ord su esami) - 1240.49(hash) e 3185.01(hash inner join), 
	-- stima del numero di tuple restituite = 11312(indice su esami) - 11312(BitMapHeapScan) - 11312(hash) - 60000(studenti) e 11312(hash inner join) tuple, 
	-- stima dimensione media ciascuna tupla: 68(studenti) - 28(BitMapHeapScan) - 28(hash) e 96(hash inner join), tempo di esecuzione totale: 21.671 ms
	-- Secondo le stime date dal sistema si identifica come outer la relazione studenti (più grande rispetto a esami (di cui si considera un indice))
	-- Rispetto a prima si nota sostanzialmente che il numero di tuple e blocchi acceduti è inferiore, questo proprio perchè la clusterizzazione pone un ordine sul file di dati permettendo un minor numero di accessi (spesso duplicati) a blocchi
EXPLAIN ANALYZE SELECT *
FROM Esami JOIN Studenti ON Matricola = Studente
WHERE Voto > 29

-----------------------------------------------------------------
-- * FACOLTATIVO: INTERROGAZIONI COMPLESSE (ORDINAMENTO, GROUP BY)

	--1)Scansione Sequenziale di ESAMI + Sort, 
	-- start-up cost = 361.209(sort), stima del costo totale dato dall'operazione = 2083(esami) - 15380.1(sort), 
	-- stima del numero di tuple restituite = 120000(esami) e 120000(sort, per ovvie ragioni il numero rimane invariato) tuple, 
	-- stima dimensione media ciascuna tupla: 28(esami) e 28(sort), tempo di esecuzione totale: 396.52 ms
	-- Come è noto, l'ordinamento è un'operazione costosa, infatti il tempo di esecuzione è molto più alto delle query precedenti
EXPLAIN ANALYZE SELECT *
FROM Esami
ORDER BY Corso

--2)Index Scan su indice di esami (senza sort, perchè giustamente l'indice è ordinato), 
	-- start-up cost = 0.29, stima del costo totale dato dall'operazione = 5760.28, 
	-- stima del numero di tuple restituite = 120000 tuple, 
	-- stima dimensione media ciascuna tupla: 28, tempo di esecuzione totale: 43.421 ms
	-- Risparmiamo molto tempo utilizzando un indice ordinato, poichè non è più necessario effettuare un sort durante la query (bensì facciamo riferimento a una struttura, l'indice, già
	-- ordinato precedentemente alla query stessa)
CREATE INDEX idx_ord_corso_esami
ON esami(corso);
EXPLAIN ANALYZE SELECT *
FROM Esami
ORDER BY Corso

--3)Scansione Sequenziale di ESAMI + Aggregate(plain), 
	-- start-up cost = 2383(aggregate), stima del costo totale dato dall'operazione = 2083(esami) e 2383.01(aggregate), 
	-- stima del numero di tuple restituite = 120000(esami) e 1(aggregate) tuple, 
	-- stima dimensione media ciascuna tupla: 0(esami) e 8(aggregate), tempo di esecuzione totale: 12.419  ms
EXPLAIN ANALYZE SELECT COUNT(*)
FROM Esami

	-- Scansione Sequenziale di ESAMI + Aggregate(plain), 
	-- start-up cost = 2683(aggregate), stima del costo totale dato dall'operazione = 2083(esami) e 3114.7(aggregate), 
	-- stima del numero di tuple restituite = 120000(esami) e 43170(aggregate) tuple, 
	-- stima dimensione media ciascuna tupla: 8(esami) e 16(aggregate), tempo di esecuzione totale: 64.038  ms
	-- Si nota che l'operazione di raggruppamento porta via maggiore tempo, inoltre il risultato non è più una tupla sola bensì una tupla per ogni studente, dunque l'output ha maggiore dimensione
EXPLAIN ANALYZE SELECT COUNT(*)
FROM Esami
GROUP BY Studente
