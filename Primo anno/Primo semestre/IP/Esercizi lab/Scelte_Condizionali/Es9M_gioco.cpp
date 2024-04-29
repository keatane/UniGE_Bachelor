// Es_9 base: Scrivere un programma che implementa un turno di gioco di forbice carta sasso, ovvero che legge in input la mossa dei due giocatori e restituisce in output chi ha vinto.

#include <iostream>

using namespace std;

int main()
{
	char g1, g2;
	cout << "Inserisci la giocata del primo giocatore fra [C]arta, [F]orbice e [S]asso\n";
	cin >> g1;
	
	cout << "Inserisci la giocata del secondo giocatore fra [C]arta, [F]orbice e [S]asso\n";
	cin >> g2;
	
	if (g1 == g2)
		cout << "Pareggio" << endl;
	else
	{
		if ((g1 == 'C')&&(g2 == 'F'))
			cout << "Vince g2" << endl;
		if ((g1 == 'C')&&(g2 == 'S'))
			cout << "Vince g1" << endl;
		if ((g1 == 'F')&&(g2 == 'C'))
			cout << "Vince g1" << endl;
		if ((g1 == 'F')&&(g2 == 'S'))
			cout << "Vince g2" << endl;
		if ((g1 == 'S')&&(g2 == 'F'))
			cout << "Vince g1" << endl;
		if ((g1 == 'S')&&(g2 == 'C'))
			cout << "Vince g2" << endl;
	}
		
}
