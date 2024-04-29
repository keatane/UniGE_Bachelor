// Es1 di riscaldamento: Scrivere un programma che legge due caratteri e stampa la stringa “Uguali” se sono lo stesso carattere e la stringa “Diversi”se sono due caratteri differenti.


#include <iostream>

using namespace std;

int main()
{
	// dichiarare due variabili a e b di tipo char
	char a, b;
	
	// leggere a e b
	cin >> a >> b;
	
	// se a e b sono uguali
	if (a==b)
	//      stampare la stringa "Uguali"
			cout << "Uguali" << endl;
	// altrimenti
	else
	//      stampare la stringa "Diversi"
			cout << "Diversi" << endl;

}
