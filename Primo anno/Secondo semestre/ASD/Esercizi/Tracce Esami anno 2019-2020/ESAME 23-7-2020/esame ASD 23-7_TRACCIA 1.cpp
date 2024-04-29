/****************************************************/
/* PROVA DI ESAME DI LABORATORIO DI ASD (traccia 1) */
/****************************************************/

// Descrizione:
// In questa prova di esame di laboratorio consideriamo i grafi orientati pesati implementati con le matrici di adiacenza.
// Il peso di un arco e' sempre un numero intero maggiore di zero. Il valore zero e' invece usato per rappresentare l'assenza di un arco.
//
// Ad esempio la seguente matrice di adiacenza:
// 0 2 0
// 0 0 3
// 0 0 0
//
// rappresenta il seguente grafo con tre vertici: 0 -> 1 -> 2
//
// dove l'arco tra i vertici 0 e 1 ha peso 2 e l'arco tra i vertici 1 e 2 ha peso 3

// scrivere sotto Nome, Cognome e Matricola:
// NOME:
// COGNOME:
// MATRICOLA:

#include <iostream>
using namespace std;

/************************************************************************************/
/*      Grafo pesato orientato implementato con una matrice di adiacenza            */
/************************************************************************************/

typedef int VerticeID;
const int maxNumVertici = 50; // al massimo e' possibile creare Grafi con numero di vertici uguale a maxNumVertici
const int elementoInesistente = -1;
const int arcoNonPresente = 0; // lo zero e' usato per rappresentare l'assenza di un arco
typedef int Peso;
/* Un grafo pesato e' implementato con una struct che contiene il numero di vertici del grafo (numVertici) e una matrice di adiacenza (matrice). 
 Nella matrice un valore p (> 0) in posizione 'i' e 'j' indica che il grafo ha un arco da 'i' a 'j' con peso p 
*/
typedef struct { 
  int numVertici;
  Peso matrice[maxNumVertici][maxNumVertici];
} Grafo;

/* Operazioni sui Grafi */
Grafo creaGrafo(const int n); 
bool aggiungiArco(Grafo&, VerticeID, VerticeID, Peso); 
int pesoTotaleArchi(const Grafo&); 
bool sonoCollegatiDaUnVertice(const Grafo&, VerticeID, VerticeID, VerticeID&);  
void stampaGrafo(Grafo);  

/* Inizializza la matrice maxNumVertici x maxNumVertici associata al grafo con tutti valori uguali alla costante elementoInesistente
e crea un grafo di dimensione n */
Grafo creaGrafo(const int n) {
   Grafo g;
   for(int i=0; i<maxNumVertici; ++i)     // inizializzo tutta la matrice a elementoInesistente
         for(int j=0; j<maxNumVertici; ++j)
            g.matrice[i][j] = elementoInesistente;
   g.numVertici = n;
   for(int i=0; i<g.numVertici; ++i)     // inizializzo la parte di matrice che corrisponde al grafo di dimensione n
         for(int j=0; j<g.numVertici; ++j)
            g.matrice[i][j] = arcoNonPresente;
   return g;
}

/* Aggiunge un arco tra i due vertici passati come argomento, con peso passato come quarto parametro; restituisce false nei seguenti casi: 
 1) se uno dei due vertici non ha un indice ammissibile (l'indice deve essere compreso tra 0 e il numero di vertici del grafo-1)
 2) se il peso e' negativo
 3) se i due vertici sono identici (sulla diagonale devono esserci tutti zeri) */
bool aggiungiArco(Grafo& g, VerticeID v1, VerticeID v2, Peso p) {  
  if (0<=v1 && v1<g.numVertici && 0<=v2 && v2<g.numVertici && p>=0 && v1 != v2) {
    g.matrice[v1][v2] = p; 
    return true;
  }
  else
   return false;
} 

/****************************************************************/
/* DESCRIZIONE FUNZIONI DA IMPLEMENTARE

/* Sviluppare le due seguenti funzioni C/C++:

   1) pesoTotaleArchi() 
      
   2) sonoCollegatiDaUnVertice() 
   
la cui specifica testuale e' data sotto forma di commento direttamente sopra alla loro definizione
*/

/* Calcola e restituisce la somma del peso di tutti gli archi nel grafo */
int pesoTotaleArchi(const Grafo& g) {
   return 0; // istruzione inserita solo per non avere problemi di compilazione
}

/* Verifica se esiste il modo di raggiungere il secondo vertice (v2) a partire dal primo (v1) attraversando un altro vertice (vlink); 
nel caso siano collegati da un vertice, la funzione restituisce true e aggiorna l'ultimo parametro (vlink) per contenere il vertice che 
collega il primo vertice (v1) al secondo (v2); nel caso non esista un vertice che li collega, la funzione restituisce false e assegna 
al quarto parametro (vlink) il valore costante elementoInesistente */
bool sonoCollegatiDaUnVertice(const Grafo& g, VerticeID v1, VerticeID v2, VerticeID& vlink) {
    vlink=0;       // istruzione inserita solo per non avere problemi di compilazione
    return false; // istruzione inserita solo per non avere problemi di compilazione
}

/* stampa il grafo */
void stampaGrafo(Grafo g) {
  for(int i=0; i<g.numVertici; ++i) {
      for(int j=0; j<g.numVertici; ++j)
         cout << g.matrice[i][j] << "\t";
      cout << endl;
  }
} 

int main() {   
  Grafo g;
  // creo un grafo di dimensione 4
  g = creaGrafo(4);
  aggiungiArco(g, 0, 1, 2);
  aggiungiArco(g, 1, 2, 4);
  aggiungiArco(g, 1, 3, 6);
  aggiungiArco(g, 2, 1, 8);
  aggiungiArco(g, 3, 0, 2);
  cout << "E' stato inserito il seguente grafo:" << endl;
  stampaGrafo(g);
  cout << endl;
  
  cout << "*** PRIMA FUNZIONE *** " << endl;
  if (pesoTotaleArchi(g)==22) cout << "TEST pesoTotaleArchi PASSATO" << endl;
  else cout << "TEST pesoTotaleArchi FALLITO" << endl;
  cout << endl;
   
  cout << "*** SECONDA FUNZIONE *** " << endl;
  VerticeID vlink = -1;
  if (sonoCollegatiDaUnVertice(g, 1, 0, vlink) && vlink == 3) cout << "TEST 1 sonoCollegatiDaUnVertice PASSATO" << endl;
  else cout << "TEST 1 sonoCollegatiDaUnVertice FALLITO" << endl;
  vlink = -1;
  if (!sonoCollegatiDaUnVertice(g, 2, 0, vlink) && vlink == -1) cout << "TEST 2 sonoCollegatiDaUnVertice PASSATO" << endl;
  else cout << "TEST 2 sonoCollegatiDaUnVertice FALLITO" << endl;
   
  return 0;
}
