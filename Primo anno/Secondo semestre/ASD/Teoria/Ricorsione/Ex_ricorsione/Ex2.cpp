#include "ricorsione.h"

using namespace seq;

struct seq::cell {
    Elem head;  // una sequenza e' costituita da una head che è un elemento
    Seq  tail;  // e da una tail che e' a sua volta una sequenza (e' intrinsecamente una definizione ***ricorsiva*** di sequenza)
};


/****************************************************************/
/****************************************************************/

void seq::createEmpty(Seq& s)
{
   deleteSeq(s);    // potrei chiamare createEmpty su una sequenza esistente; prima la svuoto
   s = EMPTY_SEQ;   // poi le assegno il valore EMPTY_SEQ
}

/****************************************************************/
bool seq::isEmpty(const Seq& s)  
{
   return (s == EMPTY_SEQ);  
// ***NON*** SCRIVERE ASSOLUTAMENTE
// if (s == EMPTY_SEQ) return true; else return false;  
// E' UN PESSIMO MODO DI IMPLEMENTARE UNA FUNZIONE BOOLEANA CHE DEVE SOLO RESTITUIRE IL VALORE DI UN'ESPRESSIONE
}

/****************************************************************/
void seq::deleteSeq(Seq& s){
   if (!isEmpty(s))       // se la sequenza e' vuota non c'e' niente da rimuovere, altrimenti
   {
      deleteSeq(s->tail); // chiamo ricorsivamente deleteSeq sulla coda
      delete s;           // dealloco il puntatore al primo elemento
   }
}


/****************************************************************/
Error insertElemInOrderAux(cell* aux, Seq& current, Seq& prev)
// assumo che questa funzione ausiliaria venga chiamata con prev != EMPTY_SEQ (il controllo viene fatto in insertElemInOrder)
{    
    if (isEmpty(current) || current->head > aux->head) // devo inserire l'elemento dopo prev e prima di current; notare la valutazione lazy da sinistra a destra della disgiunzione (isEmpty(current) || current->head > aux->head) che garantisce che se isEmpty(current) l'espressione a destra della disgiunzione non verra' valutata  
       {
          aux->tail=current;
          prev->tail=aux;   
          return OK;
       }  

    if (!isEmpty(current) || current->head < aux->head) // non sono ancora nel punto giusto: richiamo ricorsivamente sulla coda della lista cambiando gli argomenti per spostarmi in avanti di una cella nella lista
       return insertElemInOrderAux(aux, current->tail, current);

    return OK; // aggiunto per evitare warning In function ‘seq::Error insertElemInOrderAux(seq::cell*, seq::cell*&, seq::cell*&)’: ./ricorsione_aux.cpp:52:1: warning: control reaches end of non-void function [-Wreturn-type]

}


Error seq::insertElemInOrder(const Elem x, Seq& s)
{
    if (member(x,s))           // verifico per prima cosa se l'elemento e' gia' presente, per non ri-inserirlo
       return PRESENT;
 
    cell *aux;
    try  { aux = new cell; }
    catch(...) { return FAIL;} //heap esaurito
    aux->head=x;
    aux->tail=EMPTY_SEQ;
    
    if (isEmpty(s) || s->head>x){ // la lista e' vuota oppure sono all'inizio della lista e devo aggiungere prima del primo elemento; questo caso va trattato a parte
        aux->tail=s;
        s=aux;
        return OK;
    }
    else // altrimenti chiamo insertElemInOrderAux
        return insertElemInOrderAux(aux, s->tail, s);

   
}

/****************************************************************/
Error seq::insertElem(const Elem x, Seq& s) 
// insertElem aggiunge sempre in prima posizione; non rispetta quindi l'ordine "temporale" con cui gli elementi vengono inseriti, ma e' molto piu' efficiente rispetto a un inserimento in coda; se stiamo implementando un insieme, in cui la posizione degli elementi non conta, va benissimo inserire nel punto che rende l'operazione piu' efficiente
{
    if (member(x, s)) 
       return PRESENT; // l'elemento e' gia' presente, non lo aggiungo

    cell *aux;
    try  { aux = new cell; }
    catch(...) { return FAIL;} //heap esaurito
    aux->head=x;
    aux->tail=s;
    s = aux;
    return OK;
}

/****************************************************************/
Error deleteElemAux(const Elem x, Seq& current, Seq& prev)
// se si sa che la sequenza è implementata mediante una lista ordinata, e' possibile ottimizzare il codice; in questo caso non facciamo alcuna assunzione
{
    if (isEmpty(current)) 
       return NOT_FOUND; // se arrivo in fondo alla lista senza trovare l'elemento vuole dire che non c'é (il caso di sequenza inizialmente vuota e' trattato a parte nella funzione principale deleteElem)

    if (!isEmpty(current) && current->head!=x) // se l'elemento da cancellare non e' quello corrente, richiamo ricorsivamente sulla coda della lista cambiando gli argomenti per spostarmi in avanti di una cella nella lista
        return deleteElemAux(x, current->tail, current);

    if (!isEmpty(current) && current->head==x) // l'elemento corrente e' quello da cancellare: lo rimuovo aggiustando i puntatori
        { 
         cell *tmp = current; 
         prev->tail=current->tail;
         delete tmp; 
         return OK;
        }

    return OK; // aggiunto per evitare warning In function ‘seq::Error deleteElemAux(seq::Elem, seq::cell*&, seq::cell*&)’: ./ricorsione_aux.cpp:106:1: warning: control reaches end of non-void function [-Wreturn-type]

}

Error seq::deleteElem(const Elem x, Seq& s)
{
    if  (isEmpty(s))
        return EMPTY;

    if (s->head == x)
        {
        cell *tmp = s;
        s = tmp->tail;
        delete tmp;
        return OK;
        }
    else
        return deleteElemAux(x, s->tail, s);
}


/****************************************************************/
int seq::size(const Seq& s)
{
   if (isEmpty(s))  // se la sequenza e' vuota la sua cardinalita' e' 0 
      return 0; 
   else 
      return size(s->tail)+1; // altrimenti e' la cardinalita' del resto della sequenza + 1
}


/****************************************************************/
bool seq::member(const Elem e, const Seq& s)
// se si sa che la sequenza è implementata mediante una lista ordinata, e' possibile ottimizzare il codice; in questo caso non facciamo alcuna assunzione
{
   if (isEmpty(s))  // se la sequenza e' vuota l'elemento non c'e': restituisco false
      return false; 
   
   if (s->head == e)  // se la head e' l'elemento cercato restituisco true
      return true;
   else 
      return member(e, s->tail); // altrimenti chiamo ricorsivamente sulla coda, restituendo il risultato della chiamata ricorsiva
}



/****************************************************************/
Error seq::reverse(Seq& l) // VERSIONE VISTA A IP, CON PARAMETRO PASSATO PER RIFERIMENTO
{
   if (isEmpty(l) || isEmpty(l->tail)) return OK;
   Seq l1 = l->tail;
   seq::reverse(l1); // capovolgi il resto
   l->tail->tail = l;
   l->tail = EMPTY_SEQ;
   l = l1;
   return OK;
}


/****************************************************************/
Seq seq::reverse2(Seq l)   // VERSIONE ASD, IL PARAMETRO NON CAMBIA MA VIENE RESTITUITO IL PUNTATORE AL "NUOVO PRIMO ELEMENTO"
{
   if (isEmpty(l) || isEmpty(l->tail)) return l;
   Seq l1 = l->tail;
   Seq start = seq::reverse2(l1); // capovolgi il resto
   l->tail->tail = l;
   l->tail = EMPTY_SEQ;
   return start;
}


/****************************************************************/
Seq seq::reverse3(Seq l)   // VERSIONE ASD 2 (CON UN'ISTRUZIONE IN MENO), IL PARAMETRO NON CAMBIA MA VIENE RESTITUITO IL PUNTATORE AL "NUOVO PRIMO ELEMENTO"
{
   if (isEmpty(l) || isEmpty(l->tail)) return l;
   Seq start = seq::reverse3(l->tail); // capovolgi il resto
   l->tail->tail = l;
   l->tail = EMPTY_SEQ;
   return start;
}



/****************************************************************/
int seq::sumRec(Seq l)
{
    if (isEmpty(l)) return 0; // va bene, approccio "safe" (non accedo a campi di una struct "vuota")
  // if isEmpty(l->tail) return l->head; // questo non andrebbe bene, rischio segmentation fault

    return l->head + sumRec(l->tail);
}



/****************************************************************/
int seq::multRec(Seq l)
{
    if (isEmpty(l)) return 1; // va bene, approccio "safe" (non accedo a campi di una struct "vuota")
  // if isEmpty(l->tail) return l->head; // questo non andrebbe bene, rischio segmentation fault

    return l->head * multRec(l->tail);
}


/****************************************************************/
// restituisce true se esiste nella lista un elemento < e; restituisce false altrimenti
bool seq::existsLesserThan(int e, Seq l) 
{
    if (isEmpty(l)) return false;
    if (l->head  < e) return true;
    
    return existsLesserThan(e, l->tail); 
}


/****************************************************************/
// restituisce true se tutti gli elementi della lista sono >= e; restituisce false altrimenti
bool seq::areAllGreaterEqualThan(int e, Seq l) 
{
   return (!existsLesserThan(e, l)); 
}

/****************************************************************/
Seq seqReadFromStream(istream& str)
{
    Seq s = EMPTY_SEQ;
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e!= seq::FINEINPUT)  // assumiamo che il segnale di fine input nel file sia il numero  FINEINPUT
       {
       insertElem(e, s);
       str>>e;
       if (!str) throw runtime_error("Errore inserimento dati\n");
       }
return s;
}

/****************************************************************/
Seq seqOrderedReadFromStream(istream& str)
{
    Seq s = EMPTY_SEQ;
    Elem e;
    str>>e;
    if (!str) throw runtime_error("Errore inserimento dati\n");
    while (e!= seq::FINEINPUT)  // assumiamo che il segnale di fine input nel file sia il numero  FINEINPUT
       {
       insertElemInOrder(e, s);
       str>>e;
       if (!str) throw runtime_error("Errore inserimento dati\n");
       }
return s;
}

/****************************************************************/
Seq seqReadFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return seqReadFromStream(ifs);
}

/****************************************************************/
Seq seqOrderedReadFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    return seqOrderedReadFromStream(ifs);
}



/****************************************************************/
Seq seqReadFromStdin()
{
    cout << "\nInserire una sequenza di numeri separati da spazi seguiti da " <<  seq::FINEINPUT << " per terminare\n";
    return seqReadFromStream((std::cin));
}


/****************************************************************/
void seqPrint(const Seq& s)
{
   if (!isEmpty(s))
      {
      cout << s->head << " "; 
      seqPrint(s->tail);            
      }
}