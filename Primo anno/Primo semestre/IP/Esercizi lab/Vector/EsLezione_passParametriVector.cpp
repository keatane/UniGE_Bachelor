// Es in lezione: Vector e passaggio dei parametri

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readVector(vector<int>& v) {

    cout << "Inserisci valori:\n";
	for (unsigned int i = 0; i<v.size(); ++i){
        int val;
        cin >> val;
        v.push_back(val);
	}

}

void printVector(const vector<int>& v) {
	/* iterare v.size() volte
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << (i==v.size()-1 ? "\n" : " ");
}

void funzione1(vector<int>v){ // passaggio per valore

	v.at(0) = 42;  // modifica nella copia v del vector V1 (modifica temporanea, alla fine della funzione V1 non viene influenzato da v)
	cout << "Da funzione1, v: ";
	printVector(v);
}

void funzione2(vector<int>& v){ // passaggio per riferimento

	v.at(0) = 42; // modifica permanente del vector
	cout << "Da funzione2, v: ";
	printVector(v);
}

void funzione3(const vector<int>& v){ // passaggio per riferimento costante (non si rischia di modificare in scrittura il contenuto del parametro) - viene impedito (da errore sintattico)


	//cout << "Da funzione3: ";
	//printVector(v);
	//v.at(0) = 42; // da errore
}

int main()
try{
	vector<int> V1(10);
    printVector(V1);

	funzione1(V1);

	cout << "Dopo funzione1, V1: ";
	printVector(V1);

	funzione2(V1);

	cout << "Dopo funzione2, V1: ";
	printVector(V1);

	funzione3(V1);

	cout << "Dopo funzione3, V1: ";
	printVector(V1);
}
catch(...){
	cerr << "\nerror\n";
}
