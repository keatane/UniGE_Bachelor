#ifndef STRINGLIST
#define STRINGLIST

#include <string>
#include "list_basic_types.h"
//typedef struct cell_impl cell;//nascondiamo implementazione di cell
//typedef cell* list; // Definisco il puntatore alla struct cell (la lista)

void headInsert(list& l, std::string s);

void read(list& l);/*legge valori da input e li memorizza nella lista

La funzione non deve rilasciare la memoria puntata da l, ma deve allocare la memoria necessaria a memorizzare gli elementi della listaDopo la chiamata l==testa della lista letta*/

void print(const list& l);

std::string getElem(const list l, int index);

// insertAt inserimento in posizione fissata

void deleteAt(list& l, int index);//cancella elemento in posizione fissata

// deleteOnce cancella la prima occorrenza di una stringa in una lista

// deleteAll cancella tutte le occorrenze di una stringa in una lista
void deleteAll(list& l, std::string s);

// insertInOrder inserisce in una lista ordinata mantendola ordinata

#endif
