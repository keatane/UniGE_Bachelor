/* Es_3 di riscaldamento: leggiArrayInt, Leggi un array di int da tastiera. Scrivere un programma che dichiara un array v di N interi e lo “popola”
leggendo valori da input.
*/

#include <iostream>

using namespace std;

int main()
{
	// Dichiarare una costante intera N con valore 10
	const int N = 10;
	// Dichiarare un array a di N interi
	int a[N];
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
		a[i] = val;
	}
	
	/* Controllo:
	for (int i=0; i<N; i++)
	{
		cout << a[i] << endl;
	}
	*/
}

