#include "stack.h"

using namespace stack;


struct stack::cell {
    Elem	elem;
    cell	*next;
};



/****************************************************************/
bool stack::isEmpty(const Stack& s)
{
	return (s==EMPTYSTACK);
}

/****************************************************************/
Stack go_last_elem (Stack s)
{
	if (isEmpty(s)) return EMPTYSTACK;
	
	cell *aux=s;
	while (aux->next != EMPTYSTACK)
		aux=aux->next;

	return aux;	
}

/****************************************************************/
void stack::push(const Elem x, Stack& s) 
{
	cell *aux = new cell;
	aux->elem = x;
	aux->next = EMPTYSTACK;
	
    cell *last = go_last_elem(s);
    if (last == EMPTYSTACK)
    	s = aux;
    else
    	last->next = aux;
}

/****************************************************************/
Elem stack::pop(Stack& s)
{
    if (isEmpty(s)) return EMPTYELEM;
    
    cell *aux=s;
    cell *prev;
	while (aux->next != EMPTYSTACK)
	{
		prev = aux;
		aux = aux->next;
	}
	
	Elem content = aux->elem;

//controllo se la stack è composta da un singolo elemento
	if (s==aux)
		s = EMPTYSTACK;
	else
		prev->next=EMPTYSTACK;	

	delete aux;
	return content;
}


/****************************************************************/
Elem stack::top(Stack& s)
{
	cell *last=go_last_elem(s);
	
	return (last == EMPTYSTACK)? EMPTYELEM:last->elem;
}

