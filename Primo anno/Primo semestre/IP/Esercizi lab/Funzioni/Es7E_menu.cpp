// Es_7 di riscaldamento:   Scrivere un insieme di funzioni che, opportunamente composte, permettono di ottenere la gestione di un menu. Verificare il
// funzionamento di ogni funzione con opportuni programmi.
/*

1.Scrivere una funzione che presi come argomenti quattro stringhe, le stampa nell’ordine ricevuto, ciascuna su una nuova
riga e preceduta da un numero progressivo.

2.Scrivere una funzione che prende come argomenti un intero n, compreso fra uno e quattro, e quattro stringhe e che
stampa su una nuova riga il parametro stringa n-esimo preceduto dalla stringa "Scelta effettuata: ".

3.Scrivere una funzione con un argomento intero max che chiede all’utente di inserire una scelta compresa fra uno e max
finché l’utente non ne inserisce una accettabile e la restituisce.

4.Scrivere una funzione che, prese come argomenti quattro stringhe, le stampa nell’ordine ricevuto, ciascuna su una
nuova riga e preceduta da un numero progressivo, chiede all’utente un intero n compreso fra uno e quattro e stampa
su una nuova riga il parametro stringa n-esimo preceduto dalla stringa "Scelta effettuata: ":

5. Scrivere un programma, per testare le funzioni implementate, che propone all’utente un menu con quattro alternative, ne legge la scelta
e seleziona l’alternativa corrispondente finché non viene selezionata l’alternativa quattro. Il programma deve comportarsi come descritto nel seguente algoritmo.


*/

// Scrivere un programma per testare la funzione


#include <iostream>
#include <string>

using namespace std;

// PRIMO PASSO
void print_menu(string choice1, string choice2, string choice3, string choice4){
	// stampare `1' seguito da un carattere tab seguito da choice1
	cout << "1" << "	" << choice1;
	// stampare su una nuova riga `2' seguito da un tab seguito da choice2
	cout << "\n2" << "	" << choice2;
	// stampare su una nuova riga `3' seguito da un tab seguito da choice3
	cout << "\n3" << "	" << choice3;
	// stampare su una nuova riga `4' seguito da un tab seguito da choice4
	cout << "\n4" << "	" << choice4;
}

// SECONDO PASSO
void print_choice(int n, string ch1, string ch2, string ch3, string ch4){
	// Stampare un a capo seguito da "Scelta effettuata: "
	cout << "\nScelta effettuata: ";
	// Se il valore di n è 1
	// - stampare ch1
	// Se il valore di n è 2
	// - stampare ch2
	// Se il valore di n è 3
	// - stampare ch3
	// Se il valore di n è 4
	// - stampare ch4

	switch (n){
		case 1:
		cout << ch1;
		break;
		case 2:
		cout << ch2;
		break;
		case 3:
		cout << ch3;
		break;
		case 4:
		cout << ch4;
		break;
	}
	cout << endl;

}

// TERZO PASSO
int get_choice(int n){
	// Dichiarare una variabile a di tipo int
	int a;
	/* Ripetere
	- Stampare "Inserisci una scelta fra 1 e " seguito da n
	- Stampare un a capo
	- Leggere a
	finché a minore di uno o maggiore di n
	*/
	do{
		cout << "\nInserisci una scelta fra 1 e " << n;
		cout << endl;
		cin >> a;
	} while(a < 1 || a > n);

	// Restituire a
	return a;
}

// QUARTO PASSO
int use_menu(string choice1, string choice2, string choice3, string choice4){
	// Chiamare print_menu su choice1, choice2, choice3, choice4
	print_menu(choice1, choice2, choice3, choice4);
	// Dichiarare una variabile n di tipo int inizializzata con il risultato...
	// ... della chiamata di get_choice su 4
	int n = get_choice(4);
	// Chiamare print_choice su n, choice1, choice2, choice3, choice4
	print_choice(n, choice1, choice2, choice3, choice4);
	// Restituire n
	return n;
}


int main()
{
	/*
	// PRIMO PASSO
	// dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
	const string s1 = "Prima scelta";
	// dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
	const string s2 = "Seconda scelta";
	// dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
	const string s3 = "Terza scelta";
	// dichiarare una costante s4 di tipo string inizializzata con "Quarta scelta"
	const string s4 = "Quarta scelta";
	// chiamare print_menu su s1, s2, s3, s4
	print_menu(s1,s2,s3,s4);

	cout << endl;
	// SECONDO PASSO
	// chiamare print_choice su 1, s1, s2, s3, s4
	print_choice(1,s1,s2,s3,s4);
	// chiamare print_choice su 2, s1, s2, s3, s4
	print_choice(2,s1,s2,s3,s4);
	// chiamare print_choice su 3, s1, s2, s3, s4
	print_choice(3,s1,s2,s3,s4);
	// chiamare print_choice su 4, s1, s2, s3, s4
	print_choice(4,s1,s2,s3,s4);

	cout << endl;
	// TERZO PASSO
	// stampare il risultato della chiamata di get_choice su 7
	get_choice(7);

	cout << endl;
	// QUARTO PASSO
	// chiamare use_menu su s1, s2, s3, s4
	use_menu(s1, s2, s3, s4);
	*/

	//QUINTO PASSO
	// dichiarare una costante s1 di tipo string inizializzata con "Prima scelta"
	const string s1 = "Prima scelta";
	// dichiarare una costante s2 di tipo string inizializzata con "Seconda scelta"
	const string s2 = "Seconda scelta";
	// dichiarare una costante s3 di tipo string inizializzata con "Terza scelta"
	const string s3 = "Terza scelta";
	// dichiarare una costante s4 di tipo string inizializzata con "Basta!"
	const string s4 = "Basta!";
	/* ripetere
	- dichiarare una variabile intera answer inizializzata con...
	... use_menu su s1, s2, s3, s4
	finché answer è diverso da quattro
	*/
	int answer;
	do{
		answer = use_menu(s1, s2, s3, s4);
	} while(answer != 4);
}
