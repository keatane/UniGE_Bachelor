#include <iostream>

using namespace std;

int main ()
{
	float base, altezza;
	cout << "Inserisci il valore in cm della base del rettangolo" << endl;
	cin >> base;
	cout << "Inserisci il valore in cm dell'altezza del rettangolo" << endl;
	cin >> altezza;
	
	float perimetro, area;
	perimetro = base*2 + altezza*2;
	area = base * altezza;
	
	cout << "Il perimetro del rettangolo vale: " << perimetro << "cm e la sua area: " << area << "cm^2" << endl;
}
