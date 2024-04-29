/* Espressioni logiche e floating point 

Creato da Kevin il 05/10/2020

#include <iostream>

using namespace std;

int main ()
{
	float f;
	f = 3./7. + 2./7. + 2./7.;
	
	cout << (f == 1.0) << endl;
	
	double d;
	d = 3./7. + 2./7. + 2./7.;
	
	cout << (d == 1.0) << endl;
	
	// (senza tolleranza) Per via dell'approssimazione il risultato può essere uno dei casi (T-T, T-F, F-T, F-F)
	// e ciò dipende da calcolatore a calcolatore
}
*/


// Una possibile strategia

#include <iostream>
#include <cmath>

using namespace std;

// Inseriamo una tolleranza

const float TOLL = 0.0000001; // = 10e5

int main ()
{
	float f;
	f = 3./7. + 2./7. + 2./7.;
	
	cout << (fabs(f - 1.0) < TOLL) << endl; // valore assoluto float = fabs
	// Così posso determinare con una certa precisione (vedo di quanto differiscono) se i due numeri sono uguali
	
	double d;
	d = 3./7. + 2./7. + 2./7.;
	
	cout << (fabs(d - 1.0) < TOLL) << endl;
}
