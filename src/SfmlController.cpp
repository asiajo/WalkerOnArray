#include "SfmlController.hpp"

Direction SfmlController::getDirection( sf::RenderWindow & window )
{
    sf::Event event;
    while ( window.pollEvent(event) )
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
        {
            if( event.key.code == sf::Keyboard::Down && dir != Direction::Up )
                dir = Direction::Down;
            else if( event.key.code == sf::Keyboard::Right && dir != Direction::Left )
                dir = Direction::Right;
            else if( event.key.code == sf::Keyboard::Up && dir != Direction::Down )
                dir = Direction::Up;
            else if( event.key.code == sf::Keyboard::Left  && dir != Direction::Right )
                dir = Direction::Left;
        }
    }
    return dir;
}
