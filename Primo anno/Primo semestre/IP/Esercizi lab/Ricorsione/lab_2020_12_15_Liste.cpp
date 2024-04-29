#include<iostream> 
using namespace std; 

/* Link list Cell */
struct Cell { 
	int data; 
	Cell* next; 
}; 
typedef Cell* List;

/* function prototypes */
void MergeSort(List* headRef);
void HalfSplit(List source, List* frontRef, List* backRef); 
List Merge(List a, List b); 

void push(List& head_ref, int new_data);
void printList(List Cell);

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(List* headRef) 
{ 
	List head = *headRef; 
	List a; 
	List b; 

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	HalfSplit(head, &a, &b); 

	MergeSort(&a); 
	MergeSort(&b); 

	*headRef = Merge(a, b); 
} 


List Merge(List a, List b) 
{ 
	List result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if (a->data <= b->data) { 
		result = a; 
		result->next = Merge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = Merge(a, b->next); 
	} 
	return (result); 
} 

/* Split the Cells of the given list into front and back halves, 
	and return the two lists using the reference parameters. */
void HalfSplit(List source, List* frontRef, List* halfRef) 
{ 
	List fast; 
	List slow; 
	slow = source; 
	fast = source->next; 

	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	*frontRef = source; 
	*halfRef = slow->next; 
	slow->next = NULL; 
} 


/* Function to print Cells in a given linked list */
void printList(List Cell) 
{ 
	while (Cell != nullptr) { 
		cout << Cell->data << " "; 
		Cell = Cell->next; 
	} 
    cout << endl;
} 

/* Function to insert a Cell at the beginging of the linked list */
void push(List& head_ref, int new_data) 
{ 
	Cell* new_Cell = new Cell; 
	new_Cell->data = new_data; 
	new_Cell->next = head_ref; 
	head_ref = new_Cell; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	List a = nullptr; 

	push(a, 15); 
	push(a, 10); 
	push(a, 5); 
	push(a, 20); 
	push(a, 3); 
	push(a, 2); 

	cout << "Original linked list: \n"; 
	printList(a);

	MergeSort(&a); 

	cout << "Sorted linked list: \n"; 
	printList(a); 

	return 0; 
} 

