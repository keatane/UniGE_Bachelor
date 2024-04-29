#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci l'anno in cui sei nato\n";
	int anno;
	cin >> anno;
	
	int eta, a_corrente = 2020;
	eta = a_corrente - anno;
	cout << "La tua eta' e': " << eta << " anni" << endl;
}
