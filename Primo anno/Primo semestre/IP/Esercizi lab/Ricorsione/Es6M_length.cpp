// Es_6 di base: Scrivere una funzione ricorsiva int length(const list& l) che calcola la lunghezza di una lista.

#include <iostream>

using namespace std;

typedef int T;

struct cell{
	T info;
	cell* next;
};

typedef cell* list;

/* Prima versione
int count = 0;  // contatore elementi = lunghezza lista
int length(const list& l){
	if (l == 0) return count; // base, sono in testa o in coda, comunque restituisco il valore di count a cui si è arrivati (escluso nullptr)
	count++; // se non sono giunto alla coda, conto un elemento in più
	return length(l->next);
}
*/

int length(const list& l){
	if (l == nullptr) return 0; // base
	return length(l->next) + 1; // passo alla cella successiva e si ferma arrivato al fondo (ho +1 ad ogni chiamata)
}

int main()
try{

	list l = nullptr;
	cout << "Riempi la lista di numeri interi, interrompi con -1: " << endl;
	T y;
	cin >> y;
	while(y != -1){
		// Inserimento in testa alla lista
		cell* aux = new cell;
		aux->info = y;
		aux->next = l;
		l = aux;

		cin >> y;
	}

	cout << "Lunghezza lista: " << length(l) << endl;
}
catch(...){
	cout << "error\n";
}

