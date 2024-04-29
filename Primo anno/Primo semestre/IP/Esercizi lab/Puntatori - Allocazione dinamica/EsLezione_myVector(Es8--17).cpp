/* Es in lezione (es. avanzati 8-9-10): resizing di array con uno stream di valori a runtime, in "push-back" ovvero ponendo in fondo all'array tale valori. La dimensione effettiva è sconosciuta.
Size sarà la dimensione operativa, la capacity è la dimensione "nascosta" (l'utente mai accede ad essa), effettiva (massimo occupabile)
*/

#include <iostream>

using namespace std;

struct my_vector {
    int* store; // andrà a puntare all'array sullo heap
    unsigned int size;
	unsigned int capacity;
};

bool looks_consistent(const my_vector& v){
    return (v.store != 0 && 0 <= v.size && v.size <= v.capacity && 0 < v.capacity);
}

void read_d_array(my_vector& d) {

    if (looks_consistent(d) == false) throw bool(false);
	cout << "Inserisci la dimensione del vettore\n";
	cin >> d.size;
	d.capacity = d.size*2;
	int *T = new int[d.size];
	d.store = T;
	for (unsigned int i=0; i<d.size; ++i){
		cout << "Inserisci un valore:";
		cin >> d.store[i];
	}
}

// costruiamo il vector VUOTO (non numeri zero)

void create(my_vector &v, unsigned int capacity){

	v.capacity = capacity;
	int *T = new int[v.capacity];
	v.store = T;
	v.size = 0; // dimensione 0, quindi non occupa memoria

}

bool is_empty(const my_vector &v){
    if (looks_consistent(v) == false) throw bool(false);
	return (v.size==0);
}

void push_back(my_vector &v, int value){
    if (looks_consistent(v) == false) throw bool(false);
	// Controllo se in memoria (nascosta) capacity non è piena
	if (v.capacity == v.size)
			throw int(-1);

	if (v.size < v.capacity){

		*(v.store+v.size) = value; // Registro alla fine il valore // Equivale a v.store[v.size] = value; Ricorda che v.store contiene l'indirizzo (posizione) del primo elemento
		// N.B. i valori dell'array sono registrati fino a v.size-1, dunque in posizione v.size non rischio di sovrascrivere un valore già inserito
		v.size++; // Incremento la memoria operativa" occupata
	}
}

// duale di push-back: elimina l'elemento in fondo
int pop_back(my_vector &v){
    if (looks_consistent(v) == false) throw bool(false);
	if (v.size == 0){ // ovvero vector vuoto
		string err = "pop_back: illegal operation, vector is empty";
		throw err;
	}
    int aus = v.store[v.size-1];
    v.size--;
	return aus;
}

void print_d_array(const my_vector& d) {
    if (looks_consistent(d) == false) throw bool(false);
	int* p = d.store;
	int lenght = d.size;

	for (unsigned int i=0; i<lenght; ++i){
		cout << *(p+i) << "\t";
	}
	cout << endl;

}



//  Inserire (impostare) il valore value nella posizione index dell'array d
void set(my_vector &d, int index, int value) {
    if (looks_consistent(d) == false) throw bool(false);
	// Verifico che index sia un valore lecito: compreso fra zero e d.size-1;
	string err = "Out of range error";
	if ((index < 0) || (index >= d.size)) throw err;
	// Altrimenti continua il programma
    *(d.store+index) = value;
}

/*
	La funzione legge e restituisce il contenuto dell'array dinamico nella posizione index
*/
// N.B. Ho fatto un passaggio per riferimento costante con 'const dynamic_array &d': visto che devo SOLO leggere;
// non creo copie (inutili) e inoltre vieto la possibilità di modificare accidentalmente il contenuto.
int get(const my_vector &d, int index) {
    if (looks_consistent(d) == false) throw bool(false);
	//Verifica di index
	string err = "Out of range error";
	if ((index < 0) || (index >= d.size)) throw err;

	return *(d.store+index); // == d.store[index];
}

void destroy(my_vector& v){
    if (looks_consistent(v) == false) throw bool(false);
	// Deallochiamo lo spazio
	delete[] v.store;
	// Elimino l'eventualità di un dangling pointer
	v.store = 0;

	v.size = 0;
	v.capacity = 0;
}



/*
	Variare le dimensioni di un array pre-esistente
	Alla fine dell'esecuzione d avrà la nuova dimensione new_size
	//due casi: new_size > d.size oppure new_size < d.size. La seconda è un po' più distruttiva ma lecita, basta esserne consapevoli

	// array: le sue celle (entry) sono contigue in memoria
*/

void resize(my_vector &d, unsigned int new_size){
    if (looks_consistent(d) == false) throw bool(false);
	// N.B: gli array non posso essere ridimensionati in modo diretto, dunque faccio una copia in un altro array, per poi svuotare e di fatto modificare "da nuovo" l'array originale, riempiendolo nuovamente (evito di tenere celle in memoria occupati).
	// Per una questione di sicurezza, difficilmente ci è permesso dal programma di modificare la dimensione riducendola, proprio perchè si rischia di perdere valori.
	int *T = new int[new_size];
	for (unsigned int i=0; i<d.size; ++i)
		if (i<new_size) // Altrimenti vengono inseriti in T valori out of range rispetto a d (è utile se new_size è minore)
			*(T+i) = *(d.store+i);
	delete [] d.store;
	d.store = T;
	d.capacity = new_size;
}



int main()
{
    my_vector D1;
	try{

		create(D1, 5);
		read_d_array(D1);
		print_d_array(D1);
		cout << "\nInserimento valore 5: " << endl;
		push_back(D1,5);
		print_d_array(D1);
		cout << "\nIntegrita' array: " << boolalpha << looks_consistent(D1) << endl;

		//set(D1,3,1);
		//cout << get(D1,0) << endl;
		// N.B. Stampare il valore D1.store[3] non solleva eccezioni in caso di out of range (size può essere diversa, viene inserita a runtime!)
	}
	catch (int& i) {
		resize(D1, D1.size*2);
		push_back(D1,5);
	}
	catch (bool& a) {
		cout << "\nIntegrita' array imperfetta, array scorretto\n";
		return -1;
	}
	catch (string& s) {
		cerr << s << endl;
	}
	catch (...) {
		cerr << "unknown error\n";
	}
}
