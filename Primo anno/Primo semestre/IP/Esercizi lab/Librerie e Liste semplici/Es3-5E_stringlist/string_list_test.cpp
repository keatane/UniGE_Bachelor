#include <iostream>
#include "string_list.h"

int main()
try{
	
	list l = nullptr;
	headInsert(l, "ciao");
	
	read(l);
	print(l);
	
	deleteAll(l, "ciao");
	std::cout << "Lista senza 'ciao':\n";
	print(l);

}
catch(...){
	std::cout << "errore\n";
	
}
