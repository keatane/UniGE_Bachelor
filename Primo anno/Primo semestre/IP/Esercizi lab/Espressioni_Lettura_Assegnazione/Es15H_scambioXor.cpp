// Es_Avanzato_n15: scrivi un programma che scambia fra loro i valori di due variabili senza usare variabili di appoggio

#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Inserisci due valori interi:\n";
	cin >> a >> b;
	
	cout << "Hai inserito: " << a << " e " << b << endl;
	
	// A^A == 0 e A^0 == A (l'unica parte vera fra A e 0 è A)
	
	/*	Stabilisco il valore di a = a^b;
	
		Stabilisco b:
		b = a^b
		b = (a^b)^b sostituisco il valore di a
		b = a^(b^b) applico proprietà associativa
		b = a^0 sapendo che b^b == 0
		b = a;
		
		Ritorno su a, ripetendo gli stessi passi di b:
		a = a^b
		a = a^(a^b)
		a = (a^a)^b
		a = 0^b
		a = b
		
		XOR mantiene in memoria il valore originale di a e b, quindi non c'è il rischio di perderli nello scambio
	
	*/		
	
	a = a^b;
	b = a^b;
	a = a^b;
	
	/* N.b. Posso anche effettuare la seguente:
	
	a = a+b;
	b = a-b;
	a = a-b
	*/ 
	
	cout << "Dopo lo scambio: " << a << " e " << b << endl;
}
