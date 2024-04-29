#ifndef QUEUE
#define QUEUE

#include <string>

struct Persona{
	std::string name;
	std::string surname;
	int birth;
};

struct cell{
	Persona content;
	cell* next;
};

struct queue{
	cell* head;
	cell* tail;
};

void leggiLista(std::string, queue&);
int eta(cell*);
void create_empty(queue&);
void enqueue(queue&, Persona&);
void dequeue(queue&);
void print(queue&);
void sort(queue&);

#endif 
