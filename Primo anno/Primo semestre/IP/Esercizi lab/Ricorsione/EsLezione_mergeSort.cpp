#include <iostream>
using namespace std;

struct Cell{
	int data;
	Cell* next;
};
typedef Cell* List;

/* function prototypes */

void MergeSort(List* headRef); // Riordina la parte di list
void HalfSplit(List source, List* frontRef, List* backRef); // funz ausiliaria, divide a metà la lista (parte sx, parte dx) (crea puntatori che individua le teste delle parti)
List Merge(List a, List b); // funz ausiliaria, unisce le parti di lista ordinate

void push(List& head_ref, int new_data); // aggiunge elementi in testa alla lista
void printList(List Cell);

int main()
{
	// Start with the empty list
	List L1 = NULL;
	push(L1,15);
	push(L1,10);
	push(L1,5);
	push(L1,20);
	push(L1,3);
	push(L1,2);

	cout << "Original linked list: \n";
	printList(L1);

	// Merge and order
	MergeSort(&L1);

	cout << "Sorted linked list: \n";
	printList(L1);
}

void MergeSort(List* headRef){

	List head = *headRef;
	List a;
	List b;

	//Caso base, length = 0 o 1
	if (head == NULL || head->next == NULL) {
		return;
	}

	// Split head into 'a' and 'b' sublists
	HalfSplit(head, &a, &b);

	// Recursively sort the sublists
	MergeSort(&a); // spacchetto fino ad arrivare a un singolo elemento
	MergeSort(&b);

	// answer = merge the two sorted lists together
	*headRef = Merge(a,b); // la prima unione è fra singoli elementi
}


List Merge(List a, List b){

	List c = NULL;

	if (a == NULL){ //base
		return b; //elementi rimanenti in b
	}
	else if (b == NULL){ //base
		return a; //elementi rimanenti in a
	}

	if (a->data <= b->data){
		c = a; // analogo a tailInsert(c,a->data) se inserisco una funzione che inserisce in coda
		c->next = Merge(a->next, b);
	}
	else{
		c = b;
		c->next = Merge(a, b->next);
	}
	return c;

}

void HalfSplit(List source, List* frontRef, List* halfRef){ // quindi list* (puntatore a puntatore a cell, puntatore a lista) e list& sono analoghi
    // frontRef è la testa della prima metà
    // halfRef è la testa della seconda metà

	List fast = source->next;
	List slow = source;

	/* Advance 'fast' two Cells, and advance 'slow' one Cell */
	// Se fast va avanti di due, ovviamente slow si ritroverà a metà della lista quando fast è NULL
	while (fast != NULL){
		fast = fast->next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    /* 'slow' is before the midpoint in the list, so split it in two at that point. */
	*frontRef = source;
	*halfRef = slow->next; // in caso di lista dispari un elemento in più è presente nella prima lista
	slow->next = NULL; // rompo il collegamento fra le due parti (salvando l'elemento in halfRef)

}

void push(List& head_ref, int new_data){

	// Allocate Cell
	Cell* new_Cell = new Cell;

	// put in the data
	new_Cell -> data = new_data;

	// link the old list off the new Cell
	new_Cell -> next = head_ref;

	// move the head to point to the new Cell
	head_ref = new_Cell;

}

void printList(List Cell){
	while (Cell != NULL){
		cout << Cell->data << " ";
		Cell = Cell ->next;
	}
	cout << endl;
}

