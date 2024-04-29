#include "graph.h"

using namespace graph;

const int MAX_INT = 1000000;

/*******************************************************************************************************/
// Grafo

struct halfEdgeVertex{
	vertexNode* vertPtr;
	Weight weight;
	halfEdgeVertex* nextEdge;
};

halfEdgeVertex* const emptyEdge = NULL; // non presente nel namespace

struct graph::vertexNode{
	Label label;
	halfEdgeVertex *adjList;
	vertexNode* nextNode;
	bool visited;
};

/*******************************************************************************************************/

// Restituisce il grafo vuoto
Graph graph::createEmptyGraph()
{
  	return emptyGraph;
}

//*************************
// Funzione ausiliaria getNode da label
vertexNode* getVertex(Label l, const Graph& g){
	vertexNode* aux = g;
	while(!isEmpty(aux)){
		if(aux->label == l)
			return aux;
		aux = aux->nextNode;
	}
	return emptyGraph; // se giunto qui, non ho trovato la label
}

//*************************

// Aggiunge nuovo vertice con etichetta la stringa. Fallisce se gia' presente
bool graph::addVertex(Label l, Graph& g) {
  	
  	if(!isEmpty(getVertex(l,g))) return false;
  	
  	// Creazione nuovo vertex
  	vertexNode* aux = new vertexNode;
  	aux->label = l;
  	aux->adjList = emptyEdge; // grafo vuoto = punta a NULL (no liste di adiacenza)
  	aux->nextNode = emptyGraph; // vertice inserito in fondo
  	aux->visited = false;
  	
  	if (isEmpty(g)){
  		g = aux;
  		return true;
  	}	
  	
  	Graph tail = g;
  	while(!isEmpty(tail->nextNode))
  	{
  		//if(tail->label == l) return false; // fallito, vertex già presente
  		tail = tail->nextNode;
  	}
  	tail->nextNode = aux;
  	return true;
}



//*************************

// Aggiunge un arco di peso "w" tra i nodi con etichetta "f" e "t". Fallisce se esiste gia' l'arco
// se i nodi non esistono nel grafo e se si tenta di inserire un arco tra un nodo ed esso stesso
bool graph::addEdge(Label from, Label to, Weight w, Graph& g) {
  	// Controllo cappi (label)
  	if(from == to) // escludiamo cappi (arco a se stesso)
  		return false;
  		
  	// Controllo se esiste già un arco tra i due vertici (label)
  	if(areAdjacent(from, to, g))
  		return false;
	
	// Controllo sui nodi (vertex)
  	vertexNode* fromNode = getVertex(from, g);
  	vertexNode* toNode = getVertex(to, g);
  	if(isEmpty(fromNode) || isEmpty(toNode))
  		return false;
  	
  	// Creazione arco from->to
  	halfEdgeVertex* aux = new halfEdgeVertex;
  	aux->vertPtr = toNode;
  	aux->weight = w;
  	aux->nextEdge = fromNode->adjList;
  	fromNode->adjList = aux;
  	
  	// Creazione arco to->from
  	halfEdgeVertex* aux2 = new halfEdgeVertex;
  	aux2->vertPtr = fromNode;
  	aux2->weight = w;
  	aux2->nextEdge = toNode->adjList;
	toNode->adjList = aux2;

  	return true;
}

// Restituisce true se il grafo e' vuoto, false altrimenti
bool graph::isEmpty(const Graph& g)
{ 
 	return (g == emptyGraph);
}

// Ritorna il numero di vertici del grafo
int graph::numVertices(const Graph& g){
 
 	int counter = 0;
 	Graph aux = g;
  	while(!isEmpty(aux))
  	{
  		//DEBUG: cout << "\n" << aux->label;
		aux = aux->nextNode;
		counter++;
  	}
  	//cout << "\n";
  	return counter;
}

// Ritorna il numero di archi del grafo
int graph::numEdges(const Graph& g){
	int counter = 0;
 	Graph aux = g;
  	while(!isEmpty(aux)){
  		while(aux->adjList != emptyEdge)
	  	{
	  		counter++;
			aux->adjList = aux->adjList->nextEdge;
	  	}
	  	aux = aux->nextNode;
	}
  	return counter/2; // poichè facciamo riferimento a grafi orientati il nosto numero di strade sarà dimezzato
}

// Calcola e ritorna (nel secondo parametro) il grado del nodo. Fallisce
// se il nodo non esiste
bool graph::nodeDegree(Label l, int& degree, const Graph& g) {
	if(isEmpty(getVertex(l,g))) return false;
	
	list::List lst = adjacentList(l,g);
	degree = size(lst); // funzione di libreria (implementata)
 	return true;
}

// Verifica se i due vertici v1 e v2 sono adiacenti (ovvero se esiste un arco)
bool graph::areAdjacent(Label v1, Label v2, const Graph& g) {
	halfEdgeVertex* v1Vertex = getVertex(v1, g)->adjList;
	while(v1Vertex != emptyEdge){
		if(v1Vertex->vertPtr->label == v2) // esiste l'arco v1->v2
			return true;
		v1Vertex = v1Vertex->nextEdge;
	}
	return false;
	
	// Essendo arco non orientato, se l'arco non è presente nella lista di adiacenza di v1, non lo
	// è neanche in quella di v2
}

// Restituisce la lista di adiacenza di un vertice
list::List graph::adjacentList(Label v1, const Graph& g) {
  list::List lst = list::createEmpty();
  
  vertexNode* v1Vertex = getVertex(v1,g);
  if(v1Vertex == emptyGraph)
  	return lst; // vertice non esistente, return lista vuota

  halfEdgeVertex* aux = v1Vertex->adjList;
  while(aux != emptyEdge){
  	addFront(aux->vertPtr->label, lst);
  	aux = aux->nextEdge;
  }
  return lst;
}

// Ritorna un cammino tra una citta' ed un altra
// Il cammino da "v1" a "v2" alla fine sara' in "path"
// e la lunghezza sara' in "len".
// Si assume che il chiamante fornisca inizialmente un cammino vuoto.
//
// La funzione rappresenta una variante della visita DFS



// Funzione ausiliaria che mette i Vertex visited a false
void vertexZeroVisited(const graph::Graph& g){
	if(isEmpty(g)) return;
	g->visited = false;
	vertexZeroVisited(g->nextNode);
}

// NOTA: presenta dei passi geografici inutili (dati dalla ricorsione)
void findPathAux(Label v1, Label v2, list::List &path, int &len, const Graph& g, bool &found){
	
	vertexNode* vertexAux = getVertex(v1,g);
	if(isEmpty(vertexAux) || isEmpty(getVertex(v2,g))) return;
	
	cout << "V1: " << v1 << "   " << "V2: " << v2 << endl;
	if (v1==v2){
		found = true;
		return;
	}
	
	halfEdgeVertex* aux = vertexAux->adjList;
	
	vertexAux->visited = true;
	while(aux != emptyEdge && !found)
		{
			if(!aux->vertPtr->visited){
				addFront(aux->vertPtr->label,path);
				len += aux->weight;
				findPathAux(aux->vertPtr->label, v2, path, len, g, found);
			}
			aux = aux->nextEdge;
		}
	return;
	
}

void graph::findPath(Label v1, Label v2, list::List &path, int &len, const Graph& g) {
    
     vertexZeroVisited(g);
     bool found = false;
     findPathAux(v1,v2,path,len,g, found);
     return; 
}

/*******************************************************************************************************/

void printGraphAux(const graph::Graph& g){
	if(isEmpty(g)) return;
  	g->visited = true;
  	std::cout << g->label << " ";
  	
  	halfEdgeVertex* aux = g->adjList; // puntatore ausiliario alla lista di adiacenza
  	
  	while(aux != emptyEdge){
  		//if(!g->adjList->vertPtr->visited){
  			cout << aux->vertPtr->label << " ";
  			cout << aux->weight << "|| ";
  		//}
		aux = aux->nextEdge;
  	}
  	cout << endl;
  	printGraphAux(g->nextNode);
}

// Stampa il grafo
void printGraph(const graph::Graph& g) {
  	vertexZeroVisited(g);
  	printGraphAux(g);
}
