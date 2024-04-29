// Es_16 avanzato: Scrivere un programma che legge un array di int, riordina i suoi elementi in modo crescente, e poi lo stampa.

#include <iostream>

using namespace std;

const unsigned int N = 10;

int main()
{
	int a[N];
	int val;
	for (int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << ": ";
		cin >> val;
		a[i] = val;
	}

	// SELECTION SORT
	int smallest;
	int temp = 0;
	for (unsigned int i=0; i<N;  ++i){	// Visita esterna della sequenza
		smallest = i;
		for (unsigned int mini = i+1; mini < N; ++mini)		// min (i)
			if (a[smallest] > a[mini])
				smallest = mini;			// Controllo dei valori, cerco il minimo valore (e ne registro l'indice)

		// Dopodichè ho uno swap di due variabili, ovvero fra il valore corrente e il minimo. N.B. Nel SELECTION SORT Le righe di swap sono fuori dal for interno.
		// Vado a sostituire nel valore attuale a[i] il minimo trovato a[smallest], e riparto col ciclo.
		temp = a[smallest];
		a[smallest] = a[i];
		a[i] = temp;
	}

	/* // BUBBLE SORT
	int temp;
	for (unsigned int i=0; i<N-1;  ++i){
		for (unsigned int j= 0; j < N-1; ++j)
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	}*/

	cout << endl;
	cout << "Array ordinato in modo crescente: " << endl;
	for (int i=0; i<N; i++)
	{
		cout << a[i] << endl;
	}

}
