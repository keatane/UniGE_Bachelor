/* Es_13 di base: Scrivere un programma che chiede all’utente di scegliere il suo colore preferito presentandogli un menu con almeno 5 scelte
di colori i cui nomi iniziano con una lettera diversa (ad esempio rosso, verde, blu, giallo e arancio). Per selezionare la
scelta l’utente potrà usare l’iniziale del colore scelto, indifferentemente in maiuscolo o minuscolo. Se il carattere inserito
non corrisponde a nessun colore proposto il programma ricomincerà da capo presentando il menu con le scelte.
*/

#include <iostream>

using namespace std;

int main ()
{
	char scelta;
	do{
	cout << "Scegli il tuo colore preferito dal menu seguente: " << endl;
	cout << "[R]osso\n[V]erde\n[B]lu\n[G]iallo\n[M]agenta\n";
	cin >> scelta;
	} while (scelta != 'R' && scelta != 'r' && scelta != 'V' && scelta != 'v' && scelta != 'B' && scelta != 'b' && scelta != 'G' && scelta != 'g' && scelta != 'M' && scelta != 'm');
	cout << "End\n";
}
