/*!
 * @file Wallet.h
 * @brief New declaration of the Wallet class for Assignment 5.
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

#include "Bank.h"
#include <vector>

/**
 * A basic representation of a bank to be used
 * in our Monopoly game implementation.
 */
class Wallet
{
public:
    // Constructor takes a reference to a Bank object
    Wallet(Bank& banker);
    
    /**
     * Method to add money to wallet.
     *
     * @params m - amount to be added
     *
     * @modifies cash field to be old value + m
     */
    void deposit(unsigned int m);
    
    
    
    /**
     * Withdraws specified amount from the wallet (if it can)
     * 
     * @params m - amount to withdraw
     * 
     * @modifies cash field - if m <= cash, m = m-c,
     *     otherwise nothing happens.
     *
     * @returns true if specified amount is removed, false otherwise
     */
    bool withdraw(unsigned int m);
    
    /**
     * Returns total amount in wallet.
     *
     * @returns cash value
     */
    unsigned int netWorth();
    
    /**
     * Transfer specified amount from this wallet
     * to payee wallet (if possible).
     *
     * @params m - amount to transfer
     *         payee - Wallet to transfer to
     *
     * @modifies cash field by subtracting m (if possible)
     *
     * @returns true if transfer was made, else false
     */
    bool transferTo(unsigned int m, Wallet& payee);

private:
    const Bank& theBank; // reference to the bank
    unsigned int cash; // stores current cash amount
};

#endif // the end of the WALLET_H header guard