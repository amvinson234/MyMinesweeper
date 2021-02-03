#include "Tile.h"
#include "Game.h"
#include <iostream>
#include <string>

Tile::Tile()
{
    //ctor
}

Tile::Tile(int rpos, int cpos, bool place_bomb, int pixel_size)
{
    bomb = place_bomb;
    revealed = false;
    flagged = false;
    questioned = false;
    row_pos = rpos;
    col_pos = cpos;
    width = pixel_size;
    adj_bombs = 0;


    int margin = Game::SCREEN_HEIGHT / 4;
    tile_shape = sf::RectangleShape(sf::Vector2f(width, width));
    tile_shape.setFillColor(sf::Color(100,100,100));
    int thickness = width / 10;
    tile_shape.setOutlineThickness(thickness);
    tile_shape.setOutlineColor(sf::Color(50,50,50));

    tile_shape.setPosition(margin + (width + thickness*2.0) * col_pos, margin + (width + thickness*2.0) * row_pos);

    font.loadFromFile("FreeMonoBold.otf");
    text_status.setFont(font);
    text_status.setCharacterSize(width/2);
    text_status.setString("");
    text_status.setOrigin(text_status.getLocalBounds().width/2,text_status.getLocalBounds().height/2);
    text_status.setPosition(margin + (width + thickness*2.0) * col_pos + (width+thickness*0.0)/2, margin + (width + thickness*2.0) * row_pos + width / 4.);// (width+thickness*0.0)/2);


}

Tile::~Tile()
{
    //dtor
}


void Tile::reveal()
{
    if(bomb) text_status.setString("B");
    else text_status.setString(std::to_string(adj_bombs));
    tile_shape.setFillColor(sf::Color(200,200,200));
    revealed = true;
}
void Tile::flag()
{
    if(revealed) return;
    text_status.setString("F");
    flagged = true;
}
void Tile::unflag()
{
    if(revealed) return;
    text_status.setString("");
    flagged = false;
}
void Tile::change_flag()
{
    if(flagged) unflag();
    else flag();
}
void Tile::question()
{
    if(revealed) return;
    text_status.setString("?");
    questioned = true;
}
void Tile::unquestion()
{
    if(revealed) return;
    text_status.setString("");
    questioned = false;
}
void Tile::change_question()
{
    if(questioned) unquestion();
    else question();
}
void Tile::place_bomb()
{
    bomb = true;
}
void Tile::add_adj_bomb()
{
    adj_bombs++;
}



bool Tile::bomb_present()
{
    return bomb;
}
bool Tile::flag_status()
{
    return flagged;
}
bool Tile::reveal_status()
{
    return revealed;
}
int Tile::get_adj_bombs()
{
    return adj_bombs;
}




