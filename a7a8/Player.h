/*!
 * @file Player.h
 * @brief Dclaration of the Player class for Assignments 7 and 8.
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

// Forward declaration of get out of jail free card class
// Must include "Card.h" in implementation
class GetOutOfJail;

#include <vector>

class Player
{
public:
    enum class Token {Dog, Boot, Wheelbarrow, Car, Thimble, Battleship,
                        TopHat, Iron, HorseRider, Cannon};

    //! Constructor takes a player token
    Player(Token t);
    
    //! Destructor -- must delete and cards it owns
    ~Player();
    
    //! Returns player's token
    Token token();
    
    //! Deposits money into player's account. @pre amount >= 0
    void depositMoney(int amount);
    
    /**
    * Withdraws money from player's account.
    *
    * @params amount - amount to withdraw if possible @pres >= 0
    *
    * @modifies account_ to be current value - amount or 0,
    *           whichever is higher
    *
    * @returns amount removed from account_
    */
    int withdrawMoney(int amount);
    
    //! Returns account balance
    int balance();
    
    //! Returns current location of player (0..39)
    unsigned int location();
    
    /**
    * Set player location directly. Player does
    * not pass intervening spaces.
    *
    * @params newLoc - destination to move to
    *          @pre 0 <= newLoc <= 39
    *
    * @modifies location_ of player to be newLoc
    */
    void setLocation(unsigned int newLoc);
    
    //! Move player forward 2..12 spaces
    void move(unsigned int amt);
    
    /**
    * Advances player to newLoc, passing any
    * spaces in between.  If player passes Go (0),
    * they should receive $200.
    *
    * @params newLoc - destination to move to
    *          @pre 0 <= newLoc <= 39
    *
    * @modifies location_ of player to be newLoc,
    *           account_ if passes Go (location 0)
    */
    void advanceToLocation(unsigned int newLoc);
    
    //! Sets inJail_ field to be equal to jail param.
    void setInJail(bool jail);
    
    //! Returns inJail_ field.
    bool inJail();
    
    //! Adds a shared_ptd to a "Get out of jail free" card to list
    void addGetOutOfJailFreeCard(GetOutOfJail* goojCard);
    
    /**
    * Use a get out of jail free card (if player has one)
    *
    * @modifies getOutOfJailFreeCards_ to have one fewer pointer,
    *           inJail_ to be false
    *
    * @returns true if player was in jail and a get out of jail free
    *          card was used to get out, else false
    */
    bool useGetOutOfJailFreeCard();

    //! Add a number of houses to numHouses_    
    void addHouses(unsigned int num);
    //! Returns numHouses_
    unsigned int numHouses();
    //! Add a number of hotels to numHotels_
    void addHotels(unsigned int num);
    //! Returns numHotels_
    unsigned int numHotels();
    
    
    
private:
    const Token token_;      // Token representing player
    int account_;            // Player's money
    unsigned int location_;  // Player's current location
                             
    unsigned int numHouses_; // Number of houses owned by player
    unsigned int numHotels_; // Number of hotels owned by player
    
    bool inJail_; // Flag indicating if player is in jail or not
    
    // List of pointers to "get out of jail free" cards
    std::vector< GetOutOfJail* > getOutOfJailFreeCards_;
};


#endif // end of PLAYER_H header guard

