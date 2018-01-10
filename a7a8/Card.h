/*!
 * @file Card.h
 * @brief Dclaration of the Card class and subclasses for Assignments 7 and 8.
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
#if !defined(CARD_H)
#define CARD_H


// Forward delcaration of Player class
// In implementation, must include "Player.h"
class Player;

// Forward delcaration of CardDeck class
// In implementation, must include "CardDeck.h"
class CardDeck;

#include <string>
#include <vector>

//! Superclass for all cards.  This is a virtual class.
class Card
{
public:
    // Constructor to set text, deck
    Card(std::string flavourText, CardDeck* deck);
    
    // Virtual destructor to ensure that subclasses
    // can be deleted by pointer to superclass
    virtual ~Card() = default; // Will use default implementation
    
    std::string text(); // Accesses the card's text
    CardDeck* myDeck(); // Accesses the card's deck pointer
    
    /**
    * This virtual method applies the effect of the particular card
    * drawn to the players.
    *
    * @params currentPlayer - pointer to the current player
    *         otherPlayers - vector of pointers to other players
    *
    */
    virtual void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) = 0;
protected:
    const std::string text_; // Text on the card
    CardDeck* myDeck_;       // Pointer to deck the card belongs to
};

//! Subclass of Card representing cards that affect players' money
class MoneyEffect: public Card
{
public:
    //! Constructor takes text, deck, and an amount of money to use
    MoneyEffect(std::string flavourText, CardDeck* deck, int amtToUse);
    
    // Virtual destructor
    virtual ~MoneyEffect() = default;
    
    // Virtual method
    virtual void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) = 0;
protected:
    int amountToUse_; // Money amount to be used by card effect
};

//! Subclass of Card representing cards that modify players' locations
class MoveEffect: public Card
{
public:
    //! Constructor takes text, deck, and a location to use
    MoveEffect(std::string flavourText, CardDeck* deck, unsigned int locToUse);
    
    // Virtual destructor
    virtual ~MoveEffect() = default;
    
    // Virtual method
    virtual void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) = 0;
protected:
    int locationToUse_; // location value to be used by the card effect
};

//! PayMoney card requires player to pay money to the bank
class PayMoney: public MoneyEffect
{
public:
    // Constructor
    PayMoney(std::string flavourText, CardDeck* deck, int amtToUse);
    
    /**
    * PayMoney cards withdraw amountToUse_ from the current
    * player's account (if possible).
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so that they have amountToUse_ less money
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! GetMoney card gives player money from bank
class GetMoney: public MoneyEffect
{
public:
    // Constructor
    GetMoney(std::string flavourText, CardDeck* deck, int amtToUse);
    
    /**
    * GetMoney cards deposit amountToUse_ to the current
    * player's account.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so that they have amountToUse_ more money
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! PayOthers card requires player to pay each other player
class PayOthers: public MoneyEffect
{
public:
    // Constructor
    PayOthers(std::string flavourText, CardDeck* deck, int amtToUse);
    
    /**
    * For each other player, PayOthers cards withdraw amountToUse_
    * from the current player's account (if possible) and deposit'sb_type
    * it to the others player's account.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so that they have amountToUse_ less money
    *           per other player, each of the other players so they have
    *           amountToUse_ more money (if possible).
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! GetFromOthers cards give current player money from each other player.
class GetFromOthers: public MoneyEffect
{
public:
    GetFromOthers(std::string flavourText, CardDeck* deck, int amtToUse);

    /**
    * GetFromOthers cards withdraw amountToUse_ from each other player
    * and deposit it to the currentplayer's account.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so that they have amountToUse_ more money
    *           per other player (if possible), each other player has_denorm
    *           amountToUse_ less money (if possible)
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! PayPer cards require player to pay a certain amount per house/hotel owned.
class PayPer: public MoneyEffect
{
public:
    /**
    * Constructor is slightly different from all other MoneyEffect cards,
    * since this one needs 2 amounts (1 for houses, 1 for hotels).
    *
    * @params flavourText - the card text
    *         deck - pointer to the deck object this card belongs to
    *         amtToUseHouse - amount to pay per house owned
    *         amtToUseHotel - amount to pay per hotel owned
    */
    PayPer(std::string flavourText, CardDeck* deck, int amtToUseHouse, int amtToUseHotel);
    
    /**
    * PayPer cards cost the current player an amount of money based on the number
    * of houses and hotels they own.  The superclass field amountToUse_ stores
    * the cost per house; this class field amtToUseForHotels_ stores the cost per hotel.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so that they have (amountToUse_ * the number of houses
    *           they own) + (amtToUseForHotels_ * number of hotels they own) less
    *           money (if possible)
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
private:
    int amtToUseForHotels_; // Amount to pay per hotel
};

//! The "Get out of jail free" card
class GetOutOfJail: public Card
{
public:
    // Simple constructor
    GetOutOfJail(std::string flavourText, CardDeck*);
    /**
    * This card effect just adds itself to the current player's hand.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so they have a "get out of jail free" card
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! Sends player directly to jail
class GoToJail: public MoveEffect
{
public:
    // Constructor doesn't mirror MoveEffect since we know where player is sent.
    GoToJail(std::string flavourText, CardDeck* deck);
    
    /**
    * Sends current player to jail (sets location and inJail status).
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so they are located in jail and their inJail
    *           flag is true.
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! Moves player around the board to a specific location
class AdvanceToSpecific: public MoveEffect
{
public:
    //! Constructor takes text, deck, and the location to move to
    AdvanceToSpecific(std::string flavourText, CardDeck* deck, unsigned int locToUse);
    
    /**
    * Sends current player specified location, possibly passing "Go" along the way.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so they are located at locationToUse_ and have $200
    *           more money if they passed/landed on "Go" (0).
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

/**
* Moves the player to the nearest following example of the specified
* type of property (railroad or utility).
*/
class AdvanceToNearest: public MoveEffect
{
public:
    /**
    * Constructor
    *
    * @params flavourText - text to appear on the card
    *         deck - pointer to the card's deck
    *         locToUse - integer representing the type of property
    *                    the player is moved to
    *                    @pre locToUse == 5 (for railroads) or
    *                         locTouse == 12 (for utilities)
    */
    AdvanceToNearest(std::string flavourText, CardDeck* deck, unsigned int locToUse);
    
    /**
    * Sends current player nearest following instance of the specified type of
    * property (railroad or utility).
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so they are located at the next following
    *           railroad (if locationToUse_ == 5) or utility
    *           (if locationToUse_ == 12) from their current location,
    *           giving them $200 more money if they passed/landed on "Go"
    *           (location 0) on the way.
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

//! Moves player back a specified number of spaces
class MoveBack: public MoveEffect
{
public:
    // Constructor takes locToUse as number of spaces to go back
    MoveBack(std::string flavourText, CardDeck* deck, unsigned int locToUse);
    
    /**
    * Sends current player back a specified number of spaces. Players
    * do not pass "Go" when moving backwards, but if they land *on*
    * "Go" as the last move they will still get $200.
    *
    * @params currentPlayer - pointer to current player
    *         otherPlayers - vector of pointers to the other players
    *
    * @modifies currentPlayer so they are located at their current
    *           location - locationToUse_, accounting for wrap around
    *           at the beginning of the board.  If player ends up on "Go",
    *           also gets $200 more money.
    */
    void applyEffect(Player* currentPlayer, std::vector< Player* > otherPlayers) override;
};

#endif // end of CARD_H header guard