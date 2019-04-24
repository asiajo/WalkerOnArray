#include "Board.hpp"

Board::Board(int width, int height)
{
    board.resize(height);
    std::for_each(begin(board), end(board), [&](auto& v){v.resize(width);});
}

void Board::setFieldState(Position pos, FieldState state)
{
    board[pos.x][pos.y] = state;
}


FieldState Board::getFieldState(Position pos)
{
    return board[pos.x][pos.y];
}