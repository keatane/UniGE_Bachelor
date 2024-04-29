// Scrivere una funzione con un argomento intero n che restituisce un booleano, true sse n è palindromo, ovvero se le sue cifre
// (in base 10) lette da destra a sinistra corrispondono alle cifre lette da sinistra a destra.
// [SUGGERIMENTO: usare la funzione reverse.]


#include <iostream>

using namespace std;

int reverse(int n){
	// dichiarare una variabile intera sign inizializzata con 1
	int sign = 1;
	// se k minore di zero
	if (n<0){
		// - assegnare -1 a sign
		sign = -1;
		// - assegnare -k a k
		n = -n; // Rendo positivo il numero k (-(-k) = +k), nella riga precedente ho già tenuto conto (registrato) il segno
	}
	// dichiarare una variabile intera inv inizializzata a zero
	int inv = 0;
	/* finché k è maggiore di zero
	- dichiarare una variabile intera mod inizializzata con
	il resto della divisione intera di k per 10
	- assegnare a k il quoziente di k per 10
	- assegnare a inv la moltiplicazione di inv per 10
	- assegnare a inv la somma di inv e mod
	*/
	while (n > 0)
	{
		int mod = n%10;
		n /= 10;
		inv *= 10;
		inv += mod;
	}
	// restituire inv moltiplicato per sign
	return inv*sign;
}

int main()
{
	bool isPalindrome = false;
	// stampare la stringa "Inserire un numero intero: "
	cout << "Inserire un numero intero: ";
	// dichiarare una variabile intera z
	int z;
	// leggere z
	cin >> z;
	if (z == reverse(z))
		cout << boolalpha << "Palindromo: " << !isPalindrome << endl; // !isPalindrome stampa true (contrario di false preregistrato in isPalindrome)
    else
        cout << "No palindromo" << endl;
}
