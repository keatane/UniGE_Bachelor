/* Es_2 di riscaldamento: stampaArrayFloat, Stampa un array di float. Scrivere un programma che, dati un array a di float e la sua lunghezza N, stampa
tutto l’array.
*/


#include <iostream>

using namespace std;

int main()
{
	// Creare e popolare un array a di lunghezza N.
	// per la variabile intera i che va da 0 incluso a N escluso:
	
	const int N = 10;
	float a[N];
	for (int i=0; i<N; i++){
		a[i] = N-i;
	}
		
	// stampare l'elemento i-esimo di a
	// stampare un a-capo
	for (int i=0; i<N; i++){
		cout << "In posizione " << i << " il valore e' " << a[i] << endl;
	}
	
}
