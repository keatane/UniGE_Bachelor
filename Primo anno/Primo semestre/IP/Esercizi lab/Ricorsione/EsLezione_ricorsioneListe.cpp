//Esercizio in lezione: ricorsione su liste

#include <iostream>
#include "liste.h"

using namespace std;

void insert_elem_aux(cell* aux, lista& current, lista& prev){
	// sono arrivato nel punto giusto, posso fare l'inserimento (QUESTA E' LA BASE)
	if (current == nullptr || current->head > aux->head)
	{
		aux->next = current;
		prev->next = aux;
		return;
	}
	return insert_elem_aux(aux, current->next, prev->next);
}


void insert_elem(Elem x, lista &l){
	cell *aux = new cell;
	aux -> head = x;
	aux -> next = nullptr;
	
	if (l==nullptr || l->head > x){ 
		// inserimento in testa
		aux->next = l;
		l = aux;
		return;
	}	
	else insert_elem_aux (aux, l->next, l) // funzione ausiliaria, con puntatori curr e p
	
}


int main()
{
	

}