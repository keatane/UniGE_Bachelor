// Es_8 parte 4, di base con RICORSIONE: Scrivere un programma reverse che legge N interi in un array source (vedi leggiArrayInt), e poi copia in un array dest gli
// elementi di source in ordine inverso.
// Quindi stampa source e dest (lasciando una riga vuota in mezzo per chiarezza).

#include <iostream>
#include <vector>

using namespace std;

typedef int T;

void reverseInPlace(vector<T>& v, int first, int last){

	if (v.size() == 0) throw 42;
	if (first >= last) return;

	T aux = v[first];
	v[first] = v[last];
	v[last] = aux;

	return reverseInPlace(v,first+1, last-1);
}

int main()
try{
	vector<T> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	reverseInPlace(v,0, v.size()-1);

	for(unsigned int i=0; i<v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

}
catch(...){
	cout << "error\n";
}

