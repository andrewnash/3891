/*!
 * @file Game.h
 * @brief Declaration of the Game class for Assignment 5.
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
#if !defined(GAME_H)
#define GAME_H

#include "Bank.h"
#include "Dice.h"

// Forward declaration of Player class
class Player;
//#include "Player.h" in Game.cpp

#include <vector>

class Game
{
public:
    // Default constructor is fine, will use static Create 
    // method to produce instances of Game with specified number
    // of players.
    
    /**
    * Static method creates a Game() object
    * and specified number of players and adds
    * players to game, returning pointer to new object.
    *
    * @params numPlayers - desired number of players
    *                    @pre 2 <= numPlayers <= 8
    *
    * @returns pointer to heap-allocated Game object
    *          containing the requested number of players,
    *          or else nullptr if unsuccessful at any point
    */
    static Game* Create(unsigned int numPlayers);
    
    /**
    * Method to be called to delete all heap-allocated
    * player objects in game.  Call this before using delete
    * on the Game object.  Later will be incorporated into
    * a destructor, but we haven't gotten there yet.
    */
    void gameOver();
    
    //! Adds a player object to the current game.
    void addPlayer(Player* p);
    
    //! Returns a vector of all the players
    std::vector<Player*>& getPlayers();
    
    //! Returns a pointer to the Bank object
    Bank* getBank();
    
    //! Returns a pointer to the Dice object
    Dice* getDice(); 
private:
    std::vector<Player*> players;
    Bank theBank;
    Dice theDice;
};

#endif // End of the GAME_H header guard
