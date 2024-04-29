// Es_21 avanzato: Scrivere una funzione con un argomento intero n compreso fra 1 e 3000 e lo stampa in notazione romana.

#include <iostream>

using namespace std;

void stampa_romano(int num){
	// le lettere I (per 1), V (per 5), X (per 10), L (per 50), C (per 100), D (per 500) e M (per 1000)
    // Trasformazione in romano
	int i = 0, DIM = 15;
	// Se non volessi usare un array posso semplicemente stampare in output 'cout' le lettere corrispondenti
	char rom[DIM] = {};
	while (num > 0){
		if (num >= 1000)
		{
			num -= 1000;
			rom[i] = 'M';
			++i;
		}
		else if (num >= 900)
		{
			num -= 900;
			rom[i] = 'C'; // rom[i] = 'CM'; non si può rappresentare in char, quindi spezzo
			++i;
			rom[i] = 'M'; // Posizione successiva
			++i;
		}
		else if (num >= 500)
		{
			num -= 500;
			rom[i] = 'D';
			++i;
		}
		else if (num >= 400)
		{
			num -= 400;
			rom[i] = 'C';
			++i;
			rom[i] = 'D';
			++i;
		}
		else if (num >= 100)
		{
			num -= 100;
			rom[i] = 'C';
			++i;
		}
		else if (num >= 90)
		{
			num -= 90;
			rom[i] = 'X';
			++i;
			rom[i] = 'C';
			++i;
		}
		else if (num >= 50)
		{
			num -= 50;
			rom[i] = 'L';
			++i;
		}
		else if (num >= 40)
		{
			num -= 40;
			rom[i] = 'X';
			++i;
			rom[i] = 'L';
			++i;
		}
		else if (num >= 10)
		{
			num -= 10;
			rom[i] = 'X';
			++i;
		}
		else if (num >= 9)
		{
			num -= 9;
			rom[i] = 'I';
			++i;
			rom[i] = 'X';
			++i;
		}
		else if (num >= 5)
		{
			num -= 5;
			rom[i] = 'V';
			++i;
		}
		else if (num >= 4)
		{
			num -= 4;
			rom[i] = 'I';
			++i;
			rom[i] = 'V';
			++i;
		}
		else if (num >= 1)
		{
			num -= 1;
			rom[i] = 'I';
			++i;
		}
	}

	// OUTPUT notazione romana
	for (i=0; i<DIM; ++i)
		cout << rom[i];
}


int main()
{
 int n;
	do{
		cout << "Inserisci un numero intero positivo maggiore di zero\n";

		cin >> n;
	} while (n <= 0);
	stampa_romano(n);
}

