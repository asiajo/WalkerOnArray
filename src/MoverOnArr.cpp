#include "MoverOnArr.hpp"
#include <ncurses.h>
#include <unistd.h>

Mover::Mover( int size,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker ),
              space( size, std::vector<FieldState>( size, FieldState::Free )),
              walker_position( 0, 0 ),
              dir( Direction::Right ),
              symbols{{ FieldState::Free, background },
                      { FieldState::SnakeNode, walker },
                      { FieldState::Fruit, '@' },
                      { FieldState::Obstacle, '#' }}
{ }

void Mover::move()
{
    space [ walker_position.first ] [ walker_position.second ] = FieldState::Free;
    if( dir == Direction::Down )
        walker_position.first = ( ++walker_position.first < space.size() ) ? walker_position.first : 0;
    else if ( dir == Direction::Up )
        walker_position.first = ( --walker_position.first >= 0  ) ? walker_position.first : space.size() - 1;
    else if ( dir == Direction::Left )
        walker_position.second = ( --walker_position.second >= 0 ) ? walker_position.second : space.size() - 1;
    else if ( dir == Direction::Right )
        walker_position.second = ( ++walker_position.second < space.size() ) ? walker_position.second : 0;
    space [ walker_position.first ] [ walker_position.second ] = FieldState::SnakeNode;
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

void Mover::play()
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
            if ( newdir == 97 )
                dir = Direction::Left;
            if ( newdir == 100 )
                dir = Direction::Right;
            if ( newdir == 115 )
                dir = Direction::Down;
            if ( newdir == 119 )
                dir = Direction::Up;
            refresh();
        }
        move();
        for( const auto & row : space )
        {
            for( const auto & elem : row )
            {
                printw( "%c", symbols [ elem ] ); 
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