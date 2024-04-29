#include "string_ord_list.h"

int main()
try{
	ordList L1 = nullptr;
	ordList L2 = nullptr;
	
	std::cout << "--Riempimento prima lista--\n";
	read(L1);
	std::cout << "--Riempimento seconda lista--\n";
	read(L2);
	std::cout << std::endl;
	std::cout << "--Stampa della prima lista ordinata--\n";
	print(L1);
	std::cout << std::endl;
	std::cout << "--Stampa della seconda lista ordinata--\n";
	print(L2);
	std::cout << std::endl;
	
	/*
	std::cout << "Rimozione di un'occorrenza di 'ciao' dalla prima lista\n";
	deleteOnce(L1, "ciao");
	print(L1);
	std::cout << std::endl;
	*/
	
	/*
	std::cout << "Rimozione di tutte le occorrenze di 'ciao' dalla prima lista\n";
	deleteAll(L1, "ciao");
	print(L1);
	std::cout << std::endl;
	*/
	
	/*std::cout << "Inserisci index\n";
	int n;
	std::cin >> n;
	std::cout << n << "-th element is " << getElem(L1,n) << std::endl;
	*/
	
	std::cout << "Inserisci index\n";
	int n;
	std::cin >> n;
	deleteAt(L1,n);
	print(L1);
	std::cout << std::endl;
	
	//std::cout << "Le liste hanno stessi elementi: " << std::boolalpha << are_equal(L1,L2) << std::endl;
	std::cout << "--Stampa della lista concatenata--\n";
	ordList L3 = concat(L1,L2);
	print(L3);
	std::cout << std::endl;
	
	std::cout << "--Stampa della lista di unione senza ripetizioni--\n";
	ordList L4 = unione(L1,L2);
	print(L4);
	std::cout << std::endl;
	std::cout << "--Stampa della lista di elementi comuni a entrambe le liste inserite--\n";
	ordList L5 = intersect(L1,L2);
	print(L5);
	std::cout << std::endl;
}
catch(std::string s){
	std::cout << s << std::endl;
}
