/* Es_19 avanzato: Scrivere una funzione con un argomento intero n che verifica se un numero intero positivo dato in input è un numero di
Armstrong e se sì restituisce true, altrimenti restituisce false.
Un intero positivo che si può rappresentare con n cifre (come minimo) si dice numero di Armstrong se è uguale alla somma
delle potenze n-esime delle cifre che lo compongono. Ad esempio 153 = 1
3 + 5
3 + 3
3 = 1 ∗ 1 ∗ 1 + 5 ∗ 5 ∗ 5 + 3 ∗ 3 ∗ 3 è un
numero di Armstrong, come pure 1634 = 1
4 + 6
4 + 3
4 + 4
4 = 1 + 1296 + 81 + 256.
*/

#include <iostream>

using namespace std;


void armstrong (int numero)
{
	int n = 0; // Numero cifre
	int ris = numero;

	while (ris != 0)
	{
		ris /= 10;
		n++;
	}

	cout << "Numero di cifre: " << n << endl;
	int k = 0, sum = 0;
	ris = numero;
	for (int i = 0; i < n; i++)
	{
		int sum_par = 1; // Somma parziale dei singoli numeri a potenza
		k = ris%10; // Osservo il resto della divisione intera
		for (int j = 0; j < n; j++)
			sum_par *= k;
		ris /= 10; // Salto alla cifra successiva da destra verso sinistra
		sum += sum_par; // Aggiungo i pezzetti alla somma complessiva
	}

	if (sum == numero) // Confronto finale fra somma e numero originale
		cout << numero << " e' un numero di Armstrong\n";
	else
		cout << numero << " non e' un numero di Armstrong\n";
}

int main()
{
	int num;
	cout << "Inserisci un numero" << endl;
	cin >> num;
	armstrong(num);
}
