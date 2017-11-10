/*!
 * @file Card.h
 * @brief Declaration of the Card class for ENGI 3891 Assignment 3, that
 *        represents the cards in Community Chest or Chance in the Monopoly game.
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

#include <string>


// This is a forward declaration of the CardDeck class.
// It lets the Card class know CardDeck exists, without
// leading to a set of circular includes.
class CardDeck;


class Card
{
public:
    // Enum class to identify type of card
    enum class CardType {PayMoney, GetMoney, AdvanceTo};

    /** Constructor ****************************
    *
    * @params ct - type of card
    * @params text - flavour text on card
    * @params own - pointer to CardDeck object this card
    *               belongs to @pre own != nullptr
    * @params amt - money about to be used if card needs it
    * @params dest - location to be used if card needs it
    *                @pre 0 <= dest <= 39
    */
    Card(CardType ct, std::string text, CardDeck* own,
         unsigned int amt, unsigned int dest);

    /** getEffect ****************************
    *
    * @returns a string describing the effect of the card
    * based on the CardType and field values.
    * Eg. Player pays 200, Player gets 200, Player advances to 0
    * where the numbers are from the moneyAmount and destination
    * fields.
    */
    std::string getEffect() const;


    /** getDeck *****************************
    *
    * @returns pointer to CardDeck object
    *          that owns this card.
    */
    CardDeck* getDeck() const;

    /** getText ****************************
    *
    * @returns the flavourText string
    */
    std::string getText() const;
private:
    CardDeck* myDeck;
    const CardType mytype;
    const std::string flavourText;
    const unsigned int moneyAmount;
    const unsigned int destination;
};

#endif // the end of the CARD_H header guard

