#include<vector>
#include<thread>
#include<chrono>
#include<iostream>
#include<map>

#include "Snake.hpp"
#include "Food.hpp"
#include "Position.hpp"
#include "Controller.hpp"
#include "Board.hpp"
#include "TerminalGUI.hpp"



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
    Controller controller;
    TerminalGUI terminalGui;
};