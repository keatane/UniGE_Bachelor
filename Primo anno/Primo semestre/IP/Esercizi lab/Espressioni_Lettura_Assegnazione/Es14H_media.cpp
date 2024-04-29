#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci due numeri:\n";
	float a, b;
	cin >> a >> b;
	
	float media;
	media = (a+b)/2;
	float semidistanza;
	semidistanza = abs(media-a); //Valore assoluto (rendo positivo nel caso sottraggo il numero maggiore)
	// Posso anche calcolare la metà della distanza: (a-b)/2
	
	float val_minore, val_maggiore;
	val_minore = media-semidistanza;
	val_maggiore = media+semidistanza;
	
	cout << "In ordine crescente: " << endl;
	cout << val_minore << ", " << val_maggiore << endl;
}
