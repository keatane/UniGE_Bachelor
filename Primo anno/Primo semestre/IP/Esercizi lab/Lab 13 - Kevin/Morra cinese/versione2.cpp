#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	char giocatore1, giocatore2;
	cout << "Inserisci la giocata del primo giocatore \n[Scegli fra [c]arta, [f]orbice, [s]asso]\n";
	cin >> giocatore1;

	//Generazione automatica della seconda giocata
	srand (time(NULL));
	int n;
	n = rand() % 3 + 1; // Numero fra 1 e 3 compresi

	switch (n)
	{
		case 1:
		{
			giocatore2 = 'c';
			break;
		}
		case 2:
		{
			giocatore2 = 'f';
			break;
		}
		case 3:
		{
			giocatore2 = 's';
			break;
		}
		default:
		cout << "Errore\n";
	}

    cout << "Giocatore 2: " << giocatore2 << endl;

	if (giocatore1 != 'c' && giocatore1 != 'f' && giocatore1 != 's') // A differenza della prima release, qui controllo solo l'inserimento dell'utente, presupponendo che la generazione della seconda giocata sia corretta.
	{
		cout << "Valore non valido\n";
		return 1;
	}

	bool vittoriaG1 = false;
	if (giocatore1 == giocatore2)
		cout << "Parita'\n";
	else
	{
		if (giocatore1 == 'f')
		{
			if (giocatore2 =='c')
				vittoriaG1 = true;
			else
				vittoriaG1 = false; // So già che G2 = S, non F perchè sarebbe pari a G1.
		}
		else
		{
			if (giocatore1 == 's')
			{
				if (giocatore2 == 'f')
					vittoriaG1 = true;
				else
					vittoriaG1 = false;
			}
			else
			{
				if (giocatore2 == 'f') // A questo punto so che G1 = C, perchè ho escluso le altre, e quindi nemmeno G2 è C.
					vittoriaG1 = false;
				else
					vittoriaG1 = true;
			}
		}

        if (vittoriaG1)
            cout << "Ha vinto il giocatore 1\n";
        else
            cout << "Ha vinto il giocatore 2\n";
	}

	return 0;

}
