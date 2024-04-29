// Es_18 di base: Scrivere una funzione con un argomento intero n che stampa la scomposizione in fattori primi di n. Ad esempio su 392
// stampa "392 = 2^3 * 7^2", usando il carattere `^' per rappresentare l’elevamento a potenza.


#include <iostream>

using namespace std;

void scomposizione(int n){

	int val = n;
	bool primo = true;
	int fattore = 2; // Parto dal fattore 2 per scomporre i numeri (vedi dopo)
	int potenza = 0;

	cout << n << " = ";

	while (val > 1 && fattore <= val && fattore != n)
	{
		if (val % fattore == 0)
		{
			if (!primo)	// Queste due righe si verificano al secondo ciclo
				cout << " * ";
			primo = false;
			while (val % fattore == 0)
			{
				potenza++;
				val /= fattore;
			}
			cout << fattore << "^" << potenza;
			potenza = 0; // Riporto l'esponente a zero
		}

		if (fattore == 2)
			fattore = 3; // Proseguo con il secondo numero primo
		else
			fattore += 2; // Così da scomporre per i numeri dispari (primi)
	}

	if (primo)
		cout << "primo";
	cout << endl;
}

int main ()
{
	int num;
	cout << "Inserisci un numero positivo\n";
	cin >> num;
	scomposizione(num);
}
