// Es_5 di riscaldamento:  Scrivere un programma che dati un array a di float che contiene una sequenza di valori decrescenti; la sua lunghezza N; e
// un valore intero i tra 0 e N, memorizza nell’elemento i-esimo il valore (1/2)*(i^2). Poi stampa l’array.
/*[SUGGERIMENTO: L’espressione 1/2, con 1 e 2 interi, ha valore 0. Però se anche solo un termine in una espressione ha tipo
floating point, tutta l’espressione viene convertita in floating point. La costante 2 se scritta 2.0 o anche 2. è una costante in
floating point.]
*/

#include <iostream>

using namespace std;

int main()
{
	// creaArrayInt
	// richiedere all'utente e leggere da input un valore di i
	// scrivere nell'elemento i-esimo di a il valore i quadrato mezzi
	// stampaArrayInt

	
	const int N = 10;

	float a[N];

	for (int i=0; i<N; i++){
		a[N-1-i] = (1/2.0)*(i*i);	// a[i] per averlo crescente, a[N-1-i] per averlo decrescente
	}
	
	for (int i=0; i<N; i++){
		cout << a[i] << endl;
	}

}