#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Board;
class SplashScreen;
class ScoreBoard;

class Game
{
    public:

        static void start();
        sf::RenderWindow& get_window();
        const static int SCREEN_WIDTH = 1024;
        const static int SCREEN_HEIGHT = 768;

        enum game_state{Uninitialized, ShowingSplash, Paused, ShowingMenu, ShowingOptions, Playing, Restarting, Exiting};
        static game_state _game_state;



    private:

        static bool is_exiting();
        static void game_loop(sf::Clock & clock);

        static void show_splash_screen(sf::Event &event);
        static void show_menu();
        static void show_options();
        static void show_board(sf::Event &event);

        static Board *game_board;
        static ScoreBoard *score_board;


        static sf::RenderWindow main_window;
        static double total_elapsed_time;


};

#endif // GAME_H
