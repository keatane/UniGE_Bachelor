// Es_3 di riscaldamento: Scrivere una funzione int SequentialSearch_vector(const std::vector<int>& v, int item) che effettui la ricerca dell’elemento item all’interno di v

#include <iostream>
#include <vector>
#include <string>

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

void printVector(const std::vector<int>& v) {
	/* iterare v.size() volte
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << (i==v.size()-1 ? "\n" : " ");
}

int SequentialSearch_vector(const std::vector<int>& v, int item) {
// dichiarare una variabile int loc e inizializzarla a -1
int loc = -1;
// dichiarare una variabile bool found e inizializzarla a false
bool found = false;
/* iterare su v fino a che found diventa true o ...
... si \`e iterato su tutto il vector
- se il valore alla pos corrente (i) e' uguale a item
-- assegnare true a found e i a loc
*/
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

int SequentialSearch_vector2(const std::vector<int>& v, int item) {
	/* iterare su v dalla prima all'ultima posizione
	- se il valore alla pos corrente (i) e' uguale a item
	-- restituire i
	*/
	for (unsigned int i=0; i<v.size(); ++i)
		if (v.at(i) == item)
			return i;

	// restituire -1
	return -1;
}



int main() {

	// dichiarare un std::vector vect di interi
	vector<int> v;
	// chiamare la funzione readVector su vect
	readVector(v);
	cout << endl;
	cout << "Stampa: ";
	// chiamare la funzione printVector su vect
	printVector(v);
	cout << "Elemento 3 trovato a index: " << SequentialSearch_vector2(v, 3) << endl;
}
