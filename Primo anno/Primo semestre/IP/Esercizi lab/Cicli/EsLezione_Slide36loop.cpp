// Es slide sui loop: calcolo fattoriale

#include <iostream>

using namespace std;

int main()
{
	int n;
	
	do{
	cout << "Inserisci un numero intero positivo" << endl;
	cin >> n;
	if (n < 0)
		cout << "Per favore, un numero positivo" << endl;
	} while (n < 0);
	
	int fattoriale;
	
	if (n == 0)
		fattoriale = 0;
	else
	{
		fattoriale = 1;
		for (int i=0; i < n; ++i) // Se i = n avrei n-i = 0 che annullerebbe la moltiplicazione effettuata
		{
			fattoriale *= (n-i);
		}
	}
	
	cout << "Fattoriale: " << fattoriale << endl;

}
