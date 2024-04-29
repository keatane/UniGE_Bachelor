#include "tree-chsib.h"

using namespace tree;

/* Nota: nei commenti usiamo "albero" e "puntatore a un nodo" come sinonimi, scegliendo di volta in volta
la formulazione più adatta a dare la specifica di una funzione. 
Dal punto di vista tecnico, usiamo sempre il tipo Tree sia quando operiamo su un albero, sia quando operiamo, 
a livello concettuale, su un puntatore a un nodo dell'albero. 
Questo approccio e' corretto in quanto un albero (o sottoalbero) è un puntatore a una struct di tipo treeNode:
un albero è identificato univocamente dal puntatore alla sua radice */ 

/*******************************************************************************************************/
// il nodo di un albero è caratterizzato dall'etichetta, il puntatore al primo figlio e il puntatore al prossimo fratello
// NON manteniamo il puntatore al padre, anche se sarebbe comodo per alcune funzioni (ma del tutto inutile per altre)
struct tree::treeNode {
    Label label;    
    treeNode *firstChild;
    treeNode *nextSibling;
};


//funzione ausiliaria getNode

/* restituisce il puntatore al nodo che si trova in t ed ha come etichetta l */
Tree getNode(const Label l, const Tree& t)
{
	/* se t è vuoto o l'etichetta è vuota restituisco emptyTree */
	if (isEmpty(t) || l==emptyLabel)
		return emptyTree;
	/* se l'etichetta di t è quella cercata, restituisco t */
	if (t->label == l)
		return t;
	/* ...chiamata ricorsiva di getNode su ciascuno dei figli di t,
	finché una delle chiamate non restituisce un valore diverso da
	emptyTree.... Rispetto alla visita esaustiva vista prima, la getNode non
	deve per forza esplorare tutto l'albero: quando una delle chiamate
	restituisce un albero != emptyTree, si deve fare return di tale albero
	non vuoto interrompendo la scansione dei fratelli */
	treeNode* auxT = t->firstChild;
	treeNode* a;
	while(!isEmpty(auxT))
	{
		if((a = getNode(l, auxT)) != emptyTree) return a;
		auxT = auxT->nextSibling;
	}
	return emptyTree;
}


/*******************************************************************************************************/
// isEmpty restituisce true se l'albero t e' vuoto, false altrimenti
bool tree::isEmpty(const Tree& t)
{ 
	return t==emptyTree;
}



/*******************************************************************************************************/
// addElem aggiunge il nodo etichettato con labelOfNodeToAdd come
// figlio del nodo etichettato con labelOfNodeInTree.
// Caso particolare: aggiunta della radice, che si ottiene
// con labelOfNodeInTree uguale a emptyLabel (= nessun padre), e ha successo
// solo se l'albero e' vuoto (in caso contrario restituisce FAIL 
// e non aggiunge nulla).
// Restituisce FAIL se non esiste un nodo nell'albero etichettato 
// con labelOfNodeInTree oppure se nell'albero esiste gia' un nodo 
// etichettato con labelOfNodeToAdd; aggiunge e restituisce OK altrimenti
Error tree::addElem(const Label labelOfNodeInTree, const Label labelOfNodeToAdd, Tree& t)
{
	/* ...controlli iniziali: L'albero t e' vuoto? L'etichetta labelOfNodeInTree
	e' emptyLabel? L'etichetta labelOfNodeToAdd è già presente nell'albero?.... */
	if(isEmpty(t) && labelOfNodeInTree==emptyLabel)
	{
		t = new treeNode;
		t->label = labelOfNodeToAdd;
		t->firstChild = emptyTree;
		t->nextSibling = emptyTree;
		return OK;
	}
	
	if(isEmpty(t) || labelOfNodeInTree==emptyLabel || member(labelOfNodeToAdd, t))
		return FAIL;
	
	Tree auxT = getNode(labelOfNodeInTree, t); //recupero il puntatore al nodo dell'albero che ha etichetta labelOfNodeInTree
	if (auxT == emptyTree)
		return FAIL; /* nell'albero non esiste un nodo con etichetta labelOfNodeInTree, restituisco FAIL */
	else /* ho trovato il nodo auxT a cui aggiungere il figlio */
	{
	/* creo il figlio con etichetta labelOfNodeToAdd e lo aggiungo a auxT. Può
	essere una buona idea implementare una funzione ausiliaria che crea il nodo e
	ne restituisce il puntatore */
		treeNode* auxN = new treeNode;
		auxN->label = labelOfNodeToAdd;
		auxN->firstChild = emptyTree;
		auxN->nextSibling = auxT->firstChild;
		auxT->firstChild = auxN;
	}
	return OK;
}     



/*******************************************************************************************************/
// deleteElem (versione iterativa) rimuove dall'albero il nodo etichettato con la Label l
// e collega al padre di tale nodo tutti i suoi figli
// Restituisce FAIL se si tenta di cancellare la radice e questa ha 
// dei figli (non si saprebbe a che padre attaccarli) oppure se non esiste 
// un nodo nell'albero etichettato con la Label; cancella e restituisce OK altrimenti
Error tree::deleteElemI(const Label l, Tree& t)
{
	/*
	Abbiamo scelto di utilizzare la stessa implementazione di deleteElemR perchè reimplementare le funzioni father e getNode in modo iterativo
	si è rivelato troppo complesso e controproducente e avrebbe richiesto un tempo maggiore di quello a nostra disposizione.
	Non ci è chiaro se è possibile utilizzare delle funzioni ausiliarie ricorsive in un'implementazione iterativa.
	
												  ⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
										⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
										⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
										⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
										⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
										⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
										⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
										⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
										⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
										⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
										⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
										⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
	*/
	bool radice = false;
	Tree nodo, padre, primoFiglioPadre = emptyTree, primoFiglioNodo, ultimoFiglioNodo, fratelloPrecedente = emptyTree, aux;
	Label labelPadre = father(l, t);
	nodo = getNode(l, t);
	padre = getNode(labelPadre, t);
	
	if(isEmpty(nodo)) return FAIL;
	if(isEmpty(padre)) radice = true;
	
	primoFiglioNodo = nodo->firstChild;
	
	aux = primoFiglioNodo;
	//cerco ultimo figlio nodo
	if(!isEmpty(primoFiglioNodo))
		while(!isEmpty(aux->nextSibling))
			aux = aux->nextSibling;
	ultimoFiglioNodo = aux;
	
	//cerco fratello precedente di nodo
	if(!radice)
	{
		primoFiglioPadre = padre->firstChild;
		aux = primoFiglioPadre;
		if(aux->label != l) //se il primo figlio del padre non è nodo
		{
			while(aux->nextSibling->label != l)
				aux = aux->nextSibling;
			//qui ho il fratello precedente di nodo oppure emptyTree se nodo è il primo figlio di padre
			fratelloPrecedente = aux;
		}
	}
	
	if(radice) //se nodo radice
	{
		if(!isEmpty(primoFiglioNodo)) return FAIL;
		t = emptyTree;
	}
	else //nodo non radice
	{
		if(isEmpty(fratelloPrecedente)) // se nodo è il primo figlio di padre
		{
			if(isEmpty(primoFiglioNodo)) // se nodo non ha figli
				padre->firstChild = nodo->nextSibling;
			else // nodo ha almeno un figlio
			{
				padre->firstChild = primoFiglioNodo;
				ultimoFiglioNodo->nextSibling = nodo->nextSibling;
			}
		}
		else // nodo non è il primo figlio di padre, quindi ha un fratelloPrecedente
		{
			if(isEmpty(primoFiglioNodo)) // se nodo non ha figli
				fratelloPrecedente->nextSibling = nodo->nextSibling;
			else // nodo ha almeno un figlio
			{
				fratelloPrecedente->nextSibling = primoFiglioNodo;
				ultimoFiglioNodo->nextSibling = nodo->nextSibling;
			}
		}
	}
	
	delete nodo;
	return OK;
}



/*******************************************************************************************************/
// deleteElem (versione ricorsiva): stesso comportamento della versione iterativa, ma implementata ricorsivamente
// (può anche non essere ricorsiva la deleteElemR, ma deve fare uso di funzioni ausiliarie ricorsive)
Error tree::deleteElemR(const Label l, Tree& t)
{
	bool radice = false;
	Tree nodo, padre, primoFiglioPadre = emptyTree, primoFiglioNodo, ultimoFiglioNodo, fratelloPrecedente = emptyTree, aux;
	Label labelPadre = father(l, t);
	nodo = getNode(l, t);
	padre = getNode(labelPadre, t);
	
	if(isEmpty(nodo)) return FAIL;
	if(isEmpty(padre)) radice = true;
	
	primoFiglioNodo = nodo->firstChild;
	
	aux = primoFiglioNodo;
	//cerco ultimo figlio nodo
	if(!isEmpty(primoFiglioNodo))
		while(!isEmpty(aux->nextSibling))
			aux = aux->nextSibling;
	ultimoFiglioNodo = aux;
	
	//cerco fratello precedente di nodo
	if(!radice)
	{
		primoFiglioPadre = padre->firstChild;
		aux = primoFiglioPadre;
		if(aux->label != l) //se il primo figlio del padre non è nodo
		{
			while(aux->nextSibling->label != l)
				aux = aux->nextSibling;
			//qui ho il fratello precedente di nodo oppure emptyTree se nodo è il primo figlio di padre
			fratelloPrecedente = aux;
		}
	}
	
	if(radice) //se nodo radice
	{
		if(!isEmpty(primoFiglioNodo)) return FAIL;
		t = emptyTree;
	}
	else //nodo non radice
	{
		if(isEmpty(fratelloPrecedente)) // se nodo è il primo figlio di padre
		{
			if(isEmpty(primoFiglioNodo)) // se nodo non ha figli
				padre->firstChild = nodo->nextSibling;
			else // nodo ha almeno un figlio
			{
				padre->firstChild = primoFiglioNodo;
				ultimoFiglioNodo->nextSibling = nodo->nextSibling;
			}
		}
		else // nodo non è il primo figlio di padre, quindi ha un fratelloPrecedente
		{
			if(isEmpty(primoFiglioNodo)) // se nodo non ha figli
				fratelloPrecedente->nextSibling = nodo->nextSibling;
			else // nodo ha almeno un figlio
			{
				fratelloPrecedente->nextSibling = primoFiglioNodo;
				ultimoFiglioNodo->nextSibling = nodo->nextSibling;
			}
		}
	}
	
	delete nodo;
	return OK;
}



/*******************************************************************************************************/
// father restituisce l'etichetta del padre del nodo con etichetta l se il nodo esiste nell'albero 
// (o sottoalbero) t e se il padre esiste. 
// Restituisce la costante emptyLabel altrimenti
Label tree::father(const Label l, const Tree& t)
{ 
	if(isEmpty(t) || l == emptyLabel || l == t->label) return emptyLabel;
	Tree aux = t->firstChild;
	Tree prev = t;
	Label lAux;
	while(!isEmpty(aux))
	{
		if(l == aux->label) return prev->label;
		if((lAux = father(l, aux)) != emptyLabel) return lAux;
		aux = aux->nextSibling;
	}
	return emptyLabel;
}



/*******************************************************************************************************/
// children restituisce una lista di Label, contenente le etichette 
// di tutti i figli nell'albero t del nodo etichettato con l
// La lista può essere implementata usando una qualunque delle strutture dati viste a lezione
// (non un Vector!!!): si riusi una implementazione del TDD list, adattandola 
// a elementi di tipo string (nelle precedenti esercitazioni gli elementi erano int)
list::List tree::children(const Label l, const Tree& t)
{
	list::List lst = list::createEmpty();
	Tree n = getNode(l, t);
	if(isEmpty(n)) return lst;
	n = n->firstChild;
	while(!isEmpty(n))
	{
		list::addFront(n->label, lst);
		n = n->nextSibling;
	}
	return lst;
}



/*******************************************************************************************************/
// degree restituisce il numero di archi uscenti dal nodo etichettato con l; restituisce -1 se non esiste 
// nessuna etichetta l nell'albero
int tree::degree(const Label l, const Tree& t)
{
	unsigned int counter = 0;
	Tree n = getNode(l, t);
	if(isEmpty(n)) return counter;
	n = n->firstChild;
	while(!isEmpty(n))
	{
		counter++;
		n = n->nextSibling;
	}
	return counter;
}



/*******************************************************************************************************/

void ancestorsRaux(const Label l, const Tree& t, list::List& lst)
{
	Label aux = father(l, t);
	if(aux != emptyLabel)
	{
		list::addFront(aux, lst);
		ancestorsRaux(aux, t, lst);
	}
}

// ancestors (versione ricorsiva) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
// (può anche non essere ricorsiva la ancestorsR, ma deve fare uso di funzioni ausiliarie ricorsive)
list::List tree::ancestorsR(const Label l, const Tree& t)
{
	list::List lst = list::createEmpty();
	if(!isEmpty(t) && t->label != l && l != emptyLabel) ancestorsRaux(l, t, lst);
	return lst;
}



/*******************************************************************************************************/
// ancestors (versione iterativa) restituisce una lista di Label, contenente le etichette 
// di tutti gli antenati del nodo l ESCLUSA l'etichetta del nodo stesso
// La lista può essere implementata usando una delle strutture dati viste a lezione
// (non un Vector)
list::List tree::ancestorsI(const Label l, const Tree& t)
{
	list::List lst = list::createEmpty();
	if(isEmpty(t) || t->label == l || l == emptyLabel) return lst;
	Label aux = l;
	while((aux = father(aux, t)) != emptyLabel)
		list::addFront(aux, lst);
	return lst;
}



/*******************************************************************************************************/
// leastCommonAncestor restituisce l'etichetta del minimo antenato comune 
// ai nodi etichettati con label1 e label2
Label tree::leastCommonAncestor(const Label label1, const Label label2, const Tree& t)
{
	list::List l1 = ancestorsR(label1, t);
	list::List l2 = ancestorsR(label2, t);
	Label curr = emptyLabel;
	for(unsigned i=0; i<l1.size; i++)
		for(unsigned j=0; j<l1.size; j++)
			if(l2.list[j] == l1.list[i])
				curr = l1.list[i];
	return curr;
}



/*******************************************************************************************************/
// member restituisce true se il nodo etichettato con la label l appartiene all'albero t e false altrimenti
bool tree::member(const Label l, const Tree& t)
{ 
	return !isEmpty(getNode(l, t));
}



/*******************************************************************************************************/
// numNodes restituisce il numero di nodi nell'albero t mediante una visita ricorsiva in depthfirst
int tree::numNodes(const Tree& t)
{
	if(isEmpty(t)) return 0;
	Tree aux = t->firstChild;
	int c = 1;
	while(!isEmpty(aux))
	{
		c += numNodes(aux);
		aux = aux->nextSibling;
	}
	return c;
}



/*******************************************************************************************************/
// createEmptyTree restituisce l'albero vuoto
Tree tree::createEmpty()
{
	return emptyTree;
}



/*******************************************************************************************************/

void printAux(const Tree& t, unsigned int level=0)
{
	//se l'albero e' vuoto non c'é niente da visitare
	if (isEmpty(t))
		return;
	for(unsigned int i=0; i<level; i++)
		cout << "--";
	cout << t->label << endl;
	Tree auxT = t->firstChild;
	while (!isEmpty(auxT))
	{
		printAux(auxT, level+1);
		auxT=auxT->nextSibling;
	}
}

// Visualizzazione possibilmente strutturata come visto a lezione
void printTree(const Tree& t)
{
	printAux(t);
}



/****************************************************************/
// Questa funzione NON richiede di conoscere come e' fatta la struttura dati che implementa l'albero: usa solo addElem e quindi e' ad 
// un alto livello di astrazione
// Vantaggi: codice compatto, leggibile, riutilizzabile per qualunque implementazione del TDD Tree
// Svantaggi: inefficiente: la addElem cerca ogni volta il nodo con etichetta fatherLabel, mentre basterebbe una chiamata sola per 
// trovarlo e poi si potrebbero attaccare tutti i figli a esso, senza ripetere la dispendiosa ricerca nell'albero; per renderla 
// efficiente dovrei pero' accedere direttamente alla struttura dati chiamando qualche funzione ausiliaria che operi 
// sui nodi dell'albero, rinunciando a scrivere codice modulare, chiaro e ad un ragionevole livello di astrazione... 
// Non esiste un'opzione migliore tra le due: se il codice deve essere efficiente, è opportuno scrivere una funzione ad hoc per 
// una determinata implementazione; se il codice deve essere riutilizzabile, bisogna limitarsi a usare le funzioni offerte dall'
// interfaccia del TDD in modo che la funzione continui ad andare bene anche se cambia l'implementazione
Tree readFromStream(istream& str)
{
    Tree t = createEmpty(); 
    string line;
    Label rootLabel, fatherLabel, childLabel;
    getline(str, line);  
    istringstream instream;            // uso una variabile di tipo istringstream per poter scandire i pezzi di ogni riga usando >>
    instream.clear();
    instream.str(line);
    instream >> rootLabel;             // il primo elemento che si incontra nel file e' l'etichetta della radice, per convenzione su come deve essere fatto il file
    addElem(emptyLabel, rootLabel, t); // la si inserisce nell'albero vuoto, indicando che il padre non c'e' (primo argomento emptyLabel)
    getline(str, line);                // poi si iniziano a scansionare le righe seguenti
    instream.clear();
    instream.str(line);
    while (!str.eof())  
        {        
	instream >> fatherLabel; // in ogni riga del file, il primo elemento e' l'etichetta del nodo padre e gli altri sono le etichette dei figli
        removeBlanksAndLower(fatherLabel); // normalizzo l'etichetta del padre
        while (!instream.eof())            // finche' la riga corrente non e' terminata
            { 
            instream >> childLabel;              // leggo la prossima etichetta
            removeBlanksAndLower(childLabel);    // la normalizzo
            addElem(fatherLabel, childLabel, t); // e la attacco al padre
            }
        getline(str, line);  
        instream.clear();
        instream.str(line);
        }
    str.clear();
    return t;
}



/****************************************************************/
Tree readFromFile(string nome_file)
{
    ifstream ifs(nome_file.c_str()); // apertura di uno stream associato ad un file, in lettura
    if (!ifs) {cout << "\nErrore apertura file, verificare di avere inserito un nome corretto\n"; return createEmpty();}  
    return readFromStream(ifs);
}

