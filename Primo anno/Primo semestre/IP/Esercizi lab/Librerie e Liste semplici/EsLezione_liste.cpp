// Es in lezione: Liste semplici

#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef int Elem; // tipo base della lista

struct cell{
	Elem info; // contenuto della cella
	cell * next; // puntatore alla cella successiva (eventualmente nullptr se non esiste cella successiva)
};

typedef cell* list; // diamo un nome più evocativo allla nostra lista semplice


// effettua inserimento in testa di un elemento in una lista
void head_insert(Elem x, list &l){
	cell *aux = new cell; // non collegato a l (lista)
	aux -> info = x; // equivalente a aux.info = x;
	aux -> next = l; // punta ai contenuti di lista (conservo ancora il contenuto di aux in info)
	l = aux; // viene inserito l'elemento, puntando la lista ad aux (che a sua volta punta alle celle precedenti di lista), in questo momento aux è la prima cella davanti alle altre precedenti di lista
}

// cancella elemento in testa alla lista

// Partenza: l -> [X| ] --> [Y|nullptr] (ultimo elemento)
// Si vuole cancellare l'elemento [X| ], tenendo in memoria il fatto che esso è l'unico collegamento per [Y|nullptr]

void head_delete(Elem x, list &l){
	cell *aux = l->next; // ovvero [Y|nullptr]
	delete l; // libera lo spazio di memoria heap puntato da l (ovvero [X| ])
	l = aux;
}

int main()
{
	list L1 = nullptr;
	head_insert(3,L1);
	
	// In questo momento L1 -> [3 | ???], ma finchè non visito quella parte della lista, ??? non da problemi (??? punta a qualcosa di non noto ma comunque presente fra i nostri dati!). Diverso se inizializzo la lista a vuoto (nullptr)
	// Dopodichè diviene L1 -> [3 | nullptr]
}
