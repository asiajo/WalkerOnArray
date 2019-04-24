#include "Controller.hpp"

Direction Controller::getDirection()
{
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
    }
    return dir;
}

int Controller::kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}