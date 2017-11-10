/*!
 * @file Dice.h
 * @brief Declaration of the Dice class for Assignment 5.
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
#if !defined(DICE_H)
#define DICE_H

/**
 * A basic representation of the pair of 6-sided dice
 * used in the Monopoly game.
 */
class Dice
{
public:
     // Constructor needed to set values of d1, d2
     // so that isDoubles() can't return true before
     // dice are rolled the first time.
    Dice();
    
    /**
     * Method to roll the dice.
     *
     * @modifies d1, d2 to hold randomly selected values
     *           in the range of 1 to 6 (inclusive)
     *
     * @returns sum of d1 + d2 (total rolled on dice)
     */
    unsigned int roll();
    
    /**
     * Method to check if doubles were rolled by
     * most recent call to roll().
     *
     * @returns true if d1==d2, else false
     */
    bool isDoubles() const;
private:
    unsigned int d1, d2; // @pre d1, d2 in range 1 <= d# <= 6
};

#endif // the end of the DICE_H header guard