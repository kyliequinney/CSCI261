/* CSCI 261: Lab 3B: Strings Test Suite
 *
 * Author: Kylie Quinney
 * Resources used: class slides,
 *
 * Description: Implement functions so that all tests in test_suite.cpp are passed
 */
#include <iostream>
#include <string>
#include <locale>
#include <algorithm>
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