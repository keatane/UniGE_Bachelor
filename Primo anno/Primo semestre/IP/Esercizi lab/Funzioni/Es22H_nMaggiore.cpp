/* Scrivere una funzione con argomenti interi n e d, con d compreso fra 0 e 9 e n maggiore di 10, che restituisce il più grande
numero compreso fra 0 e n che nella sua rappresentazione in base 10 usa la cifra d. Ad esempio la sua chiamata con argomenti
3 per d e 15 per n restituisce 13 e la sua chiamata con argomenti 3 per d e 42 per n restituisce 39.
Riuscite a generalizzare questa funzione al caso in cui invece di cercare una singola cifra ne cerchiamo una sequenza? Ad
esempio se cerco il più grande numero fra 0 e 400 che nella sua rappresentazione in base 10 contiene 39 il risultato sarà
399.
*/


#include <iostream>

using namespace std;

const int DIMn = 3;
const int DIMd = 2;


// SEQUENZA
int trovaMaggioreS(int d, int n){

	// Registro singole cifre di d
	int cifreD[DIMd];
	for (unsigned int i = 0; i < DIMd; ++i)
	{
		cifreD[i] = d % 10;
		d /= 10;
	}

	// Registro singole cifre di n
	int cifreN[DIMn];
	for (unsigned int i = 0; i < DIMn; ++i)
	{
		cifreN[i] = n % 10;
		n /= 10;
	}

	// Controllo sequenza
	int temp;
	bool seq_trovata = false;
	do{
		for (unsigned int i = 0; i < DIMn; ++i)
		{
			seq_trovata = true;
			if (cifreN[i] == cifreD[i])
				for (unsigned int j = 1; j < DIMd; ++j)
				{
					if (cifreN[j] != cifreD[j]){
						seq_trovata = false;
						break;
					}
				}
			else
				seq_trovata = false;
			if (seq_trovata == true)
				{
				    for (unsigned int i = DIMn-1; i >= 0; --i)
                    cout << cifreN[i];
				}
		}

		n--;
		for (unsigned int i = 0; i < DIMn; ++i)
		{
			cifreN[i] = n % 10;
			n /= 10;
		}
		if (n < 0)
		{
		    cout << "ERR: Sequenza D non trovata in N" << endl;
		    return 0;
		}
    }while(true);
}


/* SINGOLA CIFRA
int trovaMaggiore(int d, int n){
    int temp;
    do{
        temp = n;
		do{
            if (temp % 10 == d)
                return n;
            else
				temp /= 10;
		}while(temp > 0);
		n--;
    }while(true);
}
*/

int main()
{
    int nBase;
    int nLimite;

	/* SINGOLA CIFRA
	do{
		cout << "Inserisci un numero D compreso fra 0 e 9" << endl;
		cin >> nBase;
		cout << "Inserisci un numero N maggiore uguale di 10" << endl;
		cin >> nLimite;

		if (nBase < 0 || nBase > 9 || nLimite < 10)
			cout << "Errore nell'input, ripeti. \n\n" << endl;
	}while(nBase < 0 || nBase > 9 || nLimite < 10);
	*/

	// SEQUENZA
	do{
		cout << "Inserisci una sequenza D di " <<  DIMd << " numeri interi maggiore di zero" << endl;
		cin >> nBase;
		cout << "Inserisci una sequenza N di " << DIMn << " numeri interi maggiore di zero" << endl;
		cin >> nLimite;

		if (nBase < 0 || nLimite < 0)
			cout << "Errore nell'input, ripeti. \n\n" << endl;
	}while(nBase < 0 || nLimite < 0);

	cout << "Il numero piu' grande, minore di N, che usa la cifra D e': " << trovaMaggioreS(nBase, nLimite) << endl;
}
