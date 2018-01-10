#include <iostream>
#include "fstream"
#include "sstream"
#include "Player.h"
#include "CardDeck.h"
#include "Card.h"
#include <stdlib.h>
//#include "Dice.h"
#include <iomanip>

using namespace std;

int main() {

    //!Program declarations

    freopen("TestOutput.txt","w",stdout);

    srand(time(0));
   // Dice PlayerDice;
    int numSucessfulTests = 0;
    double individualTest = 0;
    double percent = 0.00;
   // int roll = 0;
    int tempBalance1 = 0;
    int tempBalance2 = 0;
    int tempBalance3 = 0;
    int tempBalance4 = 0;
    Player P1(Player::Token::Battleship);
    Player P2(Player::Token::Cannon);
    Player P3(Player::Token::HorseRider);
    Player P4(Player::Token::TopHat);

    Player* P1P = &P1;
    Player* P2P = &P2;
    Player* P3P = &P3;
    Player* P4P = &P4;

    vector<Player*> Players;
    Players.push_back(P1P);
    Players.push_back(P2P);
    Players.push_back(P3P);
    Players.push_back(P4P);

    CardDeck Chance("Chance");
    CardDeck CommunityChest("CommunityChest");


    //!***************************************Assignment 8*******************************************************
     CardDeck* CP = Chance.CreateFromFile("chance.txt","Chance");
     CardDeck* CCP = CommunityChest.CreateFromFile("Community_chest.txt","CommunityChest");
    //!**********************************************************************************************************

    Card *DrawnCard;

    //!setting output precision and type

    std::cout << std::fixed;
    std::cout << std::setprecision(2);




    //! CardDeck.Draw() & CardDeck.Shuffle Methods
    cout << "***********************************************" << endl;
    cout << ".<Total Test Weight = >" << endl;
    cout << "***********************************************" << endl << endl;

    //!If you have not completed assignment 8, uncomment this code//

    P1P->addHotels(1);
    P2P->addHotels(2);
    P3P->addHotels(3);
    P4P->addHotels(4);

    P1P->addHouses(4);
    P2P->addHouses(3);
    P3P->addHouses(2);
    P4P->addHouses(1);

    P1P->advanceToLocation(2);
    P2P->advanceToLocation(3);
    P3P->advanceToLocation(4);
    P4P->advanceToLocation(5);

    cout << "**********************************************************************"<<endl;
    cout << "Player Stats"<<endl;
    cout << "**********************************************************************"<<endl;

    cout << "Player1"<<endl;
    cout << "Current Location: " << P1P->location() << endl;
    cout << "Current Balance: " << P1P->balance()<<endl;
    cout << "InJail status: " << P1P->inJail()<<endl;
    cout << "Number of houses: " << P1P->numHouses()<<endl;
    cout << "Number of hotels: " << P1P->numHotels()<<endl;
    cout << endl;
    cout << "Player2"<<endl;
    cout << "Current Location: " << P2P->location() << endl;
    cout << "Current Balance: " << P2P->balance()<<endl;
    cout << "InJail status: " << P2P->inJail()<<endl;
    cout << "Number of houses: " << P2P->numHouses()<<endl;
    cout << "Number of hotels: " << P2P->numHotels()<<endl;
    cout << endl;
    cout << "Player3"<<endl;
    cout << "Current Location: " << P3P->location() << endl;
    cout << "Current Balance: " << P3P->balance()<<endl;
    cout << "InJail status: " << P3P->inJail()<<endl;
    cout << "Number of houses: " << P3P->numHouses()<<endl;
    cout << "Number of hotels: " << P3P->numHotels()<<endl;
    cout << endl;
    cout << "Player4"<<endl;
    cout << "Current Location: " << P4P->location() << endl;
    cout << "Current Balance: " << P4P->balance()<<endl;
    cout << "InJail status: " << P4P->inJail()<<endl;
    cout << "Number of houses: " << P4P->numHouses()<<endl;
    cout << "Number of hotels: " << P4P->numHotels()<<endl;
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++){
            if(j==0){
                cout << "Player 1 turn."<<endl;
            }else if(j==1){
                cout << "Player 2 turn."<<endl;
            }else if(j==2){
                cout << "Player 3 turn."<<endl;
            }else if(j==3){
                cout << "Player 4 turn."<<endl;
            }
            DrawnCard = CP->draw();
            cout << "Drawing card from " << (DrawnCard->myDeck()->getName()) << " Deck." << endl;
            cout << DrawnCard->text() << endl;

            if (Card *test = dynamic_cast< PayMoney * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl<< endl;
                }else if(j==1){
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 2 Balance After: " << P2P->balance()<< endl<< endl;
                }else if(j==2){
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 3 Balance After: " << P3P->balance()<< endl<< endl;
                }else if(j==3){
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 4 Balance After: " << P4P->balance()<< endl<< endl;
                }
            } else if (Card *test = dynamic_cast< GetMoney * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl<< endl;
                }else if(j==1){
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 2 Balance After: " << P2P->balance()<< endl<< endl;
                }else if(j==2){
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 3 Balance After: " << P3P->balance()<< endl<< endl;
                }else if(j==3){
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 4 Balance After: " << P4P->balance()<< endl<< endl;
                }
            } else if (Card *test = dynamic_cast< PayOthers * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==1){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==2){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==3){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }

            } else if (Card *test = dynamic_cast< GetFromOthers * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==1){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==2){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }else if(j==3){
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl;
                    cout <<"Player 2 Balance After: " << P2P->balance() << endl;
                    cout <<"Player 3 Balance After: " << P3P->balance() << endl;
                    cout <<"Player 4 Balance After: " << P4P->balance() << endl<< endl;
                }
            } else if (Card *test = dynamic_cast< PayPer * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 Balance Before: " << P1P->balance() << endl;
                    cout <<"Player 1 Hotels Before: " << P1P->numHotels() << endl;
                    cout <<"Player 1 Houses Before: " << P1P->numHouses() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 Balance After: " << P1P->balance()<< endl<<endl;
                }else if(j==1){
                    cout <<"Player 2 Balance Before: " << P2P->balance() << endl;
                    cout <<"Player 2 Hotels Before: " << P2P->numHotels() << endl;
                    cout <<"Player 2 Houses Before: " << P2P->numHouses() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 2 Balance After: " << P2P->balance()<< endl<<endl;
                }else if(j==2){
                    cout <<"Player 3 Balance Before: " << P3P->balance() << endl;
                    cout <<"Player 3 Hotels Before: " << P3P->numHotels() << endl;
                    cout <<"Player 3 Houses Before: " << P3P->numHouses() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 3 Balance After: " << P3P->balance()<< endl<<endl;
                }else if(j==3){
                    cout <<"Player 4 Balance Before: " << P4P->balance() << endl;
                    cout <<"Player 4 Hotels Before: " << P4P->numHotels() << endl;
                    cout <<"Player 4 Houses Before: " << P4P->numHouses() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 4 Balance After: " << P4P->balance()<< endl<<endl;
                }
            } else if (Card *test = dynamic_cast< GetOutOfJail * >( DrawnCard )) {
                   cout << "Added 1 get out of jail free card."<< endl<< endl;
            } else if (Card *test = dynamic_cast< GoToJail * >( DrawnCard )) {
                if(j==0) {
                    cout <<"Player 1 inJail status before: " << P1P->inJail() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout <<"Player 1 inJail status after: " << P1P->inJail()<< endl<< endl;
                }else if(j==1){
                    cout <<"Player 2 inJail status before: " << P2P->inJail() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout <<"Player 2 inJail status after: " << P2P->inJail()<< endl<< endl;
                }else if(j==2){
                    cout <<"Player 3 inJail status before: " << P3P->inJail() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout <<"Player 3 inJail status after: " << P3P->inJail()<< endl<< endl;
                }else if(j==3){
                    cout <<"Player 4 inJail status before: " << P4P->inJail() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout <<"Player 4 inJail status after: " << P4P->inJail()<< endl<< endl;
                }
            } else if (Card *test = dynamic_cast< AdvanceToSpecific * >( DrawnCard )) {
                if(j==0) {
                    cout << "Player 1 Location Before: " << P1P->location() << endl;
                    cout << "Player 1 Balance Before: " << P1P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout << "Player 1 Location After: " << P1P->location()<< endl;
                    cout << "Player 1 Balance After: " << P1P->balance() << endl<<endl;
                }else if(j==1){
                    cout << "Player 2 Location Before: " << P2P->location() << endl;
                    cout << "Player 2 Balance Before: " << P2P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout << "Player 2 Location After: " << P2P->location()<< endl;
                    cout << "Player 2 Balance After: " << P2P->balance() << endl<<endl;
                }else if(j==2){
                    cout << "Player 3 Location Before: " << P3P->location() << endl;
                    cout << "Player 3 Balance Before: " << P3P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout << "Player 3 Location After: " << P3P->location()<< endl;
                    cout << "Player 3 Balance After: " << P3P->balance() << endl<<endl;
                }else if(j==3){
                    cout << "Player 4 Location Before: " << P4P->location() << endl;
                    cout << "Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout << "Player 4 Location After: " << P4P->location()<< endl;
                    cout << "Player 4 Balance After: " << P4P->balance() << endl<<endl;
                }
            } else if (Card *test = dynamic_cast< AdvanceToNearest * >( DrawnCard )) {
                if(j==0) {
                    cout << "Player 1 Location Before: " << P1P->location() << endl;
                    cout << "Player 1 Balance Before: " << P1P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout << "Player 1 Location After: " << P1P->location()<< endl;
                    cout << "Player 1 Balance After: " << P1P->balance() << endl<<endl;
                }else if(j==1){
                    cout << "Player 2 Location Before: " << P2P->location() << endl;
                    cout << "Player 2 Balance Before: " << P2P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout << "Player 2 Location After: " << P2P->location()<< endl;
                    cout << "Player 2 Balance After: " << P2P->balance() << endl<<endl;
                }else if(j==2){
                    cout << "Player 3 Location Before: " << P3P->location() << endl;
                    cout << "Player 3 Balance Before: " << P3P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout << "Player 3 Location After: " << P3P->location()<< endl;
                    cout << "Player 3 Balance After: " << P3P->balance() << endl<<endl;
                }else if(j==3){
                    cout << "Player 4 Location Before: " << P4P->location() << endl;
                    cout << "Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout << "Player 4 Location After: " << P4P->location()<< endl;
                    cout << "Player 4 Balance After: " << P4P->balance() << endl<<endl;
                }
            } else if (Card *test = dynamic_cast< MoveBack * >( DrawnCard )) {
                if(j==0) {
                    cout << "Player 1 Location Before: " << P1P->location() << endl;
                    cout << "Player 1 Balance Before: " << P1P->balance() << endl;
                    DrawnCard->applyEffect(P1P, Players);
                    cout << "Player 1 Location After: " << P1P->location()<< endl;
                    cout << "Player 1 Balance After: " << P1P->balance() << endl<<endl;
                }else if(j==1){
                    cout << "Player 2 Location Before: " << P2P->location() << endl;
                    cout << "Player 2 Balance Before: " << P2P->balance() << endl;
                    DrawnCard->applyEffect(P2P, Players);
                    cout << "Player 2 Location After: " << P2P->location()<< endl;
                    cout << "Player 2 Balance After: " << P2P->balance() << endl<<endl;
                }else if(j==2){
                    cout << "Player 3 Location Before: " << P3P->location() << endl;
                    cout << "Player 3 Balance Before: " << P3P->balance() << endl;
                    DrawnCard->applyEffect(P3P, Players);
                    cout << "Player 3 Location After: " << P3P->location()<< endl;
                    cout << "Player 3 Balance After: " << P3P->balance() << endl<<endl;
                }else if(j==3){
                    cout << "Player 4 Location Before: " << P4P->location() << endl;
                    cout << "Player 4 Balance Before: " << P4P->balance() << endl;
                    DrawnCard->applyEffect(P4P, Players);
                    cout << "Player 4 Location After: " << P4P->location()<< endl;
                    cout << "Player 4 Balance After: " << P4P->balance() << endl<<endl;
                }
            }



        }

    }





    delete CP;
    delete CCP;

    return 0;

}