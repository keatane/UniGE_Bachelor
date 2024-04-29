#include "queue.h"
#include <iostream>

using namespace queue;


/****************************************************************/
/* 			FUNZIONI SULLE CODE 			*/
/****************************************************************/

/****************************************************************/
Queue queue::createEmpty()
{
   Queue q;
   
   q.size=0;
   q.maxsize=BLOCKDIM;
   Elem *aux = new Elem[BLOCKDIM];
   q.queue = aux;
   return q;
}


/****************************************************************/
void resize (Queue& l, bool increase)
{
	l.maxsize = (increase) ? l.maxsize+BLOCKDIM : l.maxsize-BLOCKDIM; //maxsize per il nuovo array
	Elem* aux = new Elem[l.maxsize];
	
	int smaller = min(l.size, l.maxsize); //size per il nuovo array
	
	if (l.size != 0){
	for (int i=0; i<=smaller; i++)
	{
		aux[i] = l.queue[i]; // segm fault
	}
	
	delete l.queue;
	l.queue = aux;
	l.size = smaller;
	}

	// Se sono giunto a size == 0 DOPO la dequeue, la maxsize sarà altrettanto a zero
	//cout << "Debug maxsize: " << l.maxsize << endl;
}


/****************************************************************/
void queue::enqueue(Elem e, Queue& l) // aggiunge e in coda
{
	if (l.size == l.maxsize) resize(l,true);
	l.queue[l.size++] = e;
}


/****************************************************************/
Elem queue::dequeue(Queue& l) // rimuove il primo elemento e lo restituisce
{
	if (isEmpty(l)) return EMPTYELEM;
	Elem save = l.queue[0];
	
	for (int i=0; i<l.size; ++i)
	{
		l.queue[i] = l.queue[i+1];
	}
	
	l.size--;
	
	if (l.size == l.maxsize-BLOCKDIM) resize(l,false);

	return save;
}


/****************************************************************/
Elem queue::first(Queue& l) // restituisce il primo elemento
{
	if (isEmpty(l)) return EMPTYELEM;
	return l.queue[0];
}


/****************************************************************/
bool queue::isEmpty(const Queue& l)
{
   return l.size==0;
}

void queue::printQueue(const Queue& l) // stampa la coda
{
	for(int i=0; i<l.size; i++)
		cout << l.queue[i].val << " ";
	cout << endl;
}

