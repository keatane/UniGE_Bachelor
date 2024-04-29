#include <iostream>
#include "bitv.h"

using namespace std;
using namespace bitv;

int main(){
	Set v;
	
	cout << "Creazione bit vector\n";
	v = emptySet(v);
	printSet(v);
	
	int n = 5;
	cout << "Inserimento elemento " << n << " nel bit vector\n";
	v = insertElem(n,v);
	printSet(v);
	
	cout << "Cancellazione elemento " << n << " nel bit vector\n";
	deleteElem(n,v);
	printSet(v);
	
	
	Set w, k;
	w = emptySet(w);
	w = insertElem(3,w);
	w = insertElem(4,w);
	v = insertElem(n,v);
	cout << "Unione di set \n";
	k = setUnion(v,w);
	printSet(k);
	
	//v = insertElem(4,v);
	v = deleteElem(n,v);
	cout << "Intersezione di set \n";
	k = setIntersection(v,w);
	printSet(k);
	
	cout << "Set vuoto: ";
	cout << boolalpha << isEmpty(v) << noboolalpha << endl;
	printSet(v);
	
	cout << "Numero elementi nel set: ";
	cout << size(v) << endl;
	printSet(v);
	
	cout << "Elemento " << n << " presente nel set: ";
	cout << boolalpha << member(n,v) << noboolalpha << endl;
	printSet(v);
	

}
