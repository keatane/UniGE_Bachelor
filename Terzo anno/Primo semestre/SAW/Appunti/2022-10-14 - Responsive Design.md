# Responsive Design
Obiettivo: progettare pagine per dispositivi diversi (Desktop, Mobile)
- focus sullo schermo più che sul dispositivo
- accesso mobile completo come per desktop
- risultato: better user experience

## Media query
@media {...} permette di specificare il tipo e le dimensioni del dispositivo (schermo) su cui le regole scritto di seguito si applicano.
Esistono **breakpoint** che permettono di lavorare su dimensioni prefissate.

## FlexBox
Modulo che permette di costruire layout flessibili
Necessità di una classe con "display: flex", che rende gli elementi dentro un cointainer flessibili
Con "flex-wrap" si va a capo quando gli oggetti iniziano a essere nascosti dalla finestra.

## CSS-Grid Layout
Ottengo la stessa cosa del *flex*, ma rientrerà nello standard
- necessità di una classe con "display: grid"; posso creare una griglia con dimensione variabile (es. la prima riga con tre colonne e la seconda con quattro), definendo inoltre "frazioni" di griglia (potendo specificare ad esempio che la colonna centrale è il doppio di quelle laterali).

## Sito web usabile - consigli
- attenzione alle famiglie di carattere
- poco grassetto (significativo), no: corsivo, maiuscolo, sottolineato
- link significativi (no "Premi qui")
- i colori freddi recedono, i caldi avanzano
- chiaro su scuro appare più sottile
- non veicolare messaggi solo via colori (daltonismo)
- il colore ha significato e deve rispettare i contrasti
- non affollare la pagina (max 7+-2 elementi per volta)
- contenuti importanti al centro