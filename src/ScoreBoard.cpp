#include "ScoreBoard.h"
#include <string>
#include <iostream>

ScoreBoard::ScoreBoard()
{
    font.loadFromFile("FreeMonoBold.otf");
    restart.setFont(font);
    restart.setString("Restart");
    exit.setFont(font);
    exit.setString("Exit");
    loser.setFont(font);
    loser.setString("You Lost");
    winner.setFont(font);
    winner.setString("You Won!");
}

ScoreBoard::~ScoreBoard()
{
    //dtor
}


void ScoreBoard::draw(sf::RenderWindow &rw)
{



}

void ScoreBoard::update(sf::RenderWindow &rw, Board &game_board, sf::Event &event)
{
    bombs_left.setString("Bombs Left: " + std::to_string(game_board.bombs_left()));
    bombs_left.setFont(font);
    //std::cerr << std::to_string(game_board.bombs_left()) << std::endl;

}
