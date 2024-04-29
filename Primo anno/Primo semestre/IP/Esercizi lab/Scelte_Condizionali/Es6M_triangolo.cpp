// Es_6 base: Scrivere un programma che verifica se tre numeri reali dati in input possono essere i lati di un triangolo, cioè se nessuno diessi è maggiore della somma degli altri due o minore del valore assoluto della loro differenza

#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	cout << "Inserisci tre numeri reali: " << endl;
	cin >> a >> b >> c;
	
	if ((a > b+c) || (b > a+c) || (c > a+b))
		cout << "I dati in input non possono essere i lati di un triangolo" << endl;
	else if ((a < abs(b-c)) || (b < abs(a-c)) || (c < abs(a-b)))
		cout << "I dati in input non possono essere i lati di un triangolo" << endl;
	else // Ovvero se i casi precedenti non sono verificati
		cout << "I dati in input possono essere i lati di un triangolo" << endl;

}
