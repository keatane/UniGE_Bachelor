// Es_2 di riscaldamento: Scrivere una funzione void SelectionSort_vector(std::vector<int>& v) che effettui l’ordinamento di v secondo l’algoritmo SelectionSort

#include <iostream>
#include <vector>

using namespace std;

void readVector(std::vector<int>& v) {
	// Stampare "Inserisci la dimensione della sequenza: "
	cout << "Inserisci la dimensione della sequenza: ";
	// Dichiarare una variabile intera N
	int N;
	// Leggere N
	cin >> N;
	/* iterare N volte
	- leggere un valore intero
	- memorizzare il valore letto in v
	*/
	cout << "Inserisci " << N << " valori interi" << endl;
	for (unsigned int i = 0; i<N; ++i){
        int val;
        cin >> val;
        v.push_back(val); // Inserisco in fondo al vector l'elemento in input: automaticamente il push back ridimensiona il vectir
	}

}

void print_v(vector<int> v){
	for (unsigned int i=0; i<v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

void SelectionSort_vector(vector<int>& d){
	// dichiarare una variabile int greatestIndex
	/* iterare sul std::vector dalla prima all'ultima posizione
	- memorizzare in greatestIndex la posizione corrente (sia i)
	- *//* iterare sul std::vector dalla posizione successiva alla corrente ...
	... (i+1) fino all'ultimo elemento
	-- se il valore alla pos corrente (j) e' < del valore...
	... alla pos greatestIndex
	--- memorizzare j in greatestIndex
	*//*
	- scambiare il valore alla posizione i con quello alla pos greatestIndex
	*/
	int greatestIndex;
	for (unsigned int i=0; i<d.size(); ++i){
				int greatesIndex = i;
				for (unsigned int j=i+1; j<d.size(); ++j) // Gli elementi prima di i sono già stati ordinati, controllo gli elementi da i in poi e cerco il minimo, per poi sostituirlo nell'indice attuale i.
					if (d[j]<d[greatesIndex])
						greatesIndex = j;

				int temp = d[greatesIndex];
				d[greatesIndex] = d[i];
				d[i] = temp; // Posiziono nella posizione attuale l'elemento minimo (quindi il più piccolo)
			}
}

int main()
{
	// dichiarare un std::vector vect di interi
	vector<int> vect; // v è vuoto
	// chiamare la funzione readVector su vect
	readVector(vect);
	// chiamare la funzione printVector su vect
	cout << "Vector inserito: ";
	print_v(vect);
	// chiamare la funzione SelectionSort_vector su vect
	SelectionSort_vector(vect),
	// chiamare la funzione printVector su vect
	cout << "Vector ordinato: ";
	print_v(vect);
}
