#include "CardDeck.h"
#include "Card.h"
#include "Player.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;




CardDeck::CardDeck(std::string name): deckName(name)
{}


CardDeck::~CardDeck()
{
	for(int i=0; i < discardPile.size(); i++)
	{	
		if(discardPile[i]->text() != " Get out of jail free")
		{
			delete discardPile[i];
			discardPile[i] = nullptr;
		}
	}
	discardPile.clear();
	for(int i=0; i < drawPile.size(); i++)
	{
		if(drawPile[i]->text() != " Get out of jail free")
		{
			delete drawPile[i];
			drawPile[i] = nullptr;
		}
	}
	drawPile.clear();
}
    

CardDeck* CardDeck::CreateFromFile(std::string filename, std::string deckname)
{
	CardDeck* deck = new CardDeck(deckname);
	ifstream readFile;
	readFile.open(filename);
	if(readFile.is_open())
	{
		while(!readFile.eof())    
		{
			string type;
			string txt;
			string i;
			string j;
			for(int p = 0; p < 4; p++)
			{
				string onCard;
				switch(p)
				{
				case 0:
					getline(readFile, onCard, ',');
					type = onCard;
					break;

				case 1:
					getline(readFile, onCard, ',');
					txt = onCard;
					break;

				case 2:
					getline(readFile, onCard, ',');
					i = onCard;
					break;

				case 3:
					getline(readFile, onCard, '\n');
					j = onCard;
					break;
				}
			}
			if(type == "AdvanceToSpecific")
			{
				deck->addCardToDeck(new AdvanceToSpecific(txt, deck, stoi(i)));
			}
			else if(type == "AdvanceToNearest")
			{
				deck->addCardToDeck(new AdvanceToNearest(txt, deck, stoi(i)));
			}
			else if(type == "GetMoney")
			{
				deck->addCardToDeck(new GetMoney(txt, deck, stoi(i)));
			}
			else if(type == "GetOutOfJail")
			{
				deck->addCardToDeck(new GetOutOfJail(txt, deck));
			}
			else if(type == "GoToJail")
			{
				deck->addCardToDeck(new GoToJail(txt, deck));
			}
			else if(type == "MoveBack")
			{
				deck->addCardToDeck(new MoveBack(txt, deck, stoi(i)));
			}
			else if(type == "PayPer")
			{
				deck->addCardToDeck(new PayPer(txt, deck, stoi(i), stoi(j)));
			}
			else if(type == "PayMoney")
			{
				deck->addCardToDeck(new PayMoney(txt, deck, stoi(i)));
			}
			else if(type == "PayOthers")
			{
				deck->addCardToDeck(new PayOthers(txt, deck, stoi(i)));
			}
			else if(type == "GetMoney")
			{
				deck->addCardToDeck(new GetMoney(txt, deck, stoi(i)));
			}
			else if(type == "GetFromOthers")
			{
				deck->addCardToDeck(new GetFromOthers(txt, deck, stoi(i)));
			}
		}
	}
	else
	{
		return nullptr;
	}
	readFile.close();
	return deck;
}

Card* CardDeck::draw()
{
	if(drawPile.size() < 1)
	{
		shuffle();
	}
	if(drawPile.front()->text().find("Get out of jail") == string::npos)
    {
        discardPile.push_back(drawPile.front()); 
        drawPile.erase(drawPile.begin()); 

        return discardPile.front(); 
    } 
    else 
    {
        Card *DrawnGOOJ = drawPile.front();
        drawPile.erase(drawPile.begin()); 

       	return DrawnGOOJ; 
    }
}

std::string CardDeck::getName()
{
	return deckName;
}

void CardDeck::shuffle()
{
	drawPile.insert(drawPile.end(), discardPile.begin(), discardPile.end());
	
	discardPile.clear();

	random_shuffle(drawPile.begin(), drawPile.end()); 
}

void CardDeck::addCardToDeck(Card* c)
{
	discardPile.push_back(c);
}