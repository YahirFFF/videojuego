#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../objects/Ball.hpp"
#include "../misc/Resolution.hpp"

inline void showHP(int hp, sf::RenderWindow &window)
{

    for(int i = 0; i < hp; i++)
    {
      sf::CircleShape heart(10);
      heart.setFillColor(sf::Color::Red);
      heart.setPosition(20 + i * 25, 20);
      window.draw(heart);
    }
}

