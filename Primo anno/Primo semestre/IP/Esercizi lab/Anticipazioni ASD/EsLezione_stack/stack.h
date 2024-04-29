// stack.h

#ifndef stack_h
#define stack_h

typedef int Elem;

struct cell{
	Elem head;
	cell* next;
};

typedef cell* stack;

void create_empty(stack&);
void push(stack&, Elem);
void pop(stack&); // se volessi togliere e restituire l'elemento: Elem pop(stack&);
Elem top(const stack&); // accede in sola lettura all'elemento in cima alla pila, restituendo il contenuto (non la "cella")

bool isEmpty(const stack&);
#endif // stack_h