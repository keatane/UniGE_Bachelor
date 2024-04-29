#include <iostream>
#include "queue.h"

using namespace std;

int main(){

	queue q;
	create_empty(q);
	
	cout << "Inserisci persone" << endl;
	/*
	// Lettura a mano
	Persona p; // viene riutilizzata per più persone
	for (int i=0; i<4; ++i)
	{
		cout << "Nome: ";
		cin >> p.name;
		cout << "Cognome: ";
		cin >> p.surname;
		cout << "Anno di nascita: ";
		cin >> p.birth;
		enqueue(q, p);
		cout << endl;
	}
	*/
	
	leggiLista("datiPersona.txt", q);
	
	cout << "Lista inserita" << endl;
	print(q);
	cout << endl;
	
	dequeue(q);
	
	cout << "Lista senza testa" << endl;
	print(q);
	cout << endl;
	
	cout << "Lista ordinata" << endl;
	sort(q);
	print(q);
	cout << endl;

}
