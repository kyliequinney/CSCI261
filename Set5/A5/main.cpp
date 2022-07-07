/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Kylie Quinney
 * Resources used : none
 *
 * code the game left right center using a doubly circularly linked list as well as casses for Player, Die, and Game
 */
#include <iostream>
#include <string>
#include <ctime>
#include "DoublyNode.hpp"
#include "LeftRightCenter.hpp"

using namespace std;

int main() {

    srand(time(0));
    //create game
    Game <Player> myGame ;
    //create die (takes argument of how many times to roll)
    Die myDie;

    //ask user how many players in the game
    cout << "How many players are playing? " << endl;
    int numPlayers;
    cin >> numPlayers;
    
    //create a player object for each player and a node in the linked list for each player
    for(int i = 1; i < numPlayers+1; i++){
        Player player;
        player.setPlayerNum(i);
        myGame.pushBack(player);
    }

    myGame.leftRightCenter();

    return 0;
}