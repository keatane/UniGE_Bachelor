// Es_9: Scrivere un programma che chiede all’utente un numero intero positivo e ne stampa il numero di cifre (in base 10). Ad
// esempio su 27458 stampa 5.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cout << "Inserisci un numero intero positivo" << endl;
	cin >> n;
	
	int n_cifre = 0, contatore = 0;
	do
	{
		n = n / 10;
		contatore++; // Il numero ha almeno una cifra
	
	} while (n >= 1); // Quando la divisione da come risultato 0 (e resto), significa che l'intero numero è diventato 0.parte decimale (ovvero il numero stesso), quindi le cifre del numero intero sono finite. Ogni divisione è una cifra.
	
	cout << "Numero cifre: " << contatore << endl;
	
}
