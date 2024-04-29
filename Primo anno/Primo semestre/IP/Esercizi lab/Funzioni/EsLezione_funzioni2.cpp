// EsLezione Funzioni 3

// Created by Kevin Cattaneo on 04/11/2020

// Es_1 di riscaldamento: Scrivere una funzione che prende come argomento un intero hm, legge hm numeri reali e ne restituisce la media.
// Scrivere un programma per testare la funzione try secondo il seguente algoritmo.


#include <iostream>

using namespace std;

// INTERFACCIA DELLA FUNZIONE
bool is_even(int);
int my_square(int);
int count_digits(int);


int main() // FUNZIONE CHIAMANTE
{
    int m;
	cout << "Inserisci un elemento di tipo int" << endl;
	cin >> m;

	// ESEMPI DI CHIAMATE D FUNZIONE
	bool b;
	b = is_even(m);		// Viene eseguita prima la parte destra e poi viene fatto un accesso in scrittura sulla variabile di sinistra.
	cout << boolalpha << b << endl;

	// Diverso da:
	cout << "Pari: " << boolalpha << is_even(m) << endl;	// Stesso risultato, ma così facendo non sto tenendo traccia del valore, dunque la chiamata non viene assegnata ad alcun valore in memoria

	cout << "Quadrato: " <<  my_square(m) << endl;   			// Stampo senza registrare il valore. Se successivamente mi servisse il quadrato di m, devo richiamare nuovamente la funzione

	cout << "Il quadrato e' pari: " << boolalpha << is_even(my_square(m)) << endl;

	cout << "Numero cifre: " << count_digits(m) << endl;
}


// DICHIARAZIONI

// Funzione booleana che verifica se un intero è pari
bool is_even(int n){
	return ((n%2) == 0);		// NON verifico con un if, bensì ritorno direttamente il valore dell'espressione booleana.
}

// Funzione che restituisce il quadrato dell'argomento
int my_square(int n){
	return (n*n);           // Non è necessario salvare il valore durante il processo
}

// Funzione che conta le cifre di un intero. Es 101 ha 3 cifre
// per il momento consideriamo interi senza segno
// Es. 1023		count = 0 	Divido per 10
// 102 			count = 1
// 10 			count = 2
// 1 			count = 3
// 0 			count = 4
int count_digits(int n){	// n è locale alla funzione, quando la funzione termina, termina anche la sua esistenza
	int count = 0;
	if (n==0)
		return 1; // Senza eseguire count = 1, restituisco il valore secondo la conoscenza (ovvero 0 ha una cifra)
	while (n > 0){	// Posso inserire un do while per gestire il valore in ingresso 0 (che è una cifra)
		count++;
		n /= 10;	// Divisione intera
	}
	return count;
}

