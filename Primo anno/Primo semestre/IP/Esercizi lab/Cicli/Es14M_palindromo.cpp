// Es_14 di base: Scrivere un programma che chiede all’utente un numero intero e verifica se è palindromo, ovvero se le sue cifre (in base 10) lette da destra a sinistra corrispondono alle cifre lette da sinistra a destra (ad esempio 165373561 è palindromo). Dopo la verifica stampa il risultato all’utente.

#include <iostream>

using namespace std;

int main ()
{
	int k, kk;
	do{
		cout << "Inserire un numero positivo: " << endl;
		cin >> k;
		kk = k;
		if (k < 0)
			cout << "Valore non valido" << endl;
	}while (k<0);
	
	int inv = 0;
	while (k > 0)
	{
		int mod = k%10;
		k = (k-mod)/10; // E' uguale a fare k/10 poichè lavoriamo con divisioni intere
		inv = inv * 10;
		inv = inv + mod;
	}
	//cout << k << " " << " " << kk << " " << inv << endl;
	
	if (kk == inv) // Perchè ormai la variabile k non ha più il valore originale
		cout << "Palindromo" << endl;
	else
		cout << "No palindromo" << endl;
}
