#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define N 64
 
int main(int argc, char* argv[]){

	pid_t pid = fork(); // fork perchè si chiamerà exec e non voglio far chiudere il programma corrente
	int status = -1;
	switch(pid){
		case -1: perror("fork error");
		case 0: // child
		execlp("ls", "ls", "-l", NULL);	perror("Exec fallita");
		
		// Serve usare wait() perchè altrimenti il programma non termina
			// questo perchè quando il parent termina non richiama il terminale
		default: // parent 
		wait(&status); if(!WIFEXITED(status) || WEXITSTATUS(status) == -1) perror("Error in wait()");
	}
	
	
	
}


