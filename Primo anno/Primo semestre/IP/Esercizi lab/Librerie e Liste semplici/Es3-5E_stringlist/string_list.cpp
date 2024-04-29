#include "string_list.h"
#include <iostream>

const std::string ELEMENT_NOT_FOUND = "ELEMENT NOT FOUND";

struct cell_impl{ // Definisco la struct

	std::string info;
	cell* next = nullptr; // Nel caso si faccia riferimento all'ultimo elemento	
};

void headInsert(list& l, std::string s){
	
	cell* new_cell = new cell;
	
	new_cell -> info = s;
	new_cell -> next = l;
	
	l = new_cell;
}

void read(list& l){

	std::string s = "";
	std::cout << "Inserisci righe: ";
	
	while(s != "exit"){
	
		std::cin >> s;
		headInsert(l,s);
	}

}

void print(const list& l){

	cell* cur = l;
	
	while (cur != nullptr){
		
		std::cout << cur -> info << " ";
		cur = cur -> next;
	
	}
	
	std::cout << std::endl;

}

std::string getElem(const list l, int index){

	cell* cur = l;
	int i = 0;
	
	while (cur != nullptr){
	
		if(i == index)
			return cur -> info;
			
		i++;
		cur = cur -> next;
		
		}
	// Se l'index è fuori dalla mia lista
	throw ELEMENT_NOT_FOUND;
}


void deleteAt(list& l, int index){

	cell* cur = l;
	cell* prev = nullptr;
	
	int i=0;
	
	while(cur != nullptr && i!=index){
		i++;
		prev = cur;
		cur = cur -> next;
	}
	
	if (cur != nullptr){
	
		if(cur == l)
			l = l->next; // Tolgo il primo elemento
		else
			prev -> next = cur -> next;
	}
	
	throw ELEMENT_NOT_FOUND;
	
}

void insertAt(list& l, int index){

	cell* new_cell = new cell;
	new_cell -> info = "nuova roba";
	new_cell -> next = nullptr;
	
	cell* cur = l;
	cell* prev = nullptr;
	
	int i=0;
	
	while(cur != nullptr && i!=index){
		i++;
		prev = cur;
		cur = cur -> next;
	}
	
	if (cur != nullptr){
	
		if(cur == l){ // Siamo nel primo elemento
			new_cell -> next = l;
			l = new_cell;
		}
		else {// non siamo nel primo elemento
			new_cell -> next = cur;
			prev -> next = new_cell;
		}
	}
	
	throw ELEMENT_NOT_FOUND;
	
}

void deleteOnce (list& l){

	deleteAt(l,0);
}

void deleteAll(list& l, std::string s){

	cell * cur = l;
	
	cell* prev = nullptr;
	
	while(cur != nullptr){
		if (cur -> info == s){
			if (cur == l)
				l = l->next;
			else
				prev -> next = cur -> next; // "Salto" una cella, così da eliminarla (memory leak)
		}
		
		prev = cur; // Tolgo una posizione dalla lista
		cur = cur -> next;
	
	}
}

