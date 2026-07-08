#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:

  sf::CircleShape circle;

  float vx;
  float vy;
  float radius;

  float posX = circle.getPosition().x;
  float posY = circle.getPosition().y;

  Ball(float x, float y, float r, int color)
  {
    vx = 0;
    vy = 0;
    posX = 0;
    posY = 0;
    radius = r;
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    if(color == 1)
      circle.setFillColor(sf::Color::Blue);
    else circle.setFillColor(sf::Color::Red);
  }

};
