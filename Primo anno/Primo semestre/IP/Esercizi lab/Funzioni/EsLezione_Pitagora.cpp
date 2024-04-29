// EsLezione: Pitagora
// Created by Kevin Cattaneo on 4/11/2020

#include <iostream>
#include <cmath>

using namespace std;

double sq(double);


int main()
{
	double cateto1 = 3;
	double cateto2 = 4;
	double ipotenusa = sqrt(sq(cateto1) + sq(cateto2));
	cout << "Il triangolo che ha cateti lunghi " << cateto1 << " e " << cateto2;
	cout << " ha ipotenusa lunga " << ipotenusa << endl;
}

double sq(double n){
	return n*n;
}
