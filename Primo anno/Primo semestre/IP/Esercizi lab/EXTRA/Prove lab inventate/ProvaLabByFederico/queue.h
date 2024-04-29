#ifndef QUEUE
#define QUEUE

#include <string>

struct data{
	int anno;
	int mese;
	int giorno;
};

struct Auto{
	std::string casa;
	std::string modello;
	data dataArrivo;
};

struct cell{
	Auto content;
	cell* next;
};

struct queue{
	cell* head;
	cell* tail;
};

typedef queue concessionaria;

void crea_concessionaria(concessionaria&);
bool empty(concessionaria&);
void enqueue(concessionaria&, Auto);
Auto dequeue(concessionaria&);
void read_concessionaria(concessionaria&);
void print(const concessionaria&);
bool is_in(concessionaria&, Auto);
int check_old(concessionaria&, data);
Auto sold(concessionaria&, Auto);
void transfer_auto(concessionaria&, concessionaria&, Auto);
void transfer_last_auto(concessionaria&, concessionaria&, int);
void transfer_old_auto(concessionaria&, concessionaria&, data);
void sort(concessionaria&); 





#endif
