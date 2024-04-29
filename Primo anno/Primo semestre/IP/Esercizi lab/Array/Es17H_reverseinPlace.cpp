/* Es_17 avanzato: reverseinPlace Scrivere un programma che esegue lo stesso compito di reverse, ovvero legge un array di float e inverte
l’ordine dei valori contenuti, ma questa volta senza usare un altro array come spazio di lavoro.
[SUGGERIMENTO: Basta fare swap fra le celle poste alla stessa distanza dagli estremi dell’array.]
*/

#include <iostream>

using namespace std;

int main()
{
	// Popolo l'array
	const int N = 10;       //N.B Per dimensioni dispari, il numero centrale non viene scambiato.
							// Per dimensioni pari il numero centrale viene scambiato con se stesso (stessa posizione centrale). In entrambi i casi il risultato non cambia
	float source[N];
	int val;
	for (int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << ": ";
		cin >> val;
		source[i] = val;
	}

	// Swap
	float temp = 0.0;
	for (int i=0; i<N/2; i++)   //Eseguo uno swap solo su metà dei componenti (l'altra metà è già stata scambiata), altrimenti ripristino i valori nelle posizioni precedenti
	{
		temp = source[i];
		source[i] = source[N-1-i];
		source[N-1-i] = temp;
	}


	for (int i=0; i<N; i++)
	{
		cout << source[i] << endl;
	}

}
