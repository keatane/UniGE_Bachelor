/* ordinamento.cpp

	Obiettivo: ordinamento in place (ossia senza copia, sovrascivo l'ordine)
	
	INPUT
	- sequenza arbitraria di elementi omogenei
	
	ALGORITMO
	- Selection Sort
	
	OUTPUT
	- sequenza ordinata in modo crescente
*/

#include <iostream>	

using namespace std;

const unsigned int DIM = 10;

int main()
{
	// Ordinati				Da ordinare
	// [1][3][5]	[7]		[6][10][11][12][9]
	//  i-1			i		 min
	// Giro successivo
	// [1][3][5][6]		[7][10][11][12][9]
	//  i-1				i		 min
	
	int smallest;
	for (unsigned int i=0; i<DIM;  ++i){	// Visita esterna della sequenza
		smallest = i;
		for (unsigned int mini = i+1; mini < DIM; ++mini)		// min (i)
			if (S[smallest] > S[mini])
				smallest = mini;			// Controllo dei valori, cerco il minimo valore (e ne registro l'indice)
		
		// Dopodichè ho uno swap di due variabili, ovvero fra il valore corrente e il minimo. N.B. Nel SELECTION SORT Le righe di swap sono fuori dal for interno.
		// Vado a sostituire nel valore attuale a[i] il minimo trovato a[smallest], e riparto col ciclo.
		temp = S[smallest];
		S[smallest] = S[i];
		S[i] = temp;
	}
	
}