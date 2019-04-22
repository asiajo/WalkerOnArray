#include<vector>
#include<thread>
#include<chrono>
#include<iostream>

enum class Direction
{
    Right,
    Left
};

class Mover{
public:
    Mover( int size,
           char background,
           char walker );
    void play();
    void move();
private:
    
    const char background;
    const char walker;
    std::vector<char> space;
    int walker_position;
    Direction dir;
};