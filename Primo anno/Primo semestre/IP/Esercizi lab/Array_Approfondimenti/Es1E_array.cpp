// Es_1 di riscaldamento - Array, approfondimenti.


#include <iostream>

using namespace std;

const int N = 5;

struct array_str {
	int array[N];
	unsigned int size;
};



void readArray(array_str& v){
	/* iterare sul campo di tipo array di v...
	...dalla prima all'ultima posizione (indicata dal campo intero di v)
	- leggere un valore intero
	- assegnare il valore letto all'elemento corrente di v
	*/
	for (unsigned int i=0; i<v.size; ++i)
		cin >> v.array[i];
}

void printArray(const array_str& v){
	/* iterare sul campo di tipo array di v...
	...dalla prima all'ultima posizione (indicata dal campo intero di v)
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i=0; i<v.size; ++i)
		cout << v.array[i] << endl;
}

void SelectionSort(array_str& v) {

	// dichiarare una variabile int greatestIndex
	int greatestIndex;
	/* iterare sul vettore dalla prima all'ultima posizione
	- memorizzare in greatestIndex la posizione corrente (sia i)
	- *//* iterare sul vettore dalla posizione successiva alla corrente ...
	... (i+1) fino all'ultimo elemento
	-- se il valore alla pos corrente (j) e' < del valore...
	... alla pos greatestIndex
	--- memorizzare j in greatestIndex
	*//*
	- scambiare il valore alla posizione i con quello alla pos greatestIndex
	*/
	int temp;
	for (unsigned int i=0; i<v.size; ++i){
		greatestIndex = i;
		for (unsigned int j=i+1; j<v.size; ++j){
			if (v.array[j] < v.array[greatestIndex])
				greatestIndex = j;
        }

		temp = v.array[i];
		v.array[i] = v.array[greatestIndex];
		v.array[greatestIndex] = temp;
	}
}

int SequentialSearch(const array_str& v, int item) {
	// dichiarare una variabile int loc e inizializzarla a -1
	int loc = -1;
	// dichiarare una variabile bool found e inizializzarla a false
	bool found = false;
	/* iterare sul campo array di v fino a che found diventa true o ...
	... si è iterato su tutto l'array
	- se il valore alla pos corrente (i) e' uguale a item
	-- assegnare true a found e i a loc
	*/
	unsigned int i = 0;
	while(found == false && i < v.size){
		if (v.array[i] == item){
			found = true;
			loc = i;
		}
		i++;
	}
	// restituire loc
	return loc;
}

// Si tratta dell'ordinamento di dividere a metà e spostarsi fra gli intervalli.
bool BinarySearch(const array_str& v, int item ){
	
	int sx = 0, dx = v.size-1, mid = 0;
	for (int i=0; i<v.size; ++i)
	{
		mid = (sx+dx)/2;
		if (v.array[mid] == item) return true;
		if (item < v.array[mid]) dx = mid;
		else sx = mid;
	}
	
	// Se sono qui item non è stato trovato
	return false;
}



int main()
{
	// dichiarare un array_str vett
	array_str vett;
	// inizializzare il suo campo intero a N
	vett.size = N;
	// chiamare la funzione readArray su vett
	// chiamare la funzione printArray su vett
	readArray(vett);
	cout << endl;
	cout << "Array inserito: " << endl;
	printArray(vett);

	// chiamare la funzione SelectionSort su vett
	SelectionSort(vett);
	// chiamare la funzione printArray su vett
	cout << endl;
	cout << "Array ordinato: " << endl;
	printArray(vett);

	cout << endl;
	cout << "Il numero 1 si trova alla posizione: " << SequentialSearch(vett, 1) << " dell'array ordinato" << endl;
	
	cout << "-- Ricerca binaria --\n";
	cout << "Inserisci item da trovare: ";
	int item = 0;
	cin >> item;
	cout << "Oggetto trovato: " << boolalpha << BinarySearch(vett, item) << endl;


}
