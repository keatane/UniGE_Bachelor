// Es_12H: Scrivere una funzione isUpper che presa una matrice quadrata di caratteri restituisce true se tutti gli elementi contenuti sono
// lettere maiuscole, cioè caratteri nell’intervallo ['A','Z'], false altrimenti usando l’aritmetica dei puntatori per scorrere la matrice.


#include <iostream>

using namespace std;

const int N = 2;
const int M = 2;

bool isUpper(char *p){

	for (unsigned int i=0; i<N*M; ++i)
		if (*(p+i) < 'A' || *(p+i) > 'Z')
			return false;
	return true;
}

int main()
{
	char a[N][M];
    for (unsigned int i=0; i<N; ++i)
		for (unsigned int j=0; j<N; ++j){
			cout << "Inserisci l'elemento alla riga " << i << " e colonna " << j << endl;
			cin >> a[i][j];
		}

    char *p = &a[0][0];
	cout << boolalpha << "Tutte maiuscole: " << isUpper(p) << endl;
}
