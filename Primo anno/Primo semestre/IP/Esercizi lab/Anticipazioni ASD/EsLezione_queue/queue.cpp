// stack.cpp

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

bool isEmpty(const queue& q){
	// se la lista è vuota entrambi i puntatori sono nullptr, altrimenti sono entrambi occupati, quindi basta controllare un puntatore
	return (q.tail == nullptr);
}

void create_empty(queue& q){
	q.head = nullptr;
	q.tail = nullptr;
}

void enqueue(queue& q, Elem e){ // inserimento in coda
	cell* aux = new cell;
	aux->content = e;
	aux->next = nullptr;
	
	if (isEmpty(q)){
		q.head = aux;
		q.tail = aux;
	}
	else {// inserisco in fondo
		q.tail->next = aux; // cella attualmente in coda, faccio puntare al prossimo elemento
		q.tail = aux; // la coda quindi ora punta al nuovo ultimo elemento
	}
}

void dequeue(queue& q){ // estrazione di elemento dalla testa
	if (isEmpty(q)){
		string str = "dequeue: empty queue";
		throw str;
	}
	cell* temp = q.head;
	q.head = q.head->next;
	delete temp;
	
	// Se avevo solo un elemento (head = tail), l'eliminazione di head influenza tail, quindi gestisco
	if (q.head == nullptr) q.tail = nullptr;
}

Elem front(const queue&){ // elemento in prima posizione nella coda
	if (isEmpty(q)){
		string str = "dequeue: empty queue";
		throw str;
	}
	return q.head->content;
}

Elem back(const queue&){ // elemento in fondo alla coda
	if (isEmpty(q)){
		string str = "dequeue: empty queue";
		throw str;
	}
	return q.tail->content;
}


