/* Es_11 di base: Scrivere un programma che definisce un valore costante, N pari a 10.
Dichiara poi un array bidimensionale tavolaPitagorica di dimensioni N×N, e lo riempie dei valori della tavola pitagorica,
dove l’elemento (i, j) contiene il prodotto tra i+1 e j+1 (perché? Perchè sto costruendo la tabellina fino al 10 escluso, una riga per N colonne (ovvero 10)).
Infine chiede all’utente una coppia di valori tra 1 e 10, e restituisce il loro prodotto – ottenuto consultando la tavola
pitagorica come una look-up table, e non eseguendo la moltiplicazione.
*/

#include <iostream>

using namespace std;

int main()
{
	const int N = 10;
	int tavolaPitagorica[N][N];

	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
			tavolaPitagorica[i][j] = (i+1)*(j+1);
	}

	/* Controllo
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
			cout << tavolaPitagorica[i][j] << " ";
		cout << endl;
	}
	*/

	int a, b;
	do{
	cout << "Inserisci una coppia di valori fra 1 e 10: \n";
	cin >> a >> b;
	} while(a>10 || a<1 || b>10 || b<1);

	cout << "Prodotto: " << tavolaPitagorica[a-1][b-1] << endl; // Non è necessario controllare tutto l'array, basta inserire la posizione in righe e colonne
																// del risultato precedentemente calcolato (ovvero il prodotto)
																// Inoltre bisogna ricordare che l'array registra i numeri dalla posizione (0,0) in cui è presente 1.
																// Dunque i fattori in questione hanno una posizione inferiore di 1, in quanto lo zero non è ammesso.

}
