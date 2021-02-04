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


        //modifiers
        void reveal_all(); //loops through tiles on board and changes reveal status

        //accessors
        int bombs_left();
        Tile* get_tile(int x, int y);

        void draw(sf::RenderWindow &rw);
        void update(sf::RenderWindow &rw, sf::Event &event);

    private:
        std::vector<Tile*> tiles; //flattened list of tiles on the board
        void populate(); //populates the board with defined tiles
        void determine_adjacencies(); //loops through tiles to determine number of adjacent bombs;
        int N_cols;
        int N_rows;
        int N_bombs;
        int N_bombs_left;
        int index(int row, int col);


};

#endif // BOARD_H
