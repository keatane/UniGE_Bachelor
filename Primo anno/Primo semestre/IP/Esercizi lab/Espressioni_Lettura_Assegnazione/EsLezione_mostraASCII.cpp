#include <iostream>

using namespace std;

int main (){

	/* Acquisire da tastiera un char e voglio capire cosa succede se lo 
	converto in int */
	
	char c;
	
	cout << "Inserisci un carattere alfabetico: \n";
	cin >> c; 
	
	//int i = c; // cast implicito safe = conversione di tipo, implicito perchè uso l'assegnazione, safe perchè il valore a destra dell'uguale ha un range di valori inferiore di quello a sinistra, quindi non vengono persi dei valori.
	
	
	/* Il cast esplicito rende esplicito il passaggio di tipo: */
	int i = static_cast<int>(c);
	// Prende l'argomento e lo attribuisce a un certo tipo 'di arrivo' specificato fra < >
	
	cout << "Il carattere " << c << " ha valore intero: " << i << endl; 
	// Il valore stampato è la codifica intera (ASCII) della lettera conservata in c
	
	cout << "La posizione del carattere a: " << static_cast<int>('a') << endl;
	cout << "La posizione del carattere a: " << static_cast<int>('z') << endl;
	cout << "Il mio carattere dista da a: " << i - static_cast<int>('a') << " posizioni" << endl;
	
	cout << c - 'a' << endl; // Ottengo lo stesso risultato di prima, durante operazioni matematiche del char viene vista la parte intera.
	
	return 0;
	}
	
