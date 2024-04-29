// Es_2A di riscaldamento: Definire un tipo struct Point per rappresentare punti su un piano cartesiano. La struct deve mantenere le coordinate di un punto:

#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;
};

const double TOLL = 0.000001;

int main()
{
	// Stampare "Inserire le coordinate del punto P1: "
	cout << "Inserire le coordinate del punto P1: " << endl;
	// Dichiarare una variabile P1 di tipo Point
	Point P1;
	// Leggere da input le coordinate e memorizzarle in P1.x e P1.y
	cin >> P1.x >> P1.y;
	// Stampare "Inserire le coordinate del punto P2: "
	cout << "Inserire le coordinate del punto P2: " << endl;
	// Dichiarare una variabile P2 di tipo Point
	Point P2;
	// Leggere da input le coordinate e memorizzarle in P2.x e P2.y
	cin >> P2.x >> P2.y;
	// Se P1 e P2 sono lo stesso punto (ossia se hanno le stesse coordinate)

	if (fabs(P1.x - P2.x)< TOLL && fabs(P1.y - P2.y)< TOLL)
	// - Stampare "I punti sono uguali" seguito da un a capo
		cout << "I punti sono uguali" << endl;
	// Altrimenti
	else{
	// - Stampare "Il secondo punto è "
		cout << "Il secondo punto e' ";
	// - Se P2.y > P1.y
		if (P2.y > P1.y)
	// -- Stampare "in alto "
			cout << "in alto ";
	// - Altrimenti
		else
	// -- Stampare "in basso "
			cout << "in basso ";
	// - Se P2.x > P1.x
		if (P2.x > P1.x)
	// -- Stampare "a destra "
			cout << "a destra ";
	// - Altrimenti
		else
	// -- Stampare "a sinistra "
			cout << "a sinistra ";
	// - Stampare " rispetto al primo" seguito da un a capo
		cout << " rispetto al primo" << endl;
	}

}
