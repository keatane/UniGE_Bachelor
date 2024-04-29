#include <iostream>
#include <fstream>

using namespace std;

struct cell;           // definita nel file ausiliario
typedef cell *Seq;     // una sequenza e' univocamente identificata dal puntatore al suo primo elemento

void create_Seq(Seq &);
void insert_Elem(const int,  Seq &);    /* inserisce l'elemento passato come primo argomento in prima posizione */

bool isEmpty(const Seq&);                  /* restituisce il valore dell'espressione booleana "la sequenza e' vuota" */

void print_Seq(const Seq&);



bool aGe(const int, const Seq); /* aGe (allGreaterEqual) restituisce true se tutti gli elementi della sequenza sono maggiori o uguali all'elemento passato come primo argomento */

bool eOl(const int, const Seq); /* eOl (existsOneLesser) restituisce true se nella sequenza c'e' ALMENO un valore minore dell'elemento passato come primo argomento  */

