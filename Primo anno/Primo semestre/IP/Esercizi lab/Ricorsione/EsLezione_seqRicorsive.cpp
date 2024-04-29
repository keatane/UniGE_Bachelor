// Es in lezione: sequenze ricorsive

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int DIM=5;

// funzione void visita ricorsiva e stampa
void print_seq(int A[], int size){ // n.b. l'indice più grande è size-1
	if (size<0) throw 42;
	if (size==0)
		return; // non ho più alcun elemento da stampare

    // Print reverse
	//cout << A[size-1] << " ";
	//print_seq(A,size-1);

	// Print direct
	print_seq(A,size-1);
    cout << A[size-1] << " ";
}

// funzione int calcolo prodotto elementi (analogo a somma)
int prod_seq(int A[], int size){
	if (size<=0) throw 42; // devo gestire anche la situazione in cui l'operazione si applica sul vuoto
	if (size==1) return A[size-1]; // PASSO BASE // unico elemento ancora disponibile // Equivale ad A[0];
	return prod_seq(A,size-1)*A[size-1]; // PASSO INDUTTIVO
}

int somma_seq(int A[], int size) {
    if (size<=0) throw 42;
    if (size==1) return A[size-1];
    return A[size-1]+somma_seq(A,size-1);
}

// funzione int calcolo il minimo (analogo a max)
// ATTENZIONE
int min_seq(int A[], int size){
    if (size<=0) throw 42;
	if (size==1) return A[size-1]; // base

    return (min_seq(A,size-1) < A[size-1] ? min_seq(A,size-1) : A[size-1]);
   // return min(A[size-1],min_seq(A,size-1)); // PASSO INDUTTIVO: confronto il valore di indice più piccolo con il valore di indice successivo crescente
}

/* Seconda versione: nel caso di size = 3 dove l'array è
index 0 1 2
      4 5 7

return min(A[size-1],min_seq(A,size-1))
        min (A[2],min_seq(A,2))
                    min(A[1],min_seq(A,1))
                                size==1 -> A[0]
                        5                   4
                7       4
                    4 è il minimo

*/

bool pal_seq(int A[], int size){
    if (size<=0) throw 42;
	if (size==1) return true; // base

	if (size%2 == 0)
        return (somma_seq(A,(size/2) == (somma_seq(A,size)-somma_seq(A,size/2))));
    else
        return (somma_seq(A,size/2) == (somma_seq(A,size)-somma_seq(A,(size/2)+1)));
}


int main()
{
	int v1[DIM] = {2,3,4,3,2};
	int v2[DIM] = {2,16,4,1,8};

	print_seq(v1,DIM);
	cout << endl;
	cout << "prodotto: " << prod_seq(v1,DIM) << endl;
	cout << "somma: " << somma_seq(v1,DIM) << endl;
	cout << "minimo: " << min_seq(v1,DIM) << endl;
	cout << "palindromo: " << boolalpha << pal_seq(v1,DIM) << endl;

    cout << endl;

	print_seq(v2,DIM);
    cout << endl;
	cout << "prodotto: " << prod_seq(v2,DIM) << endl;
	cout << "minimo: " << min_seq(v2,DIM) << endl;
	cout << "somma: " << somma_seq(v2,DIM) << endl;
	cout << "palindromo: " << boolalpha << pal_seq(v2,DIM) << endl;
}

