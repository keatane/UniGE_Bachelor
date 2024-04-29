// Es_5 base: Scrivere un programma che legge un numero intero da input e stampa se è o no divisibile per 13.

#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci un numero intero" << endl;
	int n;
	cin >> n;
	
	if (n%13 == 0)
		cout << "Il numero e' divisibile per 13\n";
	else
		cout << "Il numero non e' divisibile per 13\n";

}


