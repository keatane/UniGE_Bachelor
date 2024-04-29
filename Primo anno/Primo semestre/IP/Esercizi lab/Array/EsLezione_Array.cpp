// Es in classe sugli Array
// 19/10/2020

#include <iostream>
#include <limits>

using namespace std;

const unsigned int DIM = 10;

int main()
{
	//dichiarare un array di interi
	int A[DIM] = {5,6,1,2,3,6,12,5,2,1};

	cout << "Ecco il mio primo array: \n";
	// cout << A Non stampa ciò che desidero (non stampa gli elementi degli array)

	for (unsigned int i=0; i<DIM; i++)
		cout << A[i] << "  ";
	cout << endl;

    // Calcolo la somma degli elementi
    int sum = 0;
    for (unsigned int i=0; i<DIM; i++)
        sum += A[i];
	cout << "Somma numeri: " << sum << endl;

	// Costruire la copia dell'array con contenuto ribaltato
	int Arev[DIM];
	for (unsigned int i=0; i<DIM; i++)
        Arev[DIM-1-i] = A[i]; // E' uguale a scrivere Arev[i] = A[DIM - 1 - i]
	cout << endl;

	// Ciò che ottengo è il seguente:
	// A: 5,6,1,2,3,6,12,5,2,1
	// Arev: 1,2,5,12,6,3,2,1,6,5

	// A[0] --> Arev[DIM-1] = Arev[DIM-1-0]
	// A[1] --> Arev[DIM-2] = Arev[DIM-1-1]
	// A[2] --> Arev[DIM-3] = Arev[DIM-1-2]
	//...
	// A[DIM-1] --> Arev[0] = Arev[DIM-1-DIM+1] = Arev[0]

	for (unsigned int i=0; i<DIM; i++) // Stampo Arev
		cout << Arev[i] << "  ";
	cout << endl;

	// Calcolare il valore massimo dell'array e la sua posizione nell'array
	int nMax = INT_MIN, idx_max = 0;  // Per nMax, come valore più piccolo (per far risultare true l'if che segue, scelgo una costante presa dalla libreria (nel mondo degli interi, il N più piccolo
                                           // Non è zero, ma meno infinito, in informatica uso tale costante prefissata.
	for (unsigned int i=0; i<DIM; i++)      //Esploro TUTTO l'array
        if (A[i] > nMax)
           {
                nMax = A[i];                //Tengo traccia del valore max
                idx_max = i;                      // Tengo traccia dell'indice del nMax, assicurandomi di assegnarla a un'altra variabile, poichè l'indice i cambia durante l'esplorazione dell'array.
           }
    cout << "Numero max: " << nMax << ", il suo indice: " << idx_max << endl;

}
