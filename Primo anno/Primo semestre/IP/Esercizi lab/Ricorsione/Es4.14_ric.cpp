// Es_14 di base parte 4, con RICORSIONE: Scrivere un programma che legge un array di int e stampa il secondo valore piú elevato.

#include <iostream>
#include <vector>

using namespace std;

typedef int T;

T searchMax(vector<T> v, T max, T maxp, int i){

	if (v.size() <= 1) throw 42; // non c'è il secondo numero più elevato, ne ho solo uno o zero
	if (v[i] > max){
		maxp = max;
		max = v[i];
	}
	else if (v[i] > maxp && v[i] != max)
		maxp = v[i];
    if (i==v.size()-1) return maxp;
	return searchMax(v, max, maxp, i+1);

}

int main()
try{
	vector<T> v;
	v.push_back(8);
	v.push_back(2);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);

	cout << searchMax(v,-50,-45,0);

}
catch(...){
	cout << "error\n";
}

