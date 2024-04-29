// Programma di esempio Loop
// Problema: calcolare l'età media degli studenti in classe (non conosciamo la cardinalità dell'insieme di studenti, ovvero non sappiamo quanti studenti vi sono in aula).
//
//
// Created by Kevin on 12/10/2020

#include <iostream>
#include <iomanip> // Per setprecision

using namespace std;

int main()
{
	int sum = 0;
	int contatore = 0;
	int eta;
	
	// INPUT e CALCOLI
	
	cout << "Inserisci eta' (numeri interi positivi)" << endl;
	cout << "per uscire dal ciclo scrivi -1" << endl;
	
	while (eta != -1)
	{
		cin >> eta;
		
		if (eta != -1)
		{
			contatore ++;
			sum += eta;	// Altrimenti avrei un valore di somma errato
		}
	}
	
	float media;
	// Per evitare una perdita di informazioni dalla divisione intera, applico una conversione di tipo al numeratore o al denominatore
	media = static_cast<float>(sum)/contatore;
	
	cout << setprecision(4) << "Media: " << media << endl; //setprecision(4) = numero cifre

	// OUTPUT: stampare su standard output la media calcolata
}
