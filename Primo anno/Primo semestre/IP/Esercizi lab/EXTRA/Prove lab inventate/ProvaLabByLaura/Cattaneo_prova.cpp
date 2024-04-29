#include <iostream>
#include <fstream>
#include <iomanip>
#include "queue.h"

using namespace std;

// Definizione funzioni

bool readPeople(ifstream &f, Persona& p){
	
	f>>p.name;
	f>>p.surname;
	f>>p.birth;
	
	return f.good();
}

void leggiLista(std::string nomeFile, queue& q){
	std::ifstream f;
	f.open(nomeFile);
	
	Persona aux;
	if (f.is_open()){
		while(readPeople(f,aux))
			enqueue(q, aux);
	}
	
	f.close();
}

//Restituire età di una data persona
int eta(Persona p){
	if (2021-p.birth <= 0)
		throw string("la persona non e' ancora nata");
	return (2021-p.birth);
}

// Crea queue vuota

void create_empty(queue& q){
	q.head = nullptr;
	q.tail = nullptr;
}

void enqueue(queue& q, Persona& p){
	cell* aux = new cell;
	aux->content.name = p.name;
	aux->content.surname = p.surname;
	aux->content.birth = p.birth;
	aux->next = nullptr;
	
	if (q.head == nullptr){
		q.head = aux;
		q.tail = aux;
	}
	else{
		q.tail->next = aux;
		q.tail = aux;
	}
}

void dequeue(queue& q){
	cell* aux = q.head->next;
	delete q.head;
	q.head = aux;
}

void print(queue& q){
	cell* temp = q.head;
	while (temp != nullptr){
		cout << temp->content.name << setw(10) << "\t";
		cout << temp->content.surname << setw(10) << "\t";
		cout << temp->content.birth << "\n";
		temp = temp->next;
	}
}

void sort(queue& q){
	for (cell* i = q.head; i != nullptr; i = i->next){
		cell* idx = i;
		for (cell* j = i->next; j != nullptr; j = j->next)
			if (eta(j->content) < eta(idx->content))
				idx = j;
		// Non scambio le celle, ma i loro contenuti (le struct)
		Persona temp = i->content;
		i->content = idx->content;
		idx->content = temp;
	}
}
