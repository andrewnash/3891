#include <iostream>
#include <sstream>
#include "CardDeck.h"
#include "Card.h"
#include "Player.h"

using namespace std;

void displayPlayerStats(Player* p);
void testDeck(CardDeck* deck, vector<Player*> players, bool testJail);

int main()
{
	// Dummy players
	Player* houseyPoo = new Player(Player::Token::Boot);
	Player* venkyHankySpanky = new Player(Player::Token::Car);

	// Player to be modified
	Player* frank = new Player(Player::Token::Dog);
	frank->addHouses(2);
	frank->addHotels(2);
	// I add extra money just to test the constructor.
	// When starting out your testing your balance should be 3500
	frank->depositMoney(2000);

	vector<Player*> players;
	players.push_back(frank);
	players.push_back(houseyPoo);
	players.push_back(venkyHankySpanky);
	// Prints inital player stats of player to be modified. Should look like:
	// Name: Dog    Location: 0     Money: 3500    In jail? 0
	displayPlayerStats(frank);

	// Check to see what happens when we feed the create a bad file
	// Should return nullptr... cout of nullptr should be zero
	CardDeck* thisWillFail = CardDeck::CreateFromFile("Not a real file", "hahah sucks to be c++");
	cout << "This should be zero: " << thisWillFail << endl << endl;
	delete thisWillFail;

	CardDeck* chance;
	chance = CardDeck::CreateFromFile("chance.txt", "CHANCE");
	// Next line should print CHANCE
	cout << "The next line should print CHANCE" << endl;
	cout << chance->getName() << endl;
	// Shuffle twice to make sure she's super stirred
	chance->shuffle();
	chance->shuffle();

	CardDeck* comChest;
	comChest = CardDeck::CreateFromFile("community_chest.txt", "CC");
	// Next line should print CC
	cout << "The next line should print CC" << endl;
	cout << comChest->getName() << endl;
	// Shuffle twice to make sure she's super stirred
	comChest->shuffle();
	comChest->shuffle();
	
	// Successive tests of the the cards are tested.
	// Depending on how yours shuffles it should come up random every time you run
	// None of the descriptions of the cards falter from their effects (I think...)
	// So your stats next card to next card should be pretty good.
	// Some things to look out for in the first run of the cards:
	
	// 1. dog getting money when he moves and doesn't passes go
	// 2. the payPer not using right values/not making right amount (For 2H/2h should be 310$)
	// 3. Go to jail card doesn't set user in jail and move location to 10
	// 4. dog doesn't go to the right place when nearest is called
	// 5. Car and boot don't have the right amounts of money added/taken away when payOthers
	testDeck(chance, players, false);
	testDeck(comChest, players, false);
	
	// Shuffle the chance deck
	chance->shuffle();
	// Then test the cards when the player actually goes to jail
	// In a real game scenario a player would never be in jail and pickup a card
	// But you never know what house is going to throw at you
	// Things to watch for when the player is in jail:
	
	// 1. I've assumed that the player can still get money in jail
	// 2. The dog can't move while he's in jail
	// 3. The dog can still pay all while he's in jail
	// The hasbro official rules say you can still collect money so I guess these are right
	cout << "NOW TESTING WHAT HAPPENS WHEN PLAYER IS IN JAIL" << endl;
	testDeck(chance, players, true);

	// Make some space
	cout << endl << endl << endl << endl;

	// Testing railroad advanceToNearest
	frank->setLocation(0);
	frank->setInJail(false);
	AdvanceToNearest* railroad = new AdvanceToNearest("Shit", chance, 5);
	cout << "This should take you to 5, 15, 25 and 35" << endl;
	for(int i = 0; i < 4; i++)
	{
		railroad->applyEffect(frank, players);
		displayPlayerStats(frank);
	}	
	delete railroad;
	cout << endl << endl;
	
	// Testing utility advanceToNearest
	frank->setLocation(0);
	AdvanceToNearest* skrat = new AdvanceToNearest("Dwight Ball", chance, 12);
	cout << "This should 12 then 28" << endl;
	skrat->applyEffect(frank, players);	
	displayPlayerStats(frank);
	skrat->applyEffect(frank, players);
	displayPlayerStats(frank);
	delete skrat;

	// Testing moveback... should give $200 when you move past go
	cout << endl << endl;
	frank->setLocation(10);
	MoveBack* backTrack = new MoveBack("Take it back now yall", chance, 10);
	cout << "You should move back to go. And get 200 dollars" << endl;
	displayPlayerStats(frank);
	backTrack->applyEffect(frank, players);
	displayPlayerStats(frank);
	
	//Testing Moveback to see if it wraps backwards
	cout << endl << endl << "After applying backtrack again you should be at 30" << endl;
	displayPlayerStats(frank);
	backTrack->applyEffect(frank, players);
	displayPlayerStats(frank);
	delete backTrack;
	
	delete frank;
	delete venkyHankySpanky;
	
	delete houseyPoo;

	delete chance;
	delete comChest;

	// Some additional things to test for are dangaling pointers in your card 
	// vectors after the destructor is called. Just make sure they are set deleted and
	// set to nullptr in the destructor.
	// I didn't know how to test these without crashing the program
	// But if somebody knows how and could tell me that would be great!
	// I'd love some feedback if possible
	// Thanks :)
}

void testDeck(CardDeck* deck, vector<Player*> players, bool testJail)
{
	cout << endl << endl << endl << endl << "*******TESTING NEW DECK***********" << endl;
	for(int i = 0; i < 15; i++)
	{
		Card* c = deck->draw();
		cout << "Current Card is: " << c->text() << endl;
		cout << "Press Enter to apply effect." << endl;
		cin.ignore();
	
		c->applyEffect(players[0], players);
		for(int i = 0; i < players.size(); i++)
		{
			displayPlayerStats(players[i]);
		}
		if(players[0]->inJail() == true && testJail == false)
		{
			players[0]->setInJail(false);
			cout << "Player was removed from jail for test purposes" << endl;
		}
		cout << endl << endl;
	}
}

void displayPlayerStats(Player* p)
{
	string name;
	switch(p->token())
	{
		case Player::Token::Car:
			name = "Car";
		break;
		case Player::Token::Dog:
			name = "Dog";
		break;
		case Player::Token::Boot:
			name = "Boot";
		break;
	}
	cout << "Name: " << name << "\t" << "Location: " << p->location() << "\t" << " Money: " 
		<< p->balance() << "\t" << "In jail? " << p->inJail() << endl;
}