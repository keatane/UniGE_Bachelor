// Es_2 di riscaldamento:  Scrivere un programma che legge tre interi e li stampa in ordine crescente, seguendo l’algoritmo proposto (che fissa una serie di dettagli ulteriori)

#include <iostream>

using namespace std;

int main()
{
	// chiedere di inserire tre numeri interi
	cout << "Inserisci tre numeri interi" << endl;
	
	// dichiarare tre variabili a0, a1 e a2 di tipo int
	int a0, a1, a2;
	
	// leggere a0, a1 e a2
	cin >> a0 >> a1 >> a2;
	
	// ordinare a0, a1 e a2, ovvero:
	// dichiarare una variabile intera aux;
	int aux;
	
	// se a0 maggiore di a1 scambiare fra loro a0 e a1, cioè
	// - assegnare ad aux il valore di a1, ad a1 il valore di a2...
	//    ... e ad a0 il valore di aux
	//    (a questo punto a0 <= a1 e a1 == aux)
	if (a0 > a1)
		{aux = a1;
		a1 = a0;
		a0 = aux;}

	// se a0 maggiore di a2
	// - assegnare ad aux il valore di a0, ad a0 il valore di a2 e...
	//    ... ad a2 il valore di aux
	if (a0 > a2)
		{aux = a0;
		a0 = a2;
		a2 = aux;}
	
	// se a1 maggiore di a2 scambiare fra loro a1 e a2, cioè
	// - assegnare ad aux il valore di a2, ad a2 il valore di a1,...
	//    ... ad a1 i valore di aux (a questo punto a0<=a1 e a1<=a2)
	if (a1 > a2)
		{aux = a2;
		a2 = a1;
		a1 = aux;}

	
	// stampare  la stringa  "I numeri inseriti, in ordine crescente, sono: "
	cout << "I numeri inseriti, in ordine crescente, sono: " << endl;
	
	// stampare il valore di a0, seguito dal carattere <
	cout << a0 << " < ";
	
	// stampare il valore di a1, seguito dal carattere <
	cout << a1 << " < ";
	
	// stampare il valore di a2
	cout << a2;
	
	// stampare un  a capo
	cout << endl;
}


}


