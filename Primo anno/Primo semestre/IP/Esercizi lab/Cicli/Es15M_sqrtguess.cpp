/*Es_15 di base: Scrivere un programma che chiede all’utente un numero reale e lo legge. Poi chiede all’utente di provare a indovinarne la
radice quadrata e se l’utente inserisce il valore giusto gli dice "Bravo!" ed esce, altrimenti gli propone di riprovare finché
l’utente non riesce ad indovinare.
Per provare questo programma usate come dati 25.3268614564 la cui radice quadrata è 5.03258 (se preferite altri valori, vi
conviene partire da un numero con cifre decimali e farne il quadrato, in modo da evitare errori di approssimazione dovuti
ai troncamenti).
*/

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	cout << "Inserisci un numero reale" << endl;
	float n;
	cin >> n;
	
	float radN, attempt;
	radN = sqrt(n);
	
	do{
		cout << "Indovina la radice quadrata del numero inserito" << endl;
		cin >> attempt;
		if (attempt == radN)
			cout << "Bravo!" << endl;
		else
			cout << "Riprova" << endl;
	}while(attempt != radN);	

}
