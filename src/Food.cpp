#include "../include/Food.hpp"

Food::Food(int boardX, int boardY) : _boardX(boardX), _boardY(boardY){}

void Food::generateFood()
{
    srand(time(0));
    _x = rand() % _boardX;
    _y = rand() % _boardY;
}

Position Food::getFoodPosition()
{
    Position pos{_x, _y};
    return pos;
}