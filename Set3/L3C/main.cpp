/* CSCI 261: Lab 3C: Pointers
 *
 * Author: Kylie Quinney
 * Resources used: class slides
 *
 * Description: gain familiarity with pointers, adresses, and dynamic memory
 */

#include <iostream>
using namespace std;

int main () {
    //Declare an integer named iNum with initial value 9. Declare a double named dNum with initial value 14.25.
    int iNum = 9;
    double dNum = 14.25;

    //Declare two pointers to integers named pINum1 and pINum2. Declare a pointer to a double named pDNum.
    int *pINum1;
    int *pINum2;
    double *pDNum;

    //Assign the address of iNum to pINum1
    pINum1 = &iNum;

    //Output the address of iNum
    cout << "The address of iNum is: " << pINum1 << endl; 
    cout << "The address of Num (but done ~differently~) is: " << &iNum << endl;

    //Use pINum1 to display the contents of iNum
    cout << "The contents of iNum are: " << *pINum1 << endl;

    //Try to assign the address of dNum to pINum2
    /*pINum1 = &dNum;
    error: cannot convert 'double*' to 'int*' in assignment
    pINum1 = &dNum; */

    //Assign the address of dNum to pDNum
    pDNum = &dNum;

    //Output the address and then the contents of dNum (using pDNum)
    cout << "The address of dNum is: " << pDNum << endl;
    cout << "The contents of dNum are: " << *pDNum << endl;

    //Directly change the value of iNum to 7
    iNum = 7;

    //Use pINum1 to output the contents of iNum
    cout << "The contents of iNum are: " << *pINum1 << endl;

    //Assign pINum2 to have the same value as pINum1
    pINum2 = pINum1;

    //Output the address in pINum2
    cout << "The address of pINum2 is: " << pINum2 << endl;

    //Output the value pointed to by pINum2
    cout << "The value pointed to by pINum2 is: " << *pINum2 << endl;

    //Using pINum2, change the contents of iNum to 12
    *pINum2 = 12;

    //Output the contents of iNum three times, first using pINum1, then using pINum2, then iNum directly. In each case, identify what the user is seeing appropriately
    cout << "The contents of iNum are: " << *pINum1 << endl;
    cout << "The contents of iNum are: " << *pINum2 << endl;
    cout << "The contents of iNum are: " << iNum << endl;

    return 0;
}
