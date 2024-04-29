/*
Scrivere una funzione replicate2_line con parametri f e s di tipo intero e f_c e s_c di tipo carattere, che stampa su una
nuova riga f volte f_c seguito da s volte s_c. Ad esempio replicate2_line(3, 7, 's', 'q') stampa:
sssqqqqqqq
*/

#include <iostream>

using namespace std;

void replicate2_line(int f, int s, char f_c, char s_c){

	for (unsigned int i=0; i<f; ++i)
		cout << f_c;
	for (unsigned int i=0; i<s; ++i)
		cout << s_c;
}



int main()
{
	replicate2_line(5, 5, 'a', 'b');
}
