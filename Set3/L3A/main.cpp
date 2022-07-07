/* CSCI 261: Lab 3A: Array Min/Max
 *
 * Author: Kylie Quinney
 * Resources used: class slides, stack overflow for how to put a new line in a print statement bc I somehow forgot
 *
 * Description: Prompt user for up to 15 values that are tobe store din an array
 */

#include <iostream>
#include <vector>
using namespace std;

int main () {

    //initialize array nums 
    int nums[15];
    int userNum = 1;

    //prompt user to enter the data
    cout << "Enter up to 15 non-zero numbers. Enter zero to signal the end of data or enter all 15 items: " << endl;
    
    int count = 1;
    while (count <= 15 && userNum != 0) {
        cout << "Number " << count << ": " << endl;
        cin >> userNum;
        nums[count-1] = userNum;
        count++;
    }

    cout << "The numbers are: ";
    //print the contents of the array
    for (int i = 0; i <= (count-3); i++) {
        cout << nums[i] << ' ';
    }

    int largestNum = nums[0];
    int smallestNum = nums[0];

    //find largestNum 
    for (int i = 0; i <= (count-3); i++){
        if (largestNum < nums[i]){
            largestNum = nums[i];
        }
        else 
            continue;
    }

    //find smallestNum
    for (int i = 0; i <= (count-3); i++){
        if (smallestNum > nums[i]) {
            smallestNum = nums[i];
        }
        else
            continue;
    }

    //print largest and smallest 
    cout << "\nThe maximum is: " << largestNum << endl;
    cout << "The minimum is: " << smallestNum << endl;

    return 0;
}

