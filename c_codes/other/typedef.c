#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13

// card structure definition

typedef struct card{
	const char *face;// define pointer face
	const char *suit;// define pointer suit
}Card; 

//prototypes
void fillDeck(Card * const wDeck, const char * wFace[], const char * wSuit[]);
void shuffle(Card * const wDeck);
void deal(const Card * const wDeck);

int main(void)
{
	Card deck[CARDS];//define array of cards

	//initialize array of pointers
	const char *face[] ={"Ace", "Duce", "Three","Four","Five","Six","Seven", "Eight","Nine", "Ten","Jack","Queen","King"};

	//initialize array of pointers
	const char *suit[]={"Hearts","Diamonds","Clubs","Spades"};

	srand(time(NULL)); //randomize using time

	fillDeck(deck, face, suit);//load the deck with Cards
	shuffle(deck);// put Cards in random order
	deal(deck);// deal all 52 Cards
}// end main

//place string into Card structures
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[])
{

	size_t i;//counter

	//loop through wDeck
	for (i=0; i<CARDS; ++i){

		wDeck[i].face = wFace[i %FACES];
		wDeck[i].suit = wSuit[i/FACES];
	}//end for
}//end function fillDeck

//shuffle cards
void shuffle(Card * const wDeck){

	size_t i;//counter
	size_t j;//variable to hold random value between 0-51
	Card temp;//define temporary

	//loop through wDeck randomly swapping Cards
	for (i=0; i<CARDS; ++i){
		j = rand() % CARDS;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j]= temp;
	}
}//end function shuffle

//deal cards
void deal(const Card * const wDeck)
{
	size_t i; //counter

	//loop through wDeck
	for (i=0; i< CARDS; ++i){
		printf("%5s of %-8s%s", wDeck[ i ].face , wDeck[ i ].suit ,
			( i + 1 ) % 4 ? " " : "\n" );
	}
}
