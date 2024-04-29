/* Es_20 avanzato: La tavola pitagorica è simmetrica, quasi metà di essa contiene informazione ripetuta. Precisamente, N(N−1)/2 elementi
sopra la diagonale sono uguali a N(N−1)/2 elementi sotto la diagonale.
Scrivere un programma che usa un array monodimensionale per rappresentare la tavola pitagorica usando solo gli N(N+1)/2
elementi necessari. Dal punto di vista dell’utente il programma deve comportarsi in modo identico a quello dell’esercizio 11.

!! NON TERMINATO
*/

#include <iostream>

using namespace std;

const int N = 10;
const int DIM = N*(N+1)/2;

int main()
{
	int index = 0;
    int tav[DIM] = {};

    for (int i=0; i<N; ++i){
        for (int j=i; j<N; ++j){
            tav[index++] = (i+1)*(j+1);
		}
    }



	int a, b;
	do{
	cout << "Inserisci una coppia di valori fra 1 e " << N << endl;
	cin >> a >> b;
	} while(a>N || a<1 || b>N || b<1);

	if (a < b){
		int tmp = a;
		a = b;
		b = tmp;
	}

	index = (N-1)*(b-1) + (a-1)-((b-1)*(b-2))/2; // conversione indice da 2D a 1D

	cout << "Prodotto: " << tav[index] << endl;
}
