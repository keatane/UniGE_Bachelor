/* Es_4 di riscaldamento: Scrivere un programma che, letta una matrice A quadrata di dimensione 2x2, calcoli il determinante di tale matrice. Per
questo esercizio usate direttamente gli array bidimensionali senza incapsularli in una struct. Scrivere una funzione per la
lettura dei dati della matrice (analoga a void readMatrix(array2D& A)) e una funzione per il calcolo del determinante. Per
quest’ultima funzione non vi forniamo il prototipo della funzione, ma un’idea dell’algoritmo:

*/


#include <iostream>

using namespace std;

void readMatrix(int A[2][2]) {
	/* iterare sulle righe della matrice (indice i) fino al numero di righe di A
	*//* iterare sulle colonne della matrice (indice j) fino al numero di colonne di A
	- leggere un valore e memorizzarlo in A.data[i][j]
	*//*
	*/
	cout << "Inserisci i valori di una matrice " << 2 << " x " << 2 << endl;
	for (unsigned int i=0; i<2; ++i){
		for (unsigned int j=0; j<2; ++j)
			cin >> A[i][j];
	}

}

int determinante(int A[2][2]){
    // dichiarare una variabile det
    int det;
    // assegnare a det A[0][0]*A[1][1]-A[0][1]*A[1][0]
    det = A[0][0]*A[1][1]-A[0][1]*A[1][0];
    // ritornare det
    return det;

}
int main()
{
	int vett[2][2];
	readMatrix(vett);
	cout << endl;
	cout << "Matrice inserita: " << endl;
	for (unsigned int i=0; i<2; ++i){
		for (unsigned int j=0; j<2; ++j)
			cout << vett[i][j] << endl;
	}

	cout << "Determinante matrice: " << determinante(vett) << endl;
}
