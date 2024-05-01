#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define N 64
 
int main(){
	for(;;){
		printf("\nveronica $ ");
		
		char fn[N];
		scanf("%s", fn);
		
		// EOF è -1
		if(*fn == EOF || !strcmp(fn, "exit")) exit(EXIT_SUCCESS); 
		
		pid_t pid = fork();
		int status;
		switch(pid){
			case -1: perror("fork error");
			case 0: execlp(fn, fn, NULL); // execlp(primo valore, ultimo valore, terminatore) 
				perror("Exec fallita");
			default: wait(&status);
		}
	}
}
