#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    //ctor
}

SplashScreen::~SplashScreen()
{
    //dtor
}

void SplashScreen::show(sf::RenderWindow& renderWindow, sf::Event &event)
{
    sf::Text title;
    sf::Font font;
    font.loadFromFile("FreeMonoBold.otf");
    title.setFont(font);
    title.setString("My Minesweeper");
    title.setCharacterSize(70);
    title.setFillColor(sf::Color(0,100,200));
    title.setStyle(sf::Text::Bold);
    sf::FloatRect titleBounds = title.getLocalBounds();
    title.setPosition(Game::SCREEN_WIDTH/2 - titleBounds.width/2-70, Game::SCREEN_HEIGHT/2 - titleBounds.height/2-70);

    renderWindow.clear(sf::Color::White);
    renderWindow.draw(title);
    renderWindow.display();

    while(1)
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::KeyPressed || event.type == sf::Event::EventType::MouseButtonPressed || event.type == sf::Event::EventType::Closed)
            {
                if(event.type == sf::Event::EventType::Closed)
                {
                    Game::_game_state = Game::Exiting;
                }
                else Game::_game_state = Game::Playing;
                return;
            }
        }
    }
}
