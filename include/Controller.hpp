#pragma once

#include <ncurses.h>
#include <unistd.h>

enum class Direction
{
    Right,
    Left,
    Up,
    Down
};

class Controller
{
    Direction dir = Direction::Right;
    int kbhit(void);
public:
    Direction getDirection();
};