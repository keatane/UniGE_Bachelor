// Es_3 di riscaldamento: Scrivere una funzione ricorsiva int fibonacci(const int& n) per il calcolo del numero di Fibonacci.

#include <iostream>

using namespace std;

int fibonacci(const int& n) {
	// se n e' minore di zero solleva eccezione
	if (n<0) throw 42;
	// se n=0 oppure n=1 ritorna 1
	if (n==0 || n==1) return 1;
	// altrimenti ritorna la somma del numero di fibonacci di n-1 e ...
	// ...del numero di fibonacci di n-2
	return fibonacci(n-1) + fibonacci(n-2);
}

// n:   0 1 2 3 4 5 6...
// nF:  1 1 2 3 5 8 13...

int main()
try{
	cout << "Inserisci un numero intero positivo \n";
	int num;
	cin >> num;
	cout << "Il " << num << "-esimo numero di Fibonacci e': " << fibonacci(num) << endl;
}
catch(...){
	cout << "error\n";
}

