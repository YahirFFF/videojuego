#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

bool checkCollision(const sf::RectangleShape &rect, const sf::CircleShape &circle) 
{
  sf::FloatRect bounds = rect.getGlobalBounds();

  float circleX = circle.getPosition().x + circle.getRadius();
  float circleY = circle.getPosition().y + circle.getRadius();
  float radius = circle.getRadius();

  float closestX = std::max(bounds.left, std::min(circleX, bounds.left + bounds.width));
  float closestY = std::max(bounds.top, std::min(circleY, bounds.top + bounds.height));

  float dx = circleX - closestX;
  float dy = circleY - closestY;

  return ((dx * dx + dy * dy) <= (radius * radius));
}

