/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo gli Insiemi di numeri interi.
// In questa versione molto semplificata un'insieme e' implementato come un array statico di 
// dimensione massima uguale a 8 (per semplificare la prova non consideriamo il caso di overflow).
//
// Per semplificare la prova di esame non esistono operazioni di creazione dell'insieme e di 
// inserimento di un elemento in un insieme (come ad esempio visto a lezione).
// Anche il fatto che un elemento non possa comparire piu' di una volta in un insieme viene 
// gestito a livello di inizializzazione evitando di inserie due volte lo stesso numero intero.

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:

#include<iostream>
using namespace std;

const int dim = 8; // dimensione massima di un insieme

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

/* Sviluppare le tre seguenti funzioni C/C++:

   1) is_in() che controlla se un elemento (passato come parametro) e' presente in un insieme 
      (anch'esso passato come parametro).
      
   2) intersection() che calcola l'intersezione tra due insiemi passati come parametri e mette il risultato in un terzo parametro.
      La funzione deve anche restituire la dimensione dell'insieme calcolato.
   
   3) equal() che restituisce 'true' se i due insiemi passati come parametri sono uguali e 'false' 
      altrimenti.
      
*/

// Ritorna true se 'x' e' presente nell'insieme 'a', false altrimenti
// si suppone che l'insieme 'a' non possa contenere elementi "doppi"
bool is_in(const int a[], int x) {
    return false; // istruzione inserita solo per non avere problemi di compilazione
}

// Calcola l'intersezione di 'a' e 'b' e mette il risultato in 'c'. Inoltre la funzione deve anche restituire la dimensione (cioe' la size) dell'insieme 'c' 
// dell'insieme intersezione calcolato.
// Assumiamo che 'a' e 'b' contengano entrambi 'dim' elementi, mentre 'c' sia inizialmente vuoto.
// si suppone che 'a' e 'b' non possano contenere elementi "doppi"
int intersection(const int a[], const int b[], int c[]) {
    return 0; // istruzione inserita solo per non avere problemi di compilazione
}

// Ritorna 'true' se 'a' e 'b' sono uguali, 'false' altrimenti
// si suppone che 'a' e 'b' non possano contenere elementi "doppi"
bool equal(const int a[], const int b[]) {
    return true; // istruzione inserita solo per non avere problemi di compilazione
}

// Stampa l'insieme 'a'
// si suppone che 'a' non possa contenere elementi "doppi"
void print(const int a[], int size) {
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    // inizializzazione degli insiemi (non possono essere inseriti numeri doppi)
    int x[dim] = {1, 3, 5, 7, 90, 32, 45, 10};
    int equal_to_x[dim] = {1, 10, 7, 5, 90, 32, 45, 3};
    int y[dim] = {4, 5, 45, 10, 33, 6, 1, 2};
    int z[dim]; // insieme nel quale verra' inserito il risultato dell'intersezione tra x[] e y[]
    
    cout << "*** PRIMA FUNZIONE *** " << endl;
    if (is_in(x, 5)==1) cout << "TEST 1 IS_IN PASSATO" << endl;
    else cout << "TEST 1 IS_IN FALLITO" << endl;
    if (is_in(x, 11)==0) cout << "TEST 2 IS_IN PASSATO" << endl;
    else cout << "TEST 2 IS_IN FALLITO" << endl;
    cout << endl;
    
    cout << "*** SECONDA FUNZIONE *** " << endl;
    cout << "IL TEST INTERSEZIONE tra x[] e y[] E' CORRETTO SE LE DUE STAMPE SONO UGUALI (A MENO DI PERMUTAZIONI DEI NUMERI INTERI)" << endl;
    cout << "--- risultato corretto" << endl;
    cout << "1 5 45 10" << endl;
    cout << "--- stampa della vostra funzione" << endl;
    print(z, intersection(x, y, z));
    cout << endl << endl;
    
    cout << "*** TERZA FUNZIONE *** " << endl;
    if (!equal(x, y)) cout << "TEST 1 UGUALE PASSATO" << endl;
    else cout << "TEST 1 UGUALE FALLITO" << endl; 
    
    if (equal(x, equal_to_x)) cout << "TEST 2 UGUALE PASSATO" << endl;
    else cout << "TEST 2 UGUALE FALLITO" << endl;
    return 0;
}


