// Es_12 di base: Scrivere un programma che chiede all’utente un numero intero positivo n e stampa un rombo di asterischi che sulla diagonale ha 2 ∗ n + 1 caratteri.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Inserisci un numero intero positivo" << endl;
	cin >> n;
	
	// N.B un ciclo fa una riga in più, ovvero si gestisce la riga centrale.
	
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
