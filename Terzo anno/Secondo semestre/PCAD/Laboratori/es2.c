#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *foo(void *vargp) {
	int myid;
	myid = *((int *)vargp);
	printf("Thread %d\n", myid);
	*(int*)vargp = 10; // se il thread non ha aggiornato questo valore dal for nel main non va avanti
	return(0);
}

int main() {
	pthread_t tid[5];
	void *ret;
	int *ptr;
	ptr = malloc(sizeof(int));
	*ptr = 10;
	for (int i = 0; i < 5; i++) {
		while(*ptr + 1 == i);
		*ptr = i;
		pthread_create(tid+i, 0, foo, ptr);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(tid[i],&ret);
	}
	return 0;
}
