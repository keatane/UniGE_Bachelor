#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

const int TURNI = 3;

int main()
{
	cout << "Prego, inserisci un nickname\n";
	string nick;
	cin >> nick;

	for (int i=0; i < TURNI; i++)
	{
		char giocatore, mossa_computer;
		cout << "Inserisci la giocata del primo giocatore \n[Scegli fra [c]arta, [f]orbice, [s]asso]\n";
		cin >> giocatore;

		//Generazione automatica della seconda giocata
		srand (time(NULL));
		int n;
		n = rand() % 3 + 1; // Numero fra 1 e 3 compresi

		switch (n)
		{
			case 1:
			{
				mossa_computer = 'c';
				break;
			}
			case 2:
			{
				mossa_computer = 'f';
				break;
			}
			case 3:
			{
				mossa_computer = 's';
				break;
			}
			default:
			cout << "Errore\n";
		}

		cout << "Il computer gioca " << mossa_computer << endl;

		if (giocatore != 'c' && giocatore != 'f' && giocatore != 's') // A differenza della prima release, qui controllo solo l'inserimento dell'utente, presupponendo che la generazione della seconda giocata sia corretta.
		{
			cout << "Valore non valido\n";
			return 1;
		}

		bool vittoriaG1 = false;
		string vincitore;

		if (giocatore == mossa_computer)
			cout << "Parita'\n";
		else
		{
			if (giocatore == 'f')
			{
				if (mossa_computer =='c')
				{
					vittoriaG1 = true;
					vincitore = nick;
				}
				else
				{
					vittoriaG1 = false; // So già che G2 = S, non F perchè sarebbe pari a G1.
					vincitore = "Computer";
				}
			}
			else
			{
				if (giocatore == 's')
				{
					if (mossa_computer == 'f')
					{
						vittoriaG1 = true;
						vincitore = nick;
					}
					else
					{
						vittoriaG1 = false;
						vincitore = "Computer";
					}
				}
				else
				{
					if (mossa_computer == 'f') // A questo punto so che G1 = C, perchè ho escluso le altre, e quindi nemmeno G2 è C.
					{
						vittoriaG1 = false;
						vincitore = "Computer";
					}
					else
					{
						vittoriaG1 = true;
						vincitore = nick;
					}
				}
			}

			if (vittoriaG1)
				cout << giocatore << " vince su " << mossa_computer << endl;
			else
				cout << mossa_computer << " vince su " << giocatore << endl;
            cout << "Ha vinto " << vincitore << endl;
            cout << endl;
		}

	}

	return 0;
}
