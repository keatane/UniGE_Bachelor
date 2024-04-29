// Es_10 di base: Scrivere un programma che definisce due valori costanti, M pari a 5 e N pari a 8. Dichiara poi un array bidimensionale a di
// dimensioni M×N, e lo riempie di valori 0.

#include <iostream>

using namespace std;

int main()
{
	const int N = 8;
	const int M = 5;

	int matrix[M][N];	//Righe x colonne

	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			matrix[i][j] = 0;
		}
	}

    // Lista di zeri verticale
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			cout << matrix[i][j] << endl; //
		}
	}

	/* Lista a griglia
	for (int i=0; i<M; i++){
		for (int j=0; j<N; j++){
			cout << matrix[i][j];
		}
		cout << endl;
	}
	*/
	
	/* Se volessi stampare una certa riga (es. la numero 2), faccio variare solo le colonne:
		
		for (int j=0; j<N; j++){
			cout << matrix[2][j] << endl; //Con la riga 2 fissata
		}

}
