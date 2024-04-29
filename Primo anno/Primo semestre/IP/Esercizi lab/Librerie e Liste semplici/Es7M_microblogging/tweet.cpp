#include "tweet.h"
#include <iostream>

// prende in input alcuni dati
Tweet tweetread(){
	Tweet t;
	std::cout << "Inserisci testo (una parola sola):\n";
	std::cin >> t.text;	// singola parola
	
	std::cout << "Inserisci gli hashtags (separati da spazi, iniziano per #,\n";
	std::cout << "per finire scrivi qualunque altra cosa\n";
	std::string input = "";
	std::cin >> input;
	/*while(input.find('#') != std::string::npos){ //questa versione cerca # in tutta la parola
		t.hashtags.push_back(input);
		std::cin >> input;
	}*/
	while (input[0]=='#'){ // le stringhe sono array di char
		t.hashtags.push_back(input);
		std::cin >> input;
	}
	std::cout << std::endl;
	return t;
}

// stampa in ouput il tweet
void tweetwrite(Tweet t){
	std::cout << "Testo:\n";
	std::cout << t.text << std::endl;
	std::cout << std::endl;
	
	for (unsigned int i=0; i<t.hashtags.size(); ++i) std::cout << t.hashtags[i] << "  ";
	std::cout << std::endl;
	std::cout << "---------------\n\n";
}
