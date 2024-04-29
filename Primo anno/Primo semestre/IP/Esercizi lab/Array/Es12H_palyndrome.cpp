/* Es_12: Scrivere un programma palyndrome che legge un array a e calcola un valore di tipo bool che vale true se l’array è palindromo.
Poi stampa un messaggio che comunica il risultato all’utente.
[SUGGERIMENTO: usare il programma reverse.]
*/

#include <iostream>

using namespace std;

int main()
{
	// Dichiarare una costante intera N con valore 10
	const int N = 10;
	// Dichiarare un array a di N interi
	int source[N];
	// Iterare sulla variabile intera i a partire da 0 e fino a N escluso:
	// Dichiarare una variabile intera val
	// Stampare il messaggio composto da:
	// - la stringa "Valore n. "
	// - il valore di i
	// - il separatore ": "
	// Leggere da input un valore di val
	// Assegnare all'elemento i-esimo di a il valore di val
	int val;
	for (int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << ": ";
		cin >> val;
		source[i] = val;
	}

	int dest[N];
	for (int i=0; i<N; i++)
	{
		dest[i] = source[N-1-i];
	}

	/* Controllo:
	for (int i=0; i<N; i++)
	{
		cout << source[i] << endl;
	}
	cout << endl;
	for (int i=0; i<N; i++)
	{
		cout << dest[i] << endl;
	}
	*/

	bool palyndrome = true;
	for (int i=0; i<N; i++)
	{
		if (dest[i] != source[i])
		{
			palyndrome = false;
			break;		// Appena trovo un valore diverso interrompo il ciclo, perchè anche solo un valore diverso non mi rende palindroma la sequenza.
		}
	}

	if (palyndrome)
		cout << "L'array inserito e' palindromo" << endl;
	else
		cout << "L'array inserito NON e' palindromo" << endl;

}
