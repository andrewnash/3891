/*!
 * @file CardDeck.h
 * @brief Declaration of the CardDeck class for ENGI 3891 Assignment 7/8, that
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
// Must include "Card.h" in implementation file.
class Card;




class CardDeck
{
public:
    /** Constructor *************************************
    *
    * @params name - name of card deck
    */
    CardDeck(std::string name);
    
    /** Destructor **************************************
    *
    * This destructor is used to delete all cards
    * in the draw and discard piles.  This means all
    * those pointers must be pointing to heap objects.
    * Your test code must create cards on the heap using
    * 'new" before adding them to a deck.
    */
    ~CardDeck();
    
    /** CreateFromFile **********************************
    *
    * Static method to create a deck and its cards
    * based on information from a loaded file.
    *
    * This method is what will be considered Assignment 8.
    * You can just have it return nullptr to start and
    * test all the other parts of this assignment before
    * doing the file I/O stuff.
    *
    * @params filename - name of file to use
    * @params deckname - name of deck to create
    *
    * @returns pointer to newly-created deck with cards
    *          initialized from file, or nullptr if error
    */
    static CardDeck* CreateFromFile(std::string filename, std::string deckname);

    /** draw **************************************
    * Draw a card from the draw pile. If draw pile
    * is empty, shuffle the deck and then draw again.
    * If a "get out of jail free" card is drawn, it
    * is not moved to the discard pile, but goes to
    * the player's hand.  (Adding to the player's
    * hand happens when the card effect is applied,
    * not during the draw itself.)
    *
    * @pre deck contains at least 1 card
    *
    * @modifies drawPile and discardPile, by moving
    *           a pointer from the drawPile to the
    *           discardPile
    * @returns pointer of the card that was drawn
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
    *
    * @params c - pointer to card to be added
    *             @pre c was created with a pointer
    *                  to this deck
    *             @pre c is a pointer to a Card
    *                  object on the heap
    *
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

