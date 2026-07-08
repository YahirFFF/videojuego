#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

inline void showGrid(sf::RenderWindow &window, unsigned maxWidth, unsigned maxHeight) {
  static std::vector<sf::RectangleShape> hgrid, vgrid;
  
  //construction
  static bool initialized = false;  
  if(!initialized)
  {
    for(int i = 50; i < maxWidth; i += 50) 
    {
      sf::RectangleShape grid(sf::Vector2f(1.1f, maxHeight));
      grid.setPosition(i, 0);
      hgrid.emplace_back(grid);
    }

    for(int i = 50; i < maxHeight; i += 50) 
    {
      sf::RectangleShape grid(sf::Vector2f(maxWidth, 1.1f));
      grid.setPosition(0, i);
      vgrid.emplace_back(grid);
    }

    initialized = true;
  }


  //display
  for(const auto &line : hgrid)
    window.draw(line);
  for(const auto &line : vgrid)
    window.draw(line);

  return;
}
