/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche 
//                mediante pile e code
//
// vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"
#include "queue.h"
#include "stack.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

using namespace stack;
using namespace queue;

/////////////////////////////////////////////////////////////////////
// Funzioni principali: leggi() e calcola()
/////////////////////////////////////////////////////////////////////

void trim(string& s){
	s.erase(0, s.find_first_not_of(" \t"));
	s.erase(s.find_last_not_of(" \t") + 1);
}

// Estrae uno dopo l'altro i token dalla stringa "str", inserendoli via via nella coda "codaToken"
// Nota bene, l'interfaccia di questa funzione è stata modificata rispetto all'originale
bool leggi(string &str, Queue &codaToken) {
	token t;
	while(prossimoToken(str, t)) //scorro token e aggiungo in coda
		enqueue(t, codaToken);
	//quando esco dal while controllo se token sconosciuto (prossimoToken interrotto) o stringa finita (true)
	return (t.k != SCONOSCIUTO);
}

// Estrae uno dopo l'altro i token dalla coda, inserendoli via via sullo stack.
// Appena si incontra un token PARENTESI CHIUSA, quello segnala la fine
// di una sottoespressione; allora tiriamo giu' dallo stack gli ultimi cinque token inseriti.
// I token estratti dovrebbero essere esattamente, nell'ordine:
// un ")", un numero, un operatore aritmetico, un altro
// numero, e un "("; se non è così, allora si segnala
// errore sintattico e l'algoritmo termina.
// A questo punto la funzione deve convertire i token di tipo NUMERO in numeri interi, 
// eseguire l'operazione aritmetica opportuna, e trasformare il risultato da numero a
// token e inserire quest'ultimo sullo stack.
// Alla fine se non ci sono errori sintattici la funzione deve mettere nella variabile
// risultato il valore dell'espressione

bool calcola(Queue codaToken, int &risultato) {
	token t;
	Stack s = EMPTYSTACK;
	int a, b, op;
	
	while(!isEmpty(codaToken))
	{
		while((t = dequeue(codaToken)).k != PARENTESI_CHIUSA)
		{
			if(t.k==VUOTO) return false;
			push(t, s);
		}
		// La PARENTESI_CHIUSA non è nello stack
		
		t = pop(s);
		
		if(t.k != NUMERO)
			return false;	
		a = str2int(t.val); // operando destro
		
		t = pop(s);
		op = t.k;
	
		t = pop(s);
		if(t.k != NUMERO)
			return false;
		b = str2int(t.val); // operando sinistro
		
		switch(op)
		{
			case OP_SOMMA : risultato=b+a; break;
			case OP_SOTTRAZIONE : risultato=b-a; break;
			case OP_MOLTIPLICAZIONE : risultato=b*a; break;
			default : return false;
		}
		
		t.val = int2str(risultato);
		t.k = NUMERO;
		
		if (top(s).k == PARENTESI_APERTA)
			pop(s); // tolgo la parentesi ( aperta rimasta
		else 
			return false; // Dopo un calcolo deve rimanere la parentesi aperta, qualsiasi altra cosa trovo si traduce in un errore sintattico, ad esempio ( - 2 + 3), perchè - è staccato da 2
		
		// Inserimento risultato nello stack	
		push(t, s); 
		
		// === Debug - print result === 
		//std::cout << top(s).val << std::endl;
	}
	
	return true;
}

/////////////////////////////////////////////////////////////////////
//                               MAIN
/////////////////////////////////////////////////////////////////////

int main() {

  string s;
  queue::Queue q = queue::createEmpty();
  int r;

  cout << "Inserisci l'espressione che vuoi valutare:" << endl;
  cout << "Nel caso si volessero inserire valori negativi, "
  "si ponga il segno meno vicino al numero negativo" << endl;
  getline(cin,s);

  if (!leggi(s,q)) {
    cout << "errore lessicale\n";
    exit(1);
  }
  
  //printQueue(q); // === Debug === : stampa queue

  if (!calcola(q,r)) {
    cout << "errore sintattico\n";
    exit(1);
  }

  cout << "risultato: " << r << "\n";
  exit(0);

}
