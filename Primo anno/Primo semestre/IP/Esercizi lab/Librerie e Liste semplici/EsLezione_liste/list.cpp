// Es in lezione: Liste semplici e librerie

#include <iostream>
#include <string>

using namespace std;

struct cell{
	Elem content; // contenuto della cella
	cell * next; // puntatore alla cella successiva (eventualmente nullptr se non esiste cella successiva)
};

void headInsert(list& l, std::string s){
	cell* aux = new cell;			// creo la nuova cella da inserire
	aux -> content = s;	// Aggiorno il contenuto
	aux -> next = l; // punta al primo elemento della lista

	l = aux; // guardo al nuovo primo elemento della lista
}

void read(list& l){

	string input;
	cout << "Inserisci una stringa o premi n per terminare l'inserimento\n";
	cin >> input;

	while (input != "n"){

		headInsert(l,input);
		cout << "Inserisci una stringa o premi n per terminare l'inserimento\n";
		cin >> input;
	}
}


void print(const list l){ // Posso anche passarlo per riferimento (evito copie)
	list lCopy = l;
	cout << "Lista: " << endl;
	while(lCopy != nullptr){ // Alla fine il puntatore punta a nullptr
		cout << "Elemento: " << lCopy->content << endl; // Stampo il contenuto
		lCopy = lCopy -> next; // Faccio puntare all'elemento successivo (ovvero punto al nuovo puntatore), così facendo il puntatore stesso si aggiorna col puntatore successivo
	}
}

void tailInsert(list &l, string x){

    cell* aux = new cell;	// creo la nuova cella da inserire
	aux -> content = x;	// Aggiorno il contenuto
	aux -> next = nullptr; // il successivo non esiste (aux è l'ultimo)

	cell* tail = l; // "Cerco la coda", COPIA di puntatori (tail punta alle stesse celle di lista)
    while(tail->next != nullptr){ // Mi fermo al 'penultimo' valore ovvero all'elemento il cui successivo (l'ultimo) è vuoto
		tail = tail -> next; // aggiorno il valore di tail, ovvero modifico facendo puntare a un altro puntatore
	}
	tail->next = aux; // infine aggiorno il valore a cui punta tail (che si ripercuote su l)

}

void deleteAll(list &l){

    // free(l); cancellerebbe solo la testa
	while(l != nullptr){
        list currentHead = l;
		l = currentHead-> next; // aggiorno la testa con il valore successivo al corrente, dopodichè posso cancellare l'elemento corrente
		delete currentHead;
	}

}


// funzione parziale (non gestisce tutti i casi, si deve gestire l'eccezione) che accede all'elemento in posizione idx nella lista e lo restituisce (accesso all'elemento IN LETTURA)

string get(const list &l, int idx){
	list lCopy = l; // faccio guardare la stessa sequenza di l a lCopy (lista ausiliaria)
	int cont = 0; // contatore
	
	while((lCopy != nullptr) && (cont < idx)){ // con solo (lCopy != nullptr) farei una visita completa, mentre mi interessa fermarmi (eventualmente) a una certa posizione (cont == idx)
												// N.B. non rischio di andare fuori memoria, perchè se idx va oltre le celle della lista, l'ultima cella sarà nullptr (vuota)
		lCopy = lCopy->next; // punto alla cella successiva
		cont++;
	}
	
	if ((cont == idx) && (lCopy != nullptr)) // sono arrivato all'indice di mio interesse (n.b ovviamente escludo dalla stampa l'ultimo elemento vuoto della lista, nel caso idx fosse uguale alla posizione della cella nullptr)
		return lCopy -> content;
	else{
		string err = "Out of list error";
		throw err;
	}
	
	// return "error"; // E' sbagliato! Potrebbe esserci una stringa chiamata error nella lista
}	

// funzione che inserisce un elemento in una lista in maniera ordinata
// versione con ordinamento CRESCENTE

// PRECONDIZIONE ("do per scontato"): la lista data in input è ordinata
// POSTCONDIZIONE: la lista modificata con elemento in più è ancora ordinata

void insertInOrder(list &l, string x){
	list aux = new cell;
	aux->content = x;
	
	list cur = l;
	list prev;
	
	while((cur!=nullptr) && (cur->content<=x)){
		prev = cur;
		cur = cur->next;
	}
	
	aux->next = cur; //se sono arrivato in fondo, cur sarà nullptr
	if (cur == l) // sono rimasto in testa
		l = aux;
	else
		prev->next = aux;
	
}
