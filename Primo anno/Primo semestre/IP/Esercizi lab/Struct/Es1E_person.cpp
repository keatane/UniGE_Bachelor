// Es_1 di riscaldamento: Definire un tipo struct Person per rappresentare i dati relativi a una persona.

#include <iostream>

using namespace std;

struct Person {
    string name;
    string surname;
    string birthYear;
};


int main()
{
	// Dichiarare due variabili di tipo Person
	Person me, you;

	// Assegnare valori ai membri di me e di you:
	me.name = "Bruce";
	me.surname = "Wayne";
	me.birthYear = "1939";
	you.name = "Clark";
	you.surname = "Kent";
	you.birthYear = "1933";

	// Assegnare il valore di un’intera variabile struct a un’altra:
	me = you;

	// Accedere (in lettura) ai valori dei membri, qui per stamparli:
    cout << "My name is " << me.name << " " << me.surname << std::endl;
	cout << "I was born in " << me.birthYear << std::endl;

}
