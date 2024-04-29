/* Es_5 di base: Definire una struct Date per rappresentare date, ossia informazioni relative a giorno, mese ed anno (tutti memorizzabili con
degli interi senza segno)
Scrivere un programma che legge una data D1 e, dopo averne verificato la correttezza controlla se D1 sia una data passata
o futura e stampa un messaggio di output opportuno.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double TOLL = 0.0000001;

struct Date{
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};

int main()
{
    bool bisestile = false;

	Date Do;

	//Data odierna (scelta)
	Do.giorno = 27;
	Do.mese = 10;
	Do.anno = 2020;

	Date D1;
	do{
	cout << "Inserisci l'anno della data da controllare" << endl;
	cin >> D1.anno;
	cout << "Inserisci il mese della data da controllare" << endl;
	cin >> D1.mese;
	cout << "Inserisci il giorno della data da controllare" << endl;
	cin >> D1.giorno;

	//Controllo se anno bisestile
	if (D1.anno%4 == 0)
		if (D1.anno%100 == 0)
			if (D1.anno%400 == 0)
				bisestile = true;
			else
				bisestile = false;
		else
			bisestile = true;

    //Interrompo il programma se non viene rispettata la condizione
    if (D1.mese == 1 || D1.mese == 3 || D1.mese == 5 || D1.mese == 7 || D1.mese ==  8 || D1.mese == 10 || D1.mese == 12)
        if (D1.giorno > 31)
    {
        cout << "Dati non validi" << endl;
        return 32;
    }
    if (D1.mese == 2 || D1.mese == 4 || D1.mese == 5 || D1.mese == 6 || D1.mese ==  9 || D1.mese == 11)
        if (D1.giorno > 30)
    {
        cout << "Dati non validi" << endl;
        return 32;
    }


	if (D1.anno < 1 || D1.giorno < 1 || D1.mese > 12 || D1.giorno > 31 || D1.mese < 1 || (bisestile && D1.giorno > 29 && D1.mese == 2) || (!bisestile && D1.giorno > 28 && D1.mese == 2))
		cout << "Dati non validi, inseriscili nuovamente \n\n";

	//Nel while controllo se bisestile e supera il 29 esimo giorno e se non lo è, pongo i giorni di febbraio non inseribili
	}while (D1.anno <= 0 || D1.giorno <= 0 || D1.mese > 12 || D1.giorno > 31 || D1.mese <= 0 || (bisestile && D1.giorno > 29 && D1.mese == 2) || (!bisestile && D1.giorno > 28 && D1.mese == 2));

	if (D1.anno < Do.anno)
		cout << "La data e' passata" << endl;
	else if (D1.anno > Do.anno)
		cout << "La data e' futura" << endl;
	else	// Stesso anno
	{
		if (D1.mese < Do.mese)
		cout << "La data e' passata" << endl;
		else if (D1.mese > Do.mese)
		cout << "La data e' futura" << endl;
		else // Stesso mese
		{
			if (D1.giorno < Do.giorno)
			cout << "La data e' passata" << endl;
			else if (D1.giorno > Do.giorno)
			cout << "La data e' futura" << endl;
			else
			cout << "Le date coincidono!" << endl;
		}
	}


}
