#pragma once

#include "Board.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <map>

class TerminalGUI
{
    std::map<FieldState,char> symbols;
public:
    TerminalGUI();
    ~TerminalGUI();
    void display(Board& board);
};