// Es_4 di riscaldamento: Scrivere un programma che legge N valori reali, li memorizza in un array di lunghezza N, e ne stampa la media

#include <iostream>

using namespace std;

int main()
{

		// copiare qui il codice del programma ``leggiArrayFloat''

			// Dichiarare una costante intera N con valore 10
			const int N = 10;
			// Dichiarare un array a di N interi
			float a[N];
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

	// dichiarare una variabile sum di tipo float e inizializzarla a zero
	float sum = 0.0;
	/* iterare su i a partire da 0 e fino a N-1
	- sommare il contenuto dell'i-esimo elemento di a a sum
	*/

	for (int i=0; i < N; ++i)		// Posso anche eseguirla in un solo for, ma anche per una questione di riutilizzo (fra diversi programmi) tengo i due pezzi separati
		sum += a[i];

	// stampare la divisione di sum per N
	cout << "Media valori inseriti: " << sum/N << endl;

}
