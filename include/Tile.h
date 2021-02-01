#ifndef TILE_H
#define TILE_H

//#include "Board.h"
#include <vector>

class Tile
{
    public:
        Tile();
        Tile(bool place_bomb);
        Tile(int rpos, int cpos, bool place_bomb);


        virtual ~Tile();

        //accessors
        bool bomb_present();
        bool reveal_status();
        bool flag_status();
        int get_adj_bombs(); //returns adj_bombs


        //modifiers
        void reveal();
        void flag();
        void unflag();
        void place_bomb();

    private:
        bool bomb;
        bool revealed;
        bool flagged;
        int row_pos;
        int col_pos;
        int adj_bombs;
        void find_adj_bombs(); //calculates number of adjacent bombs

        std::vector<Tile*> adj_tiles;
};

#endif // TILE_H
