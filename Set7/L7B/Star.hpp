#ifndef STAR_HPP
#define STAR_HPP

#include <SFML/Graphics.hpp>

class Star {
    public:
        Star();

        Star(float xVal, float yVal, float brightnessVal);

        void setPosition(float xVal, float yVal);

        void setBrightness(float brightnessVal);

        int getBrightness();

        float getX();

        void drawStar(sf :: RenderWindow &window);

    private:

        int windowWidth = 640;

        int windowHeight = 640;

        float maxBrightness = 8.0f;

        float x;

        float y;

        int brightness;

        sf :: CircleShape star ;

};

Star :: Star(){
    x=0;
    y=0;
    star.setRadius(2.0);
}

//assign all data members, radius = 2, brightness = half max, position = (0,0)
Star :: Star(float xVal, float yVal, float brightnessVal){
    setPosition(xVal, yVal);
    setBrightness(brightnessVal);
    star.setRadius(2.0);
    star.setPosition(x, y);
    star.setFillColor(sf :: Color(brightness,brightness,brightness));
}

void Star :: drawStar(sf :: RenderWindow &window){
    window.draw(star);
    star.setPosition(x,y);
}

void Star :: setPosition(float xVal, float yVal){
    x = (xVal + 1.0) * windowWidth / 2.0;
    y = (-yVal + 1.0) * windowHeight / 2.0;
}

void Star :: setBrightness(float brightnessVal){
    float invertedBrightness = maxBrightness - brightnessVal;
    int shadeOfGray = (int)((255.0 * invertedBrightness ) / maxBrightness);
    brightness = shadeOfGray;
}

float Star :: getX(){
    return x;
}

int Star :: getBrightness(){
    return brightness;
}

#endif