/* op_sequenze.cpp


Ricerca di un elemento all'interno di una sequenza

INPUT 
una sequenza di int
un elemento dello stesso tipo

ALGORITMO
- sequenziale: per qualunque sequenza input

OUTPUT
	trovato o non trovato
	eventualmente specificando dove
	*/

#include <iostream>

using namespace std;

const unsigned int DIM = 10;

int main()
{
	// INPUT
	int S[DIM];
	int elem;
	
	cout << "Inserisci " << DIM << " elementi interi\n"; //Posso cambiare la DIM ma l'array rimane statico, in quanto la DIM è fissata durante la compilazione
	for (unsigned int i=0; i<DIM; ++i)		//Pongo unsigned int nel caso in cui la DIM fosse molto grande (è una formalità per numeri piccoli, che non possono essere negativi)
		cin >> S[i];
	cout << "Inserisci un elemento da cercare\n";
	cin >> elem;
	
	
	// RICERCA
	bool trovato = false;
	for (unsigned int i=0; i<DIM; ++i)
		if (S[i] == elem)
			trovato = true;		//Non sono necessarie le graffe per singole istruzioni (anche se successive)
		
	/* Alternativa 1, una volta trovato l'elemento fermo la ricerca
	for (unsigned int i=0; i<DIM; ++i)
		if (S[i] == elem)
		{	
			trovato = true;
			break;
		}
	*/
	
	/* Alternativa 2, con un while che si ferma quando trovo l'elemento (o arrivare in fondo se non trovo l'elemento)
	unsigned int i = 0;
	while (!trovato && i<DIM) {		//Continua il ciclo quando trovato == false
		
		if (S[i] == elem)
			trovato = true;
		++i;						//Corrisponde al numero di passi effettuati
	}
	*/
	
	/* Alternativa 3, uguale alla 2 ma registro la posizione
	unsigned int i = 0;
	int pos = -1; // Stato di errore di default, in modo tale che non esce con una posizione lecita dell'array (che non è corretta)
	while (!trovato && i<DIM) {		//Continua il ciclo quando trovato == false
		
		if (S[i] == elem)
		{	
			trovato = true;
			pos = i;			//Ma ancora una volta pos non è necessario, in quanto i conserva la posizione dell'elemento nell'array, stando attenti che dopo viene incrementato.
								// Dunque la posizione sarebbe i-1
		}
		++i;						//Corrisponde al numero di passi effettuati
	}
	*/
	
	// OUTPUT
	if (trovato)	
		cout << "Ho trovato l'elemento " << elem << endl;
	else
		cout << "Non ho trovato l'elemento " << elem << endl;
	
}