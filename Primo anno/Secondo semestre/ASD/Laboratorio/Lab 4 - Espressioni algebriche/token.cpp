/////////////////////////////////////////////////////////////////////
//
// Laboratorio 3: calcolo di semplici espressioni numeriche 
//                mediante pile e code
//
// Vengono accettati dall'esterno solo numeri positivi.
// Per trattare anche numeri negativi occorre modificare
// l'analizzatore lessicale.
//
///////////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

#include "token.h"

using std::cout;
using std::cin;
using std::string;
using std::istringstream;
using std::ostringstream;

/////////////////////////////////////////////////////////////////////
// Funzioni ausiliarie su tipi di dato semplici
/////////////////////////////////////////////////////////////////////

// da stringa a numero
int str2int(const string &s) {
	/*
 	istringstream itmp(s);
	itmp >> n;
	return n;
	*/
	return std::stoi(s);

}

// da numero a stringa
string int2str(int n) {
	/*
	string s;
	ostringstream otmp;
	otmp << n;
	s = otmp.str();
	return s;
	*/
	return std::to_string(n);
}

// ritorna false se e solo se token di tipo sconosciuto o se stringa vuota.
// se stringa non vuota, la stringa perde il pezzo iniziale,
// che diventa token.

bool prossimoToken(string &s, token &t) {
	t.val = "";
	t.k = VUOTO;
	if(s.empty())
		return false;
	//stringa ausiliaria dove salvare val token
	string aux = "";
	unsigned int i;
	for(i=0; i<s.size(); i++)
	{
		if(s[i] != ' '){ //se diverso da spazio
			aux.append(1, s[i]); //aggiungo a aux
			}
		else
			break;
	}

	s.erase(0, i+1); // nel caso in cui i+1 supera s.size() vengono cancellati tutti i caratteri (situazione regolare!)
		
	//QUI abbiamo il val del token in aux
	t.val = aux;
	
	// Controllo del kind del token
	if(isNumeric(aux))
		t.k = NUMERO;
	else if(aux=="(")
		t.k = PARENTESI_APERTA;
	else if(aux==")")
		t.k = PARENTESI_CHIUSA;
	else if(aux=="+")
		t.k = OP_SOMMA;
	else if(aux=="-")
		t.k = OP_SOTTRAZIONE;
	else if(aux=="*")
		t.k = OP_MOLTIPLICAZIONE;
	else //se entra in questo else, vuol dire che il token è sconosciuto
	{
		t.k = SCONOSCIUTO;
		return false;
	}
	return true;
}

bool isNumeric(string &s)
{
	bool neg = false;
	if(s[0] == '-' && s.size()>1){ // in modo tale da non prendere il caso di OP_SOTTRAZIONE
						// in caso di -- o altri simboli dopo -, non passa il controllo digit nè altri
		neg = true;
		s.erase(0,1); // tolgo il -, isolo il valore assoluto
	}

	for(int i=0; i<s.size(); i++)
		if(!isdigit(s[i])){
		if (neg) s.insert(0,"-"); // Re-inserisco il -, onde evitare che venga letto lecito il simbolo rimasto (poichè passo string per riferimento, -* rimarrebbe *, valore lecito in prossimoToken()
		return false;
	}
	
	// Giunti qui è un numero
	if(neg)
		s.insert(0,"-"); // inserisco il - al valore assoluto di un numero negativo
		
	// === Debug - stampa numero ===
	//std::cout << "Numero " <<  s << std::endl;
	
	return true;
	
	//Alternativa: confrontare direttamente i valori ASCII di ogni carattere e controllare se sono in [0-9]
}

