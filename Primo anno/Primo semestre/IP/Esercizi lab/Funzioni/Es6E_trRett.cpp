// Es_6 di riscaldamento:   Scrivere una funzione che preso come argomento numero intero strettamente positivo stampa un triangolo rettangolo fatto
// di '*' con lato lungo quanto il numero letto.

// Scrivere un programma per testare la funzione:


#include <iostream>

using namespace std;

void replicate(int length, char c){

	for (unsigned i = 1; i<=length; ++i)
		cout << c;
}

void triangle(int length){
	// se len non è maggiore di zero
	if (length<0)
	{
		// - dichiarare una variabile err di tipo int
		int err;
		// - sollevare una eccezione con argomento err (throw err)
		throw err;
	}
	/* iterare su i a partire da 1 e fino a length
	- chiamare replicate su i e '*'
	- stampare un a capo
	*/
	for (unsigned i=1; i<=length; ++i)
	{
		replicate(i, '*');
		cout << endl;
	}
}


int main()
{
	try {
		// stampare la stringa "Inserisci un numero maggiore di 0: "
		cout << "Inserisci un numero maggiore di 0: ";
		// dichiarare una variabile len di tipo int
		int len;
		// leggere len
		cin >> len;
		// chiamare triangle su len
		triangle(len);
	}
	catch(int& err) {
		// stampare un messaggio di errore
		cout << "Errore: input negativo" << endl;
	}

}
