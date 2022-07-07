/* CSCI 261: L7A - SFML Drawing
 *
 * Author: Kylie Quinney
 * Resources used : SFML.org for help with syntax
 *
 * Description: Make five shapes using SFML (shapes made = smiley: 3 circles and a convex shape, triangle, and square)
 * extra credit (the red square moves back and forth on the bottom of the window indefinately... and also very fast)
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "Kylie's Window" );
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING

    // Make face of smiley
    CircleShape circle;
    circle.setRadius(200);
    circle.setPosition(320-circle.getRadius(), 320-circle.getRadius());
    circle.setFillColor(Color:: Yellow);

    // Make eyes for smiley
    CircleShape eyeOne;
    eyeOne.setRadius(40);
    eyeOne.setPosition(400-eyeOne.getRadius(), 240-eyeOne.getRadius());
    eyeOne.setFillColor(Color :: Black);

    CircleShape eyeTwo;
    eyeTwo.setRadius(40);
    eyeTwo.setPosition(240-eyeTwo.getRadius(), 240-eyeTwo.getRadius());
    eyeTwo.setFillColor(Color :: Black);

    //draw rectangle
    RectangleShape rect;
    rect.setSize(Vector2f(20,20));
    rect.setFillColor(Color :: Red);
    rect.setPosition(20,600);

    //draw the mouth for the smiley
    ConvexShape smile;
    smile.setPointCount(4);
    smile.setPoint(0, Vector2f(450, 320));
    smile.setPoint(1, Vector2f(390, 450));
    smile.setPoint(2, Vector2f(260, 450));
    smile.setPoint(3, Vector2f(200, 320));
    smile.setFillColor(Color :: Black);

    //make a triangle with multicolored gradient
    VertexArray triangle(Triangles, 3);

    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 10.f);
    triangle[2].position = sf::Vector2f(100.f, 100.f);

    triangle[0].color = Color::Red;
    triangle[1].color = Color::Blue;
    triangle[2].color = Color::Green;


    // while the window is open
    while( window.isOpen() ) {
        Event event;

        // move rectangle right 10
        if(rect.getPosition().x <= 600){
            rect.move(1.f,0.f);
        }   
        else{     
        while (rect.getPosition().x >= 40){
            rect.move(-1.f,0.f);
        }
        }
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }

            // check addition event types to handle additional events
        }
        // clear any existing contents
        window.clear();

        window.draw(circle);

        window.draw(eyeOne);

        window.draw(eyeTwo);

        window.draw(smile);

        window.draw(triangle);

        window.draw(rect);

        // display the current contents of the window
        window.display();
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }

    return 0;
}