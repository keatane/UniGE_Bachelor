// Es_7 di base: Scrivere una funzione ricorsiva bool rec_insertElemInOrder(const list& l, T x) che dati una lista ordinata l senza ripetizioni di elementi di tipo T inserisce il nuovo elemento x nella posizione giusta. La funzione restituisce true se l’operazione
// è andata a buon fine, false altrimenti.

#include <iostream>

using namespace std;

typedef int T;

struct cell{
	T info;
	cell* next;
};

typedef cell* list;

// Inserimento senza ripetizione
bool rec_insertElemInOrder(list& l, T x){
	if (l == nullptr || l->info > x){ // o inserisco l'elemento in fondo o inserisco l'elemento subito prima del suo maggiore
		cell* aux = new cell;
		aux->info = x;
		aux->next = l;
		l = aux;
		return true;
	}
	else if (l->info == x)
		return false; // L'elemento è già inserito, non lo re inserisco!
	else
		return rec_insertElemInOrder(l->next, x);

}

void print(const list& l){ // Posso anche passarlo per riferimento (evito copie)
	list lCopy = l;
	cout << "Lista: " << endl;
	while(lCopy != nullptr){ // Alla fine il puntatore punta a nullptr
		cout << "Elemento: " << lCopy->info << endl; // Stampo il contenuto
		lCopy = lCopy -> next; // Faccio puntare all'elemento successivo (ovvero punto al nuovo puntatore), così facendo il puntatore stesso si aggiorna col puntatore successivo
	}
}

int main()
try{

	list l = nullptr;
	T y;

	rec_insertElemInOrder(l,1);
	rec_insertElemInOrder(l,2);
	rec_insertElemInOrder(l,3);
	print(l);

	cout << "Inserisci l'elemento da inserire\n";
	cin >> y;

	cout << "Elemento " << y << " inserito: " << boolalpha << rec_insertElemInOrder(l,y) << endl;

	print(l);
}
catch(...){
	cout << "error\n";
}

