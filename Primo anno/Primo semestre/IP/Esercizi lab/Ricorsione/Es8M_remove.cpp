// Es_8 di base: Scrivere una funzione ricosiva bool rec_removeElemInOrder(const list& l, T x) che dati una lista ordinata l senza ripetizioni di elementi di tipo T elimina l’elemento x dalla listaa. La funzione restituisce true se l’operazione è andata a buon fine,
// false altrimenti.


#include <iostream>

using namespace std;

typedef int T;

struct cell{
	T info;
	cell* next;
};

typedef cell* list;

bool rec_removeElemInOrder(list& l, T x){

	if (l == nullptr || l->info > x){
		return false; // valore x non trovato (non eliminabile)
	}
	else if (l->info == x){
		cell* aux = l;
		l = l->next;
		delete aux;
		return true;
    }
	else
		return rec_removeElemInOrder(l->next, x);

}

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

void print(const list l){ // Posso anche passarlo per riferimento (evito copie)
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

	cout << "Inserisci l'elemento da rimuovere\n";
	cin >> y;

	cout << "Elemento " << y << " rimosso: " << boolalpha << rec_removeElemInOrder(l,y) << endl;

	print(l);
}
catch(...){
	cout << "error\n";
}

