/* Es_17 di base: Scrivere una funzione con due argomenti reali x e sqrt_x che restituisce un valore booleano, true se sqrt_x è la radice
quadrata di x, ovvero se il quadrato di sqrt_x coincide con x.
Per testare la funzione usate come dati 25.3268614564 la cui radice quadrata è 5.03258 (se preferite altri valori, vi conviene partire da un numero con cifre decimali e farne il quadrato, in modo da evitare errori di approssimazione dovuti ai
troncamenti).
*/

#include <iostream>

using namespace std;

void stampaMessaggio(double x, double y, bool q);

bool quadratoDi(double x, double sqrt_x){

	//return ((sqrt_x*sqrt_x) - x < 0.00001); // Osservo l'uguaglianza tenendo presente di eventuali troncamenti (esprimo una tolleranza)
	// In realtà, poichè sto facendo il 'quadrato' di un numero a confronto di un altro, il valore ottenuto è abbastanza preciso
	return (x == sqrt_x*sqrt_x);
}

int main()
{
    double rad = 4;
	double quad = 16;
	stampaMessaggio(quad,rad, quadratoDi(quad,rad));

	rad = 5;
	quad = 12;
	stampaMessaggio(quad,rad, quadratoDi(quad,rad));
}

void stampaMessaggio(double x, double y, bool q)        // Racchiudo la stampa
{
	cout << x << (q ? " e'" : " non e'") << " quadrato di " << y << endl;
}
