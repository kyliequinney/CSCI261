#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "LinkedList.hpp"
//#include "ScaleneTriangle.hpp"
//#include "EquilateralTriangle.hpp"
//#include "IsoscelesTriangle.hpp"
#include <vector>
#include <cmath>

class Triangle {
    public:
        Triangle(); //default constructor

        void setColor(sf :: Color color); //sets triangle color

        void draw(sf :: RenderTarget& window); //creates a convex shape, sets points for each coord, sets fill color, draws to window

        bool setCoordinates(LinkedList <float> myCoords); //accepts (x,y) coords for three vertices

    protected:
        int numVertices; //num of vertices making up triangle
        
        LinkedList <float> coords; //list of (x,y) coords

    private:
        sf :: Color triColor;

        sf :: ConvexShape tri;

};

Triangle :: Triangle(){
    triColor = sf :: Color :: White;
}

void Triangle :: setColor(sf :: Color color){
    triColor = color;
}

void Triangle :: draw(sf :: RenderTarget& window){
    Node <float> *pNode = coords.pHead;
    Node <float> *pNodeTwo = pNode -> pNext;
    tri.setPointCount(3);
    tri.setPoint(0, sf :: Vector2f((pNode-> value), (pNodeTwo -> value)));
//std :: cout << pNode -> value << " " << pNodeTwo -> value << "\n";
    pNode = pNodeTwo -> pNext;
    pNodeTwo = pNode -> pNext;
    tri.setPoint(1, sf :: Vector2f((pNode-> value), (pNodeTwo -> value)));
//std :: cout << pNode -> value << " " << pNodeTwo -> value << "\n";
    pNode = pNodeTwo -> pNext;
    pNodeTwo = pNode -> pNext;
    tri.setPoint(2, sf :: Vector2f((pNode-> value), (pNodeTwo -> value)));
//std :: cout << pNode -> value << " " << pNodeTwo -> value << "\n";
    tri.setFillColor(triColor);
    window.draw(tri);
}
#endif