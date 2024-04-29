/* Scrivere un programma che legge un certo numero di valori reali e ne stampa la media (notare che lo schema seguente fissa
una serie di dettagli ulteriori non specificati nel “testo” dell’esercizio):
*/

#include <iostream>

using namespace std;

int main ()
{
	// stampare la stringa "Di quanti numeri vuoi fare la media?"
	cout << "Di quanti numeri vuoi fare la media?" << endl;
	// dichiarare una variabile how_many di tipo int
	int how_many;
	// leggere how_many
	cin >> how_many;
	// se how_many non è strettamente positivo
	if (how_many <= 0)
		{
	// - stampare "Errore: il numero doveva essere positivo"
		cout << "Errore - il numero doveva essere positivo" << endl;
	// - uscire dal main ritornando il codice di errore 42
		return 42; }
	// dichiarare una variabile sum di tipo float inizializzata a 0
	float sum = 0;
	/* iterare how_many volte le seguenti istruzioni
	- stampare un a capo seguito dalla stringa "Inserisci un numero "
	- dichiarare una variabile x di tipo float
	- leggere x
	- assegnare a sum la somma di sum e x
	*/
	for (int i = 0; i < how_many; i++)
	{
		cout << endl;
		cout << "Inserisci un numero" << endl;
		float x;
		cin >> x;
		sum += x;
	}
	// stampare un a capo seguito dalla stringa "La media è "
	cout << endl << "La media e' ";
	// stampare la divisione di sum per how_many
	cout << sum/how_many << endl;

}
