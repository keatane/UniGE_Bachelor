// Es_1 di riscaldamento: Scrivere due funzioni void readVector(std::vector<int>& v) e void printVector(const std::vector<int>& v) che permettano di riempire v con valori letti e stamparli

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
        v.push_back(val); // Inserisco in fondo al vector l'elemento in input: automaticamente il push back ridimensiona il vector
	}

}

void readVectorY(std::vector<int>& v) {
	cout << "Inserisci valori interi e termina con 'y'" << endl;
    string input;
	while(input != "y")

    try
    {
        //Codice da testare
        int val = stoi(input); // Converte string a intero
		v.push_back(val);
    }
    catch(const exception& e) // Così facendo catturo l'eccezione senza inviarla al main, il programma avvisa e salta l'inserimento del valore errato nel vector.
    {
        cout << "Il valore inserito non e' un numero!\n";
    }
    cin >> input; // Blocca o continua il ciclo
}


void printVector(const std::vector<int>& v) {
	/* iterare v.size() volte
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << (i==v.size()-1 ? "\n" : " ");
}


int main() {

	// dichiarare un std::vector vect di interi
	vector<int> v;
	// chiamare la funzione readVector su vect
	readVectorY(v);
	cout << endl;
	cout << "Stampa: ";
	// chiamare la funzione printVector su vect
	printVector(v);
}
