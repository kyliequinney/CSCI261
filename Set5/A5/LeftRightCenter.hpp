/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Kylie Quinney
 * Resources used : none
 *
 * code the game left right center using a doubly circularly linked list as well as casses for Player, Die, and Game
 */
#ifndef LEFTRIGHTCENTER_HPP
#define LEFTRIGHTCENTER_HPP

#include <ctime>
#include <vector>
#include "DoublyNode.hpp"

template <typename T>
class Game {

    public:
    
        Game();

        Node <T> *pHead;

        Node <T> *pTail;

        unsigned int sizeList; 

        Game(const Game& OTHER);

        ~Game();

        int getNumPlayers();

        void pushBack (const T VALUE);

        void leftRightCenter();

        void setCenterChips(int numChips);

        int getCenterChips();

    private:
        int numPlayers;
        int turn;
        int centerChips;
};

class Player {

    public:
        Player();
        void setPlayerNum(int num);
        void setNumChips(int num);
        int getPlayerNum();
        int getNumChips();
        int getCenterChips();
        void giveChipToPlayer();
        void giveChipToCenter();

    private:
        int playerNum;
        int numChips;
};

class Die {
    public:
        Die();
        void dieRoll(Player& player);
        vector <int> getMyRolls();

    private:
        int roll; //num from 0-7
        vector <int> myRolls;
};


//DIE FUNCTIONS

//constructor
Die :: Die() {
    roll = 0;
}

//rolls die for has many chips as the player has and 3 times if player has three or more chips
void Die :: dieRoll(Player& player){
    myRolls.clear();
    int chips = player.getNumChips();
    if (chips > 3) chips = 3;
    for (int i = 0; i < chips; i++){
        roll = 0 + (rand() % 8);
        myRolls.push_back(roll);
    }
    return;
}

//vector with the rolls from diRoll function
vector <int> Die :: getMyRolls(){
    return myRolls;
}


//PLAYER FUNCTIONS

//constructor
Player :: Player(){
    numChips = 3;
    playerNum= 0;
}

//setter for players num (to know which player is which)
void Player :: setPlayerNum(int num){
    playerNum = num;
}

//setter for number of chips the player has
void Player :: setNumChips (int num){
    numChips = num;
}

//getter for numChips
int Player :: getNumChips(){
    return numChips;
}

//getter for playerNum
int Player :: getPlayerNum(){
    return playerNum;
}

//subtract one chip from player
void Player :: giveChipToPlayer(){
    setNumChips(numChips-1);
}

//takes away chip from player (chip is added to center in leftrightcenter function)
void Player :: giveChipToCenter(){
    setNumChips(numChips-1);
}

//GAME FUNCTIONS

//constructor sets head and tail to null and size to 0
template <typename T>
Game <T>:: Game(){
    pHead = nullptr;

    pTail = nullptr;

    sizeList = 0;
}

//adds node to end of list
template <typename T>
void Game <T>:: pushBack(const T VALUE) {
    Node<T> *pNode = new Node <T>;
    pNode -> value = VALUE;
    pNode -> pNext = nullptr;
    pNode -> pPrevious = nullptr;

    Node <T> *pCurrent = new Node <T>;

    pCurrent = pHead;


    if (pHead == nullptr){
        pHead = pNode;
        pTail = pHead;
        pHead -> pNext = pTail -> pNext = nullptr;
        pHead -> pPrevious = pTail -> pPrevious = nullptr;
    }

    else {
        pTail -> pNext = pNode;
        pNode -> pPrevious = pTail;
        pTail = pNode;
        pHead -> pPrevious = pTail;
        pTail -> pNext = pHead;
    }
    ++ numPlayers;
}

//Destructor that deallocates the entire list, sets the head & tail pointers to be null, sets the size to be zero
template <typename T>
Game <T>:: ~Game(){
    Node<T> *pCurrent= pHead;
    Node<T> *pNext2 = pHead;

    for(int i = 0; i < numPlayers; i++) {
        pNext2 = pCurrent -> pNext;
        delete pCurrent;
        pCurrent = pNext2;
    }

    pHead = nullptr;
    pTail = nullptr;
    numPlayers = 0;
}

//returns the current size of the list aka number of players
template <typename T>
int Game <T> :: getNumPlayers() {
    return numPlayers;
}

//setter for number of chips in the center pile
template <typename T>
void Game <T> :: setCenterChips(int numChips){
    centerChips = numChips;
}

//getter for number of chips in the center pile
template <typename T> 
int Game <T> :: getCenterChips(){
    return centerChips;
}

//all game logic
template <typename T>
void Game <T> :: leftRightCenter() {
    //start at player 1
    Node <T> *pNode = pHead;
    Node <T> *pNodeLeft = pHead -> pNext;
    Node <T> *pNodeRight = pHead -> pPrevious;
    Die myDie;

    //count is to see when all players but one are out of chips to end game and declare winner
    int count = 0;
    int skipCount = 0;
    int chips;

    while(count < (numPlayers-1)){
    for (int i = 1 ; i < numPlayers+1; i++){
        Player& player = pNode -> value;
        Player& playerLeft = pNodeLeft -> value; 
        Player& playerRight = pNodeRight -> value;

        cout << "Player " << player.getPlayerNum() << " has " << player.getNumChips() << " chips left" << endl;
        if (player.getNumChips() > 3){
             chips = 3;
        }
        else chips = player.getNumChips();

        cout << "Rolling " << chips << " dice" << endl;
        myDie.dieRoll(player);
        vector <int> myRolls = myDie.getMyRolls();
        for (int j = 0; j < chips ; j++){
            // 0-2 keep chip
            if (myRolls[j] == 0 || myRolls[j] == 1 || myRolls[j] == 2){
                cout << "Rolled a " << myRolls[j] << " - keeping chip - Player" <<  player.getPlayerNum() << " has " << player.getNumChips() << " chips" << endl;
            }
            //3 pass left (forward)
            if (myRolls[j] == 3){
                player.giveChipToPlayer();
                playerLeft.setNumChips((playerLeft.getNumChips())+1);
                cout << "Rolled a " << myRolls[j] << " - give left - Player" << player.getPlayerNum() << " has " << player.getNumChips() << " chips - Player" << playerLeft.getPlayerNum() << " has " << playerLeft.getNumChips() << " chips" << endl; 
            }
            //4 pass right (backwards)
            if (myRolls[j] == 4){
                player.giveChipToPlayer();
                playerRight.setNumChips((playerRight.getNumChips())+1);
                cout << "Rolled a " << myRolls[j] << " - give right - Player" << player.getPlayerNum() << " has " << player.getNumChips() << " chips - Player" << playerRight.getPlayerNum() << " has " << playerRight.getNumChips() << " chips" << endl; 
            }
            //5 give chip to center
            if (myRolls[j] == 5){
                player.giveChipToCenter();
                centerChips++;
                cout << "Rolled a " << myRolls[j] << " - give center - Center has " << centerChips << " - Player" << player.getPlayerNum() << " has " << player.getNumChips() << " chips" <<endl;
            }
            //6 reverse direction of play
            if (myRolls[j] == 6){
                //HOW LOL
                cout << "Rolled a 6" << endl;
            }
            //7 skip a player
            if (myRolls[j] == 7){
                skipCount++;
                cout << "Rolled a 7 - skip! Skipping " << skipCount << " a player"<< endl;
            }
        }

        //if players were skipped during turn
        if (skipCount != 0){
            for(int k = 0; k < skipCount; k++){
                pNode = pNode -> pNext;
                pNodeLeft = pNodeLeft -> pNext;
                pNodeRight = pNodeRight -> pNext;
                i++;
            }
        }

        //checks if player is out of chips and if all but one player is out of chips it ends the game
        if (player.getNumChips() == 0){
            count++;

            if ( count == (numPlayers-1)){
                Node <T> *pNode = pHead;
                for (int l = 0; l < numPlayers; l++){
                    Player& player = pNode -> value;
                    if (player.getNumChips() != 0){
                        cout << "Player" << player.getPlayerNum() << " wins with " << player.getNumChips() << " chip(s)!" << endl;
                        return;
                    }
                    else{ 
                        pNode = pNode -> pNext;
                    }
                }
            }
        }
        else{
            count = 0;
        }

        //move to next player and reset skipCount
        pNode = pNode -> pNext;
        pNodeLeft = pNodeLeft -> pNext;
        pNodeRight = pNodeRight -> pNext;
        skipCount = 0;
    }
}
}
#endif