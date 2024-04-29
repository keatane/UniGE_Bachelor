/* Es_3 di riscaldamento: Implementare le funzioni necessarie a leggere e stampare un array dinamico di interi, ovvero un array la cui dimensione
viene fissata al momento dell’esecuzione (invece che della dichiarazione). Per rappresentare gli array dinamici di interi
utilizzeremo il seguente tipo:
*/

#include <iostream>

using namespace std;

struct dynamic_array {
int* store;
unsigned int size;
};

void read_d_array(dynamic_array& d) {
	// definire una variabile intera s a un valore negativo
	int s = -1;
	/* finché s non è strettamente positiva....
	// stampare "Inserisci la dimensione del vettore" e andare a capo
	// leggere s
	*/
	while (s <= 0){
		cout << "Inserisci la dimensione del vettore\n";
		cin >> s;
	}

	// assegnare s al campo size di d
	d.size = s;
	// allocare s interi assegnando l'area di memoria riservata al campo store di d
	d.store = new int[s]; // n.b. NO d-> store, perchè non voglio accedere al contenuto ma alla memoria
	for (unsigned int i=0; i<s; ++i)
		d.store[i];
	/* iterare s volte....
	// stampare "inserisci un valore"
	// leggere un valore nell'i-esimo elemento del campo store di d...
	// ...usando la notazione con le quadre per accedervi
	*/
	for (unsigned int i=0; i<s; ++i){
		cout << "Inserisci un valore:";
		cin >> d.store[i];
	}
}

void print_d_array(const dynamic_array& d) {
	// definire un puntatore p e inizializzarlo con il campo array di d
	int* p = d.store;
	int length = d.size;
	// usando l'aritmetica dei puntatori su p per visitare il campo store di d...
	// ...stampare gli elementi del campo store di d, ...
	// ...ciascuno seguito dal carattere '\t'
	// stampare una andata a capo
	for (unsigned int i=0; i<length; ++i){
		cout << *(p+i) << "\t";
	}
	cout << endl;

}


int main()
{
    dynamic_array a;
    read_d_array(a);
	print_d_array(a);
}
