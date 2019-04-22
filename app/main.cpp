#include "MoverOnArr.hpp"
#include <iostream>

void testOMove()
{
    Game mover( 10, '.', 'o' );
    mover.play();
}
int main()
{
    std::cout << "=== START ===" << std::endl;
    testOMove();
    return 0;
}