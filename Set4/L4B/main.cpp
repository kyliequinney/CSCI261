/* CSCI 261: Lab 4B: Linked List Operations
 *
 * Author: Kylie Quinney
 * Resources used: class slides,
 *
 * Description: implement functions in linked_list_tests so that all tests are passed
 */
#include <iostream>
using namespace std;

#include "test_suite.h"

int main() {

    cout << "Testing your functions..." << endl << endl;
    if( run_all_tests() ) {
        cout << "ALL TESTS PASSED!" << endl;
    } else {
        cout << "Not all tests are passing, errors remain..." << endl;
    }

    return 0;
}