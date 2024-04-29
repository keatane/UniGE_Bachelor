/* Es_11 di base: Scrivere una funzione senza argomenti che chiede all’utente di inserire e legge numeri interi e poi chiede all’utente se vuole
continuare e legge la risposta finché l’utente non risponde di no. Finito il ciclo di lettura restituisce la media dei numeri letti
(di tipo float).
*/


#include <iostream>

using namespace std;


float leggiInt(){
	int n;
	int somma = 0;
	int contatore = 0;
    char answer;
	do{
	cout << "Inserisci un numero intero" << endl;
	cin >> n;
	somma += n;
	contatore++;
	cout << "Vuoi continuare a inserire? [S] [N]" << endl;

	cin >> answer;
	}while (answer == 'S' || answer == 's');

	return (static_cast<float>(somma))/contatore;
}

int main()
{
    cout << "Media: " << leggiInt() << endl;
}
