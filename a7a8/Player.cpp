/*!
 * @file Player.cpp
 * @brief Implementation of the Player class for Assignments 7 and 8,
 *        proved by the instructor.
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

#include "Player.h"
#include "Card.h"
#include "CardDeck.h"
#include <vector>
#include <memory>

//! Constructor takes a player token
Player::Player(Player::Token t)
    : token_(t), account_(1500), location_(0),
      numHouses_(0), numHotels_(0), inJail_(false)
{
}

// Destructor must delete any "get out of jail free" cards
// the player owns, since they are not in their deck.
Player::~Player()
{
    for (GetOutOfJail* g: getOutOfJailFreeCards_)
    {
        delete g;
    }
}

//! Returns player's token
Player::Token Player::token()
{
    return token_;
}

//! Deposits money into player's account.
void Player::depositMoney(int amount)
{
    account_ += amount;
}

/**
* Withdraws money from player's account.
*
* @params amount - amount to withdraw if possible
*
* @modifies account_ to be current value - amount or 0,
*           whichever is higher
*
* @returns amount removed from account_
*/
int Player::withdrawMoney(int amount)
{   int retVal;
    if (account_ >= amount)
    {
        account_ -= amount;
        retVal = amount;
    }
    else
    {
        // Not enough money! Return as much as possible
        retVal = account_;
        account_ = 0;
    }
    return retVal;
}

//! Returns account balance
int Player::balance()
{
    return account_;
}

//! Returns current location of player (0..39)
unsigned int Player::location()
{
    return location_;
}

/**
* Set player location directly. Player does
* not pass intervening spaces.
*
* @params newLoc - destination to move to
*          @pre 0 <= newLoc <= 39
*
* @modifies location_ of player to be newLoc
*/
void Player::setLocation(unsigned int newLoc)
{
    location_ = newLoc;
}

void Player::move(unsigned int amt)
{
    this->advanceToLocation((location_ + amt)%40);
}

/**
* Advances player to newLoc, passing any
* spaces in between.
*
* @params newLoc - destination to move to
*          @pre 0 <= newLoc <= 39
*
* @modifies location_ of player to be newLoc
*/
void Player::advanceToLocation(unsigned int newLoc)
{
    while (location_ != newLoc)
    {
        // use mod to ensure location in 0..39
        location_ = (location_ + 1) % 40;
        if (location_ == 0)
        {
            account_ += 200;
        }
    }
}

//! Sets inJail_ field to be equal to jail param.
void Player::setInJail(bool jail)
{
    inJail_ = jail;
}

//! Returns inJail_ field.
bool Player::inJail()
{
    return inJail_;
}

//! Adds a shared_ptd to a "Get out of jail free" card to list
void Player::addGetOutOfJailFreeCard(GetOutOfJail* goojCard)
{
    getOutOfJailFreeCards_.push_back(goojCard);
}

/**
* Use a get out of jail free card (if player has one)
*
* @modifies getOutOfJailFreeCards_ to have one fewer pointer,
*           inJail_ to be false
*
* @returns true if player was in jail and a get out of jail free
*          card was used to get out, else false
*/
bool Player::useGetOutOfJailFreeCard()
{
    if ((inJail_ == true) and (getOutOfJailFreeCards_.size() > 0))
    {
        // Pick first card to use
        GetOutOfJail* escapeCard = getOutOfJailFreeCards_[0];
        // Remove from hand
        getOutOfJailFreeCards_.erase(getOutOfJailFreeCards_.begin());
        // Add card back to its deck's discard pile
        escapeCard->myDeck()->addCardToDeck(escapeCard);
        // Bust player out
        inJail_ = false;
        return true;
    }
    else
    {
        // No need to use or no card to use
        return false;
    }
}

//! Add a number of houses to numHouses_    
void Player::addHouses(unsigned int num)
{
    numHouses_ += num;
}

//! Returns numHouses_
unsigned int Player::numHouses()
{
    return numHouses_;
}

//! Add a number of hotels to numHotels_
void Player::addHotels(unsigned int num)
{
    numHotels_ += num;
}

//! Returns numHotels_
unsigned int Player::numHotels()
{
    return numHotels_;
}
