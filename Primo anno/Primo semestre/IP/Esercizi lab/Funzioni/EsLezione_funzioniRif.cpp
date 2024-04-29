// EsLezione: passaggio parametri per riferimento, es_funzioni

// Creato da Kevin Cattaneo il 9/11/2020

#include <iostream>

using namespace std;

// INTERFACCE

int sum(int x, int y);
void sum_diff(int x, int y, int &s, int &d);
void order(int &x, int &y);

int main()
{
	int m, n;
	cout << "Inserisci due interi\n";
	cin >> m >> n;
	order(m, n);
	int s = sum(m,n);
    cout << "Somma: " << s << endl;
	int d;
	sum_diff(m,n,s,d);
	cout << "Somma: " << s << endl;
	cout << "Differenza: " << d << endl;
}

// DICHIARAZIONI

// x e y sono PARAMETRI DI INPUT
int sum(int x, int y){
	return (x+y);
}

// funzione che calcola la somma e la differenza di due interi ("2 valori in ritorno")
// x e y sono PARAMETRI DI INPUT
// OUTPUT: somma e differenza (2 output, non ottenibili col return)
	// s e d sono PARAMETRI DI OUTPUT (d è parametro di "solo output", in quanto la sua inizializzazione è presenta direttamente nella funzione e non nel main)
void sum_diff(int x, int y, int &s, int &d){	// oppure (int& s, int& d)

	s = x+y;
	d = x-y;
}

// Obiettivo: Il primo argomento deve diventare minore del secondo (differenza negativa)
// x e y sono PARAMETRI DI INPUT-OUTPUT
void order(int &x, int &y){

	if (x>y){
		int temp = x;
		x = y;
		y = temp;
	}
}
