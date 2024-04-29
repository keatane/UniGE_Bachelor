// Programma svolto dai membri: Gabriele DellePere, Roberto Lazzarini, Kevin Cattaneo

#include <iostream>
#include <math.h> // per pow()

using namespace std;

double fact(int N){
	if(N < 0) return -1;
	if(N == 0) return 1;
	return N*fact(N-1);
}

double funcTaylor(double x, int N){
	if(N < 0) return -1.0;
	double sum = 0.0;
	for(int i=0; i<N; ++i){
		sum += pow(x,i)/fact(i);
	}
	return sum;
}

void printResults(double x, int ALG){

	if(ALG != 1 && ALG != 2) return; 
	int N[5] = {3,10,50,100,150};
	
	cout << "Valore x = " << x << endl;

	double res = 0.0;
	
	res = exp(x); // se ALG2 e -x qui non cambia
	cout << "f(x) = " << res << endl;
		
	
	double resN = 0.0;
	double errA = 0.0;
	
	cout.precision(17);
	if(ALG == 1){
		for(int i = 0; i < 5; ++i){
			cout << "fN(x) = " << (resN = funcTaylor(x,N[i])) << " con N = " << N[i] << endl;
			cout << "Errore assoluto " << resN << "-" << res << " = " << (errA = (resN-res)) << endl;
			cout << "Errore relativo " << (errA/res) << endl << endl;
		}
	}
	else{ // ALG == 2
		x = -x;
		for(int i = 0; i < 5; ++i){
			cout << "1/fN(x) = " << (resN = 1/funcTaylor(x,N[i])) << " con N = " << N[i] << endl;
			cout << "Errore assoluto " << resN << "-" << res << " = " << (errA = (resN-res)) << endl;
			cout << "Errore relativo " << (errA/res) << endl << endl;
		}
	}
}

int main(){
	
	// ALGORITMO 1
	cout << "ALGORITMO 1\n";
	printResults(0.5,1);
	cout << "--------------------------" << endl;
	printResults(30,1);
	cout << "--------------------------" << endl;
	printResults(-0.5,1);
	cout << "--------------------------" << endl;
	printResults(-30,1);
	
	// ALGORITMO 2
	cout << "ALGORITMO 2\n";
	printResults(-0.5,2); // in Taylor viene valutata la x opposta
	cout << "--------------------------" << endl;
	printResults(-30,2);
	cout << "--------------------------" << endl;
	
	return 0;
}
