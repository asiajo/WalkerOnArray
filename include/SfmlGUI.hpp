#pragma once
#include <memory>
#include <map>
#include "Board.hpp"
#include <SFML/Graphics.hpp>

class SfmlGUI
{
    std::map<FieldState, sf::Color> colors;
    const float TILE_SIZE = 10.f;
public:
    SfmlGUI();
    void init( sf::RenderWindow& window, int height, int width );
    void display( sf::RenderWindow& window, Board& board);
};