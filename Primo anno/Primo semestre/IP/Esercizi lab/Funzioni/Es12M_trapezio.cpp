/* Es_11 di base: Scrivere una funzione con due parametri di tipo intero che stampa il trapezio rettangolo fatto di `x' con le basi lunghe
quanto gli argomenti, e l’altezza pari alla differenza fra le basi più uno.
Si noti che data la scelta dell’altezza a ogni riga bisogna stampare un carattere in più.
[SUGGERIMENTO: usare la funzione replicate.]
*/

#include <iostream>
#include <cmath>

using namespace std;

struct OutOfRangeError{
	string paramName;
	int paramValue;
};

void replicate(int base, char c){

	if (base < 0)
	{
        OutOfRangeError err;

        err.paramName = "base";
        err.paramValue = base;
        throw err;
	}

	for (unsigned int i = 1; i<=base; ++i)
		cout << c;
}

void trapezio(float b1, float b2){

    float altezza = abs(b1-b2)+1;
	for (unsigned int i=1; i<=altezza; ++i)
	{
		replicate(b1, 'x');
		b1++;
		cout << endl;
	}
}

int main()
{
	try {
		cout << "Inserisci la base minore del trapezio: ";
		float bm;
		cin >> bm;
		cout << "Inserisci la base maggiore del trapezio: ";
		float bM;
		cin >> bM;
		trapezio(bm, bM);
	}
	catch(OutOfRangeError& err) {
		cout << "Errore nel parametro: '" << err.paramName << "' con valore: " << err.paramValue;
	}
}
