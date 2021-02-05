#include "Board.h"
#include "Game.h"
#include <time.h>
#include <random>
#include <unordered_map>
#include <stdlib.h>
#include <SFML/Window/Mouse.hpp>

Board::Board()
{
    N_cols = 10;
    N_rows = 10;
    N_bombs = 20;
    N_bombs_left = N_bombs;

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


Tile* Board::get_tile(int x, int y)
{
    for(int index = 0; index < tiles.size(); index++)
    {
        sf::FloatRect shape = tiles[index]->tile_shape.getGlobalBounds();
        int left_bound = shape.left;
        int right_bound = shape.left + shape.width;
        int top_bound = shape.top;
        int bottom_bound = shape.top + shape.height;
        if(x < right_bound && x > left_bound && y < bottom_bound && y > top_bound) return tiles[index];
    }
    return NULL;
}

int Board::bombs_left()
{
    N_bombs_left = N_bombs;
    for(int i = 0; i < tiles.size(); i++)
    {
        if(tiles[i]->flag_status()) N_bombs_left--;
        if(tiles[i]->reveal_status() && tiles[i]->bomb_present()) N_bombs_left--;
    }
    return N_bombs_left;
}

void Board::draw(sf::RenderWindow &rw)
{
    for(int i = 0; i < tiles.size(); i++)
    {
        rw.draw(tiles[i]->tile_shape);
        rw.draw(tiles[i]->text_status);
    }
}

void Board::update(sf::RenderWindow &rw, sf::Event &event)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
    {
        if(event.type == sf::Event::EventType::MouseButtonReleased)
        {
            int x_pos = sf::Mouse::getPosition(rw).x;
            int y_pos = sf::Mouse::getPosition(rw).y;

            //find tile and reveal it
            Tile *selected_tile = get_tile(x_pos, y_pos);
            if(selected_tile != NULL)
            {
                selected_tile->change_flag();
            }
            return;
        }
    }
    else
    {
        if(event.type == sf::Event::EventType::Closed)
        {
            Game::_game_state = Game::Exiting;
            return;
        }
        if(event.type == sf::Event::EventType::MouseButtonReleased)
        {

            int x_pos = sf::Mouse::getPosition(rw).x;
            int y_pos = sf::Mouse::getPosition(rw).y;

            Tile *selected_tile = get_tile(x_pos, y_pos);
            if(selected_tile != NULL)
            {
                get_tile(x_pos,y_pos)->reveal();
            }

            return;
        }

    }
}

void Board::reset()
{
    for(int i = 0; i < tiles.size(); i++)
    {
        delete tiles[i];
    }
    tiles.erase(tiles.begin(),tiles.end());

    N_bombs_left = N_bombs;
    populate();
    determine_adjacencies();
}

int Board::index(int row, int col)
{
    if(row < 0 || row > N_rows - 1 || col < 0 || col > N_cols - 1) return -1;
    else return row*N_cols + col;
}
