//Calcola la media (reale) di due numeri interi in input

#include <iostream>

using namespace std;

int main ()
{
	int a, b;
	cout << "Inserisci due numeri interi:\n";
	cin >> a >> b;
	
	float media;
	media = (a+b)/2.0;
	
	cout << "La media vale: " << media << endl;
}
