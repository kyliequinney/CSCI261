/* CSCI 261: Lab 2B: Procedural Programming with Functions
 *
 * Author: Kylie Quinney
 * Resources used: TA help hours on 2/7/22
 *
 * Description: create two functions for outputting 10 random integers and 10 random floats within a given range
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;


//create function that prints 10 random values w/in min and max

/**
 * @brief prints 10 random ints between min and max
 * 
 * @param min 
 * @param max 
 */
void generate_random_integer(int min, int max) {
    int count;
    count = 0;

    while(count < 10) {

        cout << rand() % (max - min + 1) + min << endl;
        count ++;
    }
    return;
}

/**
 * @brief prints 10 random floats between min and max
 * 
 * @param min 
 * @param max 
 */
void generate_random_float(float min, float max) {
    int count;
    count = 0;

    while(count < 10) {
        cout << setprecision(4) << min + static_cast <float> (rand()) /(static_cast <float> (RAND_MAX/(max-min))) << endl;
        count++;
    }
    return;
}

int main() {

    srand (time(0));
    rand();

    cout << "Please enter a minimum value: " << endl;
    int userMin;
    cin >> userMin ;

    cout << "Please enter a maximum value: " << endl;
    int userMax;
    cin >> userMax;
    

    //use function to print 10 integers w/in user bounds
    cout << "10 random integers between " << userMin << " and " << userMax << " are: " << endl;

    generate_random_integer (userMin , userMax);

    cout << "10 random floats between " << userMin << " and " << userMax << " are: " << endl;

    generate_random_float (userMin, userMax);


    return 0;
}