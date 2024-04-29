// Es_8 avanzato:  Ancora sul Crivello di Eratostene: scrivere la funzione std::vector<int> primes(int n) che dato un intero positivo n restituisce un std::vector<int> che contiene tutti e soli
// i numeri primi compresi tra 2 e n, che quindi deve essere un vettore
// vuoto se n<2. Partire dal codice della funzione isprime (Parte 4, esercizio 9).

#include <iostream>
#include <vector>

using namespace std;

void print_v(vector<int> v1){
	for (unsigned int i=0; i<v1.size(); ++i)
		cout << v1.at(i) << " ";
	cout << endl;
}

vector<int> primes(int N){

	vector<int> v;
	if (N<1) throw -1;
	
	if (N<2){
        cout << "Vector vuoto\n";
        return v;
	}


	//Inizializzazione
	bool isprime[N];

	for (unsigned int i = 0; i < N; ++i)
		isprime[i] = true;

	// CALCOLO
	int p = 2;

	do{
		for (int i=2; i<=N/p; ++i)
			isprime[i*p] = false;
		for (int i = p +1; ; ++i) // Il for cicla finchè non viene eseguito il break (no condizione di limite superiore)
			if (isprime[i]){
				p = i;
				break;
			}
	}while(p < N / 2);

	//Output
	for (unsigned int i = 2; i < N; ++i)
		if(isprime[i])
			// cout << i << " e' un numero primo" << endl;
			v.push_back(i);

}


int main()
try{

	cout << "Inserisci un numero intero" << endl;
	int num;
	cin >> num;
	vector<int> a; // v è vuoto
	a = primes(num);
    print_v(a);
}
catch(...)
{
	cerr << "error\n" << endl;
}
