// Es_lezione: rect.cpp
/* obiettivo: fare pratica con le struct

	realizziamo 2 tipi di dato
		strutturato eterogeneo innestati

	- Point punti del piano cartesiano
	- Rect rettangolo sul piano cartesiano
	- inserimento valori
	- stampare
	- ragionare sulla "correttezza" dei valori
	- svolgere operazioni su variabili di tipo Pointe Rect:
        -- è un quadrato?
        -- è un rettangolo "alto" (altezza > larghezza)
        -- SE largo lo correggo per farlo diventare alto

*/


#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	double x;
	double y;
};

struct Rect {
	Point top_left;
	Point bottom_right;
};

const double TOLL = 0.000001;

int main()
{
	Rect R1;
	// Inserisco da tastiera i valori all'interno del rettangolo R1

	// Per essere sicuri di inserirli nel rettangolo in modo corretto, li inserisco prima in due variabili di tipo Point e verifico la proprietà geometrica
	Point P1, P2;
	cout << "Inserisci un rettangolo, prima il vertice in alto a sinistra, poi quello in basso a destra (usa sistema di riferimento (sdr) piano cartesiano)\n";
	cout << "Inserisci coordinate del primo punto x e y\n";
	cin >> P1.x >> P1.y;
	cout << "Inserisci coordinate del primo punto x e y\n";
	cin >> P2.x >> P2.y;

	// verifica geometrica (devo vedere se per errore l'utente inserisce come primo punto (top_left quello in basso a destra)
	if ((P1.x < P2.x) && (P1.y > P2.y)) // Punti corretti
	{
		R1.top_left = P1;
		R1.bottom_right = P2;
	}
	else cout << "Il rettangolo e' errato, dovremmo farci qualcosa\n";
	// else // Se la proprietà non è rispettata posso richiedere nuovamente i dati oppure scambiare i due punti (il programma corregge l'input errato)


	// Stampa
	cout << "\nRettangolo" << endl;
	cout << "Top left: (" << R1.top_left.x << "," << R1.top_left.y << ")\n";
	cout << "Bottom Right: (" << R1.bottom_right.x << "," << R1.bottom_right.y << ")\n";


	// Da qui in poi opero sempre su R1 e non sui punti Point
	// 1. E' un quadrato?
    double base, altezza;
    base = R1.bottom_right.x - R1.top_left.x;  //N.B. R1.bottom_right.x > R1.top_left.x (quadrante positivo), se un punto in x fosse nel quadrante negativo avrei comunque
												// una somma tale che prende il numero più a sinistra nel grafico come punto più alto.
	altezza = R1.top_left.y - R1.bottom_right.y;

	cout << "Base: " << base << endl;
	cout << "Altezza: " << altezza << endl;

	if (fabs(base-altezza) < TOLL)  // Verifico se sono uguali (tenendo conto delle approssimazioni)
		cout << "E' un quadrato\n";
	else
		if((altezza - base) > TOLL) 			// Scrivere (altezza > base) direttamente potrebbe avere conflitti se fossero uguali (me lo evita l'else)
			cout << "E' un rettangolo alto\n";
		else { // Ribalto il rettangolo, tenendo fermo il top_left e invertendo altezza e base, ovvero muovendo bottom_right.
			R1.bottom_right.x = R1.top_left.x + altezza;
			R1.bottom_right.y = R1.top_left.y - base; // Va verso il basso
		}

    	// Stampa
	cout << "\nRettangolo finale (alto)" << endl;
	cout << "Top left: (" << R1.top_left.x << "," << R1.top_left.y << ")\n";
	cout << "Bottom Right: (" << R1.bottom_right.x << "," << R1.bottom_right.y << ")\n";
}
