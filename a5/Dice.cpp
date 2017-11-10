#include <iostream>
#include "Dice.h"
#include "cstdlib"


Dice::Dice(): d1(1), d2(2) {}
    
unsigned int Dice::roll() //generate random number for d1 & d2 (seperatly) and return their sum
{
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    return d1 + d2;
}
    
bool Dice::isDoubles() const
{
    if(d1 == d2) //check if d1 = d2, if not false
    {
        return true;
    }
    return false;
}