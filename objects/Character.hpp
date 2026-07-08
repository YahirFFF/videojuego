#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Character {

public:
  bool air;
  int health;
  float vy;
  bool turned = true;
  std::string name;
  sf::Texture texture;
  sf::Sprite sprite;
  sf::RectangleShape hitbox;
  Character(const std::string name, int16_t x, int16_t y)
  {
    buffer.loadFromFile("misc/sound.mp3");
    sound.setBuffer(buffer);
    health = 15;
    vy = 0;
    air = false;
    texture.loadFromFile("misc/tung.png");
    sprite.setTexture(texture);
    sprite.setPosition(200, 520);
    sprite.setScale(0.2f, 0.2f);
    hitbox.setPosition(sprite.getPosition());
    hitbox.move(-17.5, 0);
    hitbox.setFillColor(sf::Color::Green);
    hitbox.setSize(sf::Vector2f(
      sprite.getGlobalBounds().width - 35,
      sprite.getGlobalBounds().height - 30
      ));
  }   

public:
  sf::Clock timer;

  void hurted() { timer.restart(); }

  sf::SoundBuffer buffer;
  sf::Sound sound;
  void hurtsound() { sound.play(); }

  void jump(float strenght)
  {
    if(!air) 
    {
      hitbox.move(0, strenght);
      sprite.move(0, strenght);
    }
  }
};
