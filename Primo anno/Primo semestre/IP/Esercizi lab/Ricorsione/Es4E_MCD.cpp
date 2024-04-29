/* Es_4 di riscaldamento: Scrivere una funzione ricorsiva int MCD(const int& m, const int& n) che dati due numeri interi m ed n calcola il massimo
comune divisore utilizzando l’algoritmo di Euclide, descritto nel seguente modo:

MCD(m,n) = m se m=n
MCD(m,n) = MCD(m-n, n) se m > n
MCD(m,n) = MCD(m, n-m) se n > m
*/

#include <iostream>
#include <cmath>

using namespace std;

int MCD(const int& m, const int& n){
	if (m==n) return m;
	if (m>n) return MCD(m-n, n);
	else return MCD(m, n-m);
}

int main()
try{
	cout << "Inserisci due interi positivi\n";
	int num1,num2;
	cin >> num1 >> num2;

	// Gestisco i casi negativi poichè MCD(-m,n) = MCD(m,n) e viceversa
	if (num1) num1 = abs(num1);
	if (num2) num2 = abs(num2);

	cout << "MCD: " << MCD(num1, num2) << endl;
}
catch(...){
	cout << "error\n";
}

