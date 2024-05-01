#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define N 64
 
int main(){
	int f[2];
	
	int status1, status2;
	
	// Chiamata di pipe
	if(pipe(f) == -1) perror("Pipe failed\n");
	
	pid_t pid = fork();
	
	switch(pid){
		
		case -1: perror("Fork error\n");
		case 0:
		// la write end del pipe va sullo stdout
		if(dup2(f[1],1) == -1) exit(EXIT_FAILURE);
		execlp("ps","ps","aux",NULL);
		exit(EXIT_FAILURE); // se giungo qui, significa che non è stata eseguita correttamente la exec
	}
	wait(&status1);
	close(f[1]); // fine scrittura
	
	pid = fork();
	switch(pid){
		
		case -1: perror("Fork error\n");
		case 0:
		// la read end del pipe va sullo stdin
		if(dup2(f[0],0) == -1) exit(EXIT_FAILURE);
		execlp("grep","grep","bash", NULL);
		exit(EXIT_FAILURE); // se giungo qui, significa che non è stata eseguita correttamente la exec
	}
	
	// controllo wexitstatus omesso
	
	wait(&status2);
	close(f[0]); // questo è necessario: serve per "confermare" alla pipe che il lavoro sulla lettura è terminato, e quindi legge EOF

	
}


