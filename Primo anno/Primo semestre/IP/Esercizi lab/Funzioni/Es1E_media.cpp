// Es_1 di riscaldamento: Scrivere una funzione che prende come argomento un intero hm, legge hm numeri reali e ne restituisce la media.
// Scrivere un programma per testare la funzione try secondo il seguente algoritmo.


#include <iostream>

using namespace std;

float average(int hm){
// se hm non è positivo
if (hm < 0)
{
// - dichiarare una variabile err di tipo int
int err;
// - sollevare una eccezione con argomento err (throw err)
throw err;
}
// dichiarare una variabile sum di tipo float inizializzata a 0
float sum = 0;
// iterare hm volte le seguenti istruzioni
for (unsigned int i=0; i<hm; ++i)
{
	//- stampare un a capo seguito dalla stringa "Inserisci un numero "
	cout << "Inserisci un numero" << endl;
	//- dichiarare una variabile x di tipo float
	float x;
	//- leggere x
	cin >> x;
	//- assegnare a sum la somma di sum e x
	sum += x;
}
// restituire il risultato della divisione di sum per hm
return sum/hm;
}


int main()
{
    try {
	// stampare la stringa "Di quanti numeri vuoi fare la media?"
	cout << "Di quanti numeri vuoi fare la media?" << endl;
	// dichiarare una variabile how_many di tipo int
	int how_many;
	// leggere how_many
	cin >> how_many;
	// stampare un'andata a capo seguita dalla stringa "La media è "
	cout << endl << "La media e' ";
	// stampare il risultato della chiamata di average su how_many
	cout <<  average(how_many) << endl;
	}

	catch(int& err) {
		// stampare un messaggio d'errore
		cout << "///\nErrore: inserimento di numero negativo" << endl;
	}
}
