#include "MoverOnArr.hpp"
#include <ncurses.h>
#include <unistd.h>

Mover::Mover( int size,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker )
{
    space = std::vector<char>( size, background );
    walker_position = 0;
    space[ walker_position ] = walker;
    dir = Direction::Left;
}

void Mover::move()
{
    space [ walker_position ] = background;
    if( dir == Direction::Right )
        walker_position = ( ++walker_position < space.size() ) ? walker_position : 0;
    else
        walker_position = ( --walker_position >= 0  ) ? walker_position : space.size() - 1;
    space [ walker_position ] = walker;
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
            if ( newdir == 113 )
                break;
            refresh();
        }
        move();
        for( const auto & elem : space )
            {printw( "%c", elem ); refresh();}
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