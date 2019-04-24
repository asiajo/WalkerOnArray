#include "MoverOnArr.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <random>
Game::Game( int size,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker ),
              space( size, std::vector<FieldState>( size, FieldState::Free )),
              snake( { size/2, size/2 } ),
              dir( Direction::Right ),
              symbols{{ FieldState::Free, background },
                      { FieldState::SnakeNode, walker },
                      { FieldState::Fruit, '@' },
                      { FieldState::Obstacle, '#' }}
{   
    space[ size/2 ] [ size/2  ] = FieldState::SnakeNode;
    for( int i = 1; i < 3; ++i )
    {   snake.body.push_back( { size/2, size/2 - i } );
        space[ size/2 ] [ size/2 - i ] = FieldState::SnakeNode;
    }
    putRandolmyFruit();
}

void Game::putRandolmyFruit()
{
    Food fruit{space.size(), space.size()};
    do
    {
        fruit.generateFood();
    } while ( space [ fruit.getFoodPosition().x ] [ fruit.getFoodPosition().y ] != FieldState::Free );
    space [ fruit.getFoodPosition().x ] [ fruit.getFoodPosition().y ] = FieldState::Fruit; 
}

FieldState Game::moveHead()
{
    // space [ snake.head.first ] [ snake.head.second ] = FieldState::Free;
    Coords newHead = snake.head;
    if( dir == Direction::Down )
        newHead.first = ( ++newHead.first < space.size() ) ? newHead.first : 0;
    else if ( dir == Direction::Up )
        newHead.first = ( --newHead.first >= 0  ) ? newHead.first : space.size() - 1;
    else if ( dir == Direction::Left )
        newHead.second = ( --newHead.second >= 0 ) ? newHead.second : space.size() - 1;
    else if ( dir == Direction::Right )
        newHead.second = ( ++newHead.second < space.size() ) ? newHead.second : 0;
    snake.head = newHead;
    FieldState fieldToCheckCollision = space [ snake.head.first ] [ snake.head.second ];
    space [ snake.head.first ] [ snake.head.second ] = FieldState::SnakeNode;
    return fieldToCheckCollision;
}

bool Game::move()
{
    Coords oldHead = snake.head;
    Coords oldTail = snake.body.back();
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
    space [ oldTail.first ] [ oldTail.second ] = FieldState::Free;
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
        usleep(50000);
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
//         std::this_thread::sleep_for( std::chrono::seconds(1) );
//     }
// }