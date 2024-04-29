#include <iostream>
#include <fstream>
#include "book.h"

//Definizione di funzioni

bool readFile(std::ifstream& f, Libro& b){
	f>>b.title;
	f>>b.publisher;
	f>>b.writer;
	f>>b.NoP;
	f>>b.coverColor;
	f>>b.data.day;
	f>>b.data.month;
	f>>b.data.year;
	return f.good();
} 

// Inserimento in coda
void insertNewBook(Libreria& l){
	Libro b;
	std::ifstream f;
	f.open("datiBook.txt");
	if (f.is_open()){
		while (readFile(f,b)){
		std::cout << b.title << std::endl;
			if (l==nullptr){
					cell* aux = new cell;
					aux->next = nullptr;
					aux->content = b;
					l = aux;
				}
			else{
				cell* aux = new cell;
				aux->next = nullptr;
				aux->content = b;
				cell* temp = l;
				while(temp->next != nullptr){
					temp = temp->next;
				}
				temp->next = aux;
			}
		}
	}
	f.close();
}

void printLibrary(const Libreria& l){
	cell* temp = l;
	if(temp==nullptr) return;
	std::cout << temp->content.title << std::endl;
	printLibrary(temp->next);
}

//Ordinamento alfabetico (titoli)
void sortLibrary(Libreria& l){
	for (cell* i=l; i!=nullptr; i=i->next){
		cell* idx = i;
		for (cell* j=i->next; j!=nullptr; j = j->next)
			if ((j->content.title) < (idx->content.title))
				idx = j;
		Libro temp = i->content;
		i->content = idx->content;
		idx->content = temp;
	}
}

void pickBook(Libreria& l, std::string title){
	cell* temp = l;
	cell* prec = temp;
	while(temp!=nullptr){
		if (temp->content.title == title) break;
		prec = temp;
		temp = temp->next;
	}
		
	
	if (temp == nullptr){
		std::cout << "Libro non trovato" << std::endl;
		return;
	}
	
	std::cout << "Libro in rimozione:\n";
	std::cout << temp->content.title << std::endl;
	std::cout << temp->content.publisher << std::endl;
	std::cout << temp->content.writer << std::endl;
	std::cout << temp->content.NoP << std::endl;
	std::cout << temp->content.coverColor << std::endl;
	
	// Gestione caso in testa
	if (temp==l){
		l = l->next;
		delete temp;
		return;
	}
	
	// Rimozione dalla lista
	prec->next = temp->next;
	delete temp;
}

bool findBook(Libreria& l, std::string title){
	cell* temp = l;
	/* Iterativa:
	while(temp!=nullptr){
		if (temp->content.title == title) return true;
		temp = temp->next;
	}
	// Titolo non trovato
	return false;
	*/
	if (temp==nullptr) return false;
	if (temp->content.title == title) return true;
	return findBook(temp->next, title);
}

int howManyBook(Libreria& l){
	cell* temp = l;
	int counter = 0;
	while(temp!=nullptr){
		counter++;
		temp = temp->next;
	}
	return counter;
}

Libro findBiggest(Libreria& l){
	cell* max = l;
	for (cell* i=l; i!= nullptr; i=i->next)
		if (i->content.NoP > max->content.NoP)
			max = i;
	return max->content;
}

Libro findSmallest(Libreria& l){
	cell* min = l;
	for (cell* i=l; i!= nullptr; i=i->next)
		if (i->content.NoP < min->content.NoP)
			min = i;
	return min->content;
}
