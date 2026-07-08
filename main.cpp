#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "objects/Grid.hpp"
#include "objects/Ball.hpp"
#include "objects/Character.hpp"
#include "misc/Random.hpp"
#include "misc/Resolution.hpp"
#include "misc/Collision.hpp"
#include "misc/Hpbar.hpp"
#include "debug.h"

float gravity = 0.08;
constexpr float epsilon = 1e-3;
float speed = 3.5;
float strenght = -7;
sf::Music music;
sf::Clock game;
int rev = 444;
sf::Clock repeatMusic;

signed main() {
  std::vector<Ball> balls;
  music.openFromFile("misc/Bonetrousle.ogg");

  sf::Font font;
  font.loadFromFile("misc/UbuntuMonoNerdFont-Bold.ttf");
  sf::Text timerText;
  timerText.setFont(font);
  timerText.setCharacterSize(24);
  timerText.setFillColor(sf::Color::Green);
  timerText.setPosition(maxWidth - 200, 10);
  music.play();

  Character tung = Character("tung", maxWidth, maxHeight);
  sf::RenderWindow window(sf::VideoMode(maxWidth, maxHeight), "tung tung chorizo");
  window.setFramerateLimit(120);
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    //display grid function 
    showGrid(window, maxWidth, maxHeight);

    //texto

    float time = game.getElapsedTime().asSeconds();
    float rep = repeatMusic.getElapsedTime().asSeconds();

    if(rep >= 59.f) {
      music.play();
      repeatMusic.restart();
    }

    timerText.setString("Tiempo " + std::to_string(time));
    window.draw(timerText);

    int xd = probability(gen);
    if(balls.size() < 11 && (xd == 67 or xd == 68 or xd == 69))
      balls.emplace_back(Ball(SpawnX(gen), 0, 30, 1));

    for(auto &ball : balls)
    {

      ball.vy += gravity;
      if(ball.circle.getPosition().y + ball.radius > 1 + maxHeight) ball.vy = 0;

      ball.circle.move(ball.vx, ball.vy);
      if(ball.circle.getPosition().y + ball.radius > maxHeight)
        ball.vy *= -0.5;

    }

  balls.erase(
    std::remove_if(balls.begin(), balls.end(),
      [](const Ball &ball) {
        return (ball.vy <= 0 && (ball.circle.getPosition().y + ball.radius > 1 + maxHeight));
      }),
    balls.end()
  );

    for(auto &ball : balls)
      window.draw(ball.circle);
    
    //tung
    sf::FloatRect bounds = tung.sprite.getLocalBounds();

    tung.sprite.setOrigin(
        bounds.width / 1.6f,
        bounds.height / 5.f
    );

    //move left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      //if(tung.turned) tung.hitbox.move(10, 0);
      tung.turned = false;
      if(tung.hitbox.getPosition().x > 30)
      {
        tung.sprite.move(-1 * speed, 0);
        tung.hitbox.move(-1 * speed, 0);
      }
    }
    //move right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      //if(!tung.turned) tung.hitbox.move(-10, 0);
      tung.turned = true;
      if(tung.hitbox.getPosition().x < 780)
      {
        tung.sprite.move(speed, 0);
        tung.hitbox.move(speed, 0);
      }
    }
    //flip sprite
    if(tung.turned) tung.sprite.setScale(-0.2f, 0.2f);
    else tung.sprite.setScale(0.2f, 0.2f);

    //physics

    tung.vy += 1.4 * (gravity);

    if (tung.hitbox.getPosition().y > 515)
    {
      tung.vy = 0;
      tung.air = false;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !tung.air)
    {
      tung.vy = strenght;
      tung.air = true;
    }

    tung.sprite.move(0, tung.vy);
    tung.hitbox.move(0, tung.vy);
    
    //tung dibujo
    tung.hitbox.setPosition(tung.sprite.getPosition());
    window.draw(tung.sprite);
    //window.draw(tung.hitbox); 

    for(auto &ball : balls)
    {
      if (tung.timer.getElapsedTime().asSeconds() >= 1.5f && checkCollision(tung.hitbox, ball.circle))
      {
        tung.hurtsound();
        tung.health--;
        tung.hurted();
      }
      
      if(tung.health <= 0)
      {
        music.stop();
        rev--;
        if(rev <= 0) return 0;
      }
    }
    showHP(tung.health, window);
    window.display();
  }
  return 0;
}
