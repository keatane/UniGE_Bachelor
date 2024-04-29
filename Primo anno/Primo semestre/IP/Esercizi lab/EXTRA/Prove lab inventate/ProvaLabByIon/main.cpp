#include <iostream>
#include "book.h"

using namespace std;

int main(){
	Libreria l;
	l = nullptr;
	
	insertNewBook(l);

	cout << "Libreria:\n";
	printLibrary(l);
	
	sortLibrary(l);
	
	cout << endl;
	cout << "Libreria ordinata alfabeticamente:\n";
	printLibrary(l);
	
	cout << endl;
	pickBook(l,"Arcangelo");
	
	cout << endl;
	cout << "Libreria dopo rimozione:\n";
	printLibrary(l);
	
	cout << "Libro trovato: " << boolalpha << findBook(l,"Socrate") << endl;
	cout << "Quanti libri ci sono: " << howManyBook(l) << endl;
	
	Libro b;
	b = findBiggest(l);
	cout << "Libro con più pagine: " << b.title << " con " << b.NoP << " pagine\n";	
	b = findSmallest(l);
	cout << "Libro con meno pagine: " << b.title << " con " << b.NoP << " pagine\n";
}
