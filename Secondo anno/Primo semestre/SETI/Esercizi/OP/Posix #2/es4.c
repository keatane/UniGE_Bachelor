#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define N 64
 
int main(int argc, char* argv[]){
	if(argc != 2) exit(EXIT_FAILURE);
	
	int fd;
	
	while((fd = dup(1)) == -1); // dup restituiscce il fd, duplicato da stdout

	if(close(1)) exit(1); // duplicato, quindi chiude l'oldfd
	
	while(open(argv[1], O_CREAT | O_RDWR, 00664) == -1); // open sul fd corrente, ovvero il fd più piccolo liberato (1)
	// non ho bisogno di salvare il fd della open, so già che è 1 (prima ricoperto da stdout ora liberato)
	if(close(fd)) exit(1);
	
	execlp("ls", "ls", "-l", NULL); // la sys call prende automaticamente i fd aperti (usa 1 di standard, che è stdout ma sostituito)
	
	
	
	
}
