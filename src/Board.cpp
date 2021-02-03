#include "Board.h"
#include "Game.h"
#include <time.h>
#include <random>
#include <unordered_map>
#include <stdlib.h>

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
    int current_bombs = 0;
    srand(time(NULL));
    std::unordered_map<int,bool> index_bomb;
    for(int i = 0; i < N_cols*N_rows; i++) index_bomb[i] = false;
    while(current_bombs < N_bombs)
    {
        int index = rand() % (N_cols * N_rows);
        if(!index_bomb[index])
        {
            index_bomb[index] = true;
            current_bombs++;
        }
    }


    for(int i = 0; i < N_cols * N_rows; i++)
    {
        int rpos = i / N_cols;
        int cpos = i % N_cols;

        bool place_bomb = false;
        if(index_bomb[i]) place_bomb = true;


        int margin = Game::SCREEN_HEIGHT / 2.;
        Tile *new_tile = new Tile(rpos, cpos, place_bomb, (Game::SCREEN_HEIGHT-margin)/N_rows);
        tiles.push_back(new_tile);
    }
}

void Board::determine_adjacencies()
{
    for(int i = 0; i < N_rows*N_cols; i++)
    {
        int row = tiles[i]->row_pos;
        int col = tiles[i]->col_pos;

        int row_above = row - 1;
        int row_below = row + 1;
        int col_right = col + 1;
        int col_left = col - 1;

        if(index(row_above,col_left) >= 0 && tiles[index(row_above,col_left)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row_above,col) >= 0 && tiles[index(row_above,col)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row_above,col_right) >= 0 && tiles[index(row_above,col_right)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row,col_left) >= 0 && tiles[index(row,col_left)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row,col_right) >= 0 && tiles[index(row,col_right)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row_below,col_left) >= 0 && tiles[index(row_below,col_left)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row_below,col) >= 0 && tiles[index(row_below,col)]->bomb_present()) tiles[i]->add_adj_bomb();
        if(index(row_below,col_right) >= 0 && tiles[index(row_below,col_right)]->bomb_present()) tiles[i]->add_adj_bomb();

    }
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
    rw.clear(sf::Color(0,0,100.));
    for(int i = 0; i < tiles.size(); i++)
    {
        tiles[i]->reveal();
        rw.draw(tiles[i]->tile_shape);
        rw.draw(tiles[i]->text_status);
    }
}

int Board::index(int row, int col)
{
    if(row < 0 || row > N_rows - 1 || col < 0 || col > N_cols - 1) return -1;
    else return row*N_cols + col;
}
