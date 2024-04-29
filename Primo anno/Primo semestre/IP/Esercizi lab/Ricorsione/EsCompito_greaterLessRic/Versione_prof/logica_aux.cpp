#include "logica.h" 

struct cell {
    int head;  // una sequenza e' costituita da una head che è un elemento
    Seq  tail;  // e da una tail che e' a sua volta una sequenza (avete mai pensato che e' intrinsecamente una definizione ***ricorsiva*** di sequenza?)
};


void create_Seq(Seq &s) {
    s=nullptr;
}

bool isEmpty(const Seq s)  
{
   return (s == nullptr);
}


/****************************************************************/
void insert_Elem(const int x,  Seq &s)
{
    
    cell *aux;
    aux = new cell; 
    aux->head=x;
    aux->tail=s;
    s = aux;
}

void print_Seq(const Seq&s) {
    if (s==nullptr)
        cout << endl;
    else {
        cout << s->head << "//";
        print_Seq(s->tail);
    }
}


/****************************************************************/
/* eOl (existsOneLesser) restituisce true se nella sequenza c'e' ALMENO un valore minore dell'elemento passato come primo argomento  */

bool eOl(const int elem, const Seq& s){
    // caso base negativo: se la sequenza e' vuota la proprieta' "esiste elemento.." e' false
   if (isEmpty(s)) return false;
    // caso base positivo: esiste un elemento...
   if (s->head < elem) return true;
   else return eOl(elem, s->tail);
}




/* aGe (allGreaterEqual) restituisce true se tutti gli elementi della sequenza sono maggiori o uguali all'elemento passato come primo argomento */

bool aGe(const int elem, const Seq& s){
    // caso base positivo: se la sequenza e' vuota la proprieta' "per ogni" vale
    if (isEmpty(s)) return true;
    // caso base negativo: se trovo un elemento minore di elem allora il perogni e' false
    if (s->head < elem) return false;
    else return aGe(elem,s->tail);

    
// NB: le due funzioni di cui sopra sono una la complementare dell'altra per cui la sequente implementazione alternativa potrebbe essere usata
    
/*
 bool aGe(const int elem, const Seq l){
       return (!eOl(elem, l));
    }
*/

