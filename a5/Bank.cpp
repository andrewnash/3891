/*!
 * @file Bank.cpp
 * @brief New implementation of the Bank class for Assignment 5.
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
#include <iostream>
#include "Bank.h"
#include "Player.h"
#include "Wallet.h"

// Constructor implementation
Bank::Bank()
    : housesAvailable(32), hotelsAvailable(12)
{
}

// Iterate over vector of players, deposit 1500 to wallet of each
void Bank::distributeStartMoney(std::vector<Player*>& players)
{
    for (Player* p : players)
    {
        p->getWallet()->deposit(1500);
    }
}