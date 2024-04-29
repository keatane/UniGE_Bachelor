/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo le liste circolari semplici viste a lezione (ovvero strutture collegate 
// semplicemente mediante puntatori) i cui elementi sono delle struct (vedere la struct people_t nel codice) che contengono il 
// cognome (family_name), nome (first_name) anno di nascita (born_on) e luogo di nascita (born_in) di una persona.
//
// ad esempio:
// "Rossi", "Carlo", 1980, "Milano"

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:
    
/**************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

   Sviluppare le seguenti funzioni C/C++:

   1) print_list() che stampa gli elementi contenuti nella lista senza effettuare nessun ordinamento. 
      Se ad esempio nella lista sono contenute le seguenti 3 celle:
      {"Neri", "Gianno", 1990, "Genova}; {"Bianchi", "Gino", 1970, "Roma"}; {"Rossi", "Carlo", 1980, "Milano"}; 
      la funzione dovra' stampare il seguente testo:
      Neri Gianno, nato nel 1990 a Genova
      Bianchi Gino, nato nel 1970 a Roma
      Rossi Carlo, nato nel 1980 a Milano
      Nel caso la lista sia vuota la funzione non deve stampare nulla
      
   2) tail_insert() che inserisce una nuova cella alla fine della lista
      Se ad esempio nella lista sono contenute le seguenti 2 celle:
      {"Neri", "Gianno", 1990, "Genova}; {"Bianchi", "Gino", 1970, "Roma"}; 
      ed aggiungiamo {"Rossi", "Carlo", 1980, "Milano"}
      la lista diventera' la seguente:
      {"Neri", "Gianno", 1990, "Genova}; {"Bianchi", "Gino", 1970, "Roma"}; {"Rossi", "Carlo", 1980, "Milano"}; 
*/

#include <iostream>
using namespace std;
/****************************************************************/
// Struct, typedef e const
/****************************************************************/

struct people_t {
	std::string family_name;
	std::string first_name;
	int born_on;
	std::string born_in;
};

struct cell {
	people_t payload;
	cell* next;
};

typedef cell* basic_list;

const basic_list emptyList = NULL;

/****************************************************************/
// Implementazione delle liste circolari semplici
/****************************************************************/

// Inserisce una nuova cella che contiene il valore 'new_value' all'inizio della lista (in testa)
void head_insert(basic_list& list, people_t new_value) {
	cell* aux = new cell;
	aux->payload = new_value;
	if (list == emptyList) 
		aux->next = aux;
	else 
		{cell* tmp = list;
		 while (tmp->next != list)
			tmp = tmp->next;
		tmp->next = aux;
		aux->next = list;
		}
    
    list = aux;
}

// Stampa gli elementi contenuti nella lista. Nel caso la lista sia vuota la funzione non deve stampare nulla
void print_list(std::ostream& output_stream, basic_list list) {
   // *** INSERIRE QUI IL VOSTRO CODICE, E' POSSIBILE AGGIUNGERE FUNZIONI AUSILOIARIE SE NECESSARIO *** 
}

// Inserisce una nuova cella che contiene il valore 'new_value' alla fine della lista (in coda)
void tail_insert(basic_list& list, people_t new_value) {
    // *** INSERIRE QUI IL VOSTRO CODICE, E' POSSIBILE AGGIUNGERE FUNZIONI AUSILOIARIE SE NECESSARIO *** 
}

/****************************************************************/
// MAIN con casi di test
/****************************************************************/
int main(int argc, char* argv[]) {
    // definiamo una lista
	basic_list my_list = emptyList;
	// definiamo due persone p1 e p2
	people_t p1 = {"Rossi", "Carlo", 1980, "Milano"};
	people_t p2 = {"Bianchi", "Gino", 1970, "Roma"};
	// inseriamo p1 e p2 nella lista usando head_insert() (in testa)
	head_insert(my_list, p1);
	head_insert(my_list, p2);
	cout << "****** ESECUZIONE  ****** " << endl;
	cout << "*** FUNZIONE 1 *** " << endl;
	// stampiamo la lista
	cout << "* INIZIO STAMPA *" << endl;
	print_list(cout, my_list);
	cout << "* FINE STAMPA *" << endl;
	cout << "\nLa tua funzione 1 e' corretta se subito sopra, tra INIZIO e FINE, ha stampato: " << endl;
	cout << "Bianchi Gino, nato nel 1970 a Roma" << endl;
    cout << "Rossi Carlo, nato nel 1980 a Milano" << endl;
	
	// definiamo una nuova persona p3
	people_t p3 = {"Neri", "Gianno", 1990, "Genova"};
	// inseriamo p3 nella lista usando tail_insert() (in coda)
    tail_insert(my_list, p3);
    cout << "\n*** FUNZIONE 2 *** " << endl;
	// stampiamo la lista
	cout << "* INIZIO STAMPA *" << endl;
	print_list(cout, my_list);
	cout << "* FINE STAMPA *" << endl;
	cout << "\nLa tua funzione 2 e' corretta se subito sopra, tra INIZIO e FINE, ha stampato: " << endl;
	cout << "Bianchi Gino, nato nel 1970 a Roma" << endl;
    cout << "Rossi Carlo, nato nel 1980 a Milano" << endl;
	cout << "Neri Gianno, nato nel 1990 a Genova" << endl;
	
	// inserito solo per wxDev-C++
	cout << endl;
	char c;
	cout << "inserisci un valore per terminare" << endl;
	cin >> c;
	
}



