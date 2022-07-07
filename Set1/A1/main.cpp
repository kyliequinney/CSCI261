/* CSCI 261: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Kylie Quinney
 * Resources used: class slides, overstack for setting up rand w/ ctime and how to use string library
 *
 * Description: user competes against the computer (using random computer output) in rock paper scissors
 */

#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    char again;
    again = 'Y';

    int wins;
    int losses;
    int ties;

    wins = 0;
    losses = 0;
    ties = 0;

do {
    //ask user for their choice
    
    cout <<"Can you beat the computer in Rock, paper, Scissors? Enter R, P, or S to find out!" << endl;
    char userChoice;
    cin >> userChoice;


    // Display the users choice based on their input

    if (userChoice == 'R') {
        cout << "Player choice: Rock" << endl;
    }
    
    if (userChoice == 'P') {
        cout<< "Player choice: Paper" << endl;
    }

    if (userChoice == 'S') {
        cout<< "Player choice: Scissors" << endl;
    }


    //use the time to 'randomly' decide on the computer's choice

    srand(time(0));
    int compChoice;
    compChoice = rand() % 2 + 1;


    //output Rock, Paper, or Scissors depending on if the computer chooses 1, 2, or 3, respectively

    if (compChoice == 1) {
        cout << "Computer choice: Rock" << endl;
    }

    if (compChoice == 2) {
        cout<< "Computer choice: Paper" << endl;
    }

    if (compChoice == 3) {
        cout<< "Computer choice: Scissors" << endl;
    }


    //Declare a winner
    if (userChoice == 'R') {

        if (compChoice == 1) {
            cout << "There was a tie." << endl;
            ties++;
        }

        if (compChoice == 2) {
            cout << "Computer wins!" << endl;
            losses++;
        }

        if (compChoice == 3) {
            cout << "You win!" << endl;
            wins++;
        }

    }

    else if (userChoice == 'P') {
        if (compChoice == 1) {
            cout << "You win!" << endl;
            wins++;
        }

        if (compChoice == 2) {
            cout << "There was a tie." << endl;
            ties++;
        }

        if (compChoice == 3) {
            cout << "Computer wins!" << endl;
            losses++;
        }
    }

    else if (userChoice == 'S') {
        if (compChoice == 1) {
            cout << "Computer Wins!" << endl;
            losses++;
        }

        if (compChoice == 2) {
            cout << "You win!" << endl;
            wins++;
        }

        if (compChoice == 3) {
            cout << "There was a tie." << endl;
            ties++;
        }
    }

    // Ask user if they would like to continue playing
    cout << "Would you like to play again? (Y or N)" << endl;
    cin >> again;

} while (again == 'Y');

    // Output stats for games played
    cout << "Game Over" << endl;
    cout << "Wins: " << wins << endl;
    cout << "Losses: " << losses << endl;
    cout << "Ties: " << ties << endl;

  return 0; 
}