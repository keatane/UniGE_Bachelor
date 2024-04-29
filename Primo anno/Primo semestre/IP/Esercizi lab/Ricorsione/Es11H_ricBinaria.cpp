// Es_11 avanzato: Scrivere una funzione ricorsiva per la ricerca binaria su sequenze ordinate. Come per il punto precedente, implementare la
// versione basata su vector e su liste.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef int T;

int binary_search(vector<T> v, T x, int left, int right){

	if (v.size() == 0) throw 42;
	if (right < left) return -1;

	int mid = (left+right)/2;
	if (v[mid] == x) return mid;
	if (x < v[mid])
		return binary_search(v,x,left,mid-1);
	//else if (x > v[mid])
		return binary_search(v,x,mid+1,right);
}

int main()
try{
	vector<T> v1
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(3);

	// vector ordinabile (in maniera crescente) con 
	sort(v1.begin(), v1.end());
	// vector riempibile (in maniera crescente) con 
	//iota(v1.begin(), v1.end(),0);

	cout << "Inserisci il valore da trovare: ";
	int val;
	cin >> val;

	cout << "Il valore e' stato trovato a indice: " << binary_search(v1,val,0,v1.size()-1) << endl;

}
catch(...){
	cout << "error\n";
}

