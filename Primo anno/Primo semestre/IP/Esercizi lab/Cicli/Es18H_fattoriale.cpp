/* Scrivere un programma che legge un intero positivo e stampa il numero di zeri alla fine del suo fattoriale (in base 10) senza
calcolarne il fattoriale. Ad esempio su 5 stampa 1 perché 5! = 120, mentre su 11 stampa 2 perché 11! = 39,916,800. Si
noti che, siccome il fattoriale diventa rapidamente più grande dei numeri rappresentabili sul calcolatore, è molto importante
riuscire a calcolare quanto richiesto senza dover calcolare il fattoriale.
*/

#include <iostream>

using namespace std;

int main ()
{

    cout << "Inserisci un numero intero maggiore di zero\n";
    int n, zeri = 0;
    cin >> n;
    int aux = n; // Solo per la stampa finale
	for (n; n>4; n/= 5)
		zeri += n/5;

    cout << "Numero zeri del fattoriale di " << aux << " \212: " << zeri << endl;
}
