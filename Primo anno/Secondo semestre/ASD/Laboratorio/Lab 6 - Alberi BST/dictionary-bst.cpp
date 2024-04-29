#include "dictionary.h"

#include <math.h> // sqrt()

using namespace dict;

struct dict::bstNode {
    Elem	 elem;
	bstNode* leftChild;
	bstNode* rightChild;
};

/*
g++ -std=c++11 -Wall -D USE_BST dictionary-bst.cpp string-utility.cpp dictionary-main.cpp
*/


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/

/************** Funzione ausiliaria #2 **********************************/
Elem deleteMin (Dictionary& d)
{
	if (d->leftChild == emptyNode) 
	{	
		Elem aux = d->elem;
		bstNode* temp = d;
		d = d->rightChild;
		delete temp;
		return aux;	
		
	}
	return deleteMin (d->leftChild);
}

/************** Funzione ausiliaria #1 **********************************/
Error deleteAux (const Key k, Dictionary& d,  Dictionary& father)
{
	if (d==emptyNode){
		//cout << "Failing" << endl; // ---- DEBUG ----
		return FAIL; // bst vuoto o elemento non trovato
	}
	
	if (k < d->elem.key){
		//cout << "Lefting" << endl; // ---- DEBUG ----
		return deleteAux (k, d->leftChild, d);
	}
	
	else if (k > d->elem.key)
	{
		//cout << "Righting" << endl; // ---- DEBUG ---- 
		return deleteAux (k, d->rightChild, d);
	}
	// Giunto qui il nodo bersaglio è stato trovato (k==d->elem.key)
	
	/* 
		CASO 1: il nodo con chiave k non ha figli -> 
		cancellazione del nodo con chiave k;
		il padre del nodo con chiave k viene fatto puntare al vuoto 
	*/
	if ((d->leftChild == emptyNode) && (d->rightChild == emptyNode))
	{
		//eliminare la radice -> ti rimane un albero vuoto 
		
		delete d;
		if (father == emptyNode) //caso particolare: d è la radice
			d = emptyNode;
		
		//controllo: d è rightChild o leftChild di suo padre (k == d->elem.key)
		else if (k < father->elem.key)
			father->leftChild = emptyNode;
		else if (k > father->elem.key)
			father->rightChild = emptyNode;
	}
	
	/*
		CASO 2: il nodo con chiave k ha un figlio -> aggiusto la catena dei puntatori
	*/
	else if (d->leftChild == emptyNode)
	{
		//non ha il leftchild->lavoro con il rightchild
	
		if (father == emptyNode) //caso particolare: d è la radice
		{
			bstNode* temp = d; // tengo traccia della radice
			d = d->rightChild; // sovrascrivo col ramo rimanente
			delete temp;
			return OK;
		}
		
		else if (k < father->elem.key)
			father->leftChild = d->rightChild; 
		else if (k > father->elem.key)
			father->rightChild = d->rightChild;
	}
	
	else if (d->rightChild == emptyNode)
	{
		//non ha il rightChild->lavoro con il leftchild
		cout << "Caso 3: il nodo ha SOLO un figlio sinistro " << endl;
		
		if (father == emptyNode) //caso particolare: d è la radice
		{
			cout << "--Sto lavorando con una radice" << endl;
			bstNode* temp = d; // tengo traccia della radice
			d = d->leftChild; // sovrascrivo col ramo rimanente
			delete temp;
			return OK;
		}
		
		else if (k < father->elem.key)
			father->leftChild = d->leftChild; 
		else if (k > father->elem.key)
			father->rightChild = d->leftChild;
	}
	
	/* 
		Caso 3: il nodo con chiave k ha entrambi i figli -> chiamo deleteMin
	*/ 
	else
		d->elem = deleteMin(d->rightChild);
		
	return OK;
}

Error dict::deleteElem(const Key k, Dictionary& d)
{
	bstNode* aux = emptyNode;
	return deleteAux (k, d, aux);
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Value dict::search(const Key k, const Dictionary& d)
{	
	if (d==emptyNode) return emptyValue; 			//caso base 1: elemento non trovato
	else if (k==d->elem.key) return d->elem.value;	//caso base 2: elemento trovato 
	
	else if (k<d->elem.key) return (search(k, d->leftChild)); // chiave presente nel ramo sinistro
	else if (k>d->elem.key) return (search(k, d->rightChild)); // chiave presente nel ramo destro
	
	return emptyValue;	// Necessario per evitare un warning del compilatore (perchè return condizionati)
}


/****************************************************************/
/*              FUNZIONE NON IMPLEMENTATA                       */
/****************************************************************/
Error dict::insertElem(const Key k, const Value v,  Dictionary& d)
{
	if(d==emptyNode) // inserimento della radice o del nuovo nodo figlio
	{
		bstNode* aux = new bstNode;
		aux->elem.key = k;
		aux->elem.value = v;
		aux->leftChild = emptyNode;
		aux->rightChild = emptyNode;
		d = aux;
		return OK;
	}
	
	// Radice già presente 
	else if(k < d->elem.key)
		return insertElem(k, v, d->leftChild);
	else if(k > d->elem.key)
		return insertElem(k, v, d->rightChild);
		
	// L'elemento è già nel set (chiavi uguali)
	return FAIL; 
}


/****************************************************************/
Dictionary dict::createEmptyDict()
{
   return emptyNode;
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
    cin.ignore(); // Per togliere il newline character lasciato da cin
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



/******** Stampa il contenuto del dizionario DFS simmetrica**************************/
void print(const Dictionary& d)
{
	/* 
		Stampa per visionare la struttura dell'albero
	*/
	/*
	if(d==emptyNode) return;
	cout << d->elem.key << "(";
	print(d->leftChild);
	cout << ",";
	print(d->rightChild);
	cout << ")";
	*/

	/* 
		Stampa in maniera crescente 
	*/
	if(d==emptyNode)
		return;
	print(d->leftChild);
	cout << d->elem.key << ":" << d->elem.value << endl;
	print(d->rightChild);
	// Risultato atteso: stampa in ordine crescente/alfabetico
}



