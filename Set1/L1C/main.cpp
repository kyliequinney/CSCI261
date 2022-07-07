/* CSCI 261 Lab 1C : Random Generation and Classification
 *
 * Author: Kylie Quinney
 * Resources used: Melissa (TA) helped debug
 * Purpose: print random float in range of user input min and max 
 */


  #include <cstdlib>
  #include <iostream>
  #include <ctime>
  using namespace std;

int main() {
  //smallest value=0
  //largest value= RAND_MAX
  srand (time(0));

  int x; //establishing min
    cout << "Enter a minimum value: " ;
    cin >> x ;

  int y; //establishing max
    cout << "Enter your maximum value: " ;
    cin >> y ;

  //float randomNum = rand() / (double)RAND_MAX * (y-x) + x; //returning random num between given min and max       
    cout << "A random value is: " << rand() % y + x << endl; 

  return 0;
}
