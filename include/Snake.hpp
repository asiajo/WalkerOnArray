#include<deque>
using Coords = std::pair<int,int>;
using Body = std::deque<Coords>;
class Snake
{
public:
    Coords head;
    Body body;
    Snake (Coords);
};