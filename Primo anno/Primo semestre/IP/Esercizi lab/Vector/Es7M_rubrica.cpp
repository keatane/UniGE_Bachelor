/* Es_7 di base: Implementare le funzioni che compongono una libreria per la memorizzazione e gestione di una rubrica telefonica utilizzando
struct e std::vector. Oltre alla definizione delle funzioni e dei tipi richiesti per la libreria, dovete, naturalmente, scrivere
un programma per testare le funzioni man mano che le implementate.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact_Str {
	// Membri della struct
	string Name;
	string Surname;
	int PhoneNumber;
};

typedef vector<Contact_Str> PhoneBook; // vector di struct

// typedef serve per dare un nome più significativo a un tipo generico già stabilito
// typedef unsigned char byte; // Chiamiamo byte il tipo unsigned char


void add(PhoneBook&, string, string, int);
void print(const PhoneBook&);
void input(PhoneBook&);
void sortSurnames(PhoneBook&);
int FindPos(const PhoneBook&, string);
void Shift_PhoneBook(PhoneBook&, int);
void add_ord(PhoneBook&, string, string, int);

int main()
{
	PhoneBook rubrica;

	// Input dati - test add
	input(rubrica);

	// Test print
	cout << "\nHai inserito la seguente rubrica:\n";
	print(rubrica);

    // Test sortSurnames
    cout << "\nRubrica ordinata:\n";
	sortSurnames(rubrica);
	print(rubrica);

	//cout << FindPos(rubrica, "den") << endl;

	//cout << "Shift di contatti (con duplicazione)\n";
	//Shift_PhoneBook(rubrica, 1);
	//print(rubrica);

	cout << "\nInserimento contatto, stampa nuova lista:\n";
	add_ord(rubrica, "gualdi", "flaminia", 23);
	print(rubrica);
}

void add(PhoneBook& pb, string s, string n, int p)
{
	Contact_Str voce;
	voce.Name = n;
	voce.Surname = s;
	voce.PhoneNumber = p;

	// Automaticamente viene portato un nuovo contatto in fondo al vector (size aumenta di 1)
	pb.push_back(voce); // Inserisco un intera variabile struct nel vector (anch'esso di tipo struct)
}

void input(PhoneBook& pb){
	string name;
	string surname;
	int phonenumber;

	cout << "Input rubrica (nome/cognome/numero). STOP per fermare input\n";
	cin >> name;
	while (name != "STOP")
	{
		cin >> surname;
		cin >> phonenumber;
		add (pb, surname, name, phonenumber);
		cin >> name; // Altrimenti non viene più chiesto
	}
}

void print(const PhoneBook& pb){

	for(unsigned int i=0; i<pb.size(); ++i){
		cout << i+1 << ". ";
		// pb[i] è un contatto, ovvero una struct, allora pb[i].Name sarà il membro Name del contatto di tipo struct
		cout << pb[i].Name << " " << pb[i].Surname << " ";
		cout << ": " << pb[i].PhoneNumber << endl;
	}
}

void sortSurnames(PhoneBook& pb)
{
    // Bubble sort
	for(unsigned int i=0; i<pb.size(); ++i)
		for(unsigned int j=0; j<pb.size()-1-i; ++j)
			if (pb[j].Surname > pb[j+1].Surname){
				Contact_Str temp = pb[j];
				pb[j]= pb[j+1];
				pb[j+1] = temp;
			}

    /*
    //Insertion sort ridotto:
    for(unsigned int i=1; i<pb.size(); ++i)
        for(unsigned int j=i; j>0 && pb[j].Surname < pb[j-1].Surname; --j){ // Pongo già qui la condizione del corpo del for
            Contact_Str temp = pb[j];
            pb[j] = pb[j-1];
            pb[j-1] = temp;
        }
    */
}

int FindPos(const PhoneBook& pb, string S)
{
	/* Ricerca sequenziale, non binaria
    for(unsigned int i=0; i<pb.size(); ++i)
         if (pb[i].Surname == S){
            cout << "Contatto trovato a indice: ";
            return i;
         }

    // Se sono qui significa che non c'è un contatto trovato
    string near = "a";
    int k = -1; // Nel caso S fosse proprio il primo contatto, non ho alcun indice che indica il contatto prima (non esiste il contatto prima)
    for(unsigned int i=0; i<pb.size(); ++i)
        if (pb[i].Surname < S && pb[i].Surname > near){
            near = pb[i].Surname;
            k = i;
        }
    return k;
	*/

	int mid;
	bool found = false;
	int last = pb.size() - 1;
	int first = 0;

	while (first <= last && !found)
	{

		mid = (first + last)/2;
		if (pb[mid].Surname == S)
				found = true;
		else
			if(S < pb[mid].Surname) last = mid-1;
			else
				first = mid+1;

	}
	if (found) return mid;
	else return last; // Corrisponde all'ultimo contatto secondo l'ordine alfabetico (se non è found, first è incrementato (> last!)
}

void Shift_PhoneBook(PhoneBook& pb, int pos)
{
    pb.resize(pb.size()+1);
    for(unsigned int i=pb.size()-1; i>pos; --i)
        pb[i] = pb[i-1];
}

void add_ord(PhoneBook& B, string surname, string name, int phoneNumber)
{
    int pos_prec = FindPos(B, surname); // posizione precedente rispetto a quella dove va messo il nuovo contatto
    Shift_PhoneBook(B, pos_prec);
    B[pos_prec+1].Surname = surname;
    B[pos_prec+1].Name = name;
    B[pos_prec+1].PhoneNumber = phoneNumber;
}
