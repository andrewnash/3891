#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Dice.h"
#include "Bank.h"
#include <vector>


Game* Game::Create(unsigned int numPlayers)
{
    if(numPlayers < 2 || numPlayers > 8) //If players are not withinin bounds return nulptr
    {
        return nullptr;
    }
    Game* g = new Game();  //create game object
    Player::Token t;
    for(int i = 0; i < numPlayers; i++) //assign each player a token
    {
        if(i == 0)
            t = Player::Token::Dog;
        else if(i == 1)
            t = Player::Token::Cannon;
        else if(i == 2)
            t = Player::Token::Iron;
        else if(i == 3)
            t = Player::Token::TopHat;
        else if(i == 4)
            t = Player::Token::Thimble;
        else if(i == 5)
            t = Player::Token::Car;
        else if(i == 6)
            t = Player::Token::Boot;
        else if(i == 7)
            t = Player::Token::Battleship;

        g->addPlayer(new Player(t, g));
    }
    g->theBank.distributeStartMoney(g->players); //give all players starting money
    g->theBank = Bank(); //refrences to bank & dice as per contract
    g->theDice = Dice();
    if(!g)
    {
        return nullptr;
    }
    return g;
}
    
void Game::gameOver()
{
    int size = players.size();
    for(int i = 0; i < size; i++) //delete pointers in players untill empty to "delete" all players
    {
        delete players[i];
        players[i] = nullptr; //Prevents hanging pointer
    }
}

void Game::addPlayer(Player* p)
{
    players.push_back(p); //add a pointer to the vector of pointers to players
}

std::vector<Player*>& Game::getPlayers()
{
    return players;
}
    
Bank* Game::getBank()
{
    return &theBank;
}

Dice* Game::getDice()
{
    return &theDice;
}