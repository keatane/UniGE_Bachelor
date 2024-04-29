// Es_4 base:  Scrivere un programma che legge tre numeri reali e li stampa in ordine decrescente

#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci tre numeri interi" << endl;
	
		double a0, a1, a2;
	
	
	cin >> a0 >> a1 >> a2;
	
	double aux;
	
	if (a0 < a1)
		{aux = a1;
		a1 = a0;
		a0 = aux;}

	
	if (a0 < a2)
		{aux = a0;
		a0 = a2;
		a2 = aux;}
	
	
	if (a1 < a2)
		{aux = a2;
		a2 = a1;
		a1 = aux;}

	
	// stampare  la stringa  "I numeri inseriti, in ordine decrescente, sono: "
	cout << "I numeri inseriti, in ordine decrescente, sono: " << endl;
	
	// stampare il valore di a0, seguito dal carattere >
	cout << a0 << " > ";
	
	// stampare il valore di a1, seguito dal carattere >
	cout << a1 << " > ";
	
	// stampare il valore di a2
	cout << a2;
	
	// stampare un  a capo
	cout << endl;
	
	
	// N.B. Un altro modo e' creare l'ordine crescente e stampare i numeri in modo inverso ì: prima a2, poi a1 e poi a0.
}



