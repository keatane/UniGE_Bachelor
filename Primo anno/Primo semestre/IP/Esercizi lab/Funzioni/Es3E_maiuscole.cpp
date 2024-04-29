// Es_2 di riscaldamento:  Scrivere una funzione senza parametri che legge lettere maiuscole finché l’utente non inserisce un carattere che non è una
// lettera maiuscola e restituisce la prima in ordine alfabetico.
// Scrivere un programma per testare la funzione secondo il seguente algoritmo.

#include <iostream>

using namespace std;

char first_letter(){
	// stampare la stringa "Inserisci una lettera maiuscola "
	cout << "Inserisci una lettera maiuscola: ";
	// dichiarare una variabile first di tipo char
	char first;
	/* ripetere
	- leggere first
	finché first minore di `A' o maggiore di `Z'
	*/
	do{
		cin >> first;
	}while(first < 'A' || first > 'Z');
	// dichiarare una variabile c di tipo char inizializzata con 'Z'
	char c = 'Z';
	/* ripetere
	- se c è minore di first
	-- assegnare il valore di c a first
	- stampare la stringa "Inserisci una lettera maiuscola (o altro...
	... carattere per terminare)"
	- leggere c
	finché c è maggiore di 'A' e minore di 'Z'
	*/
	do{
		if (c < first)
			first = c;
		cout << "Inserisci una lettera maiuscola (o altro carattere per terminare): ";
		cin >> c;
	} while(c > 'A' && c < 'Z');
	// ritornare il carattere c (!si intende first)
	return first;
}


int main()
{
	char alpha;
	alpha = first_letter();
	// stampare la stringa "La lettera piu' piccola inserita e' "
	cout << "La lettera maiuscola piu' piccola inserita e' ";
	// stampare il risultato della chiamata di first_letter
	cout << alpha << endl;
}
