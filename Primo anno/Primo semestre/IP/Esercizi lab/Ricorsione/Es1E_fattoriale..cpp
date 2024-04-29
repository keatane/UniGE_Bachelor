// Es_1 di riscaldamento: Scrivere una funzione ricorsiva int fact(const int& n) per il calcolo del fattoriale di un intero positivo n


#include <iostream>

using namespace std;

int fact(const int& n) {
	// se n < 0 solleva eccezione
	if (n<0) throw 42;
	// se n=0 ritorna 1
	if (n==0) return 1;
	// altrimenti ritorna n moltiplicato per il fattoriale di n-1
	// 'else' non necessario
	return n*fact(n-1);
}

int main()
try{

	cout << "Inserisci un intero positivo\n";
	int num;
	cin >> num;
	cout << "Fattoriale: " << fact(num) << endl;


}
catch(...){
	cout << "error\n";
}

