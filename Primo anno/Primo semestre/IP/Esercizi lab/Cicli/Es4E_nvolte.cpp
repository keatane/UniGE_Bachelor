// Scrivere un programma che legge un numero intero n strettamente positivo ed un carattere, e stampa il carattere n volte:

#include <iostream>

using namespace std;

int main ()
{
	// stampare la stringa "Inserisci un numero maggiore di 0: "
	// dichiarare una variabile len di tipo int
	// leggere len
	// se len non e ` maggiore di zero
	// - stampare "Avevo detto positivo!"
	// - uscire dal programma ritornando codice di errore 1
	// stampare la stringa "Inserisci il carattere da replicare: "
	// dichiarare una variabile c di tipo char
	// leggere c
	/* iterare su i a partire da 1 e fino a len
	- stampare c
	*/

	cout << "Inserisci un numero maggiore di 0:\n";
	int len;
	cin >> len;
	
	if (len < 0)
		{
			cout << "Avevo detto positivo!\n";
			return 1;
		}
		
	cout << "Inserisci il carattere da replicare:\n";
	char c;
	cin >> c;
	
	for (int i=0; i < len; ++i)
	{
		cout << c;
	}
	cout << endl;
}
