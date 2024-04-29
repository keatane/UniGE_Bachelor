/* Es_6 di riscaldamento: Scrivere una funzione delRowCol che prenda in ingresso una matrice NxN, un indice di riga ed un indice di colonna, e
restituisca (passandola come ulteriore argomento) una matrice (N-1)x(N-1) ottenuta eliminando la colonna e riga indicate.
Definire i tipi struct necessari per rappresentare rispettivamente le matrici NxN e quelle (N-1)x(N-1).
Verificare che gli indici della riga e colonna da eliminare siano coerenti rispetto alla dimensione delle matrici in ingresso. Se
non lo sono, sollevare eccezioni di tipo diverso per distinguere l’errore dato da un indice negativo da quello dovuto a indice
troppo grande.
Scrivere un programma di test che verifica il funzionamento della funzione sviluppata e gestisce in maniera opportuna le
eventuali eccezioni, definendovi opportune struct per rappresentare i possibili tipi di errore.


*/


#include <iostream>

using namespace std;

const int N = 3;

struct array2D {
	int data[N][N];
	unsigned int rows;
	unsigned int cols;
};

struct array2Dmin {
	int data[N-1][N-1];
	unsigned int rows;
	unsigned int cols;
};

void delRowCol (array2D& A, array2Dmin& B, int row, int col){

	// Rimuovo la riga
	for (unsigned int i=row; i<A.rows-1; ++i)		// Non devo considerare l'ultima riga
		for (unsigned int j=0; j<A.cols; ++j)
			A.data[i][j] = A.data[i+1][j];

	// Rimuovo la colonna
	for (unsigned int i=0; i<A.rows-1; ++i)		// Non devo considerare l'ultima riga
		for (unsigned int j=col; j<A.cols-1; ++j)	// Non devo considerare l'ultima colonna
			A.data[i][j] = A.data[i][j+1];

	// Popolo B
	for (unsigned int i=0; i<A.rows-1; ++i)
		for (unsigned int j=0; j<A.cols-1; ++j)
			B.data[i][j] = A.data[i][j];
}


void readMatrix(array2D& A) {
	/* iterare sulle righe della matrice (indice i) fino al numero di righe di A
	*//* iterare sulle colonne della matrice (indice j) fino al numero di colonne di A
	- leggere un valore e memorizzarlo in A.data[i][j]
	*//*
	*/
	cout << "Inserisci i valori di una matrice " << N << " x " << N << endl;
	for (unsigned int i=0; i<A.rows; ++i){
		for (unsigned int j=0; j<A.cols; ++j)
			cin >> A.data[i][j];
	}

}

int main()
{
    try{
        array2D vett;
        array2Dmin vettMin;
        vett.rows = N;
        vett.cols = N;
        vettMin.rows = N-1;
        vettMin.cols = N-1;
        readMatrix(vett);
        cout << endl;
        cout << "Matrice inserita: " << endl;
        for (unsigned int i=0; i<vett.rows; ++i){
            for (unsigned int j=0; j<vett.cols; ++j)
                cout << vett.data[i][j];
            cout << endl;
        }

        cout << endl;
        cout << "Inserisci gli indici di riga e colonna da eliminare: ";
        int delR, delC;
        cin >> delR >> delC;
        if (delR < 0 || delR > vett.rows-1 || delC < 0 || delR > vett.cols-1){  // N.B. rows e cols sono delle dimensioni in base ai calcoli che vengono effettuati, quindi gli indici saranno uno in meno
            string OutOfRange = "Un valore di riga o colonna inserito e' fuori range dalla matrice";
            throw OutOfRange;
        }

        delRowCol(vett, vettMin, delR, delC);

        cout << endl;
        cout << "Matrice ridotta: " << endl;
        for (unsigned int i=0; i<vettMin.rows; ++i){
            for (unsigned int j=0; j<vettMin.cols; ++j)
                cout << vettMin.data[i][j];
            cout << endl;
        }
    }
    catch(string& OutOfRange){
        cout << OutOfRange << endl;
    }



}
