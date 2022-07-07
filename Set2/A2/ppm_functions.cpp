/* CSCI 261: A2 function definitions
 *
 * Author: Kylie Quinney
 * Resources used: none
 *
 * Description: define all functions to be used in A2 main.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

/**
 * @brief Prints the options menu for which file to input
 * 
 * @param userChoice 
 * 
 * @return int 
 */
int print_file_options( string& userChoice){
    do {
        //prompt user for image choice
        cout << "Which image would you like to load? \n 1. Brick \n 2. Wallpaper \n 3. Private" << endl;
        cout << "Enter 1, 2, or 3: " << endl;

        cin >> userChoice;

            if (userChoice != "1" && userChoice != "2" && userChoice != "3" ) {
                cout << "invalid input" << endl;
            }

    } while (userChoice != "1" && userChoice != "2" && userChoice != "3");
    return 0;
}

/**
 * @brief Prints the options menu for which file processing to perform
 * @param editChoice
 * @return int 
 */
int print_operation_options(int& editChoice) {
    cout << "How would you like to edit the image? \n 1) Convert to grayscale \n 2) Invert the colors" << endl;
    //int editChoice;
    cin >> editChoice;
    return 0;
}

/*int read_header_information(ifstream input, string line, string& dimensions, string& maxVal, string& fileType){
    //if (input.is_open()) {
    string line;
    getline(input, line);
        string fileType= line;
        if (line != "P3"){
            cout << "Incorrect file type" << endl;
            exit(1);
        }

    //read in width, height, and max value
    getline(input,line);
        string dimensions = line;
    getline(input, line);
        string maxVal = line;
    return 0;
}
*/