// test.cpp

#include <iostream>
#include <string>
#include "queue.h"

using namespace std;

int main()
try{
	queue q;
	create_empty(q);
	Elem x;
	string op;
	while(true){
		cout << "op (enqueue,dequeue,front,back,exit): ";
		cin >> op;
		// N.b. si ricordi che l'eventuale implementazione di switch funziona con singoli numeri o caratteri, NON stringhe!
		if (op=="enqueue"){
			cin >> x;
			enqueue(s,x);
		}
		else if (op=="dequeue"){
			try{ // Porre il try catch interno mi permette di non compiere una certa operazione ma far comunque continuare il programma
				dequeue(s);
			} catch(string st){
				cerr << st << endl;
			}
		}
		else if (op=="front"){
			try{
				cout << "chi e' il primo?: " << front(s) << endl;
			} catch(string st){
				cerr << st << endl;
			}
		}
		else if (op=="back"){
			try{
				cout << "chi e' l'ultimo?: " << back(s) << endl;
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
	cerr << st << endl;
}