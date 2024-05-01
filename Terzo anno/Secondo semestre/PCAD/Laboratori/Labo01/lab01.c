#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

struct sharedInfo {
	const unsigned blocks_num;
	double* first_matrix;
	double* second_matrix;
	double* third_matrix;
	double* aux_matrix;
	double* destination_matrix;
	const unsigned long first_matrix_height;
	const unsigned long second_matrix_width;
	const unsigned long shared_dim;

	pthread_barrier_t barrier;
};

typedef struct sharedInfo shared_info;

struct threadInfo {

	unsigned thread_id;
	shared_info* shared;
};

typedef struct threadInfo thread_info;

void multiply(double * row, double * column, double * dest, const unsigned long row_width_1, const unsigned long row_width_2) {
// funzione che effettua il prodotto scalare tra una riga e una colonna

	double sum = 0.0f;
	for(unsigned long i = 0; i < row_width_1; i++) {
		sum += row[i] * column[row_width_2 * i];
	}
	*dest = sum;
}

void multiplyMatrices(double * first_matrix, double * second_matrix, double * dest, const unsigned long row_width_1, const unsigned long num_rows_1, const unsigned long row_width_2) {
// funzione che effettua la moltiplicazione di due blocchi, appoggiandosi alla funzione multiply

	for(unsigned long row = 0; row < num_rows_1; row++) {
		for(unsigned long col = 0; col < row_width_2; col++) {
			multiply(first_matrix + (row * row_width_1), second_matrix + col, dest + (row * row_width_2) + col, row_width_1, row_width_2);
		}
	}
}


void thread_init(void* args) {
// funzione che inizializza un singolo thread, determina su quale blocco deve lavorare sulla base del suo id (e le dimensioni delle matrici)
// e poi chiama la multiplyMatrices due volte (una per A*B e l'altra per C*R)
	
	thread_info* t_info = (thread_info*) args;
	shared_info* s_info = t_info->shared;
	
	long block_height = 1 + ((s_info->first_matrix_height - 1) / s_info->blocks_num);	//non possiamo renderlo unsigned perchè sennò non possiamo controllare lo sforamento

	double* block = s_info->first_matrix + (block_height * t_info->thread_id) * s_info->shared_dim;
	double* dest = s_info->aux_matrix + (block_height * t_info->thread_id) * s_info->second_matrix_width;

	bool working = true;

	if (block_height * (t_info->thread_id + 1) > s_info->first_matrix_height) {			//evitiamo di sforare (es. 7 thread per 5 righe)
		block_height = s_info->first_matrix_height - (block_height * t_info->thread_id);
		if (block_height <= 0) {
				
			working = false;	//a questo thread non è rimasto lavoro da fare
		}
	}

	if(working)
		multiplyMatrices(block, s_info->second_matrix, dest, s_info->shared_dim, (unsigned long) block_height, s_info->second_matrix_width);	// R = A * B

	pthread_barrier_wait(&(s_info->barrier));
	
	block_height = 1 + ((s_info->second_matrix_width - 1) / s_info->blocks_num);

	block = s_info->third_matrix + (block_height * t_info->thread_id) * s_info->first_matrix_height;
	dest = s_info->destination_matrix + (block_height * t_info->thread_id) * s_info->second_matrix_width;

	working = true;

	if (block_height * (t_info->thread_id + 1) > s_info->second_matrix_width) {			//evitiamo di sforare (es. 7 thread per 5 righe)
		block_height = s_info->second_matrix_width - (block_height * t_info->thread_id);
		if (block_height <= 0) {
				
			working = false;	//a questo thread non è rimasto lavoro da fare
		}
	}

	if(working)
		multiplyMatrices(block, s_info->aux_matrix, dest, s_info->first_matrix_height, (unsigned long) block_height, s_info->second_matrix_width);	//CR = C * R
	
	return;
}

int main(int argc, char** argv) {
// main
	
	int err;

	unsigned long T, M, N, P;	//numero blocchi + dimensioni matrici
	scanf("%ld", &T);
	scanf("%ld", &M);
	scanf("%ld", &N);
	scanf("%ld", &P);

	if (T == 0)
		return 1;

	pthread_t* jobs = malloc(sizeof(pthread_t) * T);	//array di threads

	double *A, *B, *C;

	A = malloc(sizeof(double) * M * N);
	B = malloc(sizeof(double) * N * P);
	C = malloc(sizeof(double) * P * M);

	//le matrici sono prese da stdin. Per tale motivo, si consiglia di effettuare la redirezione dell'input da un file che le contiene

	for(unsigned m = 0; m < M; m++) {
		for(unsigned n = 0; n < N; n++) {
			scanf("%lf", A + (m * N) + n);
		}		
	}
	for(unsigned n = 0; n < N; n++) {
		for(unsigned p = 0; p < P; p++) {
			scanf("%lf", B + (n * P) + p);
		}		
	}
	for(unsigned p = 0; p < P; p++) {
		for(unsigned m = 0; m < M; m++) {
			scanf("%lf", C + (p * M) + m);
		}		
	}

	double *R = malloc(sizeof(double) * M * P);	//R matrice intermedia/ausiliaria
	double *CR = malloc(sizeof(double) * P * P);	//CR = C*R

	shared_info info = {T, A, B, C, R, CR, M, P, N};		//teniamo una sola struct allocata per le informazioni costanti tra tutti i thread 
									//(in modo da evitare copie inutili in memoria)

	thread_info* threads_info = malloc(sizeof(thread_info) * T);	//array contenente le struct passate come parametri ai thread

	err = pthread_barrier_init(&(info.barrier), NULL, T);

	if(err) {
		perror("an error has occurred while initializing the barrier\n");
		exit(1);
	}

	struct timespec then;
	err = clock_gettime(CLOCK_REALTIME, &then);

	if(err) {
		perror("clock_gettime error\n");
		exit(1);
	}
	
	for(unsigned long t = 0; t < T; t++) {
		threads_info[t].thread_id = t;
		threads_info[t].shared = &info;

		err = pthread_create(jobs + t, NULL, (void*)thread_init, (void*)(threads_info + t));
		
		if(err) {
			perror("an error has occurred while initializing a thread\n");
			exit(1);
		}
	}

	for(unsigned long t = 0; t < T; t++) {
		long* useless;
		pthread_join(jobs[t], (void**) &useless);	//non controlliamo il valore di ritorno dei thread, non ci fornisce info utili
	}

	struct timespec now;
	err = clock_gettime(CLOCK_REALTIME, &now);
	if(err) {
		perror("clock_gettime error\n");
		exit(1);
	}
	
	if (argc < 2 || (strncmp(argv[1], "NOPRINT", 7))) {	//passango come argomento "NOPRINT" il programma non stampa la matrice risultato (utile per controllare solo i tempi di calcolo)

		printf("R: \n");

		for(unsigned p1 = 0; p1 < M; p1++) {
			for(unsigned p2 = 0; p2 < P; p2++) {
				printf("%f ", *(R + (p1 * P) + p2));
			}	
			printf("\n");
				
		}
		printf("\n");
		printf("C*R: \n");

		for(unsigned p1 = 0; p1 < P; p1++) {
			for(unsigned p2 = 0; p2 < P; p2++) {
				printf("%f ", *(CR + (p1 * P) + p2));
			}	
			printf("\n");
				
		}

		printf("\n");

	}

	double elapsed_seconds = difftime(now.tv_sec, then.tv_sec);
	double elapsed_milliseconds = (double)((now.tv_nsec - then.tv_nsec) / 1000);	//tronchiamo alla sesta cifra decimale

	printf("the computation took: %lf seconds\n", (elapsed_seconds + elapsed_milliseconds / 1000000.0));

	/*
		Note sui risultati: Come ci si poteva aspettare, la performance del programma aumenta linearmente con l'aumentare
		del numero di blocchi (e quindi thread) fino al raggiungimento del numero massimo di core (fisici + virtuali) che la
		macchina ha a disposizione. Superato quel numero, anche per input grandi (di ordine 10^6) si registrano fluttuazioni 
		dei tempi impiegati di appena qualche millisecondo (su una media dell'ordine di qualche secondo), quindi non 
		statisticamente significative.
	*/

	free(A);
	free(B);
	free(C);
	free(R);
	free(CR);

	return 0;

}
