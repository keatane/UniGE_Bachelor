#include "tweet.h"
#include <iostream>
#include <vector>

const int ntweets = 3;

void printalltweets(std::vector<Tweet> tl, int num){
	//for (unsigned int i=0; i<tl.size(); ++i) tweetwrite(tl[i]); // non ricorsivo
	if (num < tl.size()){
		tweetwrite(tl[num]);
		printalltweets(tl,num+1); // richiamo la stessa funzione su num+1 (posizione successiva nel vector)
	}
	// else NIENTE (if(tl.size()==0) return; è ridondante)
}

int main(){
	std::vector <Tweet> tweetlist; // elenco di tweet nel sistema
	for (unsigned int i=0; i<ntweets; ++i) tweetlist.push_back(tweetread());
	std::cout << "Hai scritto:\n";
	printalltweets(tweetlist, 0); // mi permette di stampare da un certo num
}
