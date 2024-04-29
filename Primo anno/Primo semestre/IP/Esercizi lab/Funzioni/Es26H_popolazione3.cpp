/*Es_26 avanzato: Scrivere una funzione che prende come argomenti un intero non negativo (la popolazione iniziale), la percentuale di nascite al netto delle morti come intero
fra 0 e 100 e restituisce il numero di anni necessario a raddoppiare gli abitanti se la
popolazione è in crescita, o a dimezzarli se la popolazione sta diminuendo (nell’ipotesi che non vi siano trasferimenti).
*/

#include <iostream>

using namespace std;


int crescita_popolazione(int pop0, int percNascite){
	int crescita = pop0;
	int Nanni= 0;
	if ((pop0*percNascite/100) > 0){
		cout << "Numero anni per ottenere il doppio della popolazione iniziale :";
		do{
			crescita += (pop0*percNascite/100);
			Nanni++;
		}while(crescita < 2*pop0);
	}
	else if ((pop0*percNascite/100) < 0){
		cout << "Numero anni per ottenere la meta' della popolazione iniziale :";
		do{
			crescita += (pop0*percNascite/100);
			Nanni++;
		}while(crescita > 0.5*pop0);
	}
	else
		cout << "La crescita annuale e' zero! " << endl;

	return Nanni;
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
	cout << "Inserisci il numero della percentuale delle nascite al netto delle morti (fra 0 e 100) (anche negativa)" << endl;
	cin >> percNasciteMorti;
	cout << endl;
	cout << "Crescita demografica della citta'" << endl;
	cout << crescita_popolazione(pop_iniz, percNasciteMorti) << endl;

}
