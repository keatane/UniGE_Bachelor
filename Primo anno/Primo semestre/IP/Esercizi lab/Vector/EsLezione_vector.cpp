// Es a lezione - vector
// Created by Kevin Cattaneo on 23/11/2020

#include <iostream>
#include <vector>

using namespace std;

void print_v(vector<int> v){
	for (unsigned int i=0; i<v1.size(); ++i)
		cout << v1.at(i) << " ";
	cout << endl;
}

int main()
try{

	vector<int> v; // v è vuoto
	cout << v.size() << endl; // size è zero, v.size() è un metodo che restituisce la dimensione del vector (n. elementi)
	//cout << v.at(0) << endl; // Errore, viene sollevata un'eccezione: sto accedendo al vuoto
	// cout << v[0] << endl; // Viene stampato un errore: accesso a un segmento di memoria non proprio al vector (Segmentation fault)
	// cout << v.front() << endl; // Errore: Segmentation fault

	vector<int> v1(10); // v1 contiene 10 valori inizializzati tutti uguali (per gli interi sono tutti 0)
    print_v(v1);
}
catch(...) // I vector sono complessi, altrettanto lo sono le loro eccezioni, dunque catturo eccezioni in generale
{
	cerr << "error\n" << endl;
}
