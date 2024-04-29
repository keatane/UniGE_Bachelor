#include "string_ord_list.h"

// Es in lezione: Liste semplici

#include <iostream>
#include <string>

using namespace std;

struct cell_str{
	Elem content; // contenuto della cella
	cell * next; // puntatore alla cella successiva (eventualmente nullptr se non esiste cella successiva)
};

void read(list& l){

	string input;
	cout << "Inserisci una stringa o premi n per terminare l'inserimento\n";
	cin >> input;

	while (input != "n"){

		insertInOrder(l, input);		
		
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
/*
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
*/

void deleteAt(list &l, int index){

	list cur = l;
	
	list prev = nullptr;
	
	int count = 0;
	
	while(cur != nullptr && count < index){ // Mi fermo a un certo indice (cur è in pos idx) o vado fino in fondo
		prev = cur;	
		cur = cur->next;
		count++;
	}
	if (cur!=nullptr){
		if (cur == l)
			l = l->next;
		else
			prev -> next = cur -> next;
			delete cur;
	}
				

}

void deleteOnce(list &l, std::string s){

	list cur = l;
	
	list prev = nullptr;
	
	while(cur != nullptr && cur->content != s){ 
		// Scorro finchè non trovo l'elemento (nella cella cur) o finisco la lista
		prev = cur;	
		cur = cur->next;
	
	}
	if (cur!=nullptr){
		if (cur == l)
			l = l->next;
		else
			prev -> next = cur -> next;
			delete cur;
	}
				

}

void deleteAll(list &l, std::string s){

	bool noMoreElem = false;
	
	list cur = l;
	
	list prev = nullptr;
	
	while (!noMoreElem){
		cur = l;
		while(cur != nullptr && cur->content != s){ 
			// Scorro finchè non trovo l'elemento (nella cella cur) o finisco la lista
			prev = cur;	
			cur = cur->next;
		}
		if (cur!=nullptr){
			if (cur == l)
				l = l->next;
			else
				prev -> next = cur -> next;
				delete cur;
		}
		else
			noMoreElem = true; // perchè cur ha raggiunto il fondo della lista senza trovare elementi da cancellare
	}
}


// funzione parziale (non gestisce tutti i casi, si deve gestire l'eccezione) che accede all'elemento in posizione idx nella lista e lo restituisce (accesso all'elemento IN LETTURA)

std::string getElem(const list &l, int idx){
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

bool are_equal(ordList l1, ordList l2){
	bool found = false;
	while (l1 != nullptr){
		while(l2 != nullptr){
			if (l1->content == l2->content){
				found = true;
				break;
			}
			l2 = l2->next; // Proseguo con la prossima cella in l2
		}
		if (!found)
			return false;
		else
			found = false; 
		l1 = l1->next; // Proseguo con la prossima cella in l1
	}
	return true;
}

ordList concat (ordList l1, ordList l2){

	// Concatenazione
	ordList Lcat = nullptr;
	// ordList lCopy = l2;
	while (l1 != nullptr){
		insertInOrder(Lcat, l1->content);
		l1 = l1->next;
	}
	while (l2 != nullptr){
		insertInOrder(Lcat, l2->content);
		l2 = l2->next;
	}
	
	//Restituzione della somma delle occorrenze comuni
	int somma = 0;
	l1 = Lcat;
	l2 = Lcat->next;
	string prevContent = "";

	while (l1 != nullptr){
		while(l2 != nullptr && l1->content <= l2->content){ // Essendo lista ordinata mi fermo prima se trovo una lettera alfabetica successiva
			if (l1->content == l2->content){
				somma += l2->content;
			}
			l2 = l2->next;
		}
		if (l1->content != prevContent) // Essendo lista ordinata l'elemento doppio capita successivamente
			std::cout << "L'oggetto " << l1->content << " e' comparso " << somma << " volte nella lista concatenata\n";
		
		prevContent = l1->content;
		l1 = l1->next; // Proseguo con la prossima cella in lCopy
		if (l1 != nullptr)
			l2 = l1->next; // Ripristino alla cella dopo lCopy
		somma = 0;

	}
	return Lcat;
}
	
	
ordList unione(ordList l1, ordList l2){
	
	//int N = 0;
	// Concatenazione
	ordList Lcat = nullptr;
	// ordList lCopy = l2;
	while (l1 != nullptr){
		insertInOrder(Lcat, l1->content);
		l1 = l1->next;
		//N++;
	}
	while (l2 != nullptr){
		insertInOrder(Lcat, l2->content);
		l2 = l2->next;
		//N++;
	}
	
	ordList unionList = nullptr;
	std::string temp="";
	
	while (Lcat != nullptr){
		if (Lcat->content != temp) // Poichè la lista concatenata è ordinata, gli elementi uguali sono consecutivi
			insertInOrder(unionList, Lcat->content); // Finchè l'elemento attuale non è diverso dal successivo quello attuale non viene inserito nella nuova lista
		temp = Lcat->content;
		Lcat = Lcat->next;
	}
	
	return unionList;
}

ordList intersect(ordList l1, ordList l2){

	ordList Lcat = nullptr; 
	ordList lCopy = l2;
	while (l1 != nullptr){
		while(lCopy != nullptr){
			if (l1->content == lCopy->content){
					insertInOrder(Lcat, lCopy->content);
				}
			lCopy = lCopy->next; // Proseguo con la prossima cella in l2
		}			 
		l1 = l1->next; // Proseguo con la prossima cella in l1
		lCopy = l2;
	}
	
	ordList intersectList = nullptr;
	std::string temp="";
	
	while (Lcat != nullptr){
		if (Lcat->content != temp)
			insertInOrder(intersectList, Lcat->content);
		temp = Lcat->content;
		Lcat = Lcat->next;
	}
	
	return intersectList;
}

