#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>

const int DIM = pow(10,4);
const int NUMITER = pow(10,5);
int k = 0; // var ausiliaria per tenere in memoria il numero di confronti

int partition(std::vector<int>& seq, int start, int end){
    int p = seq[end];
    int i = start;
    int j = end - 1;
    k += end-start;

	while (true){
		while (i <= j && seq[j] >= p) j--;
		while (i <= j && seq[i] <= p) i++;
		if (i > j) break;
		int tempy = seq[i];
		seq[i] = seq[j];
		seq[j] = tempy;
	}

	// Riporto il pivot in posizione 
	int temp = seq[i];
	seq[i] = seq[end];
	seq[end] = temp;

	return i;
}

void qsort(std::vector<int>& seq, int start, int end){
	if (start < end){
		int p = partition(seq, start, end);
		qsort(seq, start, p - 1);
		qsort(seq, p + 1, end);
	}
}

void lvqs(std::vector<int>& seq){
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(seq.begin(), seq.end(), std::default_random_engine(seed));
	qsort(seq,0,DIM-1);
}

int main(){
	std::vector<int> S(DIM);
	std::vector<int> X(NUMITER); // confronti per run
	
	// Inserisco valori casuali nella sequenza
	for (int i=0; i<DIM; i++) S[i] = std::rand()%DIM; 
	// LVQS
	for (int i=0; i<NUMITER; i++){	
		lvqs(S);
		X[i] = k;
		std::cout << "Numero iterazioni run " << i+1 << ": " << k << std::endl;
		k = 0;
	}
	std::cout << std::endl;
	
	// Calcolo valore medio
	double medio = accumulate(X.begin(),X.end(),0.)/NUMITER;
	std::cout << "Valore medio: " << medio << std::endl;
	// Calcolo varianza
	double somma = 0;
	for(int i=0; i<NUMITER; i++)
		somma += pow(X[i] - medio, 2);
	double var = somma/(NUMITER-1);
	std::cout << "Varianza: " << var << std::endl;
	
	// Stampa su file
	std::ofstream f("confronti.txt");
	if (f.is_open())
	{
		for(int i=0; i<NUMITER; ++i) 
		    f << X[i] << "\n";
		f.close();
	}
	else std::cout << "Errore nell'apertura del file";
	return 0;
}
