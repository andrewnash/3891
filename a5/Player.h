/*!
 * @file Player.h
 * @brief Dclaration of the Player class for Assignment 5.
 *
 * @author Andrew House <andrew.w.h.house@mun.ca>
 * @copyright (c) 2017 Andrew House. All rights reserved.
 * @license Apache License, Version 2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

// The following lines are "header guards": they prevent us from redefining the
// Course class if we include this header file more than once. They effectively
// tell the pre-processor, "only pay attention to the contents of this file if
// you haven't seen them before".
#if !defined(PLAYER_H)
#define PLAYER_H

#include "Wallet.h"
#include <iostream>

// Forward declaration of Game class
class Game;
//#include "Game.h" in Player.cpp


class Player
{
public:
    enum class Token {Dog, Boot, Wheelbarrow, Car, Thimble, Battleship,
                        TopHat, Iron, HorseRider, Cannon};

    Player(Token t, Game* theGame);
    
    // Basic access methods
    
    //! Returns the player's token
    Token getToken();
    
    //! Get player's current location
    unsigned int getLocation();
    
    //! Set player's location directly
    void setLocation(unsigned int loc);
  
    //! Get a pointer to player's wallet
    Wallet* getWallet();
    
    //! Get a pointer to current game
    Game* getGame();

private:
    Game* myGame; // Reference to the game object we are part of
    const Token tok;   // player's token
    unsigned int location; // location on board, initially 0 (Go)
    Wallet money;      // wallet to handle money
};

//! Overload output stream to print token names to stream
std::ostream& operator<<(std::ostream& os, const Player::Token t);  
#endif // end of PLAYER_H header guard

