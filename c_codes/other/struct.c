#include <stdio.h>

struct card{
	char *face;
	char *suit;
};//end structure card

int main(void){
	struct card aCard;// define one struct card variable
	struct card *cardPtr;// define a pointer to a struct card

	// place string into aCard
	aCard.face ="Ace";
	aCard.suit = "Spades";

	cardPtr = &aCard; // assing address of aCard to cardPtr

	printf("%s%s%s\n%s%s%s\n%s%s%s\n",aCard.face, " of ", aCard.suit,
	 cardPtr->face, " of ", cardPtr->suit,
	  (*cardPtr).face, " of ",(*cardPtr).suit );

	
}