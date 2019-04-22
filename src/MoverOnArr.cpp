#include"MoverOnArr.hpp"

Mover::Mover( int size,
              char background,
              char walker )
            : 
              background( background ),
              walker( walker )
{
    space = std::vector<char>( size, background );
    walker_position = 0;
    space[ walker_position ] = walker;
    dir = Direction::Left;
}

void Mover::move()
{
    space [ walker_position ] = background;
    if( dir == Direction::Right )
        walker_position = ( ++walker_position < space.size() ) ? walker_position : 0;
    else
        walker_position = ( --walker_position >= 0  ) ? walker_position : space.size() - 1;
    space [ walker_position ] = walker;
}

void Mover::play()
{
    while( 1 )
    {
        system("clear");
        for( const auto & elem : space )
            std::cout << elem;
        std::cout << std::endl;
        move();
        std::this_thread::sleep_for( std::chrono::seconds(1) );
    }
}