/* Es_4 di base: Definire una struct Rect per rappresentare un rettangolo mediante i vertici (Point) in alto a sinistra e in basso a destra.
Scrivere un programma che verifica se uno dei due rettangoli sia contenuto nell’altro, e stampa un messaggio di output
opportuno.

VERSIONE B
*/

#include <iostream>
#include <cmath>

using namespace std;

const double TOLL = 0.0000001;

struct Point {
	double x;
	double y;
};

struct Rect {
	Point vul; // vertice upper left
	Point vlr; // vertice lower right
};

int main()
{
	Rect R1 = { { 0, 5 } , { 10, 0 } };
	Rect R2 = { { 1, 4 } , { 8, 2 } };

	Point R1perim[4];
	Point R2perim[4];


	// Costruisco i rettangoli con 4 vertici (mi costruisco i vertici mancanti)
	R1perim[0] = R1.vul;
	R1perim[1].x = R1.vul.x; R1perim[1].y = R1.vlr.y;
	R1perim[2] = R1.vlr;
	R1perim[3].x = R1.vlr.x; R1perim[3].y = R1.vul.y;

	R2perim[0] = R2.vul;
	R2perim[1].x = R2.vul.x; R2perim[1].y = R2.vlr.y;
	R2perim[2] = R2.vlr;
	R2perim[3].x = R2.vlr.x; R2perim[3].y = R2.vul.y;

	// Spezzo i test sui quattro vertici
	bool testv0 = R1perim[0].x < R2perim[0].x && R1perim[0].y > R2perim[0].y; // punto in alto a sinistra
	bool testv1 = R1perim[1].x < R2perim[1].x && R1perim[1].y < R2perim[1].y; // punto in basso a sinistra
	bool testv2 = R1perim[2].x > R2perim[2].x && R1perim[2].y < R2perim[2].y; // punto in basso a destra
	bool testv3 = R1perim[3].x > R2perim[3].x && R1perim[3].y > R2perim[3].y; // punto in alto a destra

	if (testv0 && testv1 && testv2 && testv3)
		cout << "R2 contenuto in R1\n";
	else
		cout << "R2 non contenuto in R1\n";
}
