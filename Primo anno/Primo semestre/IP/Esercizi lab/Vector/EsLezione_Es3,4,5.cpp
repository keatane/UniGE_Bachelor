// Es a lezione - vector n. 4, 5
// Created by Kevin Cattaneo on 23/11/2020


#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readVector(std::vector<int>& v) {
	cout << "Inserisci valori strettamente positivi, interrompi l'inserimento con un negativo: ";
	do{
		int val;
        cin >> val;
		if (val < 0) break;
        v.push_back(val); // Inserisco in fondo al vector l'elemento in input: automaticamente il push back ridimensiona il vector
	}while(true);

}

void printVector(const std::vector<int>& v) {
	/* iterare v.size() volte
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << (i==v.size()-1 ? "\n" : " ");
}

int SequentialSearch_vector(const std::vector<int>& v, int item) {
int loc = -1;
bool found = false;
int i = 0;

try{
    do{
	if(v.at(i) == item){
		found = true;
		loc = i;
	}
	i++;

}while(!found && i < v.size());
}
catch (const exception& e){
    cout << "Elemento non trovato\n";
}
	// restituire loc
	return loc;
}

// Variante 1 della SequentialSearch
int SequentialSearch_vector2(const std::vector<int>& v, int item) {
	for (unsigned int i=0; i<v.size(); ++i)
		if (v.at(i) == item)
			return i;

	return -1;
}

// Variante 2 della SequentialSearch (ritorna true se item è trovato)
bool isIn(const vector<int>& v, int item)
{
	for (unsigned int i=0; i<v.size(); ++i)
		if (v.at(i) == item)
			return true;
	// se sono qui non ho trovato item da nessuna parte
	return false;
}


// v è un parametro formale INPUT
// reverse restituiscce un valore (vector di int): l'OUTPUT della funzione
vector<int> reverse(vector<int> v){

	vector<int> v_rev(v.size()); // v_rev NON è vuoto: ho predisposto con un costruttore uno spazio nello heap pari a v.size() inizializzati con 0;

	for (unsigned int i=0; i<v.size(); ++i)
		v_rev.at(v.size()-1-i) = v.at(i);
	return v_rev;

}

// Reverse in place (non creo ulteriori vector a quello già presente)
void reverse_inPlace(vector<int>& v){

	int temp = 0;
	for (unsigned int i=0; i<v.size()/2; ++i){ // Eseguo uno swap su metà degli elementi (l'altra metà viene conseguentemente scambiata con la prima), continuare fino in fondo tornerei al punto di partenza
		temp = v.at(v.size()-1-i);
		v.at(v.size()-1-i) = v.at(i);
		v.at(i) = temp;
	}
}

vector<int> cat(vector<int>& v1, vector<int>& v2){

	vector<int> v_cat(v1); // Così facendo associo già una parte dell'elenco composto, produco una copia di v1	//vector<int> v_cat(v1.size()+v2.size()) è un'altra strada possibile
	// Posso fare un resize oppure effettuare un pushback (mette automaticamente gli elementi in fondo): così facendo ricopio all'interno di v_cat gli elementi di v2
	for (unsigned int i=0; i<v2.size(); ++i){
		v_cat.push_back(v2.at(i));
	}
	return v_cat;
}

// con push_back e pop_back riusciamo agevolmente a modificare il contenuto di un vector secondo il concetto LAST IN FIRST OUT (LIFO) (l'ultimo elemento inserito è quello che si può facilmente togliere)

// come implementare un approccio FIRST IN FIRST OUT (FIFO)? (cioè il primo elemento inserito nel vector è il primo che esce se richiesto, cioò non viene fatto dalla pop_back)

// Per implementare il modello FIFO se inserisco elementi nuovi con push_back non posso estrarre con pop_back. Nota bene non posso deallocare solo il primo elemento a causa della definizione di gruppi elementi contigui presenti nei vector (non si può modificare il puntamento)

void pop_front(vector<int>&v){
	// Controllo se il vector è vuoto
	string err= "vector vuoto";
	if (v.size() == 0) throw err;
	for (unsigned int i=1; i<v.size(); ++i)
		v.at(i-1) = v.at(i); // Il valore attuale lo inserisco (copio e sovrascrivo il valore) nella posizione precedente
	// Infine riduco la dimensione (size) di 1 (togliendo il valore che rimane duplicato alla fine)
	v.pop_back(); // equivalente a v.resize(v.size()-1) (memory leak evitato automaticamente dal vector)
	
}

int main()
try{

	vector<int> v1; // v1 contiene 10 valori inizializzati tutti uguali (per gli interi sono tutti 0)
	readVector(v1);
    printVector(v1);
    cout << "\n--Sequential Search--\n";
	cout << "Elemento 3 trovato: " << boolalpha << isIn(v1, 3) << endl;
	vector<int> v2;
	v2 = reverse(v1);
	cout << "\n--Reverse--\n";
	cout << "Source: ";
	printVector(v1);
	cout << "Dest: ";
	printVector(v2);
	cout << endl;
	cout << "\n--Reverse in Place--\n";
	reverse_inPlace(v1);
	printVector(v1);
	// N.B. v = reverse(v) non è una reverse in place in quanto viene comunque creata una copia di v nella funzione chiamata: vi è solo il parametro di Input e Output uguali
	cout << "\n--Concatenazione--\n";
    cout << "Primo vector: ";
	printVector(v1);
	cout << "Secondo vector: ";
	printVector(v2);
	cout << "Terzo vector: ";
	vector<int> v3 = cat(v1,v2);
	printVector(v3);

}
catch(...) // I vector sono complessi, altrettanto lo sono le loro eccezioni, dunque catturo eccezioni in generale
{
	cerr << "error\n" << endl;
}
