/*!
 * @file Wallet.h
 * @brief Declaration of the Wallet class for ENGI 3891 Assignment 3, that
 *        represents the money for each played, stored as a vector of
 *        individual denominations.
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
#if !defined(WALLET_H)
#define WALLET_H

#include <vector>
#include "Money.h"
//#include "Bank.h"

// This is a forward declaration of the Bank class.
// It lets the Wallet class know Bank exists, without
// leading to a set of circular includes.
class Bank;

class Wallet
{
public:
    // Constructor
    Wallet(Bank& banker);
    
    /**
     * Add money to wallet.
     *
     * @params amt - amount of money to be added to wallet
     *               @pre amt in set {500, 100, 50, 20, 10, 5, 1}
     *
     * @modifies cash - adds new value to cash vector
     */
    void deposit(Money amt);
    
    /**
     * Removes specified amount of money from cash vector.     
     *
     * @params amt - amount of money to be taken from wallet
     *               @pre amt in set {500, 100, 50, 20, 10, 5, 1}
     *
     * @modifies cash - removes an item equal to amt from 
     *                  cash vector if possible
     *
     * @returns true if successfully found/removed matching amt,
     *          false otherwise
     */
    bool withdraw(Money amt);
    

    /**
     * Pays another wallet by removing value from own cash vector
     * and depositing it to payee.  Will have to search cash
     * vector to find appropriate denomination, return true if
     * found and can make the transfer, false if not.
     *
     * @params amt - amount of money to pay to other wallet
     *               @pre amt in set {500, 100, 50, 20, 10, 5, 1}
     *
     * @modifies cash - removes item equal to amt from 
     *                  cash vector if possible
     *
     * @returns true if successfully transferred matching amt,
     *          false otherwise (including if netWorth < amt)
     */
    bool transferTo(Money amt, Wallet& payee);
    
    //! Returns sum of all values in cash vector
    Money netWorth() const;
private:
    Bank& theBank; // reference to the bank
    
    // Vector holding individual items of Money
    // @inv values in cash vector are one of {500, 100, 50, 20, 10, 5, 1}
    std::vector<Money> cash;
    

};

#endif // the end of the WALLET_H header guard
