set search_path to "Pizze";

-- Determinare le pizze che sono state ordinate almeno una volta da tutti i clienti
SELECT Nome
FROM Pizza NATURAL JOIN Ordine
GROUP BY Nome
HAVING COUNT(DISTINCT telC) = (SELECT COUNT(telC) FROM Cliente)

--- Soluzione alternativa:
-- Difatto rimuovo le tuple con un certo telC in 'relazione' con quelle di un certo codP, infine le 
-- tuple che ho tolto (quindi not exists nella sotto-relazione) saranno quelle che cerco
SELECT Nome
FROM Pizza AS P
WHERE NOT EXISTS((SELECT telC FROM Cliente)
				EXCEPT
				(SELECT telC FROM Ordine WHERE P.codP = codP));

-- Determinare il numero di telefono dei clienti che hanno ordinato solo pizze che costano 6 euro
SELECT telC
FROM Cliente
EXCEPT
SELECT telC
FROM Ordine NATURAL JOIN Pizza
WHERE Costo <> 6

-- Determinare il numero di telefono dei clienti che hanno ordinato tutte le pizze che costano 6 euro
-- Nota: dai codP di costo 6 tolgo quelli presenti negli ordini di un certo telC.
-- Se la differenza toglie il codP significa che il telC ha ordinato quella pizza, dunque
-- quando verifico se non esiste quel codP all'interno della relazione, il risultato diviene vero 
-- (e prelevo telC) perchè effettivamente codP non compare perchè cancellato perchè ordinato
SELECT DISTINCT telC FROM Ordine as O
WHERE NOT EXISTS (( SELECT CodP FROM Pizza WHERE Costo = 6)
EXCEPT
 (SELECT CodP FROM Ordine WHERE telC = O.telC ));

-- Determinare per ogni cliente la sua pizza preferita (= la pizza che ha ordinato in quantitativo maggiore)
SELECT TelC, NomeC, Pizza.Nome
FROM Cliente NATURAL JOIN Ordine AS O NATURAL JOIN Pizza
WHERE Qta = (SELECT MAX(Qta) FROM Ordine WHERE telC = O.telC)