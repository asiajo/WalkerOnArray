#pragma once
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
#include "SfmlController.hpp"
#include "SfmlGUI.hpp"

class Game
{
public:
    Game( int height, int width );
    void playInTerminal();
    void playInSFML();
private:
    FieldState moveHead();
    bool move();
    void putRandolmyFruit();
    
    Board board;
    Snake snake;
    Direction dir;
};