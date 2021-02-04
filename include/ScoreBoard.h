#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>
#include "Board.h"

class ScoreBoard
{
    public:
        ScoreBoard();
        virtual ~ScoreBoard();

        void update(sf::RenderWindow &rw, Board &game_board, sf::Event &event);
        void draw(sf::RenderWindow &rw);


    private:
        sf::Font font;
        sf::Text bombs_left;
        sf::Text restart;
        sf::Text exit;
        sf::Text loser;
        sf::Text winner;


};

#endif // SCOREBOARD_H
