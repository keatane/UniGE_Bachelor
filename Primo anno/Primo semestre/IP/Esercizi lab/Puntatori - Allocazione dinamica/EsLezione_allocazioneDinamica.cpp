// Es-lezione: allocazione dinamica
// Creato da Kevin Cattaneo il 16/11/2020.

#include <iostream>

using namespace std;

int main(){

	int M[4][3]; // 4 righe x 3 colonne

	for (unsigned int i=0; i<4; ++i)
		for (unsigned int j=0; j<3; ++j)
			M[i][j]=i-j;

	cout << "Matrice statica:\n";
	for (unsigned int i=0; i<4; ++i){
		for (unsigned int j=0; j<3; ++j)
			cout << M[i][j] << "\t";
		cout << endl;
	}

    int *ptr = &M[0][0]; // poichè bidimensionale, vado a puntare al primo elemento della matrice
	// Nota che il puntatore in questo momento sta puntando su un array già riempito
    cout << "Visita con puntatore\n";

    // In questo caso l'aritmetica dei puntatori sfrutta la contiguità di elementi (natura degli array) (gli elementi su "diverse" righe, in realtà sono uno dopo l'altro)
    // mantengo la formattazione a matrice
    /* Nota bene: in
        1 2 3
        4 5 6
        Il valore 1 ha posizione 0, il 3 ha pos 2, il 4 ha posizione 3! Quindi (vedi sotto) per la "riga" i = 1, prendo come primo elemento il terzo (0+3+0) = 3, poi il quarto e quinto.
    */
	for (unsigned int i=0; i<4; ++i){
		for (unsigned int j=0; j<3; ++j)
			cout << *(ptr+i*3+j) << "\t";
		cout << endl;
	}

	/*OPPURE (stampa lineare)
	for (unsigned int k=0; k<4*3; ++k){
			cout << *(ptr+k) << "\t";
	}
	*/
}




/* Esempio di array dinamico e MEMORY LEAK
int main(){

	int *p;
	p = new int [5]
	for (unsigned int i=0; i<5; ++i)
		p[i] = 3; // equivale a *(p+i)

	//p = nullptr; // scrivere subito così produce MEMORY LEAK in quanto la porzione con gli elementi viene persa (persi gli elementi, ma ANCHE lo spazio ancora allocato e non svuotato)
	delete [] p;
	p = nullptr;
}
*/
