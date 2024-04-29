// Es_17 avanzato: Scrivere un programma che verifica se un numero intero positivo dato in input è un numero di Armstrong, ovvero se è uguale alla somma delle potenze n-esime delle cifre che lo compongono.

#include <iostream>

using namespace std;

int main()
{
	int num;
	cout << "Inserisci un numero" << endl;
	cin >> num;
	
	int n = 0; // Numero cifre
	int ris = num;
	
	while (ris != 0)
	{
		ris /= 10;
		n++;
	}
	
	cout << "Numero di cifre: " << n << endl;
	int k = 0, sum = 0;
	ris = num;
	for (int i = 0; i < n; i++)
	{
		int sum_par = 1; // Somma parziale dei singoli numeri a potenza 
		k = ris%10; // Osservo il resto della divisione intera
		for (int j = 0; j < n; j++)
			sum_par *= k;
		ris /= 10; // Salto alla cifra successiva da destra verso sinistra
		sum += sum_par; // Aggiungo i pezzetti alla somma complessiva
	}
	
	if (sum == num) // Confronto finale fra somma e numero originale
		cout << num << " è un numero di Armstrong\n";
	else
		cout << num << " non è un numero di Armstrong\n";

}
