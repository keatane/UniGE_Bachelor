/* Es_2 di riscaldamento: stampaArrayInt, Stampa un array di interi. Scrivere un programma che, dati un array a di int e la sua lunghezza N, stampa
tutto l’array.
*/


#include <iostream>

using namespace std;

int main()
{
	// Creare e popolare un array a di lunghezza N.
	// per la variabile intera i che va da 0 incluso a N escluso:
	
	const int N = 10;
	int a[N];
	for (int i=0; i<N; i++){
		a[i] = N-i;
	}
		
	// stampare l'elemento i-esimo di a
	// stampare un a-capo
	for (int i=0; i<N; i++){
		cout << "In posizione " << i << " il valore e' " << a[i] << endl;
	}
	
}
