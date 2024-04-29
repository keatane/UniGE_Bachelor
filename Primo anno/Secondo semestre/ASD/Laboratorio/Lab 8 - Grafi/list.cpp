////////////////////////////////////////////////////
//
//  Questa serve per realizzare le liste che vengono fuori come risultato di
//  operazioni quali il percorso tra due citta' (che viene rappresentato come
//  lista di nomi di citta') e l'elenco delle citta' adiacenti a una certa
//  citta' (anch'esso rappresentato come lista di nomi di citta').
//  Non serve invece per le liste dei vertici nel grafo, ne' per le liste di
//  adiacenza di ciascun vertice.
//
////////////////////////////////////////////////////

#include "list.h"

using namespace list;

struct list::list{
	Elem info;
	list* next;
};


/****************************************************************/
void list::clear(List& l){
	if(!isEmpty(l))
	{
		clear(l->next);
		delete l;
		l=emptyList;
	}
}


/****************************************************************/
void list::set(int pos, Elem e, List& l) // "set" nel senso di "assegna un valore", non nel senso di "insieme"! E' una terminologia standard, non fate confusione con gli insiemi
{
	List aux = l;
	int i = 0;
	while(!isEmpty(aux) && i<pos)
	{
		aux = aux->next;
		i++;
	}
	if(!isEmpty(aux))
		aux->info = e;
}


/****************************************************************/
void list::add(int pos, Elem e, List& l) // aggiunge e nella posizione pos
{
	if(isEmpty(l) || pos <= 0)
	{
		addFront(e, l);
		return;
	}
	
	List n = new list;
	n->info = e;
	
	int i = 0;
	List aux = l;
	List app;
	while(!isEmpty(aux) && i<pos)
	{
		app = aux;
		aux = aux->next;
		i++;
	}
	app->next = n;
	n->next = aux;
}

/****************************************************************/
void list::addBack(Elem e, List& l) // aggiunge e in coda
{
	List n = new list;
	n->info = e;
	n->next = emptyList;
	
	if(isEmpty(l))
		l = n;
	
	List aux = l;
	List prev = aux;
	while(!isEmpty(aux))
	{
		prev = aux;
		aux = aux->next;
	}
	prev->next = n;
}


/****************************************************************/
void list::addFront(Elem e, List& l) // aggiunge e in coda
{
	List n = new list;
	n->info = e;
	n->next = l;
	l = n;
}

/****************************************************************/
void list::removePos(int pos, List& l)
{
	if(pos <= 0)
	{
		List aux = l;
		l = l->next;
		delete aux;
		return;
	}
	int i = 0;
	List aux = l;
	List prev = aux;
	while(!isEmpty(aux) && i<pos)
	{
		prev = aux;
		aux = aux->next;
		i++;
	}
	//se la lista ha un elemento in posizione pos
	if(!isEmpty(aux))
	{
		prev->next = aux->next;
		delete aux;
	}
}


List list::createEmpty()
{
	return emptyList;
}

/****************************************************************/
Elem list::get(int pos, const List& l)
{
	List aux = l;
	int i=0;
	while(!isEmpty(aux) && i<pos)
	{
		aux = aux->next;
		i++;
	}
	
	if(isEmpty(aux))
		return emptyElem;
	return aux->info;
}


/****************************************************************/
bool list::isEmpty(const List& l)
{
   return (l==emptyList);
}

/****************************************************************/
int list::size(const List& l)
{
	if(isEmpty(l))
		return 0;
	return 1+size(l->next);
}


/****************************************************************/
void printList(const List& l)
{
	if(isEmpty(l))
	{
		cout << "[ ]" << endl;
		return;
	}
	cout << "[";
	List aux = l;
	while(!isEmpty(aux->next))
	{
		cout << aux->info << ", ";
		aux = aux->next;
	}
	cout << aux->info << "]" << endl;
}
