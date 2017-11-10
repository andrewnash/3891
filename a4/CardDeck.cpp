#include <iostream>
#include "Card.h"
#include "CardDeck.h"
#include <vector>
#include <algorithm>
using namespace std;



CardDeck::CardDeck(std::string name) : deckName(name)
{

}

Card* CardDeck::draw()
{
	if(drawPile.size() < 2) //If we have reached the end of the deck (one card left) we shuffle
	{
		shuffle();
	}
	discardPile.push_back(drawPile.front()); //Put first card in draw pile into discard pile
	
	drawPile.erase(drawPile.begin()); //Erease first card in draw pile
	
	return discardPile.back(); //returns last element in discard pile which is the card we just put there
}

std::string CardDeck::getName()
{
	return deckName;
}

void CardDeck::shuffle()
{
	drawPile.insert(drawPile.end(), discardPile.begin(), discardPile.end()); //fill draw pile with contents of discard pile
	
	discardPile.clear(); //empty discard pile

	random_shuffle(drawPile.begin(), drawPile.end()); //shuffle draw pile
}

void CardDeck::addCardToDeck(Card* c)
{
	discardPile.push_back(c); //move card pointer to discard pile
}