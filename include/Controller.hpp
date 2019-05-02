#pragma once

enum class Direction
{
    Right,
    Left,
    Up,
    Down
};

class Controller
{
public:
    Direction dir = Direction::Right;
    virtual Direction getDirection() = 0;
    virtual ~Controller() = default;
};