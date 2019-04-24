#include "TerminalGUI.hpp"

TerminalGUI::TerminalGUI() :

              symbols{{ FieldState::Free, '.' },
                      { FieldState::SnakeNode, 'o' },
                      { FieldState::Fruit, '@' },
                      { FieldState::Obstacle, '#' }}
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
}

TerminalGUI::~TerminalGUI()
{
    endwin();
}

void TerminalGUI::display(Board& board)
{
    erase();

        for( int i = 0; i < board.getHeight(); i++ )
        {
            for( int j = 0; j < board.getWidth(); j++ )
            {
                printw( "%c ", symbols [ board.getFieldState(Position{i, j}) ] ); 
                refresh();
            }
            printw("\n");
            refresh();
        }
        printw("\n");
        refresh();
        usleep(1000000);
}