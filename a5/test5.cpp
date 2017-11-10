/**
 * Test file for Assignment 5, depending on how you did stuff different than me this may
 * vary a little bit, but hopefully it all works out.  Let me know if there are issues
 * with the file.
 * @author Matthew Hickey, 2017
**/

#include <iostream>
#include "Game.h" // Also includes Bank and Dice
#include "Player.h" // Also includes Wallet

using namespace std;

int main(int argc, char const *argv[]) {

    // seed for random number generator
    srand(time(0));

    // Create a new game of Monopoly.
    Game* Monopoly = Game::Create(4);

    // Get a vector of all players in the game.
    vector<Player*>& monopolyPlayers = Monopoly->getPlayers();

    // Check the token type and position of each player:
    int i = 1;
    for (Player* p : monopolyPlayers) {
        cout << "Player " << i << " is the " << p->getToken() <<
            ". They are currently at position " << p->getLocation() << endl;
        i++;
    }

    cout << endl;

    // Check the Dice functionality:
    Dice* gameDice = Monopoly->getDice();
    gameDice->roll();
    cout << "Player has rolled a " << gameDice->roll() << endl;
    cout << "Did the Player roll doubles? 1 means yes, 0 means no:\n" << gameDice->isDoubles() << endl;

    cout << endl;

    // Set player position according to dice roll
    monopolyPlayers[0]->setLocation(monopolyPlayers[0]->getLocation() + gameDice->roll());
    cout << monopolyPlayers[0]->getToken() << " has moved to " << monopolyPlayers[0]->getLocation() << " by rolling the dice (separate from dice test above)." << endl;

    cout << endl;




    // Delete all players from the heap
    Monopoly->gameOver();

    // monopolyPlayers should be empty
    if (monopolyPlayers.empty()) {
        cout << "players have been deleted." << endl;
    } else {
        for(Player* p : monopolyPlayers) {
            cout << p->getToken() << endl;
        }
    }

    // Delete the game object
    delete Monopoly;

    //! End of test code.
    return 0;
}
