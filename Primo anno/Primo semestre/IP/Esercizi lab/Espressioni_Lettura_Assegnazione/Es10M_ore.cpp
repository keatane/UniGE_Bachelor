//Calcola i minuti totali dopo aver ricevuto in input un numero di ore da 0 a 23 e un numero di minuti da 0 a 59

#include <iostream>

using namespace std;

int main ()
{
	int ora, minuto;
	cout << "Inserisci l'ora attuale: " << endl;
	cin >> ora;
	cout << ":\n";
	cin >> minuto;
	
	int minTot;
	minTot = ora*60 + minuto;
	cout << "I minuti complessivi passati dalle ore 00:00 e': " << minTot << endl;
	
}
