/* Es_3 di base: Scrivere la funzione delete_d_array che preso il riferimento ad un array dinamico d lo svuota, ovvero se d.size è positivo
rilascia lo spazio allocato per d.store e assegna zero a d.size. Altrimenti, solleva un’eccezione (di tipo opportuno, nel
definirla tenete conto che si tratterebbe di una doppia delete dello stesso puntatore).
Nota. Nel programma di test potete facilmente verificare se due chiamate di delete_d_array successive su uno stesso array
dinamico d (inizializzato con read_d_array) sollevano un’eccezione. Non avete invece modo di verificare da programma che
lo spazio sia effettivamente stato rilasciato. Per farlo potete però usare programmi che controllano che non ci siano memory
leak, come ad esempio valgrind (http://www.valgrind.org/) che trovate già installato sulle macchine di laboratorio.
*/

#include <iostream>

using namespace std;

struct dynamic_array {
    int* store; // andrà a puntare all'array sullo heap
    unsigned int size;
};

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

void delete_d_array (dynamic_array &d){
	if (d.size > 0){
		delete[] d.store;
		d.size = 0;
	}
	else{
		string err = "Doppia deallocazione";
		throw err;
	}
}


int main()
{
	try{
		dynamic_array D1;
		read_d_array(D1);
		print_d_array(D1);
				D1.size = 0;
		delete_d_array(D1);
		cout << "Array:";

		print_d_array(D1);

	}

	catch (string& s) { // Gestisce tutte le eccezioni sollevate di tipo stringa
		cerr << s << endl;
	}
	catch (...) {
		cerr << "unknown error\n";
	}
}
