/*Es_7 di base: Scrivere un programma che legge N interi in un array a di int (vedi leggiArrayInt). Quindi con un opportuno messaggio di
output stampa il numero nPari dei numeri pari contenuti nell’array ed il numero nDispari di quelli dispari (nPari e nDispari sono quindi entrambi valori interi).
*/

#include <iostream>

using namespace std;

int main()
{
	const int N = 10;
	int a[N];
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

	int nPari = 0, nDispari = 0;
	for (int i=0; i<N; i++)
	{
		if (a[i]%2)
			nPari++;
		else
			nDispari++;
	}

	cout << "Quantita' numeri pari: " << nPari << endl;
	cout << "Quantita' numeri dispari: " << nDispari << endl;

}
