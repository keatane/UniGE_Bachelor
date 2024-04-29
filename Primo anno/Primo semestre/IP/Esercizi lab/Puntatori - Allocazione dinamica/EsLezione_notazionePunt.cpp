// Es in lezione: notazione dei puntatori

#include <iostream>

using namespace std;


int main()
{
	int * p = new int[10];

	*(p+2) = 10;
	p[4] = 20;
	*(3+p) = 30;
	p[5] = 40; // Equivale a: 5[p] = 40;

	for (int i=0; i<10; ++i) cout << p[i] << (i==10-1 ? "\n" : " ");
}
