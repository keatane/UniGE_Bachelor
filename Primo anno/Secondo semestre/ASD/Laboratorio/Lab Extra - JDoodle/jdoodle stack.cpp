/*******************************/
/* PROVA DI LABORATORIO DI ASD */
/*******************************/

// Descrizione:
// In questo laboratorio si considera il tipo di dato STACK visto a lezione implementato con la struttura dati lista di puntatori

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

/***************************/
/* Stack.h
/***************************/
namespace stack {

   // Gli elementi dello STACK sono interi
   typedef int Elem;
   struct cell;
   typedef cell *Stack;
   const Stack EMPTYSTACK = NULL;
   const Elem EMPTYELEM = -1000000;

   bool isEmpty(const Stack&);
   void push(const Elem, Stack&);	/* aggiunge elem in cima (operazione safe, si puo' sempre fare) */
   Elem pop(Stack&);	           /* toglie dallo stack l'ultimo elemento e lo restituisce; se lo stack e' vuoto 
                                      viene sollevata un'eccezione) */
}
using namespace stack;

/***************************/
/* Stack.cpp
/***************************/
struct stack::cell {
    Elem	elem;
    cell	*next;
};

/****************************************************************/
bool stack::isEmpty(const Stack& s) {
    return (s==EMPTYSTACK);
}

/****************************************************************/
void stack::push(const Elem x, Stack& s) {
    cell *aux = new cell; 
    aux->elem=x;
    aux->next=s;
    s = aux;
}

/****************************************************************/
stack::Elem stack::pop(Stack& s) {
    if (isEmpty(s)) return EMPTYELEM;
    cell* cur=s;
    s=s->next;
    Elem e = cur->elem;
    delete cur;
    return e;
}

/****************************************************************/
/* DESCRIZIONE FUNZIONE DA IMPLEMENTARE
/* Sviluppare una funzione C/C++ chiamata sumStack che prende in input uno Stack ed usando le operazioni offerte 
/* dal tipo di dato Stack somma i numeri positivi trovati (e scarta i negativi) svuotando lo Stack e mette il 
/* risultato ottenuto sullo Stack richiamando push (che era stato in precedenza svuotato)
/*
/* ESEMPIO
/* (prima della chiamata della funzione SumStack) Stack = 4, -1, 2, 0, -10
/* (dopo della chiamata della funzione SumStack) Stack = 6 */

stack::Elem sumStack(stack::Stack& s) {
    int sum = 0;
    Elem auxS;
    for(auxS = pop(s); auxS != EMPTYELEM; auxS = pop(s))
        if(auxS > 0)
            sum += auxS;
    push(sum, s);
    return sum;
    
}


/***************************/
/* Main.cpp
/***************************/
using namespace stack;

int main() {
  int prova;
  Stack myStack = EMPTYSTACK; 
  
  push(4, myStack); push(-1, myStack); push(2, myStack); push(0, myStack); push(-10, myStack);
      
  if (sumStack(myStack) == 6) {
     if (isEmpty(myStack))
       cout << "TEST FALLITO" << endl;
     else {
       pop(myStack);  
       if (isEmpty(myStack))
         cout << "TEST PASSATO" << endl;
       else
         cout << "TEST FALLITO"<< endl;
     }
  }
  else
     cout << "TEST FALLITO"<< endl;
  
  return 0;
}