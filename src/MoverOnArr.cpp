#include "MoverOnArr.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <random>
Game::Game(   int height,
              int width,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker ),
              space( height, std::vector<FieldState>( width, FieldState::Free )),
              snake( { height/2, width/2 } ),
              dir( Direction::Right ),
              symbols{{ FieldState::Free, background },
                      { FieldState::SnakeNode, walker },
                      { FieldState::Fruit, '@' },
                      { FieldState::Obstacle, '#' }}
{   
    space[ height/2 ] [ width/2 ] = FieldState::SnakeNode;
    for( int i = 1; i < 3; ++i )
    {   snake.body.push_back( { height/2, width/2 - i } );
        space[ height/2 ] [ width/2 - i ] = FieldState::SnakeNode;
    }
    putRandolmyFruit();
}

void Game::putRandolmyFruit()
{
    Food fruit;
    do
    {
        fruit.generateFood( getHeight(), getWidth() );
    } while ( space [ fruit.getFoodPosition().x ] [ fruit.getFoodPosition().y ] != FieldState::Free );
    space [ fruit.getFoodPosition().x ] [ fruit.getFoodPosition().y ] = FieldState::Fruit; 
}

FieldState Game::moveHead()
{
    Position newHead = snake.head;
    if( dir == Direction::Down )
        newHead.x = ( ++newHead.x < getHeight() ) ? newHead.x : 0;
    else if ( dir == Direction::Up )
        newHead.x = ( --newHead.x >= 0  ) ? newHead.x : getHeight() - 1;
    else if ( dir == Direction::Left )
        newHead.y = ( --newHead.y >= 0 ) ? newHead.y : getWidth() - 1;
    else if ( dir == Direction::Right )
        newHead.y = ( ++newHead.y < getWidth() ) ? newHead.y : 0;
    snake.head = newHead;
    FieldState fieldToCheckCollision = space [ snake.head.x ] [ snake.head.y ];
    space [ snake.head.x ] [ snake.head.y ] = FieldState::SnakeNode;
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
    space [ oldTail.x ] [ oldTail.y ] = FieldState::Free;
    return true;
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void Game::play()
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);

    scrollok(stdscr, TRUE);
    while (1) {
        erase();
        if (kbhit()) 
        {
            int newdir = getch();
            if ( newdir == 97 && dir != Direction::Right )
                dir = Direction::Left;
            if ( newdir == 100 && dir != Direction::Left )
                dir = Direction::Right;
            if ( newdir == 115 && dir != Direction::Up )
                dir = Direction::Down;
            if ( newdir == 119 && dir != Direction::Down )
                dir = Direction::Up;
            refresh();
        }

        if( !move() )
            break;

        for( const auto & row : space )
        {
            for( const auto & elem : row )
            {
                printw( "%c ", symbols [ elem ] ); 
                refresh();
            }
            printw("\n");
            refresh();
        }
        printw("\n");
        refresh();
        usleep(1000000);
    }
    endwin();
}





// void Mover::play()
// {
//     while( 1 )
//     {
//         system("clear");
//         for( const auto & elem : space )
//             std::cout << elem;
//         std::cout << std::endl;
//         move();
//         std::this_thread::sleep_for( std::chrono::ys(1) );
//     }
// }