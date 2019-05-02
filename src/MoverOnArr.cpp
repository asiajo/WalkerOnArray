#include "MoverOnArr.hpp"
#include <random>

Game::Game(   int height,
              int width )
            : snake( { width/2, height/2 } ),
              board( width, height )              
{   
    const Direction DEFAULT_DIRECTION = Direction::Right;
    dir = DEFAULT_DIRECTION;
    board.setFieldState(Position{width/2, height/2}, FieldState::SnakeNode);
    for( int i = 1; i < 3; ++i )
    {   
        snake.body.push_back( { width/2, height/2 - i } );
        board.setFieldState( Position{width/2, height/2 - i}, FieldState::SnakeNode );
    }
    putRandolmyFruit();   
}

void Game::putRandolmyFruit()
{
    Food fruit;
    do
    {
        fruit.generateFood( board.getHeight(), board.getWidth() );
    } while ( board.getFieldState( Position{fruit.getFoodPosition().x, fruit.getFoodPosition().y}) != FieldState::Free );
    board.setFieldState( Position{fruit.getFoodPosition().x, fruit.getFoodPosition().y}, FieldState::Fruit );
}

FieldState Game::moveHead()
{
    Position newHead = snake.head;
    if( dir == Direction::Down )
        newHead.x = ( ++newHead.x < board.getHeight() ) ? newHead.x : 0;
    else if ( dir == Direction::Up )
        newHead.x = ( --newHead.x >= 0  ) ? newHead.x : board.getHeight() - 1;
    else if ( dir == Direction::Left )
        newHead.y = ( --newHead.y >= 0 ) ? newHead.y : board.getWidth() - 1;
    else if ( dir == Direction::Right )
        newHead.y = ( ++newHead.y < board.getWidth() ) ? newHead.y : 0;
    snake.head = newHead;
    FieldState fieldToCheckCollision = board.getFieldState(Position{snake.head.x, snake.head.y});
    board.setFieldState(Position{snake.head.x , snake.head.y}, FieldState::SnakeNode);
    return fieldToCheckCollision;
}

bool Game::move()
{
    Position oldHead = snake.head;
    Position oldTail = snake.body.back();
    FieldState fieldToCheckCollision = moveHead();
    if( fieldToCheckCollision == FieldState::Obstacle || fieldToCheckCollision == FieldState::SnakeNode )
        return false;
    snake.body.push_front( oldHead );
    if( fieldToCheckCollision == FieldState::Fruit )
    {
        putRandolmyFruit();
    }
    else
    {
        snake.body.pop_back();
    }
    board.setFieldState( Position{oldTail.x, oldTail.y}, FieldState::Free );
    return true;
}



void Game::playInTerminal()
{
    TerminalGUI displayer;
    TerminalController controller;
    while ( 1 ) 
    { 
        if( !move() )
            break;
        displayer.display( board );
        dir = controller.getDirection();
    }
}

void Game::playInSFML()
{
    
    sf::RenderWindow window;
    SfmlGUI displayer;
    SfmlController controller;

    displayer.init( window, board.getHeight(), board.getWidth());
    while ( window.isOpen() ) 
    {
        displayer.display( window, board );
        if( !move() )
            window.close();
        dir = controller.getDirection( window );
    }
}
