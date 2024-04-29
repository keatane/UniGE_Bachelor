/* Es_8 avanzato: Definire un tipo struct Complex che rappresenta un numero complesso in due forme:
(a) come parte reale e parte immaginaria (forma cartesiana);
(b) come modulo e fase (forma esponenziale),
tutte variabili-membro di tipo double.
Scrivere un programma che legge due numeri complessi e ne calcola:
• Somma
• Differenza
• Prodotto
• Rapporto
Ogni operazione deve mantenere consistenti, allineate fra loro, le due rappresentazioni, ovvero le coppie (re, im) e (modulo,
fase) di un dato numero complesso devono sempre rappresentare lo stesso numero.
Stampare i risultati delle operazioni nelle due forme, cartesiana ed esponenziale.
*/

#include <iostream>
#include <cmath>

using namespace std;


struct Complex{
	 double Re;
	 double Im;
	 double modulo;
	 double arg;
};

const unsigned int PI = 3.14159;

int main()
{
	Complex n1, n2;
	cout << "Inserisci il primo numero complesso in forma cartesiana" << endl;
	cout << "Inserisci la parte reale:" << endl;
	cin >> n1.Re;
	cout << "Inserisci la parte immaginaria:" << endl;
	cin >> n1.Im;
	cout << endl;
	cout << "Inserisci il secondo numero complesso in forma cartesiana" << endl;
	cout << "Inserisci la parte reale:" << endl;
	cin >> n2.Re;
	cout << "Inserisci la parte immaginaria:" << endl;
	cin >> n2.Im;

	cout << "Numeri in forma cartesiana: " << endl;
	cout << n1.Re << " + " << n1.Im << "*i" << endl;
	cout << n2.Re << " + " << n2.Im << "*i" << endl;

	n1.modulo = sqrt(pow(n1.Re, 2)+pow(n1.Im, 2));
	n2.modulo = sqrt(pow(n2.Re, 2)+pow(n2.Im, 2));
	n1.arg = atan(n1.Im / n1.Re);   // Risultati già in radianti (ovvero uguali a Pigreco / n)
	n2.arg = atan(n2.Im / n2.Re);

	cout << "Numeri in forma esponenziale: " << endl;
	cout << n1.modulo << " + e^(i*" << n1.arg << ")" << endl;
	cout << n2.modulo << " + e^(i*" << n2.arg << ")" << endl;

	double sommaR, sommaI, diffR, diffI, prodottoR, prodottoI, rapportoR, rapportoI;
	// Forma cartesiana
	cout << "\nForma cartesiana" << endl;
	sommaR = n1.Re + n2.Re;
	sommaI = n1.Im + n2.Im;
	cout << "Somma: " << sommaR << " + " << sommaI << "*i" << endl;

	diffR = n1.Re - n2.Re;
	diffI = n1.Im - n2.Im;
	cout << "Differenza: " << sommaR << " + " << sommaI << "*i" << endl;

	diffR = n1.Re - n2.Re;
	diffI = n1.Im - n2.Im;
	cout << "Differenza: " << sommaR << " + " << sommaI << "*i" << endl;

	prodottoR = n1.Re * n2.Re - n1.Im * n2.Im; // Il meno è dettato da i^2
	prodottoI = n1.Re * n2.Im + n1.Im * n2.Re;
	cout << "Prodotto: " << prodottoR << " + " << prodottoR << "*i" << endl;

	double tempR, tempI;
	tempR = n2.Re / n2.modulo;
	tempI = n2.Im / n2.modulo; // Spezzo il denominatore

	rapportoR = n1.Re * tempR + n1.Im * tempI; // Il meno è dettato da i^2
	rapportoI = n1.Im * tempR - n1.Re * tempI;

	// Forma esponenziale
	// Riutilizzo le variabili
	cout << "\nForma esponenziale" << endl;
    double somma;
	somma = n1.modulo + n2.modulo;
	cout << "Somma: " << somma << " + e^(i*" << n1.arg << " + e^(i*" << n2.arg << ")" << endl;

	double diff;
	diff = n1.modulo - n2.modulo;
	cout << "Differenza: " <<  diff << " + e^(i*" << n1.arg << " - e^(i*" << n2.arg << ")" << endl;

    double temp;
	temp = n1.modulo * n2.modulo;
	double prodotto;
	cout << "Prodotto: " << temp << " + e^(" << n1.arg + n2.arg << ")" << endl;

	temp = n1.modulo / n2.modulo;
	double rapporto;
	cout << "Rapporto: " << temp << " + e^(" << n1.arg - n2.arg << ")" << endl;


}
