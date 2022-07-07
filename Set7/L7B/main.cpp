/* CSCI 261: L7B - SFML Drawing
 *
 * Author: Kylie Quinney
 * Resources used : SFML reference for random questions on syntax/debugging
 *
 * Description: read in star data file, store in a list of objects, make modifications to the data, draw star map 
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Star.hpp"
#include <SFML/Graphics.hpp>

int main(){
    std :: ifstream input;
    input.open("stars.txt");

    //check if file opened
    if(input.fail()){
        std :: cerr << "Error opening the input file" ;
        return -1;
    }

    //float num;
    float trash;

    if(input){

        std :: vector <std :: vector<float>> myList( 3546, std :: vector <float>(3));

        //read in all needed values into a 2D list
        for(int i = 0; i < 3546; i++){
            for(int j = 0; j < 6; j++){ 
                if (j == 0 || j == 1){
                    input >> myList[i][j];
                }
                else if(j == 2){
                    input >> trash;;
                }
                else if(j == 3){
                    input >> myList[i][2];
                }
                else if (j == 4 || j == 5){
                    input >> trash;
                }
            }
        }

        //print the list to see if correct only 5 values)
        /*std :: cout << "The table is: \n";
        for (int i = 0; i < 5; i++){
            for(int j = 0; j < 3; j++){
                std :: cout << myList[i][j] << " ";
            }
            std :: cout << "\n";
        }*/

        float x;
        float y;
        float brightness;
        int count = 0;

        //test if the stars were appended properly
        /*cout << "My valid stars are: " << endl;
        for(int i = 0; i < 5; i++){
            cout << myStars[i].getX() << endl;
        }*/
        sf :: RenderWindow window( sf :: VideoMode (640,640), "Stars");

        //create list of stars
        std :: vector <Star> myStars (3546);
        for (int i = 0; i < 3546; i++){
            //check if star is valid
            if (myList[i][2] <= 0.0 || myList[i][2] >= 8.0){
                continue;
            }
            else{
                x = myList[count][0];
                y = myList[count][1];
                brightness = myList [count][2];
                //create star and add to myStars
                Star star(x, y, brightness);
                myStars.at(i) = star;
                count++;
            }
        }

        //testing if x values are correct for first five stars
        /*std :: cout << "x value of first five stars \n" ;
        for(int i = 0; i < 5; i++){
            std :: cout << myStars[i].getX() << "\n";
        }*/

        while( window.isOpen()){
            sf :: Event event;
            while (window.pollEvent(event)){
                if(event.type == sf :: Event :: Closed){
                    window.close();
                }
            }
        window.clear(sf :: Color(0,0,0));

        //draw stars using drawStar function
        for(int i = 0; i < 3521; i++){
            (myStars.at(i)).drawStar(window);
        }

        window.display();
        }


    }

    input.close();

    return 0;
}