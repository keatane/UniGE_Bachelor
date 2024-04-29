#include <iostream>

using namespace std;

int main()
{
	char giocatore1, giocatore2;
	cout << "Inserisci la giocata del primo giocatore \n[Scegli fra [c]arta, [f]orbice, [s]asso]\n";
	cin >> giocatore1;
	cout << "Inserisci la giocata del secondo giocatore\n";
	cin >> giocatore2;

	if ((giocatore1 != 'c' && giocatore1 != 'f' && giocatore1 != 's') || (giocatore2 != 'c' && giocatore2 != 'f' && giocatore2 != 's'))
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
