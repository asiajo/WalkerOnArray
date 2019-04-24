#include "MoverOnArr.hpp"
#include <iostream>

void testSnakeInConsole()
{
    const int H = 10;
    const int W = 15;
    Game snake( H, W, '.', 'o' );
    snake.play();
}
int main()
{
    std::cout << "=== START ===" << std::endl;
    testSnakeInConsole();
    return 0;
}