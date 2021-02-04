#include "Game.h"

void Game::start()
{
    if(_game_state != Uninitialized) return;
    main_window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,64), "My Minesweeper");

    _game_state = Game::ShowingSplash;

    sf::Clock clock;
    while(!is_exiting())
    {
        game_loop(clock);
    }
    main_window.close();
}

sf::RenderWindow& Game::get_window()
{
    return main_window;
}

bool Game::is_exiting()
{
    if(_game_state == Game::Exiting) return true;
    else return false;
}

void Game::game_loop(sf::Clock &clock)
{
    sf::Event current_event;
    while(main_window.pollEvent(current_event))
    {
        if(current_event.type == sf::Event::EventType::Closed) _game_state = Game::Exiting;
        double elapsed_time = clock.getElapsedTime().asSeconds();
        clock.restart();

        switch(_game_state)
        {
            case Game::ShowingSplash:
            {
                show_splash_screen(current_event);
                break;
            }
            case Game::Playing:
            {
                show_board(current_event);

                break;
            }
        }
    }
}

void Game::show_splash_screen(sf::Event &event)
{
    SplashScreen splash_screen;
    splash_screen.show(main_window, event);

    //if starting game, wait a little before game starts reading game inputs
    if(Game::_game_state == Game::Playing)
    {
        main_window.clear(sf::Color(0,100,200));
        game_board.draw(main_window);
        main_window.display();
        sf::Clock clock;
        while(clock.getElapsedTime().asSeconds() < 1)
        {
        }
    }
}

void Game::show_board(sf::Event &event)
{
    main_window.clear(sf::Color(0,100,200));
    //Board game_board;
   // game_board.draw(main_window);
   // main_window.display();
    game_board.update(main_window, event);
    game_board.draw(main_window);
    score_board.update(main_window, game_board, event);
    main_window.display();

}

Game::game_state Game::_game_state = Uninitialized;
sf::RenderWindow Game::main_window;
Board Game::game_board;
ScoreBoard Game::score_board;
