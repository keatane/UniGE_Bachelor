// Es_3 base: Scrivere un programma che legge un numero intero e ne stampa il valore assoluto (ovvero il numero senza segno, ad esempiose leggo−7 devo stampare 7).

#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci un numero intero" << endl;
	int n;
	cin >> n;
	
	// Metodo veloce (no IF) cout << "Il valore assoluto del numero inserito e': " << abs(n) << endl;

	cout << "Il valore assoluto e': " << endl;
	if (n < 0)
		cout << -n << endl; //Stampo l'opposto (di un numero ne cambio il segno)
	else 
		cout << n << endl;

}


