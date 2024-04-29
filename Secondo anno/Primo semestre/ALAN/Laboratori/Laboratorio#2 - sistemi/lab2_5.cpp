/* Laboratorio 2 ALAN - Sistemi
/* Membri gruppo	|||	Numero matricola

Kevin Cattaneo		||| 	S4944382
Gabriele Dellepere	||| 	S4944557
Roberto Lazzarini	||| 	S4937188
*/

#include <iostream>
#include <cstring>

struct matrix {
	float* m;
	int rows;
	int cols;
};

/* Funzione che stampa matrici di grandi dimensioni */
void print_big(matrix& mat){
	std::cout.precision(3);
	for(int t = 0; t < mat.rows; ++t){
		for(int j = 0; j < mat.cols; ++j)
			std::cout << mat.m[t * mat.cols + j] << " ";
		std::cout << "\n";
	}
}

/* Funzione che stampa matrici di piccole dimensioni */
void print_small(matrix& mat){
	std::cout.precision(3);
	for(int t = 0; t < mat.rows; ++t){
		for(int j = 0; j < mat.cols; ++j)
			std::cout << mat.m[t * mat.cols + j] << "\t";
		std::cout << "\n";
	}
}

/* Funzione che calcola e ritorna il valore di norma infinito di una matrice */
float norma_inf(matrix& mat) {
	/*
	  Per ottenere la norma infinito, è sufficiente prendere il massimo tra le somme delle righe considerando
	  tutti gli elementi in modulo.
	*/
	int max = 0;	//max non può essere < 0
	for(int i = 0; i < mat.rows; i++) {
		float sum = 0;
		for(int j = 0; j < mat.cols; j++) {
			sum += abs(mat.m[i*mat.cols + j]);
		}
		if(sum > max) max = sum;
	}

	return max;
}

/* Funzione che calcola con sostituzione all'indietro la soluzione del sistema lineare */
void sostituzione(matrix& reduced, matrix& result) {
	result.cols = 1;	//result sarà un vettore
	result.rows = reduced.cols - 1;
	result.m = new float[result.rows];
	
	for(int r = reduced.rows - 1; r >= 0; r--) {
		float sum = 0;
		for(int c = reduced.cols - 2; c > r; c--) {
			sum += reduced.m[r * reduced.cols + c] * result.m[c];
		}
		result.m[r] = (reduced.m[(r + 1) * reduced.cols - 1] - sum) / reduced.m[r * reduced.cols + r];
		//assumiamo che i pivot siano tutti sulla diagonale
	}

}

/* Funzione che calcola la riduzione gaussiana della matrice passata */
void gauss(matrix& A, matrix& b, matrix& result) {	
	if(b.cols != 1) throw "error: b deve essere un vettore";
	result.rows = A.rows;
	result.cols = A.cols + 1;
	result.m = new float[result.rows * result.cols];
	
	// Copio la matrice e unisco A e b
	for(int i = 0; i < result.rows; i++) {  
		for(int j = 0; j < result.cols - 1; j++) {
			result.m[i * result.cols + j] = A.m[i * A.cols + j];
		}
		result.m[(i + 1) * result.cols - 1] = b.m[i];				    
	}   
      						     

	float m = 0.0; // multiplo per la riduzione

	int r = 0; // indice ulteriore per le righe

	for(int i = 0; i < result.cols; ++i){ // cicla sui pivot
		// Osservo pivot potenziali più grandi di quello attuale, eventualmente swap
		int max = r; // riga del pivot di partenza
		int z = r+1;
		while(z < result.rows){
		    if(result.m[max * result.cols + i] < result.m[z * result.cols + i]) max = z;
		    z++;
		}
		if(result.m[max * result.cols + i] == 0)
			continue;
		if(max != r) // evito swap inutili
			// Giunto qui ho trovato un valore sulla colonna non zero, scambio le righe
			// -- Swap effettivo
			for(int j = 0; j < result.cols; ++j){
			    float t = result.m[r * result.cols + j];
			    result.m[r * result.cols + j] = result.m[max * result.cols + j];
			    result.m[max * result.cols + j] = t;
			}

		for(int k = r+1; k < result.rows; ++k){
		    // si suppone che matrix[k][c] != 0 (perchè già azzerata, non ripeto l'operazione), altrimenti passo alla riga successiva
		    if(result.m[k * result.cols + i] == 0)
		        continue;

		    m = result.m[k * result.cols + i] / result.m[r * result.cols + i];

		    for(int j = i; j < result.cols; ++j)
		        result.m[k * result.cols + j] = result.m[k * result.cols + j] - m * result.m[r * result.cols + j];
		}
		r++;
    	}
	std::cout << "\nMatrice A|b ridotta\n";
	result.cols > 50 ? print_big(result) : print_small(result);

}

/* Funzione che calcola il prodotto riga colonna fra due matrici (il vettore è inteso come matrice a singola colonna) */
void prod_riga_colonna(matrix& mat1, matrix& mat2, matrix& result) {	
	if(mat1.cols != mat2.rows) throw "errore: il numero di colonne di mat1 non coincide col numero di righe di mat2\n";
	result.rows = mat1.rows;
	result.cols = mat2.cols;
	result.m = new float[result.rows * result.cols];

	for(int k = 0; k < mat2.cols; k++) {	//finchè operiamo su vettori mat2.cols sarà = 1
		for(int i = 0; i < mat1.rows; i++) {
			float sum = 0.0;
			for (int j = 0; j < mat1.cols; j++) {
				sum += (mat1.m[i*mat1.cols + j] * mat2.m[j*mat2.cols + k]);
			}
			result.m[i*mat2.cols + k] = sum;
		}
	}
}

/* Funzione che esegue i passi necessari per ottenere la soluzione del sistema lineare: 
*	- calcolo di b dalla x attesa
*	- riduzione gaussiana di A|b
*	- sostituzione all'indietro
*	-- in accordo con l'esercizio 3 (b perturbato)
*/
void solve3(matrix& your_matrix){
	
	matrix x;	// x è un vettore (ci si aspetta di #colonne = 1); soluzione attesa
	matrix b;	// b sarà un vettore (ci si aspetta di #colonne = 1)
	matrix reduced;	// variabile temporanea dove porre la matrice ridotta con Gauss
	matrix xx; 	// xx come vettore soluzione x calcolato del sistema lineare
	
	x.cols = 1;	
	x.rows = your_matrix.cols;
	x.m = new float[x.rows];
	for(int i = 0; i < x.rows; i++) {
		x.m[i] = 1;
	}

	prod_riga_colonna(your_matrix, x, b);
	
	// b perturbato
	matrix db;
	db.rows = b.rows;
	db.cols = b.cols;
	db.m = new float[db.rows];
	
	for(int i=0; i<db.rows; ++i){
		db.m[i] = norma_inf(b) * (i % 2 == 0 ? -0.01 : 0.01);
		b.m[i] += db.m[i]; // sovrascrivo col vettore perturbato
	}
	
	gauss(your_matrix, b, reduced);
	sostituzione(reduced, xx);
	
	std::cout << "Vettore soluzione -trasposto-: (";
	for(int i = 0; i < xx.rows; i++) 
		std::cout << xx.m[i] << (i != xx.rows-1 ? ", " : ")");
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] x.m;
	delete[] b.m;
	delete[] reduced.m;
	delete[] xx.m;
}

/* Funzione che esegue i passi necessari per ottenere la soluzione del sistema lineare: 
*	- calcolo di b dalla x attesa
*	- riduzione gaussiana di A|b
*	- sostituzione all'indietro
*	-- in accordo con l'esercizio 2
*/
void solve2(matrix& your_matrix){
	
	matrix x;	// x è un vettore (ci si aspetta di #colonne = 1); soluzione attesa
	matrix b;	// b sarà un vettore (ci si aspetta di #colonne = 1)
	matrix reduced;	// variabile temporanea dove porre la matrice ridotta con Gauss
	matrix xx; 	// xx come vettore soluzione x calcolato del sistema lineare
	
	x.cols = 1;	
	x.rows = your_matrix.cols;
	x.m = new float[x.rows];
	for(int i = 0; i < x.rows; i++) {
		x.m[i] = 1;
	}

	prod_riga_colonna(your_matrix, x, b);
	
	gauss(your_matrix, b, reduced);
	sostituzione(reduced, xx);
	
	std::cout << "Vettore soluzione -trasposto-: (";
	for(int i = 0; i < xx.rows; i++) 
		std::cout << xx.m[i] << (i != xx.rows-1 ? ", " : ")");
	std::cout << std::endl;
	std::cout << std::endl;

	delete[] x.m;
	delete[] b.m;
	delete[] reduced.m;
	delete[] xx.m;
}

/* Funzione che calcola il fattoriale di un valore passato
* Nota: funzione tipo double per memorizzare una quantità di numeri maggiore
*/ 
double factorial(long x) {
	if(x < 0) return -1;
	if(x == 0) return 1;
	return x * factorial(x-1);
}


int main() {

	/* ------------------------------------------------------- */
	/* ---- Esercizio 1_A: Norma infinito di matrici date ---- */
	/* ------------------------------------------------------- */
	std::cout << "@@@ Esercizio 1A @@@\n\n";
	float norma;
	matrix A1;
	A1.rows = 4;
	A1.cols = 4;
	float matrix1[16] = 
	{	
	  3, 1, -1, 0,
	  0, 7, -3, 0,
	  0, -3, 9, -2,
	  0, 0, 4, -10	
	};
	A1.m = matrix1;
	
	std::cout << "\n### Questa è la matrice A1 ###\n";
	print_small(A1);
	
	norma = norma_inf(A1);
	std::cout << "Norma infinito della matrice A1: " << norma << std::endl;
	
	matrix A2;
	A2.rows = 4;
	A2.cols = 4;
	float matrix2[16] = 
	{	
	  2, 4, -2, 0,
	  1, 3, 0, 1,
	  3, -1, 1, 2,
	  0, -1, 2, 1
	};
	A2.m = matrix2;

	std::cout << "\n### Questa è la matrice A2 ###\n";
	print_small(A2);

	norma = norma_inf(A2);
	std::cout << "Norma infinito della matrice A2: " << norma << "\n\n";
	
	/* ------------------------------------------ */
	/* ---- Esercizio 1_B: Matrice di Pascal ---- */
	/* ------------------------------------------ */
	
	std::cout << "---------------------------------------------\n";
	std::cout << "@@@ Esercizio 1B @@@\n\n";
	int n = 10; // dimensione data
	matrix P;
	P.rows = n;
	P.cols = n;
	P.m = new float[(n)*(n)];
	//P.m = new float[(n+1)*(n+1)]; // il +1 è 

	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < n+1; j++) {
			//sottraiamo 1 a i e j quando indicizziamo (dato dalla dichiarazione standard di un array: da 0 a n-1) 
				// (qui da 1 a n)
			P.m[(i-1) * n + (j-1)] = factorial(i + j - 2) / (factorial(i-1)*factorial(j-1));
		}
	}
	std::cout << "\n### Questa è la matrice di Pascal calcolata ###\n";
	print_small(P);
	norma = norma_inf(P);
	std::cout << "Norma infinito della matrice di Pascal: " << norma << "\n\n";


	/* --------------------------------------------- */
	/* ---- Esercizio 1_C: Matrice tridiagonale ---- */
	/* --------------------------------------------- */
	
	/* In ordine alfabetico
	Roberto Lazzarini	||| 	S4937188
	è l'ultimo componente del gruppo. D0 = 8, D1 = 8;
	Dunque n = 10*(D1+1)+D0 è n = 98;
	*/
	std::cout << "---------------------------------------------\n";
	std::cout << "@@@ Esercizio 1C @@@\n\n";
	int d1 = 1;
	int d0 = 1;
	int m = 10*(d1+1) + d0;

	matrix T;
	T.rows = m;
	T.cols = m;
	T.m = new float[m*m];

	// Inizializzo la matrice a zero
	std::memset(T.m, 0, m*m*sizeof(float));
	
	for(int i = 0; i < m-1; i++) {
		T.m[i * m + i] = 2;	
		T.m[(i+1) * m + i] = -1;	
		T.m[i * m + (i+1)] = -1;
	}
	T.m[m*m-1] = 2;	// inizializziamo così l'ultimo elemento, che altrimenti resterebbe a 0
	
	std::cout << "\n### Questa è la matrice tridiagonale ###\n";
	print_big(T);
	norma = norma_inf(T);
	std::cout << "Norma infinito della matrice tridiagonale: " << norma << "\n\n";

	/* ------------------------------------------------------ */
	/* ---- Esercizio 2: Soluzione di un sistema lineare ---- */
	/* ------------------------------------------------------ */
	
	std::cout << "---------------------------------------------\n";
	std::cout << "@@@ Esercizio 2 @@@\n\n";
	std::cout << "\n### Matrice A1 ###\n";
	matrix your_matrix = A1;
	solve2(your_matrix);

	std::cout << "\n### Matrice A2 ###\n";
	your_matrix = A2;
	solve2(your_matrix);

	std::cout << "\n### Matrice di Pascal ###\n";
	your_matrix = P;
	solve2(your_matrix);

	std::cout << "\n### Matrice Tridiagonale ###\n";
	your_matrix = T;
	solve2(your_matrix);


	/* ---------------------------------------------------------------------------------- */
	/* ---- Esercizio 3: Soluzione di un sistema lineare con termine noto perturbato ---- */
	/* ---------------------------------------------------------------------------------- */
	
	std::cout << "---------------------------------------------\n";
	std::cout << "@@@ Esercizio 3 @@@\n\n";
	std::cout << "\n### Matrice A1 ###\n";
	your_matrix = A1;
	solve3(your_matrix);

	std::cout << "\n### Matrice A2 ###\n";
	your_matrix = A2;
	solve3(your_matrix);

	std::cout << "\n### Matrice di Pascal ###\n";
	your_matrix = P;
	solve3(your_matrix);

	std::cout << "\n### Matrice Tridiagonale ###\n";
	your_matrix = T;
	solve3(your_matrix);
	
	return 0;

}
