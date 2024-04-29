/*Es_9 di base: Scrivere un programma che, usando l’algoritmo “crivello di Eratostene”, trova i numeri primi minori di 1000.

CRIVELLO DI ERATOSTENE (n)
1) Creare un array di bool chiamato isprime di lunghezza n,
inizializzandolo a tutti valori true.
Al termine dell'algoritmo, l'elemento i-esimo di isprime varra' true
se i e' primo, false altrimenti
2) Inizialmente, sia p pari a 2, il numero primo più piccolo.
3) Partendo da p escluso, marcare come NON PRIMI tutti i numeri multipli di p (2p, 3p, 4p...).
Ovvero impostare a false ogni elemento isprime[2*p], isprime[3*p]...
4) Partire da p=p+1 e scorrere in avanti l'array isprime finché non si trova il primo numero
NON marcato (isprime[p] è true), oppure finché non è finita la lista
5) Se la lista è finita, stop. Altrimenti p diventa pari al numero trovato
e si ricomincia (la prima volta sarà 3)
All'uscita dell'algoritmo, tutti i numeri non marcati (tali che il corrispondente elemento
di isprime vale ancora true) sono tutti i numeri primi <= n

Stampare tutti i numeri tali che il corrispondente elemento di isprime e’ true.
[SUGGERIMENTO: Come visto a lezione, bisogna fare diversi cicli for:
(a) Un ciclo su tutti gli elementi di isprime, per impostarli a true
(b) Un ciclo sugli elementi di isprime, per cercare il primo elemento true
(c) ALL’INTERNO DEL CICLO PRECEDENTE, un ciclo su tutti i multipli di p per marcarli false
(d) Un ciclo finale per stampare gli elementi true
Ricordate il criterio per scegliere tra for, while e do ... while (ripassare parte sui cicli). ]


*/



#include <iostream>

using namespace std;

const unsigned int N = 1000;

int main()
{
	// INIZIALIZZAZIONE (punto 1 e 2)
    bool isprime[N];

	for (unsigned int i = 0; i < N; ++i)
		isprime[i] = true;

	// CALCOLO (punto 3 e 4)
	int p = 2;

	do{
		for (int i=2; i<=N/p; ++i)
			isprime[i*p] = false;
		for (int i = p +1; ; ++i) // Il for cicla finchè non viene eseguito il break (no condizione di limite superiore)
			if (isprime[i]){
				p = i;
				break;
			}
	}while(p < N / 2);


	//OUTPUT
	for (unsigned int i = 2; i < N; ++i)
		if(isprime[i])
			cout << i << " e' un numero primo" << endl;
	cout << endl;
}



