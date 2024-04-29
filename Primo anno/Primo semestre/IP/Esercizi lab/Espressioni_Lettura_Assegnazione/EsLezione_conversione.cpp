/* Programma che fa una conversione fra altezza di persone in cm (come facciamo in Italia) e rappresentazione in piedi (misura anglosassone)

Passi da seguire:

1. INPUT Acquisire informazione da tastiera
	"Inserisci altezza in cm"
	
2. CALCOLO (conversione)

3. OUTPUT Stampo l'altezza in piedi


Creato da Kevin Cattaneo il 05/10/2020.
*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Inserisci altezza in cm (numero intero)" << endl;
	int h_cm; // Intero a meno che non mi serva una precisione maggiore (es. 173.2 cm)
	cin >> h_cm;
	
	const float CM2FOOT = 0.0328; // Tasso di conversione
	
	float h_foot;
	h_foot = h_cm * CM2FOOT;
	
	cout << "L'altezza in piedi è " << h_foot << endl;
	
	// Posso anche stampare un risultato in linguaggio più naturale
	// Dividendo in due parti il risultato
	
	int i, j;
	
	i = static_cast<int>(h_foot); // Parte intera della misura
	j = static_cast<int>((h_foot - i + 0.05)*10); // Si lavora sulla seconda parte (decimale) della misura
	// +0.05 mi permette di arrotondare (se il numero è >= .05 automaticamente diventa 0.1)
	
	// j = static_cast<int>((h_foot - i + 0.05)*10); parte decimale in pollici
	
	cout << "L'altezza è " << i << " piedi e " << j << endl;
	

}
