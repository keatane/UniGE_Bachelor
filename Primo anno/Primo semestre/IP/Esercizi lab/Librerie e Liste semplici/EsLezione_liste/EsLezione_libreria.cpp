// Es in lezione: Liste semplici e libreria

#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main()
try{
	list L1 = nullptr;
	headInsert(L1, "head1");
	headInsert(L1, "head2");
	headInsert(L1, "head3");

	read(L1);
	tailInsert(L1, "end");

	print(L1);

	//deleteAll(L1);
	//print(L1);
	
	cout << "Inserti index\n";
	int n;
	cin >> n;
	cout << n << 2-th element is " << get(L1,n) << endl;
}
catch(string s){
	cout << s << endl;
}