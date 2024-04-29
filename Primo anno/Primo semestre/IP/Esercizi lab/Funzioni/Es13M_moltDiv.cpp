// Es_12 di base: Scrivere una funzione con tre parametri di tipo float che li moltiplica fra loro, divide il risultato ottenuto per ciascuno degli
// argomenti in successione e restituisce un booleano che vale vero se il risultato dell’operazione è 1.

#include <iostream>

using namespace std;

bool calculus(float a, float b, float c){
	float prodotto;
	prodotto = a*b*c;
	float quoziente = prodotto;
	quoziente /= a;
	quoziente /= b;
	quoziente /= c;

	if (quoziente == 1)
		return 1;
	else
		return 0;
}

int main()
{
	float n1, n2, n3;
    cout << "Inserisci tre valori numerici" << endl;
	cin >> n1 >> n2 >> n3;
	cout << boolalpha << calculus(n1,n2,n3) << endl;
}
