/* Es_3 di riscaldamento: Scrivere una funzione void readMatrix(array2D& A) che permetta di riempire il campo data di A con valori letti. Questa
funzione assume che i campi rows e cols di A contengano rispettivamente il numero di righe e di colonne prima della
chiamata e inizializza il campo data con i valori inseriti dall’utente.
*/


#include <iostream>

using namespace std;

const int N = 3;
const int M = 3;

struct array2D {
	int data[N][M];
	unsigned int rows;
	unsigned int cols;
};

void readMatrix(array2D& A) {
	/* iterare sulle righe della matrice (indice i) fino al numero di righe di A
	*//* iterare sulle colonne della matrice (indice j) fino al numero di colonne di A
	- leggere un valore e memorizzarlo in A.data[i][j]
	*//*
	*/
	cout << "Inserisci i valori di una matrice " << N << " x " << M << endl;
	for (unsigned int i=0; i<A.rows; ++i){
		for (unsigned int j=0; j<A.cols; ++j)
			cin >> A.data[i][j];
	}

}

int main()
{
	array2D vett;
	vett.rows = N;
	vett.cols = M;
	readMatrix(vett);
	cout << endl;
	cout << "Matrice inserita: " << endl;
	for (unsigned int i=0; i<vett.rows; ++i){
		for (unsigned int j=0; j<vett.cols; ++j)
			cout << vett.data[i][j] << endl;
	}


}
