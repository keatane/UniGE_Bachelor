/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 2) */
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

   1) stack_size() che fa parte del tipo di dato stack (vedere la specifica testuale nel namespace)
      
   2) stack_union() la cui definizione e' data sotto forma di commento direttamente sopra alla definizione della funzione
   
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
   int stack_size(const Stack&);    /* Restituisce il numero di elementi nello stack */
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
    while (!isEmpty(s))
        pop(s);
}

/****************************************************************/
int stack::stack_size(const Stack& s) {
    return 0; // ISTRUZIONE INSERITA AI SOLI FINI DELLA COMPILAZIONE
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

// La funzione stack_union() prende in ingresso due stack s1 e s2 contenenti interi, tutti diversi tra loro
// e ordinati in ordine non decrescente (l'elemento piu` piccolo si trova in cima allo stack) e restituisce una terza
// pila s3 che contiene tutti gli elementi che compaiono in s1 o in s2, in modo tale che gli elementi di s3
// risultino anch'essi tutti distinti (senza ripetizioni) e ordinati questa volta in ordine non crescente.
// Attenzione: gli stack s1 e s2 possono anche essere modificati durante l'esecuzione della funzione e l'effetto puo` perdurare
// fino alla fine dell'esecuzione del programma
//
// Ad esempio:
//  Se s1 e` lo stack che contiene i valori 2, 4, 6 dove 2 e' l'elemento in cima allo stack
//  Se s2 e` lo stack che contiene i valori 1, 2, 4 dove 1 e' l'elemento in cima allo stack
// Allora
//  s3 (che rappresenta il risultato della funzione) dovra` contenere i valori 6, 4, 2, 1
Stack stack_union(Stack& s1, Stack& s2) {
    Stack s_union = EMPTYSTACK;
    return s_union; // ISTRUZIONE INSERITA AI SOLI FINI DELLA COMPILAZIONE
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
  
  cout << "*** PRIMA FUNZIONE stack_size() *** " << endl;
  if(stack_size(s1) == 3 && stack_size(s_void)==0) cout << "TEST stack_size() PASSATO" << endl;
  else cout << "TEST stack_size() FALLITO" << endl;
  cout << endl;
  
  cout << "*** SECONDA FUNZIONE stack_union() *** " << endl;
  // Creo un altro Stack 's2' e inserisco i valori 4, 2, 1
  Stack s2 = EMPTYSTACK;
  push(4, s2); push(2, s2); push(1, s2);
  if(stack_union(s_void, s_void) != EMPTYSTACK) cout << "PRIMO TEST su stack_union FALLITO" << endl;
  else cout << "PRIMO TEST su stack_union PASSATO" << endl;  
  
  Stack s3 = stack_union(s1, s2); // calcolo l'unione tra 's1' e 's2'
  cout << "SECONDO TEST su stack_union: la funzione e` corretta se le due stampe sono uguali:" << endl;
  cout << "Output della vostra funzione: ";
  print(s3);
  cout << "Output corretto: " << endl;
  cout << "6; 4; 2; 1;" << endl;

}

