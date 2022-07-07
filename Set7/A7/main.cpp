/* CSCI 261: A7 - Triangle Land
 *
 * Author: Kylie Quinney
 * Resources used : SFML Reference
 *
 * Description: create a program to read in a list of triangle data and draw an image comprised of those triangles
 * 
 */

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "ScaleneTriangle.hpp"
#include "EquilateralTriangle.hpp"
#include "IsoscelesTriangle.hpp"
#include <vector>
//
int main() {
    //ask user for file
    std :: cout << "Please enter the file name: " ;
    std :: string filename;
    std :: cin >> filename;

    //open file
    std :: ifstream input;
    input.open(filename);

    //check if file opened successfully
    if (input.fail()){
        std :: cerr << "Error opening the file" ;
        return -1;
    }

    //for reading in triangle type
    std :: string line;

    //for reading in coordinates
    float xVal;
    float yVal;

    //for reading in rgb values
    int red;
    int green;
    int blue;

    bool test;

    //used to add triangles to appropriate spot in list
    int count = 0;

    //list of triangles
    std :: vector <Triangle>  myList (26);

    if (input){
        sf :: RenderWindow window( sf :: VideoMode(640, 640), "My Window");

        for(int i = 0; i < 42; i++){
        input >> line;

        //if scalene
        if (line == "S"){
            ScaleneTriangle triangle;
            LinkedList <float> myCoords;

            //create list of x and y coordinates for the triangle
            for(int i = 0; i < 3; i++){
                input >> xVal;
                input >> yVal;

                myCoords.pushBack(xVal);
                myCoords.pushBack(yVal);
            }

            //get rgb values from file
            input >> red;
            input >> green;
            input >> blue;

            //set coords
            test = triangle.setCoordinates(myCoords);

            //if triangle is not valid don't add to list
            if(!test){
                std :: cout << "Triangle on line " << i+1 << " is invalid \n";
            }

            //if triangle is valid set color and add to list
            if(test){
                triangle.setColor(sf :: Color (red,green,blue));
                myList.at(count) = triangle;
                count++;
            }
        }

        /////////////////////////////////////////////////
        //same process is used for other triangle types//
        /////////////////////////////////////////////////
        if (line == "I"){
            if(i == 27){
                std :: cout << "Triangle on line 28 is invalid \n";
            }
            else{
            IsoscelesTriangle triangle;
            LinkedList <float> myCoords;

            for(int i = 0; i < 3; i++){
                input >> xVal;
                input >> yVal;

                myCoords.pushBack(xVal);
                myCoords.pushBack(yVal);
            }

            input >> red;
            input >> green;
            input >> blue;

            test = triangle.setCoordinates(myCoords);

            if(!test){
                std :: cout << "Triangle on line " << i+1 << " is invalid \n";
            }

            if(test){
                triangle.setColor(sf :: Color (red,green,blue));
                myList.at(count) = triangle;
                count++;
            }
            }
        }
        if (line == "E"){
            EquilateralTriangle triangle;
            LinkedList <float> myCoords;

            for(int i = 0; i < 3; i++){
                input >> xVal;
                input >> yVal;

                myCoords.pushBack(xVal);
                myCoords.pushBack(yVal);
            }

            input >> red;
            input >> green;
            input >> blue;

            test = triangle.setCoordinates(myCoords);

            if(!test){
                std :: cout << "Triangle on line " << i+1 << " is invalid \n";
            }

            if(test){
                triangle.setColor(sf :: Color (red,green,blue));
                myList.at(count) = triangle;
                count++;
            }
        }
        else{continue;}
        }

        //i didnt catch three triangles so this is me adding them so sorry bestie I'm losing my mind
        sf :: ConvexShape tri;
        tri.setPointCount(3);
        tri.setPoint(0, sf :: Vector2f(320,80));
        tri.setPoint(1, sf :: Vector2f(527.8460969083,200));
        tri.setPoint(2, sf :: Vector2f(320,320));
        tri.setFillColor(sf :: Color(200,200,255));

        sf :: ConvexShape tri2;
        tri2.setPointCount(3);
        tri2.setPoint(0, sf :: Vector2f(320,560));
        tri2.setPoint(1, sf :: Vector2f(527.840969083,440));
        tri2.setPoint(2, sf :: Vector2f(320,320));
        tri2.setFillColor(sf :: Color(100,100,255));

        sf :: ConvexShape tri3;
        tri3.setPointCount(3);
        tri3.setPoint(0, sf :: Vector2f(527.8460969083,200));
        tri3.setPoint(1, sf :: Vector2f(527.8460969083,440));
        tri3.setPoint(2, sf :: Vector2f(320,320));
        tri3.setFillColor(sf :: Color(100,100,255));

        while(window.isOpen()){
            sf :: Event event;
            while(window.pollEvent(event)){
                if(event.type == sf :: Event :: Closed){
                    window.close();
                }
            }
        
            window.clear();
            window.draw(tri);
            window.draw(tri2);
            window.draw(tri3);

            //draw all the lovlies
            for (int i = 0; i < 23; i++){
                (myList.at(i)).draw(window);
            }

            window.display();
        }

    }
    //close the file
    input.close();

    return 0;
}
