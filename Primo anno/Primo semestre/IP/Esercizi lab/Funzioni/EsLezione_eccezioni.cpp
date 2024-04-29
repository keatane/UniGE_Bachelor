// Es_eccezioni (riferimento es 6 Funzioni)

// Creato da Cattaneo Kevin

#include <iostream>

using namespace std;

long factorial(int); // long = long int (aumento lo spazio se uso unsigned int)

int main() // Poichè ho un blocco unico all'interno del main, posso omettere le graffe
{
    try {
		int number;
		cout << "Inserisci un numero naturale" << endl;
		cin >> number;
		cout << number << "! = " << factorial(number) << endl;
	}

	catch(string& s) { // Passaggio con riferimento, non credo una variabile copia della var errore, ottimizzo gli spazi.
		cerr << s << endl; // Uso cerr, uno stream di output fatto apposta per raggruppare gli errori (al momento è equivalente al cout). Nel caso di un'analisi successiva dei log potrebbe essere utile.
	}
	catch(...){ // Sollevo un'eccezione la cui origine è sconosciuta, ma la catturo e la comunico
		cerr << "unknown ecception" << endl;
	}
}

long factorial(int n){
	long f=n;

	if (n<0){ // Prevedo l'eccezione, in modo tale da gestire l'errore e comunicarlo all'utente
		string err = "questa funzione opera su numeri naturali";
		throw err;	// Sollevo l'eccezione, tale istruzione fa uscire dalla funzione SENZA ritornare un valore
	}
	if (n==0) return 1;
	for (int i=f-1; i>1; --i)
		f *= i;
	return f;
}
