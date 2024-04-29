// Es_1 di riscaldamento: creaArrayInt, Crea un array di prova con elementi di tipo int. Scrivere un programma che dichiara un array v di N interi
// e lo “popola” (assegna valori ai suoi elementi).

#include <iostream>

using namespace std;

int main()
{
	// Dichiarare una costante N con valore 10
	const int N = 10;
	// Dichiarare un array a di N interi
	int a[N];
	// Iterare sulla variabile intera i a partire da 0 e fino a N escluso:
	for (int i=0; i<N; i++){
	// Assegnare all'elemento i-esimo di a il valore N-i
		// cout << "Valore prima: " << v[i] << endl;
		a[i] = N-i;
		// cout << "Valore dopo: " << v[i] << endl;
		}

}


/*N.B. Se l'array non viene inizializzato, nel valore a[i] prima di inserire un valore, viene inserito un valore del tutto casuale.
Mentre anche solo inizializzare con a[N] = {} (parentesi graffe vuote), ottengo un'inizializzazione di tutti gli elementi i-esimi a zero.
*/