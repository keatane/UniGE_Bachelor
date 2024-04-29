////////////////////////////////////////////////////
//
//  Questa serve per realizzare le liste che vengono fuori come risultato di
//  operazioni quali il percorso tra due citta' (che viene rappresentato come
//  lista di nomi di citta') e l'elenco delle citta' adiacenti a una certa
//  citta' (anch'esso rappresentato come lista di nomi di citta').
//  Non serve invece per le liste dei vertici nel grafo, ne' per le liste di
//  adiacenza di ciascun vertice.
//
////////////////////////////////////////////////////

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string> 

using namespace std; 
 
namespace list{

/**************************** Tipi e costanti *********************************************/
typedef string Elem;      // tipo base, compatibile con il tipo Label dell'grafo 

const Elem emptyElem = "$#$#$";

struct list;

typedef list * List;

const List emptyList = nullptr;

// ATTENZIONE: per la realizzazione del laboratorio 8 non vi serviranno tutte le seguenti funzioni ma solo un sottoinsieme
void clear(List&);          /* "smantella" la lista */
void set(int, Elem, List&); /* modifica l'elemento in posizione pos */
void add(int, Elem, List&); /* inserisce l'elemento in posizione pos, shiftando a destra gli altri elementi */
void addBack(Elem, List&);  /* inserisce l'elemento alla fine della lista */
void addFront(Elem, List&); /* inserisce l'elemento all'inizio della lista */
void removePos(int, List&); /* cancella l'elemento in posizione pos dalla lista  */
Elem get(int, const List&);	/* restituisce l'elemento in posizione pos */
List createEmpty();         /* crea la lista vuota e la restituisce */
bool isEmpty(const List&);
int size(const List&);
}

void printList(const list::List&);
