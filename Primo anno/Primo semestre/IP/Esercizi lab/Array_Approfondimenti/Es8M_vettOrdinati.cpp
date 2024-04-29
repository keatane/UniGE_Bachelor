/*Scrivere una funzione che riceva in ingresso due vettori di interi. Dopo aver ordinato i due vettori in ingresso in maniera
crescente ([HINT: utilizzate le funzioni sviluppate negli esercizi precedenti!]) la funzione deve riempire un terzo vettore
(passato anch’esso per argomento) in modo che contenga tutti gli elementi dei due vettori ordinati tra loro in modo crescente. Attenzione: nel costruire il terzo vettore tenete conto del fatto che i due vettori di partenza sono stati precedentemente
ordinati.
Ad esempio, se il primo vettore contiene gli elementi
2 5 9 14 15 20 25 27 30
e il secondo vettore contiene gli elementi
3 5 10 11 12 22 23 24 26 27
la funzione riempie il terzo vettore con i seguenti elementi
2 3 5 5 9 10 11 12 14 15 20 22 23 24 25 26 27 27 30.
*/

#include <iostream>

using namespace std;

const int DIM = 5;

struct array {
	int data[DIM];
	unsigned int size;
};


void readArray(array& A) {

	cout << "Inserisci " << DIM << " valori nell'array\n";
	for (unsigned int i=0; i<DIM; ++i)
		cin >> A.data[i];

}


void printArray(const array& A) {

	for (unsigned int i=0; i<A.size; ++i)
		cout << A.data[i] << (i == A.size-1 ? "\n" : " ");

}

void orderArray(array& d) {

    int temp;
	int minIndex;
		for (unsigned int i=0; i<d.size; ++i){
            minIndex = i;
			for (unsigned int j=i+1; j<d.size; ++j)
				if (d.data[j]<d.data[minIndex]) // Il più piccolo viene posto all'inizio ((viceversa cambiando con >)
                    minIndex = j;

			temp = d.data[i];
            d.data[i] = d.data[minIndex];
            d.data[minIndex] = temp;
		}
}

int main()
{
	// Creo gli array
	array vett1;
	vett1.size = DIM;
	readArray(vett1);
	array vett2;
    vett2.size = DIM;
	readArray(vett2);


	// Stampa pre-ordinati
	cout << "Array pre-ordinati\n";
	printArray(vett1);
	printArray(vett2);

	// Ordino gli array
	orderArray(vett1);
	orderArray(vett2);

	// Stampa ordinati
	cout << "Array ordinati\n";
	printArray(vett1);
	printArray(vett2);


}
