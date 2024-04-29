// Es in lezione: funzione che ritorna true se la funzione è pari e palindroma

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef int T;

// PRIMA VERSIONE (index parte da v.size())
bool pari(vector<T>& v, int idx){
	if (v.size() == 0) throw 42; // vector vuoto
	else if (idx-1 == 0) return (v[0]%2==0);

	return ((v[idx-1]%2 == 0) && (pari(v, idx-1)));
}

// SECONDA VERSIONE (index parte da zero)
bool pari2(vector<T>& v, int index){
	if (index == v.size()-1) return v[index]%2 == 0; // index ferma l'incremento quando giunge a size-1

	return (v[index]%2==0) && pari(v, index+1);
}

int somma_seq(vector<T> A, int size) {
    if (size<=0) throw 42;
    if (size==1) return A[size-1];
    return A[size-1]+somma_seq(A,size-1);
}

bool pal_seq(vector<T> A, int size){
    if (A.size() == 0) throw 42;
	if (size==1) return true; // base

	if (size%2 == 0)
        return (somma_seq(A,(size/2) == (somma_seq(A,size)-somma_seq(A,size/2))));
    else
        return (somma_seq(A,size/2) == (somma_seq(A,size)-somma_seq(A,(size/2)+1)));
}

// VERSIONE STRINGA (n.b. l'eventuale stringa vuota è palindroma, perchè il vuoto soddisfa tutte le proprietà
bool pal_seq_string(string &s, int sinistra, int destra){ // sx e dx sono gli estremi della stringa (n.b. stringa = array di char)

	//if (sinistra == destra) return true; // capita per le sequenza dispari
	if (destra <= sinistra) return true; // < capita per le sequenze pari(vi è uno scambio di indici), in questo caso ho analizzato l'intera stringa (metà e metà) e sostanzialmente per interrompere le chiamate ritorno true (false pesa troppo su &&)

	return (s[sinistra]==s[destra]) && pal_seq_string(s, sinistra + 1, destra - 1); // muovo l'estremo di sinistra avanti e di destra indietro
}

int main()
try{
	vector<T> v1;
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(2);

	cout << "Sequenza di numeri pari: " << boolalpha <<  pari(v1,v1.size()) << endl;
	cout << "Sequenza di numeri pari: " << boolalpha <<  pari2(v1,0) << endl;

	cout << "Sequenza di numeri palindroma: " << boolalpha << pal_seq(v1,v1.size()) << endl;

	string s = "anna";
	cout << "Stringa palindroma: " << boolalpha << pal_seq_string(s, 0, s.size()-1);

}
catch(...){
	cout << "error\n";
}

