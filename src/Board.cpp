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
      //  std::cerr << tiles[i]->tile_shape.getPosition().x << std::endl;
        tiles[i]->reveal();
        rw.draw(tiles[i]->tile_shape);
        rw.draw(tiles[i]->text_status);
    }
    /*
    int margin = Game::SCREEN_HEIGHT / 2.;
    int width = (Game::SCREEN_WIDTH-margin)/N_rows;
    sf::RectangleShape tile_shape(sf::Vector2f(width, width));
    tile_shape.setFillColor(sf::Color(100,100,100));
    int thickness = width / 10;
    tile_shape.setOutlineThickness(thickness);
    tile_shape.setOutlineColor(sf::Color(50,50,50));
    tile_shape.setOrigin(50.,50.);
    tile_shape.setPosition(Game::SCREEN_WIDTH/2.,Game::SCREEN_HEIGHT/2.0);
    rw.draw(tile_shape);
    tile_shape.setPosition(Game::SCREEN_WIDTH/2. + width + 2*thickness, Game::SCREEN_HEIGHT/2.0);
    rw.draw(tile_shape);
    */



}
