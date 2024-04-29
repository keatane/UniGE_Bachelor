// Es_8 di base: Scrivere un programma reverse che legge N interi in un array source (vedi leggiArrayInt), e poi copia in un array dest gli
// elementi di source in ordine inverso. Quindi stampa source e dest (lasciando una riga vuota in mezzo per chiarezza).


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
	
	for (int i=0; i<N; i++)
	{
		cout << source[i] << endl;
	}
	cout << endl;
	for (int i=0; i<N; i++)
	{
		cout << dest[i] << endl;
	}
	
}
