// Es_Base_n6: scrivi un programma che scambia i valori di tre variabili di tipo float in maniera "circolare", lette da input, e stampa i valori pre e post scambio.

#include <iostream>

using namespace std;

int main()
{
	float a, b, c;
	cout << "Scrivi tre numeri decimali\n";
	cin >> a >> b >> c;
	cout << "\nHai scritto:\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	
	float temp;
	temp = a;
	a = b;
	b = c;
	c = temp;
	
	cout << "Dopo lo scambio i valori sono:\n";
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
}
