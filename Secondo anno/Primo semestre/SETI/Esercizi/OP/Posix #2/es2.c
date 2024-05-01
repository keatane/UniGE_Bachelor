#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define N 64
 
int main(int argc, char* argv[]){

	char f[N] = "/usr/bin/";
	printf("Inserisci il nome di un file\n");
	
	// Al posto di sprintf, uso fgets
	fgets(f+9, N-9, stdin);
	f[strlen(f)-1] = '\0';
	
	execl(f, f+9, NULL);
	// Giunto qui la exec non è stata eseguita
	perror("Exec error\n");
	
	
	
}


