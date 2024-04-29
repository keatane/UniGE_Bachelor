// Es_10 di base: Scrivere una funzione con un argomento num di tipo intero che restituisce il numero di cifre (in base 10). Ad esempio su 27458 restituisce 5.

#include <iostream>

using namespace std;

int contaCifre(int n){
	int k = 0;
	do{
		n/10; // Divisione intera, conto anche il caso zero, uguale a 1 cifra (eseguo solo una volta il processo)
		k++;
	} while (n>0);
	
	return k;
}


int main()
{
	int num;
    cout << "Inserisci un numero intero: ";
	cin >> num;
	cout << "Numero cifre: " << contaCifre(num) << endl;
}
