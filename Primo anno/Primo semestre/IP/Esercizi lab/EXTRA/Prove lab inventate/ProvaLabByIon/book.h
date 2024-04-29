#ifndef BOOK
#define BOOK

struct PublicationDay{
	int day;
	int month;
	int year;
};

struct Libro{
	std::string title;
	std::string publisher;
	std::string writer;
	int NoP; // Number of pages
	std::string coverColor;
	PublicationDay data;
};

struct cell{
	Libro content;
	cell* next;
};

typedef cell* Libreria;

bool readFile(std::ifstream&, Libro&);
void insertNewBook(Libreria&);
void printLibrary(const Libreria&);
void sortLibrary(Libreria&);
void pickBook(Libreria&, std::string);
bool findBook(Libreria&, std::string);
int howManyBook(Libreria&);
Libro findBiggest(Libreria&);
Libro findSmallest(Libreria&);

#endif
