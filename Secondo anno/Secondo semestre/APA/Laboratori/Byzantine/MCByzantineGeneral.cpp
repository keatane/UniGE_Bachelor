#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include <vector>

const int t = 1; // numero processi inaffidabili
const int numProc = 3*t+1; // numero processi totali, gli ennesimi sono inaffidabili
const int numRun = pow(2,10);

int MCByzantine(int bit[], int& round){
	int a[numProc][numProc-t];
	
	while (true){
		// Trasmetto bit (fra righe), tranne quello inaffidabile
		for(int k=0; k<numProc-t; k++)
			for(int i=0; i<numProc-t; i++)
					a[k][i] = bit[k];
	
		// Trasmissione della confusione da parte degli inaffidabili
		for(int k=0; k<numProc-t; k++){
			for(int i=numProc-t; i<numProc; i++)
				a[i][k] = 1-bit[k];
		}

		int numZero[numProc-t];
		int numOne[numProc-t];
		int maj[numProc-t];
		int tally[numProc-t];
		int moneta = rand()%2; // moneta globale: esito uguale x tutti ad ogni round
		
		// Conta dei valori maggioritari (solo per processi affidabili)
		for(int k=0; k<numProc-t; k++){	
			numZero[k] = 0;
			numOne[k] = 0;
			
			for(int i=0; i<numProc; i++){
				if(i != k){
					if(a[i][k] == 0)
						numZero[k]++;
					else numOne[k]++;
				}	
			}
			
			// Includo il proprio bit trasmesso
			if(bit[k] == 0)
				numZero[k]++;
			else numOne[k]++;
			
			// Calcolo maggioritari
			if(numZero[k] > numOne[k]){
			 	maj[k] = 0;
			 	tally[k] = numZero[k];
			}
			else{
				 maj[k] = 1;
				 tally[k] = numOne[k];
			}
			//std::cout << "Bit: " << bit[k] << std::endl;
			if(tally[k] >= 2*t+1)
				bit[k] = maj[k];
			else if(moneta==0)
				bit[k] = 1;
			else bit[k] = 0;
		}
		
		// Verifico se si è raggiunto il consenso fra gli affidabili
		bool consenso = true;
		for(int i=0; i<numProc-t-1; i++)
			if(a[i][0] != a[i+1][0])
				consenso = false;
		if(consenso) return a[0][0];
		round++;
	}
}

int main(){
	srand(time(NULL));
	int bit[numProc-t], round; // bit trasmessi da processi affidabili
	std::vector<int>roundTot;
	std::vector<int>freq(numRun+1,0);
	
	for(int i=0; i<numRun; i++){
		bit[0] = bit[1] = 0;
		bit[2] = 1;
		
		/*** 
		NOTA: Di per sè non saranno mai d'accordo al 'primo' round
		per come ho impostato i bit, quindi non considero l'inizializzazione 
		dei bit come un round (che dunque parte da zero).
		***/

		MCByzantine(bit, round=0);
		roundTot.push_back(round);
	}
		
	// Freq[0] = numero di run in cui l'accordo è raggiunto in 1 round
	for(int i=0; i<numRun; i++)
		for (int e : roundTot)
			if(e == i+1)
				freq[i]++;
				
	// Stampa su file della frequenza di ottenimento dei round
	std::cout << "Round | Frequenza consensi\n";
	std::ofstream f("freq.txt");
	if (f.is_open())
	{
		for(int i=0; i<numRun; i++)
			if(freq[i] != 0){
				f << freq[i] << "\n";
				std::cout << i+1 << ": " << freq[i] << std::endl;
				if(accumulate(freq.begin(),freq.begin()+i,0) == numRun) break;
			}
		f.close();
	}
	else std::cout << "Errore nell'apertura del file";
	
	
}
