#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Board.h"
#include "SplashScreen.h"


class Game
{
    public:

        static void start();
        sf::RenderWindow& get_window();
        const static int SCREEN_WIDTH = 1024;
        const static int SCREEN_HEIGHT = 768;



    private:

        static bool is_exiting();
        static void game_loop(sf::Clock & clock);

        static void show_splash_screen();
        static void show_menu();
        static void show_options();
        static void show_board();

        enum game_state{Uninitialized, ShowingSplash, Paused, ShowingMenu, ShowingOptions, Playing, Exiting};

        static game_state _game_state;

        static sf::RenderWindow main_window;
        static double total_elapsed_time;


};

#endif // GAME_H
