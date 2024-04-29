// Es_7 base: Scrivere un programma che chiede all’utente un numero reale e lo legge.Quindi, in cascata (ovvero usando il risultato di ciascuna operazione come argomento per la successiva), lo divide per 4.9,per 3.53 e per 6.9998. Poi, sempre in cascata, moltiplica per 4.9, per 3.53 e per 6.9998. Infine confronta il risultato ottenuto con il numero iniziale e se rappresentano due numeri reali diversi stampa "moltiplicare NON è l'inverso di dividere".

#include <iostream>

using namespace std;

int main()
{
	float n, m = 0.0; // Se metto tipo double riconosce m diverso da n
	cout << "Inserisci un numero reale" << endl;
	cin >> n;
	
	m = n;
	
	n /= 4.9;
	n /= 3.53;
	n /= 6.9998;
	
	n *= 4.9;
	n *= 3.53;
	n *= 6.9998;
	
	
	if (m != n)
		cout << "Moltiplicare NON e' l'inverso di dividere" << endl;
	else
		cout << "END" << endl;

}
