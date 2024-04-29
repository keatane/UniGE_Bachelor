// Es_13 avanzato: 

#include <iostream>

using namespace std;

int main()
{	
	int ore, minuti;
	
	cout << "Inserisci le ore attuali: " << endl;
	cin >> ore;
	cout << "Inserisci i minuti attuali: " << endl;
	cin >> minuti;
	
	if ((ore < 1) || (ore > 12) || (minuti < 0) || (minuti > 59))
	{
		cout << "ERRORE nell'input" << endl;
		return -1;
	}
	
	cout << "Sono le ore: ";
	
	
// Elaboro le ore

	switch (ore)
	{
		case 1:
		cout << "una";
		break;
		
		case 2:
		cout << "due";
		break;
		
		case 3:
		cout << "tre";
		break;
		
		case 4:
		cout << "quattro";
		break;
		
		case 5:
		cout << "cinque";
		break;
		
		case 6:
		cout << "sei";
		break;
		
		case 7:
		cout << "sette";
		break;
		
		case 8:
		cout << "otto";
		break;
		
		case 9:
		cout << "nove";
		break;
		
		case 10:
		cout << "dieci";
		break;
		
		case 11:
		cout << "undici";
		break;
		
		case 12:
		cout << "dodici";
		break;


}

cout << " ";

// Elaboro i minuti

// if ((minuti > 0)&&(minuti < 15)) Poichè per difetto a 15 minuti, in caso fosse compreso fra 1 e 14 inclusi o fosse zero, non stampo nulla

if ((minuti >= 15)&&(minuti < 30))
	cout << "e un quarto";
else if ((minuti >= 30)&&(minuti < 45))
	cout << "e mezza";
else if (minuti >= 45)
	cout << "e tre quarti";

if (minuti%15 != 0)
	cout << " circa";
	
	
	cout << endl;
	return 0;
	
}
