// list.h: contiene tutti i prototipi delle funzioni

#ifndef LIST_H // se non è stato definito tale simbolo, viene definito
#define LIST_H

#include <iostream>
#include <string>

typedef string Elem; // tipo base della lista

struct cell{

};

typedef cell* list; // diamo un nome più evocativo allla nostra lista semplice

void headInsert(list& l, std::string s); // inserisce un elemento in testa alla lista
void read(list& l);/* legge valori da input e li memorizza nella lista
                        La funzione non deve rilasciare la memoria puntata da l, ma deve
                        allocare la memoria necessaria a memorizzare gli elementi della lista
                        Dopo la chiamata l==testa della lista letta*/
void tailInsert(list &l, string x); // inserisce un elemento in coda alla lista
void print(const list l); // stampa una lista
void deleteAll(list &l); // cancella tutte le occorrenze di una stringa in una lista

#endif