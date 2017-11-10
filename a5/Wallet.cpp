/*!
 * @file Wallet.cpp
 * @brief New implementation of the Wallet class for Assignment 5.
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
#include "Wallet.h"
#include "Bank.h"


// Constructor
Wallet::Wallet(Bank& banker)
    : theBank(banker), cash(0)
{
}
    
/**
 * Method to add money to wallet.
 *
 * @params m - amount to be added
 *
 * @modifies cash field to be old value + m
 */
void Wallet::deposit(unsigned int m)
{
    cash += m;
}
    
    
    
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
bool Wallet::withdraw(unsigned int m)
{
    if (m <= cash)
    {
        cash -= m;
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Returns total amount in wallet.
 *
 * @returns cash value
 */
unsigned int Wallet::netWorth()
{
    return cash;
}

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
bool Wallet::transferTo(unsigned int m, Wallet& payee)
{
    if (this->withdraw(m))
    {
        payee.deposit(m);
        return true;
    } else {
        return false;
    }
}
