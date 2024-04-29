// Es_8 di riscaldamento:   Scrivere una funzione con un parametro intero k che restituisce il numero ottenuto leggendo k da destra verso sinistra. Ad
// esempio su 17 restituisce 71, su 27458 restituisce 85472 e così via.


// Scrivere un programma per testare la funzione


#include <iostream>

using namespace std;

int reverse(int k){
	// dichiarare una variabile intera sign inizializzata con 1
	int sign = 1;
	// se k minore di zero
	if (k<0){
		// - assegnare -1 a sign
		sign = -1;
		// - assegnare -k a k
		k = -k; // Rendo positivo il numero k (-(-k) = +k), nella riga precedente ho già tenuto conto (registrato) il segno
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
	while (k > 0)
	{
		int mod = k%10;
		k /= 10;
		inv *= 10;
		inv += mod;
	}
	// restituire inv moltiplicato per sign
	return inv*sign;
}

int main()
{
	// stampare la stringa "Inserire un numero intero: "
	cout << "Inserire un numero intero: ";
	// dichiarare una variabile intera z
	int z;
	// leggere z
	cin >> z;
	// stampare su una nuova riga la stringa "Rovesciando " seguita da z
	cout << "\nRovesciando " << z;
	// stampare la stringa " si ottiene " seguita dal risultato della chiamata di...
	// ... reverse su z
	cout << " si ottiene " << reverse(z) << endl;

}
