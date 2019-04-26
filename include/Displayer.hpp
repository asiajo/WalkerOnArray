#pragma once
#include "Board.hpp"

class DisplayerI
{
public:
    virtual ~DisplayerI() = default;
    virtual void display(Board& board) = 0;
};