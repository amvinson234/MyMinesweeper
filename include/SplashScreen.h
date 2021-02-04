#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include "Game.h"

class SplashScreen
{
    public:
        SplashScreen();
        ~SplashScreen();

        void show(sf::RenderWindow& rw, sf::Event &event);

    private:
};

#endif // SPLASHSCREEN_H
