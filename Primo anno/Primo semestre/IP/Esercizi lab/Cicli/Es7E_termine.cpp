// Scrivere un programma che chiede all’utente numeri interi positivi e stampa su una nuova riga tante ` | ' quanto è grande il
// numero (come le aste all’asilo), finché l’utente non vuole terminare:

#include <iostream>

using namespace std;

int main ()
{
	// dichiarare una variabile answer di tipo carattere
	/* ripetere
	- stampare la stringa "inserisci un numero intero positivo"
	- dichiarare una variabile n di tipo intero
	- leggere n
	- iterare su una variabile intera i a partire da 1 fino a n
	-- stampare
	` | '
	- stampare un ' andata a capo
	- stampare su una nuova riga la stringa
	"inserisci s o S per terminare, qualsiasi altro carattere per proseguire"
	- leggere answer
	finché answer è diverso sia da
	` s ' che da ` S '
	*/
	// stampare la stringa "ho terminato perchè hai inserito " seguita da answer
	// che cosa succede se inserisci un numero negativo e perchè?

	char answer;
	do{
	cout << "Inserisci un numero intero positivo" << endl;
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		cout << " | ";
	}
	
	cout << endl;
	cout << "Inserisci s o S per terminare, qualsiasi altro carattere per proseguire" << endl;
	cin >> answer;

	} while ((answer != 's') && (answer != 'S'));
	
	cout << "Ho terminato perchè hai inserito " << answer << endl;
	
}
