//Es13: Date le frasi, stampare se vere o false

#include <iostream>

using namespace std;

int main ()
{
	bool flag = true;
	cout << boolalpha; // Basta scriverlo una volta per determinare i risultati 0 o 1 in forma scritta "false" e "true"
		// cout << noboolalpha; Per ripristinare la notazione in numeri
	cout << "Tre e' maggiore di uno = " << (3>1) << endl; // Mi scrive se l'espressione è vera o falsa
	cout << "Quattro diviso due e' minore di zero = " << (4/2==0) << endl;
	cout << "Il carattere 'zero' e' uguale al valore zero = " << ("zero"==0) << endl;
	cout << "Dieci mezzi è compreso fra zero escluso e dieci incluso = " << ((10/2 > 0)&&(10/2 <= 10)) << endl;
	cout << "Non e' vero che tre e' maggiore di due e minore di uno = " << flag << endl;
	cout << "Tre minore di meno cinque implica sette maggiore di zero = " << flag << endl;
}
