// Es_10 base:   Scrivere un programma che legge da input un numero interoTempe stampa:•  “Freddo dannato” seTempè compreso fra−20 e 0•  “Freddo” seTempè compreso fra 1 e 15•  “Normale” seTempè compreso fra 16 e 2314 •  “Caldo” seTempè compreso fra 24 e 30•  “Caldo da morire” seTempè compreso fra 31 e 40•  “Non ci credo, il termometro deve essere rotto” seTempè superiore a 40 o inferiore a−20

#include <iostream>

using namespace std;

int main()
{
	int Temp;
	cout << "Inserisci un numero intero" << endl;
	cin >> Temp;
	
	
	if (Temp <= -20)
		cout << "Non ci credo, il termometro deve essere rotto" << endl;
	else if ((Temp >= -20) && (Temp <= 0))
		cout << "Freddo dannato" << endl;
	else if ((Temp >= 1) && (Temp <= 15))
		cout << "Freddo" << endl;
	else if ((Temp >= 16) && (Temp <= 23))
		cout << "Normale" << endl;
	else if ((Temp >= 24) && (Temp <= 30))
		cout << "Caldo" << endl;
	else if ((Temp >= 31) && (Temp < 40))
		cout << "Caldo da morire" << endl;
	else if (Temp >= 40)
		cout << "Non ci credo, il termometro deve essere rotto" << endl;


}
