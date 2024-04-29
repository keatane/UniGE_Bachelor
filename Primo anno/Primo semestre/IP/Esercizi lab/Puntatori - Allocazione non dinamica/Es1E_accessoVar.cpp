/* Es_1 di riscaldamento: Scrivete un programma in cui usate i puntatori per accedere alle locazioni di variabili. Siete incoraggiati a migliorare i messaggi di stampa minimali proposti nell’esercizio in modo da capire più facilmente quali valori state stampando, ad esempio
aggiungendo frasi come indirizzo di s1 == oppure valore di p ==.

[SUGGERIMENTO: Per stampare gli indirizzi (riferimenti a variabili e valore di puntatori) in maniera leggibile, bisogna usare
static_cast<void*>(...) mettendo l’indirizzo al posto dei puntini.]
*/

#include <iostream>

using namespace std;

int main()
{
	// dichiarare due variabili s1 e s2 di tipo string inizializzate rispettivamente...
	// ... a "Hello" e "World"
	string s1 = "hello";
	string s2 = "world";
	// stampare il messaggio "Debug: ", gli indirizzi di s1 e di s2 e andare a capo
	// stampare s1 e s2 e andare a capo
	cout << "Debug 1: " << &s1 << "  " << &s2 << endl;
	// dichiarare una variabile p di tipo puntatore a string inizializzata con...
	// ... l'indirizzo di s1
	string *p = &s1;
	// stampare il messaggio "Debug: ", il valore di p e il valore ...
	// ...dell'area di memoria puntata da p e andare a capo
	cout << "Debug 2: " << p << "  " << *p << endl;
	// assegnare all'area di memoria puntata da p la stringa "Ciao"
	*p = "Ciao";
	// assegnare a p l'indirizzo di s2
	p = &s2;
	// stampare il messaggio "Debug: ", il valore di p e il valore ...
	// ...dell'area di memoria puntata da p e andare a capo
	cout << "Debug 3: " << p << "  " << *p << endl;
	// assegnare all'area di memoria puntata da p la stringa "Mondo"
	*p = "Mondo";
	// stampare s1 e s2 e andare a capo
	cout << &s1 << "  " << &s2 << ":::" << s1 << "  " << s2 << endl;

}