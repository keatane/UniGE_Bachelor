/* Scrivere un programma che legge un array di interi positivi, lo scorre dall’inizio alla fine, e di tutti gli elementi che sono
ripetuti in sequenza contigua cancella tutte le occorrenze tranne una, trasformando le ripetizioni in elementi unici (vedi
esempi qui sotto).
Al termine del procedimento, i valori che non sono stati eliminati devono essere contenuti in elementi consecutivi dello stesso
array, e gli elementi rimanenti devono essere azzerati. Il programma infine stampa tutti gli elementi non zero.
*/

#include <iostream>

using namespace std;

int main()
{
	const int N = 10;
	int a[N], val;

	//INPUT
	for (int i=0; i<N; i++)
	{
		cout << "Valore n. " << i << ": ";
		cin >> val;
		a[i] = val;
	}

	// Registrazione dei primi valori di sequenze ripetute
	int aus[N] = {};
	aus[0] = a[0];
	for (int i=1; i<N; i++)
	{
		if (a[i] != a[i-1])
		aus[i] = a[i];
	}

	/* // Controllo
	cout << endl;
	for (int i=0; i<N; i++)
	{
		cout << aus[i] << endl;
	}
	*/

	// Ordinamento delle cifre in modo consecutivo (a destra gli zeri)
	int temp = 0;
	for (int i=0; i<N; i++)
	{
		if (aus[i] == 0)
        {
            for (int j=i+1; j<N; j++)
            {
                if (aus[j] != 0)
                {
                    temp = aus[i];
                    aus[i] = aus[j];
                    aus[j] = temp;

                    break; // Altrimenti il programma continua a cercare un numero diverso da zero e lo sostituisce nuovamente
                }
            }
        }

	}


	// Riporto i valori dentro l'array originale
	for (int i=0; i<N; i++)
	{
		a[i] = aus[i];
	}

	//OUTPUT (senza zeri)
	cout << endl;
    cout << "Array ordinato senza sequenze ripetute: " << endl;
	for (int i=0; i<N; i++)
	{
	    if (a[i] == 0)
            break;  // Fermo l'output se trovo il primo zero (sono sicuro che le prossime cifre saranno altri zeri)
		cout << a[i] << endl;
	}

}
