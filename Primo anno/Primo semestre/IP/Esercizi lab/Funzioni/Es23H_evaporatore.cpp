/* Un evaporatore è una macchina in cui viene inserita una certa quantità iniziale di acqua e che ogni giorno ne disperde una
percentuale prefissata nell’ambiente. Quando l’acqua contenuta scende sotto la soglia minima di funzionamento la macchina
si spegne per evitare danni.
Scrivere una funzione che presi come argomenti un float che rappresenta i litri di acqua inizialmente introdotti nella macchina, un int che rappresenta la percentuale di evaporazione giornaliera e un float che indica la soglia minima al di sotto
della quale la macchina si spegne, restituisce il numero di giorni in cui la macchina può continuare ad operare senza essere riempita. Si assuma che tutti gli argomenti siano sempre non negativi.
*/


#include <iostream>

using namespace std;

float evaporatore(float litri0, int percGiorn, float limite){

	int giorni = 0;
	int litriPerc;
	litriPerc = litri0 * percGiorn / 100; // Prefissata (non varia)
	do{
		litri0 -= litriPerc;
		giorni++;
	}while(litri0 - limite > 0.00001);
	return giorni;
}

int main()
{
	float litri;
	int percentuale;
	float soglia;
	do{

		cout << "Inserisci la quantita' di litri d'acqua introdotti inzialmente nell'evaporatore" << endl;
		cin >> litri;
		cout << "Inserisci la percentuale (intera) di evaporazione giornaliera" << endl;
		cin >> percentuale;
		cout << "Inserisci la soglia sotto la quale l'evaporatore si spegne" << endl;
		cin >> soglia;
		if (litri < 0.0 || percentuale < 0 || soglia < 0.0)
			cout << "Errore input, inserisci nuovamente i dati" << endl;
	}while(litri < 0.0 || percentuale < 0 || soglia < 0.0);

	cout << "Prima di un nuovo rifornimento, l'evaporatore puo' operare per " << evaporatore(litri, percentuale, soglia) << " giorni" << endl;

}
