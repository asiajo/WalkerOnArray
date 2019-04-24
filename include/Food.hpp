#pragma once

#include "Position.hpp"
#include <random>

class Food
{
    int _boardX;
    int _boardY;
    int _x;
    int _y;
public:
    Food(int boardX, int boardY);
    void generateFood();
    Position getFoodPosition();
};