// Es_9 avanzato:  Scrivere una funzione ricorsiva che, data una lista, ne restituisce una con gli elementi in ordine inverso. Per la progettazione
// della funzione, considerare due varianti, ossia il caso in cui si abbia una diversa lista da restituire in output, e quello in cui
// modifica direttamente la lista di input.

#include <iostream>

using namespace std;

typedef int Elem;

struct cell{
	Elem data;
	cell* next;
};

typedef cell* list;

void printList(const list& l){
	list lCopy = l;
	while(lCopy != nullptr){
        cout << lCopy->data << endl;
        lCopy = lCopy->next;
    }
}

void headInsert(list& l, Elem x){
	cell* aux = new cell;
	aux->data = x;
	aux->next = l;
	l = aux;
}

void reverse(list& l, list& lRev){
	if (l->next == nullptr){
		headInsert(lRev,l->data);
		return;
	}
	headInsert(lRev,l->data);
	reverse(l->next,lRev);
}

void reverseInPlace(list& l){
	list temp = nullptr;
	reverse(l,temp);
	while(l!= nullptr){
		list lCopy = l;
		l = l->next;
		delete lCopy;
	}
	l = temp;
}

int main(){

	list a = nullptr;
	headInsert(a,1);
	headInsert(a,2);
	headInsert(a,3);

	printList(a);
	cout << endl;

	list b = nullptr;
	reverse(a,b);

	printList(b);
	cout << endl;

	reverseInPlace(a);
	printList(a);
	cout << endl;

}
