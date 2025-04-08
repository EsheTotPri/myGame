#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
  Bullet(sf::Vector2f startPos, sf::Vector2f targetPos);

  void update();
  void draw(sf::RenderWindow& window) const;
  sf::FloatRect getBounds() const;

  bool isActive;

private:
  sf::CircleShape shape;
  sf::Vector2f velocity;
  float speed = 1.f;
};

#endif
