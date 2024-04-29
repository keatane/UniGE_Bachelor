// EsLezione: passaggio parametri per riferimento, es_punti

// Creato da Kevin Cattaneo il 9/11/2020

/* Realizzare un programma che prende in input 3 punti del piano cartesiano
e verifica se sono disposti in modo crescente (rispetto alle ordinate)
*/

#include <iostream>

using namespace std;

// INTERFACCE

struct Point {
	float x;
	float y;
};

Point ReadPoint();
void PrintPoint(Point);
void OrderByX(Point &P1, Point &P2, Point &P3);
bool IsAscending(Point P, Point Q, Point R);

int main()
{
	// PRENDO PUNTI IN INPUT
	Point P1, P2, P3;
	P1 = ReadPoint();
	P2 = ReadPoint();
	P3 = ReadPoint();

	// (ORDINO PRIMA LE ASCISSE)
	OrderByX(P1, P2, P3);

	PrintPoint(P1);
	PrintPoint(P2);
	PrintPoint(P3);

	// FACCIO LA VERIFICA (rispetto alle ordinate)
	cout << boolalpha << IsAscending(P1,P2,P3);
}

// FUNZIONI

Point ReadPoint() {
	cout << "Inserisci le coordinate x e y di un punto\n";
	Point P;
	cin >> P.x >> P.y;
	return P;
}

/* OPPURE
void ReadPoint(Point &P) {
	cout << "Inserisci le coordinate x e y di un punto\n";
	cin >> P.x >> P.y;
}
*/

void PrintPoint(Point P){
	cout << "(" << P.x << "," << P.y << ")" << endl;
}

void Swap(Point &P1, Point &P2){
	Point temp;
	temp = P1;
	P1 = P2;
	P2 = temp;
}

// POSTCONDIZIONE: P1.x < P2.x < P3.x
void OrderByX(Point &P1, Point &P2, Point &P3){

	// metto a posto il più piccolo in P1 (rispetto alle ascisse)
	if (P2.x < P1.x && P2.x < P3.x)	// Se P2 è il più piccolo
		Swap(P1,P2);
	if (P3.x < P1.x && P3.x < P2.x)	// Se P3 è il più piccolo
		Swap(P1,P2);
	// In ogni caso so che P1 sarà il più piccolo (anche nel caso gli if non vengano eseguiti)
	if (P3.x < P2.x)	// Infine scambio il valore intermedio con quello finale se quest'ultimo è minore
		Swap(P2,P3);

}

bool IsAscending(Point P, Point Q, Point R){
	return (P.y < Q.y && Q.y < R.y);
}
