// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
Elem info;
node *prev;
node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'  */
/*************************************************/

void readFromStream(istream& str, List& l)
{
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e != FINEINPUT)  // assumiamo che il segnale di fine input nel file sia  FINEINPUT
        {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
        }
}

void readFromFile(string nome_file, List& l)  /* legge il contenuto di una lista da file */
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}



void readFromStdin(List& l)         /* legge il contenuto di una lista da standard input */
{
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}


void print(const List& l)           /* stampa la lista */
{
    List q = l->next;  // q "salta la sentinella" e va alla testa della lista
    while (q != l) {   // avanza finche' non finisce la lista
        cout << q->info << "; ";
        q = q->next; 
    }
}


// Ricerca di un intero nella lista. Restituisce il puntatore al nodo che lo
// contiene, oppure alla sentinella se non e' presente il valore cercato.
// NOTA: se "e" non esiste nella lista, la funzione restituisce il puntatore
// alla sentinella.

List searchElemPointer(Elem e, List l)
{
    // "salta la sentinella" e vai alla testa della lista,
    // poi avanza finche' non finisce il giro o non trovi l'elem cercato
    List q = l->next;
    while (q != l && q->info != e)
        q = q->next;
    return q;
}


// Ricerca di una posizione nella lista. Restituisce il puntatore al nodo
// che si trova in quella posizione, se tale posizione esiste.
// Se invece la posizione non esiste, restituisce il puntatore alla sentinella
// e "pos" viene modificato, diventando uguale al numero di elem nella lista.

List searchPositionPointer(int &pos, List l)
{
    // "salta la sentinella" e vai alla testa della lista,
    // poi avanza finche' non trovi la posizione cercata o non finisce il giro

    List q = l->next;
    int counter = 0;
    while (q != l && counter < pos) {
        q = q->next; 
        ++counter;    
    }

    // a questo punto "counter" e' uguale a "pos" se la posizione esiste,
    // altrimenti e' uguale alla dimensione della lista
    // (poiche' ha fatto l'intero giro senza trovare "pos").

    pos = counter;
    return q;
}


// Inserisce un nuovo elemento subito prima del nodo puntato da "p"

void insertBeforePointer(Elem e, const List& p)
{
    List q = new node;
    q->info = e;
    q->prev = p->prev;
    q->next = p;
    p->prev = q;
    q->prev->next = q;
}


/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/


/* "smantella" la lista svuotandola */

void list::clear(const List& l)
{
    List aux;

    // "salta la sentinella" e vai alla testa della lista,
    // poi avanza finche' non finisce il giro, man mano deallocando gli elem
    List q = l->next;
    while (q != l) {
        aux = q;
        q = q->next; 
        delete aux;
    }
    // lista svuotata.  sentinella punta a se stessa.
    l->prev = l->next = l;
}



// restituisce l'elemento in posizione "pos" se tale posizione esiste,
// altrimenti restituisce un elemento che per convenzione rappresenta
// l'elemento nullo.

Elem list::get(int pos, const List& l)
{
    if (pos < 0) return EMPTYELEM;

    // vai alla posizione "pos"
    List q = searchPositionPointer(pos, l);

    // se "pos" non esiste, la funzione searchPositionPointer() restituisce
    // un puntatore alla sentinella, poiche' ha terminato il giro senza trovare
    // nulla.  In tal caso restituisci l'elem. nullo.
    // Altrimenti restituisci l'elem. trovato.

    if (q == l) return EMPTYELEM;
    return q->info;
}


// modifica l'elemento in posizione "pos", se la posizione esiste

void list::set(int pos, Elem e, const List& l)
{
    if (pos < 0) return;

    // vai alla posizione "pos"
    List q = searchPositionPointer(pos, l);

    // se "pos" non esiste, la funzione searchPositionPointer() restituisce
    // un puntatore alla sentinella, poiche' ha terminato il giro senza trovare
    // nulla.  In tal caso non fare nulla.
    // Altrimenti modifica l'elem. trovato.

    if (q != l) q->info = e;
}


// inserisce un nuovo elemento in posizione "pos",
// facendo scorrere a valle gli elementi da "pos" in giu'.

void list::add(int pos, Elem e, const List& l)
{                                               
    if (pos < 0) return;

    // qui c'e' un aspetto delicato da implementare:
    // se la lista ha N elementi, la posizione pos=N a rigore non esiste
    // (perche' le posizioni vanno da 0 a N-1)
    // ma l'inserimento in posizione pos=N ha senso, perche' avverrebbe
    // a fine lista.

    // vai alla posizione "pos".
    // NOTA: se "pos" non esiste, la funzione searchPositionPointer()
    // modifichera' il parametro "pos" che diventera' uguale al numero di
    // elementi presente nella lista.  cio' sara' utile piu' avanti, ma
    // in previsione di cio' conviene conservare il valore originario di "pos"
    // in una variabile apposita.

    int pos_orig = pos;
    List q = searchPositionPointer(pos, l);

    // se "pos" esiste, la funzione searchPositionPointer() restituisce
    // un puntatore alla posizione trovata, che sara' diversa dalla sentinella.
    // in tal caso inserisce subito a monte di quel nodo e tutto finisce li'.

    if (q != l) {
        insertBeforePointer(e, q);
        return;
    }

    // qui ci si arriva solo se "pos" non esiste.
    // in questo caso "pos" e' stato modificato, e' diventato uguale al
    // numero N di elementi presenti in lista.  abbiamo pero' conservato
    // il valore originale di "pos".

    // come discusso sopra, dobbiamo gestire il caso particolare pos=N
    // dove N e' la dimensione della lista, l'unica situazione in cui
    // l'inserimento sarebbe comunque ammissibile anche se "pos" in realta'
    // non esiste.  questo lo vediamo confrontando il "pos" originale
    // con quello modificato dalla searchPositionPointer().

    if (pos_orig == pos)
        insertBeforePointer(e, l);

    // altrimenti "pos" non era comunque ammissibile, non fare nulla.
}


// inserisce un nuovo elemento alla fine della lista

void list::addRear(Elem e,  const List& l)
{
    insertBeforePointer(e, l);
}


// inserisce un nuovo elemento all'inizio della lista

void list::addFront(Elem e, const List& l)
{
    insertBeforePointer(e, l->next);
}


// cancella dalla lista l'elemento in posizione "pos", se esiste

void list::removePos(int pos, const List& l)
{
    if (pos < 0) return;

    // vai alla posizione "pos"
    List q = searchPositionPointer(pos, l);

    if (q != l) {
        // trovato il nodo in posizione "pos".
        // esegue il bypass tra il suo predecessore e il suo successore,
        // poi dealloca il nodo.
        q->next->prev=q->prev;
        q->prev->next=q->next;
        delete q;
    }

    // arriva qui solo se "pos" non esiste.  In tal caso non fare nulla.
}


// cancella dalla lista tutte le occorrenze del valore "e"

void list::removeEl(Elem e, const List& l)
{
    List q = l->next;

    while (q != l)
        if (q->info == e) {
            // trovata una istanza di "e".
            // esegui il bypass di quel nodo dalla lista
            // e poi dealloca il nodo
            q->next->prev=q->prev;
            q->prev->next=q->next;
            delete q;
        }
}


// restituisce true se e solo se la lista e' vuota
// (ed e' vuota se il next di l, e' l stessa

bool list::isEmpty(const List& l)
{
    return (l->next == l);
}


// restituisce la dimensione della lista

int list::size(const List& l)
{

// "salta la sentinella" e vai alla testa della lista,
// poi avanza finche' non finisce il giro, e man mano incrementa un contatore.

    int counter = 0;
    List q = l->next;
    while (q != l) {
        q = q->next;
        ++counter;
    }
    return counter;
}


// crea la lista vuota

void list::createEmpty(List& l)
{
    // Crea il nodo sentinella
    l = new node;
    // Concatenalo circolarmente a se stesso
    l->prev = l->next = l;
}
