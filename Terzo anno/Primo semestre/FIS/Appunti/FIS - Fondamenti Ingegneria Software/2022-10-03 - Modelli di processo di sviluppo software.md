# Modelli di processo di sviluppo software
**Processo**: insieme strutturato e organizzato di attività che si svolgono per ottenere un risultato
Consideriamo il software un **prodotto**, concentrandoci sul processo di sviluppo seguendo l'idea "migliore il processo -> migliore il prodotto".

Modellando il processo ottengo:
- ordine
- controllo
- ripetibilità


I **modelli** sono visioni "astratte" del processo
	- possono essere generici (adattivi) (es. Do Whatever, zero regole)
	- possono essere molto descrittivi (UP, 120+ regole)

I modelli definiscono il processo tramite **regole** e descrivono quali **deliverable** bisogna ottenere.
La decisione di un modello da adattare prima dell'inizio di un progetto è deciso dall'azienda o dal **project manager**.

## Code & Fix
L'approccio Code&Fix descrive l'arrivo del codice finale attraverso "tentativi": 
	- non si eseguono fasi di analisi o progettazione
	- non adatto per grandi progetti (<1500 LinesOfCode)

## Modello Waterfall
Il modello Waterfall mette in cascata i passi tradizionali.
Ogni fase produce un prodotto usato come input dalla fase successiva.
Deriva dal processo manifatturiero (industriale)
Code&Fix (dimensione artigianale) -> Waterfall (produzione industriale) del software

*Pro*
- enfasi su analisi dei requisiti
- bisogna sapere esattamente cosa fare e tale deve rimanere
- pospone la codifica a dopo aver capito i bisogni del cliente
- introduce disciplina e pianificazione

*Contro*
- lineare, rigido, monolitico:
	- no feedback
	- no parallelismo (tutti i team sono coinvolti nella stessa fase)
	- unica data di consegna, che avviene dopo anni (software prodotto potenzialmente obsoleto)
	- tanta documentazione, spesso poco chiara all'utente

### Studio di fattibilità
Fase aggiuntiva, precedente allo sviluppo: trattasi di un analisit della fattibilità e convenienza del progetto e delle sue funzionalità. 
- Go/No-Go: conviene implementare una certa funzionalità o il progetto nel suo complesso? Si ha un Return of Investment (guadagno corrisposto all'investimento)?

### Varianti del Waterfall
Per ovviare ai difetti del Waterfall sono state proposte delle varianti:
- modello waterfall di prototipazione: si crea un prototipo "usa e getta" solo per fornire agli utenti una base per descrivere meglio i requisiti (e specificare la loro soddisfazione)
- modello waterfall con feedback: dalle fasi successive si estrae un feedback che può essere passato alle fasi precedenti creando un'iterazione
- v-model

### V-Model
- Esplicita le iterazioni nascoste nel waterfall
- enfasi sulla fase di testing (trattato su più fasi)
- ogni fase di testing è legata alla fase di progettazione: la progettazione guida il testing e il testing afferma in quale fase della progettazione mettere mano per migliorare il sistema.
- inizio di parallelismo: appena una parte di progettazione è completa può cominciare il testing
- usato per sistemi safety-critical, ovvero a rischio di perdite ingenti di denaro o vite umane

### Problematiche Waterfall e V-Model
- requisiti in continua evoluzione, che in questi casi vengono invece congelati
- unica consegna
- il cliente può non sapere esattamente cosa vuole all'inizio dello sviluppo
- errori nella fase iniziale portano a conseguenze disastrose

Da ciò nascono i modelli evolutivi, più flessibili al cambiamento dei requisiti nel tempo
	- nascono le release (rilascio) multiple del software in varie versioni

## Modelli evolutivi
Idea: sviluppo un'implementazione iniziale, la si espone al cliente e la si raffina tramite release successive.
Di seguito alcune sottocategorie.

### Modelli a prototyping
Si realizza un prototipo funzionante del sistema
	- usa e getta
	- oppure si può evolvere nel sistema
Il prototipo è meno completo e meno efficiente in prestazioni del progetto finale, serve per dare un'idea del sistema al cliente, che fornisce un feedback
	- si ciclano le fasi fino al soddisfacimento dei requisiti, migliorando via via il prototipo
Il linguaggio del prototipo è ad altissimo livello, per essere più comprensibile e di facile modifica.

*Pro*
- raffinazione dei requisiti
- rilevazione precoce degli errori

*Contro*
- prototipo (=lavoro) usa e getta: danno economico e psicologico

Si cerca allora una via di mezzo: solo le idee poco chiare al cliente vengono prototipate (così da non rallentare lo sviluppo delle funzionalità principali già chiare)

### Modelli iterativi-incrementali
- sviluppo di varie release
- richiede di individuare le funzionalità da rilasciare al cliente per ogni release
- dopo la prima release si produce parallelamente
	- utilizzo di una prima release
	- sviluppo della release successiva ascoltando il feedback sulla prima

- incrementale 'puro'
	- ogni release aggiunge nuove funzionaltà + risoluzione dei problemi
	- è importante pianificare cosa allocare nel prossimo rilascio, si usano criteri di priorità
	- si seguono due strategie:
		- trattare le funzionalità ad alto rischio (difficili o che potrebbero portare parecchi problemi)
		- massimizzare il valore per gli utenti
- iterativo 'puro'
	- da subito sono già presenti le funzionalità, nelle release successive raffino e ottimizzo
Nella pratica si mischiano incrementale e iterativo: a volte si aggiungono funzionalità, a volte si ottimizza

*Pro*
- continui feedback
- più facile prevedere le risorse necessarie (perchè si focalizza su una parte sempre più piccola del sistema con le varie release (più vicine al progetto finale))
- più facile individuazione degli errori
- risposta rapida al mercato, rilasciando già delle parti intermedie

Esempi di seguito

#### Modello a spirale
- approccio evolutivo
- risk-driven: tutte le scelte sono basate sui risultati dell'analisi dei rischi
- meta-modello: necessita di essere completato con un altro modello a più basso livello
	- per requisiti chiari e stabili: waterfall
	- per requisiti poco chiari: prototipo o altro
- rischio = circostanza potenzialmente avversa che può danneggiare lo sviluppo del software

Ogni scelta / decisione porta a un potenziale rischio. Si valuta dunque:
	- la gravità della conseguenza
	- probabilità di verifica

Consta di 4 fasi:
	- Planning
	- Risk Analysis
	- Engineering (Sviluppo)
	- Custom Evaluation (feedback)

Dopo un analisi dei rischi ad ogni iterazione, si può valutare se fermare il progetto o meno

*Pro*
- adatto allo sviluppo di sistemi complessi
- considera il rischio

*Contro*
- richiede alta competenza per la stima dei rischi
- bisogna scegliere il modello appropriato da usare nella fase di Engineering


## Unified Process (UP)
Modello prescrittivo, plan driven
- modello iterativo-incrementale (evolutivo)
- sviluppo dei sistemi a oggetti, utilizzo di UML
- si usano formalismi Use Case
- incorpora idee e gestione rischi del modello a spirale
- è un meta modello
- supportato da tool (WebRatio)

Consta di più iterazioni di 4 fasi che possono ripetersi più volte:
- Inception (avvio): studio di fattibilità e analisi dei requisiti e dei rischi
- Elaboration: comprensione del dominio, del problema, use-case, infine si produce uno schema
- Construction: design, codifica e testing
- Transiction: deploy della release e testing

## Sviluppo basato sui componenti
- software creati per composizione (pezzi preconfezionati)
- modello nella direzione del riutilizzo
	- esiste uno 'store' delle componenti

Fasi:
	- Specifica requisiti
	- Analisi componenti (fase aggiuntiva: si verificano che le componenti siano tutte quelle necessarie)
	- Modifica dei requisiti (si contratta col cliente, cercando di scrivere meno codice in più possibile)
	- Design del sistema
	- Sviluppo e integrazione delle componenti
	- Rilascio e testing

*Pro*
- riutilizzo, meno codice da scrivere
- riduce i costi di sviluppo e consegne più veloci (-- questo punto non è verificato --)

*Contro*
- necessari compromessi col cliente
- integrazione non sempre facile
- componenti usati possono evolvere da parte dei fornitori

## Metodi plan-driven vs Metodi agili
- Plan-driven (o prescrittivi)
	- qualità del processo -> qualità del prodotto
	- seguono i passi dell'ingegneria
	- es. Waterfall, UP
- Agili (o adattivi)
	- meno regole, più flessibili
	- rispondere velocemente ai cambiamenti
	- programmare "è arte" e non un processo industriale
	- focus sulla soddisfazione del cliente e non seguire un piano
	- es. Extreme Programming (XP), Scrum

## The Agile Manifesto
Fissa alcuni principi:
- Individuals and interactions OVER Process and tools
- Working SW (SW sempre attivo) OVER Comprehensive documentation
- Customer collaboration OVER Contract negotiation
- Responding to change (anche nel caso di cambiamenti all'interno del team si sviluppo) OVER Following a plan

*Problemi*

- gestionali: 
	- la conoscenza dei requisiti e il design del sistema è nella testa degli sviluppatori
	- sviluppatori esperti
	- utenti non sempre disponibili
- legali: quando è soddisfatto il contratto?
- manutenzione:
	- scarsa documentazione
	- architettura complessa determianta dalla release attuale, che spesso si evolve casualmente

Come scegliere:
- plan-driven
	- per sistemi grandi e complessi, safety-critical
	- requisiti stabili

- metodi agili
	- sistemi e team piccoli con utenti disponibili
	- team esperto
	- tempi di consegna rapidi

- Nei casi dubbi: si cerca di bilanciare