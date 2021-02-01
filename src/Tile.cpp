#include "Tile.h"

Tile::Tile()
{
    //ctor
}

Tile::Tile(int rpos, int cpos, bool place_bomb)
{
    bomb = place_bomb;
    revealed = false;
    flagged = false;
    row_pos = rpos;
    cpos = col_pos;

}

Tile::~Tile()
{
    //dtor
}


void Tile::reveal()
{
    revealed = true;
}
void Tile::flag()
{
    flagged = true;
}
void Tile::unflag()
{
    flagged = false;
}
void Tile::place_bomb()
{
    bomb = true;
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
