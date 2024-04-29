#include "bitv.h"

using namespace std;
using namespace bitv;

/**** Funzioni ausiliarie ****/

/*
void addSize(Set &v){
	v.maxsize += BLOCKDIM;
	Elem* aux = new Elem[v.maxsize]; // nuovo insieme di elementi
	for(int i=0; i<v.maxsize; ++i)
		aux[i] = v.elem[i];
	delete[] v.elem;
	v.elem = aux;
}
*/

/**** Funzioni principali ****/

/* crea un set vuoto */
Set bitv::emptySet (Set &v){
	v.maxsize = BLOCKDIM;
	v.elem = new Elem[v.maxsize];
	for (int i=0; i<v.maxsize; ++i)
		v.elem[i] = 0;
	return v;
}

/* inserisce un elem nel set */
Set bitv::insertElem (int e, Set &v){
	// elem in questo caso è l'indice -> pongo il valore a 1 = elem presente

	//while(e > v.maxsize) // Capienza non sufficiente
		//addSize(v);
	
	v.elem[e] = 1;
	return v;
}

/* cancella un elem dal set */
Set bitv::deleteElem (int e, Set &v){
	// elem in questo caso è l'indice -> pongo il valore a 0 = elem assente
	v.elem[e] = 0;
	return v;
} 

/* unione di due set */
Set bitv::setUnion (const Set &v, const Set &w){

	// Nel caso uno dei due insiemi sia vuoto, restituisco l'altro
	if (isEmpty(v))
		return w;
	if (isEmpty(w))
		return v;
	
	Set z;
	z.maxsize = v.maxsize; // Si assume che i due bit vector abbiano dim uguali
	z.elem = new Elem[z.maxsize];
	
	// Processo di unione
	for (int i=0; i<z.maxsize; ++i)
		if (v.elem[i] || w.elem[i])
			z.elem[i] = 1;
	return z;
} 

/* intersezione di due set */
Set bitv::setIntersection (const Set &v, const Set &w){
	Set z;
	
	// Nel caso uno dei due insiemi sia vuoto, restituisco insieme vuoto
	if (isEmpty(v) || isEmpty(w)){
		emptySet(z);
		return z;
	}

	
	z.maxsize = v.maxsize;
	z.elem = new Elem[z.maxsize];
	
	// Processo di intersezione
	for (int i=0; i<z.maxsize; ++i)
		if (v.elem[i] && w.elem[i])
			z.elem[i] = 1;
	return z;
}

/* controlla se un set è vuoto */
bool bitv::isEmpty (const Set &v){
	return size(v) == 0;
}

/* restituisce il numero di elementi presenti nel set */
unsigned int bitv::size (const Set &v){
	unsigned int size = 0;
	for (int i=0; i<v.maxsize; ++i)
		if (v.elem[i]) size++;
	return size;
}

/* verifica se un elemento è presente nel set */
bool bitv::member (int e, Set &v){
	return (e < v.maxsize && e >= 0 && v.elem[e]);
}

/* stampa il set */
void bitv::printSet(const Set &v){
	cout << "Elem:\t";
	for(int i=0; i<v.maxsize; ++i)
		cout << i << "\t";
	cout << endl;
	cout << "Is in:\t";
	for(int i=0; i<v.maxsize; ++i)
		cout << v.elem[i] << "\t";
	cout << endl;
}

