#include "MoverOnArr.hpp"
#include <ncurses.h>
#include <unistd.h>

Game::Game( int size,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker ),
              space( size, std::vector<FieldState>( size, FieldState::Free )),
              snake( 0, 0 ),
              dir( Direction::Right ),
              symbols{{ FieldState::Free, background },
                      { FieldState::SnakeNode, walker },
                      { FieldState::Fruit, '@' },
                      { FieldState::Obstacle, '#' }}
{ }

void Game::move()
{
    space [ snake.head.first ] [ snake.head.second ] = FieldState::Free;
    if( dir == Direction::Down )
        snake.head.first = ( ++snake.head.first < space.size() ) ? snake.head.first : 0;
    else if ( dir == Direction::Up )
        snake.head.first = ( --snake.head.first >= 0  ) ? snake.head.first : space.size() - 1;
    else if ( dir == Direction::Left )
        snake.head.second = ( --snake.head.second >= 0 ) ? snake.head.second : space.size() - 1;
    else if ( dir == Direction::Right )
        snake.head.second = ( ++snake.head.second < space.size() ) ? snake.head.second : 0;
    space [ snake.head.first ] [ snake.head.second ] = FieldState::SnakeNode;
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
        if (kbhit()) {
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
        move();
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
        sleep(1);
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