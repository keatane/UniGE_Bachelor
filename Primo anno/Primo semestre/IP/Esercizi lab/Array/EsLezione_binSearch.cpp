/* bin_search.cpp


Ricerca di un elemento all'interno di una sequenza in modo efficiente nel caso la sequenza sia ordinata	

INPUT 
- sequenza di interi ordinati in modo crescente
- elemento intero	

ALGORITMO 
- ricerca binaria (binary search)

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
	
	cout << "Inserisci " << DIM << " elementi interi crescente\n"; //Posso cambiare la DIM ma l'array rimane statico, in quanto la DIM è fissata durante la compilazione
															// Utilizzo una precondizione, ovvero che la sequenza sia crescente (posso comunque ordinarlo con dei cicli).
	for (unsigned int i=0; i<DIM; ++i)		//Pongo unsigned int nel caso in cui la DIM fosse molto grande (è una formalità per numeri piccoli, che non possono essere negativi)
		cin >> S[i];
	cout << "Inserisci un elemento da cercare\n";
	cin >> elem;
	
	// RICERCA BINARIA (divisione dicotomica)
	// Divido l'input in maniera da eliminare velocemente lo spazio di ricerca, arrivando più velocemente all'elemento cercato.
	// Ad ogni passo vado a tagliare la mia sequenza con una verifica che decide che strada prendere durante la ricerca.
	
	/*
		ES 1 2 3 4 5 6 7 8 9 10
		elem = 3
		
		1 2 3 4 		5 		6 7 8 9 10 // Divido a metà
					il 5 diventa la guida per l'analisi
				Tutti i numeri a sx sono <5 mentre a dx ho > 5
		1 				2		3 4
						3		4  // e mi accorgo che elem = 3
	*/
	// Indici della nostra sequenza
	int first = 0;
	int last = DIM-1; // Ultimo indice possibile
	int mid = (first+last)/2;	// Automaticamente esegue un'approssimazione, senza dover gestire casi particolari
	bool trovato = false;
	
	while (first<=last && !trovato) //Se raggiungo entrambi gli estremi uguali e se non vi trovo l'elemento, significa che l'elemento non è nella sequenza.
	{
		mid = (first+last)/2;
		if (S[mid]==elem)
			trovato = true;
		else 
			if (S[mid] < elem) 	//Allora se l'elemento che cerco esiste, elem sarà dopo mid (a destra)
				first = mid+1;	// Cambio l'estremo sinistro dell'intervallo
			else
				if (S[mid] > elem)	//Allora se l'elemento che cerco esiste, elem sarà prima di mid (a sinistra)
					last = mid-1;	// Cambio l'estremo destro dell'intervallo
									// NON sono necessarie le graffe (if else viene considerato un costrutto unico)
	
	
	// OUTPUT
	if (trovato)	
		cout << "Ho trovato l'elemento " << elem << endl;
	else
		cout << "Non ho trovato l'elemento " << elem << endl;
	
}