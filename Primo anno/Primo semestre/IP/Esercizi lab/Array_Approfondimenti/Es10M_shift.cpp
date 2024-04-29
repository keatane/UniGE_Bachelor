/* Es_10 di base:  Scrivere due funzioni shiftLeft e shiftRight, che eseguano lo shift degli elementi di un vettore (passato in ingresso) verso
sinistra e verso destra, rispettivamente.
Ad esempio dato il vettore: 1 10 15 18 se si shifta a sinistra si deve generare il vettore: 10 15 18 0, se si shifta a destra deve
generare 0 1 10 15.

*/

#include <iostream>

using namespace std;

const int N = 4;

int main()
{
	int vett[N] = {};

    cout << "Popola l'array" << endl;
    for (unsigned int i=0; i<N; ++i)
			cin >> vett[i];

    // Creo un array copia
    int copia[N];
    for (unsigned int i=0; i<N; ++i)
			copia[i] = vett[i];

    // Shift Left
	for (unsigned int i=0; i<N-1; ++i) // L'ultimo elemento lo gestisco a parte
		vett[i] = vett[i+1];
	vett[N-1] = 0;

	// Shift Right
	int copia2[N];
	for (unsigned int i=0; i<N; ++i)
			copia2[i] = copia[i];
	for (unsigned int i=1; i<N; ++i) // Il primo elemento lo gestisco a parte
        copia[i] = copia2[i-1];
	copia[0] = 0;

	cout << "Shift Left: ";
	for (unsigned int i=0; i<N; ++i)
			cout << vett[i] << "  ";
	cout << endl;

	cout << "Shift Right: ";
	for (unsigned int i=0; i<N; ++i)
			cout << copia[i] << "  ";
	cout << endl;

}
