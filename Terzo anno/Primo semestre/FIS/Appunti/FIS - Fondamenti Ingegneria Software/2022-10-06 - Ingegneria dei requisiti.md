# Ingegneria dei requisiti

## Panoramica sui requisiti
**Requisito sw**: descrive una 'funzionalità' o un vincolo che il sistema ha / deve sottostare. Descrive che cosa, non come. Può variare da una descrizione astratta a una dettagliata del sistema.

La rimozione dei difetti (difetto originato dai requisiti o da errori) costa maggiormente nella fase di testing, quindi l'obiettivo è intercettare i difetti nella fase di sviluppo.

Livelli di requisiti:
	- utente: descrizione in linguaggio naturale dei vincoli operativi e delle funzionalità (bisogni / necessità dell'utente). Scritti per il cliente e usati per il contratto.
	- sistema: descrizione dettagliata delle funzionalità. Descrive cosa farà il sistema e si usano dei formalismi. Scritti per gli sviluppatori.
Non è detto che vi siano entrambi (nei metodi agili ci sono sono quelli utente), ma se esistono entrambi, devono essere allineati (alto e basso livello devono corrispondere)

Posso rappresentare i requisiti tramite:
	- linguaggi formali
	- notazioni visuali
	- testo strutturato e non
	- Use Cases
	- user stories

### Requisiti funzionali e non
- funzionali: descrivono funzionalità e servizi offerti dal sistema, indipendenti dall'implementazione. Descrivono cosa fa il sistema.
- non funzionali: non sono legati direttamente alle funzionalità; definiscono vincoli del sistema, aspetti gestionali sullo sviluppo, strumenti, prestazioni, scelte di linguaggio (es. la descrizione di quali dispositivi verranno usati per il lavoro, il formato dei prodotti del sistema)
Requisito **etico** (non funzionale): vincolo sullo sviluppo (es. si usano servizi open-source).

## Definzione formale
**Requirement Engineering** è l'insieme di attività necessarie per raccogliere, documentare e tenere aggiornato l'insieme dei requisiti del sistema.
- scopo **primario** è descrivere il documento dei requisiti da produrre, che definisce le funzionalità e i servizi offerti dal sistema da realizzare.
- scopo secondario è mantenere attivi e aggiornati tali requisiti.
E' un *processo iterativo*.

## Fasi
- elicitation: (estrazione) dei requisiti dal cliente, svolto dall'analista software. Identifica gli *stakeholders* (i clienti interessati dal progetto). Si possono usare diverse tecniche (interviste, osservazione sul lavoro, questionari...)
- analisi dei requisiti dei clienti: viene stabilita la fattibilità e correttezza (che sia quello che vuole il cliente) dei requsiti, si cerca di identificare i requisiti mancanti (gap), poco chiari o contraddittori (clienti con interessi in contrasto); in questo caso si scende a contrattazione per rimuovere o modificare almeno uno dei due requisiti in contrasto. 
	Viene inoltre stabilita una priorità dei requisiti, secondo:
	- scala numerica
	- scala moscow (MUST (absolutely), SHOULD, COULD (later) implement a requisite)
- definizione e specifica: stesura del documento
	- 1^ parte - definizione dei requisiti (come forma di contratto per il cliente); requisiti utente.
	- 2^ parte - per gli sviluppatori, più tecnica; requisiti di sistema.
- validazione: esame della definizione dei requisiti
	- sono ben scritti?
	- soddisfano il cliente?
	- solitamente svolta da ulteriori analisti (format peer review, ovvero confronto alla pari, fra analisti)
- requirements management: gestione dei requisiti, approvazione di eventuali cambiamenti con *impact analysis*, negoziazione col cliente
	Proprietà dei requisiti da rispettare:
	- correttezza: sono voluti e non sbagliati
	- consistenza: se non sono contraddittori
	- completezza: gli aspetti richiesti sono presenti
	- realistici: non chiede l'impossibile
	- inequivocabilità: non ambiguità
	- verificabile: c'è sempre la possibilità di costruire un test sul requisito
	- tracciabilità: ogni funzionalità deve essere riferita nel documento (attraverso eventualmente una matrice di tracciabilità), tale da legare la specifica alla definizione.

Esempio di descrizione di un requisito nel documento:
< id > il < sistema > deve < funzione >

## Figura dell'analista software
E' colui che si occupa della raccolta e analisi dei requisiti; deve scrivere il documento dei requisiti. Comunica con i clienti e con gli sviluppatori.
Deve saper:
- ascoltare cercando di capire le assunzioni
- negoziare
- esprimersi con sintesi
- problem solving
- conoscere il dominio (contesto in cui agirà il sistema), magari costruendo un glossario dei termini.

## Problemi possibili in un documento dei requisiti
- ambiguità
- poca chiarezza
- utilizzo di termini troppo tecnici
- requisiti troppo dettagliati o generici
- unione di requisiti funzionali e non funzionali
- verbosità

