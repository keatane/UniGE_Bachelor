# Architettura Client-Server

Web Server <--> Internet <--> Client
- web server (always on) è un programma sempre attivo in ascolto sulle porte 80 / 443 (https); sono raggiunti dai client tramite URL
- client: richiedono risorse al web server

Si usa il protocollo HTTP: richieste e risposte in formato testuale, il cui header contiene varie informazioni per la trasmissione.

Le pagine restituite al client possono essere:
- file **statici**, salvati sul filesystem del server (es. .html)
- script eseguiti dal server (output **dinamico**)
	- usiamo PHP (.php)

Si usa richiamare script che creano il file html (l'unica estensione che il browser possa leggere per visualizzare siti web)
Le pagine dinamiche sono generate interrogando DB (back-end delle web-app)

Usando XAMPP posso interagire con **localhost**: un web server che interagisce con la macchina locale attraverso il browser (interfaccia **loopback**).