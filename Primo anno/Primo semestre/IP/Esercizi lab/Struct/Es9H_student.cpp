/* Es_9 avanzato: Definire un tipo struct Student per mantenere informazioni riguardanti uno studente, ed in particolare matricola, nome,
cognome, data di nascita, voto medio.
[SUGGERIMENTO: Usate delle stringhe (tipo std::string) per rappresentare nome e cognome.]
Scrivere un programma che legga le informazioni relative ad almeno N studenti con N > 2, e le stampi in ordine decrescente
di età.
[SUGGERIMENTO: Usate array di struct.]

*/


#include <iostream>
#include <cmath>

using namespace std;

struct Date{
	unsigned int giorno;
	unsigned int mese;
	unsigned int anno;
};

struct Student{
	 int matricola;
	 Date data_nascita;
	 int voto_medio;
	 string nome;
	 string cognome;
};

const unsigned int DIM = 3;

int main()
{
	Student studenti[DIM];
	for (unsigned int i=0; i < DIM; ++i)
	{
		cout << "Studente n." << i+1 << endl;
		cout << "Inserire numero matricola\n";
		cin >> studenti[i].matricola;			// Accedo ai campi (membri) degli elementi struct all'interno dell'array.

		cout << "Inserire cognome studente\n";
		cin >> studenti[i].cognome;

		cout << "Inserire nome studente\n";
		cin >> studenti[i].nome;

		cout << "Inserire anno di nascita studente\n";
		cin >> studenti[i].data_nascita.anno;
		cout << "Inserire mese di nascita studente\n";
		cin >> studenti[i].data_nascita.mese;
		cout << "Inserire giorno di nascita studente\n";
		cin >> studenti[i].data_nascita.giorno;

		cout << "Inserire il voto medio dello studente\n";
		cin >> studenti[i].voto_medio;
		cout << endl;
	}

	// Controllo le eta' degli studenti
	unsigned int mini, smallest;
	Student temp;
	for (unsigned int i=0; i<DIM;  ++i){
		smallest = i;
		for (mini = i+1; mini < DIM; ++mini){		// min (i)
				if (studenti[smallest].data_nascita.anno > studenti[mini].data_nascita.anno)    //N.B. Più un anno è piccolo, più è vecchio lo studente
					smallest = mini;			// Controllo dei valori, cerco il minimo valore (e ne registro l'indice)

                else if (studenti[smallest].data_nascita.anno == studenti[mini].data_nascita.anno)
                {
                        smallest = i;
                        for (mini = i+1; mini < DIM; ++mini){		// min (i)
                                if (studenti[smallest].data_nascita.mese > studenti[mini].data_nascita.mese) //N.B. Più un mese è piccolo, più è vecchio lo studente
                                    smallest = mini;

                                else if (studenti[smallest].data_nascita.mese == studenti[mini].data_nascita.mese)
                                {
                                        smallest = i;
                                        for (mini = i+1; mini < DIM; ++mini)		// min (i)
                                                if (studenti[smallest].data_nascita.giorno > studenti[mini].data_nascita.giorno) //N.B. Più un giorno è piccolo, più è vecchio lo studente
                                                    smallest = mini;

                                }
                            }
                }
        }

		temp = studenti[i]; // Scambio gli studenti // Posso scambiare direttamente persone "intere", con tutti i loro attributi, senza scambiarli uno ad uno.
		studenti[i] = studenti[smallest];
		studenti[smallest] = temp;

	}

	/* Alternativa solo anno
	Student temp;
	for (unsigned int i=0; i < DIM; ++i)
		for (unsigned int j=0; j < DIM-1-i; ++j)
			if (studenti[j].data_nascita < studenti[j+1].data_nascita)
			{
					temp = studenti[j]; // Posso scambiare direttamente persone "intere", con tutti i loro attributi, senza scambiarli uno ad uno.
					studenti[j] = studenti[j+1];
					studenti[j+1] = temp;
			}

	cout << "Lista studenti in ordine decrescente di eta'" << endl;
	for (unsigned int i=0; i < DIM; ++i)
		cout << "Studente n." << i+1 << ": " << studenti[i].cognome << "  " << studenti[i].nome << endl;
	*/


	cout << "Lista studenti in ordine decrescente di eta'" << endl;
	for (unsigned int i=0; i < DIM; ++i)
		cout << "Studente n." << i+1 << ": " << studenti[i].cognome << "  " << studenti[i].nome << "  " << studenti[i].data_nascita.anno << "  " << studenti[i].data_nascita.mese << "  " << studenti[i].data_nascita.giorno << endl;
}
