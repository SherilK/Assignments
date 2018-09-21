// ConsoleApplication34.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"




	typedef enum S { CLUBS, DIAMONDS, HEARTS, SPADES } SUIT;
	char suits[][10] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

	typedef enum F { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } FACE;
	char faces[][10] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };

	typedef struct
	{
		SUIT suit;
		FACE face;
	} card;

	typedef struct
	{
		card cards[5];
	} hand;

	// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
	// so if same card already in the hand, you would need to draw again
	// also, the card cannot appear in another hand either
	hand dealHand(hand handsDealt[], int numHandsDealt);

	// returns pointer to string containing, for example, "ACE of HEARTS"
	char * printCard(card aCard);

	// compares the FACE values of two cards (TWO is lowest, ACE is highest)
	// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
	char * compareCards(card yourCard, card dealersCard);

	// returns true if the hand contains four ACES
	bool fourAces(hand aHand);


	void main()
	{
		int i = 0;
		hand myHand, dealersHand;
		int seed = time(NULL);
		srand(seed);
		hand hands[10];

		// deal the first hand
		myHand = dealHand(hands, 0);

		// add this new hand to the set of dealt hands
		hands[0] = myHand;

		// deal another hand; let dealHand know what has already been dealt
		dealersHand = dealHand(hands, 1);

		// here you are just comparing each card one at a time in the two hands
		while (i<5)
		{
			printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i + 1, printCard(myHand.cards[i]), printCard(dealersHand.cards[i]), compareCards(myHand.cards[i], dealersHand.cards[i]));
			i++;
		}

		// now try to deal 4 Aces !
		while (1)
		{
			// deal a new hand; assume new deck every time, so nothing dealt already
			myHand = dealHand(hands, 0);

			// does it contain 4 ACES?
			if (fourAces(myHand)) break;
			i++; // keep track of number of hands dealt
		}
		// print out how many hands it took to find 4 aces
		printf("\n\n4 aces found after %d hands \n\n\n", i);
	}

	// compares the FACE values of two cards (TWO is lowest, ACE is highest)
	// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
	char * compareCards(card yourCard, card dealersCard)
	{
		char * sptr;
		sptr = (char *)malloc(10 * sizeof(char));
	
		// your code goes here
	
		if (yourCard.face > dealersCard.face)
			sptr = "You";
		else if (yourCard.face < dealersCard.face)
			sptr = "Dealer";
		else if (yourCard.face == dealersCard.face)
			sptr = "Draw";
		return sptr;
	}

	// returns pointer to string containing, for example, "ACE of HEARTS"
	char * printCard(card aCard)
	{
		char * sptr;

		// your code goes here
		
		if (aCard.face == (F)0 && aCard.suit == (S)0)
			sptr = "TWO of CLUBS";
		if (aCard.face == (F)1 && aCard.suit == (S)0)
			sptr = "THREE of CLUBS";
		if (aCard.face == (F)2 && aCard.suit == (S)0)
			sptr = "FOUR of CLUBS";
		if (aCard.face == (F)3 && aCard.suit == (S)0)
			sptr = "FIVE of CLUBS";
		if (aCard.face == (F)4 && aCard.suit == (S)0)
			sptr = "SIX of CLUBS";
		if (aCard.face == (F)5 && aCard.suit == (S)0)
			sptr = "SEVEN of CLUBS";
		if (aCard.face == (F)6 && aCard.suit == (S)0)
			sptr = "EIGHT of CLUBS";
		if (aCard.face == (F)7 && aCard.suit == (S)0)
			sptr = "NINE of CLUBS";
		if (aCard.face == (F)8 && aCard.suit == (S)0)
			sptr = strcat(faces[8],suits[0]);
		if (aCard.face == (F)9 && aCard.suit == (S)0)
			sptr = "JACK of CLUBS";
		if (aCard.face == (F)10 && aCard.suit == (S)0)
			sptr = "QUEEN of CLUBS";
		if (aCard.face == (F)11 && aCard.suit == (S)0)
			sptr = "KING of CLUBS";
		if (aCard.face == (F)12 && aCard.suit == (S)0)
			sptr = "ACE of CLUBS";

		if (aCard.face == (F)0 && aCard.suit == (S)1)
			sptr = "TWO of DIAMONDS";
		if (aCard.face == (F)1 && aCard.suit == (S)1)
			sptr = "THREE of DIAMONDS";
		if (aCard.face == (F)2 && aCard.suit == (S)1)
			sptr = "FOUR of DIAMONDS";
		if (aCard.face == (F)3 && aCard.suit == (S)1)
			sptr = "FIVE of DIAMONDS";
		if (aCard.face == (F)4 && aCard.suit == (S)1)
			sptr = "SIX of DIAMONDS";
		if (aCard.face == (F)5 && aCard.suit == (S)1)
			sptr = "SEVEN of DIAMONDS";
		if (aCard.face == (F)6 && aCard.suit == (S)1)
			sptr = "EIGHT of DIAMONDS";
		if (aCard.face == (F)7 && aCard.suit == (S)1)
			sptr = "NINE of DIAMONDS";
		if (aCard.face == (F)8 && aCard.suit == (S)1)
			sptr = strcat(faces[8], suits[1]);
		if (aCard.face == (F)9 && aCard.suit == (S)1)
			sptr = "JACK of DIAMONDS";
		if (aCard.face == (F)10 && aCard.suit == (S)1)
			sptr = "QUEEN of DIAMONDS";
		if (aCard.face == (F)11 && aCard.suit == (S)1)
			sptr = "KING of DIAMONDS";
		if (aCard.face == (F)12 && aCard.suit == (S)1)
			sptr = "ACE of DIAMONDS";

		if (aCard.face == (F)0 && aCard.suit == (S)2)
			sptr = "TWO of HEARTS";
		if (aCard.face == (F)1 && aCard.suit == (S)2)
			sptr = "THREE of HEARTS";
		if (aCard.face == (F)2 && aCard.suit == (S)2)
			sptr = "FOUR of HEARTS";
		if (aCard.face == (F)3 && aCard.suit == (S)2)
			sptr = "FIVE of HEARTS";
		if (aCard.face == (F)4 && aCard.suit == (S)2)
			sptr = "SIX of HEARTS";
		if (aCard.face == (F)5 && aCard.suit == (S)2)
			sptr = "SEVEN of HEARTS";
		if (aCard.face == (F)6 && aCard.suit == (S)2)
			sptr = "EIGHT of HEARTS";
		if (aCard.face == (F)7 && aCard.suit == (S)2)
			sptr = "NINE of HEARTS";
		if (aCard.face == (F)8 && aCard.suit == (S)2)
			sptr = strcat(faces[8], suits[2]);
		if (aCard.face == (F)9 && aCard.suit == (S)2)
			sptr = "JACK of HEARTS";
		if (aCard.face == (F)10 && aCard.suit == (S)2)
			sptr = "QUEEN of HEARTS";
		if (aCard.face == (F)11 && aCard.suit == (S)2)
			sptr = "KING of HEARTS";
		if (aCard.face == (F)12 && aCard.suit == (S)2)
			sptr = "ACE of HEARTS";

		if (aCard.face == (F)0 && aCard.suit == (S)3)
			sptr = "TWO of SPADES";
		if (aCard.face == (F)1 && aCard.suit == (S)3)
			sptr = "THREE of SPADES";
		if (aCard.face == (F)2 && aCard.suit == (S)3)
			sptr = "FOUR of SPADES";
		if (aCard.face == (F)3 && aCard.suit == (S)3)
			sptr = "FIVE of SPADES";
		if (aCard.face == (F)4 && aCard.suit == (S)3)
			sptr = "SIX of SPADES";
		if (aCard.face == (F)5 && aCard.suit == (S)3)
			sptr = "SEVEN of SPADES";
		if (aCard.face == (F)6 && aCard.suit == (S)3)
			sptr = "EIGHT of SPADES";
		if (aCard.face == (F)7 && aCard.suit == (S)3)
			sptr = "NINE of SPADES";
		if (aCard.face == (F)8 && aCard.suit == (S)3)
			sptr = strcat(faces[8], suits[3]);
		if (aCard.face == (F)9 && aCard.suit == (S)3)
			sptr = "JACK of SPADES";
		if (aCard.face == (F)10 && aCard.suit == (S)3)
			sptr = "QUEEN of SPADES";
		if (aCard.face == (F)11 && aCard.suit == (S)3)
			sptr = "KING of SPADES";
		if (aCard.face == (F)12 && aCard.suit == (S)3)
			sptr = "ACE of SPADES";
	
				//sptr = strcat(faces[j],suits[i]);
		
		return sptr;
	}

	// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
	// so if same card already in the hand, you would need to draw again
	// also, the card cannot appear in another hand either
	hand dealHand(hand handsDealt[], int numHands)
	{
		int i, n;
		int found = 0;
		hand newHand;
		int ncards = 0;

		SUIT newSuit;
		FACE newFace;
		card *ip;
		card *noveau;
		ip = newHand.cards;


		// your code goes here
		for (ncards = 0; ncards < 5;ncards++)
		{
			i= rand()%SPADES;
			n = rand() % ACE;
			
		 // newHand.cards->suit =(S) i;
		 // newHand.cards->face = (F)n;
		  (ip + ncards)->suit = (S)i;
		  (ip + ncards)->face = (F)n;
		  noveau = (ip + (ncards-1));
		  if (noveau == (ip+ncards))
		  {
			  i = rand() % SPADES;
			  n = rand() % ACE;
			  (ip + ncards)->suit = (S)i;
			  (ip + ncards)->face = (F)n;
		 }

		}


		return newHand;
	}

	// returns true if the hand contains four ACES
	bool fourAces(hand aHand)
	{
		int i;
		int numAces = 0;
		bool fourAces = false;
		card *ip;
		ip = aHand.cards;
		// your code goes here
		if (aHand.cards->face == ACE && (ip+1)->face==ACE && (ip+2)->face==ACE && (ip+3)->face==ACE && (ip+4)->face==ACE)
		{
			fourAces = true;
		}
		return fourAces;

	}



