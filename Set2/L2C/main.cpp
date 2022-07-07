/* CSCI 261 Lab 2C : Coordinate Converter
 *
 * Author: Kylie Quinney
 * Resources used: TA help hours 2/7/22
 * Purpose: Use pass-by-value and pass-by-reference to 'return' two values from a single function
 */

#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief convert polar coords to cartesian
 * 
 * @param radius 
 * @param angle 
 * @return int 
 */

void polar_to_cartesian (double radius, double angle, double& xCoord, double& yCoord) { 
    
    xCoord = radius * cos(angle);
    yCoord = radius * sin(angle);

    return ;
}

/**
 * @brief convert cartesian coors to polar
 * 
 * @param xCoord 
 * @param yCoord 
 * @return int 
 */

void cartesian_to_polar (double xCoord, double yCoord, double& radius, double& angle) {

    radius = sqrt (( xCoord*xCoord ) + ( yCoord*yCoord ));
    angle = atan(yCoord/xCoord);
    
    return ;
}

int main() {

    //ask user which conversion to make
    cout << "1: (r, theta) -> (x,y) \"2: (x,y) -> (r,theta)" << endl ;
    int choice ;
    cin >> choice ;

    //if polar to cartesian

    if (choice == 1) {
        double r , theta, x, y;
        cout << "Enter the radius: " << endl;
        cin >> r;
        cout << "Enter the theta: " << endl;
        cin >> theta;

        polar_to_cartesian (r , theta, x, y);

        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
    }

    //if cartesian to polar
    if (choice == 2) {
        double r, theta, x, y;

        cout << "Enter the x coordinate: " << endl;
        cin >> x;

        cout << "Enter the y coordinate: " << endl;
        cin >> y;

        cartesian_to_polar (x, y, r, theta);

        cout << "Radius = " << r << endl;
        cout << "Theta = " << theta << endl;

    }
    
}