/*  Definire una struct Triangle per rappresentare triangoli sul piano cartesiano con coordinate intere. Triangle includerà
dunque tre campi che rappresentano altrettanti punti. Triangle avrà inoltre due ulteriori campi per memorizzare area e
perimetro del triangolo.
[SUGGERIMENTO: Per memorizzare i vertici del triangolo, potete usare una variante della struct Point del punto 1.]
A • Scrivere un programma che legge le coordinate dei 3 vertici di un triangolo e le memorizza in una struct di tipo Triangle.
Calcola poi area e perimetro del triangolo e memorizza le informazioni nei corrispondenti campi della struct. Infine
verifica se il triangolo è o no un triangolo rettangolo e stampa un messaggio di output opportuno.
B • Scrivere un programma che legge e calcola le informazioni relative a 3 triangoli, memorizzate in altrettante variabili di
tipo Triangle. Verificare poi quale dei tre triangoli abbia area maggiore e stampare un opportuno messaggio di output.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double TOLL = 0.0000001;

struct Point {

	int x;
	int y;
};

struct Triangle {

	Point v1;
	Point v2;
	Point v3;
	double area;
	double perimetro;
	double lato1;
	double lato2;
	double lato3;

};


struct StraightLine {
double m; // coefficiente angolare
double q; // quota
};

int main()
{
    //Parte A
	Triangle triangolo1;

	cout << "Inserire le coordinate del primo vertice (x,y):" << endl;
	cin >> triangolo1.v1.x >> triangolo1.v1.y;
	cout << "Inserire le coordinate del secondo vertice (x,y):" << endl;
	cin >> triangolo1.v2.x >> triangolo1.v2.y;
	cout << "Inserire le coordinate del terzo vertice (x,y):" << endl;
	cin >> triangolo1.v3.x >> triangolo1.v3.y;

	triangolo1.lato1 = sqrt(pow(triangolo1.v1.x - triangolo1.v2.x, 2) + pow(triangolo1.v1.y - triangolo1.v2.y, 2));
	triangolo1.lato2 = sqrt(pow(triangolo1.v2.x - triangolo1.v3.x, 2) + pow(triangolo1.v2.y - triangolo1.v3.y, 2));
	triangolo1.lato3 = sqrt(pow(triangolo1.v1.x - triangolo1.v3.x, 2) + pow(triangolo1.v1.y - triangolo1.v3.y, 2));
	// Controllo: cout << triangolo1.lato1 << " " << triangolo1.lato2 << " " << triangolo1.lato3 << endl;

	triangolo1.perimetro = triangolo1.lato1+triangolo1.lato2+triangolo1.lato3;
	int p = triangolo1.perimetro / 2; // Semiperimetro
	triangolo1.area = sqrt(p*(p-triangolo1.lato1)*(p-triangolo1.lato2)*(p-triangolo1.lato3)); // Area secondo la formula di Erone

	// Ricerco in ordine crescente quali sono i valori
	double lato[3];
	lato[0] = triangolo1.lato1;
	lato[1] = triangolo1.lato2;
	lato[2] = triangolo1.lato3;

	// Controllo: cout << lato[0] << " " << lato[1] << " " << lato[2] << endl;
	double temp = 0;
	for (unsigned int i=0; i<3; ++i)
		for	(unsigned int j=0; j<3-1-i; ++j)
			if (lato[j] > lato[j+1])
			{
				temp = lato[j];
				lato[j] = lato[j+1];
				lato[j+1] = temp;
			}
	// Alla fine lato[2] sarà il lato maggiore
	//Controllo: cout << lato[0] << " " << lato[1] << " " << lato[2] << endl;

	// Per verificare se triangolo rettangolo osservo se la somma dei quadrati dei lati più corti è uguale al quadrato del lato maggiore (differenza minore di una tolleranza);
	if ((lato[0]*lato[0]+lato[1]*lato[1]) - lato[2]*lato[2] < TOLL)
		cout << "Triangolo rettangolo" << endl;
	else
		cout << "Triangolo non rettangolo" << endl;



    // Parte B (alternativa non efficiente: potrei usare un array)
    Triangle triangolo2, triangolo3;

	cout << "\nSecondo triangolo" << endl;
	cout << "Inserire le coordinate del primo vertice (x,y):" << endl;
	cin >> triangolo2.v1.x >> triangolo2.v1.y;
	cout << "Inserire le coordinate del secondo vertice (x,y):" << endl;
	cin >> triangolo2.v2.x >> triangolo2.v2.y;
	cout << "Inserire le coordinate del terzo vertice (x,y):" << endl;
	cin >> triangolo2.v3.x >> triangolo2.v3.y;


	cout << "\nTerzo triangolo" << endl;
	cout << "Inserire le coordinate del primo vertice (x,y):" << endl;
	cin >> triangolo3.v1.x >> triangolo3.v1.y;
	cout << "Inserire le coordinate del secondo vertice (x,y):" << endl;
	cin >> triangolo3.v2.x >> triangolo3.v2.y;
	cout << "Inserire le coordinate del terzo vertice (x,y):" << endl;
	cin >> triangolo3.v3.x >> triangolo3.v3.y;


	// Triangolo 2
	triangolo2.lato1 = sqrt(pow(triangolo2.v1.x - triangolo2.v2.x, 2) + pow(triangolo2.v1.y - triangolo2.v2.y, 2));
	triangolo2.lato2 = sqrt(pow(triangolo2.v2.x - triangolo2.v3.x, 2) + pow(triangolo2.v2.y - triangolo2.v3.y, 2));
	triangolo2.lato3 = sqrt(pow(triangolo2.v1.x - triangolo2.v3.x, 2) + pow(triangolo2.v1.y - triangolo2.v3.y, 2));

	triangolo2.perimetro = triangolo2.lato1+triangolo2.lato2+triangolo2.lato3;
	p = triangolo2.perimetro / 2; // Semiperimetro
	triangolo2.area = sqrt(p*(p-triangolo2.lato1)*(p-triangolo2.lato2)*(p-triangolo2.lato3));

	// Ricerco in ordine crescente quali sono i valori
    // Posso riutilizzare le stesse variabili (l'area, ciò che mi interessa, è registrata in una variabile apposita)
	lato[0] = triangolo2.lato1;
	lato[1] = triangolo2.lato2;
	lato[2] = triangolo2.lato3;

	for (unsigned int i=0; i<3; ++i)
		for	(unsigned int j=0; j<3-1-i; ++j)
			if (lato[j] > lato[j+1])
			{
				temp = lato[j];
				lato[j] = lato[j+1];
				lato[j+1] = temp;
			}
	// Alla fine lato[2] sarà il lato maggiore


	// Triangolo 3
	triangolo3.lato1 = sqrt(pow(triangolo3.v1.x - triangolo3.v2.x, 2) + pow(triangolo3.v1.y - triangolo3.v2.y, 2));
	triangolo3.lato2 = sqrt(pow(triangolo3.v2.x - triangolo3.v3.x, 2) + pow(triangolo3.v2.y - triangolo3.v3.y, 2));
	triangolo3.lato3 = sqrt(pow(triangolo3.v1.x - triangolo3.v3.x, 2) + pow(triangolo3.v1.y - triangolo3.v3.y, 2));

	triangolo3.perimetro = triangolo3.lato1+triangolo3.lato2+triangolo3.lato3;
	p = triangolo3.perimetro / 2; // Semiperimetro
	triangolo3.area = sqrt(p*(p-triangolo3.lato1)*(p-triangolo3.lato2)*(p-triangolo3.lato3));

	// Ricerco in ordine crescente quali sono i valori
	// Posso riutilizzare le stesse variabili (l'area, ciò che mi interessa, è registrata in una variabile apposita)
	lato[0] = triangolo3.lato1;
	lato[1] = triangolo3.lato2;
	lato[2] = triangolo3.lato3;

	for (unsigned int i=0; i<3; ++i)
		for	(unsigned int j=0; j<3-1-i; ++j)
			if (lato[j] > lato[j+1])
			{
				temp = lato[j];
				lato[j] = lato[j+1];
				lato[j+1] = temp;
			}
	// Alla fine lato[2] sarà il lato maggiore

	//Controllo le aree:
	double area[3];
	area[0] = triangolo1.area;
	area[1] = triangolo2.area;
	area[2] = triangolo3.area;

	for (unsigned int i=0; i<3; ++i)
		for	(unsigned int j=0; j<3-1-i; ++j)
			if (area[j] > area[j+1])
			{
				temp = area[j];
				area[j] = area[j+1];
				area[j+1] = temp;
			}
	// Ho area max in area[2]

	if (area[2] == triangolo1.area)
		cout << "Il triangolo con area maggiore e' il primo\n";
	else if (area[2] == triangolo2.area)
		cout << "Il triangolo con area maggiore e' il secondo\n";
	else
		cout << "Il triangolo con area maggiore e' il terzo\n";
}
