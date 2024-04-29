#include <iostream>

using namespace std;

extern int var; // Con extern elimino la parte di dichiarazione della variabile, ma faccio capire al compilatore "che la variabile esisterà", in un certo modo la "definisco" ma senza crearla ora.
// Dunque il compilatore non lo legge come errore, ma come se "non fosse stata creata ora", dunque la riprende in seguito.
// Ricorda: posso 'definire' più volte la stessa variabile

// int var; così facendo dichiaro (creo la variabile)

int main()
{
	cout << sizeof var << endl; // Size of restituisce la quantità di byte occupata dalla variabile
	cout << var << endl;
}

int var = 100;

// N.B. Cout è una variabile anch'essa, solo racchiusa in una 'scatola' (detta std) all'interno di un namespace (di variabili globali) di una libreria (iostream)