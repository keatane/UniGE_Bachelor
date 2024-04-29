// Es_5 di base:  Scrivere una funzione ricorsiva bool is_in(const list& l, T x) per implementare la ricerca di un elemento di tipo T in una lista semplice.

#include <iostream>

using namespace std;

typedef int T;

struct cell{
	T info;
	cell* next;
};

typedef cell* list;

bool is_in(const list& l, T x){
	if (l == nullptr) return false; // lista vuota = no x
	if (l->info == x) return true; // x trovato
	return is_in(l->next, x); // passo alla cella successiva nella lista, n.b questa azione non sovrascrive dove punta l!

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

	cout << "Inserisci l'elemento da trovare\n";
	cin >> y; // Riutilizzo la stessa variabile

	cout << "Elemento " << y << " trovato: " << boolalpha << is_in(l,y) << endl;
}
catch(...){
	cout << "error\n";
}

