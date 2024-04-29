/* Es_7 di base: Scrivere una funzione verifySymmetry che verifica se una matrice è simmetrica. La funzione torna true se la matrice passata
per argomento è simmetrica, false in caso contrario.
[HINT: una matrice simmetrica è una matrice QUADRATA i cui elementi sono simmetrici rispetto alla diagonale principale.
Es:
1 2 3
2 0 5
3 5 4 ]
Scrivere un programma di test che verifica il funzionamento della funzione sviluppata su una matrice NxN (con N costante
fissata).
*/

#include <iostream>

using namespace std;

int main()
{
	const int N = 3;
	int M[N][N];	// Dichiaro una matrice bidimensionale (quadrata), array di array

	cout << "Inserisci gli elementi della matrice" << N << " x " << N << endl;
	for (unsigned int i=0; i<N; ++i)
		for (unsigned int j=0; j<N; ++j)
			cin >> M[i][j];

	bool isSymmetric = true;
	for (unsigned int i=0; i<N; ++i)
		for (unsigned int j=0; j<N; ++j)
			if  (M[i][j] != M[j][i])
				isSymmetric = false;

	cout << "La matrice data " << (isSymmetric ? "e'" : "non e'") << " simmetrica" << endl;
}
