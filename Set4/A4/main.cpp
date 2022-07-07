/* CSCI 261: A4 - Abstract Lists: Wavefront OBJ File Validator
 *
 * Author: Kylie Quinney
 * Resources used: none
 *
 * read in a simplified Wavefront OBJ file, validate if it would correctly form a model, and print out the data that makes up the model
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Node.hpp"
#include "Functions.hpp"
using namespace std;

int main() {
    cout << "Enter the name of the file you wish to open: " << endl;
    string fileName;
    cin >> fileName;

    ifstream input(fileName);

    //check if file failed
    if (input.fail()) {
        cerr << "Error opening input file" ;
        return -1;
    }

    //set up nodes for the three linked lists
    string line;
    Node <string> *pComment = new Node <string>;
    Node <string> *pCNext = pComment;

    Node <string> *pVertices = new Node <string>;
    Node <string> *pVNext = pVertices;

    Node <string> *pFaces = new Node <string>;
    Node <string> *pFNext = pFaces;
    
    //start counters for how many of each kind there are
    int cCount = 0;
    int vCount = 0;
    int fCount = 0;

    //if file is open properly
    if (input.is_open()) {
        //keep getting lines until we have gone trhough entire file
        while (getline(input, line)){
            //if it is a comment
            if (line[0] == '#'){
                pCNext -> value = line.substr(2,line.length());
                //cout << pCNext -> value << endl;
                Node <string> *pNode = new Node <string>;
                pCNext -> pNext = pNode;
                pCNext = pCNext -> pNext;
                cCount ++;
                continue;
            }

            //if it is a vertex
            if (line[0] == 'v'){
                string vString = "";
                vString.append("(");
                for (int i = 2; i< line.length(); i++){
                    if (line[i] == ' '){
                        if (i == 2 || line[i-1] == ' '){
                            vString.append("");
                        }
                        else {vString.append(", ");}
                    }
                    else{
                        vString.append(line,i,1);
                    }
                }
                vString.append(")");
                cout << vString << endl;
                pVNext -> value = vString;
                //pVNext -> value = line.substr(2,line.length());
                //cout << pVNext -> value << endl;
                Node <string> *pNode = new Node <string>;
                pVNext -> pNext = pNode;
                pVNext = pVNext -> pNext;
                vCount++;
                continue;
            }

            //if it is a face
            if (line[0] == 'f'){
                pFNext -> value = line.substr(2,line.length());
                cout << pFNext -> value << endl;
                Node <string> *pNode = new Node <string>;
                pFNext -> pNext = pNode;
                pFNext = pFNext -> pNext;
                fCount++;
                continue;
            }
        }

        //display counts of all information read in
        cout << "Read in: " << endl;
        cout << cCount << " comments" << endl;
        cout << vCount << " vertices" << endl;
        cout << fCount << " faces" << endl;
    }
    //validate faces
    //cout vertices for testing

    //ask user what they want to do
    int choice = userPrintChoice();

    //print contents of the lst they ask for
    if (choice == 1){
        printContents( "Comment", cCount, pComment);
    }
    if(choice == 2){
        printContents( "Vertex", vCount, pVertices);
    }
    if(choice == 3){
        //this was an attempt to print the faces properly, as you can see it was awful
        /*Node <string> *pfNode = new Node <string>;
        pfNode = pFaces;
        while( pfNode != nullptr){
            string fString = "";
            fString = pfNode -> value;
            for (int i = 0; i < fString.length(); i++) {
                if (fString[i] != ' '){
                    string fString2 = getVertices(fString[i], pVertices);
                    string vString = "";
                    vString.append("(");
                    for (int i = 0; i< fString2.length(); i++){
                        if (line[i] == ' '){
                            if (i == 2 || line[i-1] == ' '){
                                vString.append("");
                            }
                            else {vString.append(", ");}
                        }
                        else{
                            vString.append(line,i,1);
                        }
                        vString.append(")");
                        cout << vString << endl;
                    }
                }
            }
        }*/
        printContents( "Faces", fCount, pFaces);

    }

    //end program if user chooses to do so
    if(choice == 4){
        cout << "Goodbye!" << endl;
        exit;
    }

    return 0;
}