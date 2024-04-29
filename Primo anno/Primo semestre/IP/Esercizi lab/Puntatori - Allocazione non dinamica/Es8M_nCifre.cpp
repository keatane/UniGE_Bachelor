/* Es_8 di base: Scrivere una funzione che preso un array v di N elementi (dove N è una costante positiva a vostra scelta) di tipo char restituisce
il numero di cifre, cioè caratteri nell’intervallo ['0','9'], in v, usando l’aritmetica dei puntatori per scorrere v.
Implementate entrambe le versioni: quella in cui gli array sono usati direttamente e quella in cui sono incapsulati assieme
alla loro lunghezza in una struct.
*/

#include <iostream>

using namespace std;


// VERSIONE 1: array
/*
const int N = 4;

int count(char a[N]){

	char *p = a;

	int counter = 0;
	for (unsigned int i=0; i<N; ++i)
		if (*(p+i) >= '0' && *(p+i) <= '9')
			counter++;
	return counter;
}

int main()
{
	char v[N];
    for (unsigned int i=0; i<N; ++i){
			cout << "Inserisci l'elemento " << i << endl;
			cin >> v[i];
		}

	cout << "Numero cifre: " << count(v) << endl;
}*/

// VERSIONE 2: struct

const int N = 4;

struct Array{

    char list[N];

    int size = N; //e da ora in poi faccio riferimento alla var size e non più a N, cosicchè posso aggiornare size se ho più valori (non potrei farlo con N const)
};

int count(Array v){

    char *p;
    p = v.list; // Faccio puntare il primo elemento dell'array nella var struct Array
	int counter = 0;
	for (unsigned int i=0; i<v.size; ++i)
		if (*(p+i) >= '0' && *(p+i) <= '9')
			counter++;
	return counter;
}

int main()
{
	Array a;
    for (unsigned int i=0; i<a.size; ++i){
			cout << "Inserisci l'elemento " <<  i << endl;
			cin >> a.list[i];
		}
	cout << "Numero cifre: " << count(a) << endl;
}



