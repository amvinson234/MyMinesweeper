#include "Board.h"

Board::Board()
{
    N_cols = 10;
    N_rows = 10;
    N_bombs = 20;

    populate();
    determine_adjacencies();
}

Board::Board(int nrows, int ncols, int nbombs)
{
    N_cols = ncols;
    N_rows = nrows;
    N_bombs = nbombs;

    populate();
    determine_adjacencies();
}

Board::~Board()
{
    //dtor
}

void Board::populate()
{
    for(int i = 0; i < N_cols * N_rows; i++)
    {
        int rpos = i / N_cols;
        int cpos = i % N_cols;
        bool place_bomb = false; //PLACEHOLDER. This needs to become randomized in some manner
        Tile *new_tile = new Tile(rpos, cpos, place_bomb);
        tiles.push_back(new_tile);
    }
}

void Board::determine_adjacencies()
{

}

void Board::reveal_all()
{
    for(int i = 0; i < N_cols * N_rows; i++)
    {
        tiles[i]->reveal();
    }
}


Tile* Board::get_tile(int row, int col)
{
    int index = row * N_cols + col;
    return tiles[index];
}

void Board::draw(sf::RenderWindow &rw)
{

}
