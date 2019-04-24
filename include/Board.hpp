#pragma once

#include <vector>
#include <algorithm>
#include "Position.hpp"

enum class FieldState
{
    Free,
    SnakeNode,
    Fruit,
    Obstacle
};


class Board
{
    std::vector<std::vector<FieldState>> board;
public:
    Board(int width, int height);
    int getHeight() const { return board.size(); };
    int getWidth() const { return board.at(0).size(); };
    void setFieldState(Position pos, FieldState state);
    FieldState getFieldState(Position pos);
};