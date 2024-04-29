// Es_12 avanzato: Scrivere un programma che verifica se un numero intero dato in input rappresenta o meno un anno bisestile. Usare la regoladel calendario gregoriano che si trova su Wikipedia alla voce “Anno bisestile”.

//Nel calendario gregoriano, quindi, sono bisestili:  gli anni non secolari il cui numero è divisibile per 4; gli anni secolari il cui numero è divisibile per 400.

#include <iostream>

using namespace std;

int main()
{
	int anno;
	cout << "Inserisci un numero intero" << endl;
	cin >> anno;
	
	if (anno%100 != 0)
	{
		if (anno%4 == 0)
			cout << "Anno bisestile" << endl;
		else
			cout << "Anno non bisestile" << endl;
	}
	else
	{
		if (anno%400 == 0)
			cout << "Anno bisestile" << endl;
		else
			cout << "Anno non bisestile" << endl;
	}

}
