/* CSCI 261: Assignment 5: A5 - Wild Left-Center-Right Simulation
 *
 * Author: Kylie Quinney
 * Resources used : none
 *
 * code the game left right center using a doubly circularly linked list as well as casses for Player, Die, and Game
 */
 
1) My Player held the amount of chips for each object as well as the objects identification number to keep track of which player was which.
The class included function for getting and setting each variable as well as functions specific to certain tasks (like giving a chip to another player)

2) My game kept track of how many chips were in the center pile, numPlayers, and turns taken.
The game class is where the doubly circularly linked list was created (templated) and where all game logic was kept (LeftRightCenter() function)

3) The functions made it easier to move through the game code and allowed me to access the components of classes, they also allowed me to simplify main
The classes (specifically player and game) allowed me to make an identitiy for each player object that I could manage seperately as the game goes on.
Getters and setters were made for each variable in each class, and the Die and Player objects were used throughut the Game's LeftRightCenter() function as well as their getters and setters.