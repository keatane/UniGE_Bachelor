#include <iostream>
#include <stdexcept>
#include <fstream> 

#include "token.h"

using namespace std;

// Implementa QUEUE con strutture indicizzate e tipo base Elem dotato di ordinamento
 
namespace queue{

const int BLOCKDIM = 1000;
typedef token Elem;      // tipo base

typedef struct {
    Elem* queue;
    int size;
    int maxsize;
} Queue;

const Elem EMPTYELEM = {"", VUOTO};

Queue createEmpty();         /* restituisce la coda vuota */
bool isEmpty(const Queue&);
void enqueue(Elem, Queue&);  /* inserisce l'elemento "da una parte" della coda */
Elem dequeue(Queue&);        /* cancella l'elemento (se esiste) "dall'altra parte della coda" e lo restituisce; se la coda è vuota la condizione è di errore. Lo segnaliamo restituendo EMPTYELEM (potremmo in alternativa sollevare un'eccezione) */
Elem first(Queue&);          /* restituisce l'elemento in prima posizione (se esiste) senza cancellarlo; se la coda è vuota la condizione è di errore. Lo segnaliamo restituendo EMPTYELEM (potremmo in alternativa sollevare un'eccezione) */
void printQueue(const Queue&); /* stampa la coda */
}

