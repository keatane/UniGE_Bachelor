// Es_14 di base: Scrivere una funzione con un parametro n di tipo intero che stampa un rombo di asterischi che sulla diagonale ha 2 * n + 1 caratteri.
/*[SUGGERIMENTO: 1)è più facile stampare il rombo con due cicli, il primo per le righe in cui il numero di asterischi cresce
e il secondo per le righe in cui il numero di asterischi diminuisce.]
[SUGGERIMENTO: 2) usate la funzione replicate2_line]
*/

#include <iostream>

using namespace std;

void rombo (int n){

	// Prima metà
	for (int i = 0; i < n; i++)
	{
		for (int j=0; j < (2*n+1); j++)
		{
			if (j<n-i || j > n+i)
				cout << ' ';
			else
				cout <<'*';
		}
		cout << endl;
	}

	// Seconda metà
	for (int i = n; i >= 0; i--)
	{
		for (int j=0; j < (2*n+1); j++)
		{
			if (j<n-i || j > n+i)
				cout << ' ';
			else
				cout <<'*';
		}
		cout << endl;
	}
}


int main()
{
	cout << "Inserisci un numero intero" << endl;
	int num;
	cin >> num;
	cout << endl;
	rombo(num);

}
