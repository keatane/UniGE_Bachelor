/* Es_19 avanzato: Scrivere un programma che legge un intero positivo compreso fra 1 e 3000 e lo stampa in notazione romana. Si ricorda che:
• i numeri romani sono scritti usando le lettere I (per 1), V (per 5), X (per 10), L (per 50), C (per 100), D (per 500) e
M (per 1000) e rappresentano un numero in maniera addittiva (non posizionale come i numeri arabi), partendo dai
simboli che rappresentano i numeri più grandi a sinistra e man mano scendendo con simboli che rappresentano numeri
sempre più piccoli; ad esempio MMXVII rappresenta 2017 come 1000 + 1000 + 10 + 5 + 1 + 1.
• si possono incontrare dei simboli in ordine inverso, ma in questo caso i valori invece di andare sommati vanno sottratti;
questo meccanismo può essere usato solo per i numeri 4, rappresentato da IV, 9, rappresentato da IX, 40, rappresentato
da XL, 90, rappresentato da XC, 400, rappresentato da CD, e 900, rappresentato da CM. Quindi ad esempio 1984 si
rappresenta con MCMLXXXIV e 999 si rappresenta con CMXCIX (e non con IM).
*/

#include <iostream>

using namespace std;

int main()
{
    int num;
	do{
		cout << "Inserisci un numero intero positivo maggiore di zero\n";

		cin >> num;
	} while (num <= 0);

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
