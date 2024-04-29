/* Es_25 avanzato: Analogamente al punto precedente, scrivere una funzione che prende, oltre ai parametri della funzione al punto 23, anche
un intero che rappresenta un numero di anni e restituisce la popolazione dopo quel numero di anni.
– potete scrivere la prima e usarla ripetutamente (ciclo) per calcolare la seconda
– oppure potete scrivere la seconda in maniera indipendente; in questo caso la prima contiene una chiamata alla seconda,
essendo un caso particolare, in cui il numero di anni è uno.]
*/

#include <iostream>

using namespace std;


int crescita_popolazione(int pop0, int percNascite, int popTrasferita, int anno){
	int crescita = pop0; // Inizializzo con la popolazione iniziale, e su questa sommo la crescita 'effettiva'
	for(unsigned int i=0; i<anno; ++i)
		crescita += (pop0*percNascite/100) + popTrasferita;  // Altrimenti posso fare alla fine del calcolo: crescita*anno
	return crescita;
}


int main()
{
	int pop_iniz;
	int percNasciteMorti;
	int trasferiti;
	int anni;
    cout << "Inserisci il numero della popolazione iniziale presente nella citta'" << endl;
	cin >> pop_iniz;
	cout << "I dati seguenti saranno chiesti di tipo annuale" << endl;
	cout << "Inserisci il numero della percentuale delle nascite al netto delle morti (fra 0 e 100)" << endl;
	cin >> percNasciteMorti;
	cout << "Inserisci il numero delle persone che si trasferiscono nella citta' al netto di quelle che l'abbandonano " << endl;
	cin >> trasferiti;
	cout << "Inserisci il numero di anni dopo cui si calcola la crescita " << endl;
	cin >> anni;
	cout << endl;
	cout << "Crescita demografica della citta'" << endl;
	cout << "Abitanti iniziali: " << pop_iniz << endl;
	cout << "Abitanti dopo un anno: " << crescita_popolazione(pop_iniz, percNasciteMorti, trasferiti, anni) << endl;

}
