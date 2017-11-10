#include <iostream>
#include "Player.h"
#include "Wallet.h"
#include "Game.h"



Player::Player(Token t, Game* theGame): tok(t), myGame(theGame), location(0), money(*(theGame->getBank())) {}
    
Player::Token Player::getToken()
{
    return tok;
}

unsigned int Player::getLocation()
{
    return location;
}
    
void Player::setLocation(unsigned int loc) //overide current location value
{
    location = loc;
}
  
Wallet* Player::getWallet()
{
    return &money;
}
    
Game* Player::getGame()
{
    return myGame;
}

std::ostream& operator<<(std::ostream& os, const Player::Token t)
{
    std::string theToken;

    if(t == Player::Token::Dog)
        theToken = "Dog";
    else if(t == Player::Token::Cannon)
        theToken = "Cannon";
    else if(t == Player::Token::Iron)
        theToken = "Iron";
    else if(t == Player::Token::TopHat)
        theToken = "TopHat";
    else if(t == Player::Token::Thimble)
        theToken = "Thimble";
    else if(t == Player::Token::Car)
        theToken = "Car";
    else if(t == Player::Token::Boot)
        theToken = "Boot";
    else if(t == Player::Token::Battleship)
        theToken = "Battleship";

    os << theToken << std::endl;
    return os;
}