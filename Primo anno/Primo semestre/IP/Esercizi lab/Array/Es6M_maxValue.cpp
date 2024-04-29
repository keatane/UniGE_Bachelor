/* Es_6 di base: Scrivere un programma che legge N interi in un array a di int (vedi leggiArrayInt). Quindi stampa il valore massimo
contenuto nell’array a e il numero di volte in cui questo appare.
*/

#include <iostream>
#include <limits>

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

	// Cerco il valore max
	int nMax = INT_MIN;
	for (int i=0; i<N; i++)
	{
		if (a[i] > nMax)
			nMax = a[i];
	}

	// Conto quante volte compare il valore massimo
	int how_many_max = 0;
	for (int i=0; i<N; i++)
	{
		if (a[i] == nMax)
			how_many_max++;
	}

	// cout << "Il valore massimo e' " << nMax << " e compare " << how_many_max << " volte " << endl;
	
	

	/* Posso integrare il controllo e la conta all'interno di un ciclo for:
	nMax = INT_MIN;
	how_many_max = 0;
	for (int i=0; i<N; i++)
	{
		if (a[i] > nMax)
			{
			    nMax = a[i];
                how_many_max = 1; // Resetto la conta di uno stesso valore se trovo un nuovo valore
            }
		else if (a[i] == nMax)		// La prima volta viene eseguito appena viene cambiato valore, infatti quando a[i] > nMax, allora nMax avrà stesso valore di a[i] e viene contato
			how_many_max ++;	// come presente una volta.
	}

	cout << "Il valore massimo e' " << nMax << " e compare " << how_many_max << " volte " << endl; 
	*/
}
