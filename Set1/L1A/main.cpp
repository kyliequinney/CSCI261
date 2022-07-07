/* CSCI 261 Lab 1A : First coding assignment
 *
 * Author: Kylie Quinney
 * Resources used: Class slides
 *"Hello World" and calculate current (volts/resistance) and stress (force/area)
 */


#include <iostream> // For cin, cout, etc.
using namespace std;
int main() {
  cout << "Hello World!" << endl; //print "Hello World!"

  int resistance, volts, current; //receive input for resistance and volts then calculate current
    cout << "Enter the resistance: " ;
    cin >> resistance;

    cout << "Enter the volts: " ;
    cin >> volts;

    current = (volts/resistance);
  

  cout << "The current is: " << current << endl; //print current

  int force, area, stress; //receive inputs for force and area to calulate stress
    cout << "Enter the force: " ;
    cin >> force;

    cout << "Enter the area: " ;
    cin >> area;

    stress= (force/area);
  
  cout << "The stress is: " << stress << endl; //print stress
  
  return 0; 
}
