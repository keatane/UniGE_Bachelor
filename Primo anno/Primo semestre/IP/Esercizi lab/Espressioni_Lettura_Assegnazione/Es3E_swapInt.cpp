// Es_Riscaldamento_n3: scrivi un programma che scambia tra loro due valori interi, letti da input, e stampa i valori prima e dopo lo scambio. 

#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci il primo valore intero" << endl;
	int a;
	cin >> a;
	cout << "Inserisci il secondo valore intero" << endl;
	int b;
	cin >> b;
	cout << "\na vale: " << a;
	cout << "\nb vale: " << b;
	int c;
	c = a;
 	a = b;
	b = c;
	cout << "\n\na vale: " << a;
	cout << "\nb vale: " << b << endl; 
} 
 
