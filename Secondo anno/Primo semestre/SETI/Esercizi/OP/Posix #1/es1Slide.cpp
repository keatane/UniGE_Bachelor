#include <iostream>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>

using namespace std;

int main(){
	
	int fd;
	if(fd = open("/tmp/pippo", O_RDONLY | O_CREAT | O_EXCL) == -1)
		{cout << "Error" << endl;return errno;}
	cout << "Done" << endl;
	return 0;
}

/*
-> Se il file esiste già:
- la sys call non va a buon fine
- il contenuto del file viene preservato
- in sola lettura (e anche scrittura) il contenuto viene preservato
- con il flag O_EXCL controllo preventivamente se il file esiste, in caso non lo ri creo

-> Posso modificare il file con un editor di testo se e solo se:
- creo un altro file quando salvo ciò che ho scritto
- apro quel file con un flag diverso: col permesso di scrittura (neanche il root può sovrascrivere il divieto di scrittura)
*/
