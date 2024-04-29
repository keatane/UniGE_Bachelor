// Cattaneo Kevin - Preappello 21/12/2020


// Esercizio 1
bool ord(vector<int>& v){
	if (v.size() == 0) throw string("empty list");
	for (unsigned int i=0; i<v.size()-1; ++i)
		if (v[i]>v[i+1]) return false;
	return true;
}

// Esercizio 2
// 2.A
struct cell{
	char mov;
	cell* next;
};

typedef cell* listaMov;


// 2.B
void FaiUnPasso(listaMov &l, char x);

void FaiUnPassoIndietro(listaMov &l);

void Stampa(const listaMov &l);

char Direzione(const listaMov &l);

// 2.C
void FaiUnPasso(listaMov &l, char x){
	
	if (x == 'U' || x == 'D' || x == 'L' || x == 'R')
	{

		cell* aux = new cell;
		aux -> mov = x;
		aux -> next = nullptr;
		
		if (l==nullptr){ // lista vuota
			l = aux;
			return;
		}
		

		cell* tail = l; 
		while(tail->next != nullptr){ 
			tail = tail -> next; 
		}
		tail->next = aux;
	}
	else
		throw string("spostamento non riconosciuto");
}
