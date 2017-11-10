/*!
 * @file CardDeck.h
 * @brief Declaration of the CardDeck class for ENGI 3891 Assignment 3, that
 *        represents the card decks Community Chest and Chance in the Monopoly game.
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
#if !defined(CARDDECK_H)
#define CARDDECK_H

#include <string>
#include <vector>

// This is a forward declaration of the Card class.
// It lets the CardDeck class know Card exists, without
// leading to a set of circular includes.
class Card;




class CardDeck
{
public:
    /** Constructor *************************************
    *
    * @params name - name of card deck
    */
    CardDeck(std::string name);

    /** draw **************************************
    * Draw a card from the draw pile. If draw pile
    * is empty, shuffle the deck and then draw again.
    * @pre deck contains at least 1 card
    *
    * @modifies drawPile and discardPile, by moving
    *           a pointer from the drawPile to the
    *           discardPile
    * @returns pointer of the card that was moved
    */
    Card* draw();

    //! Returns name of deck
    std::string getName();

    /** shuffle **********************************
    * Shuffles the deck by combining cards in
    * discardPile and drawPile and randomizing them
    * back into the drawPile
    *
    * @modifies drawPile (ends with all cards newly
    *           randomized) and discardPile (ends up
    *           empty)
    **********************************************/
    void shuffle();

    /** addCardToDeck ****************************
    *
    * Adds a card to the discardPile of the deck.
    * @params c - pointer to card to be added
    *             @pre c was created with a pointer
    *                  to this deck
    * @modifies discardPile by adding c to it
    */
    void addCardToDeck(Card* c);
private:
    // Name of deck
    const std::string deckName;
    // draw and discard piles initially empty
    std::vector<Card*> drawPile;
    std::vector<Card*> discardPile;
};

#endif // the end of the CARDDECK_H header guard

