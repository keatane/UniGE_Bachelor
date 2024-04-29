//Calcola e stampa il perimetro e l'area di un triangolo

#include <iostream>

using namespace std;

int main ()
{
	float base, altezza, lato1, lato2;
	cout << "Inserisci il valore in cm della base del triangolo" << endl;
	cin >> base;
	cout << "Inserisci il valore in cm del secondo lato del triangolo" << endl;
	cin >> lato1;
	cout << "Inserisci il valore in cm del terzo lato del triangolo" << endl;
	cin >> lato2;
	
	cout << "Inserisci il valore in cm dell'altezza del triangolo" << endl;
	cin >> altezza;
	
	float perimetro, area;
	perimetro = base + lato1 + lato2;
	area = (base * altezza)/2;
	
	cout << "Il perimetro del rettangolo vale: " << perimetro << "cm e la sua area: " << area << "cm^2" << endl;
}
