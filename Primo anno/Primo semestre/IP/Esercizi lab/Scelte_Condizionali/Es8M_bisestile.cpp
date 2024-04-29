// Es_8 base:  Scrivere un programma che verifica se un numero intero dato in input rappresenta o meno un anno bisestile

#include <iostream>

using namespace std;

int main ()
{
	int anno;
	cout << "Inserisci un numero intero di quattro cifre\n";
	cin >> anno;
	
	if (anno%4 == 0)
	{
		if (anno%100 == 0)
			{ if (anno%400 == 0)
					cout << "Anno bisestile" << endl;
				else
					cout << "Anno non bisestile" << endl;
			}
		else
			cout << "Anno bisestile" << endl;
	}
	else
		cout << "Anno non bisestile" << endl;


}
