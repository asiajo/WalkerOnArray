#pragma once

#include <random>
#include "Position.hpp"

class Food
{
    Position position;
public:
    void generateFood(int heightBoard, int widthBoard);
    Position getFoodPosition();
};  