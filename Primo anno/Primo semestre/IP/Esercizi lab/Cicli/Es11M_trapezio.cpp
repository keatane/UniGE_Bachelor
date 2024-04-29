// Es_11 di base: Scrivere un programma che legge due numeri interi strettamente positivi e stampa il trapezio rettangolo fatto di ` x ' con le basi lunghe quanto i numeri letti, e l’altezza pari alla differenza fra le basi più uno.

#include <iostream>

using namespace std;

int main()
{
	int n1, n2;
	do{
	cout << "Inserisci due numeri interi strettamente positivi" << endl;
	cin >> n1 >> n2;
	} while (n1 < 0 || n2 < 0);
	
	for (int i=0; i < (abs(n1-n2)+1); i++)
	{
		for (int j=0; j < (n1+i); j++)
			cout << "x";
		cout << endl;
	}
	
}
