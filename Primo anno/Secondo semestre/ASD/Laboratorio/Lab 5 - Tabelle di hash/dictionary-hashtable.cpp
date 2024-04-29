#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::cell {
    Elem	elem;
	cell	*next;
};

/*
g++ -std=c++11 -Wall -D USE_HASH_TABLE dictionary-hashtable.cpp string-utility.cpp dictionary-main.cpp
*/


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h1(Key s) // funzione di hash che considera unicamente il valore ascii del primo carattere della chiave (se esiste) e restituisce il resto della divisione di tale valore per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
 return (!s.empty() ? (int(s[0]) % tableDim) : -1); // se stringa (chiave-parola) vuota, segnaliamo l'errore
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h2(Key s) // funzione di hash che somma il codice ascii di ogni carattere nella chiave e restituisce il resto della divisione di tale somma per tableDim 
{
 // implementare la funzione richiesta e modificare il return 
 if(s.empty()) return -1;
 
 int somma = 0;
 for(unsigned int i=0; i<s.size(); ++i)
 	somma += int(s[i]);
 return (somma % tableDim);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
int h3(Key s) // funzione di hash diversa da h1 ed h2, che progettate e implementate voi seguendo qualche criterio che vi sembra ragionevole
{
	// implementare la funzione richiesta e modificare il return
	int somma = 0;
	for(unsigned int i=0; i<s.size(); ++i)
	somma += int(s[i]);
	return abs(int(pow(tableDim,3)*cos(somma % tableDim))%tableDim);
}

/****************************************************************/
/*    FUNZIONE DA MODIFICARE PER FARE ESPERIMENTI DIVERSI       */
/****************************************************************/
int h(Key s)
{
   return h3(s); // modificare questa chiamata per sperimentare l'utilizzo delle funzioni di hash h1, h2, h3, definite prima
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::deleteElem(const Key k, Dictionary& s)
{
	// Controllo se h(k) ritorna un valore di indice lecito
	if(h(k) < 0)
		return FAIL;	

	if(s[h(k)] == emptyBucket)
		return FAIL; // non vi è l'elemento da cancellare in una lista vuota
	else{
		Bucket temp = s[h(k)]; // punta alla testa
		
		if(s[h(k)]->elem.key == k){	// In caso di eliminazione in testa (l'elemento da togliere è il primo)
			s[h(k)] = temp->next; // punta alla cella successiva
			delete temp;
			return OK;
		}
		
		// Giunti qui ho già effettuato il controllo se l'elemento da togliere è il primo
		Bucket prev = temp;
		temp = temp->next; // parto dal secondo
		while(temp != emptyBucket){
			if(temp->elem.key == k){
				// Inizio rimozione cella puntata da temp
				prev->next = temp->next; // salto la cella corrente
				delete temp;
				return OK;
			}
			prev = temp;
			temp = temp->next;
		}
	}
 	return FAIL; // se giungo in fondo significa che non è stato trovato l'elemento  	
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary& s)
{	
	// Controllo se h(k) ritorna un valore di indice lecito
	if(h(k) < 0)
		return emptyValue;	
		
	for(Bucket temp = s[h(k)]; temp != emptyBucket; temp = temp->next) // incapsula il controllo di lista vuota	
		if(temp->elem.key == k)
			return temp->elem.value; // elemento trovato
 	return emptyValue; // se giungo in fondo significa che il for non ha trovato l'elemento oppure non vi è l'elemento in una lista vuota
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::insertElem(const Key k, const Value v,  Dictionary& s)
{	
	// Controllo se h(k) ritorna un valore di indice lecito
	if(h(k) < 0)
		return FAIL;	
	
	// Creo la cella ausiliaria
	cell* aux = new cell;
	aux->elem.key = k;
	aux->elem.value = v;

	if(s[h(k)] != emptyBucket) // se non è vuota controllo eventuali duplicati di coppie
		for(Bucket temp = s[h(k)]; temp != emptyBucket; temp = temp->next)
			if(temp->elem.key == k) // se ho già una coppia (k,v) ho una collisione
				return OK; // elemento già presente
				
	/* Alternativa - non implementata - valutabile in caso di elemento duplicato:
	// sovrascrivo value vecchio con quello nuovo
	*/
		
		
	// Se la coppia non è già presente (o lista vuota) la inserisco in testa
	aux->next = s[h(k)]; // o punta alla vecchia coppia-testa o punta a emptyBucket (s[h(k)] è ancora emptyBucket se lista vuota)
	s[h(k)] = aux;
	return OK;
}


/****************************************************************/
Dictionary dict::createEmptyDict()
{
   Bucket* d = new Bucket[tableDim];
   for (int i=0; i < tableDim; ++i)
      d[i]=emptyBucket;
   return d;
}


/****************************************************************/
Dictionary readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmptyDict();}  
    return readFromStream(ifs);
}


/****************************************************************/
Dictionary readFromStdin()
{
    cout << "\nInserire una sequenza di linee che rispettano la sintassi key: value.<enter>\nDigitare CTRL^ D per terminare l'inserimento\n";
    Dictionary d = readFromStream((std::cin));
// Questa serve per aggirare un bug di alcune versioni attuali di glibc.
    clearerr(stdin);
    return d;
}


/****************************************************************/
Dictionary readFromStream(istream& str)
{
    Dictionary d = createEmptyDict();     
    string key, kcopy;
    string value;
    getline (str, key, ':'); 
    getline (str, value); 
    while (!str.eof())  
        {     
        kcopy = key;
        removeBlanksAndLower(kcopy);   
        insertElem(kcopy, value, d); // FINCHE' NON IMPLEMENTATE LA INSERTELEM, NON PUO' FUNZIONARE CORRETTAMENTE: la insertElem e' la prima funzione che dovete implementare
        getline (str, key, ':'); 
        getline (str, value); 
        }
    str.clear();
    return d;
}


/****************************************************************/
int printBucket(Bucket b) // stampa il contenuto di un bucket e restituisce il numero di elementi contenuti nel bucket stesso
{  
   int counter = 0;
   while(b!=emptyBucket) {
        counter++;
        cout << (b->elem).key << ": " << (b->elem).value << "\n"; 
	b=b->next;
	}
   return counter;	
}


/****************************************************************/
void print(const Dictionary& s)
// stampa il contenuto del dizionario ed anche informazioni su come sono stati organizzati gli elementi
{
int bucketDim[tableDim];
int totalElem = 0;
for (unsigned int i=0; i<tableDim; ++i)
   {
    cout << "\nBucket " << i << "\n\n";
    bucketDim[i] = printBucket(s[i]);
    totalElem += bucketDim[i]; 
   }
float means = totalElem/(float)tableDim;
float standardDevSum = 0;
for (unsigned int i=0; i<tableDim; ++i)
     standardDevSum += (bucketDim[i]-means)*(bucketDim[i]-means);
   
/* Lo scarto tipo, deviazione standard, o scarto quadratico medio e' un indice di dispersione statistico, vale a dire una stima della variabilita' di una popolazione di dati o di una variabile casuale.
Lo scarto tipo e' uno dei modi per esprimere la dispersione dei dati intorno ad un indice di posizione, quale puo' essere, ad esempio, la media aritmetica. */

cout << "\n===STATISTICHE SULL'ORGANIZZAZIONE DEL DIZIONARIO===\n";

for (unsigned int i=0; i<tableDim; ++i)
   cout << "\nBucket " << i << ": " << bucketDim[i] << " elementi";

cout << "\nIl numero totale di elementi memorizzati e' " << totalElem;
cout << "\nIl numero di bucket nel dizionario e' " << tableDim;
if (tableDim != 0) cout << "\nIl numero atteso di elementi per bucket e' " << means << "\nLa deviazione standard e' " << sqrt(standardDevSum/tableDim);
}



