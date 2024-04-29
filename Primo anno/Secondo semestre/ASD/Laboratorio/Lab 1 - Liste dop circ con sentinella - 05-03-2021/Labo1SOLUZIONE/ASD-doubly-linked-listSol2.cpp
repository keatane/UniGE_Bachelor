// Implementa le funzioni sulle liste realizzate con strutture doppiamente collegate, circolari, con sentinella, senza ordinamento

// FILE DA MODIFICARE

#include "ASD-doubly-linked-list.h"


using namespace list;

struct list::node {  // descrivo qui, fuori dal namespace, come e' fatta la struttura node: i dettagli interni non saranno visibili dal main
    Elem info;
    node *prev;
    node *next;
};

/*************************************************/
/* Implementazione delle operazioni di utilita'† */
/*************************************************/

void readFromStream(istream& str, List& l) {
    createEmpty(l);
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    // assumiamo che il segnale di fine input nel file sia  FINEINPUT
    while (e != FINEINPUT)  {     
        addRear(e, l);   // aggiunge l'elemento alla fine della lista
        str>>e;
        if (!str) throw runtime_error("Errore inserimento dati\n");
    }
}

/* legge il contenuto di una lista da file */
void readFromFile(string nome_file, List& l) {
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    readFromStream(ifs, l);
}


/* legge il contenuto di una lista da standard input */
void readFromStdin(List& l) {
   cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " << FINEINPUT << " per terminare\n";
   readFromStream((std::cin), l);
}

/* stampa la lista */
void print(const List& l) {
    
   List q = l->next;  // q "salta la sentinella" e va alla testa della lista
   
    while (q != l) {   // avanza finche' non finisce la lista
      cout << q->info << "; ";
      q = q->next;
    }
}

/**************************************************/
/* Implementazione delle operazioni nel namespace */
/**************************************************/

node* goToPosition(const List l, int pos) {
    
    // Assumo che all'esterno sia stata verificata l'ammissibilità della posizione
   
    // salto la sentinella
    node *q = l->next;
    
    // procedo fino alla posizione che mi interessa
    for(int i = 0; i < pos; ++i)
        q = q->next;
    
    return q;
}

/* crea la lista vuota */
void list::createEmpty(List& l) {

    // Crea il nodo sentinella
    l = new node;
    // Sistema i puntatori, che puntano a se stesso
    l->next = l;
    l->prev = l;
    
}

/* "smantella" la lista svuotandola */
void list::clear(const List& l) {
    
    // Salta la sentinella
    node *p = l->next;
    node *q;
    // va bene anche List aux, auxn;
    
    while(p != l) { // finchè ci sono elementi nella lista
        q = p->next; // tengo traccia del prossimo elemento in una variabile temporanea
        delete p; // cancello cella corrente
        p = q; // aux punta al prossimo elemento
    }
    // Notate che non serve perdere tempo ad aggiustare i puntatori next e prev, dato che stiamo svuotando la lista
    
    // la lista adesso è vuota, quindi i puntatori nella sentinella puntano alla sentinella stessa
    l->next = l;
    l->prev = l;

}

/* restituisce l'elemento in posizione pos se presente; restituisce un elemento 
che per convenzione si decide che rappresenta l'elemento vuoto altrimenti*/
Elem list::get(int pos, const List& l) {
    
    // NOTA: le posizioni ammissibili vanno da 0 a N-1 dove N=size(l)
    
    // Se la posizione non è tra quelle possibili restuisce l'elemento vuoto
    if(pos >= size(l) || pos < 0)
        return EMPTYELEM;
    
    node* q = goToPosition(l, pos);
    
    return q->info;
    
}

/* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
void list::set(int pos, Elem e, const List& l) {
    
    // NOTA: le posizioni ammissibili vanno da 0 a N-1 dove N=size(l)
    
    // Mi conviene fare il controllo sull'ammissibilità della posizione cercando quelle ammissibili, dato che se la posizione non è ammissibile non devo fare niente
    if(pos < size(l) && pos >= 0) { // se la posizione è ammissibile...
        
        node* q = goToPosition(l, pos);
        
        // modifico l'elemento
        q->info = e;
    }
}

/* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void list::add(int pos, Elem e, const List& l) {
    
    // Identifichiamo alcuni casi:
    // Se pos == 0: aggiungo in testa
    // Se pos == size(l): aggiungo in coda
    // Aggiungo in una posizione intermedia se la posizione è ammissibile, ossia se è compresa tra 1 e size(l)-1
    // Altrimenti non faccio nulla (posizione non ammissibile)
    
    if(pos == 0)
        addFront(e, l);
    else if(pos == size(l))
        addRear(e, l);
    else if(pos >= 1 && pos <= size(l)-1 ) {
        
        node* q = goToPosition(l, pos-1);
        
        // creo un nuovo nodo
        List p = new node;
        p->info = e;
        
        // aggiusto i puntatori
        p->prev = q;
        p->next = q->next;
        q->next = p;
        p->next->prev = p;
    }
        
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem e,  const List& l) {
   
    // creo un nuovo nodo
    List q = new node;
    q->info = e;
    
    // sistemo i puntatori del nuovo nodo e aggiorno quelli della sentinella
    q->prev = l->prev;
    q->prev->next = q;
    q->next = l;
    l->prev = q;
    
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem e, const List& l) {
    List q = new node;
    q->info = e;
    q->next = l->next;
    q->next->prev = q;
    q->prev = l;
    l->next = q;
}

/* cancella l'elemento in posizione pos dalla lista */
void list::removePos(int pos, const List& l) {
    
    // se pos è ammissibile...
    if(pos >= 0 && pos < size(l)) {
        
        node* q = goToPosition(l, pos);
        
        // aggiusto i puntatori dei nodi precedente e successivo a quello che sto per cancellare
        q->prev->next = q->next;
        q->next->prev = q->prev;
        
        // rimuovo l'elemento
        delete q;
    }

}

 /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
void list::removeEl(Elem e, const List& l) {
    
    // salto la sentinella e dichiaro una variabile node di supporto
    node *p = l->next, *q;
    
    // finchè ci sono elementi nella lista
    while(p != l) {
        if(p->info == e) { // se trovo un elemento da cancellare
            q = p->next; // tengo traccia della posizione seguente a quella corrente, da cui devo ripartire al controllo successivo
            
            // aggiusto i puntatori dei nodi precedente e successivo a quello che sto per cancellare
            p->prev->next = q;
            q->prev = p->prev;
            
            // cancello il nodo
            delete p;
            
            // riassegno elemento corrente
            p = q;
        } else // procedo con la scansione della lista
            p = p->next;
    }
}

/* restituisce true se la lista e' vuota (ed e' vuota se il next di l, e' l stessa */
bool list::isEmpty(const List& l) {
        return l->next == l;
}

// implementazione ricorsiva della funzione per calcolare la lunghezza della lista

int size_iter(List& aux, const List l) {
    if(aux==l)
        return 0;
    return 1 + size_iter(aux->next, l);
}


/* restituisce la dimensione della lista */
int list::size(const List& l) {
    return size_iter(l->next, l);
}



