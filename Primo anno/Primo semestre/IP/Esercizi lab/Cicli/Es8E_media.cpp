// Es_8 di base: Scrivere un programma che chiede all’utente un numero intero positivo e stampa il numero ottenuto leggendo il numero dato da destra verso sinistra. Ad esempio su 17 stampa 71, su 27458 stampa 85472 e così via.

#include <iostream>

using namespace std;

int main ()
{
	// stampare la stringa "Inserire un numero positivo: "
	// dichiarare una variabile intera k
	// leggere k
	// se k è minore di zero
	// - stampare "Valore non valido"
	// - uscire dal programma ritornando il codice di errore 666
	// stampare su una nuova riga la stringa "Rovesciando " seguita da k
	// dichiarare una variabile intera inv inizializzata a zero
	/* finché k è maggiore di zero
	- dichiarare una variabile intera mod inizializzata con il resto della...
	... divisione intera di k per 10
	- assegnare a k il quoziente di k per 10
	- assegnare a inv la moltiplicazione di inv per 10
	- assegnare a inv la somma di inv e mod
	*/
	// stampare la stringa " si ottiene " seguita da inv
	
	cout << "Inserire un numero positivo: " << endl;
	int k;
	cin >> k;
	if (k < 0)
	{ 
		cout << "Valore non valido" << endl;
		return 666;
	}
	
	cout << "Rovesciando" << k;
	
	int inv = 0;
	while (k > 0)
	{
		int mod = k%10;
		k = (k-mod)/10; // E' uguale a fare k/10 poichè lavoriamo con divisioni intere
		inv = inv * 10;
		inv = inv + mod;
	}
	
	cout << " si ottiene " << inv;
}
