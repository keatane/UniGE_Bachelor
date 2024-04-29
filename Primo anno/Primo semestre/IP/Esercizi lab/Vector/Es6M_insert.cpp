/* Es_6 di base: Scrivere una funzione std::vector<int> insert(std::vector v, int i, int val) che aggiunge a v in posizione i il valore di
val. La lunghezza di v deve essere incrementata di 1 e tutto l’eventuale contenuto di v, dalla posizione i (compresa) fino alla
fine, deve essere spostato in avanti di una posizione. NOTA: siccome è previsto che il vettore si incrementi di dimensione,
le posizioni di inserimento valide sono tutte quelle esistenti (da 0 a v.size()-1) e anche una oltre l’ultima (la posizione
v.size()), quindi i∈ [0,v.size()]. Se i non è compreso in questo intervallo sollevare una eccezione int.
[SUGGERIMENTO: Inserire in coda a v il suo ultimo elemento (se esiste), spostare in avanti di una posizione gli elementi di
v a partire dalla posizione i in avanti (copiandoli a partire dal fondo in modo da non sovrascriverli) e assegnare il valore da
inserire nella posizione i.]
Scrivere un programma di test che dichiara un std::vector<int> e fa il test della funzione insert nei seguenti casi:
(a) Inserimento in v vuoto
(b) Inserimento in testa (in posizione 0) a v non vuoto
(c) Inserimento in coda (dopo l’ultima posizione) a v non vuoto
(d) Inserimento in posizione generica (non testa, non coda) in v non vuoto
(e) Inserimento in posizione non valida (usare try . . . catch per trattare l’eccezione).
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readVector(std::vector<int>& v) {
	// Stampare "Inserisci la dimensione della sequenza: "
	cout << "Inserisci la dimensione della sequenza: ";
	// Dichiarare una variabile intera N
	int N;
	// Leggere N
	cin >> N;
	/* iterare N volte
	- leggere un valore intero
	- memorizzare il valore letto in v
	*/
	cout << "Inserisci " << N << " valori interi" << endl;
	for (unsigned int i = 0; i<N; ++i){
        int val;
        cin >> val;
        v.push_back(val); // Inserisco in fondo al vector l'elemento in input: automaticamente il push back ridimensiona il vectir
	}

}

void printVector(const std::vector<int>& v) {
	/* iterare v.size() volte
	- stampare l'elemento corrente di v
	*/
	for (unsigned int i = 0; i<v.size(); ++i)
		cout << v[i] << (i==v.size()-1 ? "\n" : " ");
}

vector<int> insert(vector<int> v, int i, int val){

    int max = v.size(); // Questo perchè size() non restituisce davvero un intero, ma un tipo size_t: non porre questa 'conversione' crea dei problemi nei confronti
	if (i>max) throw -1;
	if (i<0) throw -2;
    v.resize(v.size()+1); // Quindi i ora raggiunge size()-1, che corrisponde al valore di size() precedente

    for (unsigned int j=v.size()-1; j>i; --j) // L'indice j (per definizione di indice) ha valore max: size()-1 (= DIM-1)
        v[j] = v[j-1];   // In i=v.size() vi è un valore sconosciuto, che viene sovrascritto da un valore noto (inserito precedentemente)
    v.at(i) = val;


	return v;

}


int main() {

	// dichiarare un std::vector vect di interi
	vector<int> v;
	// chiamare la funzione readVector su vect
	readVector(v);
	cout << endl;
	cout << "Stampa: ";
	// chiamare la funzione printVector su vect
	printVector(v);
	try{
		v = insert(v, 3, 48);
        printVector(v);
	}
    catch(int& a)
	{
	    switch(a){
            case -1:
                cout << "Indice troppo grande\n";
                break;
            case -2:
                cout << "Indice troppo piccolo\n";
                break;
            default:
                break;
	    }
	}


}
