/* Es_13 avanzato:  Scrivere un programma che legge un array di int e stampa la frequenza di ogni valore contenuto (il numero di volte che
compare).
[SUGGERIMENTO: conviene avere un array di contatori (int) lungo tanto quanto l’array di ingresso (al massimo un valore può presentarsi tante volte quanto la lunghezza dell'array principale)]
*/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
	const int N = 10;
	int a[N];

	//Popolo l'array
	for (int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << " : ";
		cin >> a[i];
	}

	//Controllo la frequenza
	int freq[N] = {};
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (a[j] == a[i])	//Ogni numero è confrontato con gli altri e se stesso (se stesso conta come frequente una volta)
				freq[i]++; //Incremento la frequenza del numero in posizione i-esima
		}
	}
    cout << endl;

	for (int i=0; i<N; i++)
	{
		cout << "Frequenza numero " << a[i] << " : " << freq[i];
        if (freq[i] != 1) //Semplice controllo lessicale
            cout << " volte" << endl;
        else
            cout << " volta" << endl;
	}

}
