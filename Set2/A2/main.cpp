/* CSCI 261: A2: PPM Image Editor
 *
 * Author: Kylie Quinney
 * Resources used: geeks4geeks for how to use stringstream
 *
 * Description: use simple image processing to manipulate PPM images
 * 
 * I'm just gonna warn you it takes like 15 minutes to fully write the new ppm file
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ppm_functions.h"
using namespace std;

int main() {
    //initialize choice 
    string userChoice = "4";
    //string choice;
    print_file_options(userChoice);
    
    //set variable choice to be the string that the user chose and add file ext on it
    if (userChoice == "1") {
        userChoice = "brick";
    }

    if (userChoice == "2") {
        userChoice = "wallpaper";
    }

    if (userChoice == "3") {
        userChoice == "private";
    }

    string choice;
    string ext = ".ppm";
    choice= userChoice + ext;

    //open the image
    ifstream input(choice);

    //check if file was able to open
    if(input.fail()) {
        cerr << "Error opening input file" ;
        return -1;
    }

    string line;
    string dimensions;
    string maxVal;
    string fileType;

    //see if first line is P3
    if (input.is_open()) {

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

    //Ask user what they want to do with the image
    int editChoice;
    print_operation_options(editChoice);

    ofstream output;
    string outFileName;

    //grayscale
    if (editChoice == 1) {
        string newExt = "_grayscale.ppm";
        outFileName = userChoice + newExt;

        output.open(outFileName, ios :: out);
        output << fileType << endl;
        output << dimensions << endl;
        output << maxVal << endl;

        cout << "Opening" << choice << "file" << endl;
        cout << "Writing" << outFileName << "file" << endl;

        while (getline(input, line)){
            stringstream x;
            x << line; int r ; x >> r;
            x.clear();
            getline(input, line);
            x << line; int g ; x >> g;
            x.clear();
            getline(input, line);
            x << line; int b ; x >> b;
            x.clear();
            int gray = ((0.2989*r) + (0.5870*g) + (0.1140*b))/3;
            //string num = to_string(gray)+to_string(gray)+to_string(gray);
            output << gray << endl;
            output << gray << endl;
            output << gray << endl;
        }
        
    }

    //inverted
    if (editChoice == 2) {
        string newExt = "_inverted.ppm";
        outFileName = userChoice + newExt;

        output.open(outFileName, ios :: out);
        output << fileType << endl;
        output << dimensions << endl;
        output << maxVal << endl;

        cout << "Opening" << choice << "file" << endl;
        cout << "Writing" << outFileName << "file" << endl;

        string zero = "0";
        while (getline(input, line)){
            stringstream x;
            x << line ; int rgb; x >> rgb;
            rgb = 255 - rgb;
            output << rgb << endl;
        }

    }
    }

       

    input.close();
    return 0;
}
