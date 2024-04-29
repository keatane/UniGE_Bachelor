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
/* Implementazione delle operazioni di utilita'  */
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

/*	
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
	---------------- Ultima modifica ------------------
	di: Brega Pietro, Lazzarini Roberto, Cattaneo Kevin
	in data: 09/03/2021
	=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/	 

/* crea la lista vuota */
void list::createEmpty(List& l) {
	// L'unico elemento è la sentinella
	node* aux = new node;
	l = aux;
	l->next = aux;
	l->prev = aux;
}

/* "smantella" la lista svuotandola */
void list::clear(const List& l) {
	if(isEmpty(l)) return;
	
	node* aux = l->next->next;
	delete l->next;
	l->next = aux;
	aux->prev = l;
	return clear(l); // richiamo sulla stessa lista (la base è la sentinella)
}

/* restituisce l'elemento in posizione pos se presente; restituisce un elemento 
che per convenzione si decide che rappresenta l'elemento vuoto (EMPTYELEM) altrimenti*/
Elem list::get(int pos, const List& l) {
	if(isEmpty(l)) return EMPTYELEM;
	
	List aux = l->next; // salto la sentinella
	int i=0;
		while(aux->next!= l && i<pos)
		{
			aux = aux->next;
			i++;
		}
	if(i==pos)
		return aux->info;
	return EMPTYELEM;
}

/* modifica l'elemento in posizione pos, se la posizione e' ammissibile */
void list::set(int pos, Elem e, const List& l) {
   	List aux = l->next;
	int i=0;
	
	// Nel caso di una lista vuota, automaticamente non si entra nel while con (aux->next != l)
		while(aux->next!= l && i<pos)
		{
			aux = aux->next;
			i++;
		}
	// La verifica aux!=l permette di non accedere alla sentinella (in caso di lista vuota)
	if(aux!= l && i==pos)
		aux->info = e;
}

/* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void list::add(int pos, Elem e, const List& l) {                                               
  	// In caso di indici non ammissibili si è deciso di lasciare che il programma non alteri
  	// la lista nè visualizzi in alcun modo un messaggio di errore
 	List aux = l->next;
	int i=0;
		while(aux->next!= l && i<pos)
		{
			aux = aux->next;
			i++;
		}
	if(i==pos)
		addRear(e,aux);
}

/* inserisce l'elemento alla fine della lista */
void list::addRear(Elem e,  const List& l) {
	
	node* aux = new node;
	aux->info = e;
	aux->next = l;
	aux->prev = l->prev;
	l->prev->next = aux; // prima di modificare l->prev
	l->prev = aux;
}

/* inserisce l'elemento all'inizio della lista */
void list::addFront(Elem e, const List& l) {
     
     node* aux = new node;
     aux->info = e;
     aux->prev = l;
     aux->next = l->next;
     l->next->prev = aux; // prima di modificare l->next
     l->next = aux;
}

/* cancella l'elemento in posizione pos dalla lista */
void list::removePos(int pos, const List& l) {
	// In caso di lista vuota non viene alterata la lista
	List aux = l->next;
	int i=0;
		while(aux->next!= l && i<pos)
		{
			aux = aux->next;
			i++;
		}
	if(aux!=l && i==pos){
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		delete aux;
	}
}

 /* cancella tutte le occorrenze dell'elemento elem, se presenti, dalla lista */
void list::removeEl(Elem e, const List& l) {
	// In caso di lista vuota non viene alterata la lista
	List aux = l->next;
		while(aux!= l)
		{
			if (aux->info == e){
				aux->prev->next = aux->next;
				aux->next->prev = aux->prev;
				delete aux;
			}
			aux = aux->next;
		}
}

/* restituisce true se la lista e' vuota;
e' vuota se il next di l, e' l stessa, ovvero ho solo la sentinella) */
bool list::isEmpty(const List& l) {
	return (l->next==l);
}

 /* restituisce la dimensione della lista */
int list::size(const List& l) {
	int i=0;
	for(node* aux=l->next; aux!=l; aux=aux->next) i++;
	return i;
}


