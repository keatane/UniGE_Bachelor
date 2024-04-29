/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo il tipo di dato Stack (Pila) implementato con
// strutture collegate semplicemente mediante puntatori e tipo base 'Elem' dotato di ordinamento.

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
/**************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

   Sviluppare le seguenti funzioni C/C++:

   1) isEmpty() e make_empty() che fanno parte del tipo di dato stack (vedere la specifica testuale nel namespace)
      
   2) stack_intersection() la cui definizione e' data sotto forma di commento direttamente sopra alla definizione della funzione
   
*/
    
#include <iostream>

using namespace std;

/************************************************************************/
/*      STACK con strutture collegate semplicemente mediante puntatori  */
/************************************************************************/

namespace stack {
   typedef int Elem;
   struct cell;
   typedef cell *Stack;
   const Stack EMPTYSTACK = nullptr;
   const int EMPTYELEM = -1000000;

   bool isEmpty(const Stack&);      /* Verifica se lo stack e' vuoto. Restituisce true se lo stack e' vuoto, false altrimenti */ 
   void push(const Elem, Stack&);	/* Aggiunge elem in cima allo stack (operazione safe, si puo' sempre fare) */
   Elem pop(Stack&);	            /* Toglie dallo stack l'ultimo elemento e lo restituisce; se lo stack e' vuoto la condizione e' di errore. Lo segnaliamo restituendo EMPTYELEM */
   Elem top(Stack&);	            /* Restituisce l'ultimo elemento dello stack senza toglierlo; se lo stack e' vuoto la condizione e' di errore. Lo segnaliamo restituendo EMPTYELEM */
   void make_empty(Stack&);         /* Svuota la pila (cioe` cancella tutti gli elemti presenti */
}

using namespace stack;

struct stack::cell {
    Elem	elem;
    cell	*next;
};

/****************************************************************/
// IMPLEMENTAZIONE del tipo di dato Stack
/****************************************************************/
bool stack::isEmpty(const Stack& s) {
    return false; // ISTRUZIONE AGGIUNTA AI SOLI FINI DELLA COMPILAZIONE
}

/****************************************************************/
void stack::push(const Elem x, Stack& s) {
    cell *aux = new cell; 
    aux->elem=x;
    aux->next=s;
    s = aux;
}

/****************************************************************/
Elem stack::pop(Stack& s){
    if (isEmpty(s)) return EMPTYELEM;
    cell* cur=s;
    s=s->next;
    Elem e = cur->elem;
    delete cur;
    return e;
}

/****************************************************************/
Elem stack::top(Stack& s) {
    if (isEmpty(s)) return EMPTYELEM;
    else return s->elem;
}

/****************************************************************/
void stack::make_empty(Stack& s) {
    return; // ISTRUZIONE AGGIUNTA AI SOLI FINI DELLA COMPILAZIONE
}

/****************************************************************/
// Funzioni che non fanno parte del tipo di dato Stack
/****************************************************************/
void print(const Stack& s) {
    cell* aux = s;
    cout << endl;
    while (aux != EMPTYSTACK) {
       cout << aux->elem << "; "; 
       aux = aux->next;
    }
   cout << endl;
}

// La funzione stack_intersection() prende in ingresso due stack s1 e s2 contenenti interi, tutti diversi tra loro 
// e ordinati in ordine non decrescente (l'elemento piu` piccolo si trova in cima allo stack) e restituisce una terza
// pila s3 che contiene tutti e soli gli elementi che compaiono sia in s1 che in s2, in modo tale che gli elementi di s3 
// risultino anch'essi tutti distinti e ordinati, questa volta, in ordine non crescente (quindi l'elemento piu` grande questa
// volta si trovera` in cima allo stack).
// Attenzione: gli stack s1 e s2 possono anche essere modificati durante l'esecuzione della funzione e l'effetto puo` perdurare
// fino alla fine dell'esecuzione del programma
//
// Ad esempio:
//  Se s1 e` lo stack che contiene i valori 2, 4, 6 dove 2 e' l'elemento in cima allo stack
//  Se s2 e` lo stack che contiene i valori 1, 2, 4 dove 1 e' l'elemento in cima allo stack
// Allora
//  s3 (che rappresenta il risultato della funzione) dovra` contenere i valori 2 e 4, dove 4 sara' l'elemento in cima allo stack
Stack stack_intersection(Stack& s1, Stack& s2) {
    return s1; // ISTRUZIONE AGGIUNTA AI SOLI FINI DELLA COMPILAZIONE
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main() {
  // Creo uno Stack 's_void' vuoto
  Stack s_void = EMPTYSTACK;
  
  // Creo uno Stack 's1' e inserisco i valori 6, 4, 2
  Stack s1 = EMPTYSTACK;
  push(6, s1); push(4, s1); push(2, s1);
  cout << "E' stato inserito il seguente Stack (2 e' l'elemento in cima allo stack):";
  print(s1); cout << endl;
  
  cout << "*** PRIME DUE FUNZIONI isEmpty() e make_empty() *** " << endl;
  if (isEmpty(s_void) && !isEmpty(s1)) cout << "TEST isEmpty() PASSATO" << endl;
  else cout << "TEST isEmpty() FALLITO" << endl;
  make_empty(s1); // Svuoto s
  if (isEmpty(s_void) && isEmpty(s1)) cout << "TEST makeEmpty() PASSATO" << endl;
  else cout << "TEST makeEmpty() FALLITO" << endl;
  cout << endl;
  
  cout << "*** TERZA FUNZIONE stack_intersection() *** " << endl;
  // Riempio di nuovo 's1' con i valori 6, 4, 2
  push(6, s1); push(4, s1); push(2, s1);
  // Creo un altro Stack 's2' e inserisco i valori 4, 2, 1
  Stack s2 = EMPTYSTACK;
  push(4, s2); push(2, s2); push(1, s2);
  Stack s3 = stack_intersection(s1, s2); // calcolo l'intersezione tra 's1' e 's2'; il risultato deve essere lo Stack che contiene due elementi con 4 in cima
  Elem e1 = pop(s3); Elem e2 = pop(s3); 
  if (e1 == 4 && e2 == 2 && isEmpty(s3)) cout << "TEST stack_intersection() PASSATO" << endl;
  else cout << "TEST stack_intersection() FALLITO" << endl;
}

