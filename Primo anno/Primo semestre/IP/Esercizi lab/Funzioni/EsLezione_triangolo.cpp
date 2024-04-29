// triangolo.cpp

// Created by Kevin Cattaneo on 02/11/2020.

#include <iostream>

using namespace std;

// VERSIONE 1
void StampaTriangolo1(int altezza)
{
	for (unsigned int i=0; i<altezza; ++i)
	{
	    for (unsigned int j=altezza-1-i; j>0; --j)
			cout << " ";
		for (unsigned int k=0; k<i+1; ++k)
			cout << "**";    // Se non metto lo spazio alla fine o aggiungo più asterischi (cout << "**") oppure il risultato senza spazi consta di un triangolo rettangolo, questo perchè non esistono i mezzi spazi
        cout << endl;
	}
}

// VERSIONE 2

void StampaAsterischi(int n)
{
    for (unsigned j=1; j<=n; ++j)
				cout << "* ";
}

void StampaSpazi(int n)
{
    for (unsigned j=1; j<=n; ++j)
				cout << ' ';
}

// Versione generica di StampaSpazi(int n), stampo un elemento scelto
void StampaElem(int n, string s){

    for (unsigned j=1; j<=n; ++j)
				cout << s;
}

void StampaTriangolo2(int altezza)
{
	for (unsigned int i=1; i<=altezza; ++i){
		// stampo numero i asterischi
		// Stampo qualche spazio
		//StampaSpazi(altezza-i);
		StampaElem(altezza-i, " ");
        StampaAsterischi(i);
		cout << endl;
	}
}


int main()
{
	int h;
	cout << "Inserisci l'altezza del triangolo\n";
	cin >> h;
	StampaTriangolo1(h);
	cout << endl;
	StampaTriangolo2(h);

}