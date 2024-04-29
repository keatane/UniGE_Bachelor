// Es_2 di riscaldamento: aritmetica dei puntatori

#include <iostream>

using namespace std;


int main()
{
    // dichiarare una costante N intera inizializzandola a un valore moderato ...
	// ...( p.es. 5 o 10)
	const int N = 5;
	// dichiarare una variabile v di tipo puntatore a int
	int* v;
	// allocare una quantità di memoria pari a N int , assegnandola a v
	v = new int[N];
	// scrivere nella memoria puntata da v la sequenza di valori ...
	// ... 1, 3, 5, ... , 2*N -1 (i primi N dispari )
	for (unsigned int i=0; i<N; ++i)
		v[i] = 2*i+1;
	// stampare v usando l'aritmetica dei puntatori
	for (unsigned int i=0; i<N; ++i)
		cout << v[i] << "  ";	// oppure *(v+i)
	// deallocare v
	delete[] v;
	cout << endl;
	// allocare una quantità di memoria pari a 2*N int , assegnandola a v
	v = new int[2*N];
	// scrivere nella memoria puntata da v la sequenza di valori ...
	// ...1 , 3, 5, ... , 4*N -1 (i primi 2*N dispari )
	for (unsigned int i=0; i<2*N; ++i)
		v[i] = 2*i+1;
	// stampare v usando l'aritmetica dei puntatori
	for (unsigned int i=0; i<2*N; ++i)
		cout << v[i] << "  ";
	// deallocare v
	delete[] v;
}
