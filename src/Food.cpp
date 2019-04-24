#include "Food.hpp"

void Food::generateFood(int heightBoard, int widthBoard)
{
    srand(time(0));
    position.x = rand() % heightBoard;
    position.y = rand() % widthBoard;
}

Position Food::getFoodPosition()
{
    return position;
}