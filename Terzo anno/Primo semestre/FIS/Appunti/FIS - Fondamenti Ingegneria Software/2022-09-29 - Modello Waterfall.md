# Modello Waterfall
E' uno dei modelli utilizzati per contrassegnare un corretto sviluppo e ciclo-vita di un software. E' diviso in vari passi:
	- Requirements
	- Design
	- Implementazione
	- Testing
	- Delivery e manutenzione

## Requirements
Definizione di funzionalità, vincoli e prestazioni da soddisfare richieste dal cliente
	- fase di raccolta di requisiti
	- descrivere cosa fare e non come

Deliverable (prodotto richiesto): requirement specification / definition
	- attraverso linguaggio informale (definition)
	- attraverso linguaggio formale e rigoroso (specification)
	- si sceglie una delle due in base al contesto (un contesto medico ad esempio utilizzerà un percorso più rigoroso e meno creativo rispetto ad un'applicazione web)

## Design
Definizione della struttura, divisa in due fasi
	1. high level design
	2. low level design, focus sui dettagli
Si cerca il platform independent design: astratto senza aspetti di implementazione

Deliverable: Design specification (con documentazione), utilizzando linguaggio UML
La documentazione di un progetto software consta di: requirements, design, test a corredo del codice

## Implementazione
Codifica in linguaggio di programmazione
- se design preciso -> poca creatività (MDD)
- altrimenti -> attività creativa e metodi agili

Deliverable: codice del sistema

Model Driven Development (MDD): eseguo o traduco direttamente il modello in codice (programma che dunque viene generato automaticamente), ottenendo un programma rigoroso.

## Testing
Procedimento per trovare bug all'interno del software, eseguendo il codice e analizzando i risultati ottenuti. Prende molto tempo nel ciclo-vita di un software.

Deliverable: Test Plan (quali test e input) & Test Report (quali risultati ottenuti)

## Delivery e manutenzione
- System delivery: consegna e installazione del sistema, eventualmente istruendo l'utente con manuali
- Manutenzione: si cerca di mantenere attivo il sistema:
	- rimediando agli errori
	- migliorando il software con nuovi aggiornamenti e funzionalità
	- adattando il software al passare del tempo