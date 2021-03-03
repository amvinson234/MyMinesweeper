#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "MenuItem.h"


class Game;
class Board;

class OptionsMenu
{
    public:
        OptionsMenu();
        virtual ~OptionsMenu();

        void update(sf::RenderWindow &rw, Board &game_board, sf::Event &event);
        void draw(sf::RenderWindow &rw);

    private:
        sf::Font font;
        MenuItem create_item(std::string text, int x_pos, int y_pos, int action);
        std::map<std::string,MenuItem> items;
};

#endif // OPTIONSMENU_H
