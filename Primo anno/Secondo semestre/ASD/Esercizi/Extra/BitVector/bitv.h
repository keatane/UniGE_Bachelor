#ifndef BITV
#define BITV

#include <iostream>

namespace bitv{

typedef bool Elem;

const int BLOCKDIM = 10; // capienza default dell'array

typedef struct{

	int maxsize; // capienza array (dimensione)
	Elem* elem;
} Bitv;

typedef Bitv Set;

Set emptySet (Set &v); /* crea un set vuoto */

Set insertElem (int e, Set &v); /* inserisce un elem nel set */

Set deleteElem (int e, Set &v); /* cancella un elem dal set */

Set setUnion (const Set &v, const Set &w); /* unione di due set */

Set setIntersection (const Set &v, const Set &w); /* intersezione di due set */

bool isEmpty (const Set &v); /* controlla se un set è vuoto */

unsigned int size (const Set &v); /* restituisce il numero di elementi presenti nel set */

bool member (int e, Set &v); /* verifica se un elemento è presente nel set */

void printSet(const Set &v); /* stampa il set */

}

#endif
