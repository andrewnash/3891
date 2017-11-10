#include <iostream>
#include "Card.h"
#include "CardDeck.h"

using namespace std;

int main() {

    Card* outputCardPointer;
    CardDeck* outputDeckPointer;

    CardDeck Chance("Chance");
    CardDeck* Chance_Pointer = &Chance;
    CardDeck CommunityChest("Community Chest");
    CardDeck* CommunityChest_Pointer = &CommunityChest;

    Card GoToStart(Card::CardType::AdvanceTo,"Advance to go, collect double amount",Chance_Pointer,0,0);
    Card* GoToStart_pointer = &GoToStart;
    Card GoToJail(Card::CardType::AdvanceTo,"Go to jail",Chance_Pointer,0,0);
    Card* GoToJail_pointer =&GoToJail;
    Card GoToSpace25(Card::CardType::AdvanceTo,"Advance to space 25",Chance_Pointer,0,25);
    Card* GoToSpace25_pointer = &GoToSpace25;

    Card GetPaid200(Card::CardType::GetMoney,"Win contest, collect $200",CommunityChest_Pointer,200,0);
    Card* GetPaid200_pointer = &GetPaid200;
    Card GetPaid500(Card::CardType::GetMoney,"Sell computer, collect $500",CommunityChest_Pointer,500,0);
    Card* GetPaid500_pointer = &GetPaid500;
    Card GetPaid1000(Card::CardType::GetMoney,"Beat ECE, collect $1000",CommunityChest_Pointer,1000,0);
    Card* GetPaid1000_pointer = &GetPaid1000;

    Card Pay200(Card::CardType::PayMoney,"Failed Circuits, repeat course and pay $200",Chance_Pointer,200,0);
    Card* Pay200_pointer = &Pay200;
    Card Pay500(Card::CardType::PayMoney,"Failed Circuits and Digital Logic, repeat courses and pay $500",Chance_Pointer,500,0);
    Card* Pay500_pointer = &Pay500;
    Card Pay1000(Card::CardType::PayMoney,"Failed term 3, repeat semester and pay $1000",CommunityChest_Pointer,1000,0);
    Card* Pay1000_pointer = &Pay1000;

    Chance.addCardToDeck(GoToJail_pointer);
    Chance.addCardToDeck(GoToStart_pointer);
    Chance.addCardToDeck(GoToSpace25_pointer);
    Chance.addCardToDeck(Pay200_pointer);
    Chance.addCardToDeck(Pay500_pointer);

    for(int i=0;i<50;i++){
        outputCardPointer = Chance.draw();
        cout << outputCardPointer->getEffect() << endl;
        cout << outputCardPointer->getText() << endl;
        outputDeckPointer = outputCardPointer->getDeck();
        cout << outputDeckPointer->getName() << endl;
        cout << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    CommunityChest.addCardToDeck(GetPaid200_pointer);
    CommunityChest.addCardToDeck(GetPaid500_pointer);
    CommunityChest.addCardToDeck(GetPaid1000_pointer);
    CommunityChest.addCardToDeck(Pay1000_pointer);

    for(int i=0;i<4;i++){
        outputCardPointer = CommunityChest.draw();
        cout << outputCardPointer->getEffect() << endl;
        cout << outputCardPointer->getText() << endl;
        outputDeckPointer = outputCardPointer->getDeck();
        cout << outputDeckPointer->getName() << endl;
        cout << endl;
    }


    return 0;
}