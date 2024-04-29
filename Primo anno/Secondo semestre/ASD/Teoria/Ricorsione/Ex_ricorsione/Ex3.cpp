#include <cstddef> // serve per il NULL
#include <iostream>
#include <stdexcept>
#include <fstream> 

using namespace std;

// Sequenza senza ripetizioni e in cui l'inserimento avviene in testa - tranne nel caso in cui si adotti l'operazione insertElemInOrder; viene implementata con strutture collegate mediante puntatori e tipo base Elem dotato di ordinamento

namespace seq{

/**************************** Codici di errore ********************************************/
enum Error {OK, FAIL, PRESENT, EMPTY, NOT_FOUND};

/**************************** Tipi e costanti *********************************************/

typedef int Elem;      // tipo base 
struct cell;           // definita nel file ausiliario
typedef cell *Seq;     // una sequenza e' univocamente identificata dal puntatore al suo primo elemento
const int FINEINPUT = -1000000;
const Seq EMPTY_SEQ = NULL;


/************************* operazioni stateful  ******************************************/

void createEmpty(Seq&);                    /* crea la sequenza vuota */
void deleteSeq(Seq&);                      /* "smantella" una sequenza liberando la memoria allocata con le new */
Error insertElem(const Elem x, Seq& s);    /* inserisce l'elemento in prima posizione; restituisce FAIL in caso di errore ed PRESENT se l'elemento era gia' presente; se tutto ok, restituisce OK */
Error insertElemInOrder(const Elem, Seq&); /* inserisce un elemento nella sequenza rispettando l'ordinamento del tipo Elem [si assume che la sequenza in cui si inserisce sia correttamente ordinata]; restituisce FAIL in caso di errore e PRESENT se l'elemento era gia' presente; se tutto ok, restituisce OK */
Error deleteElem(const Elem, Seq&);	   /* cancella un elemento dalla sequenza (senza assumere che la sequenza sia ordinata); restituisce EMPTY se la sequenza è vuota, NOT_FOUND se l'elemento non e' stato trovato, OK altrimenti */
int size(const Seq&);                      /* restituisce il numero degli elementi di una sequenza */
bool member(const Elem, const Seq&);       /* restituisce il valore dell'espressione booleana "l'elemento appartiene alla sequenza" */
bool isEmpty(const Seq&);                  /* restituisce il valore dell'espressione booleana "la sequenza e' vuota" */
Error reverse(Seq&);                       /* inverte l'ordine degli elementi nella sequenza; restituisce OK */

Seq reverse2(Seq);                         /* inverte l'ordine degli elementi nella sequenza; restituisce il puntatore al primo elemento */
Seq reverse3(Seq);                         /* inverte l'ordine degli elementi nella sequenza; restituisce il puntatore al primo elemento */

int multRec(Seq);
int sumRec(Seq);
bool existsLesserThan(int, Seq); 
bool areAllGreaterEqualThan(int e, Seq l);

}



seq::Seq seqReadFromFile(string);
seq::Seq seqOrderedReadFromFile(string);
seq::Seq seqReadFromStdin();
void seqPrint(const seq::Seq&);