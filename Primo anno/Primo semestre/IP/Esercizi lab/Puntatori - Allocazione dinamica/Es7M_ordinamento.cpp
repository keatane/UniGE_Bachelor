/* Es_7 di base (modificato): Scrivere la funzione d_array_sort che ordina un array dinamico d preso come parametro per riferimento. La funzione deve accettare due argomenti:
- l'array dinamico d
- una stringa s

La stringa vontiene il nome di un algortimo di ordinamento:
"bubblesort"
"selectionsort"
"insertsort"
...

Se la stringa contiene il nome di un algortimo noto, questo viene eseguito.
Altrimenti si solleva un'eccezione di tipo string.

*/


#include <iostream>

using namespace std;

struct dynamic_array {
    int* store; // andrà a puntare all'array sullo heap
    unsigned int size;
};

// Posso far creare l'array dinamico a una funzione

	dynamic_array create(int size){
		dynamic_array new_array;
		if (size<=0) throw string("invalid size");
		new_array.store = new int[size];
		new_array.size = size;
		return new_array;
	}
//*/
void read_d_array(dynamic_array& d) {

	int s = -1;
	while (s <= 0){
		cout << "Inserisci la dimensione del vettore\n";
		cin >> s;
	}

	d.size = s;
	d.store = new int[s];
	for (unsigned int i=0; i<s; ++i)
		d.store[i];
	for (unsigned int i=0; i<s; ++i){
		cout << "Inserisci un valore:";
		cin >> d.store[i];
	}
}

void print_d_array(const dynamic_array& d) {

	int* p = d.store;
	int lenght = d.size;

	for (unsigned int i=0; i<lenght; ++i){
		cout << *(p+i) << "\t";
	}
	cout << endl;
}


void BubbleSort(dynamic_array& d){
    int temp;
    for (unsigned int i=0; i<d.size; ++i)
        for (unsigned int j=0; j<d.size-1-i; ++j) // -i perchè quelli in fondo (a incremento) sono già ordinati, non vado a ricontrollarli, -1 perchè altrimenti j+1 va out of range (comunque il controllo sull'ultimo elemento (e l'eventuale scambio viene fatto)
        {
            if (d.store[j]<d.store[j+1]){ // Il più piccolo man mano va in fondo (viceversa cambiando con >)
                temp = d.store[j];
                d.store[j] = d.store[j+1];
                d.store[j+1] = temp;
            }
        }
}

/*Procedimento Insertion sort

16 30 24 7 25

16 ok
16 (30 > 16 ok)
16 30 24 ... 24 in temp:
16 -> 30 (temp = 24), il 30 viene spostato nell'index di 24
16 24 30 ..., 24 > 16? ok
16 24 30 7 ... e si procede a ordinare il 7 (confrontando con gli elementi precedenti)
7 16 24 30 25
7 16 24 25 ->30
*/

void InsertionSort(dynamic_array& d){

    for (unsigned int i=1; i<d.size; ++i)  // Il primo elemento è considerato ordinato

		if (d.store[i]<d.store[i-1]){

			int temp = d.store[i];
			int index = i;

			do{
				d.store[index] = d.store[index-1];
				index--; // Ogni volta che trovo un elemento da ordinare, shifto tutta la parte ordinata per fare spazio a quello nuovo
			}while(index>0 && d.store[index-1] > temp);
			d.store[index] = temp; // Inserisco l'elemento da ordinare nella posizione corrente
		}
}

void SelectionSort(dynamic_array& d){

		for (unsigned int i=0; i<d.size; ++i){
			int smallestIndex = i;
			for (unsigned int j=i+1; j<d.size; ++j) // Gli elementi prima di i sono già stati ordinati, controllo gli elementi da i in poi e cerco il minimo, per poi sostituirlo nell'indice attuale i.
				if (d.store[j]<d.store[smallestIndex])
                    smallestIndex = j;

			int temp = d.store[smallestIndex];
            d.store[smallestIndex] = d.store[i];
            d.store[i] = temp; // Posiziono nella posizione attuale l'elemento minimo (quindi il più piccolo)
		}
}


void d_array_sort(dynamic_array& d, string ord){
	int temp;
	if (ord == "bubblesort") BubbleSort(d);
	else if (ord == "insertionsort") InsertionSort(d);
	else if (ord == "selectionsort") SelectionSort(d);
	else throw string("no algorithm found"); // Così facendo non creo una variabile che occupa memoria, ma creo un valore che viene sollevato e catturato dal catch nel main. Valore che non rimane in memoria dopo essere stato catturato.
}



int main()
{
	try{
		dynamic_array D1;
		read_d_array(D1);
		print_d_array(D1);

        cout << "Inserisci metodo di ordinamento: ";
        string ordine;
        cin >> ordine;
		d_array_sort(D1, ordine);
		cout << endl;
		cout << "Array ordinato: ";
		print_d_array(D1);

	}

	catch (string& s) { // Gestisce tutte le eccezioni sollevate di tipo stringa (non importa quale nome) (relative alle eccezioni sollevate da questo try)
		cerr << s << endl;
	}
	catch (...) { // catch tipo pokèmon (catch them all, ovvero i restanti)
		cerr << "unknown error\n";
	}
}
