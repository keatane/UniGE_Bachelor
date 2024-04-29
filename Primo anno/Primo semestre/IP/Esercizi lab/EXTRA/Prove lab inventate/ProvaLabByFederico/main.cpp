#include <iostream>
#include "queue.h"

using namespace std;

int main()
try{
	concessionaria c;
	crea_concessionaria(c);
	cout << "Concessionaria vuota: " << boolalpha << empty(c) << endl;
	Auto a;
	a.casa = "Kev";
	a.modello = "Honda";
	a.dataArrivo.anno = 2001;
	a.dataArrivo.mese = 3;
	a.dataArrivo.giorno = 24;
	enqueue(c,a);
	
	cout << "Concessionaria:\n";
	print(c);
	
	cout << "Elemento rimosso: " << dequeue(c).modello << endl;
	
	read_concessionaria(c);
	cout << "Concessionaria aggiornata:\n";
	print(c);
	

	cout << "Auto 'Honda' presente: " << boolalpha << is_in(c,a) << endl;

	//Definisco una data
	data d;
	d.anno = 2020;
	d.mese = 1;
	d.giorno = 1;
	
	cout << "Non vendute: " << check_old(c,d) << endl;
	cout << "Auto venduta: " << sold(c,a).modello << endl;
	print(c);
	
	enqueue(c,a);
	concessionaria k;
	crea_concessionaria(k);
	
	transfer_auto(c,k,a);
	cout << "Concessionaria 2: " << endl;
	print(k);
	enqueue(c,a);
	transfer_last_auto(c,k,2);
	cout << "Concessionaria 2: " << endl;
	print(k);
	enqueue(c,a);
	
	transfer_old_auto(k,c,d); // Riporto alla prima concessionaria alcune auto
	
	cout << "Lista non ordinata:\n";
	print(c);
	sort(c);
	cout << "Lista ordinata:\n";
	print(c);
}
catch(string &s){
	cout << s << endl;
}
