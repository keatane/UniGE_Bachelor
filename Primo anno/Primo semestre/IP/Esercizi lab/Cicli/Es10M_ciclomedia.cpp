// Es_10 di base: Scrivere un programma che chiede all’utente di inserire e leggere numeri interi e poi chiede all’utente se vuole continuare e legge la risposta, finché l’utente non risponde di no. Finito il ciclo di lettura stampa la media dei numeri letti.

#include <iostream>

using namespace std;

int main()
{
	int n, sum = 0, contatore = 0;
	char answer;
	do{
	
		cout << "Inserisci un numero intero positivo" << endl;
		cin >> n;
		sum += n;
		contatore++;
		cout << "Vuoi continuare? [s] [n]" << endl;
		cin >> answer;
		if (answer == 'n')
			break;
	} while (answer == 's');
	
	float media;
	media = static_cast<float>(sum)/contatore;
	cout << "\nMedia numeri: " << media << endl;
	
}
