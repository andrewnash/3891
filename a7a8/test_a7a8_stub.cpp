

#include "Player.h"
#include "Card.h"
#include "CardDeck.h"
#include <vector>
#include <iostream>
using namespace std;
int main()
{

    /****************************************************************
    * This first section of code sets up various other objects that
    * will be needed to interact with the code students create, and
    * runs some quick tests to ensure that the code I provided works
    * correctly.
    ***************************************************************/
    Player* p0 = new Player(Player::Token::Dog);   // will be currentPlayer
    Player* p1 = new Player(Player::Token::Boot);
    Player* p2 = new Player(Player::Token::Thimble);
    vector<Player*> others; // p1 and p2 will be "other players"
    others.push_back(p1);
    others.push_back(p2);
    
    CardDeck* cc = new CardDeck("Community Chest");
    GetOutOfJail* gooj = new GetOutOfJail("Get out of jail free", cc);
    cc->addCardToDeck(gooj);
    
    Card* drawn = cc->draw();
    drawn->applyEffect(p0, others);
    p0->setInJail(true);
    if (p0->useGetOutOfJailFreeCard() and (p0->inJail() == false))
    {
        cout << "Successfully used get out of jail free card" << endl;
    }
    else
    {
        cout << "Error! Should have been able to use get out of jail free card" << endl;
    }
    
    if (!p0->useGetOutOfJailFreeCard())
    {
        cout << "2nd attempt failed as it should because they" << endl;
    }
    else
    {
        cout << "Error! Was able to use a 2nd get out of jail card but should possibly have it." << endl;
    }
    
    p0->move(7);
    cout << "moved to " << p0->location() << endl;
    cout << "player has balance of " << p0->balance() << endl;
    p0->advanceToLocation(3);
    cout << "Using advanceToLocation(3) passes go, so balance is now " << p0->balance() << endl;
    
    p0->addHouses(5);
    p0->addHotels(2);
    cout << "Player has " << p0->numHouses() << " houses and " << p0->numHotels() << " hotels." << endl;
    drawn = cc->draw();
    drawn->applyEffect(p0, others);

    
    // Now we can start testing individual Card subclasses.  This approach
    // will print out results as the player works through the deck, but does
    // not match the exact tests we will be running.
    PayMoney* pmc = new PayMoney("Pay penalty to bank", cc, 50);
    cc->addCardToDeck(pmc);
    GetMoney* gmc = new GetMoney("Bank error in your favour", cc, 100);
    cc->addCardToDeck(gmc);
    PayOthers* poc = new PayOthers("Pay dividends to each other player", cc, 50);
    cc->addCardToDeck(poc);
    GetFromOthers* gfoc = new GetFromOthers("It's your birthday!", cc, 50);
    cc->addCardToDeck(gfoc);
    PayPer* ppc = new PayPer("Repair time!", cc, 40, 100);
    cc->addCardToDeck(ppc);
    GoToJail* gtjc = new GoToJail("Go directly to jail!", cc);
    cc->addCardToDeck(gtjc);
    AdvanceToSpecific* atsc = new AdvanceToSpecific("Visit Boardwalk!", cc, 39);
    cc->addCardToDeck(atsc);
    AdvanceToNearest* atnrrc = new AdvanceToNearest("Advance to nearest railroad", cc, 5);
    AdvanceToNearest* atnutilc = new AdvanceToNearest("Advance to nearest utility", cc, 12);
    cc->addCardToDeck(atnrrc);
    cc->addCardToDeck(atnutilc);
    MoveBack* mbc = new MoveBack("Move back 3 spaces!", cc, 3);
    cc->addCardToDeck(mbc);
    cc->shuffle();
    
    for(int i = 0; i < 20; i++)
    {
        // p0 draw a card, apply effect, print stats
        drawn = cc->draw();
        cout << "Draw " << i << ": " << drawn->text() << endl;
        drawn->applyEffect(p0, others);
        cout << "  Player loc " << p0->location() << endl;;
        if (p0->inJail())
        {
            cout << "    Player is in jail, trying to use get out of jail free card" << endl;
            if (p0->useGetOutOfJailFreeCard())
            {
                cout << "      ---> success!" << endl;
            }
            else
            {
                cout << "      ---> failed! Still in the slammer!" << endl;
            }
        }
        else
        {
            cout << "    Player is not in jail" << endl;
        }
        cout << "    Player balance is " << p0->balance() << endl;
        cout << "    Player has " << p0->numHouses() << " houses and " << p0->numHotels() << " hotels" << endl;
        cout << "    Other player balances are " << p1->balance() << ", " << p2->balance() << endl;
    }
    
    delete cc;

    // For Assignment 8
    CardDeck* chance = CardDeck::CreateFromFile("chance.txt", "Chance");
    if (chance)
    {
        cout << "Have gotten a valid pointer from CardDeck::CreateFromFile()! Try all the cards!" << endl;
        chance->shuffle();
        for(int i = 0; i < 20; i++)
        {
            // p0 draw a card, apply effect, print stats
            drawn = chance->draw();
            cout << "Draw " << i << ": " << drawn->text() << endl;
            drawn->applyEffect(p0, others);
            cout << "  Player loc " << p0->location() << endl;;
            if (p0->inJail())
            {
                cout << "    Player is in jail, trying to use get out of jail free card" << endl;
                if (p0->useGetOutOfJailFreeCard())
                {
                    cout << "      ---> success!" << endl;
                }
                else
                {
                    cout << "      ---> failed! Still in the slammer!" << endl;
                }
            }
            else
            {
                cout << "    Player is not in jail" << endl;
            }
            cout << "    Player balance is " << p0->balance() << endl;
            cout << "    Player has " << p0->numHouses() << " houses and " << p0->numHotels() << " hotels" << endl;
            cout << "    Other player balances are " << p1->balance() << ", " << p2->balance() << endl;
        }        

        delete chance;
    }
    else
    {
        cout << "Failed to create from file." << endl;
    }
    delete p0;
    delete p1;
    delete p2;
}
