// Es_11 base: Scrivere un programma che legge un numero intero compreso fra 1 e 12 e stampa il nome del mese corrispondente (1==gennaio. . . ). Se il numero non è compreso fra 1 e 12 stampa un messaggio di errore ed esce.

#include <iostream>

using namespace std;

int main()
{
	//Posso usare sia IF (ELSE IF) che SWITCH
	
	cout << "Inserisci un numero intero" << endl;
	int n;
	cin >> n;
	
	switch (n)
	{
		case 1:
			cout << "Il numero corrisponde al mese di Gennaio" << endl;
			break;
		case 2:
			cout << "Il numero corrisponde al mese di Febbraio" << endl;
			break;
		case 3:
			cout << "Il numero corrisponde al mese di Marzo" << endl;
			break;
		case 4:
			cout << "Il numero corrisponde al mese di Aprile" << endl;
			break;
		case 5:
			cout << "Il numero corrisponde al mese di Maggio" << endl;
			break;
		case 6:
			cout << "Il numero corrisponde al mese di Giugno" << endl;
			break;
		case 7:
			cout << "Il numero corrisponde al mese di Luglio" << endl;
			break;
		case 8:
			cout << "Il numero corrisponde al mese di Agosto" << endl;
			break;
		case 9:
			cout << "Il numero corrisponde al mese di Settembre" << endl;
			break;
		case 10:
			cout << "Il numero corrisponde al mese di Ottobre" << endl;
			break;
		case 11:
			cout << "Il numero corrisponde al mese di Novembre" << endl;
			break;
		case 12:
			cout << "Il numero corrisponde al mese di Dicembre" << endl;
			break;
		
		default:
			cout << "ERRORE: Mese non riconosciuto" << endl;
			// break; Non necessario, arrivati in fondo uscirebbe comunque
	}
}
