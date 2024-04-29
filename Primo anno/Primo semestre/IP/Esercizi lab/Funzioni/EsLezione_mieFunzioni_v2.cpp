// mie_funzioni.cpp

// Created by Kevin Cattaneo on 02/11/2020.

// OBIETTIVO 1: stampare n righe di * (n è una variabile "controllata" dall'utente)

#include <iostream>

using namespace std;

void StampaRighe(int n); // INTERFACCIA DELLA FUNZIONE
// N.B. Nel caso di sola interfaccia, solitamente si specificano solo i tipi in questo caso:  void StampaRighe(int);

int main() // FUNZIONE CHIAMANTE (che sta per fare una chiamata)
{
	int m;
	cout << "Inserisci quante righe vuoi stampare\n";
	cin >> m;


	// opportuna CHIAMATA di funzione
	StampaRighe(m); // m è PARAMETRO ATTUALE
	StampaRighe(3);
	StampaRighe(3+4);
}

// DICHIARAZIONE DELLA FUNZIONE DOPO IL MAIN
// void StampaRighe(int n) è detto INTESTAZIONE (Header della funzione) / INTERFACCIA / PROTOTIPO
void StampaRighe(int n)	// n è PARAMETRO FORMALE: Con informazione (argomento della funzione) che proviene dall'esterno, il nome PUO' essere diverso (es N al posto di n)
{
	for (unsigned int i=0; i<n; ++i)	// Corpo della funzione
	cout << "********************" << endl;
}
