#pragma once
#include <memory>
#include "Controller.hpp"
#include <SFML/Graphics.hpp>

class SfmlController
{
public:
    Direction dir = Direction::Right;
    Direction getDirection( sf::RenderWindow & window );
    SfmlController() = default;
    ~SfmlController() = default;
};