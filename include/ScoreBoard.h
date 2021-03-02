#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "MenuItem.h"

class Game;
class Board;

class ScoreBoard
{
    public:
        ScoreBoard();
        ScoreBoard(Board &game_board);
        virtual ~ScoreBoard();

        enum action_state{};


        /*struct Item
        {
            public:
                sf::Text text;
                int action;
        };*/



        std::map<std::string,MenuItem> items;

        void update(sf::RenderWindow &rw, Board &game_board, sf::Event &event);
        void draw(sf::RenderWindow &rw);
        void reset();


    private:
        sf::Font font;
        MenuItem create_item(std::string text, int x_pos, int y_pos, int action);

};

#endif // SCOREBOARD_H
