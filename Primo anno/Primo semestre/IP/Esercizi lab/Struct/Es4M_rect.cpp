/* Es_4 di base: Definire una struct Rect per rappresentare un rettangolo mediante i vertici (Point) in alto a sinistra e in basso a destra.
Scrivere un programma che verifica se uno dei due rettangoli sia contenuto nell’altro, e stampa un messaggio di output
opportuno.
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
	Point Pas;
	Point Pbd;
	//double h;
	//double l;
};

int main()
{
	cout << "Inserire le coordinate dei punti alto-sx (x,y) e basso-dx (x,y) del rettangolo 1: " << endl;
	Rect R1;
	cin >> R1.Pas.x >> R1.Pas.y >> R1.Pbd.x >> R1.Pbd.y;

	cout << "Inserire le coordinate dei punti alto-sx (x,y) e basso-dx (x,y) del rettangolo 2: " << endl;
	Rect R2;
	cin >> R2.Pas.x >> R2.Pas.y >> R2.Pbd.x >> R2.Pbd.y;

	/* Non necessari
	R1.h = fabs(Pas.y - Pbd.y);
	R1.l = fabs(Pas.x - Pbd.x);
	R2.h = fabs(Pas.y - Pbd.y);
	R2.l = fabs(Pas.x - Pbd.x);
	*/

	// Il punto deve essere compreso nell'intervallo di lunghezza e nell'intervallo di altezza (tutto x 2 punti)
	if ((R1.Pas.x > R2.Pas.x && R1.Pas.x < R2.Pbd.x && R1.Pas.y < R2.Pas.y && R1.Pas.y > R2.Pbd.y)&&(R1.Pbd.x < R2.Pbd.x && R1.Pbd.x > R2.Pas.x && R1.Pbd.y < R2.Pas.y && R1.Pbd.y > R2.Pbd.y))
		cout << "Il rettangolo 2 contiene il rettangolo 1" << endl;
	else if ((R2.Pas.x > R1.Pas.x && R2.Pas.x < R1.Pbd.x && R2.Pas.y < R1.Pas.y && R2.Pas.y > R1.Pbd.y)&&(R2.Pbd.x < R1.Pbd.x && R2.Pbd.x > R1.Pas.x && R2.Pbd.y < R1.Pas.y && R2.Pbd.y > R1.Pbd.y))
		cout << "Il rettangolo 1 contiene il rettangolo 2" << endl;
	else
		cout << "I due rettangoli non si contengono a vicenda" << endl;


}
