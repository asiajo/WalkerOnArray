#pragma once

#include "Displayer.hpp"
#include "SFML/Graphics"
// #include "Board.hpp"
#include " "

class SfmlGui : public DisplayerI
{
public:
    SfmlGui();
    ~SfmlGui();
    void display(Board& board);

};