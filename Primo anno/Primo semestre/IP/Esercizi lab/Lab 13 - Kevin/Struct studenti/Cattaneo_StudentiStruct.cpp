#include <iostream>
#include <string>

using namespace std;


struct Student{
	 string nome;
	 string cognome;
};

const unsigned int DIM = 3;

int main()
{
	// INPUT
	// Accedo ai campi (membri) degli elementi struct all'interno dell'array.
	Student studenti[DIM];
	for (unsigned int i=0; i < DIM; ++i)
	{
		cout << "Inserire cognome studente (prima lettera Maiuscola) \n";
		getline(studenti[i].cognome);

		cout << "Inserire nome studente (prima lettera Maiuscola) \n";
		getline(studenti[i].nome);
		getline(studenti[i].cognome);
	}

	// Ordinamento degli studenti: l'ordine alfabetico corrisponde a un ordine crescente.
	unsigned int mini, smallest;
	Student temp;
	for (unsigned int i=0; i<DIM;  ++i){
		smallest = i;
		for (mini = i+1; mini < DIM; ++mini){
				if (studenti[smallest].cognome > studenti[mini].cognome)
					smallest = mini;			// Controllo dei valori, controllo la lettera che viene prima nell'alfabeto (valore più piccolo) e ne registro l'indice

                else if (studenti[smallest].cognome == studenti[mini].cognome) // Se i cognomi degli studenti sono uguali
                {
                        smallest = i;
                        for (mini = i+1; mini < DIM; ++mini){
                                if (studenti[smallest].nome > studenti[mini].nome)
                                    smallest = mini;
                            }
                }
        }

		temp = studenti[i]; // Scambio gli studenti // Posso scambiare direttamente persone "intere", con tutti i loro attributi, senza scambiarli uno ad uno.
		studenti[i] = studenti[smallest];
		studenti[smallest] = temp;

	}

    // OUTPUT
	cout << "Lista studenti in ordine alfabetico" << endl;
	for (unsigned int i=0; i < DIM; ++i)
		cout << "Studente n." << i+1 << ": " << studenti[i].cognome << "  " << studenti[i].nome << endl;
}
