/* CSCI261 Lab 6A - Multidimensional Data
 *
 * Resources used: Peer program with Brett Eckel, stack overflow for how to initialize a 2d vector
 *
 * Author: Kylie Quinney
 *
 * Description: begin making two-dimensional lists of data
 */

#include <iostream> 
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    //prompt user for file name
    cout << "Enter file name: " << endl;
    string fileName;
    cin >> fileName;

    ifstream input;
    input.open(fileName);

    //check for error opening file
    if(input.fail()){
        cerr << "Error opening input file" ;
        return -1;
    }

    string line;

    int num;

    if(input){
        input >> num;

        //create vector of size given in first line
        vector <vector<int>> myList(num, vector<int> (num));
        for (int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                input >> myList[i][j];
            }
        }

        //print out the table
        cout << "The table is: " << endl;
        for (int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                cout << myList[i][j] << " ";
            }
            cout << endl;
        }

        //find the minimum in the table
        cout << "The min is: " ;
        int min = myList[0][0];
        for (int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if (myList[i][j] < min){
                    min = myList[i][j];
                }
            }
        }
        cout << min << endl;

        //find the maximum in the table
        cout << "The max is: " ;
        int max = myList[0][0];
        for (int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
                if(myList[i][j] > max){
                    max = myList[i][j];
                }
            }
        }
        cout << max << endl;
    }

    //close the file
    input.close();

    return 0;
}