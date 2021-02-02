#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
//#include "Game.h"
#include <vector>

class Board
{
    public:
        Board();
        Board(int nrows, int ncols);
        Board(int nrows, int ncols, int nbombs);

        virtual ~Board();

        Tile* get_tile(int row, int col);

        //modifiers
        void reveal_all(); //loops through tiles on board and changes reveal status

        void draw(sf::RenderWindow &rw);

    private:
        std::vector<Tile*> tiles; //flattened list of tiles on the board
        void populate(); //populates the board with defined tiles
        void determine_adjacencies(); //loops through tiles to determine number of adjacent bombs;
        int N_cols;
        int N_rows;
        int N_bombs;


};

#endif // BOARD_H
