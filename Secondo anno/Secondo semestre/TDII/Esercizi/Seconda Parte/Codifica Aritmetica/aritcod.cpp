//*** Cattaneo Kevin - (S4944382) - Codifica aritmetica - TDII ***// 
#include <iostream>
#include <string>
#include <vector>
#include <math.h> // per log2

int DIM; // dimensione stringa
int n0, n1; // frequenze bit, rispettivamente 0 e 1

// Funzione di codifica
// Codifica il k-esimo bit bk per k = 1, . . . , N con la
// probabilita` pk(0) per bk = 0 e pk(1) = 1 − pk(0) per bk = 1
long double coding(const std::string& stringa, std::vector<double>& pk, long double& ampiezza){

	// Calcolo le frequenze empiriche per 0 e 1
	n0 = n1 = 0;
	for(int i=0; i<DIM; ++i){
		if(stringa[i] == '0')
			n0++;
		else if(stringa[i] == '1')
			n1++;
		else throw std::string("ERRORE: la stringa non è in formato binario\n");
	}
	
	// Calcolo delle probabilità per singoli bit
	long double ak = .0, bk = 1.; // estremi dell'intervallo
	for(int k=0; k<DIM; ++k){
		//Invece di b-a, evito cancellazioni
		ampiezza *= ((stringa[k] == '0') ? pk[k] : 1-pk[k]);	
		
		// Note:
		// (*) Giungo sino a k = DIM, ma il valore calcolato per tale k...
		// ...non è importante ai fini della codifica...
		// ...(non avendo ulteriori bit da codificare, non mi serve una nuova p)
		// (*) [Per motivi di implementazione pk ha dimensione DIM+1]
		// (*) stringa-48 per trasformare da char a valore intero
		// (*) k+3 perchè nella formula k parte da 1
		pk[k+1] = pk[k] + (1-(stringa[k]-48) - pk[k])/(k+3); 
		
		// Di seguito viene applicata la formula per aggiornare gli estremi...
		// ...dell'intervallo. La cdf è applicata su due valori, quindi ho solo due...
		// ...valori di probabilità, che si accumulano bit per bit
		ak += (bk-ak)*((stringa[k]-48) ? pk[k] : 0. ); // (1 - stringa[k]) implicito
		bk = ak + (bk-ak)*((stringa[k]-48) ? 1. : pk[k]);	
	}
	
	// Cerco la potenza di 2 interna all'intervallo, utilizzando il metodo di bisezione
	long double mid = .5;
	long double max = 1.;
	long double min = .0;
	
	while (mid < ak || mid >= bk){
		if (mid <= ak) min = mid;
		else if (mid > bk) max = mid;
		mid = (max + min) / 2.;
	}
	return mid; 
}


// Funzione di decodifica
std::string decoding(long double theta, std::vector<double>& pk){
	std::string xk = "";
	for(int k=0; k<DIM; ++k){	
		char x = (theta < pk[k] ? '0' : '1');
		xk += x;
		theta = (theta - ((x-48) ? pk[k] : 0.))/((x-48) ? 1-pk[k] : pk[k]);
	}
	return xk; 
}

int main(){
	
	/***(De)Commentare le seguenti stringhe di esempio (una per volta) ***/
	//std::string stringa = "10";
	//std::string stringa = "1011";
	//std::string stringa = "1100";
	std::string stringa = "10110100110010100101011010010101010";
	//std::string stringa = "1010010101010010101010010101010001001010101";
	//std::string stringa = "000000000000000000000000000000000000000000";
	//std::string stringa = "11111111111111111111111111111111111111111111";
	//std::string stringa = "101010101001010a00101010"; // ci si aspetta un errore
	//std::string stringa = "abc"; // ci si aspetta un errore
	/** Limite superiore: 61 caratteri decodificati correttamente, stringa seguente **/
	//std::string stringa = "1011010001001011011011010101001010110101110101001010101110110";

	std::string decoded;
	long double ampiezza = 1.0;
	long double middle;
	DIM = stringa.length(); 

	// Array di probabilità  di 0 di k bit (1 è 1-p)
	// [Per motivi di implementazione pk ha dimensione DIM+1]
	std::vector<double> pk(DIM+1); 
	pk[0] = 0.5; // primo bit ha equiprobabilità di 0 e 1
	
	try{
		middle = coding(stringa, pk, ampiezza);
	}
	catch(std::string e){
		std::cout << e;
		return -1;
	}
	decoded = decoding(middle, pk);

	std::cout << "Dimensione stringa:\t" << DIM << std::endl;
	std::cout << "Origin:\t\t" << stringa << std::endl;;
	std::cout << "Decoded:\t" << decoded << std::endl;;
	std::cout << "Ampiezza intervallo:\t\t" << ampiezza << std::endl;
	std::cout << "Valore medio intervallo:\t" << middle << std::endl;
	
	// Entropia
	double H = ((n0 != 0 ? ((double)n0/DIM)*log2((double)DIM/n0) : 0) + (n1 != 0 ? ((double)n1/DIM)*log2((double)DIM/n1) : 0));

	// Calcolo log(1/A)/N
	// DIM+2 perchè la probabilità inziale è di 0.5, quindi è come aver ricevuto...
	// ...uno zero e un uno per stabilirla
	double logConfr = (log2(1/ampiezza))/(DIM+2); 
	
	std::cout << "Entropia:\t" << H << std::endl;
	std::cout << "log(1/A)/N :\t" << logConfr << std::endl;
	
	std::cout << "\nDecodifica(Codifica) == " << stringa << "? " << std::boolalpha << (decoded == stringa) << std::endl;
	
	return 0; 
}
