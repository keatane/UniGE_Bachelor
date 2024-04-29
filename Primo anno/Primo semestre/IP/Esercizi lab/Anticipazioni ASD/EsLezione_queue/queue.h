// queue.h

#ifndef queue_h
#define queue_h

typedef int Elem;

struct cell{
	Elem content;
	cell* next;
};

// Definisco queue
/*
	indirizzi:	indA			indB				indZ

	HEAP: 		[31|indB] -> [31|indC] -> ... -> [3|nullptr]
	
	nello STACK di memoria: 
		q[indA|indZ]
*/

// Registro l'indirizzo della prima cella e l'indirizzo dell'ultima
struct queue{
	cell* head;
	cell* tail;
};

void create_empty(queue&);
void enqueue(queue&, Elem); // inserimento in coda
void dequeue(queue&); // estrazione di elemento dalla testa (il primo inserito)
Elem front(const queue&); 
Elem back(const queue&);

bool isEmpty(const queue&);

#endif // queue_h