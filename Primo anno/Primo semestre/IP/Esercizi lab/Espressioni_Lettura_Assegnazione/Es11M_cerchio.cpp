//Calcola circonferenza e area cerchio dopo aver ricevuto gli opportuni dati in input

#include <iostream>

using namespace std;

int main ()
{
	float raggio;
	cout << "Inserisci il raggio della circonferenza\n";
	cin >> raggio;
	
	float circ, area, pi = 3.14159;
	circ = 2*pi*raggio;
	area = pi*raggio*raggio;
	
	cout << "La circonferenza vale: " << circ << " mentre l'area del cerchio: " << area << endl;
}
