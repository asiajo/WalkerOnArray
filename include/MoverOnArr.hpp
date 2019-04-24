#include<vector>
#include<thread>
#include<chrono>
#include<iostream>
#include<map>

#include "Snake.hpp"
#include "Food.hpp"
#include "Position.hpp"

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
    Game(  int height,
           int width,
           char background,
           char walker );
    void play();
    FieldState moveHead();
    bool move();
    void putRandolmyFruit();

private:
    int getHeight() const { return space.size(); };
    int getWidth() const { return space.at(0).size(); };
    const char background;
    const char walker;
    Board space;
    Snake snake;
    Direction dir;
    std::map<FieldState,char> symbols;
};