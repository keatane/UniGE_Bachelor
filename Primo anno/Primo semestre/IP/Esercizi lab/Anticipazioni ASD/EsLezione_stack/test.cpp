// test.cpp

#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
try{
	stack s;
	create_empty(s);
	Elem x;
	string op;
	while(true){
		cout << "op (push,pop,top,exit): ";
		cin >> op;
		// N.b. si ricordi che l'eventuale implementazione di switch funziona con singoli numeri o caratteri, NON stringhe!
		if (op=="push"){
			cin >> x;
			push(s,x);
		}
		else if (op=="pop"){
			try{ // Porre il try catch interno mi permette di non compiere una certa operazione ma far comunque continuare il programma
				pop(s);
			} catch(string st){
				cerr << st << endl;
			}
		}
		else if (op=="pop"){
			try{
				cout << "chi e' in cima?: " << top(s) << endl;
			} catch(string st){
				cerr << st << endl;
			}
		}
		else if (op=="exit")
			break;
		else
			cout << "comando sconosciuto\n";
	}
	
	cout << "fine\n";
} // non necessario
catch(string st){
	cerr << s << endl;
}