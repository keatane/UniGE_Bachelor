/* Es_9 di base:  Fissata una costante intera positiva N, scrivere una funzione che, preso in ingresso un numero intero positivo minore di 2N,
scriva la sua rappresentazione binaria su un vettore di lunghezza N anch’esso passato come argomento.
L’algoritmo per il calcolo della rappresentazione binaria è il seguente: si divide il numero in ingresso per 2 fino a che il
risultato non è 0. La rappresentazione binaria è data dai resti delle divisioni nell’ordine inverso in cui sono stati calcolati.
Quindi basta eseguire le divisioni finché non si arriva a 0 e memorizzare a ogni iterazione i resti della divisione intera in un
array partendo dall’ultima posizione.
*/

#include <iostream>

using namespace std;

const int N = 5;

int main()
{
		cout << "Inserisci il numero in base decimale\n";
		int num;
		cin >> num;

		int vett[N] = {};

        if (num < 0 || num > 2*N) return -1;
        int i=0;
        do{
            vett[N-1-i] = num%2;
            num/=2;
            i++;
        }while(num != 0);

		cout << "\nRappresentazione binaria: ";
		for (unsigned int i=0; i<N; ++i){
                cout << vett[i];
        }
        cout << endl;

}
