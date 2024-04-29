// Es_2 di riscaldamento: Scrivere una funzione ricorsiva int coeffBin(const int& n, const int& k) per il calcolo del coefficiente binomiale: dati
// n, k appartenenti a N tali che 0 ≤ k ≤ n calcola il coefficiente binomiale

#include <iostream>

using namespace std;

int coeffBin(const int& n, const int& k) {
	// se k o n sono minori di zero, oppure k > n solleva eccezione
	if (k<0 || n<0) throw 42;
	// se n=k oppure k=0 ritorna 1
	if (n==k || k==0) return 1;
	// altrimenti ritorna la somma del coefficiente binomiale di n-1 e k-1 e ...
	// ...del coefficiente binomiale di n-1 e k
	return coeffBin(n-1,k-1) + coeffBin(n-1,k);
}


int main()
try{

	cout << "Inserisci due interi positivi\n";
	int num1,num2;
	cin >> num1 >> num2;
	cout << "Coefficiente binomiale: " << coeffBin(num1, num2) << endl;


}
catch(...){
	cout << "error\n";
}

