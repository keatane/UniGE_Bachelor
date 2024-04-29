/* Es_7 di base: Definire una struct Time per mantenere informazioni orarie come terne ora, minuti, secondi (memorizzabili con degli interi
senza segno).
Scrivere un programma che legge le informazioni relative a due variabili T1, T2 di tipo Time, ne verifica la correttezza e
calcola il tempo trascorso tra i due orari, assumendo che si riferiscano allo stesso giorno.

*/


#include <iostream>
#include <cmath>

using namespace std;

struct Time{
	 int ore;
	 int mins;
	 int sec;
};


int main()
{
	// INPUT
	Time T1, T2;
	do{
	cout << "Inserisci il primo orario (piu' piccolo)" << endl;
	cout << "Ore: ";
	cin >> T1.ore;
	cout << "Minuti: ";
	cin >> T1.mins;
	cout << "Secondi: ";
	cin >> T1.sec;
	if (T1.ore > 24 || T1.ore < 0 || T1.mins < 0 || T1.mins > 59 || T1.sec < 0 || T1.sec > 59)
		cout << "Dati errati, inseriscili nuovamente" << endl;
	}while(T1.ore > 24 || T1.ore < 0 || T1.mins < 0 || T1.mins > 59 || T1.sec < 0 || T1.sec > 59);
	cout << endl;
	do{
	cout << "Inserisci il secondo orario (piu' grande)" << endl;
	cout << "Ore: ";
	cin >> T2.ore;
	cout << "Minuti: ";
	cin >> T2.mins;
	cout << "Secondi: ";
	cin >> T2.sec;
	if (T2.ore > 24 || T2.ore < 0 || T2.mins < 0 || T2.mins > 59 || T2.sec < 0 || T2.sec > 59)
		cout << "Dati errati, inseriscili nuovamente" << endl;
	}while(T2.ore > 24 || T2.ore < 0 || T2.mins < 0 || T2.mins > 59 || T2.sec < 0 || T2.sec > 59);

	// CONTROLLO
    int Dore = 0, Dmins = 0, Dsec = 0; // Differenze

	if (T1.sec > T2.sec)
	{
		Dsec = 60-T1.sec+T2.sec;
        Dmins = 60-T1.mins+T2.mins-1; // -1 perchè il minuto che compare in realtà è espresso in secondi
	}		// Es. 13.20 -> 14.10, sono passati (20>10): 60-20+10 = 50 minuti senza contare 1 ora (che NON è passata, devo impedire la differenza 14-13!)
	else{
		Dsec = T2.sec-T1.sec;
        if (T1.mins > T2.mins)
            Dmins = 60-T1.mins+T2.mins;
        else{
            Dmins = T2.mins-T1.mins;
            Dore = T2.ore-T1.ore;
        }
	}

	// OUTPUT
	cout << "Fra i due orari e' trascorso: " << Dore << " ore, " << Dmins << " minuti e " << Dsec << " secondi\n";
	if (Dore == 0 && Dmins == 0 && Dsec == 0)
		cout << "Gli orari coincidono!" << endl;

}
