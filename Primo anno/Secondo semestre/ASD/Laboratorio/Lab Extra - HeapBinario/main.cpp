#include "heap.h"

using namespace std;
using namespace heap;

int main(){
	
	heap::heapBin hb = createEmpty();
	
	// inserimento
	
	insertElem(hb, "Pietro", 114);
	insertElem(hb, "Kevin", 22);
	insertElem(hb, "Roberto", 23);
	insertElem(hb, "Gianluca", 62);
	insertElem(hb, "Antonio", 212);
	insertElem(hb, "Sara", 44);
	
	// stampa
	cout << "---- Stampa heap binario ----" << endl;
	print(hb);
	
	// findMax 
	cout << "\nMassimo: " << findMax(hb) << endl;
	
	// cancellazione
	deleteMax(hb);
	
	// stampa
	cout << endl;
	cout << "---- Stampa heap binario ----" << endl;
	print(hb);
	cout << "\nMassimo: " << findMax(hb) << endl;
}
