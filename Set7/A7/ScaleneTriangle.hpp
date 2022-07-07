#ifndef SCALENETRIANGLE_HPP
#define SCALENETRIANGLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Triangle.hpp"

class ScaleneTriangle: public Triangle {
    public:
        bool setCoordinates(LinkedList <float> myCoords); // compute length of each side (return 1 if form triangle, 0 if not)
    private:
};

bool ScaleneTriangle :: setCoordinates(LinkedList <float> myCoords){
    //distance formula : sqrt[(x2-x1)^2 + (y2-y1)^2]
    Node <float> *xOne = myCoords.pHead;//xOne
    Node <float> *yOne = myCoords.pHead -> pNext;//yOne
    Node <float> *pOne = yOne -> pNext; // xTwo
    Node <float> *pTwo = pOne -> pNext; // yTwo

    float squareX = ((pOne -> value) - (xOne -> value))*((pOne -> value) - (xOne -> value));
    float squareY =  ((pTwo -> value) - (yOne -> value))*((pTwo -> value) - (yOne -> value));
    float sideOne = sqrt(squareX+squareY);

    pOne = pTwo -> pNext; //xThree
    pTwo = pOne -> pNext; //yThree

    squareX = ((pOne -> value) - (xOne -> value))*((pOne -> value) - (xOne -> value));
    squareY =  ((pTwo -> value) - (yOne -> value))*((pTwo -> value) - (yOne -> value));
    float sideTwo = sqrt(squareX+squareY);

    xOne = yOne -> pNext; //xTwo
    yOne = xOne -> pNext; //yTwo

    squareX = ((pOne -> value) - (xOne -> value))*((pOne -> value) - (xOne -> value));
    squareY =  ((pTwo -> value) - (yOne -> value))*((pTwo -> value) - (yOne -> value));
    float sideThree = sqrt(squareX+squareY);

    if(sideOne != 0 && sideTwo != 0 && sideThree != 0){
        if((sideOne + sideTwo) > sideThree){
            Triangle :: coords = myCoords;
            return 1;
        }
    }
    return 0;
}
#endif