// Es_14 avanzato:

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// equazione: ax^2 + bx + c
	double a, b, c;
	int i = 0;
	
	cout << "Inserisci il " << i+1 << " coefficiente dell'equazione" << endl;
	cin >> a;
	cout << "Inserisci il " << i+2 << " coefficiente dell'equazione" << endl;
	cin >> b;
	cout << "Inserisci il " << i+3 << " coefficiente dell'equazione" << endl;
	cin >> c;
	
	double x1, x2, delta;
	delta = pow(b,2) - 4*a*c;
	
	if (delta < 0)
		cout << "Attenzione, hai inserito un delta negativo, risulta una radice immaginaria!" << endl;
	else
	{	
		x1 = (-b + sqrt(delta))/(2*a);
		x2 = (-b - sqrt(delta))/(2*a);
		cout << "Le soluzioni dell'equazione data sono: " << x1 << " e " << x2 << endl;
	}
	
	return 0;


}
