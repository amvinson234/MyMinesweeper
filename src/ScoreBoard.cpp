#include "ScoreBoard.h"
#include <iostream>
#include "Game.h"
#include "Board.h"

ScoreBoard::ScoreBoard()
{
    font.loadFromFile("FreeMonoBold.otf");

    items["bomb count"] = create_item("Bombs Left: ", Game::SCREEN_WIDTH - 300, 100, Game::Playing);
    items["restart"] = create_item("Restart", Game::SCREEN_WIDTH - 300, 100 + 50, Game::Restarting);
    items["exit"] = create_item("Exit", Game::SCREEN_WIDTH - 300, 100 + 100, Game::Exiting);

}

ScoreBoard::ScoreBoard(Board &game_board)
{
    font.loadFromFile("FreeMonoBold.otf");

    items["bomb count"] = create_item("Bombs Left: " + std::to_string(game_board.bombs_left()), Game::SCREEN_WIDTH - 300, 100, Game::Playing);
    items["restart"] = create_item("Restart", Game::SCREEN_WIDTH - 300, 100 + 50, Game::Restarting);
    items["exit"] = create_item("Exit", Game::SCREEN_WIDTH - 300, 100 + 100, Game::Exiting);

}

ScoreBoard::~ScoreBoard()
{
    //dtor
}

ScoreBoard::Item ScoreBoard::create_item(std::string text, int x_pos, int y_pos, int action)
{
    Item item;
    item.text = sf::Text(text,font);
    item.text.setPosition(x_pos,y_pos);
    item.action = action;
    return item;
}

void ScoreBoard::draw(sf::RenderWindow &rw)
{

    std::map<std::string,Item>::iterator it;

    for(it = items.begin(); it != items.end(); it++)
    {
        sf::Text item = it->second.text;
        std::string test = item.getString();
        rw.draw(item);

    }


}

void ScoreBoard::reset()
{
    items.erase(items.find("lost"));
    items.erase(items.find("won"));
}

void ScoreBoard::update(sf::RenderWindow &rw, Board &game_board, sf::Event &event)
{
    items["bomb count"].text.setString("Bombs Left: " + std::to_string(game_board.bombs_left()));

    if(event.type == sf::Event::EventType::Closed)
    {
        Game::_game_state = Game::Exiting;
        return;
    }


    if(event.type == sf::Event::EventType::MouseButtonReleased)
    {

        int x_pos = sf::Mouse::getPosition(rw).x;
        int y_pos = sf::Mouse::getPosition(rw).y;

        std::map<std::string, Item>::iterator it;
        for(it = items.begin(); it != items.end(); it++)
        {
            sf::FloatRect item = it->second.text.getGlobalBounds();
            if(item.top < y_pos && item.top + item.height > y_pos && item.left < x_pos && item.left + item.width > x_pos)
            {
                Game::game_state val = static_cast<Game::game_state>(it->second.action);
                Game::_game_state = val;
                return;
            }
        }
    }
    if(Game::_game_state == Game::Lost)
    {
        items["lost"] =  create_item("You Lost", Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2, Game::Lost);
    }
    if(Game::_game_state == Game::Won)
    {
        items["won"] =  create_item("You Won", Game::SCREEN_WIDTH / 2, Game::SCREEN_HEIGHT / 2, Game::Lost);
    }
}
