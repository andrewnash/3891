#include <iostream>
#include "Card.h"
#include "CardDeck.h"
using namespace std;



Card::Card(CardType ct, std::string text, CardDeck* own, unsigned int amt, unsigned int dest) : mytype(ct), myDeck(own), flavourText(text), moneyAmount(amt), destination(dest)
{
}


std::string Card::getEffect() const
{
	string amt = to_string(moneyAmount); //cast moneyAmount & destination to strings so we can combine them with our text
	string adv = to_string(destination);
	if(mytype == Card::CardType::PayMoney) //chech if card is drawn, if so output corrisponding card and value
	{
		string payTxt = ("Player pays ");
		return payTxt + amt;
	}
	else if(mytype == Card::CardType::GetMoney)
	{
		string getTxt = ("Player gets ");
		return getTxt + amt;
	}
	else if(mytype == Card::CardType::AdvanceTo)
	{
		string advTxt = ("Player advances to ");
		return advTxt + adv;
	}
	else
	{
		return nullptr;
	}
}


 
CardDeck* Card::getDeck() const //return private value
{
	return myDeck;
}


std::string Card::getText() const // return private value
{
	return flavourText;
}
