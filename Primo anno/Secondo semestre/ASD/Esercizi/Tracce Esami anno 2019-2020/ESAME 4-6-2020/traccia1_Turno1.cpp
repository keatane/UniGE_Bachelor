/***************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1)*/
/***************************************************/

// Descrizione:
// In questo laboratorio si considera il tipo di dato Albero binario dove i nodi sono numeri interi.
// Un'albero binario e' un albero con radice dove ogni nodo ha al piu' due figli

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
#include <iostream>
#include <string>

using namespace std;

// Implementa Albero binario con strutture collegate (Nodo) mediante puntatori e Label dotata di ordinamento
namespace tree {
  typedef int Label;   
  struct Nodo; 
  typedef Nodo* Tree; // un albero e' identificato dal puntatore alla sua radice
  const Tree alberoVuoto = NULL; 
  
  // Costruisce albero vuoto
  Tree creaAlberoVuoto();
  // Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
  bool vuoto(const Tree& t);
  // Aggiunge nodo radice, fallisce se l'albero e' non vuoto
  bool inserisciRadice(const Label l, Tree& t); 
  // Aggiunge nuovo nodo sinistro di un nodo esistente. Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_sx" e' gia' presente nell'albero
  bool inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t);
  // Aggiunge nuovo nodo destro di un nodo esistente. Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_dx" e' gia' presente nell'albero
  bool inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t);   
  
  // Stampa l'albero usando il formato descritto sotto, simile a quello di input. Se l'albero e' vuoto stampa "Albero vuoto"
  void stampa(const Tree& t);
  // Ritorna il numero di terminali isolati. Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cioè il genitore della foglia non ha altri figli)
  int contaNumeroTerminaliIsolati(const Tree& t);
}

using namespace tree;

// il nodo di un albero e' caratterizzato dall'etichetta (in questo caso un intero), 
// il puntatore al figlio sinistro e il puntatore al figlio destro
struct tree::Nodo {
    Label label;    
    Nodo *sinistro;
    Nodo *destro;
};

/*******************************************************************************************************/
// Funzioni ausiliarie
/*******************************************************************************************************/

// Data un'etichetta l crea il nodo con quella etichetta e ne restituisce il puntatore 
Nodo* createNode(const Label l) { 
    Nodo* t = new Nodo;
    t->label = l;
    t->sinistro = t->destro = NULL;
    return t;
}

// Data un'etichetta l e un albero t (ovvero, un albero la cui radice
// e' il nodo puntato da t), restituisce il puntatore al nodo dell'albero t che ha quell'etichetta 
// (NULL se nessun nodo ha quell'etichetta)
Nodo* getNode(const Label l, const Tree& t) { 
    // se l'albero e' vuoto restituisco il nodo vuoto
    if (vuoto(t))
        return alberoVuoto;
  
    // se l'etichetta dell'albero e' quella cercata, restituisco t
    if (t->label == l) 
        return t;
        
    // cerca nei figli
    Nodo* aux = alberoVuoto;
 
    if (!vuoto(t->sinistro)) aux = getNode(l, t->sinistro);
    if (!vuoto(aux)) return aux;
    if (!vuoto(t->destro)) aux = getNode(l, t->destro);
    if (!vuoto(aux)) return aux;
    // non trovato!
    return NULL;
}


/*******************************************************************************************************/
// Funzioni relative all'albero binario
/*******************************************************************************************************/

// Costruisce l'albero vuoto
Tree tree::creaAlberoVuoto() {
   return alberoVuoto;
}

// Restituisce true se l'albero t e' vuoto (oppure se il puntatore punta a NULL), false altrimenti
bool tree::vuoto(const Tree& t) { 
   return (t==alberoVuoto);
}

// Aggiunge il nodo radice, fallisce se l'albero e' non vuoto
bool tree::inserisciRadice(const Label l, Tree& t) {
    if (!vuoto(t)) return false;
    t = createNode(l);  // crea il nodo; t che era vuoto diventa l'albero con il solo nodo appena creato
    return true;
}

// Aggiunge nuovo nodo sinistro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero o se la label "nome_figlio_sx" e' gia' presente nell'albero
bool tree::inserisciFiglioSX(Label questo, Label nome_figlio_sx, Tree& t) {
    Tree q = getNode(questo, t);
    if (vuoto(q)) return false;
    Tree sx = getNode(nome_figlio_sx, t);
    if (!vuoto(sx)) return false;
    Tree nuovo = createNode(nome_figlio_sx);
    q->sinistro = nuovo;
    return true;
}

// Aggiunge nuovo nodo destro di un nodo esistente
// Ritorna false se non esiste il nodo "questo" nell'albero se la label "nome_figlio_dx" e' gia' presente nell'albero
bool tree::inserisciFiglioDX(Label questo, Label nome_figlio_dx, Tree& t) {
    Tree q = getNode(questo, t);
    if (vuoto(q)) return false;
    Tree dx = getNode(nome_figlio_dx, t);
    if (!vuoto(dx)) return false;
    Tree nuovo = createNode(nome_figlio_dx);
    q->destro = nuovo;
    return true;
}

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

/* Sviluppare le due seguenti funzioni C/C++:

   1) stampa() che visualizza l'albero su schermo usando un formato simile a quello di input. 
   Ad esempio un'albero formato da 4 nodi in cui abbiamo alla radice '1' con i figli '2' (figlio sinistro) e '3' (figlio destro) 
   e di cui '4' è figlio sinistro di '2' sara' stampato nel seguente modo:
        
        1
        S 1 2
        D 1 3
        S 2 4
    
    Se l'albero e' vuoto questa funzione deve stampare la stringa "Albero vuoto". Si suggerisce di implementare una funziona ricorsiva.
      
   2) contaNumeroTerminaliIsolati() che ritorna il numero di terminali isolati dell'albero.
      Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cioè il genitore della foglia non ha altri figli).
      Ad esempio: un albero formato da 3 nodi in cui abbiamo alla radice '1' con i figli '2' (figlio sinistro) e '3' (figlio destro) 
      avrà zero nodi isolati. Mentre, un'albero formato da 4 nodi in cui abbiamo alla radice '1' con i figli '2' (figlio sinistro) e '3' (figlio destro) 
      e di cui '4' è figlio sinistro di '2' (esempio visto sopra) avrà un nodo isolato (il nodo 4). 
      Si suggerisce di implementare una funzione ricorsiva.
      
*/

// Stampa l'albero usando il formato simile a quello di input. Se l'albero e' vuoto stampa "Albero vuoto"
void tree::stampa(const Tree& t) {

}

// Ritorna il numero di terminali isolati. Denominiamo terminale isolato una qualunque foglia, esclusa la radice, priva di "fratelli" (cioe' il genitore della foglia non ha altri figli)
int tree::contaNumeroTerminaliIsolati(const Tree& t) {
    return 0; 
}


int main() {
    // creazione albero binario
    Tree t = creaAlberoVuoto();  
    // inserimento di nodi in un albero binario
    inserisciRadice(1, t); // inseriamo la radice
    inserisciFiglioSX(1, 2, t);
    inserisciFiglioDX(1, 3, t);
    inserisciFiglioSX(2, -4, t);
    inserisciFiglioDX(2, -5, t);
    inserisciFiglioSX(-5, 7, t);
    
    cout << "***** PROVA DI ESAME DI LABORATOTIO DI ASD (traccia 1)" << endl;
    cout << "*** PRIMA FUNZIONE *** " << endl;
    cout << "IL TEST E' CORRETTO SE LE DUE STAMPE SONO UGUALI (A MENO DI PERMUTAZIONI DEGLI ARCHI)" << endl;
    cout << "--- risultato corretto" << endl;
    cout << "1" << endl;
    cout << "S 1 2" << endl;
    cout << "D 1 3" << endl;
    cout << "S 2 -4" << endl;
    cout << "D 2 -5" << endl;
    cout << "S -5 7" << endl;
    cout << "--- stampa della vostra funzione" << endl;
    stampa(t); 
    cout << endl;
  
    cout << "*** SECONDA FUNZIONE *** " << endl;
    if (contaNumeroTerminaliIsolati(t)==1) cout << "TEST PASSATO";
    else cout << "TEST FALLITO";
   
    return 0;
}

