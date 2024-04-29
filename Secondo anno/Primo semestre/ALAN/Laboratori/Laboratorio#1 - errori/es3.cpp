// Programma svolto dai membri: Gabriele DellePere, Roberto Lazzarini, Kevin Cattaneo

#include <iostream>
#include <math.h>

using namespace std;

int main(){

	float eps1 = 2.0;
	double eps2 = 2.0;
	
	int d = 1;
	
	while(1.0f + (float)pow(eps1,-d) > 1.0f) d++; 
	
	// usciamo dal ciclo con il valore di d dell'esponente di due 'errato', ovvero che da risultato zero come potenza;
	// nella stampa dunque teniamo in considerazione l'ultimo valore di d che restituiva true nella condizione del ciclo
	
	cout << "Precisione singola " << pow(eps1,-d+1) << ", ovvero 2^(" << (-d+1) << ")\n";
	
	while(1.0 + pow(eps2,-d) > 1.0)	d++;
	
	cout << "Precisione doppia " << pow(eps2,-d+1) << ", ovvero 2^(" << (-d+1) << ")\n";
	
	return 0;
}
