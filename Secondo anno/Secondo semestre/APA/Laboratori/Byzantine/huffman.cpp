#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <string>
#include <tuple>

using std::string;
using Map = std::unordered_map<char,int>;
using Queue = std::queue<std::string>;
using std::vector;
using std::greater;
using std::tuple;
using CompressionMap = std::unordered_map<char,std::string>;
using std::get;

struct node{
	char c;		// carattere che il nodo rappresenta
	int freq;	// frequenza della sottostringa all'interno della stringa da codificare
	//string path;	// percorso a partire dalla radice (in binario)
	node* left;	// riferimento a figlio sinistro
	node* right;	// riferimento a figlio destor
	//node* father;	// riferimento a padre
	
	node(char c, int freq = 0) : c(c), freq(std::forward<int>(freq)),
	left(nullptr), right(nullptr){}
};

using Tree = node*;
using Heap = std::priority_queue<tuple<int, char, Tree>, vector<tuple<int, char, Tree>>, greater<tuple<int, char, Tree>>>;

Tree huffman(const Map& map){
	Heap heap;
	Tree tree;
	CompressionMap compressionMap;
	
	for (const auto [c,f] : map) heap.emplace(f,c, new node(c,f));
	
	Tree aux;
	for (int i=0; i < map.size()-1; ++i){
		auto tupla1 = heap.top();
		heap.pop();
		auto tupla2 = heap.top();
		heap.pop();
		
		// Creazione nodo fittizio
		aux = new node('\0',get<0>(tupla1)+get<0>(tupla2));
		aux->left = get<2>(tupla1);
		aux->right = get<2>(tupla2);
		heap.emplace(aux->freq, aux->c, aux);
	}
	
	
	return aux;
}

// manca visita e conseguentemente aggiunta di 0 e 1 per codificare, ovvero costruzione albero



Map create_map(Queue &q)
{
	std::string aux;
	Map map;
	while (std::getline(std::cin, aux)){
		q.push(aux);
		for(auto c : aux){
			map[c]++;
		}	
	}
	return map;
}

int main(int argc, char **argv){

	Queue q;
	//create_map();
	//CompressionMap = huffman();
	
	return 0;
}
