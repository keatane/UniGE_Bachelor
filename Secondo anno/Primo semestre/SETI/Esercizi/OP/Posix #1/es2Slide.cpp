// C version
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SZ 128

int main(int argc, char* argv[]){

	size_t rsize;
		char buf[BUFF_SZ];
	if(argc == 1){
		printf("Inserisci una stringa\n");
		
		while((rsize = read(0, &buf, BUFF_SZ)) > 0){
			write(1,&buf,rsize);
		}
		
		if(rsize == -1) perror("Errore in lettura da stdin"), exit(1);
	}
	else{
		
		for(int i=1; i<argc; ++i){
			int fd = open(argv[i], O_RDONLY);
			if(fd == -1) perror(argv[i]), exit(i);
			
			while((rsize = read(fd, &buf, BUFF_SZ)) > 0)
				write(1, &buf, rsize);
			
			if(rsize == -1) perror(argv[i]), exit(i);
			close(fd);
		}	
	}

	return 0;
}

/*
-- C++ version --

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

	string word = "";
	ifstream fd;
	if(argc == 1) // significa che contiene solo il nome del programma
	{
		std::cout << "Inserisci una stringa\n";
		cin >> word;
	}
	else if(argc > 1)
	{
		for(int i=1; i<argc; ++i){
			
			fd.open(argv[i]);
			
			if(!fd)
				return -1;
				
			fd >> word;
			while(!fd.eof()){
				cout << word << endl;
				fd >> word;
			}
			fd.close();
		}
		return 0;
	}
	else return -1; // errore
	
	cout << endl;
	cout << word << endl;

	return 0;
}

// Se il file passato non esiste termina
// Se il file passato esiste ma non ho il permesso termina

*/
