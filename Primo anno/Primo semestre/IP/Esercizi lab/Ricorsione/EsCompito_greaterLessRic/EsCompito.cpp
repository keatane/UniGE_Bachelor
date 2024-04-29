#include <fstream>
#include <iostream>
#include <stdlib.h> // srand, rand

using namespace std;

typedef int Elem;

struct cell{
	Elem data;
	cell* next;
};

typedef cell *Seq; // una sequenza è univocamente identificata dal puntatore al suo primo elemento
const int FINEINPUT = -1000000; // serve per leggere sequenze da file: dobbiamo sapere quando termnare la lettura

const Seq EMPTY_SEQ = nullptr; // costante che indica la sequenza vuota

Seq insertElem(const int x, const Seq s) // inserisce l'elemento passato come primo argomento in prima posizione
{
	cell* aux = new cell; // cell* = Seq
	aux->data = x;
	aux->next = s;
	return aux; // ritorno una nuova sequenza
}

int size(const Seq s) // restituisce il numero degli elementi di una sequenza;
{
	Seq temp;
	temp = s;
	int counter = 0;
	while(temp != nullptr){
		counter++;
		temp=temp->next;
	}
	return counter;
}

bool member(const int x, const Seq s) // restituisce il valore dell'espressione boleana 'l'elemento appartiene alla sequenza'
{
	Seq temp;
	temp = s;
	while(temp != nullptr && temp->data != x){
		temp=temp->next;
	}
	if (temp == nullptr) // giunto in fondo, elem not found
		return false;
	else
		return true;
}

bool isEmpty(const Seq s) // restituisce il valore dell'espressione booleana 'la sequenza è vuota'
{
	return (s==nullptr);
}

bool aGe(const int x, const Seq s) // aGe (allGreaterEqual) restituisce true se tutti gli elementi della sequenza sono maggiori o uguali all'elemento passato come primo argomento, versione ricorsiva.
{
	if (s == nullptr)
		return true; // giunto in fondo, non si è interrotto prima (ho controllato tutti gli elementi)
	if (s->data < x)
		return false;
	return aGe(x,s->next);
}

bool eOl(const int x, const Seq s) // eOl (existsOneLesser) restituisce true se nella sequenza c'è un valore minore dell'elemento passato come primo argomento, versione ricorsiva.
{
	if (s == nullptr)
		return false; // giunto in fondo, non si è interrotto prima (non ho trovato nemmeno un elemento)
	if (s->data < x)
		return true;
	return eOl(x,s->next);
}


// FUNZIONI DI UTILITA'

Seq seqReadFromFile(string str)
{
	Seq s = nullptr;
	ifstream f;
	f.open(str);
	if (f.is_open()){
		Elem x;
		while(f >> x){ // finchè vi sono elementi nel file
		
		// Debug
		//cout << x << endl;
		
		s = insertElem(x,s);
		}
	}
	f.close();
	return s;
}
Seq seqReadFromStdin()
{
	Seq s = nullptr;
	cout << "Inserisci 3 valori da inserire nella sequenza: ";
	Elem x;
	cin >> x;
	s = insertElem(x,s);
	cin >> x;
	s = insertElem(x,s);
	cin >> x;
	s = insertElem(x,s);

	return s;
}
void seqPrint(const Seq s)
{
	Seq temp = s;
	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Seq s = nullptr;
	//s = seqReadFromStdin();
	s = seqReadFromFile("compito.txt");
	seqPrint(s);

	cout << "Dimensione sequenza: " << size(s) << endl;

	cout << "Lista vuota: " << boolalpha << isEmpty(s) << endl;

	cout << "Elem contenuto?" << endl;
	Elem x;
	cin >> x;
	cout << boolalpha << member(x,s) << endl;

	cout << "Tutti valori sono piu' grandi di quello inserito: " << boolalpha << aGe(5,s) << endl;
	cout << "Almeno un valore piu' piccolo di quello inserito: " << boolalpha << eOl(5,s) << endl;

}
