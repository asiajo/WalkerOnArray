#include "MoverOnArr.hpp"
#include <iostream>

void testSnakeInConsole()
{
    const int H = 30;
    const int W = 30;
    Game snake( H, W );
    // snake.playInTerminal();
    snake.playInSFML();
}
int main()
{
    std::cout << "=== START ===" << std::endl;
    testSnakeInConsole();
    return 0;
}