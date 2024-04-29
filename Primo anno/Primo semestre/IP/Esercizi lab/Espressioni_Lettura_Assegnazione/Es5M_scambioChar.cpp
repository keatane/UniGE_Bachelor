// Es_Base_n5: scrivi un programma che scambia i valori di due variabili di tipo char, lette da input, e stampa i valori prima e dopo lo scambio. 

#include <iostream>

using namespace std;

int main()
{
	char a, b;
	cout << "Scrivi due caratteri\n";
	cin >> a >> b;
	cout << "Hai scritto:\n";
	cout << a << "\n";
	cout << b << "\n";
	
	char temp;
	temp = a;
	a = b;
	b = temp;
	
	cout << "Dopo lo scambio i valori sono:\n";
	cout << a << "\n";
	cout << b << "\n";
}
