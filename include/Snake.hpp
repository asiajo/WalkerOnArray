#pragma once
#include<deque>
#include "Position.hpp"

using Body = std::deque<Position>;
class Snake
{
public:
    Position head;
    Body body;
    Snake (Position);
};