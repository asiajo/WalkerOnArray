#include<vector>
#include<thread>
#include<chrono>
#include<iostream>
#include<map>

#include "Snake.hpp"

enum class Direction
{
    Right,
    Left,
    Up,
    Down
};
enum class FieldState
{
    Free,
    SnakeNode,
    Fruit,
    Obstacle
};


using Board = std::vector<std::vector<FieldState>>;

class Game
{
public:
    Game( int size,
           char background,
           char walker );
    void play();
    void move();
private:
    
    const char background;
    const char walker;
    Board space;
    Coords walker_position;
    Direction dir;
    std::map<FieldState,char> symbols;
    Snake snake;
};