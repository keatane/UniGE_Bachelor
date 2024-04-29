// Es_14 avanzato: Scrivere un programma che legge un array di int e stampa il secondo valore piú elevato.

#include <iostream>
#include <limits>

using namespace std;

const unsigned int N = 10;

int main ()
{
	int a[N];
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

	// Cerco il secondo valore più elevato (posso farlo in un solo for)
	int nMaxSec = INT_MIN;
	for (int i=0; i<N; i++)
	{
		if (a[i] >nMaxSec && a[i]<nMax)
			nMaxSec = a[i];
	}

	//Controllo:
	//cout << "Nmax: " << nMax << " NmaxSec: " << nMaxSec << endl;

	cout << "Secondo valore piu' elevato: " << nMaxSec << endl;

}
