/* CSCI 261: Function Prototypes in Separate Files
 *
 * Author: Kylie Quinney
 *
 *    This program illustrates a variety of common errors.
 *    Fix the errors in each section.

Copyright 2022 Dr. Jeffrey Paone

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

 */

#include <iostream>
#include "calculator_functions.h"
using namespace std;

/* to add breakpoint
gdb b in calulculator_functions.cpp : (line #)
*/

//Take out all function def, they are included in calculator_functions.h and .cpp


/**
 * @brief main entry point to our program
 * 
 * @return int 0 for success
 */
int main() {
    cout << "Hello world" << endl;
    turn_calculator_on();
    return 0;
}