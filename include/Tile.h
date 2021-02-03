#ifndef TILE_H
#define TILE_H

//#include "Board.h"
#include <vector>
#include <SFML/Graphics.hpp>


class Tile
{
    public:
        Tile();
        Tile(bool place_bomb);
        Tile(int rpos, int cpos, bool place_bomb, int pixel_size);


        virtual ~Tile();

        //accessors
        bool bomb_present();
        bool reveal_status();
        bool flag_status();
        int get_adj_bombs(); //returns adj_bombs
        int row_pos;
        int col_pos;


        //modifiers
        void reveal();
        void flag();
        void unflag();
        void change_flag();
        void question();
        void unquestion();
        void change_question();
        void place_bomb();
        void add_adj_bomb();

        //graphics
        sf::RectangleShape tile_shape;
        sf::Text text_status;

    private:
        bool bomb;
        bool revealed;
        bool flagged;
        bool questioned;
        int width;
        int adj_bombs;
        void find_adj_bombs(); //calculates number of adjacent bombs

        sf::Font font;


        std::vector<Tile*> adj_tiles;
};

#endif // TILE_H
