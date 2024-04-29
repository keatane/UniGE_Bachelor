/* Es_9 avanzato: GIOCO DELL’UNO Scrivere un programma per realizzare il gioco di carte UNO. Potete trovare le istruzioni del gioco al
seguente indirizzo https://it.wikipedia.org/wiki/UNO_(gioco_di_carte).
[SUGGERIMENTO: Dovrete definire almeno una struct che contiene le informazioni di una carta, e i vector per memorizzare
le carte in mano di ogni giocatore, nel mazzo e in tavola.]
*/

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

enum COLOR { RED, GREEN, YELLOW, BLUE, NONE_COLOR};
enum NUMBERS { ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, NONE };
enum TYPE { DRAW_TWO_CARD, DRAW_FOUR_CARD, CHANGE_LAP, STOP, CHANGE_COLOR, NUMBER };

const int NUMCARD = 7;
const string CARD_NOT_FOUND = "INDEX OUT OF BOUND";

struct Card{

	COLOR color;
	NUMBERS number;
	TYPE type;

};

typedef vector<Card> Deck;
typedef vector<Deck> playerDeck;

Card createCard(COLOR color, TYPE type, NUMBERS number){


	Card card;
	card.color = color;
	card.type = type;
	card.number = number;

	return card;
}


void addCardNumber(Deck& d){

	for (int c = RED; c <= YELLOW; c++)
		for (int n=ONE; n < NONE; n++)
		{
			Card card = createCard((COLOR)c, NUMBER, (NUMBERS)n); // (COLOR)c fa il cast (conversione) da int a enum
			d.push_back(card);
		}
}

void addColoredAction(Deck& d){

	for (int c = RED; c <= YELLOW; c++){

		Card stop = createCard((COLOR)c, STOP, NONE);
		Card change_lap = createCard((COLOR)c, CHANGE_LAP, NONE);
		Card draw_two = createCard((COLOR)c, DRAW_TWO_CARD, NONE);

		d.push_back(stop);
		d.push_back(change_lap);
		d.push_back(draw_two);

    }
}


void createDeck(Deck& d){
	addCardNumber(d);	// Per le regole ci sono due serie per colore (2 numeri 1 blue, 2 numeri 1 green ecc.)
	addCardNumber(d);

	addColoredAction(d);
	addColoredAction(d);

	for (int c = RED; c <= YELLOW; c++){	// Aggiungo le carte rimanenti (tot. 4 per carta)

		Card zero = createCard((COLOR)c, NUMBER, ZERO);
		Card change_color = createCard(NONE_COLOR, CHANGE_COLOR, NONE);
		Card draw_four_cards = createCard(NONE_COLOR, DRAW_FOUR_CARD, NONE);

		d.push_back(zero);
		d.push_back(change_color);
		d.push_back(draw_four_cards);
	}
}

void swap(Card& a, Card& b)
{
	Card aux = a;
	a = b;
	b = aux;
}


void shuffleDeck(Deck& d){	// Mischio il mazzo

	srand (time(NULL));
	for (int i=0; i<d.size(); ++i){

		int index = rand() % d.size(); // l'indice si muove fra zero e il resto della divisione sicuramente minore a d.size()
		swap(d[i], d[index]);
	}
}

// Scambia le carte fra i mazzi
void drawFirstCard(Deck& main, Deck& player){

	Card first = main[0];

	//removeCardInIndex(main, 0);
	main.erase(main.begin() + 0);

	player.push_back(first);

}

// Rimuove una carta da un mazzo
void removeCardInIndex(Deck& d, int index){

	Card card = deck[index];

	deck.erase(index);
	/* Erase "esteso"
	for (int i = index; i< deck.size(); i++)
		deck[i] = deck[i+1];
	deck.resize(deck.size()-1);
	*/
}

playerDeck distributeCards(Deck& d, int n_players){

	playerDeck p;

	for (int i=0; i < NUMCARD; i++){
		for (int j=0; j<n_players; j++)
		{
			drawFirstCard(d, p[j]);
		}
	}
}

bool enableDiscard(Card& card1, Card& card2){

	bool none_color = (card1.color == NONE_COLOR);
	bool same_color = (mycard.color == card.color);
	bool same_number = (mycard.number == card.number && mycard.type == NUMBER);
	
	return (none_color || same_color || same_number);
}

// Funzione per giocare una carta
void discardCardFromHand(Deck% player, Deck& game_deck, int index){
	
	if (index > player.size() || index < 0) throw CARD_NOT_FOUND;
	
	Card hand = player[index];
	Card first = game_deck[0];
	
	if (enableDiscard(hand, first)){
		player.erase(player.begin() + index));
		return true;
	}
	
	return false;
}

// Ritirare n carte

void drawNcard(Deck& main, Deck& player, int n){
	
	for (int i=0; i<n; i++)
		drawFirstCard(main, player);
		
}

int main()
{



}
