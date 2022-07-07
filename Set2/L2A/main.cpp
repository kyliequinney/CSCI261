/* CSCI 261: Lab 2A: The Secret Moosage
 *
 * Author: Kylie Quinney
 * Resources used: class slides, overstack for copying contents of a file to a new file
 *
 * Description: Decrypt the secretMessage.txt file using key in lab description
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//replaceAll replaces all occurances of 'from' to 'to'
void replaceAll(string &str, const string &from, const string &to);

int main() {

    //call input file input
    ifstream input;
    input.open("secretMessage.txt", ios :: in); //read mode
    
    //check for error opening input
    if(input.fail() ) {
    cerr << "Error opening input file";
    return -1;
    }

    //call new file output
    ofstream output;
    output.open("decipheredMessage.txt", ios :: out); //write mode
    
    //check for errors in opening new file
    if(output.fail() ) {
        cerr << "Error opening output file";
        return -1;
    }

    //write to the file
    string line;
    string tilde = "~";
    string replace = " ";

    if(input && output) {
        while(getline(input, line)) {
            //doesn't work, reads until something other than tilde shows then just moves to the next line
            size_t spot = line.find(tilde);
            if(spot != string::npos){
                replaceAll(line, tilde, replace);
            }

            output << line << "\n";
        }
        cout << "SUCCESS!" << endl;
    }

    //close file
    input.close();
    output.close(); 

    return 0;
}

/**
 * @brief Replaces all occurances of 'from' to 'to'
 * 
 * @param str 
 * @param from 
 * @param to 
 */
void replaceAll (string &str, const string &from, const string &to){
    size_t startPos = 0;
    while((startPos = str.find(from, startPos)) != string::npos){
        size_t endPos = startPos + from.length();
        str.replace(startPos, endPos, to);
        startPos += to.length();
    }
}