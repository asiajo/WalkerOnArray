#include "SfmlGUI.hpp"

SfmlGUI::SfmlGUI() : colors {{ FieldState::Free, sf::Color::Black },
                            { FieldState::SnakeNode, sf::Color::Green },
                            { FieldState::Fruit, sf::Color::Red },
                            { FieldState::Obstacle, sf::Color::Yellow }}
{
    
}

void SfmlGUI::init( sf::RenderWindow& window, int height, int width )
{

    const int FRAMERATE_LIMIT = 10;
    window.create(sf::VideoMode( width * TILE_SIZE, height * TILE_SIZE ), "SnakeTitle ");
    window.setFramerateLimit( FRAMERATE_LIMIT );
}

void SfmlGUI::display(sf::RenderWindow& window, Board& board)
{
    sf::Vector2f PIXEL_SIZE { TILE_SIZE, TILE_SIZE };
    for( int i = 0; i < board.getHeight(); ++i )
        for( int j = 0; j < board.getWidth(); ++j )
    {
            sf::Vector2f coords { j * TILE_SIZE, i * TILE_SIZE };
            sf::RectangleShape rect( PIXEL_SIZE );
            rect.setPosition( coords );
            rect.setFillColor( colors[ board.getFieldState( Position{i, j} ) ] );
            window.draw(rect);
    }
    window.display();
}