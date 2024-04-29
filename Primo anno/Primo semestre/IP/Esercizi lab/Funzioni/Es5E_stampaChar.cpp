// Es_5 di riscaldamento:  Scrivere una funzione che preso come argomento numero intero n strettamente positivo e un carattere stampa il carattere n volte.
// Dichiarare una struct OutOfRangeError con un campo stringa chiamato paramName e uno di tipo intero chiamato paramValue.


// Scrivere un programma per testare la funzione:

#include <iostream>
#include <string>

using namespace std;

struct OutOfRangeError{
	string paramName;
	int paramValue;
};

void replicate(int length, char c){
	// se length non è maggiore di zero
	if (length < 0)
	{
        // - dichiarare una variabile err di tipo OutOfRangeError
        OutOfRangeError err;
        // - inizializzare il campo paramName di err con la stringa 'length'
        err.paramName = "length";
        // - inizializzare il campo paramValue con il valore del parametro length
        err.paramValue = length;
        // - sollevare una eccezione con argomento err (throw err)
        throw err;
	}
	/* iterare su i a partire da 1 e fino a length
	- stampare c
	*/
	for (unsigned i = 1; i<=length; ++i)
		cout << c;
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
		// stampare la stringa "Inserisci il carattere da replicare: "
		cout << "Inserisci il carattere da replicare: ";
		// dichiarare una variabile c di tipo char
		char c;
		// leggere c
		cin >> c;
		// chiamare replicate su len e c
		replicate(len, c);
	}
	catch(OutOfRangeError& err) {
		// stampare un messaggio d'errore usando i campi di err per
		// visualizzare quale parametro contiene un errore e quale valora ha
		cout << "Errore nel parametro: '" << err.paramName << "' con valore: " << err.paramValue;
	}
}
