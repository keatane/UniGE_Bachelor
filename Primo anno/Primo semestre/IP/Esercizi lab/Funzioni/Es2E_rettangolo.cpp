// Es_2 di riscaldamento:  Scrivere una funzione che dati due float base e altezza, restituisce l’area del rettangolo di base base e altezza altezza. La
// funzione deve verificare che base e altezza siano valori positivi ed in caso contrario sollevare una eccezione di tipo int.

// Scrivere un programma per testare la funzione e “catturare” l’eccezione:


#include <iostream>

using namespace std;

float area(float base, float altezza) {
// se base non è positivo
	if (base < 0.0){
        // - dichiarare una variabile err di tipo int inizializzata a 1
		int err = 1;
		// - sollevare una eccezione con argomento err (throw err)
		throw err;
	}
	// se altezza non è positivo
	if (altezza < 0.0){
	// - dichiarare una variabile err di tipo int inizializzata a 2
	int err = 2;
	// - sollevare una eccezione con argomento err (throw err)
	throw err;
	}
	// restituire base x altezza
	return base*altezza;
}

int main()
{
	// dichiarare due variabili b e h di tipo float
	float b, h;
	// leggere b e h
	cout << "Inserisci il valore della base del rettangolo" << endl;
	cin >> b;
	cout << "Inserisci il valore dell'altezza del rettangolo" << endl;
	cin >> h;
	try {
		// dichiarare la variabile float a
		float a;
		// chiamare la funzione area assegnando ad a il valore che restituisce
		a = area(b, h);
		// stampare l'area
		cout << "Area rettangolo: " << a << endl;
	}
	catch (int& err) {
		// stampare un messaggio che indica un errore sul valore della...
		// ... base (se err==1) o dell'altezza (se err==2)
		if (err == 1)
			cout << "Errore nell'inserimento della base" << endl;
		if (err == 2)
			cout << "Errore nell'inserimento dell'altezza" << endl;
	}

}
