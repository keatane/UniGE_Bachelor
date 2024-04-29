// numero casuale.cpp -- Fatto in lezione

// Creato da Cattaneo Kevin il 14/10/2020

/* 
	Realizziamo un programma che chiede all'utente di indovinare un numero compreso in un determinato intervallo (predefinito)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX=100;

//Posso scrivere istruzioni di debug, per capire se ci sono errori in un dato momento del programma (per lo sviluppatore).
const bool debug = true;

int main ()
{
	// Il programma genera un numero pseudo-casuale (si usano procedure non casuali per ottenere un numero casuale)
	int number;
	//number = rand(); // prende un numero nell'intervallo [0:RAND_MAX], anche numeri grandissimi
	// Così facendo, se riavvio il programma più e più volte ottengo lo stesso valore, questo perchè il programma accede sempre
	// allo stesso valore dato da rand(). Posso generare numeri diversi se richiamo la funzione più volte.
	// Per scegliere un valore fra 0 e 100 (MAX), posso limitare l'intervallo con la divisione %100.
	// Il resto ottenuto ha un oscillazione fra certi valori, ovvero fra 0 e MAX (se il resto fosse uguale a MAX o superiore il
	// numero sarebbe divisibile per MAX.
	// number = rand()%(MAX+1);
	// number = MIN è rand()/(MAX+1); Se avessi un minimo, dovrei traslare anche la fine del valore, quindi %(MAX-MIN+1)
	
	
	// Per controllare il valore che il programma pesca da rand, si usa un seme
	// Per cambiare il seme continuamente, posso far rifermento al tempo
	int seed = static_cast<int>(time(NULL));
	srand(seed);
	number = rand()%(MAX+1);
	
	if (debug) cout << number << endl; 
	
	int attempt;
	cout << "Inserisci un numero nell'intervallo [0:" << MAX << "]" << endl;
	
	do{
	//Il programma interroga l'utente "dimmi un numero"
	cin >> attempt;
	
	//Verifica se l'utente ha azzeccato il numero: if(number != attempt))
	// aiutino all'utente
	if (attempt > number)
	// Output (selezione): ci sei riuscito o no
		cout << "Il numero da indovinare è più piccolo. Riprova" << endl;
	if (attempt < number)
		cout << "Il numero da indovinare è più grande. Riprova" << endl;
	
	} while (number != attempt ); //true quando voglio rimanere dentro il ciclo
	cout << "Bravo!" << endl;

// Per trovare il numero posso usare una ricerca binaria, ovvero dividere a metà sempre l'intervallo.
}
