// Es_1 di riscaldamento: 


#include <iostream>

using namespace std;

struct person {
string name ;
string surname ;
int birthYear ;
};


/* // Modifcare il programma precedente considerando come struttura per rappresentare una persona la seguente:
struct person {
string * name ;
string surname ;
int birthYear ;
};
*/

int main()
{
	
	// dichiarare una variabile personValue di tipo person e inizializzare i suoi valori
	person personValue;
	personValue.name = "Al";
	personValue.surname = "Bil";
	personValue.birthYear = 2000;
	// dichiarare una variabile personPointer di tipo puntatore a person
	person* personPointer;
	// inizializzare personPointer con i valori associati in personValue
	personPointer = &personValue;
	// stampare i valori di personValue e personPointer
	cout << "Stampa 1" << endl;
	cout << personValue.name << endl;
	cout << personPointer->name << endl; // Struct di struct sarebbe -> ... ->
	// modificare il campo name di personPointer
	string name = "NewName";
	personPointer->name = name;
	// stampare i valori di personValue e personPointer
	cout << "Stampa 2" << endl;
	cout << personValue.name << endl;
	cout << personPointer->name << endl;
	
	
}


