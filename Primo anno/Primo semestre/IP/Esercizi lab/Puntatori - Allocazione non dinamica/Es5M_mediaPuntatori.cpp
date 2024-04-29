// Es_5E: Modificare il programma che legge N valori reali, li memorizza in un array di lunghezza N, e ne restituisce la media richiesto
// dall’esercizio 4 della sezione 4 usando l’aritmetica dei puntatori per migliorarne l’efficienza, secondo il seguente schema


#include <iostream>

using namespace std;


int main()
{
    // dichiarare una costante N di tipo int inizializzata ad un valore...
	// ... strettamente maggiore di 0
	const int N = 3;
	// dichiarare un array v di N interi
	int v[N];
	// dichiarare un puntatore a interi p inizializzato con v
	int *p = v;
	/* iterare su i a partire da 0 e fino a N-1
	- leggere un valore intero memorizzandolo nella cella puntata da p
	- incrementate p
	*/
	for (unsigned int i = 0; i<=N-1; ++i){
		cin >> *p;
		p++;
	}
	// dichiarare una variabile sum di tipo float e inizializzarla a zero
	float sum = 0.0;
	// assegnare v a p (per ricominciare da capo a scorrere v)
	p = v;		// N.B. Se non avessi fatto p++ nel for ma es. *(p+i), dove p NON viene incrementato, non c'è bisogno di riportarlo all'indirizzo del primo el. dell'array, perchè è già lì.
	/* iterare su i a partire da 0 e fino a N-1
	- sommare il contenuto della cella puntata da p a sum
	*/
	for (unsigned int i = 0; i<=N-1; ++i){
		sum += *(p+i);  // Equivalente a incrementare in un'altra riga p++, o ancora sum += *p++; in quanto viene considerato prima il puntatore *p (e assegnato) e poi viene incrementato p++
	}
	// stampare la divisione di sum per N
	cout << "Media: " << sum/N << endl;
}
