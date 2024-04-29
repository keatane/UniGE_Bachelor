// stack.cpp

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

void create_empty(stack& s){
	s = nullptr;
}

bool is_empty(const stack& s){
	return (s==nullptr);
}

void push(stack& s, Elem e){ // equivale a un inserimento in testa (cima della pila, ovvero ultimo elemento inserito)
	cell* aux = new cell;
	aux->head = e;
	aux->next = s;
	s = aux;
}
void pop(stack& s){
	if (isEmpty(s)){
		// SOLLEVO ECCEZIONE
		string str="top: empty stack";
		throw str;
	}
	//else{
	cell* temp = s; // salvo la prima cella puntata da s
	s = s->next;
	delete temp;
}

Elem top(const stack& s){
	if (isEmpty(s)){
		// SOLLEVO ECCEZIONE
		string s="pop: empty stack";
		throw s;
	}
	// al di là di eccezioni la funzione restituisce sempre un valore
	return (s->head);
}

