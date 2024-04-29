#include "set.h"
#include <iostream>


struct cell{

	Base_Type head;
	cell *next;
};

void create_empty_set(Set &s){
	s = nullptr;
}

// scegliamo un'implementazione basata su inserimenti ordinato, solo per rendere
// più efficiente l'operazione (evito di visitare tutto l'insieme per osservare se ho un elemento ripetuto,
// ma si interrompe se nell'ordinamento crescente trovo un elemento già più grande di quello inserito
// il termine sicuramente non sarà oltre).

// per gli insiemi il mantenimento degli elementi in ordine non sarebbe necessario
void insert_in_set(Base_Type x, Set &s){
	// Creo una nuova cella
	cell *aux = new cell;
	aux->head = x;
	
	Set cur = s; 
	Set prev = s;
	
	while((cur != nullptr) && (cur->head < x)){ // esco appena cur punta a un elemento che contiene x o quando giungo in fondo
		prev = cur;
		cur = cur->next;
	}
	if ((cur != nullptr) && (cur->head == x))
		return; // senza ripetizioni (ho già x nell'insieme)
	// altrimenti inserisco x
	aux->next = cur;
	if (cur==s) // inserimento in testa
		s = aux;
	else
		prev->next = aux;
	
}
void empty_set(Set &s){ // svuota la lista
	Set temp = s;
	while (s!=nullptr){
		s = s->next;
		delete temp;
		temp = s;
	}
}

void print_set(const Set&s){
	Set sCopy = s;
	std::cout << "Set: ";
	while(sCopy!=nullptr){
		std::cout<< sCopy->head << " // ";
		sCopy = sCopy->next;
	}
	std::cout << std::endl;
}

bool is_in_set(Base_Type x, const Set &s){
	Set temp=s;
	while (temp!=nullptr){
		if (temp->head == x) return true;
		temp = temp->next;
	}
	// non ho trovato l'elemento
	return false;
}


// funzioni binarie
// Attenzione l'insieme risultante deve rispettare tutte le proprietà degli insiemi 
// (in particolare no ripetizioni)

Set union_set(const Set &s1, const Set &s2){
	Set s_union;
	create_empty_set(s_union);
	Set temp = s1;
	while(temp!=nullptr){
		insert_in_set(temp->head,s_union);
		temp = temp->next;
	}
	temp = s2;
	while(temp!=nullptr){
		insert_in_set(temp->head,s_union);
		temp = temp->next;
	}
	return s_union;
}

Set inters_set(const Set &s1, const Set &s2){
	Set s_int;
	create_empty_set(s_int);
	Set temp = s1;
	while(temp!=nullptr){
		if (is_in_set(temp->head,s2)) // se l'elemento è anche in s2 (temp ha stessi contenuti di s1)
			insert_in_set(temp->head, s_int);
		temp = temp -> next;
	}
	return s_int;
}

bool is_empty_set(const Set &s){
	return s==nullptr;
}

