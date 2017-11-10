/*!
 * @file Bank.h
 * @brief Declaration of the Bank class for ENGI 3891 Assignment 3.
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

#include "Money.h"


// This is a forward declaration of the Wallet class.
// It lets the Bank class know Wallet exists, without
// leading to a set of circular includes.
class Wallet;

class Bank
{
public:
    // Since no fields yet, just let it use a default constructor.
    
    // Only one method so far; will expand this class later.
    
    /**
     * Initializes wallet with starting money.
     *
     * @params p - reference to Wallet of a player
     *
     * @modifies Wallet p of player to contain
     *           two 500’s, two 100’s, two 50’s,
     *           six 20’s, five 10’s, five 5’s, and five 1’s 
     *
     */
    void giveStartingMoney(Wallet& p);
    
private:
    // No fields needed just yet.
};

#endif // the end of the BANK_H header guard
