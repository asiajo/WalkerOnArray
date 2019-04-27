#include<vector>
#include<thread>
#include<chrono>
#include<iostream>
#include<map>
#include<memory>

#include "Snake.hpp"
#include "Food.hpp"
#include "Position.hpp"
#include "Controller.hpp"
#include "Board.hpp"
#include "TerminalGUI.hpp"
#include "TerminalController.hpp"


class Game
{
public:
    Game( int height, int width );
    void play();

private:
    FieldState moveHead();
    bool move();
    void putRandolmyFruit();
    
    Board board;
    Snake snake;
    Direction dir;
    std::unique_ptr<Controller> controller;
    std::unique_ptr<DisplayerI> displayer;
};