#include <iostream>
#include <cmath>
#include <string>

#ifndef HEAP_H
#define HEAP_H


namespace heap{ 


// Dichiarazione struttura heap binario (mediante array dinamico)

typedef std::string Elem;
typedef int Key;

const Elem emptyElem = "";
const Key emptyKey = -1;
const int BLOCKDIM = 10;

struct Coppia{
	Elem elem;
	Key key;
};

struct heapBin{
	Coppia* nodo;
	int size;
	int maxsize;
}; 

// Dichiarazioni funzioni

heapBin createEmpty();
Elem findMax(const heapBin&);
bool insertElem(heapBin&, Elem, Key);
bool deleteMax(heapBin&);
void print(const heapBin&);


};

#endif // HEAP_H
