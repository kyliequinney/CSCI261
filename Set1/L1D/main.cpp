/* CSCI 261 Lab 1D : Na na na
 *
 * Author: Kylie Quinney
 * Resources used: slides from class
 * Description: Use three different loops to print "na" 13 times, then print "batman"
 */

#include <iostream>
using namespace std;
 int main() {
     int count;
     count = 0;
     while (count != 13) //while loop
     {
         cout <<"na"<< endl;
         ++count;
     }
     cout <<"batman"<< endl;

     int count2;
     count2 = 0;
     do //do-while loop
     { 
        cout <<"na"<< endl;
         ++count2;
     } while (count2 != 13) ;
     cout <<"batman"<< endl;

     int count3;
     for ( count3 = 0; count3 < 13; ++count3 ) //for loop
     {
         cout <<"na"<< endl;
     }
     cout <<"batman"<< endl;
     return 0;
 }