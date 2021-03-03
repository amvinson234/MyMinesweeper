#include "OptionsMenu.h"
#include <iostream>
#include "Game.h"
#include "Board.h"


/*
OptionsMenu::OptionsMenu()
{

}
*/

OptionsMenu::OptionsMenu()
{
    font.loadFromFile("FreeMonoBold.otf");
/*
    items["play"] = create_item("Play: ", Game::SCREEN_WIDTH - 300, 100, Game::Playing);
    items["rows"] = create_item("Number of Rows: ", Game::SCREEN_WIDTH - 300, 100 + 50, Game::ShowingOptions);
    items["rows_plus"] = create_item()
    items["columns"] = create_item("Number of Columns", Game::SCREEN_WIDTH - 300, 100 + 100, Game::ShowingOptions);
    items["exit"] = create_item("Exit", Game::SCREEN_WIDTH - 300, 100 + 150, Game::Exiting);
*/
}

OptionsMenu::~OptionsMenu()
{
    //dtor
}


