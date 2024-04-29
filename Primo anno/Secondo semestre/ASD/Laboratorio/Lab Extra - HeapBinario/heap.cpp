#include "heap.h"

using namespace std;
using namespace heap;

// ----- Dichiarazioni funzioni Heap Binario ----- 

// Creazione heapBinario vuoto
heap::heapBin heap::createEmpty(){
	heapBin hb;
	hb.maxsize = BLOCKDIM;
	hb.nodo = new Coppia[hb.maxsize+1]; // l'array comincia dalla posizione 1
	hb.size = 0;
	
	// Azzero tutte le celle
	for(int i=1; i<hb.maxsize+1; ++i){
		hb.nodo[i].key = emptyKey;
		hb.nodo[i].elem = emptyElem;
	}
	return hb;
}

// Stampa dell'array
void heap::print(const heapBin& hb){
	for(int i=1; i<hb.size+1; ++i){
		cout << "Chiave: " << hb.nodo[i].key << "\t";
		cout << "Elemento: " << hb.nodo[i].elem << endl;
	}
}

// Ritorna l'elemento con priorità più alta, che per definizione sta in cima
Elem heap::findMax(const heapBin& hb){
	if(hb.nodo[1].key != emptyKey) return (hb.nodo[1].elem);
	return emptyElem;
}

// Inserimento elemento in modo ordinato di priorità (priorità padre > priorità figli)
bool heap::insertElem(heapBin& hb, Elem e, Key k){
	
	if(e == emptyElem || k <= emptyKey) return false; // no chiavi negative
	if(hb.size > hb.maxsize) return false;
	
	// Creazione nodo
	Coppia newNodo;
	newNodo.elem = e;
	newNodo.key = k;
	
	hb.size++;
	
	hb.nodo[hb.size] = newNodo; // elementi contenuti: size elementi
	int i = hb.size; // indice di newNodo
	while(i != 1 && newNodo.key > hb.nodo[i/2].key){
		Coppia temp = hb.nodo[i]; // nota bene, non fare riferimento a newNodo perchè modifica una copia
		hb.nodo[i] = hb.nodo[i/2];
		hb.nodo[i/2] = temp;
		i = i/2; // aggiorno l'indice attuale di newNode
	}
	
	return true;
}

// Rimozione elemento con maggiore priorità
bool heap::deleteMax(heapBin& hb){
	if(hb.size > hb.maxsize) return false;
	
	// !! Nota il valore massimo per definzione è nella radice (elemento 1 nell'array)
	
	// Azzero il valore massimo
	hb.nodo[1].key = emptyKey;
	hb.nodo[1].elem = emptyElem;
			
	Coppia temp = hb.nodo[1]; // radice
	hb.nodo[1] = hb.nodo[hb.size];
	hb.nodo[hb.size] = temp;
	hb.size--;
	
	int i = 1;
	while(true){
		int maxIndex = emptyKey;
		
		if(i > hb.size || i <= 0) break;
		if(hb.nodo[2*i].key == emptyKey && hb.nodo[2*i+1].key == emptyKey) break;
		
		// Cerco il figlio maggiore
		if(hb.nodo[2*i].key >= hb.nodo[2*i+1].key)
			maxIndex = 2*i;
		else maxIndex = 2*i+1;
		
		// DEBUG cout << "Maxindex: " << maxIndex << endl;
		if(maxIndex <= 0 || maxIndex > hb.size) break; // Se l'indice va fuori range significa che non ho figli da quelle parti, mi fermo
		
		if(hb.nodo[maxIndex].key < hb.nodo[i].key) break; // se il più grande dei figli non supera il padre allora non effettuo alcuno scambio
			
		if(maxIndex != emptyKey){
			Coppia temp = hb.nodo[i]; // radice
			hb.nodo[i] = hb.nodo[maxIndex];
			hb.nodo[maxIndex] = temp;
			i = maxIndex;
			continue; // passa di un ciclo avanti (ciclo finchè ho figli che rispettano la una delle due condizioni iniziali	
		}
		break;
	}

	return true;
}
