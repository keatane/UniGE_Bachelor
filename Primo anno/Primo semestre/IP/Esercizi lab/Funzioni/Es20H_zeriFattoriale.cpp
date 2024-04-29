/* Scrivere una funzione con un argomento intero n che restituisce il numero di zeri alla fine del fattoriale (in base 10) del
suo argomento senza calcolarne il fattoriale. Ad esempio su 5 stampa 1 perché 5 = 120, mentre su 11 stampa 2 perché
11! = 39 916 800.
*/

#include <iostream>

using namespace std;

int stampaZeriFattoriale(int n){

	int zeri = 0;
	for (n; n>4; n/= 5)
		zeri += n/5;
	return zeri;
}

int main ()
{
    cout << "Inserisci un numero intero maggiore di zero\n";
    int n;
    cin >> n;
    cout << "Numero zeri del fattoriale di " << n << " \212: " << stampaZeriFattoriale(n) << endl;
}
