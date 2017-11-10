#include <iostream>
#include "Player.h"
#include "Bank.h"
#include "Game.h"
#include "Dice.h"
#include "Wallet.h"

int main()
{
	int i = 4;
	//Create game instance with i players;
	Game* theGame = Game::Create(i);

	//get all players from Game, total should be i, add player is tested on the static method
	std::vector<Player*>& players = theGame->getPlayers();


	//should print the token of each player, total should be i
	for(auto p : players)
	{
		std::cout << "Token is " << p->getToken() << "\n";
	}

	//should be 0 at first
	std::cout << "Initial value of location is: " << players[0]->getLocation() << "\n";

	//should be 2
	players[0]->setLocation(2);
	std::cout << "New value of location is: " << players[0]->getLocation() << "\n";

	//should output 0, as dice are initialized to different numbers
	std::cout << "Check if dice are double: " << theGame->getDice()->isDoubles() << "\n";

	//should output sum of dice (max sum 12, min sum = 2), should be different each time it is run
	std::cout << "Rolling dice gave: " << theGame->getDice()->roll() << "\n";

	//checks if dice were double
	std::cout << "Check if dice are doubles: " << theGame->getDice()->isDoubles() << "\n";

    //output should be true
    if(players[0]->getGame() == theGame)
    {
        std::cout << "True" << "\n";
    }

    //should  be 1500
    std::cout << players[0]->getWallet()->netWorth() << "\n";

	//should delete all pointers inside the vector and finally delete itself
	theGame->gameOver();

	return 0;
}

