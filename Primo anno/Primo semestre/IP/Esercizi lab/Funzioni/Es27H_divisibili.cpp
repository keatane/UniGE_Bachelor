/* Es_27 avanzato: Scrivere una funzione che presi come argomenti tre interi strettamente positivi: a, b e max restituisce la somma dei numeri
divisibili per almeno uno fra a e b compresi fra 0 e max.
*/

#include <iostream>

using namespace std;

int somma_divisibili(int a, int b, int max){

	int somma = 0;
	int num = 0; // Zero so per certo che è divisibile per a o b (diversi da zero) e si somma +0
	do{
		if (num%a == 0 || num%b == 0)
			somma += num;
		num++;
	}while (num <= max);
	return somma;
}

int main()
{
	int n1, n2, limite;
    cout << "Inserisci tre numeri interi diversi da zero (nota: rispettivamente a, b, max)" << endl;
	cin >> n1 >> n2 >> limite;
	cout << "Somma dei numeri divisibili per almeno uno fra a e b compresi fra 0 e max e': " << somma_divisibili(n1, n2, limite) << endl;
}
