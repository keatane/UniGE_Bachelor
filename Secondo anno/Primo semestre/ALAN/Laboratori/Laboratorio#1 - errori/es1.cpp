// Programma svolto dai membri: Gabriele DellePere, Roberto Lazzarini, Kevin Cattaneo

#include <iostream>
#include <math.h>

using namespace std;

/*
Ordiniamo alfabeticamente secondo il cognome

'Cattaneo' è il cognome alfabeticamente in prima posizione nel gruppo.

matricola: 4944382

d0 = 2, d1 = 8;

*/

const double d0 = 2.0;
const double d1 = 8.0;

int main(){
	
	double a,b,c;
	int i = 0;
	
	a = 0.0; // per inizializzare
	b = (d1 + 1) * pow(10,20);
	c = -b;	
	
	for(i = 0; i<6; ++i){
		a = (d0 + 1) * pow(10,i);
		//primo calcolo
		cout << (a+b)+c << endl;
		
		//secondo calcolo
		cout << a+(b+c) << endl;
		cout << endl;
	}	

	return 0;
}

// Osservazioni
/*

- Nel primo calcolo viene effettuata una cancellazione in un secondo momento, ovvero dopo la somma con un numero
notevolemente minore, ovvero a. La cancellazione avviene poi fra b e c, risultando anche nella cancellazione del valore di a.

- Nel secondo calcolo si osserva una cancellazione in prima battuta fra b e c, dunque la somma di zero con la variabile 
a restituisce il valore di a medesimo.

Per i = 6, il valore di a influenza la somma di a e b, infatti la cancellazione non restituisce il valore zero, bensì 
un'approssimazione di a (per seguire la precisione di macchina, seguo l'ordine di grandezza alto, quindi quello minore
viene troncato)

*/

