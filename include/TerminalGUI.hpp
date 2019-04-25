#pragma once

#include "Displayer.hpp"
// #include "Board.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <map>

class TerminalGUI : public DisplayerI
{
    std::map<FieldState,char> symbols;
public:
    TerminalGUI();
    ~TerminalGUI();
    void display(Board& board);
};