/*!
 * @file Bank.h
 * @brief New declaration of the Bank class for Assignment 5.
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
#if !defined(BANK_H)
#define BANK_H

class Player;
// Forward declaration of player
// #include "Player.h" in Bank.cpp
#include <vector>

/**
 * A basic representation of a bank to be used
 * in our Monopoly game implementation.
 */
class Bank
{
public:
    Bank(); // Constructor to initialize some values

    /**
     * Method to distribute starting money amounts to all
     * Players in input list.  Should only be called at
     * start of game.
     *
     * @params players - a vector of references to the players
     *
     * @modifies each player so that its wallet contains $1500
     */
    void distributeStartMoney(std::vector<Player*>& players);
    
private:
    int housesAvailable;  // initially 32
    int hotelsAvailable;  // initially 12
};

#endif // the end of the BANK_H header guard
