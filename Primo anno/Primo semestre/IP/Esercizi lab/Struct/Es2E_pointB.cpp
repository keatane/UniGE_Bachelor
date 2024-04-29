// Es_2B di riscaldamento: Scrivere un programma che legge le informazioni relative a due Point P1 e P2 e ne stampa la distanza


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
    // Calcolare e stampare la distanza tra i due punti
    double dist;
    dist = sqrt(pow(P2.x-P1.x, 2) + pow(P2.y-P1.y, 2));
    cout << "Distanza fra i punti P1 e P2: " << dist << endl;

}
