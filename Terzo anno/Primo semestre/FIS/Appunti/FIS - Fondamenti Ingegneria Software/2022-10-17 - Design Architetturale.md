# Design architetturale

## Design
Propone una soluzione (il *come*) a un problema / requisito.
Rispetto all'implementazione si focalizza sulla definizione della struttura della soluzione e non la sua realizzazione.
Si sviluppa in passi:
- architetturale (high-level design): mappa i requisiti su architetture SW
- component design: raffinamento ulteriore con fissaggio delle componenti

Il design può essere prodotto:
- platform independent (*pro*: riutilizzo; *contro*: astratto e difficile da implementare)
- platform-specific, es. specifico per Java

Il design è creativo? Solo in parte.
Il design si migliora studiando e ri-adattando schemi di soluzioni già noti.
Vi sono diversi livelli di ri-uso:
- clonazione: minima modifica prima dell'inclusione nel sistema
- design pattern: buone soluzioni a problemi ricorrenti
- stili architetturali: architettura **generica** che suggerisce come decomporre il sistema; non si focalizza su un solo dominio
	- in contrapposizione si possono usare dei **reference model** ottimizzati per un certo dominio (specifici)
Inoltre il design rispetta delle **convenzioni** (es. le classi hanno l'iniziale maiuscola).

## Design architetturale
Il design architetturale è un processo per identificare:
- le macrocomponenti (package)
- framework di controllo e comunicazione fra le componenti

Produce una descrizione di **un'architettura software**.
Una componente può essere un *sottosistema* o un *modulo*.
Un **sottosistema** è un sistema di per sè che può essere eseguito da solo, composto da moduli ed interfacce ben definite per la comunicazione con altri sottosistemi.
Un **modulo** è un'unità del sistema che offre servizi ad altre unità; non può essere eseguito da solo.

Un'architettura SW è espressa con **diagrammi a blocchi**:
- blocchi = componenti
- connettori = relazioni fra componenti

*Proprietà del sistema* (impattate dalla scelta dell'architettura)
- performance: tempi di risposta rapidi
- security: difficile da manomettere (osservando le criticità)
- safety: non deve creare disastri
- availability: sempre disponibili (con componenti ridondanti e meccanismi 'fault tolerance')
- maintainability: facile da evolvere
	- componenti fine-grain (piccole) sono utili perchè facilmente rimpiazzabili

Nota: con più ridondanza ottengo più availability, ma meno safety (devo valutare le scelte in base al contesto)

*Vantaggi* di avere un'architettura SW
- guida lo sviluppo
- documenta il sistema
- supporta decisioni
- facilita l'analisi di alcune proprietà
- permette il riuso (large-scale)

## Stile architetturale
L'architettura di un sistema può conformarsi a uno **stile** (modello generico)
Solitamente l'architettura del sistema è eterogenea e non si focalizza su un unico stile.

Lo stile è definito da:
- componenti (es. servizi, procedure)
- connettori (es. invocazioni di procedure, eventi)

Esistono diversi stili:
- layered
- repository
- client/server
- microservice

Gli stili si dividono in due tipi:
- strutturale: solo info strutturali sulle componenti
- di controllo: *anche* info di controllo (es. come si passa da una componente all'altra)

### Stili strutturali
#### Stile layered
Organizza il sistema in un insieme di livelli, ognuno fornisce un insieme di servizi; un livello usa servizi del livello inferiore.
- solitamente usato per definire OS
- livelli più interni sono più volti all'HW
- livelli esterni sono più vicini all'interfaccia per l'utente

#### Stile repository
I dati condivisi sono mantenuti in un DB centrale (**blackboard**).
- tutte le componenti (sotto-sistemi) possono accedere al DB
- i sottosistemi non comunicano fra loro
- adatto per casi in cui i dati prodotti da una componente (unità di computazione) sono usati da un'altra
In questo caso può essere utile un CASE tool: SW che supporta lo sviluppo e la manutenzione del SW (es. Visual Paradigm), che permette design ed eventuale codifica del SW.

#### Stile Client-Server
Modello di sistema distribuito che mostra come i dati possono essere distribuiti su:
- insieme di server che forniscono il servizio
- insieme di clinet che ne usufruiscono

Protocollo di domanda-risposta. Esiste una **rete** che collega il client ai server e viceversa. L'interfaccia utente è costruita usando Web-Browser

#### Stile C-S a due livelli
Componenti / strati SW:
- interfaccia utente (presentation logic)
- gestione processi logici (business logic)
- gestione del DB (data logic)

Distribuiti su due livelli:
- client
- server
Posso posizionare il livello business logic in modo diverso: o sul client (fat client) o sul server (thin client).
Solitamente si fa un mix.

#### Stile C-S a tre livelli
Come sopra ma la logica del sistema è uno strato separato che gestisce multi-utenti.
Presentation - client
Logic - server
Data - server

Solitamente si usano sistemi con architetture eterogenee; si usano due modi per combinare gli stili:
- gerarchico: un sistema organizzato in uno stile ha una componente (sotto-sistema) a sua volta organizzata in un altro stile
- mix di architettura: componenti di stile diverso interagiscono fra loro contemporaneamente

#### Stile Microservices
Idea: si vuole costruire il sistema come insieme di micro-servizi che comunicano fra loro con meccanismi leggeri (basati su http e rest). Evoluzione di SOA (service oriented programming)

Si contrappongono alle rappresentazioni monolitiche e multi-livello. Popolare oggi (in particolare per le Web App).
**Ogni servizio implementa una funzionalità** (a livello di Use Case)

Se l'app cresce:
- complessità aumenta
- difficile trovare bug
- tempi estesi per il deployment
- complesso lavorare in parallelo

Se invece spezzo il sistema in microservizi posso aggiornare e ri-dislocare il singolo microservizio senza dover ricaricare il sistema. Facile da realizzare.
I microservizi possono essere dislocati anche più server in locale o in cloud.

*Proprietà micro-servizio*
- realizza unica funzionalità
- autonomo e indipendente
- possiede un proprio DB (ha solo lo schema che gli interessa)
- comunica e si coordina con gli altri

Vari framework aiutano nello sviluppo di app e microservizi.

##### Monolite VS Microservizi
Prima si usava uno stile monolitico dove i servizi erano impacchettati in un intero archivio (WAR). Ogni aggiornamento necessitava di prelevare il sistema dal server, aggiornarlo e ricaricarlo integralmente.

![[MonolithVSMicroservices.png]]

#### Sviluppo di microservizi

I microservizi possiedono un'interfaccia API (basata su REST, a sua volta basato su HTTP per effettuare le operazioni CRUD e comunicare con il server).
Il **gateway** è un microservizio che smista le richieste (espone l'interfacciai verso i client)
Solitamente il client richiama il gateway che ha l'abilità di chiamare più microservizi.

*Contro dei microservizi*
- stabilire quanti ne servono (dimensione)
- selezionare il giusto framework
- possibili disservizi di rete
- bisogna partizionare bene il DB
- non facile da testare quando si parla di app (nel suo completo, dopo aver aggiornato e introdotto il microservizio)
- maggior consumo di risorse e memoria

### Stile Peer to Peer
Come Client-Server ma i ruoli non sono definiti: ogni componente funge sia da client che da server. Ogni peer ha un'interfaccia che specifica i servizi offerti e rcihiesti. 
La differenza fra i peer sono i **dati**: questi possono essere richiesti da un peer e inviati da un altro peer.
I sistemi P2P scalano bene e sono **fault-tolerant**:
- aggiungere un peer aumenta le capabilities (nuovi dati)
- i dati sono replicati su più peer: se uno cade, i dati non vengono necessariamente persi
Esempi: BitTorrent, Emule

### Stile Pipe and Filter
Le sue componenti sono:
- **filtri**: effettuano trasformazioni che elaborano IN -> OUT
- **pipe**: connettori che trasmettono i dati fra un filtro e un altro

*Pro*
- ri-uso delle trasformazioni
- semplice da capire (composizione di filtri), modificare e implementare
- supporta l'esecuzione parallela

*Contro*
- no per sistemi interattivi (menu, click)
- solitamente indicato per **sistemi batch**: sistemi con operazioni sequenziali senza operazioni di input / output.

### Stili di controllo

Si occupano del flusso di controllo fra vari sottosistemi.
Due stili
- centralizzato: un sottosistema controlla l'avvio e l'arresto di altri sistemi
	- call return
	- manager
- basato su eventi: nessun controllore, ogni sistema può rispondere a eventi generati da altri sistemi
	- broadcast

#### Call-Return Model
- applicato a sottosistemi sequenziali (no paralleli)
- la componente Main (Driver) definisce e controlla l'ordine di esecuzione
- modello top-down
- solo un sottosistema per volta va in esecuzione

#### Manager Model
- i sottosistemi possono lavorare in parallelo
- una componente 'manager' controlla i processi

#### Broadcast Model
- no controllore: una componente 'annuncia' alle altre uno o più eventi
- ogni componente influenzata (ovvero che possiede procedure di risposta associate all'evento) gestisce da sè la risposta con una procedura.

*Pro*
- facile aggiungere/rimuovere/modificare componenti

*Contro*
- non si sa quando effettivamente l'evento sarà gestito dalle altre componenti una volta inviato 
- più difficile da implementare e testare

