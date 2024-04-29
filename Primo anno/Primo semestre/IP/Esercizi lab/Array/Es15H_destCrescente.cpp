// Es_15 avanzato: Scrivere un programma che legge un array di int source e scrive in un altro array dest il contenuto dell’array source ordinato
// in modo crescente. Poi stampa dest.


#include <iostream>

using namespace std;

const unsigned int N = 5;

int main()
{
	// Popolo l'array 'source'
	int source[N];
	int val;
	for (unsigned int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << ": ";
		cin >> val;
		source[i] = val;
	}

	// SELECTION SORT - Ordino 'source'
	int smallest;
	int temp = 0;
	for (unsigned int i=0; i<N;  ++i){	// Visita esterna della sequenza
		smallest = i;
		for (unsigned int mini = i+1; mini < N; ++mini)		// min (i)
			if (source[smallest] > source[mini])
				smallest = mini;			// Controllo dei valori, cerco il minimo valore (e ne registro l'indice)

		// Dopodichè ho uno swap di due variabili, ovvero fra il valore corrente e il minimo (valori in date posizioni indice). N.B. Nel SELECTION SORT Le righe di swap sono fuori dal for interno.
		// Vado a sostituire nel valore attuale a[i] il minimo trovato a[smallest], e riparto col ciclo.
		temp = source[smallest];
		source[smallest] = source[i];
		source[i] = temp;
	}



	// Popolo l'array 'dest'
	int dest[N];
	for (unsigned int i=0; i<N; i++)
	{
		dest[i] = source[i];
	}

	cout << endl;
	cout << "Array 'dest' ordinato in modo crescente rispetto a 'source': " << endl;
	for (unsigned int i=0; i<N; i++)
	{
		cout << dest[i] << endl;
	}

}
