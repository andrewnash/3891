#include "Card.h"
#include "Player.h"



Card::Card(std::string flavourText, CardDeck* deck) : text_(flavourText), myDeck_(deck)
{}
        
std::string Card::text()
{
	return text_;
}
CardDeck* Card::myDeck()
{
	return myDeck_;
}




MoneyEffect::MoneyEffect(std::string flavourText, CardDeck* deck, int amtToUse) : Card(flavourText, deck), amountToUse_(amtToUse)
{}




MoveEffect::MoveEffect(std::string flavourText, CardDeck* deck, unsigned int locToUse) : Card(flavourText, deck), locationToUse_(locToUse)
{}





PayMoney::PayMoney(std::string flavourText, CardDeck* deck, int amtToUse) : MoneyEffect(flavourText, deck, amtToUse)
{}

void PayMoney::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->withdrawMoney(amountToUse_);
}




GetMoney::GetMoney(std::string flavourText, CardDeck* deck, int amtToUse) : MoneyEffect(flavourText, deck, amtToUse)
{}

void GetMoney::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->depositMoney(amountToUse_);	
}





PayOthers::PayOthers(std::string flavourText, CardDeck* deck, int amtToUse) : MoneyEffect(flavourText, deck, amtToUse)
{}

void PayOthers::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->withdrawMoney(amountToUse_*otherPlayers.size());
	for(int i = 0; i < otherPlayers.size(); i++)
	{
		otherPlayers[i]->depositMoney(amountToUse_);
	}
}




GetFromOthers::GetFromOthers(std::string flavourText, CardDeck* deck, int amtToUse) : MoneyEffect(flavourText, deck, amtToUse)
{}

void GetFromOthers::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->depositMoney(amountToUse_*otherPlayers.size());
	for(int i = 0; i < otherPlayers.size(); i++)
	{
		otherPlayers[i]->withdrawMoney(amountToUse_);
	}
}




PayPer::PayPer(std::string flavourText, CardDeck* deck, int amtToUseHouse, int amtToUseHotel) :	MoneyEffect(flavourText, deck, amtToUseHouse), amtToUseForHotels_(amtToUseHotel)
{}

void PayPer::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->withdrawMoney(currentPlayer->numHouses()*amountToUse_ + currentPlayer->numHotels()*amtToUseForHotels_);
}




GetOutOfJail::GetOutOfJail(std::string flavourText, CardDeck* deck) : Card(flavourText, deck)
{}

void GetOutOfJail::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->addGetOutOfJailFreeCard(this);
}




GoToJail::GoToJail(std::string flavourText, CardDeck* deck) : MoveEffect(flavourText, deck, 10)
{}

void GoToJail::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->setInJail(true);
	currentPlayer->setLocation(10);
}




AdvanceToSpecific::AdvanceToSpecific(std::string flavourText, CardDeck* deck, unsigned int locToUse) : MoveEffect(flavourText, deck, locToUse)
{}

void AdvanceToSpecific::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->advanceToLocation(locationToUse_);
}




AdvanceToNearest::AdvanceToNearest(std::string flavourText, CardDeck* deck, unsigned int locToUse) : MoveEffect(flavourText, deck, locToUse)
{}

void AdvanceToNearest::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	if(locationToUse_== 5)
	{
		if(currentPlayer->location() >= 5 && currentPlayer->location() <= 14) 
		{
			currentPlayer->advanceToLocation(15);
		}
		else if(currentPlayer->location() >= 15 && currentPlayer->location() <= 24) 
		{
			currentPlayer->advanceToLocation(25);
		}
		else if(currentPlayer->location() >= 25 && currentPlayer->location() <= 34) 
		{
			currentPlayer->advanceToLocation(35);
		}
		else
		{
			currentPlayer->advanceToLocation(5);
		}
	}
	else if(locationToUse_ == 12)
	{
		if(currentPlayer->location() >= 12 && currentPlayer->location() <= 27) 
		{
			currentPlayer->advanceToLocation(28);
		}
		else
		{
			currentPlayer->advanceToLocation(12);
		}
	}
}




MoveBack::MoveBack(std::string flavourText, CardDeck* deck, unsigned int locToUse) : MoveEffect(flavourText, deck, locToUse)
{}

void MoveBack::applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers)
{
	currentPlayer->move(40 - locationToUse_);
	if(currentPlayer->location() == 0)
	{
		currentPlayer->depositMoney(200);
	}
}

