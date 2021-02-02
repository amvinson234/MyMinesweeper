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
    main_window.pollEvent(current_event);
    double elapsed_time = clock.getElapsedTime().asSeconds();
    clock.restart();

    switch(_game_state)
    {
        case Game::ShowingSplash:
        {
            show_splash_screen();
            break;
        }
        case Game::Playing:
        {
            show_board();
            break;
        }
    }


}

void Game::show_splash_screen()
{
    SplashScreen splash_screen;
    splash_screen.show(main_window);

    _game_state = Game::Playing;
    //game_board
}

void Game::show_board()
{
    main_window.clear(sf::Color(0,100,200));
    //Board game_board;
    game_board.draw(main_window);
    main_window.display();

}

Game::game_state Game::_game_state = Uninitialized;
sf::RenderWindow Game::main_window;
Board Game::game_board;
