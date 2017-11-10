#include "CardDeck.h"
#include "Card.h"
#include <iostream>

int main()
{
	//Create a pointer to a deck
	CardDeck* monopoly = new CardDeck("monopoly");

	//create pointers to cards
	Card* jail = new Card(Card::CardType::AdvanceTo,"Go to jail, LOL!",monopoly,0,10);
	Card* pay = new Card(Card::CardType::PayMoney,"Pay mf!",monopoly,200,0);
	Card* rain = new Card(Card::CardType::GetMoney,"Dem moniez",monopoly,200,0);
	Card* parking = new Card(Card::CardType::AdvanceTo,"Free parking!",monopoly,0,20);

	//testing card class
	//getting the effect, should output "Player advances to: 10" 
	std::cout << jail->getEffect()<<std::endl;	

	//getting the name of the deck, should output "monopoly"
	std::cout << jail->getDeck()->getName() << std::endl;

	//get flavourText, should output "Go to jail, LOL!"
	std::cout << jail->getText() << std::endl;

	//testing deck card
	//adding cards to deck
	monopoly->addCardToDeck(jail);
	monopoly->addCardToDeck(pay);
	monopoly->addCardToDeck(rain);
	monopoly->addCardToDeck(parking);

	//shuffling
	monopoly->shuffle();

	//this should output different things every time it is run
	std::cout << monopoly->draw()->getEffect() << std::endl;
	std::cout << monopoly->draw()->getEffect() << std::endl;
	std::cout << monopoly->draw()->getEffect() << std::endl;
	std::cout << monopoly->draw()->getEffect() << std::endl;

	return 0;
}
