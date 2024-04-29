/* Es_24 avanzato: La crescita della popolazione in una città può essere stimata a partire dalla popolazione iniziale, aumentata di una certa percentuale (le nascite al netto delle morti) e di un numero (le persone che ci si trasferiscono al netto di quelle che
l’abbandonano).
Scrivere una funzione che presi come argomenti un intero non negativo (la popolazione iniziale), la percentuale di nascite
al netto delle morti come intero fra 0 e 100 e il numero di persone che si trasferiscono nella città al netto di quelle che
l’abbandonano, restituisce un intero pari al numero di abitanti dopo un anno.
Si noti che sia la percentuale di nascite al netto delle morti che il numero di persone che si trasferiscono nella città al netto
di quelle che l’abbandonano possono essere negativi, positivi o nulli.
[SUGGERIMENTO: si noti che tutti i parametri sono interi, per cui usando moltiplicazione e divisione fra interi (nel giusto
ordine) il risultato sarà ancora un intero.]
*/


#include <iostream>

using namespace std;


int crescita_popolazione(int pop0, int percNascite, int popTrasferita){
	int crescita;
	crescita = pop0 + (pop0*percNascite/100) + popTrasferita;   // Diviso 100 lo applico dopo la moltiplicazione, altrimenti es. 20% -> 20/100 = 0 nella div intera,
	return crescita;                                                //  mentre con pop0 = 1000 -> 1000*20: 20000 /100 = 200 (sempre intero). pop0*percNascite calcola le nascite/morti sulla pop iniz.
}


int main()
{
	int pop_iniz;
	int percNasciteMorti;
	int trasferiti;
    cout << "Inserisci il numero della popolazione iniziale presente nella citta'" << endl;
	cin >> pop_iniz;
	cout << "I dati seguenti saranno chiesti di tipo annuale" << endl;
	cout << "Inserisci il numero della percentuale delle nascite al netto delle morti (fra 0 e 100)" << endl;
	cin >> percNasciteMorti;
	cout << "Inserisci il numero delle persone che si trasferiscono nella citta' al netto di quelle che l'abbandonano " << endl;
	cin >> trasferiti;
	cout << endl;
	cout << "Crescita demografica della citta'" << endl;
	cout << "Abitanti iniziali: " << pop_iniz << endl;
	cout << "Abitanti dopo un anno: " << crescita_popolazione(pop_iniz, percNasciteMorti, trasferiti) << endl;

}
