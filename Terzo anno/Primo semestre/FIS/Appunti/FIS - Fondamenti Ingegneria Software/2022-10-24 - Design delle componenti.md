# Design delle componenti
Diviso in fasi e artefatti (prodotti delle fasi)

![[Attività_Artefatti_DesignComponenti.png]]

Component design: da macrocomponneti a classi object oriented

![[High_Low_LevelDesign.png]]

## Design by contract (Weyer)
Può essere applicato a high level o low level design
Obj: migliorare la qualità del prodotto
Idea: il progettista deve definire specifiche precise delle interfacce, delle classi/componenti sw, basandosi sulla metafora di **contratto** (accordo fornitore-cliente), creato prima di definire la componente.

Elementi del contratto:
- precondizione: rappresenta le aspettative della classe prima dell'esecuzione di un'operazione
- postcondizione: rappresenta lo **stato del mondo** dopo l'esecuzione di un'operazione (esprimibile in OCL)
- invarianti: condizione che ogni oggetto deve soddisfare quando è in equilibrio (= non stiamo eseguendo operazioni) (esprimibile in OCL)

Utilità delle precondizioni: chiarisce la responsabilità di chi deve effettuare i controlli, controlli che senza precondizioni potrebbero risultare troppi (defense programming) o troppo pochi.

Design by contract definisce classi con ruolo di fornitore: fornisce una funzione
	- garantisce che se pre & inv valgono allora dopo l'op vale post
	- il fornitore chiede che valgano pre & inv
Pre: richiesta del fornitore al cliente
Post: garanzia che il fornitore da al cliente

Vantaggi:
- codifica guidata
- migliore qualità del sw
- documentazione precisa
- testing
- debugging più gestibile: eccezioni sollevate quando il contratto è violato (si usano framework)

## Progettazione degli algoritmi
Parte più vicina alla codifica, demandata agli sviluppatori
Passi:
- si analizza la classe di design
- se esiste si seleziona un algoritmo
- se necessario definire un nuovo algoritmo si usano notazioni sulla base della nozione di **stepwise refinement**
	- si dimostra la correttezza dell'algoritmo creato con metodi formali

Notazioni possibili:
- visuali (UML, diagrammi di flusso)
- testuali (pseudocodice)
Sullo pseudocodice posso scegliere il livello di 'narrativa' del linguaggio (stepwise refinement)


## Principi di progettazioni
Produce sw di buona qualità, manutenibile, riusabile, comprensibile.

Concetto di **modulo**: entità sw identificata da un nome
- fonisce servizi sw
- può includere ed essere incluso
- contiene istruzioni

### Astrazione
Focalizza il problema con un livello di astrazione senza perdersi in dettagli non rilevanti
- meno complessità
- più information hiding

Forme di astrazione:
- funzionale: descrive funzionalità indipendentemente dall'algoritmo che lo implementa
- di dati: definizione di un tipo di dato in base alle operazioni
- di controllo: definizione di un meccanismo di controllo (concetto di semaforo), no dettagli interni

### Decomposizione
Cercare di risolvere pezzi più piccoli del problema è più semplice.
Aumentando il numero di moduli diminuisco lo sforzo di svilupparli, ma aumento il costo di re-integrazione dei pezzetti.

### Modularità
Guida la decomposizione in moduli
**Separation of concerns**: l'idea è di tenere separati aspetti non rilevanti al dato modulo
Es. separazione di presentazione dei dati e dalla loro generazione
Ritoccare un modulo non influenza l'altro

Obj: massimizzare la coesione e minimizzare l'accoppiamento.

Ottengo classi:
- facili da comprendere
- riusabili
- fanno il meno possibile

#### Coesione
Ogni modulo ha una sua funzionalità. Poca coesione la si ha se la stessa classe sbriga più compiti non legati fra loro da un certo contesto (metodi disparati).

### Accoppiamento
Ogni modulo non deve dipendere da troppi altri moduli nè in modo troppo forte.
Si può misurare il grado di dipendenza
Ne esistono di due tipi:
- buono
- cattivo

Buono:
- chiamata di funzione da un classe all'altra
- uso di tio: di una classe rispetto a un'altra
- inclusione: di librerie

Cattivo: 
- modifica di dati di altri moduli
- saltare (goto) in altri moduli

Si riduce incapsulando i campi all'interno della classe (information hiding): dichiaro i campi privati


### Information Hiding
Idea: le informazioni devono risultare nascoste agli altri moduli
- come compromesso le interfacce permettono una visione su tali campi

### Fan in-Fan out
Si crea un grafo degli usi / dipendeze che permette di vedere il sistema con le sue dipendenze
- fan-out: archi uscenti; se tanti significa che una classe fa troppi compiti
- fan-in: archi entranti; se tanti è bene, significa che c'è tanto riuso

### Generalità
Idea del riuso del codice: posso usare la stessa classe in più contesti
Limita il principio KISS della semplicità.

Tramite tool (View Code) e metriche (LCOM) posso vedere se rispetto i criteri
LCOM = intersezioni vuote di campi utilizzati dai metodi - intersezioni non vuote
Se LCOM > 0 -> classe non coesa; le intersezioni fanno riferimento ai campi utilizzati da più metodi