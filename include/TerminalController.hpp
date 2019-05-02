#include "Controller.hpp"
#include <ncurses.h>
#include <unistd.h>

class TerminalController : public Controller
{
public:
    Direction dir = Direction::Right;
    int kbhit(void);
    Direction getDirection() override;
    TerminalController() = default;
    ~TerminalController() = default;
};