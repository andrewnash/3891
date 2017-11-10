#include<iostream> 

#include "Dice.h"
#include "Wallet.h"
#include "Bank.h"
#include "Player.h"
#include "Game.h"

#include <vector>

using namespace std;

void printPlayers(Game* instance)
{
	vector<Player*>playerObj = instance->getPlayers();
	for(int i = 0; i < playerObj.size(); i++)
	{
		Wallet* wallet = playerObj[i]->getWallet();
		cout << playerObj[i]->getToken() << "Money: " << wallet->netWorth();
	}
	
	cout << endl;
}

int main()
{	
	Game* instance = Game::Create(8);

	printPlayers(instance);

	instance->gameOver();
	
	delete instance;
	instance = nullptr;
	
	return 0;
}